#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TObjDFDemo0.h"

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
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TObjPlayer.h"

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

struct RecoveredGlobal_8004C5E8_TBoss4DarkFalz__data_804FF1E8 {
    s32 value;
    u8 remaining[0x3C];
};

extern "C" {
int VecCopy__FP3VecPC3Vec(void*, void* a1);
int freeze_all_players__14TBoss4DarkFalzFPv(void*);
s32 obj_setArrS16_FC(void *, s32, u16);
extern s32 lbl_80485454[];
extern int TBoss4DarkFalz__type3_instance;
    extern int dark_falz_form_index;
s32 TBoss4DarkFalz__sub_8004B07C(s32);
int TBoss4DarkFalz__sub_8004B7DC(void);
void play_area_music(char *name);
extern s32 game_difficulty_selection;
s32 TBoss4DarkFalz__sub_8004B730(void *, f32, int);
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
extern RecoveredGlobal_8004C5E8_TBoss4DarkFalz__data_804FF1E8 TBoss4DarkFalz__data_804FF1E8;
int TBoss4DarkFalz__sub_8004C1AC(void);
s32 TBoss4DarkFalz__sub_8004C1B4(void);
int bswap_16__FPUs(void*);
int bswap_32__FPUl(void*);

int TBoss4DarkFalz__sub_8004C1AC(void) {  return TBoss4DarkFalz__type3_instance; }

extern s32 TBoss4DarkFalz__type2_instance;

s32 TBoss4DarkFalz__sub_8004C1B4(void) {
    return TBoss4DarkFalz__type2_instance;
}

extern s32 TBoss4DarkFalz__type1_instance;

s32 TBoss4DarkFalz::get_instance() {
    return TBoss4DarkFalz__type1_instance;
}

int TBoss4DarkFalz::is_field378_zero() { return this->m_378 == 0; }
s32 TBoss4DarkFalz::get_action_state() { return this->m_374; }
s32 TBoss4DarkFalz::get_phase() { return this->m_374; }
s32 TBoss4DarkFalz::get_state() { return this->m_374; }
void*TBoss4DarkFalz::get_hit_data() { return (char*)this + 0x5c; }
void TBoss4DarkFalz::save_position() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec((void*)(arg0 + 0x44), (void*)(arg0 + 0x38));
}

int TObjBase::set_position_from(void *pos) { return VecCopy__FP3VecPC3Vec(&this->position, pos); }

void TBoss4DarkFalz::swap_and_send() { swap_bytes(); send_subcommand((u8 *)this); }
void TBoss4DarkFalz::swap_bytes() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); bswap_16__FPUs((char*)this + 0x6); bswap_32__FPUl((char*)this + 0x8); bswap_32__FPUl((char*)this + 0xc); }
void TBoss4DarkFalz::set_code_25_4() { *(u8 *)&this->m_name = 25; *(u8*)((char*)this + 0x1) = 4; }

void TBoss4DarkFalz::update_ol_ending() {
    f32 v;
    s32 t;
    t = *(s32 *)((s8 *)this + 0x380);
    if (t > 0x1BC) {
        v = (t - 0x1BC) / 6.0f;
        if (v > 1.0f) {
            v = 1.0f;
        }
        TBoss4DarkFalz__sub_8004B730(this, v, 0xFFFFFF);
    }
    t = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = t;
    if (t < 0) {
        TBoss4DarkFalz::refresh_player_equipment(this);
        handle_defeat();
    }
}

void TBoss4DarkFalz::set_state() { TBoss4DarkFalz::freeze_all_players(this); TObjOnlineEnding::create(this); *(int*)((char*)this + 0x380) = 454; }

void TBoss4DarkFalz::update_fade_countdown() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = *(s32 *)((s8 *)this + 0x380);
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            TBoss4DarkFalz__sub_8004B730(this, v, 0xFFFFFF);
        }
    }
    t = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

typedef struct Vec_8004C940 {
    f32 x, y, z;
} Vec_8004C940;

typedef struct Obj_8004C940 {
    u8 pad0[0x2D4];
    u16 f2d4;
    u16 f2d6;
    u8 pad2d8[0x380 - 0x2D8];
    s32 f380;
    u8 pad384[0x39C - 0x384];
    Vec_8004C940 pos;
    s32 f3a8;
} Obj_8004C940;

