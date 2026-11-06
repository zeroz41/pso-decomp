#include "pso/effect/TParticleCtrl.h"
#include "pso/TBoss6SwordShot.h"
#include "pso/TObject.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"

#include <stddef.h>
extern "C" {
void *__dt__15TBoss6SwordShotFv(void *arg0, s16 arg1);
void run_task__15TBoss6SwordShotFv(u8 *arg0);
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void __dt__7TObjectFv(void *, int);
void __dl__7TObjectFPv(void *);
void *__vt__15TBoss6SwordShot[6] = {
    0, 0, (void *)__dt__15TBoss6SwordShotFv, (void *)run_task__15TBoss6SwordShotFv,
    (void *)render__7TObjectFv, (void *)render_shadows__7TObjectFv,
};
}
struct Stack_80356C80 {
    s32 sp8;
    s32 spC;
};

struct RecoveredGlobal_80356B18___vt__15TBoss6SwordWave { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80356B18___vt__15TBoss6SwordWave_size[sizeof(RecoveredGlobal_80356B18___vt__15TBoss6SwordWave) == 0x18 ? 1 : -1];

struct W_80356D10 { s32 w[1]; };

struct Vec_803564F4 { f32 x, y, z; };

struct Wave_803564F4 { u8 pad0[0x1C]; s32 owner; Vec_803564F4 pos; u8 x2C[4]; u8 x30[0x24]; f32 radius; };

struct Vec_803567D0 { f32 x, y, z; };

struct Pair_8035663C { s32 a; f32 b; };

struct Vec_8035663C { f32 x, y, z; };

struct VBase_8035663C { char pad[0x18]; };

struct VObj_8035663C : VBase_8035663C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(s32, Pair_8035663C, int, int, int);
};

extern "C" {
u8 *__nw__7TObjectFUl(s32);
u8 test_rock_bit__15TBoss6SwordWaveFiUc(s32 arg0, u8 arg1);
void set_bit__15TBoss6SwordWaveFiUc(s32 arg0, u8 arg1);
f32 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 __ct__7TObjectFP7TObject(void *, void *);
void fn_80356E30(s32 *p);
extern RecoveredGlobal_80356B18___vt__15TBoss6SwordWave __vt__15TBoss6SwordWave;
extern s32 lbl_805D43A8;
u8 *__ct__15TBoss6SwordWaveFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
void queue_destruction__7TObjectFv(void *arg0);
s32 query_teammate_state__9TObjEneDDFv();
extern const f32 lbl_805E0010;
extern const f32 lbl_805E0014;
void clear_bit__15TBoss6SwordWaveFPvUc(W_80356D10 *arg0, u8 arg1);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
void *spawn_particle_effect(void *pos, s32 id);
u8 TBoss6SwordWave__sub_80356D08(u32 arg1, u32 arg2);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
f32 xyz_distance(void *, void *);
extern u8 lbl_80479388[];
extern const f32 lbl_805DFFFC;
extern const f32 lbl_805E0000;
extern const f32 lbl_805E0004;
extern const f32 lbl_805E0008;
f32 atan2_float(f32 y, f32 x);
s32 get_point__10TBoss6RockFllPf(s32, void *, void *);
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
s32 normalize_vector(void *);
extern s32 lbl_805E000C;
int get_player_data__10TObjPlayerFi(int a0);
s32 is_active__14TBoss6PlotFalzFv();
}
struct Pair_803561C4 { s32 a; f32 b; };
struct VBase_18_ec708a { char pad[0x18]; };
struct VObj_18_ec708a : VBase_18_ec708a {
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
    virtual s32 m21(s32, struct Pair_803561C4, int, int, int);
};

struct Vec_803561C4 { f32 x, y, z; };

void damage_players_in_radius(u8 *arg0) {
    Vec_803561C4 v;
    s32 n;
    s32 i;
    u8 *pl;

    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (((s32 (*)(void *))is_active__14TBoss6PlotFalzFv)(pl) != 0) {
            VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
            subtract_vector(&v, arg0 + 0x20);
            v.y = 0.0f;
            if (!(vector_length(&v) > *(f32 *)((s8 *)arg0 + 0x2C))) {
                s32 r = TBoss6PlotFalz::rand_vary_count(*(s32 *)((s8 *)arg0 + 0x34), 0.1f);
                Pair_803561C4 pr;
                pr.a = 0;
                pr.b = (f32)r;
                ((VObj_18_ec708a *)pl)->m21(*(s32 *)((s8 *)arg0 + 0x1C), pr, 0, -1, -1);
            }
        }
    }
}

