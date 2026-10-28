#include "types.h"
#include "pso/boss/TBoss6Type1.h"
#include "pso/misc/TLobby.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/boss/TUnk_804F322C.h"

struct Vec_80368C14 { f32 x, y, z; };

struct Mine_80368C14 { u8 pad[0x38]; Vec_80368C14 pos; };

#include <stddef.h>
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
extern "C" TObjEnemy *__ct__9TObjEnemyFP7TObject(void *, void *);
struct VBase_18_5673ef { char pad[0x18]; };

struct VObj_18_5673ef : VBase_18_5673ef {
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
    virtual s32 m21(void *, s32 *, s32, s32, s32);
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual s32 m45();
    virtual s32 m46(s32);
    virtual s32 m47();
};

struct Stack_80368AB8 {
    s32 sp8;
    f32 spC;
    s32 sp10;
    f32 sp14;
};

struct Key_80369228 { s32 a; s16 b; s16 c; s32 d; s32 e; };

struct M_80368CE4 { u8 pad[0x384]; Vec_80368C14 home; };

struct P_80368CE4 { u8 pad[0x38]; Vec_80368C14 pos; };

struct Vec_80369598 { f32 x, y, z; };

struct Params_80369598 { u8 pad0[6]; s16 f6; s16 f8; u8 padA[6]; Vec_80369598 pos; u8 pad1C[0x40 - 0x1C]; Vec_80369598 a; Vec_80369598 b; };

extern "C" {
void *__vt__13TBoss6MagMine[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x803b, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void vec3_add_to(void *, void *);
s32 check_demo_mode__10TObjPlayerFv(void *);
s32 query_teammate_state__9TObjEneDDFv();
void submit_cursor_candidate(void *, int);
void add_radar_scaled_marker(void *, int, int, int, f32);
void vt2__13TBoss6MagMineFv(u8 *arg0);
void vt1__13TBoss6MagMineFv(u8 *arg0);
s32 is_locally_controlled__10TObjPlayerFPv(void *);
int get_player_data__10TObjPlayerFi(int a0);
void play_sound_effect(int, Vec_80368C14 *, int, int);
f32 vector_length(Vec_80368C14 *);
void subtract_vector(Vec_80368C14 *, void *);
void explode__13TBoss6MagMineFPv(Mine_80368C14 *o);
s32 get_field_0x42c__13TBoss6MagMineFPv(void* p);
int TBoss6PlotFalz__sub_8036964C(void);
void TBoss6MagMine__sub_80368AB8(u8 *arg0, u8 *arg1);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
u8 *dispatch_shared_handler_a__6TLobbyFl(int);
void *create_particle_emitter(void *pos, s32 id);
s32 init_collision_body_parts(void *, void *, int);
s32 normalize_vector(void *);
extern s32 lbl_804F322C[];
extern s32 lbl_805D44B0;
s32 TBoss6MagMine__ct(s32 arg0, s32 arg1, s32 arg2);
s32 is_player_in_range__13TBoss6MagMineFPv(void *arg0_);
void TBoss4DarkFalz__sub_8004B4F0(void *arg0p, void *arg1p);
s32 get_phase__8TObjFishFv();
s32 create__13TBoss6MagMineFi(s32 arg0);
void spawn_mag_mine_at__13TBoss6MagMineFPvPv(void *arg0, void *arg1);
void vt3__13TBoss6MagMineFv(s32 arg0);
void vt4__13TBoss6MagMineFv(void* p);
void *__dt__13TUnk_804F322CFv(void *arg0, s16 arg1);
void copy_pos__13TBoss6MagMineFi(s32 arg0);
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 farg1);
int post_translate_matrix(void*);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 TObjControl__ct(s32, s32);
void free_collision_body_parts(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
int rotate_matrix_y(void*, void*);
int push_matrix(void*);
s32 pop_matrix(void);
void __dl__7TObjectFPv(void *);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 __nw__7TObjectFUl(s32);
void queue_destruction__7TObjectFv(void *arg0);

void TUnk_804F322C::vfunc_63() {
    if ((s32) *(s32 *)((s8 *)this + 0x390) != 4) {
        *(s32 *)((s8 *)this + 0x390) = 4;
    }
}

void TUnk_804F322C::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFFFFFDFF);
    *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) 1.0f;
}