void TBoss4DarkFalz::begin_defeat_sequence() {
    u16 sp8[4];
    s32 i;
    TBoss4DarkFalz::freeze_all_players(this);
    TLobby::stop_audio_streams();
    TBoss4DarkFalz::dispatch_by_main_phase(0x37);
    TBoss4Thanks::check_ready();
    if ((void *) (*(u8 * *)&TBoss4DarkFalz__type3_instance) != NULL) {
        TObjDFDemo5::create((void *)this, (void *)((*(u8 * *)&TBoss4DarkFalz__type3_instance) + 0x38), (void *)(*(s32 *)((s8 *)(*(u8 * *)&TBoss4DarkFalz__type3_instance) + 0x60)));
    } else {
        TObjDFDemo5::create((void *)this, (void *)lbl_80485454, (void *)0);
    }
    if ((void *) (*(u8 * *)&TBoss4DarkFalz__type3_instance) != NULL) {
        ((TBoss4DarkFalz *)TBoss4DarkFalz__type3_instance)->get_defeat_params(&((Obj_8004C940 *)this)->f2d6, &((Obj_8004C940 *)this)->f2d4, sp8);
        ((TObject *)(*(u8 * *)&TBoss4DarkFalz__type3_instance))->queue_destruction();
        (*(u8 * *)&TBoss4DarkFalz__type3_instance) = NULL;
        i = 0;
        do {
            obj_setArrS16_FC(this, i, sp8[i]);
            i += 1;
        } while (i < 4);
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x380) = 0x12E;
}
void TBoss4DarkFalz::update_type3() {  }
void TBoss4DarkFalz::request_action_e() {
    if (((u32) (*(u32 *)&TBoss4DarkFalz__type3_instance) == 0U) || (((TBoss4DarkFalz *)(*(u32 *)&TBoss4DarkFalz__type3_instance))->get_action_state() == 3) || (((TBoss4DarkFalz *)(*(u32 *)&TBoss4DarkFalz__type3_instance))->get_action_state() == 2) || (TBoss4DarkFalz__sub_8004B07C((s32)this) != 0)) {
        send_action_packet(0xE);
    }
}
void TBoss4DarkFalz::start_phase() { TBoss4DarkFalz::end_player_camera_pans(this); TBoss4DarkFalz::refresh_player_equipment(this); }

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8004C5E8_TBoss4DarkFalz__data_804FF1E8_size[sizeof(RecoveredGlobal_8004C5E8_TBoss4DarkFalz__data_804FF1E8) == 0x40 ? 1 : -1];
void TBoss4DarkFalz::update_demo_warp3() {
    typedef char sp8_offset[(offsetof(Stack_8004C5E8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8004C5E8, spC) == 0x4) ? 1 : -1];
    typedef char sp12_offset[(offsetof(Stack_8004C5E8, sp12) == 0xA) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8004C5E8, sp14) == 0xC) ? 1 : -1];
    Stack_8004C5E8 stack;
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = (f32) *(s32 *)((s8 *)this + 0x380) / 126.0f;
    TBoss4DarkFalz__sub_8004B730(this, (f32) (temp_f1 * (temp_f1 * (temp_f1 * temp_f1))), 0xFFFFFF);
    temp_r0 = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = temp_r0;
    if (temp_r0 <= 0) {
        TBoss4DarkFalz::dispatch_by_main_phase((s32)((int) (0x36U)));
        stack.sp8 = (u8 *)this;
        TBoss4DarkFalz__sub_8004B4F0((&stack.spC), (&TBoss4DarkFalz__data_804FF1E8.value));
        stack.sp14 = 2;
        stack.spC = *(s16 *)((s8 *)this + 0x2C) + 0x1FE;
        stack.sp12 = entity_id + 0x1FE;
        (*(s32 *)&TBoss4DarkFalz__type3_instance) = TBoss4Type3::create((s32)&stack.sp8);
        change_state(0xD);
    }
}
#pragma pop

void TBoss4DarkFalz::enter_state_126() { *(int*)((char*)this + 0x380) = 126; dark_falz_form_index = 2; TBoss4DarkFalz__sub_8004B7DC(); TBoss4DarkFalz::push_players_out_of_zone((s32)this, (s32)((void*)2)); }