void run_task__15TBoss6SwordShotFv(u8 *arg0) {
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        damage_players_in_radius(arg0);
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x30) > 7) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
}
void *__dt__15TBoss6SwordShotFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 0x18) = __vt__15TBoss6SwordShot;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct Shot_80356374 {
    s32 f0;
    u8 pad4[0x14];
    void *vt18;
    s32 owner;
    struct { f32 x, y, z; } pos;
    f32 speed;
    s32 f30;
    s32 life;
};

extern "C" {
u8 *fn_8035648C(s32 arg0, s32 arg1, s32 arg2, f32 farg0);
extern s32 lbl_805D43AC;
u8 *TBoss6SwordShot__ct(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0);

#pragma push
#pragma opt_common_subs off
#define self ((Shot_80356374 *)arg0)
u8 *TBoss6SwordShot__ct(void *arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    f32 scale;
    f32 v;
    void *p;
    __ct__7TObjectFP7TObject(arg0, (void *)arg1);
    self->vt18 = (s32 *)__vt__15TBoss6SwordShot;
    self->f0 = lbl_805D43AC;
    self->owner = arg1;
    VecCopy((Vec *)&self->pos, (const Vec *)arg2);
    self->speed = farg0;
    self->f30 = 0;
    v = *dispatch_shared_handler_a__6TLobbyFl(0x2B);
    self->life = (s32)v;
    if (0.0f == v) {
        self->life = 0x14;
    }
    if (arg3 != 0) {
        scale = 1.0f;
        if (self->speed > 15.0f) {
            scale = self->speed / 15.0f;
        }
        if ((p = spawn_particle_effect_with_flags(&self->pos, 0x212, 0x40)) != NULL) {
            ((TParticleCtrl *)p)->set_scale(scale, 1.0f);
        }
        if ((p = spawn_particle_effect_with_flags(&self->pos, 0x213, 0x40)) != NULL) {
            ((TParticleCtrl *)p)->set_scale(scale, 1.0f);
        }
    }
    return (u8 *)arg0;
}
#undef self
#pragma pop

#pragma push
#pragma fp_contract on
u8 *fn_8035648C(s32 arg0, s32 arg1, s32 arg2, f32 farg0) {
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x38));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TBoss6SwordShot__ct(temp_r3, arg0, arg1, arg2, farg0));
    }
    return var_r0;
}
#pragma pop

}

#include "pso/TBoss6SwordWave.h"
#include "pso/boss/TBoss6Rock.h"
#include "pso/boss/TBoss6Type2.h"

