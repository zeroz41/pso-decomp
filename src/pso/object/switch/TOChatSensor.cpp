#pragma defer_codegen on
#pragma readonly_strings on

#include "pso/unk/TQuestManager.h"
#include "pso/object/switch/TOChatSensorCapture.h"

#include "pso/ui/Language.h"

#include "pso/boss/darkfalz/TOBoss4Rock.h"

const char *chat_sensor_name = "TOChatSensor";

const char *chat_sensor_folder_name_ptr = "TOChatSensorFolder";

const char *chat_sensor_capture_class_name = "TOChatSensorCapture";

#include "types.h"
#include <string.h>

#include "pso/unk/TLobby_8015ABD0.h"

#include "pso/object/switch/TOChatSensorFolder.h"

#include "pso/render/render_util.h"

#include "pso/system/NinjaTypes.h"

#include "pso/object/switch/TOChatSensor.h"

#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/quest/TQuestThread.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/object/base/TObjCharaHelpers.h"

#include "pso/network/TLobby.h"

#include "pso/network/protocol/protocol_types.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/network/TGameProtocol.h"


#include "pso/system/byteswap.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/text_80225CD8.h"

// ChatSensor.prs: how many trigger texts there are and the texts (a sensor's text_index picks one, from 1).
struct ChatSensorTable {
    s32 count;
    char **texts;
};

TOChatSensorFolder *chat_sensor_folder_instance;

ChatSensorTable *chat_sensor_table;

TOChatSensorCapture *chat_sensor_capture_instance;

void G_SetSwitchFlagFromTimer_6x93::init() {
    header.subcommand = 0x93;
    header.size = 3;
}

void G_SetSwitchFlagFromTimer_6x93::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_16((u16 *)&switch_flag_floor);
    bswap_16(&switch_flag_num);
}

void G_SetSwitchFlagFromTimer_6x93::send() {
    bswap();
    send_subcommand(this);
}

void load_chat_sensor(void) { chat_sensor_table = (ChatSensorTable *)load_encrypted_archive_data("ChatSensor.prs"); }

void TOChatSensor::destroy_global() {
    if (chat_sensor_table != NULL) {
        TLobby::free_nodes_with_id((uaddr)chat_sensor_table);
        chat_sensor_table = NULL;
    }
}

void *TOChatSensor::create(void *set) {
    if (chat_sensor_folder_instance == NULL) {
        new TOChatSensorFolder(tl_05);
    }
    if (chat_sensor_folder_instance != NULL) {
        return new TOChatSensor(chat_sensor_folder_instance, set);
    }
    return NULL;
}

void TOChatSensor::dispatch_chat_message_to_children(char *message) {
    TObject *sensor;
    if (chat_sensor_folder_instance != NULL) {
        sensor = chat_sensor_folder_instance->m_down;
        while (sensor != NULL) {
            ((TOChatSensor *)sensor)->handle_chat_message(message);
            sensor = sensor->m_next;
        }
    }
}

TOChatSensor::TOChatSensor(TObject *parent, void *set_data) : TObjBase(parent) {
    s32 n;
    char **t;
    m_name = chat_sensor_name;
    apply_object_set_data(set_data);
    script_thread = NULL;
    player_inside = 0;
    init_params();
    n = text_index;
    if (n > 0) {
        t = chat_sensor_table->texts;
        t += n;
        set_trigger_text(t[-1]);
    }
}

TOChatSensor::~TOChatSensor() {

}

void TOChatSensor::run_task() {
    if ((u32) this->kind == 0U) {
        switch (this->state) {
        case 0:
            check_player_proximity();
            return;
        case 1:
            if ((this->script_thread != NULL) && (this->script_thread->all_parents_unqueued_for_destruction() == 0)) {
                this->script_thread = NULL;
                this->state = 0;
                return;
            }
            break;
        }
    } else {
        if (is_current_floor_switch_set(this->switch_id) == 0) {
            check_player_proximity();
            return;
        }
        this->player_inside = 0;
    }
}

void TOChatSensor::render() {
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.3f;
        color.b = color.g = 0.8f;
        debug_draw_sphere(&position, &color, newton_sqrtf(range_squared));
    }
}

void TOChatSensor::init_params() {
    f32 x;
    s32 index;

    this->kind = (u32) this->rotation_x;
    if ((u32) this->kind >= 2U) {
        this->kind = 0U;
    }
    this->match_mode = (u32) this->rotation_y;
    if ((u32) this->match_mode >= 2U) {
        this->kind = 0U;
    }
    x = this->scale.x;
    this->range_squared = (f32) (x * x);
    if ((u32) this->kind == 0U) {
        this->script_label = (s32) this->set_params[0];
    } else {
        this->switch_id = (u16) this->set_params[0];
        if ((u16) this->switch_id > 0x100U) {
            this->switch_id = 0xFFFF;
        }
    }
    this->text_index = (s32) this->set_params[1];
    index = this->text_index;
    if ((index != 0) && ((index < 0) || (chat_sensor_table->count <= index))) {
        this->text_index = 0;
    }
    this->state = 0;
}

