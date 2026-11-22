#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/camera/CameraHelpers.h"
#include "pso/system/vector.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/TUnk_80486924.h"
#include "pso/boss/darkfalz/TObjDFDemo0.h"
#include "pso/boss/darkfalz/TObjDFDemo1.h"
#include "pso/boss/darkfalz/TObjDFDemo2.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TObjDFDemo3.h"
#include "pso/boss/darkfalz/TObjDFDemo4.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/system/byteswap.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/TLevelSelect.h"

extern const char dark_falz_state_name_editor[] = "EDITOR";
extern const char dark_falz_state_name_wait_casket[] = "WAIT_CASKET";
extern const char dark_falz_state_name_demo_warp0[] = "DEMO_WARP0";
extern const char dark_falz_state_name_demo_warp1[] = "DEMO_WARP1";
extern const char dark_falz_state_name_zako[] = "ZAKO";
extern const char dark_falz_state_name_app_type1[] = "APP TYPE1";
extern const char dark_falz_state_name_type1[] = "TYPE1";
extern const char dark_falz_state_name_app_type2[] = "APP TYPE2";
extern const char dark_falz_state_name_type2[] = "TYPE2";
extern const char dark_falz_state_name_die_type2[] = "DIE TYPE2";
extern const char dark_falz_state_name_get_ring[] = "GET RING";
extern const char dark_falz_state_name_demo_warp2[] = "DEMO_WARP2";
extern const char dark_falz_state_name_demo_warp3[] = "DEMO_WARP3";
extern const char dark_falz_state_name_type3[] = "TYPE3";
extern const char dark_falz_state_name_die_type3[] = "DIE TYPE3";
extern const char dark_falz_state_name_ol_ending[] = "OL ENDING";
struct Stack_8004C5E8 {
    u8 * sp8;
    s16 spC;
    u8 pad_E[0x4];
    s16 sp12;
    s16 sp14;
    u8 trailing_storage[0x36];
};

extern "C" {
saddr VecCopy__FP3VecPC3Vec(void*, void* a1);
int freeze_all_players__14TBoss4DarkFalzFPv(void*);
s32 obj_setArrS16_FC(void *, s32, u16);
extern Vec lbl_80485454;
    extern int dark_falz_form_index;
int TBoss4DarkFalz__sub_8004B07C(TBoss4DarkFalz *);
int TBoss4DarkFalz__sub_8004B7DC(void);
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
struct RecoveredGlobal_TBoss4DarkFalz__data_804FF1E8 { s32 value; u8 remaining[0x3C]; };
extern RecoveredGlobal_TBoss4DarkFalz__data_804FF1E8 TBoss4DarkFalz__data_804FF1E8;

TBoss4Type3 *TBoss4DarkFalz__sub_8004C1AC() {  return TBoss4DarkFalz__type3_instance; }


TUnk_80486924 *TBoss4DarkFalz__sub_8004C1B4() {
    return TBoss4DarkFalz__type2_instance;
}


TBoss4Type1 *TBoss4DarkFalz::get_instance() {
    return TBoss4DarkFalz__type1_instance;
}

int TBoss4DarkFalz::is_field378_zero() { return this->m_378 == 0; }
s32 TBoss4Type3::get_action_state() { return m_374; }
s32 TUnk_80486924::get_phase() { return action; }
s32 TBoss4Type1::get_state() { return state; }
CameraAngles *TObjBase::get_rotation() { return reinterpret_cast<CameraAngles *>(&rotation_x); }
void TObjBase::save_previous_position() {
    VecCopy(&prev_position, &position);
}

int TObjBase::set_position_from(void *pos) { return VecCopy__FP3VecPC3Vec(&this->position, pos); }

void TBoss4DarkFalz::swap_and_send() { swap_bytes(); send_subcommand((u8 *)this); }
void TBoss4DarkFalz::swap_bytes() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char *)this + 0x4)); bswap_16((u16 *)((char *)this + 0x6)); bswap_32((u32 *)((char *)this + 0x8)); bswap_32((u32 *)((char *)this + 0xc)); }
void TBoss4DarkFalz::set_code_25_4() { *(u8 *)&this->m_name = 25; *(u8*)((char*)this + 0x1) = 4; }

void TBoss4DarkFalz::update_ol_ending() {
    f32 v;
    s32 t;
    t = state_timer;
    if (t > 0x1BC) {
        v = (t - 0x1BC) / 6.0f;
        if (v > 1.0f) {
            v = 1.0f;
        }
        TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, v);
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        TBoss4DarkFalz::refresh_player_equipment(this);
        handle_defeat();
    }
}

