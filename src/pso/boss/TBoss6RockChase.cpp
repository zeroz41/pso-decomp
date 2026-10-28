#include "types.h"
#include "pso/boss/TBoss6RockChase.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/object/TObjMotion.h"
extern "C" void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);

#include <stddef.h>
#include "pso/boss/TBoss6RockChase.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
struct Stack_8036D6D4 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_8036D4E0_lbl_8047ACE8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8036D4E0___vt__15TBoss6RockChase {
    s32 value;
    u8 remaining[0x34];
};

struct Vec_8036D1B4 { f32 x, y, z; };

struct Hit_8036D1B4 {
    s32 a;
    s32 b;
    s32 c;
    f32 d;
};

struct PBase_8036D1B4 { char pad[0x18]; };

struct Player_8036D1B4 : PBase_8036D1B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(s32, Hit_8036D1B4 *, s32, s32, s32);
    u8 pad1C[0x38 - 0x1C];
    Vec_8036D1B4 pos;
};

struct Ent_8036D1B4 { s32 id; f32 range; };

struct Chase_8036D1B4 {
    u8 pad0[0x38];
    Vec_8036D1B4 pos;
    u8 pad44[0xAC - 0x44];
    s32 xAC;
    s32 xB0;
};

struct Param_8036D1B4 { u8 pad[0xC]; f32 v; };

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 rand();
extern const f32 lbl_805E03D0;
extern const f32 lbl_805E03D8;
extern const f32 lbl_805E03E4;
s32 get_bml_model(int, int);
int TBoss6Rock__sub_80353A04(void);
int TBoss6Rock__sub_80353A0C(void);
__declspec(section ".rodata") char lbl_8047ACD8[] = "TBoss6RockChase";
__declspec(section ".rodata") RecoveredGlobal_8036D4E0_lbl_8047ACE8 boss6_rock_chase_model_radius_table = {
    4, { 0x41, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0xF0, 0x00, 0x00 }
};
extern s32 __vt__15TBoss6RockChase[];
extern s32 lbl_805D44F0;
extern const f32 TBoss6RockChase__data_805E03B8;
extern const f32 lbl_805E03CC;
extern const f32 lbl_805E03D4;
extern const f32 lbl_805E03DC;
extern const f32 lbl_805E03E0;
s32 query_teammate_state__9TObjEneDDFv(void);
s32 play_sound_effect(int, void *, int, int);
extern const f32 lbl_805E03C0;
extern const f32 lbl_805E03C4;
extern const f32 lbl_805E03C8;
int get_player_data__10TObjPlayerFi(int a0);
Param_8036D1B4 *dispatch_shared_handler_a__6TLobbyFl(s32);
f32 vector_length(void *);
int subtract_vector(void *, void *);
extern RecoveredGlobal_8036D4E0_lbl_8047ACE8 boss6_rock_chase_model_radius_table;
extern const f32 lbl_805E03BC;
int post_translate_matrix(void*);
int rotate_matrix_z(void*, void*);
int rotate_matrix_x(void*, void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
void __dl__7TObjectFPv(void *);

#pragma push
#pragma opt_propagation off
s32 TBoss6RockChase::damage_players_in_range() {
    Chase_8036D1B4 *self = (Chase_8036D1B4 *)this;
    Vec_8036D1B4 d;
    s32 n;
    s32 dmg;
    s32 i;
    Player_8036D1B4 *pl;
    f32 range;
    n = TLobby::get_game_mode();
    {
        Ent_8036D1B4 *tbl = (Ent_8036D1B4 *)&boss6_rock_chase_model_radius_table;
        range = tbl[self->xB0].range;
    }
    dmg = dispatch_shared_handler_a__6TLobbyFl(0x2C)->v;
    if (dmg < 1) {
        dmg = 20;
    }
    for (i = 0; i < n; i++) {
        pl = (Player_8036D1B4 *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)pl)->is_active() != 0) {
            VecCopy((Vec *)&d, (const Vec *)&pl->pos);
            subtract_vector(&d, &self->pos);
            d.y = TBoss6RockChase__data_805E03B8;
            if (!(vector_length(&d) > range)) {
                Hit_8036D1B4 h;
                h.d = (f32)TBoss6PlotFalz::rand_vary_count(dmg, lbl_805E03BC);
                s32 z = 0;
                h.a = z;
                h.c = z;
                h.b = *(s32 *)&h.d;
                pl->m21(self->xAC, &h, 0, -1, -1);
            }
        }
    }
}
#pragma pop

void TBoss6RockChase::render() { push_matrix(this); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void* *)&this->rotation_y); rotate_matrix_x((void*)0, *(void* *)&this->rotation_x); rotate_matrix_z((void*)0, *(void* *)&this->rotation_z); TObjFish::set_global_param((s32)(*(void* *)&this->m_c4)); draw_ginja_object(*(void* *)&this->m_c0); pop_matrix(); }

