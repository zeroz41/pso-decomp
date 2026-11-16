#include "pso/render/render_util.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/switch/TOChatSensor.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/TLobby.h"


struct C_8015ACE4 { u8 pad0[0xA4]; s8 buf[0x20]; };

struct Packet_8015AD54 {
    u32 hdr;
    s16 a;
    u16 b;
    u8 c;
};

extern "C" {
u8 is_current_floor_switch_set(s32 id);
void *strncpy(void *, void *, s32);
s32 find_chat_keyword(void *, void *, s32);
extern void *quest_mission_manager;
extern void *tl_00;

extern s32 local_client_id;

void TOChatSensor::check_player_proximity() {
    u8 *arg0 = (u8 *)this;
    u32 player;

    player = (u32)get_player_by_client_id((local_client_id));
    if (player != 0U) {
        if (horizontal_distance_squared((const Vec *)(player + 0x38), (const Vec *)(arg0 + 0x38)) < *(f32 *)&this->unk_9C) {
            this->m_a0 = 1;
            return;
        }
        this->m_a0 = 0;
    }
}

extern s32 *chat_sensor_table;

void TOChatSensor::set_trigger_text(void *arg1) {
    C_8015ACE4 *arg0 = (C_8015ACE4 *)this;
    s32 i;
    if (arg1 != 0) {
        strncpy(arg0->buf, arg1, 0x1F);
        arg0->buf[0x1F] = 0;
        for (i = 0; i < 0x20; i++) {
            if (arg0->buf[i] == 0xA) {
                arg0->buf[i] = 0;
            }
        }
    }
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
            r = find_chat_keyword(arg1, (u8 *)&this->unk_A4, current_language);
        } else if (mode == 1) {
            r = 0;
        }
        if (r > -1) {
            if (*(u32 *)(arg0 + 0x90) == 0) {
                if (quest_mission_manager != NULL) {
                    o = new TQuestThread((TObject *)quest_mission_manager, *(u32 *)(arg0 + 0x94));
                    *(void **)(arg0 + 0xC4) = o;
                    if (*(void **)(arg0 + 0xC4) != NULL) {
                        ((TObject *)(*(void **)(arg0 + 0xC4)))->set_parent((TObject *)tl_00);
                    }
                    *(s32 *)(arg0 + 0xC8) = 1;
                }
            } else if (*(u16 *)(arg0 + 0x94) < 0x100) {
                ((TOChatSensor *)(&pkt))->init_packet_type();
                pkt.a = get_current_floor();
                pkt.b = *(u16 *)(arg0 + 0x94);
                pkt.c = 1;
                ((TOChatSensor *)(&pkt))->send_state();
            }
        }
    }
}

void TOChatSensor::init_params() {
    f32 temp_f0;
    s32 temp_r5;

    this->m_90 = (u32) *(u32 *)&this->rotation_x;
    if ((u32) this->m_90 >= 2U) {
        this->m_90 = 0U;
    }
    this->m_98 = (u32) *(u32 *)&this->rotation_y;
    if ((u32) this->m_98 >= 2U) {
        this->m_90 = 0U;
    }
    temp_f0 = this->scale.x;
    *(f32 *)&this->unk_9C = (f32) (temp_f0 * temp_f0);
    if ((u32) this->m_90 == 0U) {
        *(s32 *)&this->m_94 = (s32) this->set_params[0];
    } else {
        this->m_94 = (u16) this->set_params[0];
        if ((u16) this->m_94 > 0x100U) {
            this->m_94 = 0xFFFF;
        }
    }
    *(s32 *)&this->m_cc = (s32) *(s32 *)&this->set_params[1];
    temp_r5 = *(s32 *)&this->m_cc;
    if ((temp_r5 != 0) && ((temp_r5 < 0) || ((s32) *chat_sensor_table <= temp_r5))) {
        *(s32 *)&this->m_cc = 0;
    }
    *(s32 *)&this->m_c8 = 0;
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
        if (is_current_floor_switch_set(this->m_94) == 0) {
            check_player_proximity();
            return;
        }
        this->m_a0 = 0;
    }
}

}

extern "C" {
s32 TOChatSensorFolder__ct(int, int);
u32 __nw__7TObjectFUl(int);
extern u32 TOChatSensorFolder__instance;
extern s32 tl_05;
u32 TOChatSensor__create(s32 arg0);
s32 __ct__8TObjBaseFP7TObject(void *, void *);
extern s32 __vt__12TOChatSensor[];
extern s32 TOChatSensor__name;
u32 TOChatSensor__ct(int arg0, void *arg1, void *arg2);

}
TOChatSensor::~TOChatSensor() {

}


u32 TOChatSensor__ct(int arg0, void *parent, void *arg2) {
    s32 n;
    s32 *t;
    __ct__8TObjBaseFP7TObject((void *) arg0, parent);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOChatSensor;
    *(s32 *)((s8 *)arg0 + 0) = TOChatSensor__name;
    ((TOChatSensor *)arg0)->apply_object_set_data(arg2);
    ((TOChatSensor *)arg0)->m_c4 = 0;
    ((TOChatSensor *)arg0)->m_a0 = 0;
    ((TOChatSensor *)arg0)->init_params();
    n = ((TOChatSensor *)arg0)->m_cc;
    if (n > 0) {
        t = (s32 *) *(s32 *)((s8 *)chat_sensor_table + 4);
        t += n;
        ((TOChatSensor *)arg0)->set_trigger_text((void *)t[-1]);
    }
    return arg0;
}

void TOChatSensor::dispatch_chat_message_to_children(s32 arg0) {
    void *var_r31;
    if (TOChatSensorFolder__instance != 0U) {
        var_r31 = *(void **)((s8 *)TOChatSensorFolder__instance + 0x14);
        while (var_r31 != NULL) {
            ((TOChatSensor *)var_r31)->handle_chat_message((void *)arg0);
            var_r31 = *(void **)((s8 *)var_r31 + 0xC);
        }
    }
}

u32 TOChatSensor__create(s32 arg0) {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 var_r0;
    if ((u32) TOChatSensorFolder__instance == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x1C);
        if (temp_r3 != 0U) {
            TOChatSensorFolder__ct(temp_r3, tl_05);
        }
    }
    if ((u32) TOChatSensorFolder__instance != 0U) {
        temp_r3_2 = __nw__7TObjectFUl(0xD0);
        var_r0 = temp_r3_2;
        if (var_r0 != 0U) {
            var_r0 = TOChatSensor__ct((int)temp_r3_2, (void *)TOChatSensorFolder__instance, (void *)arg0);
        }
        return var_r0;
    }
    return 0U;
}

void TOChatSensor::destroy_global() {
    if ((u32) chat_sensor_table != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)chat_sensor_table));
        chat_sensor_table = 0U;
    }
}