void TBoss4DarkFalz::set_state() { TBoss4DarkFalz::freeze_all_players(this); TObjOnlineEnding::create(this); state_timer = 454; }

void TBoss4DarkFalz::update_fade_countdown() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = state_timer;
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, v);
        }
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

void TBoss4DarkFalz::begin_defeat_sequence() {
    u16 sp8[4];
    s32 i;
    TBoss4DarkFalz::freeze_all_players(this);
    TLobby::stop_audio_streams();
    set_story_flag_or_send_quest_flag(0x37);
    TBoss4Thanks::check_ready();
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TObjChara *form = TBoss4DarkFalz__type3_instance;
        TObjDFDemo5::create(this, &form->position, form->rotation_y);
    } else {
        TObjDFDemo5::create(this, &lbl_80485454, 0);
    }
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TBoss4DarkFalz__type3_instance->get_defeat_params(&m_2d6, &attacker_id, sp8);
        TBoss4DarkFalz__type3_instance->queue_destruction();
        TBoss4DarkFalz__type3_instance = NULL;
        i = 0;
        do {
            obj_setArrS16_FC(this, i, sp8[i]);
            i += 1;
        } while (i < 4);
    }
    state_timer = 0x12E;
}
void TBoss4DarkFalz::update_type3() {  }
void TBoss4DarkFalz::request_action_e() {
    if ((TBoss4DarkFalz__type3_instance == NULL) || (TBoss4DarkFalz__type3_instance->get_action_state() == 3) || (TBoss4DarkFalz__type3_instance->get_action_state() == 2) || (TBoss4DarkFalz__sub_8004B07C(this) != 0)) {
        send_action_packet(0xE);
    }
}
void TBoss4DarkFalz::start_phase() { TBoss4DarkFalz::end_player_camera_pans(this); TBoss4DarkFalz::refresh_player_equipment(this); }

#pragma push
#pragma fp_contract on
void TBoss4DarkFalz::update_demo_warp3() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8004C5E8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8004C5E8, spC) == 0x4);
    LAYOUT_ASSERT(sp12_offset, offsetof(Stack_8004C5E8, sp12) == 0xA);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_8004C5E8, sp14) == 0xC);
    Stack_8004C5E8 stack;
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = (f32) state_timer / 126.0f;
    TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, (f32) (temp_f1 * (temp_f1 * (temp_f1 * temp_f1))));
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 <= 0) {
        set_story_flag_or_send_quest_flag((s32)((int) (0x36U)));
        stack.sp8 = (u8 *)this;
        TBoss4DarkFalz__sub_8004B4F0((&stack.spC), (&TBoss4DarkFalz__data_804FF1E8.value));
        stack.sp14 = 2;
        stack.spC = *(s16 *)((s8 *)this + 0x2C) + 0x1FE;
        stack.sp12 = entity_id + 0x1FE;
        TBoss4DarkFalz__type3_instance = reinterpret_cast<TBoss4Type3 *>(TBoss4Type3::create(reinterpret_cast<saddr>(&stack.sp8)));
        change_state(0xD);
    }
}
#pragma pop

void TBoss4DarkFalz::enter_state_126() { state_timer = 126; dark_falz_form_index = 2; TBoss4DarkFalz__sub_8004B7DC(); TBoss4DarkFalz::push_players_out_of_zone((saddr)this, (saddr)((void*)2)); }

void TBoss4DarkFalz::update_countdown_shrink() {
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = 1.0f - ((f32) state_timer / 114.0f);
    TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, (f32) (temp_f1 * (temp_f1 * (temp_f1 * temp_f1))));
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 <= 0) {
        this->change_state(0xC);
    }
}

void TBoss4DarkFalz::init_state() {
    TBoss4DarkFalz::freeze_all_players(this);
    TObjDFDemo4::create(this, &cinematic_position, cinematic_angle);
    play_area_music("dark2.adx");
    state_timer = 114;
}

void TBoss4DarkFalz::update_get_ring() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = state_timer;
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, v);
        }
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

void TBoss4DarkFalz::update_leader_get_ring() {  }
void TBoss4DarkFalz::enter_state_142() {
    TBoss4DarkFalz::freeze_all_players(this);
    TObjDFDemo3::create(this, &cinematic_position, cinematic_angle);
    state_timer = 142;
}
void TBoss4DarkFalz::update_timer() {
    s32 temp_r0;
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 < 0) {
        if ((s32) game_difficulty_selection == 0) {
            change_state(0xA);
            return;
        }
        change_state(0xB);
    }
}

}

struct Obj_8004CD08 { u8 pad0[0x1C]; u16 id; u8 pad1e[0xE]; s16 f2c; u8 pad2e[0x352]; s32 f380; };