void TBoss4DarkFalz::update_countdown_shrink() {
    f32 temp_f1;
    s32 temp_r0;
    temp_f1 = 1.0f - ((f32) *(s32 *)((s8 *)((u8 *)this) + 0x380) / 114.0f);
    TBoss4DarkFalz__sub_8004B730(this, (f32) (temp_f1 * (temp_f1 * (temp_f1 * temp_f1))), 0xFFFFFF);
    temp_r0 = *(s32 *)((s8 *)((u8 *)this) + 0x380) - 1;
    *(s32 *)((s8 *)((u8 *)this) + 0x380) = temp_r0;
    if (temp_r0 <= 0) {
        this->change_state(0xC);
    }
}

void TBoss4DarkFalz::init_state() {
    TBoss4DarkFalz::freeze_all_players(this);
    TObjDFDemo4::create(this, (void *)((char *)this + 924), *(void **)((s8 *)this + 0x3A8));
    play_area_music("dark2.adx");
    *(u32 *)((s8 *)this + 0x380) = 114;
}

void TBoss4DarkFalz::update_get_ring() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = *(s32 *)((s8 *)this + 0x380);
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            TBoss4DarkFalz__sub_8004B730(this, v, 0xFFFFFF);
        }
    }
    t = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

void TBoss4DarkFalz::update_leader_get_ring() {  }
void TBoss4DarkFalz::enter_state_142() { TBoss4DarkFalz::freeze_all_players(this); TObjDFDemo3::create(this, (char*)this + 0x39c, *(void**)((char*)this + 0x3a8)); *(int*)((char*)this + 0x380) = 142; }
void TBoss4DarkFalz::update_timer() {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = temp_r0;
    if (temp_r0 < 0) {
        if ((s32) game_difficulty_selection == 0) {
            change_state(0xA);
            return;
        }
        change_state(0xB);
    }
}

}

struct RecoveredGlobal_8004CBC0_lbl_80485448 {
    s32 value;
    u8 remaining[0x8];
};

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
extern RecoveredGlobal_8004CBC0_lbl_80485448 lbl_80485448;
void *create__11TBoss4Type2Fl(void *);
void normalize_vector(Vec_8004C940 *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 is_timer_expired__14TBoss4DarkFalzFv();

void TBoss4DarkFalz::update_leader_die_type2() {  }

#pragma fp_contract on
void TBoss4DarkFalz::enter_demo2_phase() {
    u16 arr[4];
    Vec_8004C940 v;
    s32 flag;
    s32 i;
    Obj_8004C940 *arg0 = (Obj_8004C940 *)this;
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    TLobby::stop_audio_streams();
    if ((u32)TBoss4DarkFalz__type2_instance != 0) {
        VecCopy__FP3VecPC3Vec(&v, (void *)VecCopy__FP3VecPC3Vec(&arg0->pos, (Vec_8004C940 *)(TBoss4DarkFalz__type2_instance + 0x38)));
        v.y = 0.0f;
        normalize_vector(&v);
        arg0->pos.x -= 75.0f * v.x;
        arg0->pos.z -= 75.0f * v.z;
        arg0->pos.y = 0.0f;
        arg0->f3a8 = *(s32 *)(TBoss4DarkFalz__type2_instance + 0x60);
    } else {
        arg0->pos.x = arg0->pos.y = arg0->pos.z = 0.0f;
        arg0->f3a8 = 0;
    }
    flag = 0;
    if (game_difficulty_selection != 0) {
        flag = 1;
    }
    TBoss4DarkFalz::create_demo2((void *)arg0, &arg0->pos, (void *)arg0->f3a8, (void *)flag);
    TBoss4DarkFalz::dispatch_by_main_phase(0x35);
    if ((u32)TBoss4DarkFalz__type2_instance != 0) {
        ((TBoss4DarkFalz *)TBoss4DarkFalz__type2_instance)->get_demo2_params(&arg0->f2d6, &this->m_2d4, arr);
        ((TObject *)TBoss4DarkFalz__type2_instance)->queue_destruction();
        TBoss4DarkFalz__type2_instance = 0;
        for (i = 0; i < 4; i++) {
            obj_setArrS16_FC(arg0, i, arr[i]);
        }
    }
    state_timer = 0x118;
}

void TBoss4DarkFalz::update_type2() {  }

void TBoss4DarkFalz::request_action_9() {
    if (((u32) TBoss4DarkFalz__type2_instance == 0U) || (((TBoss4DarkFalz *)TBoss4DarkFalz__type2_instance)->get_phase() == 3) || (((TBoss4DarkFalz *)TBoss4DarkFalz__type2_instance)->get_phase() == 2) || (TBoss4DarkFalz__sub_8004B07C((s32)this) != 0)) {
        send_action_packet(9);
    }
}

void TBoss4DarkFalz::update_parts() { TBoss4DarkFalz::end_player_camera_pans(this); TBoss4DarkFalz::refresh_player_equipment(this); }

void TBoss4DarkFalz::update_spawn_type2_countdown() {
    S_8004CB28 *o = (S_8004CB28 *)this;
    Arg_8004CB28 a;
    o->f380 = o->f380 - 1;
    if (o->f380 < 0) {
        a.owner = o;
        TBoss4DarkFalz__sub_8004B4F0(&a.d, &TBoss4DarkFalz__data_804FF1E8);
        a.d.a8 = 1;
        a.d.a0 = o->f2c + 0x1FF;
        a.d.a6 = this->entity_id + 0x1FF;
        (*(void * *)&TBoss4DarkFalz__type2_instance) = create__11TBoss4Type2Fl(&a);
        TBoss4DarkFalz::dispatch_by_main_phase(0x34);
        ((TBoss4DarkFalz *)o)->change_state(8);
    }
}

void TBoss4DarkFalz::update_leader_app_type2() {  }

typedef char RecoveredGlobal_8004CBC0_lbl_80485448_size[sizeof(RecoveredGlobal_8004CBC0_lbl_80485448) == 0xC ? 1 : -1];
void TBoss4DarkFalz::start_demo1() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    if ((void *) (*(u8 * *)&TBoss4DarkFalz__type1_instance) != NULL) {
        TBoss4DarkFalz::create_demo1(arg0, (u8 *)((*(u8 * *)&TBoss4DarkFalz__type1_instance)) + 0x38, *(u8 **)((s8 *)(*(u8 * *)&TBoss4DarkFalz__type1_instance) + 0x60));
    } else {
        TBoss4DarkFalz::create_demo1(arg0, &lbl_80485448.value, NULL);
    }
    TBoss4DarkFalz::dispatch_by_main_phase(0x33U);
    if ((void *) (*(u8 * *)&TBoss4DarkFalz__type1_instance) != NULL) {
        ((TObject *)(*(u8 * *)&TBoss4DarkFalz__type1_instance))->queue_destruction();
        (*(u8 * *)&TBoss4DarkFalz__type1_instance) = NULL;
    }
    *(s32 *)((s8 *)arg0 + 0x380) = 0x12C;
}