void copy_pos__13TBoss6MagMineFi(s32 arg0) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
}

void TUnk_804F322C::update_linked_state() {
    s32 temp_r31;
    s32 bml_motion;
    s32 bml_model;

    TObjPlayer::set_global_flag();
    temp_r31 = TObjFish__sub_8001EDB0(*(s32 *)((s8 *)this + 0x374), 2);
    bml_model = get_bml_model(*(s32 *)((s8 *)this + 0x374), 2);
    bml_motion = get_bml_motion(*(s32 *)((s8 *)this + 0x374), 0);
    TObjFish::set_global_param(temp_r31);
    TBoss6PlotFalz__sub_802AC008(*(f32 *)((s8 *)this + 0x3A8), 0.0f);
    draw_model_motion((void *)bml_model, (void *)bml_motion, *(f32 *)((s8 *)this + 0x398));
    TBoss6PlotFalz::update_camera_target();
    TObjPlayer::clear_global_state();
}

void TUnk_804F322C::render() { push_matrix(this); post_translate_matrix((char*)this + 0x38); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x3ac)); update_linked_state(); pop_matrix(); }

void TBoss6MagMine__sub_80368AB8(u8 *arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_80368AB8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80368AB8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80368AB8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80368AB8, sp14) == 0xC) ? 1 : -1];
    Stack_80368AB8 stack;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r31;
    void *boss;
    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x3A4) < (s32) *(s32 *)((s8 *)arg0 + 0x3A0)) && (TBoss6PlotFalz::get_hp() != 0U) && ((boss = ((void *(*)(void))TBoss6PlotFalz__sub_8036964C)()) != NULL)) {
        temp_r3 = get_field_0x42c__13TBoss6MagMineFPv(boss);
        switch (temp_r3) {
        case 2:
        case 3:
            var_r31 = temp_r3;
            break;
        case 4:
            var_r31 = 0x12;
            break;
        }
    }
    switch (var_r31) {
    case 2:
        ((VObj_18_5673ef *)(arg1))->m46(0);
        return;
    case 3:
        ((VObj_18_5673ef *)(arg1))->m47();
        return;
    case 18:
        ((VObj_18_5673ef *)(arg1))->m45();
        return;
    default:
        temp_r3_2 = TBoss6PlotFalz::rand_vary_count((int) (*(s32 *)((s8 *)arg0 + 0x39C)), (f32) (0.1f));
        stack.sp8 = 1;
        stack.sp10 = 1;
        stack.sp14 = (f32) temp_r3_2;
        *(s32 *)&stack.spC = *(s32 *)&stack.sp14;
        ((VObj_18_5673ef *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
        return;
    }
}

void explode__13TBoss6MagMineFPv(Mine_80368C14 *o) {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        u8 *pl = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)pl)->is_active() != 0 && is_locally_controlled__10TObjPlayerFPv(pl) != 0) {
            Vec_80368C14 v = o->pos;
            subtract_vector(&v, pl + 0x38);
            v.y = 0.0f;
            if (!(vector_length(&v) > 22.5f)) {
                TBoss6MagMine__sub_80368AB8((u8 *)o, (u8 *)pl);
            }
        }
    }
    play_sound_effect(0x4003BA1E, &o->pos, 0, 0);
}

s32 is_player_in_range__13TBoss6MagMineFPv(void *arg0_) {
    M_80368CE4 *arg0 = (M_80368CE4 *)arg0_;
    Vec_80368C14 d;
    s32 n;
    s32 i;
    void *p;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (void *)get_player_data__10TObjPlayerFi(i);
        if (((TBoss6PlotFalz *)p)->is_active() != 0) {
            ((void (*)(Vec_80368C14 *, Vec_80368C14 *))VecCopy__FP3VecPC3Vec)(&d, &((P_80368CE4 *)p)->pos);
            subtract_vector(&d, &arg0->home);
            d.y = 0.0f;
            if (vector_length(&d) <= 22.5f) {
                return 1;
            }
        }
    }
    return 0;
}