struct Sub_8004CD08 { s16 x; u8 pad2[4]; s16 id; s16 f8; u8 pada[0x42]; };

struct Params_8004CD08 { void *owner; Sub_8004CD08 sub; };

struct D_8004CB28 {
    s16 a0, a2, a4;
    u16 a6;
    s16 a8, aa, ac, ae;
    u8 pad10[0x30];
};

struct Arg_8004CB28 { void *owner; D_8004CB28 d; };

struct S_8004CB28 {
    u8 pad0[0x1c];
    u16 f1c;
    u8 pad1e[0x0e];
    s16 f2c;
    u8 pad2e[0x352];
    s32 f380;
};

extern "C" {
extern Vec lbl_80485448;
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);

void TBoss4DarkFalz::update_leader_die_type2() {  }

#pragma fp_contract on
void TBoss4DarkFalz::enter_demo2_phase() {
    u16 arr[4];
    Vec v;
    saddr flag;
    s32 i;
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    TLobby::stop_audio_streams();
    if (TBoss4DarkFalz__type2_instance != NULL) {
        VecCopy(&v, VecCopy(&cinematic_position, &TBoss4DarkFalz__type2_instance->position));
        v.y = 0.0f;
        normalize_vector(&v);
        cinematic_position.x -= 75.0f * v.x;
        cinematic_position.z -= 75.0f * v.z;
        cinematic_position.y = 0.0f;
        cinematic_angle = TBoss4DarkFalz__type2_instance->rotation_y;
    } else {
        cinematic_position.x = cinematic_position.y = cinematic_position.z = 0.0f;
        cinematic_angle = 0;
    }
    flag = 0;
    if (game_difficulty_selection != 0) {
        flag = 1;
    }
    TObjDFDemo2::create(this, &cinematic_position, cinematic_angle, flag);
    set_story_flag_or_send_quest_flag(0x35);
    if (TBoss4DarkFalz__type2_instance != NULL) {
        TBoss4DarkFalz__type2_instance->get_demo2_params(&m_2d6, &attacker_id, arr);
        TBoss4DarkFalz__type2_instance->queue_destruction();
        TBoss4DarkFalz__type2_instance = NULL;
        for (i = 0; i < 4; i++) {
            obj_setArrS16_FC(this, i, arr[i]);
        }
    }
    state_timer = 0x118;
}

void TBoss4DarkFalz::update_type2() {  }

void TBoss4DarkFalz::request_action_9() {
    if ((TBoss4DarkFalz__type2_instance == NULL) || (TBoss4DarkFalz__type2_instance->get_phase() == 3) || (TBoss4DarkFalz__type2_instance->get_phase() == 2) || (TBoss4DarkFalz__sub_8004B07C(this) != 0)) {
        send_action_packet(9);
    }
}

void TBoss4DarkFalz::update_parts() { TBoss4DarkFalz::end_player_camera_pans(this); TBoss4DarkFalz::refresh_player_equipment(this); }

void TBoss4DarkFalz::update_spawn_type2_countdown() {
    S_8004CB28 *o = (S_8004CB28 *)this;
    Arg_8004CB28 a;
    state_timer = state_timer - 1;
    if (state_timer < 0) {
        a.owner = o;
        TBoss4DarkFalz__sub_8004B4F0(&a.d, &TBoss4DarkFalz__data_804FF1E8);
        a.d.a8 = 1;
        a.d.a0 = o->f2c + 0x1FF;
        a.d.a6 = this->entity_id + 0x1FF;
        TBoss4DarkFalz__type2_instance = reinterpret_cast<TUnk_80486924 *>(TBoss4Type2::create(reinterpret_cast<saddr>(&a)));
        set_story_flag_or_send_quest_flag(0x34);
        ((TBoss4DarkFalz *)o)->change_state(8);
    }
}

void TBoss4DarkFalz::update_leader_app_type2() {  }

void TBoss4DarkFalz::start_demo1() {
    u8 *self = (u8 *)this;
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TObjChara *form = TBoss4DarkFalz__type1_instance;
        TObjDFDemo1::create(this, &form->position, form->rotation_y);
    } else {
        TObjDFDemo1::create(this, &lbl_80485448, 0);
    }
    set_story_flag_or_send_quest_flag(0x33U);
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TBoss4DarkFalz__type1_instance->queue_destruction();
        TBoss4DarkFalz__type1_instance = NULL;
    }
    state_timer = 0x12C;
}

void TBoss4DarkFalz::spawn_ancient_trap() {
    if (sub_8004D990() > 0) {
        play_persistent_sound(0x4003A30A, (saddr)this, 0, -0x20, 2);
    }
}