void TOChatSensor::handle_chat_message(char *message) {
    G_SetSwitchFlagFromTimer_6x93 pkt;
    s32 r;
    u32 mode;
    if (message != NULL && player_inside == 1) {
        mode = match_mode;
        r = -1;
        if (mode == 0) {
            r = find_chat_keyword(message, (char (*)[0x20])trigger_text, current_language);
        } else if (mode == 1) {
            r = 0;
        }
        if (r > -1) {
            if (kind == 0) {
                if (quest_mission_manager != NULL) {
                    script_thread = new TQuestThread(quest_mission_manager, script_label);
                    if (script_thread != NULL) {
                        script_thread->set_parent(tl_00);
                    }
                    state = 1;
                }
            } else if (this->switch_id < 0x100) {
                pkt.init();
                pkt.switch_flag_floor = get_current_floor();
                pkt.switch_flag_num = this->switch_id;
                pkt.should_set = 1;
                pkt.send();
            }
        }
    }
}

void TOChatSensor::set_trigger_text(void *trigger_text) {
    s32 i;
    if (trigger_text != 0) {
        strncpy(this->trigger_text, (const char *)trigger_text, 0x1F);
        this->trigger_text[0x1F] = 0;
        for (i = 0; i < 0x20; i++) {
            if (this->trigger_text[i] == 0xA) {
                this->trigger_text[i] = 0;
            }
        }
    }
}

void TOChatSensor::check_player_proximity() {
    TObjPlayer *player;

    player = get_player_by_client_id((local_client_id));
    if (player != NULL) {
        if (horizontal_distance_squared(&player->position, &position) < this->range_squared) {
            this->player_inside = 1;
            return;
        }
        this->player_inside = 0;
    }
}

TOChatSensorFolder::TOChatSensorFolder(TObject *parent) : TObject(parent) {
    m_name = chat_sensor_folder_name_ptr;
    chat_sensor_folder_instance = this;
}

TOChatSensorFolder::~TOChatSensorFolder() {
    chat_sensor_folder_instance = 0;
}

void TLobby__sub_8015ABD4(void) {  }

void TLobby__sub_8015ABD0(void) {  }

void TOChatSensorCapture::create_instance(void *parent) {
    if (chat_sensor_capture_instance == NULL) {
        new TOChatSensorCapture((TObject *)parent);
    }
}

#pragma push
#pragma opt_common_subs off
TOChatSensorCapture::TOChatSensorCapture(TObject *parent) : TObject(parent) {
    m_name = chat_sensor_capture_class_name;
    s32 i = 0;
    do {
        lifetime[i] = 0;
        messages[i] = (char *)mem_alloc(0x100);
        memset(messages[i], 0, 4);
        i += 1;
    } while (i != 4);
    chat_sensor_capture_instance = this;
}

#pragma pop
TOChatSensorCapture::~TOChatSensorCapture() {
    for (int i = 0; i != 4; i++) mem_free(messages[i]);
    chat_sensor_capture_instance = 0;
}

void TOChatSensorCapture::run_task() {
    s32 i = 0;
    do {
        if (lifetime[i] != 0) {
            lifetime[i] = lifetime[i] - 1;
            if (lifetime[i] == 0) memset(messages[i], 0, 4);
        }
        i += 1;
    } while (i != 4);
}

void TOChatSensorCapture::capture_message(u16 client, const char *message) {
    if (chat_sensor_capture_instance != NULL && client < 4) {
        strncpy(chat_sensor_capture_instance->messages[client], message, 0x100);
        chat_sensor_capture_instance->lifetime[client] = 0x78;
    }
}

s32 TOChatSensorCapture::check_keyword(u16 client, const char *keyword) {
    char buffer[0x20];
    s32 i;
    s32 c;
    if (chat_sensor_capture_instance != NULL && client < 4) {
        strncpy(buffer, keyword, 0x20);
        for (i = 0; i < 0x20; i++) {
            c = buffer[i];
            if (c == 0) break;
            if (c == 10 || c == 11) {
                buffer[i] = 0;
                break;
            }
        }
        if (find_chat_keyword(chat_sensor_capture_instance->messages[client],
                              (char (*)[0x20])buffer, current_language) > -1) return 1;
    }
    return 0;
}
