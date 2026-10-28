#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/unk/TUnk_804E1CA8.h"
#include "pso/player/TUnk_804E20FC.h"
#include "pso/player/TUnk_804E23F0.h"
#include "pso/TItemLoad.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804E22F4.h"
#include "pso/player/TUnk_804E2000.h"
#include "pso/player/TUnk_804E1F04.h"
#include "pso/unk/TUnk_804E1BB0.h"
#include "pso/player/TUnk_804E21F8.h"
#include "pso/item/TItem.h"

struct Vec_802D52E8 { f32 x, y, z; };

extern "C" {
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void TObjPlayer__sub_802D5B78(void *a, void *b);
void do_action_447_from_packet__10TObjPlayerFPvPv(void *self, void *arg);
void *__dt__13TUnk_804E1BB0Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E1CA8Fv(void *arg0, s16 arg1);
int spawn_particle_effect(void*, int);
void TItemWeapon__ct(void *);
void *__dt__11TItemWeaponFv(void *arg0, s16 arg1);
void *__dt__13TUnk_804E23F0Fv(void *arg0, s16 arg1);
void set_status_flags__10TObjPlayerFUl(void *, int);

extern s32 lbl_804E1BB0[];

void *TUnk_804E1BB0::init_state_513(s32 _w1, void *_w2) {
    TItemWeapon__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E1BB0;
    set_status_flags__10TObjPlayerFUl(this, 513);
    return this;
}

u8 *TObjPlayer::create_state_513() {
    u8 *temp_r3;
    u8 *var_r0;
    if (this != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804E1BB0 *)temp_r3)->init_state_513(tl_05, this)));
        }
        return var_r0;
    }
    return NULL;
}
void *__dt__13TUnk_804E1BB0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E1BB0;
        __dt__11TItemWeaponFv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern s32 lbl_804E1CA8[];

void *__dt__13TUnk_804E1CA8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E1CA8;
        __dt__13TUnk_804E23F0Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

int TObjPlayer::do_action_447() { return spawn_particle_effect(this, 447); }
void do_action_447_from_packet__10TObjPlayerFPvPv(void *self, void *arg) {
    Vec_802D52E8 v;
    TObjPlayer__sub_802D5B78(arg, &v);
    ((TObjPlayer *)(&v))->do_action_447();
}

}

namespace P802D5318 {

extern "C" {

void setup_radar_marker__10TObjPlayerFPvPv(TObjPlayer *arg0, void *arg1);
void* setup_state__10TObjPlayerFPv(void* a0);
int init_state_445__10TObjPlayerFPv(void);
s32 set_radar_marker_params__10TObjPlayerFPvPv();
int set_status_flags__10TObjPlayerFUl(void*, void*);

extern const f32 lbl_805DE788;
extern const f32 lbl_805DE78C;

void setup_radar_marker__10TObjPlayerFPvPv(TObjPlayer *player, void *arg1) {
    set_radar_marker_params__10TObjPlayerFPvPv();
    if (player->is_mode_two_and_ready() != 0) {
        player->drain_owner_hp_fraction(lbl_805DE788);
        *(s32 *)((s8 *)arg1 + 0x10) = 0xA;
        *(s32 *)((s8 *)arg1 + 0x44) = (s32) ((TUnk_804E1CA8 *)player)->projectile;
        *(f32 *)((s8 *)arg1 + 0x4C) = lbl_805DE78C;
    }
}

    extern unsigned char fn_80109974[];
    extern unsigned char do_action_447_from_packet__10TObjPlayerFPvPv[];
    extern unsigned char lbl_804E1CA8[];
    extern const float lbl_805DE790;
void* setup_state__10TObjPlayerFPv(void* a0) { init_state_445__10TObjPlayerFPv(); *(int*)((char*)a0 + 0x18) = (int)lbl_804E1CA8; *(float*)((char*)a0 + 0x200) = lbl_805DE790; set_status_flags__10TObjPlayerFUl(a0, (void*)32); ((TUnk_804E1CA8 *)a0)->m_208 = (int)do_action_447_from_packet__10TObjPlayerFPvPv; *(int*)((char*)a0 + 0x204) = (int)fn_80109974; return a0; }

}

}