void TBoss4DarkFalz::request_action_7() {
    if ((TBoss4DarkFalz__type1_instance == NULL) || (TBoss4DarkFalz__type1_instance->get_state() == 3) || (TBoss4DarkFalz__type1_instance->get_state() == 4) || (TBoss4DarkFalz__sub_8004B07C(this) != 0)) {
        send_action_packet(7);
    }
}

void TBoss4DarkFalz::spawn_type1() {
    Obj_8004CD08 *self = (Obj_8004CD08 *)this;
    Params_8004CD08 params;
    params.owner = self;
    TBoss4DarkFalz__sub_8004B4F0(&params.sub, &TBoss4DarkFalz__data_804FF1E8);
    params.sub.f8 = 1;
    params.sub.x = self->f2c + 0x200;
    params.sub.id = this->entity_id + 0x200;
    TBoss4DarkFalz__type1_instance = reinterpret_cast<TBoss4Type1 *>(TBoss4Type1::create(reinterpret_cast<saddr>(&params)));
    state_timer = 0;
    TBoss4DarkFalz::end_player_camera_pans(self);
    TBoss4DarkFalz::refresh_player_equipment(self);
}


void TBoss4DarkFalz::update_intro_demo() {
    s32 temp_r0;
    s32 temp_r3;

    temp_r0 = state_timer;
    if (temp_r0 < 4) {
        TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, (f32) (4 - temp_r0) / 4.0f);
    }
    if ((s32) state_timer == 0x2D) {
        if (intro_tower != NULL) {
            intro_tower->sub_8004D9A0(1);
        }
        TObjDFDemo0::create(this);
    }
    if ((s32) state_timer == 0xB9) {
        if (intro_tower != NULL) {
            intro_tower->sub_8004D9A0(2);
        }
        play_area_music("dark1.adx");
    }
    temp_r3 = state_timer;
    if (temp_r3 > 0x145) {
        if (intro_tower != NULL) {
            intro_tower->queue_destruction();
            intro_tower = NULL;
        }
        set_story_flag_or_send_quest_flag(0x32);
        change_state(6);
        return;
    }
    state_timer = (temp_r3 + 1);
}

void TBoss4DarkFalz::update_leader_app_type1() {  }
void TBoss4DarkFalz::start_effect() {
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    TLobby::stop_audio_streams();
    play_sound_effect(0x4003A80B, 0, 0, 0);
    state_timer = 0;
}
void TBoss4DarkFalz::spawn_trap() {
    play_persistent_sound(0x4003A30A, (saddr)this, 0, -0x18, 2);
}
void TBoss4DarkFalz::check_timeout() {
    if ((is_timer_expired() != 0) || (TBoss4DarkFalz__sub_8004B07C(this) != 0)) {
        send_action_packet(5);
    }
}
void TBoss4DarkFalz::enter_zako() {
    play_sound_effect(0x4003AD0C, 0, 0, 0);
    TBoss4DarkFalz::end_player_camera_pans(this);
    TBoss4DarkFalz::refresh_player_equipment(this);
    spawn_zako_rings();
}


void TBoss4DarkFalz::update_demo_warp1() {
    f32 temp_f1;
    s32 temp_r0;

    temp_f1 = (f32) state_timer / 30.0f;
    TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, temp_f1 * (temp_f1 * (temp_f1 * temp_f1)));
    temp_r0 = state_timer - 1;
    state_timer = temp_r0;
    if (temp_r0 <= 0) {
        change_state(4);
    }
}

}

extern "C" {
f32 horizontal_distance_squared(void *, void *);
extern s32 registered_player_count;
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *boss4_dark_falz);
}
void set_dark_falz_music_request(s32 arg0);
void unlock_music_flag(s32 flag);

void TBoss4DarkFalz::init_timer() {
    state_timer = 30;
    dark_falz_form_index = 1;
    intro_tower = TObjDFUsoTower::create(this);
    TBoss4DarkFalz::refresh_player_equipment(this);
}

void TBoss4DarkFalz::update_demo_warp0() {
    f32 t;
    s32 temp_r4;

    temp_r4 = state_timer;
    if (temp_r4 > 0x71) {
        t = (temp_r4 - 0x71) / 7.0f;
        t *= t;
        TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, t);
    } else if (temp_r4 < 0x20) {
        t = 1.0f - ((temp_r4 - 2) / 30.0f);
        if (t > 1.0f) {
            t = 1.0f;
        }
        t *= t;
        TBoss4DarkFalz__sub_8004B730(this, 0xFFFFFF, t);
    }
    if (--state_timer < 0) {
        change_state(3);
    }
}

