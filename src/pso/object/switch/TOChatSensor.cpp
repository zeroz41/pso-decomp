#pragma defer_codegen on
#pragma readonly_strings on

#include "pso/unk/TUnk_804C8678.h"
#include "pso/object/switch/TOChatSensorCapture.h"

#include "pso/ui/Language.h"

#include "pso/boss/darkfalz/TOBoss4Rock.h"

const char *TOChatSensor__name = "TOChatSensor";

const char *chat_sensor_folder_name_ptr = "TOChatSensorFolder";

const char *TOChatSensorCapture__class_name = "TOChatSensorCapture";

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

#include "pso/player/TObjPlayer_80011014.h"

#include "pso/unk/TLobby.h"

#include "pso/network/protocol/protocol_types.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/unk/TLobby_801E43E4.h"

#include "pso/object/switch/TOChatSensor_8015B214.h"

#include "pso/system/byteswap.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"

// ChatSensor.prs: how many trigger texts there are and the texts (a sensor's m_cc picks one, from 1).
struct ChatSensorTable {
    s32 count;
    char **texts;
};

extern "C" {
void *TOChatSensorFolder__instance;

ChatSensorTable *chat_sensor_table;

TOChatSensorCapture *TOChatSensorCapture__instance;

s32 find_chat_keyword(char *, char (*)[0x20], s32);


}


struct C_8015ACE4 { u8 pad0[0xA4]; s8 buf[0x20]; };

struct Packet_8015AD54 {
    u32 hdr;
    s16 a;
    u16 b;
    u8 c;
};


void TOChatSensor::init_packet_type() { *(u8 *)&this->m_name = 147; *(u8*)((char*)this + 0x1) = 3; }

void TOChatSensor::swap_state_endian() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void TOChatSensor::send_state() { swap_state_endian(); send_subcommand((u8 *)this); }

void load_chat_sensor(void) { chat_sensor_table = (ChatSensorTable *)load_encrypted_archive_data("ChatSensor.prs"); }

void TOChatSensor::destroy_global() {
    if (chat_sensor_table != NULL) {
        TLobby::free_nodes_with_id((uaddr)chat_sensor_table);
        chat_sensor_table = NULL;
    }
}

void *TOChatSensor::create(void *set) {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 var_r0;
    if ((uaddr) TOChatSensorFolder__instance == 0U) {
        new TOChatSensorFolder(tl_05);
    }
    if ((uaddr) TOChatSensorFolder__instance != 0U) {
        return new TOChatSensor((TObject *)TOChatSensorFolder__instance, set);
    }
    return NULL;
}

void TOChatSensor::dispatch_chat_message_to_children(saddr arg0) {
    void *var_r31;
    if (TOChatSensorFolder__instance != 0U) {
        var_r31 = *(void **)((s8 *)TOChatSensorFolder__instance + 0x14);
        while (var_r31 != NULL) {
            ((TOChatSensor *)var_r31)->handle_chat_message((void *)arg0);
            var_r31 = *(void **)((s8 *)var_r31 + 0xC);
        }
    }
}

TOChatSensor::TOChatSensor(TObject *parent, void *arg2) : TObjBase(parent) {
    s32 n;
    char **t;
    m_name = TOChatSensor__name;
    apply_object_set_data(arg2);
    m_c4 = 0;
    m_a0 = 0;
    init_params();
    n = m_cc;
    if (n > 0) {
        t = chat_sensor_table->texts;
        t += n;
        set_trigger_text(t[-1]);
    }
}

TOChatSensor::~TOChatSensor() {

}

void TOChatSensor::run_task() {
    if ((u32) this->m_90 == 0U) {
        switch (this->m_c8) {
        case 0:
            check_player_proximity();
            return;
        case 1:
            if (((u32) this->m_c4 != 0U) && (((TObject *)(this->m_c4))->all_parents_unqueued_for_destruction() == 0)) {
                this->m_c4 = 0U;
                this->m_c8 = 0;
                return;
            }
            break;
        }
    } else {
        if (is_current_floor_switch_set(this->id) == 0) {
            check_player_proximity();
            return;
        }
        this->m_a0 = 0;
    }
}

void TOChatSensor::render() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.3f;
        color.b = color.g = 0.8f;
        debug_draw_sphere(&position, &color, newton_sqrtf(*(f32 *)(arg0 + 0x9C)));
    }
}

void TOChatSensor::init_params() {
    f32 x;
    s32 temp_r5;

    this->m_90 = (u32) *(u32 *)&this->rotation_x;
    if ((u32) this->m_90 >= 2U) {
        this->m_90 = 0U;
    }
    this->m_98 = (u32) *(u32 *)&this->rotation_y;
    if ((u32) this->m_98 >= 2U) {
        this->m_90 = 0U;
    }
    x = this->scale.x;
    *(f32 *)&this->unk_9C = (f32) (x * x);
    if ((u32) this->m_90 == 0U) {
        *(s32 *)&this->id = (s32) this->set_params[0];
    } else {
        this->id = (u16) this->set_params[0];
        if ((u16) this->id > 0x100U) {
            this->id = 0xFFFF;
        }
    }
    *(s32 *)&this->m_cc = (s32) *(s32 *)&this->set_params[1];
    temp_r5 = *(s32 *)&this->m_cc;
    if ((temp_r5 != 0) && ((temp_r5 < 0) || (chat_sensor_table->count <= temp_r5))) {
        *(s32 *)&this->m_cc = 0;
    }
    *(s32 *)&this->m_c8 = 0;
}