void TBoss4DarkFalz::spawn_ancient_trap() {
    if (sub_8004D990() > 0) {
        play_persistent_sound(0x4003A30A, (s32)this, 0, -0x20, 2);
    }
}

void TBoss4DarkFalz::request_action_7() {
    if (((u32) TBoss4DarkFalz__type1_instance == 0U) || (((TBoss4DarkFalz *)TBoss4DarkFalz__type1_instance)->get_state() == 3) || (((TBoss4DarkFalz *)TBoss4DarkFalz__type1_instance)->get_state() == 4) || (TBoss4DarkFalz__sub_8004B07C((s32)this) != 0)) {
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
    TBoss4DarkFalz__type1_instance = TBoss4Type1::create((s32)&params);
    state_timer = 0;
    TBoss4DarkFalz::end_player_camera_pans(self);
    TBoss4DarkFalz::refresh_player_equipment(self);
}


void TBoss4DarkFalz::update_intro_demo() {
    s32 temp_r0;
    s32 temp_r3;

    temp_r0 = *(s32 *)((s8 *)this + 0x380);
    if (temp_r0 < 4) {
        ((void (*)(void *, s32, f32))TBoss4DarkFalz__sub_8004B730)(this, 0xFFFFFF, (f32) (4 - temp_r0) / 4.0f);
    }
    if ((s32) *(s32 *)((s8 *)this + 0x380) == 0x2D) {
        if ((u32) this->m_394 != 0U) {
            ((TObjDFUsoTower *)this->m_394)->sub_8004D9A0(1);
        }
        TObjDFDemo0::create(this);
    }
    if ((s32) *(s32 *)((s8 *)this + 0x380) == 0xB9) {
        if ((u32) this->m_394 != 0U) {
            ((TObjDFUsoTower *)this->m_394)->sub_8004D9A0(2);
        }
        play_area_music("dark1.adx");
    }
    temp_r3 = *(s32 *)((s8 *)this + 0x380);
    if (temp_r3 > 0x145) {
        if ((u32) this->m_394 != 0U) {
            ((TObject *)(*(void * *)&this->m_394))->queue_destruction();
            this->m_394 = 0U;
        }
        TBoss4DarkFalz::dispatch_by_main_phase(0x32);
        change_state(6);
        return;
    }
    *(s32 *)((s8 *)this + 0x380) = (temp_r3 + 1);
}

void TBoss4DarkFalz::update_leader_app_type1() {  }
void TBoss4DarkFalz::start_effect() {
    ((s32 (*)(void))freeze_all_players__14TBoss4DarkFalzFPv)();
    TLobby::stop_audio_streams();
    play_sound_effect(0x4003A80B, 0, 0, 0);
    *(s32 *)((s8 *)this + 0x380) = 0;
}
void TBoss4DarkFalz::spawn_trap() {
    play_persistent_sound(0x4003A30A, (s32)this, 0, -0x18, 2);
}
void TBoss4DarkFalz::check_timeout() {
    if ((is_timer_expired__14TBoss4DarkFalzFv() != 0) || (TBoss4DarkFalz__sub_8004B07C((s32)this) != 0)) {
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

    temp_f1 = (f32) *(s32 *)((s8 *)this + 0x380) / 30.0f;
    TBoss4DarkFalz__sub_8004B730(this, temp_f1 * (temp_f1 * (temp_f1 * temp_f1)), 0xFFFFFF);
    temp_r0 = *(s32 *)((s8 *)this + 0x380) - 1;
    *(s32 *)((s8 *)this + 0x380) = temp_r0;
    if (temp_r0 <= 0) {
        change_state(4);
    }
}

}

struct V_8004D1E4 { f32 x, y, z; };

extern "C" {
f32 horizontal_distance_squared(void *, void *);
extern s32 registered_player_count;
void TBoss4DarkFalz__sub_8004B8F8(TBoss4DarkFalz *arg0);
}
void set_dark_falz_music_request(s32 arg0);
extern "C" {
int check_demo_mode__10TObjPlayerFv(void*);
int create__14TObjDFUsoTowerFPv(void);
void unlock_music_flag(s32 flag);

void TBoss4DarkFalz::init_timer() { *(int*)((char*)this + 0x380) = 30; dark_falz_form_index = 1; this->m_394 = create__14TObjDFUsoTowerFPv(); TBoss4DarkFalz::refresh_player_equipment(this); }

void TBoss4DarkFalz::update_demo_warp0() {
    f32 t;
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0x380);
    if (temp_r4 > 0x71) {
        t = (temp_r4 - 0x71) / 7.0f;
        t *= t;
        ((void (*)(void *, s32, f32))TBoss4DarkFalz__sub_8004B730)(this, 0xFFFFFF, t);
    } else if (temp_r4 < 0x20) {
        t = 1.0f - ((temp_r4 - 2) / 30.0f);
        if (t > 1.0f) {
            t = 1.0f;
        }
        t *= t;
        ((void (*)(void *, s32, f32))TBoss4DarkFalz__sub_8004B730)(this, 0xFFFFFF, t);
    }
    if (--*(s32 *)((s8 *)this + 0x380) < 0) {
        change_state(3);
    }
}

void TBoss4DarkFalz::start_demo() { TBoss4DarkFalz__sub_8004B8F8((TBoss4DarkFalz *)((void *)this)); TBoss4DarkFalz::push_players_out_of_zone((s32)this, (s32)((void*)1)); TBoss4DarkFalz::freeze_all_players(this); TObjDFDemoF::create(this); set_dark_falz_music_request((s32)((void*)1)); unlock_music_flag((s32)((void*)23)); *(int*)((char*)this + 0x380) = 120; }

void TBoss4DarkFalz::check_players_near_center() {
    V_8004D1E4 v;
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
    if (((s32 (*)(void *))TBoss4DarkFalz__sub_8004B07C)(this) != 0) {
        send_action_packet(2);
    }
}

void TBoss4DarkFalz::update_leader_editor() { if (check_demo_mode__10TObjPlayerFv(this) == 0) { change_state((s32)((void*)1)); } }


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
RecoveredGlobal_8004CBC0_lbl_80485448 lbl_80485448 = { 0 };
s32 lbl_80485454[3] = { 0, 0, 0 };
}

}