#pragma push
#pragma fp_contract on
s32 TBoss6SwordWave::spawn_wave_ring_particles() {
    Wave_803564F4 *o = (Wave_803564F4 *)this;
    f32 d;
    f32 f;
    s32 step;
    s32 ang;
    d = 6.28f * o->radius;
    if (d <= lbl_805E0004) {
        f = 1.0f;
    } else {
        f = lbl_805E0000 / d;
    }
    step = (s32)(lbl_805DFFFC * f);
    for (ang = 0; ang < 0x10000; ang += step) {
        s32 seg = ((s32 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(o->x30, ang);
        if (((s32 (*)(void *, s32))test_rock_bit__15TBoss6SwordWaveFiUc)(o->x30, seg) != 0) {
            Vec_803564F4 v = o->pos;
            v.x += o->radius * sin_table_lookup(ang);
            v.z += o->radius * cos_table_lookup(ang);
            if (!(xyz_distance(&v, lbl_80479388) > lbl_805E0008)) {
                spawn_particle_effect_with_flags(&v, 0x212, 0x40);
                if (((TBoss6Type2 *)(o->owner))->get_rotation_timer() == 0) {
                    spawn_particle_effect(&v, 0x213);
                } else {
                    spawn_particle_effect_with_flags(&v, 0x229, 0x2000);
                }
            }
        }
    }
}
#pragma pop

struct W_80356D10;

s32 TBoss6SwordWave::check_player_hits() {
    void *a = (void *)this;
    s32 n;
    s32 i;
    VObj_8035663C *pl;
    u8 *arg0 = (u8 *)a;
    u8 t;
    s32 v;
    f32 d;
    Vec_8035663C dir;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (VObj_8035663C *)get_player_data__10TObjPlayerFi(i);
        if (is_active__14TBoss6PlotFalzFv() != 0) {
            VecCopy((Vec *)&dir, (const Vec *)((u8 *)pl + 0x38));
            subtract_vector(&dir, arg0 + 0x20);
            dir.y = 0.0f;
            d = vector_length(&dir);
            if (d < *(f32 *)((s8 *)arg0 + 0x50) || d > *(f32 *)((s8 *)arg0 + 0x54)) {
                continue;
            }
            t = ((u8 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(arg0 + 0x30,
                        (s32)(10430.38043493439 * atan2_float(dir.x, dir.z)));
            if (((s32 (*)(void *, u8))test_rock_bit__15TBoss6SwordWaveFiUc)(arg0 + 0x30, t) == 0) {
                continue;
            }
            v = *(s32 *)((s8 *)arg0 + 0x5C);
            if (((TBoss6Type2 *)(*(s32 *)((s8 *)arg0 + 0x1C)))->get_rotation_timer() != 0) {
                v = (s32)((f32)v * *(f32 *)((s8 *)arg0 + 0x60));
            }
            Pair_8035663C pr;
            s32 r = TBoss6PlotFalz::rand_vary_count(v, 0.1f);
            pr.a = 0;
            pr.b = (f32)r;
            pl->m21(*(s32 *)((s8 *)arg0 + 0x1C), pr, 0, -1, -1);
        }
    }
}

s32 TBoss6SwordWave::break_rocks_in_wave() {
    Vec_803567D0 pt;
    Vec_803567D0 d;
    Vec_803567D0 va;
    Vec_803567D0 vb;
    Vec_803567D0 n;
    f32 scale;
    u8 *arg0 = (u8 *)this;
    s32 i;
    u8 t;
    s32 a1;
    s32 a2;
    s32 lo;
    s32 hi;
    f32 dist;
    for (i = 0; i < 32; i++) {
        if (get_point__10TBoss6RockFllPf(i, &pt, &scale) == 0) {
            continue;
        }
        VecCopy((Vec *)&d, (const Vec *)&pt);
        subtract_vector(&d, arg0 + 0x20);
        d.y = 0.0f;
        dist = vector_length(&d);
        if (dist < *(f32 *)((s8 *)arg0 + 0x50) || dist > *(f32 *)((s8 *)arg0 + 0x54)) {
            continue;
        }
        t = ((u8 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(arg0 + 0x30,
                (s32)(10430.38043493439 * atan2_float(d.x, d.z)));
        if (((s32 (*)(void *, u8))test_rock_bit__15TBoss6SwordWaveFiUc)(arg0 + 0x30, t) == 0) {
            continue;
        }
        ((void (*)(void *, u8))clear_bit__15TBoss6SwordWaveFPvUc)(arg0 + 0x30, t);
        TBoss6Rock::reset_rock_state(i);
        if (dist <= lbl_805E0004) {
            continue;
        }
        n.x = -d.z;
        n.y = 0.0f;
        n.z = d.x;
        normalize_vector(&n);
        n.x *= scale;
        n.z *= scale;
        VecCopy((Vec *)&va, (const Vec *)&pt);
        vec3_add_to(&va, &n);
        VecCopy((Vec *)&vb, (const Vec *)&pt);
        subtract_vector(&vb, &n);
        a1 = (s32)(10430.38043493439 * atan2_float(va.x - *(f32 *)((s8 *)arg0 + 0x20), va.z - *(f32 *)((s8 *)arg0 + 0x28)));
        a2 = (s32)(10430.38043493439 * atan2_float(vb.x - *(f32 *)((s8 *)arg0 + 0x20), vb.z - *(f32 *)((s8 *)arg0 + 0x28)));
        lo = ((s32 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(arg0 + 0x30, a1);
        hi = ((s32 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(arg0 + 0x30, a2);
        if (hi < lo) {
            hi += lbl_805E000C;
        }
        for (; lo <= hi; lo++) {
            ((void (*)(void *, s32))clear_bit__15TBoss6SwordWaveFPvUc)(arg0 + 0x30, lo);
        }
    }
}

void TBoss6SwordWave::render() {  }

#pragma push
#pragma opt_common_subs off
void TBoss6SwordWave::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    if (query_teammate_state__9TObjEneDDFv() == 0) {
        break_rocks_in_wave();
        check_player_hits();
        if (*(f32 *)((s8 *)arg0 + 0x58) < lbl_805E0010) {
            spawn_wave_ring_particles();
        }
        *(f32 *)((s8 *)arg0 + 0x58) = (f32) (*(f32 *)((s8 *)arg0 + 0x58) + lbl_805E0010);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x58);
        if (temp_f1 > lbl_805E0014) {
            *(f32 *)((s8 *)arg0 + 0x58) = (f32) (temp_f1 - lbl_805E0014);
        }
        *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)arg0 + 0x54);
        *(f32 *)((s8 *)arg0 + 0x54) = (f32) (*(f32 *)((s8 *)arg0 + 0x54) + lbl_805E0010);
        if (*(f32 *)((s8 *)arg0 + 0x54) > *(f32 *)((s8 *)arg0 + 0x2C)) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
}
#pragma pop

TBoss6SwordWave::~TBoss6SwordWave() {}
u8 *__ct__15TBoss6SwordWaveFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    f32 temp_f1;
    f32 temp_f2;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__15TBoss6SwordWave.value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D43A8;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    VecCopy((Vec *)(arg0 + 0x20), (const Vec *)(arg2));
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x2C) = farg0;
    ((TBoss6SwordWave *)(arg0 + 0x30))->fill_range((void *)arg3, (void *)arg4);
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) 0.0f;
    temp_f2 = *dispatch_shared_handler_a__6TLobbyFl(0x2C);
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) temp_f2;
    if (0.0f == temp_f2) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x14;
    }
    temp_f1 = *(f32 *)((s8 *)(dispatch_shared_handler_a__6TLobbyFl(0x2F)) + 8);
    *(f32 *)((s8 *)arg0 + 0x60) = temp_f1;
    if (0.0f == temp_f1) {
        *(f32 *)((s8 *)arg0 + 0x60) = (f32) 1.0f;
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
u8 *TBoss6SwordWave::create(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x64));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(__ct__15TBoss6SwordWaveFv(temp_r3, arg0, arg1, arg2, arg3, farg0));
    }
    return var_r0;
}
#pragma pop