void vt4__13TBoss6MagMineFv(void* p) { spawn_particle_effect_with_flags(((char*)p + 0x38), (s32)((void*)252), (s32)((void*)64)); queue_destruction__7TObjectFv(p); }

void vt3__13TBoss6MagMineFv(s32 arg0) {
    explode__13TBoss6MagMineFPv((Mine_80368C14 *)(arg0));
    spawn_particle_effect_with_flags((void *)(arg0 + 0x38), 0xFB, 0x40);
    spawn_particle_effect_with_flags((void *)(arg0 + 0x38), 0xFC, 0x40);
    TBoss6PlotFalz::apply_radial_effect_to_players((void *)(arg0 + 0x38), (s16)0xC0, (s16)0xF, (f32)100.0f);
    queue_destruction__7TObjectFv((void *)arg0);
}

#pragma push
#pragma opt_common_subs off
void vt2__13TBoss6MagMineFv(u8 *arg0_) {
    f32 temp_f1;
    if (is_player_in_range__13TBoss6MagMineFPv(arg0_) != 0) {
        *(s32 *)((s8 *)arg0_ + 0x394) = 0x96;
    }
    *(f32 *)((s8 *)arg0_ + 0x398) += 0.33333334f;
    temp_f1 = *(f32 *)((s8 *)arg0_ + 0x398);
    if (temp_f1 >= 10.0f) {
        *(f32 *)((s8 *)arg0_ + 0x398) = (f32) (temp_f1 - 10.0f);
    }
    *(s32 *)((s8 *)arg0_ + 0x394) = (s32) (*(s32 *)((s8 *)arg0_ + 0x394) + 1);
    if ((s32) *(s32 *)((s8 *)arg0_ + 0x394) >= 0x96) {
        *(s32 *)((s8 *)arg0_ + 0x390) = 3;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void vt1__13TBoss6MagMineFv(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg0 + 0x384);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) *(f32 *)((s8 *)arg0 + 0x38C);
    *(f32 *)((s8 *)arg0 + 0x3C) += 1.0f;
    if (*(f32 *)((s8 *)arg0 + 0x3C) >= 10.0f) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) 10.0f;
        *(s32 *)((s8 *)arg0 + 0x394) = 0;
        *(s32 *)((s8 *)arg0 + 0x390) = 2;
    }
}
#pragma pop

struct Vec_80368F20 { f32 x, y, z; };
struct Mine_80368F20 { u8 pad[0x38]; Vec_80368F20 pos; u8 pad44[0x378 - 0x44]; Vec_80368F20 vel; Vec_80368F20 home; s32 f390; };

void vt0__13TBoss6MagMineFv(Mine_80368F20 *m) {
    m->vel.y += -0.25f;
    if (m->vel.y < -20.0f) {
        m->vel.y = -20.0f;
    }
    vec3_add_to(&m->pos, &m->vel);
    if (m->pos.y < -20.0f) {
        m->pos.x = m->home.x;
        m->pos.z = m->home.z;
        m->f390 = 1;
    }
}

struct Vec_80368FA0 { f32 x, y, z; };

class TBoss6MagMine_80368FA0 {
public:
    void m0();
    void m1();
    void m2();
    void m3();
    void m4();
    u8 pad0[0x38];
    Vec_80368FA0 pos;
    Vec_80368FA0 prev;
    u8 pad50[0x390 - 0x50];
    s32 state;
    u8 pad394[0x3A8 - 0x394];
    f32 f3A8;
    s32 f3AC;
    void *f3B0;
};

typedef void (TBoss6MagMine_80368FA0::*Handler_80368FA0)();

class TBoss6MagMine {
public:
    void vt0();
    void vt1();
    void vt2();
    void vt3();
    void vt4();
};