void TOChatSensor::handle_chat_message(void *arg1) {
    u8 *arg0 = (u8 *)this;
    Packet_8015AD54 pkt;
    s32 r;
    u32 mode;
    void *o;
    if (arg1 != NULL && *(s32 *)(arg0 + 0xA0) == 1) {
        mode = *(u32 *)(arg0 + 0x98);
        r = -1;
        if (mode == 0) {
            r = find_chat_keyword((char *)arg1, (char (*)[0x20])&this->unk_A4, current_language);
        } else if (mode == 1) {
            r = 0;
        }
        if (r > -1) {
            if (*(u32 *)(arg0 + 0x90) == 0) {
                if (quest_mission_manager != NULL) {
                    o = new TQuestThread(quest_mission_manager, *(u32 *)(arg0 + 0x94));
                    *(void **)(arg0 + 0xC4) = o;
                    if (*(void **)(arg0 + 0xC4) != NULL) {
                        ((TObject *)(*(void **)(arg0 + 0xC4)))->set_parent(tl_00);
                    }
                    *(s32 *)(arg0 + 0xC8) = 1;
                }
            } else if (this->id < 0x100) {
                ((TOChatSensor *)(&pkt))->init_packet_type();
                pkt.a = get_current_floor();
                pkt.b = this->id;
                pkt.c = 1;
                ((TOChatSensor *)(&pkt))->send_state();
            }
        }
    }
}

void TOChatSensor::set_trigger_text(void *trigger_text) {
    C_8015ACE4 *arg0 = (C_8015ACE4 *)this;
    s32 i;
    if (trigger_text != 0) {
        strncpy((char *)arg0->buf, (const char *)trigger_text, 0x1F);
        arg0->buf[0x1F] = 0;
        for (i = 0; i < 0x20; i++) {
            if (arg0->buf[i] == 0xA) {
                arg0->buf[i] = 0;
            }
        }
    }
}

void TOChatSensor::check_player_proximity() {
    u8 *arg0 = (u8 *)this;
    uaddr player;

    player = (uaddr)get_player_by_client_id((local_client_id));
    if (player != 0U) {
        if (horizontal_distance_squared((const Vec *)(player + 0x38), (const Vec *)(arg0 + 0x38)) < *(f32 *)&this->unk_9C) {
            this->m_a0 = 1;
            return;
        }
        this->m_a0 = 0;
    }
}

TOChatSensorFolder::TOChatSensorFolder(TObject *parent) : TObject(parent) {
    m_name = chat_sensor_folder_name_ptr;
    TOChatSensorFolder__instance = this;
}

TOChatSensorFolder::~TOChatSensorFolder() {
    TOChatSensorFolder__instance = 0;
}

void TLobby__sub_8015ABD4(void) {  }

void TLobby__sub_8015ABD0(void) {  }

void TOChatSensorCapture::create_instance(void *parent) {
    if (TOChatSensorCapture__instance == NULL) {
        new TOChatSensorCapture((TObject *)parent);
    }
}

#pragma push
#pragma opt_common_subs off
TOChatSensorCapture::TOChatSensorCapture(TObject *parent) : TObject(parent) {
    m_name = TOChatSensorCapture__class_name;
    s32 i = 0;
    do {
        lifetime[i] = 0;
        messages[i] = (char *)mem_alloc(0x100);
        memset(messages[i], 0, 4);
        i += 1;
    } while (i != 4);
    TOChatSensorCapture__instance = this;
}

#pragma pop
TOChatSensorCapture::~TOChatSensorCapture() {
    for (int i = 0; i != 4; i++) mem_free(messages[i]);
    TOChatSensorCapture__instance = 0;
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
    if (TOChatSensorCapture__instance != NULL && client < 4) {
        strncpy(TOChatSensorCapture__instance->messages[client], message, 0x100);
        TOChatSensorCapture__instance->lifetime[client] = 0x78;
    }
}

s32 TOChatSensorCapture::check_keyword(u16 client, const char *keyword) {
    char buffer[0x20];
    s32 i;
    s32 c;
    if (TOChatSensorCapture__instance != NULL && client < 4) {
        strncpy(buffer, keyword, 0x20);
        for (i = 0; i < 0x20; i++) {
            c = buffer[i];
            if (c == 0) break;
            if (c == 10 || c == 11) {
                buffer[i] = 0;
                break;
            }
        }
        if (find_chat_keyword(TOChatSensorCapture__instance->messages[client],
                              (char (*)[0x20])buffer, current_language) > -1) return 1;
    }
    return 0;
}
