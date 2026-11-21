#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/text_80087278.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_80356E30.h"
#include "pso/boss/olgaflow/TBoss6SwordShot.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/TBoss6SwordWave.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/text_803D96A8.h"


extern "C" {
void *__dt__15TBoss6SwordShotFv(void *arg0, s16 arg1);
void run_task__15TBoss6SwordShotFv(u8 *arg0);
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void __dt__7TObjectFv(void *, int);
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
LAYOUT_ASSERT(RecoveredGlobal_80356B18___vt__15TBoss6SwordWave_size, sizeof(RecoveredGlobal_80356B18___vt__15TBoss6SwordWave) == 0x18);

struct W_80356D10 { s32 w[1]; };

struct Wave_803564F4 { u8 pad0[0x20]; Vec pos; u8 x2C[4]; u8 x30[0x24]; f32 radius; };

struct Pair_8035663C { s32 a; f32 b; };

struct VBase_8035663C { char pad[0x18]; };

struct VObj_8035663C : VBase_8035663C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(TObject *, Pair_8035663C, int, int, int);
};

extern "C" {
u8 test_rock_bit__15TBoss6SwordWaveFiUc(saddr arg0, u8 arg1);
void set_bit__15TBoss6SwordWaveFiUc(saddr arg0, u8 arg1);
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_80356B18___vt__15TBoss6SwordWave __vt__15TBoss6SwordWave;
extern const char *TBoss6SwordWave__name;
TBoss6SwordWave *__ct__15TBoss6SwordWaveFv(u8 *arg0, TObject *owner, const Vec *position, saddr arg3, saddr arg4, f32 farg0);
s32 query_teammate_state__9TObjEneDDFv();
void clear_bit__15TBoss6SwordWaveFPvUc(W_80356D10 *arg0, u8 arg1);
u8 TBoss6SwordWave__sub_80356D08(u32 arg1, u32 arg2);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
f32 xyz_distance(void *, void *);

s32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 subtract_vector(void *, void *);
}

const char TBoss6SwordWave__class_name_string[] = "TBoss6SwordWave";
const Vec lbl_80479388 = {-10000.0f, 0.0f, 0.0f};
const char TBoss6SwordShot__class_name_string[] = "TBoss6SwordShot";
const char *TBoss6SwordWave__name = TBoss6SwordWave__class_name_string;
const char *TBoss6SwordShot__name = TBoss6SwordShot__class_name_string;

void TBoss6SwordShot::damage_players_in_radius() {
    Vec offset;
    s32 count = TLobby::get_game_mode();
    for (s32 i = 0; i < count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&offset, &player->position);
            subtract_vector(&offset, &position);
            offset.y = 0.0f;
            if (!(vector_length(&offset) > radius)) {
                s32 power = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = (f32)power;
                player->receive_direct_attack(owner, attack, NULL, -1, -1);
            }
        }
    }
}

void TBoss6SwordShot::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        damage_players_in_radius();
        age++;
        if (age > 7) {
            queue_destruction();
        }
    }
}
void *__dt__15TBoss6SwordShotFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((u8 *)arg0 + 0x18) = __vt__15TBoss6SwordShot;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_common_subs off
TBoss6SwordShot::TBoss6SwordShot(TObject *owner, const Vec *position, s32 with_particles, f32 radius)
    : TObject(owner) {
    f32 scale;
    f32 v;
    void *p;
    m_name = TBoss6SwordShot__name;
    this->owner = owner;
    VecCopy(&this->position, position);
    this->radius = radius;
    age = 0;
    v = *(f32 *)TLobby::dispatch_shared_handler_a(0x2B);
    damage = (s32)v;
    if (0.0f == v) {
        damage = 0x14;
    }
    if (with_particles != 0) {
        scale = 1.0f;
        if (this->radius > 15.0f) {
            scale = this->radius / 15.0f;
        }
        if ((p = spawn_particle_effect_with_flags(&this->position, 0x212, 0x40)) != NULL) {
            ((TParticleCtrl *)p)->set_scale(scale, 1.0f);
        }
        if ((p = spawn_particle_effect_with_flags(&this->position, 0x213, 0x40)) != NULL) {
            ((TParticleCtrl *)p)->set_scale(scale, 1.0f);
        }
    }
}
#pragma pop

TBoss6SwordShot *TBoss6SwordShot::create(TObject *owner, const Vec *position, s32 with_particles, f32 radius) {
    return new TBoss6SwordShot(owner, position, with_particles, radius);
}

#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"

void TBoss6SwordWave::spawn_wave_ring_particles() {
    Wave_803564F4 *o = (Wave_803564F4 *)this;
    f32 d;
    f32 f;
    s32 step;
    s32 ang;
    d = 6.28f * o->radius;
    if (d <= 1e-05f) {
        f = 1.0f;
    } else {
        f = 42.158997f / d;
    }
    step = (s32)(65536.0f * f);
    for (ang = 0; ang < 0x10000; ang += step) {
        s32 seg = ((s32 (*)(void *, s32))TBoss6SwordWave__sub_80356D08)(o->x30, ang);
        if (((s32 (*)(void *, s32))test_rock_bit__15TBoss6SwordWaveFiUc)(o->x30, seg) != 0) {
            Vec v = o->pos;
            v.x += o->radius * sin_table_lookup(ang);
            v.z += o->radius * cos_table_lookup(ang);
            if (!(xyz_distance(&v, (void *)&lbl_80479388) > 400.0f)) {
                spawn_particle_effect_with_flags(&v, 0x212, 0x40);
                if (((TBoss6Type2 *)owner)->get_rotation_timer() == 0) {
                    spawn_particle_effect(&v, 0x213);
                } else {
                    spawn_particle_effect_with_flags(&v, 0x229, 0x2000);
                }
            }
        }
    }
}