void *create_timed_particle_emitter_with_angles(void *pos, void *dir, s32 id, s32 a, s32 b, s32 flags);
namespace P802D53E4 {

struct V_802D5478 { s32 a; s32 b; s32 c; };

struct P_802D5478 { f32 x; f32 y; f32 z; };

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *);
void spawn_hit_particles_at_vec__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
s32 TObjPlayer__sub_802D5B78(void *, void *);
void spawn_hit_particles_at__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2);
extern const f64 lbl_804725B8[];
extern const f32 lbl_805DE794;
f32 atan2_float(f32 y, f32 x);
void set_position_xy__10TObjPlayerFff(f32, f32);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
void spawn_hit_particles__10TObjPlayerFiPv(s32 arg0, const P_802D5478 *arg1);
void* init_needle_effect__10TObjPlayerFPv(void* a0);
void set_radar_marker_flag__10TObjPlayerFPvPv(void *arg0, void *arg1);
int init_state_445__10TObjPlayerFPv(void);
s32 set_radar_marker_params__10TObjPlayerFPvPv();

void set_radar_marker_flag__10TObjPlayerFPvPv(void *arg0, void *arg1) {
    set_radar_marker_params__10TObjPlayerFPvPv();
    *(s32 *)((s8 *)arg1 + 0x50) = 0x8000;
}

    extern unsigned char fn_80109974[];
    extern unsigned char create_needle_effect[];
    extern unsigned char lbl_804E20FC[];
    extern const float lbl_805DE78C;
void* init_needle_effect__10TObjPlayerFPv(void* a0) { init_state_445__10TObjPlayerFPv(); *(int*)((char*)a0 + 0x18) = (int)lbl_804E20FC; *(float*)((char*)a0 + 0x200) = lbl_805DE78C; *(int*)((char*)a0 + 0x204) = (int)fn_80109974; ((TUnk_804E20FC *)a0)->m_208 = (int)create_needle_effect; return a0; }

void spawn_hit_particles__10TObjPlayerFiPv(s32 pos, const P_802D5478 *arg1) {
    s32 v[3];
    create_timed_particle_emitter((void *)pos, 0x1EF, 0, 0xF);
    v[0] = 0;
    v[1] = (s32)(lbl_804725B8[0] * atan2_float(arg1->x, arg1->z));
    v[2] = 0;
    if (create_timed_particle_emitter_with_angles((void *)pos, (void *)v, 0x1B8, 0, 0xF, 4) != 0U) {
        set_position_xy__10TObjPlayerFff(lbl_805DE794, lbl_805DE794);
    }
}

void spawn_hit_particles_at_vec__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    VecCopy__FP3VecPC3Vec(&sp8);
    spawn_hit_particles__10TObjPlayerFiPv((s32)&sp8, (const P_802D5478 *)(arg2));
}
void spawn_hit_particles_at__10TObjPlayerFiii(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp8;
    TObjPlayer__sub_802D5B78((void *)arg1, &sp8);
    spawn_hit_particles__10TObjPlayerFiPv((s32)&sp8, (const P_802D5478 *)(arg2));
}

}

}

struct O_802D576C { u8 pad[0x24a]; s16 v; };

typedef struct E_802D56F0 { u8 p[0xC]; } E_802D56F0;

typedef struct S_802D56F0 {
    u8 pad0[0xF4];
    s32 fF4;
    u8 padF8[0x20C - 0xF8];
    E_802D56F0 e[1];
} S_802D56F0;

struct Sub_802D564C { u8 pad0[0x60]; s32 f60; };

struct Ent_802D564C { s32 a; s32 b; s32 c; };

struct VBase_802D564C { char pad[0x18]; };

struct Pl_802D564C : VBase_802D564C {
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
    virtual void m21();
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
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60(void *);
    u8 pad1c[0xF0 - 0x1C];
    Sub_802D564C *f0F0;
    s32 f0F4;
    u8 padF8[0x20C - 0xF8];
    Ent_802D564C arr[5];
    s16 f248;
    s16 f24A;
    u8 pad24C[4];
    s32 f250;
};

struct V_802D577C { f32 x, y, z; };