void TUnk_804F322C::run_task() {
    TBoss6MagMine_80368FA0 *self = (TBoss6MagMine_80368FA0 *)this;
    s32 color;
    if (check_demo_mode__10TObjPlayerFv(self) != 0) {
        return;
    }
    if (TBoss6PlotFalz::is_boss_active() == 0) {
        self->state = 4;
    }
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->prev, &self->pos);
    static Handler_80368FA0 tbl[5] = {
        reinterpret_cast<Handler_80368FA0>(&TBoss6MagMine::vt0),
        reinterpret_cast<Handler_80368FA0>(&TBoss6MagMine::vt1),
        reinterpret_cast<Handler_80368FA0>(&TBoss6MagMine::vt2),
        reinterpret_cast<Handler_80368FA0>(&TBoss6MagMine::vt3),
        reinterpret_cast<Handler_80368FA0>(&TBoss6MagMine::vt4),
    };
    void (TBoss6MagMine_80368FA0::*m)() = tbl[self->state];
    if (m) {
        (self->*m)();
    }
    copy_pos__13TBoss6MagMineFi((s32)self);
    if (self->state == 2) {
        ((TObjPlayer *)self)->update_collisions();
        submit_cursor_candidate(self, -1);
    }
    if (self->state != 0) {
        color = 0xFF7F5126;
        if (self->state == 2) {
            color = 0xFFFFA24C;
        }
        add_radar_scaled_marker(&self->pos, color, 1, 1, 1.0f);
    }
    self->f3A8 += -0.06666667f;
    if (self->f3A8 < 0.0f) {
        self->f3A8 = 0.0f;
    }
    switch (self->state) {
    case 0:
        self->f3AC += 0x1111;
        break;
    case 1:
    case 2:
        self->f3AC += 0x888;
        break;
    }
    if (self->f3B0 != 0) {
        ((TNowLoading *)(self->f3B0))->copy_pos(&self->pos);
    }
}

void *__dt__13TUnk_804F322CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F322C;
        if (*(void **)((s8 *)arg0 + 0x3B0) != NULL) { TBoss4Type2::request_destroy((u32)(*(void **)((s8 *)arg0 + 0x3B0))); *(s32 *)((s8 *)arg0 + 0x3B0) = 0; }
        free_collision_body_parts(arg0);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 tl_04;