struct W_80356D10;

void TBoss6SwordWave::check_player_hits() {
    void *a = (void *)this;
    s32 n;
    s32 i;
    VObj_8035663C *pl;
    u8 *arg0 = (u8 *)a;
    u8 t;
    s32 v;
    f32 d;
    Vec dir;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        pl = (VObj_8035663C *)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active((TObjPlayer *)pl) != 0) {
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
            if (((TBoss6Type2 *)owner)->get_rotation_timer() != 0) {
                v = (s32)((f32)v * *(f32 *)((s8 *)arg0 + 0x60));
            }
            Pair_8035663C pr;
            s32 r = TBoss6PlotFalz::rand_vary_count(v, 0.1f);
            pr.a = 0;
            pr.b = (f32)r;
            pl->m21(owner, pr, 0, -1, -1);
        }
    }
}

// The wave's rock bitmap has 256 bit slots (TBoss6SwordWave__sub_80356D08 maps an angle to one); a range that wraps
// is unwrapped by one bitmap length. The code loads it from .sdata2 ahead of run_task's float literals: a file
// constant read through an inlined reference, emitted at its first user (the TBoss6Type2.cpp form).
static const s32 wave_bit_count = 0x100;

inline const s32 &get_wave_bit_count() { return wave_bit_count; }

void TBoss6SwordWave::break_rocks_in_wave() {
    Vec pt;
    Vec d;
    Vec va;
    Vec vb;
    Vec n;
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
        if (TBoss6Rock::get_point(i, &pt, &scale) == 0) {
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
        if (dist <= 1e-05f) {
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
            hi += get_wave_bit_count();
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
    if (TObjEneDD::query_teammate_state() == 0) {
        break_rocks_in_wave();
        check_player_hits();
        if (*(f32 *)((s8 *)arg0 + 0x58) < 6.6666665f) {
            spawn_wave_ring_particles();
        }
        *(f32 *)((s8 *)arg0 + 0x58) += 6.6666665f;
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x58);
        if (temp_f1 > 29.9f) {
            *(f32 *)((s8 *)arg0 + 0x58) = (f32) (temp_f1 - 29.9f);
        }
        *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)arg0 + 0x54);
        *(f32 *)((s8 *)arg0 + 0x54) += 6.6666665f;
        if (*(f32 *)((s8 *)arg0 + 0x54) > *(f32 *)((s8 *)arg0 + 0x2C)) {
            ((TObject *)arg0)->queue_destruction();
        }
    }
}
#pragma pop

TBoss6SwordWave::~TBoss6SwordWave() {}
TBoss6SwordWave *__ct__15TBoss6SwordWaveFv(u8 *arg0, TObject *owner, const Vec *position, saddr arg3, saddr arg4, f32 farg0) {
    f32 temp_f1;
    f32 temp_f2;
    __ct__7TObjectFP7TObject(arg0, owner);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__15TBoss6SwordWave.value;
    *(s32 *)((s8 *)arg0 + 0) = (saddr) TBoss6SwordWave__name;
    ((TBoss6SwordWave *)arg0)->owner = owner;
    VecCopy((Vec *)(arg0 + 0x20), position);
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x2C) = farg0;
    ((TBoss6SwordWave *)(arg0 + 0x30))->fill_range((void *)arg3, (void *)arg4);
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) 0.0f;
    temp_f2 = *(f32 *)TLobby::dispatch_shared_handler_a(0x2C);
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) temp_f2;
    if (0.0f == temp_f2) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0x14;
    }
    temp_f1 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 8);
    *(f32 *)((s8 *)arg0 + 0x60) = temp_f1;
    if (0.0f == temp_f1) {
        *(f32 *)((s8 *)arg0 + 0x60) = (f32) 1.0f;
    }
    return (TBoss6SwordWave *)arg0;
}

TBoss6SwordWave *TBoss6SwordWave::create(TObject *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius) {
    u8 *memory = (u8 *)TObject::operator new(0x64);
    TBoss6SwordWave *wave = (TBoss6SwordWave *)memory;
    if (wave != NULL) {
        wave = __ct__15TBoss6SwordWaveFv(memory, owner, position, start_angle, end_angle, radius);
    }
    return wave;
}

u8 test_rock_bit__15TBoss6SwordWaveFiUc(saddr arg0, u8 arg1) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80356C80, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80356C80, spC) == 0x4);
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
    TBoss6SwordWave::split_bit_index((saddr)arg0, arg1, &idx, &bit);
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

void set_bit__15TBoss6SwordWaveFiUc(saddr arg0, u8 arg1) {
  s32 spC;
  s32 sp8;
  s32 temp_r5;
  s8 *new_var;
  TBoss6SwordWave::split_bit_index(arg0, arg1, &spC, &sp8);
  temp_r5 = spC * 4;
  new_var = ((s8 *) arg0) + temp_r5;
  *((s32 *) (((s8 *) arg0) + temp_r5)) = (*((s32 *) new_var)) | (1 << sp8);
}