void TBoss4DarkFalz::start_demo() { TBoss4DarkFalz__sub_8004B8F8((TBoss4DarkFalz *)((void *)this)); TBoss4DarkFalz::push_players_out_of_zone((saddr)this, (saddr)((void*)1)); TBoss4DarkFalz::freeze_all_players(this); TObjDFDemoF::create(this); set_dark_falz_music_request((saddr)((void*)1)); unlock_music_flag((saddr)((void*)23)); state_timer = 120; }

void TBoss4DarkFalz::check_players_near_center() {
    Vec v;
    void *p;
    s32 i;
    f32 lim;
    v.x = -9860.0f;
    v.z = -240.0f;
    lim = 900.0f;
    for (i = 0; i < registered_player_count; i++) {
        p = (void *)TObjPlayer::get_player_data(i);
        if (p != 0 && horizontal_distance_squared(&v, (u8 *)p + 0x2FC) <= lim) {
            send_action_packet(2);
            return;
        }
    }
    if (TBoss4DarkFalz__sub_8004B07C(this) != 0) {
        send_action_packet(2);
    }
}

void TBoss4DarkFalz::update_leader_editor() { if (TObjPlayer::check_demo_mode() == 0) { change_state((saddr)((void*)1)); } }


TBoss4DarkFalzState dark_falz_state_table[16] = {
    { dark_falz_state_name_editor, 0, 0, &TBoss4DarkFalz::update_leader_editor, 0 },
    { dark_falz_state_name_wait_casket, 0, 0, &TBoss4DarkFalz::check_players_near_center, 0 },
    { dark_falz_state_name_demo_warp0, &TBoss4DarkFalz::start_demo, 0, 0, &TBoss4DarkFalz::update_demo_warp0 },
    { dark_falz_state_name_demo_warp1, &TBoss4DarkFalz::init_timer, 0, 0, &TBoss4DarkFalz::update_demo_warp1 },
    { dark_falz_state_name_zako, &TBoss4DarkFalz::enter_zako, 0, &TBoss4DarkFalz::check_timeout, &TBoss4DarkFalz::spawn_trap },
    { dark_falz_state_name_app_type1, &TBoss4DarkFalz::start_effect, 0, &TBoss4DarkFalz::update_leader_app_type1, &TBoss4DarkFalz::update_intro_demo },
    { dark_falz_state_name_type1, &TBoss4DarkFalz::spawn_type1, 0, &TBoss4DarkFalz::request_action_7, &TBoss4DarkFalz::spawn_ancient_trap },
    { dark_falz_state_name_app_type2, &TBoss4DarkFalz::start_demo1, 0, &TBoss4DarkFalz::update_leader_app_type2, &TBoss4DarkFalz::update_spawn_type2_countdown },
    { dark_falz_state_name_type2, &TBoss4DarkFalz::update_parts, 0, &TBoss4DarkFalz::request_action_9, &TBoss4DarkFalz::update_type2 },
    { dark_falz_state_name_die_type2, &TBoss4DarkFalz::enter_demo2_phase, 0, &TBoss4DarkFalz::update_leader_die_type2, &TBoss4DarkFalz::update_timer },
    { dark_falz_state_name_get_ring, &TBoss4DarkFalz::enter_state_142, 0, &TBoss4DarkFalz::update_leader_get_ring, &TBoss4DarkFalz::update_get_ring },
    { dark_falz_state_name_demo_warp2, &TBoss4DarkFalz::init_state, 0, 0, &TBoss4DarkFalz::update_countdown_shrink },
    { dark_falz_state_name_demo_warp3, &TBoss4DarkFalz::enter_state_126, 0, 0, &TBoss4DarkFalz::update_demo_warp3 },
    { dark_falz_state_name_type3, &TBoss4DarkFalz::start_phase, 0, &TBoss4DarkFalz::request_action_e, &TBoss4DarkFalz::update_type3 },
    { dark_falz_state_name_die_type3, &TBoss4DarkFalz::begin_defeat_sequence, 0, 0, &TBoss4DarkFalz::update_fade_countdown },
    { dark_falz_state_name_ol_ending, &TBoss4DarkFalz::set_state, 0, 0, &TBoss4DarkFalz::update_ol_ending },
};

// Zero positions passed to create_demo1 (start_demo1) and TObjDFDemo5::create (begin_defeat_sequence);
// they follow the state table in .data.
extern "C" {
Vec lbl_80485448 = {0.0f, 0.0f, 0.0f};
Vec lbl_80485454 = {0.0f, 0.0f, 0.0f};
}