#pragma push
#pragma opt_common_subs off
#define self ((u8 *)arg0)
s32 TBoss6MagMine__ct(s32 arg0, s32 parent, s32 arg2) {
    Key_80369228 key;
    u8 *d;
    __ct__9TObjEnemyFP7TObject(self, (void*)parent);
    *(s32 **)((s8 *)self + 0x18) = lbl_804F322C;
    *(s32 *)((s8 *)self + 0) = lbl_805D44B0;
    VecCopy__FP3VecPC3Vec(arg0 + 0x38, arg2 + 0x40);
    VecCopy__FP3VecPC3Vec(arg0 + 0x384, arg2 + 0x4C);
    ((TObjChara *)self)->add_flags_2e4(8);
    ((TBoss3Volopt *)(self))->apply_set_data((void *)arg2);
    if (((TObjEnemy *)self)->exchange_object_state((s32)&key, (s16)1) != 0) {
        key.a = 0;
        key.c = 0;
        ((TObjEnemy *)self)->exchange_object_state((s32)&key, (s16)0);
    }
    *(s32 *)((s8 *)self + 0x374) = TObjFish::get_fish_count();
    *(s32 *)((s8 *)self + 0x24) = 0;
    *(s32 *)((s8 *)self + 0x34) = 0;
    VecCopy__FP3VecPC3Vec(arg0 + 0x44, VecCopy__FP3VecPC3Vec(arg0 + 0x50, VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x38)));
    init_collision_body_parts(self, __vt__13TBoss6MagMine, 1);
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    *(f32 *)((s8 *)self + 0x308) = *(f32 *)((s8 *)self + 0x30C) = *(f32 *)((s8 *)self + 0x310) = 0.0f;
    *(s32 *)((s8 *)self + 0x2A8) = 0;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x2D)), (u8 *)(TLobby::dispatch_shared_handler_b(0x2D)), (u8 *)(TLobby::register_object(0x2D)));
    *(s16 *)((s8 *)self + 0x33E) = *(s16 *)((s8 *)self + 0x32C);
    ((TBoss3Volopt *)self)->reset_photon_effect();
    ((TObjEnemy *)self)->set_param(0);
    d = dispatch_shared_handler_a__6TLobbyFl(0x2D);
    *(s32 *)((s8 *)self + 0x39C) = (s32) *(f32 *)((s8 *)d + 4);
    if ((f32) *(s32 *)((s8 *)self + 0x39C) <= 0.0f) {
        *(s32 *)((s8 *)self + 0x39C) = 0x14;
    }
    *(s32 *)((s8 *)self + 0x3A0) = (s32) *(f32 *)((s8 *)d + 8);
    if ((f32) *(s32 *)((s8 *)self + 0x3A0) < 0.0f || *(s32 *)((s8 *)self + 0x3A0) > 0x64) {
        *(s32 *)((s8 *)self + 0x3A0) = 0;
    }
    *(s32 *)((s8 *)self + 0x3A4) = (u16) (*(u16 *)((s8 *)self + 0x1C) + (s32) (10.0f * (*(f32 *)((s8 *)self + 0x38) + *(f32 *)((s8 *)self + 0x40)))) % 100;
    *(f32 *)((s8 *)self + 0x3A8) = 0.0f;
    *(f32 *)((s8 *)self + 0x398) = 1.0f;
    *(s32 *)((s8 *)self + 0x394) = 0;
    *(s32 *)((s8 *)self + 0x390) = 0;
    VecCopy__FP3VecPC3Vec(arg0 + 0x378, arg0 + 0x384);
    subtract_vector((Vec_80368C14 *) (self + 0x378), self + 0x38);
    *(f32 *)((s8 *)self + 0x37C) = 0.0f;
    if (vector_length((Vec_80368C14 *) (self + 0x378)) <= 1e-05f) {
        *(f32 *)((s8 *)self + 0x378) = 1.0f;
    }
    normalize_vector(self + 0x378);
    *(f32 *)((s8 *)self + 0x378) *= 4.166667f;
    *(f32 *)((s8 *)self + 0x380) *= 4.166667f;
    *(u32 *)((s8 *)self + 0x3B0) = (u32)create_particle_emitter(self + 0x38, 0x146);
    if (*(u32 *)((s8 *)self + 0x3B0) != 0U) {
        ((TBoss4Type2 *)(*(void **)((s8 *)self + 0x3B0)))->set_flags(0x40);
    }
    return arg0;
}
#undef self
#pragma pop

s32 create__13TBoss6MagMineFi(s32 arg0) {
    s32 var_r31;
    s32 parent;

    var_r31 = __nw__7TObjectFUl(0x3B4);
    if (var_r31 != 0) {
        parent = __nw__7TObjectFUl(0x20);
        if (parent != 0) {
            parent = TObjControl__ct(parent, tl_04);
        }
        var_r31 = TBoss6MagMine__ct(var_r31, parent, arg0);
    }
    return var_r31;
}

void spawn_mag_mine_at__13TBoss6MagMineFPvPv(void *arg0, void *arg1) {
    Params_80369598 p;
    u32 boss;
    boss = TBoss6PlotFalz::get_hp();
    if (boss == 0 || get_phase__8TObjFishFv() != 6) {
        return;
    }
    TBoss4DarkFalz__sub_8004B4F0(&p, (void *)(((TBoss6Type1 *)boss)->get_mag_mine_ptr()));
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&p.a, arg0);
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&p.b, arg1);
    p.f8 = 1;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&p.pos, &p.a);
    if (((TBoss6PlotFalz *)boss)->get_next_point((s16 *)&p, (s16 *)&p.f6) != 0) {
        create__13TBoss6MagMineFi((s32)&p);
    }
}

s32 get_field_0x42c__13TBoss6MagMineFPv(void* p) { return *(s32*)((char*)p + 0x42c); }

    extern int TBoss6PlotFalz__type2_instance;
int TBoss6PlotFalz__sub_8036964C(void) {  return TBoss6PlotFalz__type2_instance; }

}