#pragma push
#pragma opt_common_subs off
void TBoss6RockChase::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        temp_r3 = this->m_b4;
        if (temp_r3 > 0) {
            this->m_b4 = (temp_r3 - 1);
            return;
        }
        this->rotation_y = (s32) (this->rotation_y + this->m_bc);
        *(f32 *)&this->_padB8 = (f32) (*(f32 *)&this->_padB8 + lbl_805E03C0);
        if (*(f32 *)&this->_padB8 < lbl_805E03C4) {
            *(f32 *)&this->_padB8 = (f32) lbl_805E03C4;
        }
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) + *(f32 *)&this->_padB8);
        if (*(f32 *)((s8 *)arg0 + 0x3C) <= TBoss6RockChase__data_805E03B8) {
            *(f32 *)((s8 *)arg0 + 0x3C) = (f32) TBoss6RockChase__data_805E03B8;
            *(f32 *)&this->_padB8 = (f32) TBoss6RockChase__data_805E03B8;
            damage_players_in_range();
            play_sound_effect(0x4006B51E, (u8 *)&this->position, 0, 0);
            spawn_particle_effect(((u8 *)&this->position), 0x220);
            spawn_particle_effect(((u8 *)&this->position), 0x222);
            TBoss6PlotFalz::apply_radial_effect_to_players((u8 *)&this->position, 0xC0, 0xF, lbl_805E03C8);
            ((TBoss6Rock *)(arg0 + 0x38))->spawn_crush_rocks(this->m_b0);
            play_sound_effect(0x4006AB1F, (u8 *)&this->position, 0, 0);
            queue_destruction__7TObjectFv(arg0);
        }
    }
}
#pragma pop

}
TBoss6RockChase::~TBoss6RockChase() {

}
extern "C" {

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8036D4E0_lbl_8047ACE8_size[sizeof(RecoveredGlobal_8036D4E0_lbl_8047ACE8) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8036D4E0___vt__15TBoss6RockChase_size[sizeof(RecoveredGlobal_8036D4E0___vt__15TBoss6RockChase) == 0x38 ? 1 : -1];
u8 *TBoss6RockChase__ct(TBoss6RockChase *boss6_rock_chase, s32 arg1, s32 arg2, s32 arg3) {
    __ct__13TUnk_804AF8A0FP7TObject(boss6_rock_chase, arg1);
    *(s32 **)((s8 *)boss6_rock_chase + 0x18) = &(*(RecoveredGlobal_8036D4E0___vt__15TBoss6RockChase *)&__vt__15TBoss6RockChase).value;
    *(s32 *)((s8 *)boss6_rock_chase + 0) = (s32) lbl_805D44F0;
    boss6_rock_chase->m_ac = arg1;
    boss6_rock_chase->m_b0 = arg3;
    boss6_rock_chase->m_b4 = (s32) (lbl_805E03CC * (lbl_805E03D0 * (f32) rand()));
    *(s32 *)((s8 *)boss6_rock_chase + 0x5C) = (s32) (lbl_805E03D4 * ((lbl_805E03D0 * (f32) rand()) - lbl_805E03D8));
    boss6_rock_chase->rotation_y = (s32) (lbl_805E03DC * (lbl_805E03D0 * (f32) rand()));
    boss6_rock_chase->rotation_z = (s32) (lbl_805E03D4 * ((lbl_805E03D0 * (f32) rand()) - lbl_805E03D8));
    boss6_rock_chase->m_bc = (s32) (lbl_805E03E0 * ((lbl_805E03D0 * (f32) rand()) - lbl_805E03D8));
    *(f32 *)((s8 *)boss6_rock_chase + 0xB8) = (f32) TBoss6RockChase__data_805E03B8;
    VecCopy((Vec *)((u8 *)boss6_rock_chase + 0x38), (const Vec *)(arg2));
    boss6_rock_chase->m_c0 = get_bml_model((int) (TBoss6Rock__sub_80353A0C()), (int) (*(s32 *)((s8 *)&boss6_rock_chase_model_radius_table.value + (arg3 * 8))));
    boss6_rock_chase->m_c4 = TBoss6Rock__sub_80353A04();
    return (u8 *)boss6_rock_chase;
}
#pragma pop

s32 TBoss6RockChase::spawn(s32 arg0, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_8036D6D4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8036D6D4, spC) == 0x4) ? 1 : -1];
    Stack_8036D6D4 stack;
    s32 boss6_rock_chase;
    s32 var_r0;
    s32 var_r31;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg1));
    var_r31 = 0;
    stack.spC = lbl_805E03E4;
    if ((lbl_805E03D0 * (f32) rand()) < lbl_805E03D8) {
        var_r31 = 1;
    }
    boss6_rock_chase = __nw__7TObjectFUl(0xC8);
    var_r0 = boss6_rock_chase;
    if (var_r0 != 0) {
        var_r0 = ((s32)TBoss6RockChase__ct((TBoss6RockChase *)((u8 *)boss6_rock_chase), (s32)arg0, (s32)((void *)&stack.sp8), (s32)var_r31));
    }
    return var_r0;
}

__declspec(section ".sdata2") extern const f32 TBoss6RockChase__data_805E03B8 = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03BC = 0.10000000149011612f;
__declspec(section ".sdata2") extern const f32 lbl_805E03C0 = -0.9375f;
__declspec(section ".sdata2") extern const f32 lbl_805E03C4 = -11.25f;
__declspec(section ".sdata2") extern const f32 lbl_805E03C8 = 100.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03CC = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03D0 = 3.0517578125e-05f;
__declspec(section ".sdata2") extern const f32 lbl_805E03D4 = 2048.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03D8 = 0.5f;
__declspec(section ".sdata2") extern const f32 lbl_805E03DC = 65535.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03E0 = 8192.0f;
__declspec(section ".sdata2") extern const f32 lbl_805E03E4 = 450.0f;

}