extern "C" {
s32 send_activate_effect__5TItemFl(void *, s16);
void spawn_item__10TObjPlayerFi(s32 arg0);
s32 is_hidden__5TItemFv(void *);
void draw_weapon_model__11TItemWeaponFv(void);
void rotate_matrix_x(s32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_object(void *child);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
s32 rotate_matrix_about_axis(int, void *, int);
void set_matrix_identity(u8 *arg0);
s32 transform_point_by_current_matrix(void *, void *);
extern V_802D577C lbl_8047259C;
extern V_802D577C player_pb_zero_vec_block;
int set_radar_marker_params__10TObjPlayerFPvPv(void);
void init_state_445__10TObjPlayerFPv(void *);

extern s32 lbl_804E2000[];
extern s32 spawn_hit_particles_at__10TObjPlayerFiii[];
extern s32 spawn_hit_particles_at_vec__10TObjPlayerFiii[];

void *TUnk_804E2000::enter_state_341() {
    init_state_445__10TObjPlayerFPv(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E2000;
    this->m_1fc = 341;
    this->m_208 = spawn_hit_particles_at__10TObjPlayerFiii;
    *(s32 **)((s8 *)this + 0x204) = spawn_hit_particles_at_vec__10TObjPlayerFiii;
    return this;
}

    extern const float lbl_805DE790;
void TObjPlayer::set_radar_marker_pos(int a0, void* a1) { set_radar_marker_params__10TObjPlayerFPvPv(); *(float*)((char*)a1 + 0x38) = lbl_805DE790; }

void TObjPlayer::spawn_item_from_arg(s32 arg0, s32 arg1) {
    spawn_item__10TObjPlayerFi((arg1));
}

void TUnk_804E21F8::emit_marker_effects() {
    Ent_802D564C *p;
    s32 v;
    s32 step;
    s32 n;
    s32 cnt;
    p = ((Pl_802D564C *)this)->arr;
    cnt = ((Pl_802D564C *)this)->f24A;
    n = cnt;
    v = ((Pl_802D564C *)this)->f250 - ((Pl_802D564C *)this)->f0F0->f60;
    step = 0x10000 / cnt;
    while (n != 0) {
        fire_shot_at_target((void *)(p++), (void *)(((Pl_802D564C *)this)->f0F4), (s32)v);
        v += step;
        n--;
    }
    ((Pl_802D564C *)this)->m60((u8 *)((Pl_802D564C *)this)->f0F0 + 0x2FC);
    ((Pl_802D564C *)this)->f24A = 0;
    ((Pl_802D564C *)this)->f248 = 0x87;
}

void TUnk_804E21F8::reserved_53() {
    E_802D56F0 *p;
    s32 n;
    draw_weapon_model__11TItemWeaponFv();
    if (is_hidden__5TItemFv(this) == 0) {
        n = *(s16 *)(((u8 *)this) + 0x24A);
        p = ((S_802D56F0 *)((u8 *)this))->e;
        while (n != 0) {
            push_matrix();
            post_translate_matrix(p++);
            rotate_matrix_x(0, -0x4000);
            draw_ginja_object((void *)(((S_802D56F0 *)((u8 *)this))->fF4));
            pop_matrix();
            n--;
        }
    }
}

void TUnk_804E21F8::vfunc_17(s32 x) {
    O_802D576C *self = (O_802D576C *)this;
    if (x < 5) self->v = x;
}

void TUnk_804E21F8::sub_802D577C() {
    V_802D577C *pb;
    V_802D577C *pa;
    u8 *p;
    u8 *q;
    s32 ang2;
    s16 n;
    u8 *arg0 = (u8 *) this;
    s32 ang;
    s32 step;
    s32 step2;
    s32 cnt;
    n = *(s16 *)((s8 *)arg0 + 0x24A);
    if (n != 0) {
        ang = *(s32 *)&this->unk_250;
        cnt = n;
        p = arg0 + 0x20C;
        q = *(u8 * *)&this->player + 0x2FC;
        pa = &lbl_8047259C;
        pb = &player_pb_zero_vec_block;
        ang2 = 0x31C7;
        step = 0x10000 / n;
        step2 = 0x238E / n;
        while (cnt != 0) {
            V_802D577C a = *pa;
            a.z = this->m_24c;
            V_802D577C b = *pb;
            b.x = cos_table_lookup(ang2);
            b.y = sin_table_lookup(ang2);
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(q);
            rotate_matrix_about_axis(0, &b, ang);
            transform_point_by_current_matrix(&a, p);
            pop_matrix();
            ang += step;
            ang2 += step2;
            cnt--;
            p += 0xC;
        }
        *(s32 *)&this->unk_250 += 0x38E;
    }
}

void TUnk_804E21F8::update_weapon() {
    s16 temp_r4;
    s16 temp_r4_2;
    temp_r4 = this->m_248;
    temp_r4 += 1;
    this->m_248 = temp_r4;
    if ((s16) temp_r4 == 0x96) {
        temp_r4_2 = *(s16 *)((s8 *)this + 0x24A);
        if (temp_r4_2 < 5) {
            *(s16 *)((s8 *)this + 0x24A) = (temp_r4_2 + 1);
            send_activate_effect__5TItemFl(this, *(s16 *)((s8 *)this + 0x24A));
        }
        this->m_248 = 0;
    }
    sub_802D577C();
}

}

namespace P802D5900 {

struct V3_802D595C { f32 x; f32 y; f32 z; };

struct S_802D595C {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x204 - 0x1C];
    void *f204;
    void *f208;
    V3_802D595C v[5];
    s16 f248;
    s16 f24A;
};

extern "C" {
void spawn_item__10TObjPlayerFi(s32 arg0);
void spawn_item_thunk__10TObjPlayerFii(s32 arg0, s32 arg1);
extern u8 lbl_804E21F8[];
extern const f32 lbl_805DE798;
void init_state_445__10TObjPlayerFPv(void *);
void alloc_and_init__10TObjPlayerFlll(s32, s32, s32);
void create_and_init_effect__10TObjPlayerFlPUll(s32, void *, s32);
S_802D595C *init_mag_effect_state__10TObjPlayerFPv(S_802D595C *arg0);
void reset_animation_state__10TObjPlayerFPv(void *arg0);
f32 TObjPlayer__sub_8017A1A4(s32, s32);

extern f32 lbl_805DE790;

void reset_animation_state__10TObjPlayerFPv(void *arg0) {
    ((TUnk_804E21F8 *)arg0)->m_248 = 0;
    *(s16 *)((s8 *)arg0 + 0x24A) = 0;
    ((TUnk_804E21F8 *)arg0)->m_24c = (f32) (lbl_805DE790 + TObjPlayer__sub_8017A1A4(*(s32 *)((s8 *)arg0 + 0xF0), 0));
    *(s32 *)((s8 *)arg0 + 0x250) = 0;
    ((TUnk_804E21F8 *)arg0)->sub_802D577C();
}

S_802D595C *init_mag_effect_state__10TObjPlayerFPv(S_802D595C *arg0) {
    s32 i;
    V3_802D595C *p;
    init_state_445__10TObjPlayerFPv(arg0);
    arg0->vt = lbl_804E21F8;
    arg0->f248 = 0;
    arg0->f24A = 0;
    p = arg0->v;
    for (i = 0; i < 5; i++) {
        p->x = lbl_805DE798;
        p->y = lbl_805DE798;
        p->z = lbl_805DE798;
        p++;
    }
    arg0->f204 = (void *)alloc_and_init__10TObjPlayerFlll;
    arg0->f208 = (void *)create_and_init_effect__10TObjPlayerFlPUll;
    return arg0;
}

void spawn_item_thunk__10TObjPlayerFii(s32 arg0, s32 arg1) {
    spawn_item__10TObjPlayerFi((arg1));
}

}

}

extern s32 lbl_804E22F4[];
extern s32 alloc_and_init__10TObjPlayerFlll[];
extern s32 create_and_init_effect__10TObjPlayerFlPUll[];

void *TUnk_804E22F4::init_type_447() {
    init_state_445__10TObjPlayerFPv(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E22F4;
    this->m_1fc = 447;
    *(s32 **)((s8 *)this + 0x204) = alloc_and_init__10TObjPlayerFlll;
    this->m_208 = create_and_init_effect__10TObjPlayerFlPUll;
    return this;
}

extern s32 lbl_804E1F04[];
extern s32 TItemWpnCardEffect__sub_8032E588[];
extern s32 create_aux_object__10TObjPlayerFlPUll[];

void *TUnk_804E1F04::init_vtable_and_handlers_341() {
    init_state_445__10TObjPlayerFPv(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E1F04;
    this->m_1fc = 341;
    *(s32 **)((s8 *)this + 0x204) = TItemWpnCardEffect__sub_8032E588;
    this->m_208 = create_aux_object__10TObjPlayerFlPUll;
    return this;
}

namespace P802D5ABC {

extern "C" {

void* init_vtable_and_field200__10TObjPlayerFPv(void* a0);
void spawn_item__10TObjPlayerFi(s32 arg0);
s32 spawn_particle_effect(s32, s32);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
int init_state_445__10TObjPlayerFPv(void);
s32 set_position_xy__10TObjPlayerFff(s32, f32, f32);

    extern unsigned char lbl_804E1E08[];
    extern const float lbl_805DE790;
void* init_vtable_and_field200__10TObjPlayerFPv(void* a0) { init_state_445__10TObjPlayerFPv(); *(int*)((char*)a0 + 0x18) = (int)lbl_804E1E08; *(float*)((char*)a0 + 0x200) = lbl_805DE790; return a0; }

extern f32 lbl_805DE78C;
extern f32 lbl_805DE79C;

void spawn_item__10TObjPlayerFi(s32 arg0) {
    s32 spC;
    s32 sp8;
    s32 particle_effect;

    particle_effect = spawn_particle_effect(arg0, 0x1BF);
    if (particle_effect != 0) {
        TItemLoad::lookup_item_data(0xD, &spC);
        TItemLoad::get_data_entry(0xD, &sp8);
        attach_particle_model((u8 *)particle_effect, spC, sp8, 0, 0, lbl_805DE78C);
        set_position_xy__10TObjPlayerFff(particle_effect, lbl_805DE79C, lbl_805DE79C);
    }
}

}

}