u8 test_rock_bit__15TBoss6SwordWaveFiUc(s32 arg0, u8 arg1) {
    typedef char sp8_offset[(offsetof(Stack_80356C80, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80356C80, spC) == 0x4) ? 1 : -1];
    Stack_80356C80 stack;
    TBoss6SwordWave::split_bit_index(arg0, arg1, &stack.spC, &stack.sp8);
    return (u8) (((1 << stack.sp8) & *(s32 *)((s8 *)arg0 + (stack.spC * 4))) != 0);
}

void TBoss6SwordWave::split_bit_index(s32 arg0, u8 v, void *a, void *b) {
    s32 x = v;
    *(s32 *)a = x / 32;
    *(s32 *)b = x % 32;
}

u8 TBoss6SwordWave__sub_80356D08(u32 arg1, u32 arg2) {
    return (u8) (arg2 >> 8U);
}

void clear_bit__15TBoss6SwordWaveFPvUc(W_80356D10 *arg0, u8 arg1) {
    s32 idx;
    s32 bit;
    TBoss6SwordWave::split_bit_index((s32)arg0, arg1, &idx, &bit);
    arg0->w[idx] &= ~(1 << bit);
}

void TBoss6SwordWave::fill_range(void *arg1, void *arg2) {
    s32 a = ((s32 (*)(void *, void *))TBoss6SwordWave__sub_80356D08)(this, arg1);
    s32 b = ((s32 (*)(void *, void *))TBoss6SwordWave__sub_80356D08)(this, arg2);
    if (a > b) {
        b += 0x100;
    }
    fn_80356E30((s32 *)this);
    while (a <= b) {
        ((void (*)(void *, s32))set_bit__15TBoss6SwordWaveFiUc)(this, a);
        a++;
    }
}

void set_bit__15TBoss6SwordWaveFiUc(s32 arg0, u8 arg1) {
  s32 spC;
  s32 sp8;
  s32 temp_r5;
  s8 *new_var;
  TBoss6SwordWave::split_bit_index(arg0, arg1, &spC, &sp8);
  temp_r5 = spC * 4;
  new_var = ((s8 *) arg0) + temp_r5;
  *((s32 *) (((s8 *) arg0) + temp_r5)) = (*((s32 *) new_var)) | (1 << sp8);
}
