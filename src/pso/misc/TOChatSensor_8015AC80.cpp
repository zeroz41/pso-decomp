#include "pso/object/TObjMapWarp_80141C68.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TOChatSensor.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/quest/TQuestThread.h"


struct C_8015ACE4 { u8 pad0[0xA4]; s8 buf[0x20]; };

struct Packet_8015AD54 {
    u32 hdr;
    s16 a;
    u16 b;
    u8 c;
};

extern "C" {
u8 is_current_floor_switch_set(int);
f32 newton_sqrtf(f32);
extern const f32 lbl_805DB388;
extern const f32 lbl_805DB38C;
void *strncpy(void *, void *, s32);
s32 get_current_floor(void);
s32 find_chat_keyword(void *, void *, s32);
void *__nw__7TObjectFUl(u32);
extern void *quest_mission_manager;
extern void *tl_00;
void *get_player_by_client_id(s32 i);

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
        color.a = lbl_805DB388;
        color.r = lbl_805DB388;
        color.b = color.g = lbl_805DB38C;
        TObjRoomId__sub_80141CF4(&position, &color, newton_sqrtf(*(f32 *)(arg0 + 0x9C)));
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
