#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/vector.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/barbaray/TBoss7Tentacle.h"
#include "pso/boss/barbaray/TBoss7PhotonBullet.h"
#include "pso/boss/barbaray/TBoss7TentacleNeedle.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"

struct Ten_802F08A8;
extern "C" {
s32 approach_angle_limited(s32, s32, s32);
void TBoss7Tentacle__sub_802F0608(TBoss7Tentacle *tentacle, f32 len);
s32 subtract_vector(void *, void *);
s32 transform_point_by_current_matrix(void *, void *);
void push_matrix(void);
struct RecoveredGlobal_802EFB1C_lbl_80541918 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_802EFB1C_lbl_80541918;

struct VBase_18_9935f6 { char pad[0x18]; };

struct VObj_18_9935f6 : VBase_18_9935f6 {
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
    virtual s32 m20(s32, f32);
    virtual s32 m21(s32, void *, s32, s32, s32);
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual s32 m25(s32, s32, f32);
};

typedef struct Hit_802EF99C { s32 a; f32 f; } Hit_802EF99C;

typedef struct Obj_802EF99C { u8 pad0[0x44]; s32 flags[12]; } Obj_802EF99C;

struct Cnt_802EF898 { u8 pad[4]; u32 n; };

struct Ten_802EF898 { u8 pad[0x74]; f32 t; Cnt_802EF898 *c; };

typedef char RecoveredGlobal_802EFB1C_lbl_80541918_size[sizeof(RecoveredGlobal_802EFB1C_lbl_80541918) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802EFEA8_lbl_80541918 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_802EFEA8_lbl_80541918_size[sizeof(RecoveredGlobal_802EFEA8_lbl_80541918) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802EFEC4_lbl_80541918 {
    s32 value;
    u8 remaining[0xC];
};

typedef char RecoveredGlobal_802EFEC4_lbl_80541918_size[sizeof(RecoveredGlobal_802EFEC4_lbl_80541918) == 0x10 ? 1 : -1];

struct V_802F0A5C { f32 x, y, z; };

struct Ten_802F0A5C { u8 pad0[0x50]; V_802F0A5C v[14]; u32 w[14]; };

struct V_802EFF24 { f32 x, y, z; };

struct Node_802EFF24 { u32 flags; u8 pad4[4]; V_802EFF24 pos; u8 pad14[8]; s32 ang; u8 pad20[0x18]; };

struct Tent_802EFF24 { u8 pad0[0x50]; V_802EFF24 pos[14]; s32 ang[14]; };

struct Cnt_802F08A8 { u8 pad[4]; u32 n; };

struct Ten_802F08A8 { u8 pad0[0x20]; Cnt_802F08A8 *c; u8 pad1[0x134 - 0x24]; f32 t; f32 d; };

struct Ten_802F0A5C;

typedef struct Anim_802F0BE8 { u8 pad0[4]; u32 n; } Anim_802F0BE8;

s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s32 attach_particle_model(int, int, int, int, int, f32);
f32 horizontal_distance_squared(void *, void *);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);
s32 notify_fish_obj__10TObjPlayerFPv(int);
s32 queue_boss_effect__10TObjPlayerFPv(int);
s32 TObjPlayer__sub_802E80A0();
void draw_effect__10TObjPlayerFv(void *);
void rotate_matrix_by_node_angles(void *, int);
s32 scale_current_matrix(void *);
void post_translate_matrix(void *);

extern V_802F0A5C TBoss7Tentacle__segment_offsets[];
extern s32 __vt__20TBoss7TentacleNeedle[];
extern Node_802EFF24 lbl_80541528[];
extern u32 TBoss7Tentacle__needle_offsets[];
extern RecoveredGlobal_802EFB1C_lbl_80541918 boss7_tentacle_needle_target_state;
extern s32 lbl_805D6948;

// .rodata 0x80474070-0x804740C8 and the .sdata names are not this TU's: defined here, run_task would
// address the tables and its 10430.38 literal off one hoisted .rodata base, and defined after their
// first use CW would place them in .data.
extern const f32 lbl_80474070[3];
extern const s32 TBoss7Tentacle__target_angle_table[4];
extern const s32 boss7_tentacle_angle_table[4];
extern const char *lbl_805D3FD8;
extern const char *boss7_tentacle_needle_name_ptr;

struct Ten_802F01D0 { u8 pad0[0x50]; V_802F0A5C v[14]; };

void __ct__7TObjectFP7TObject(void *, void *);
void copy_model_node(u8 *dst, u8 *src);

struct Arr_802EFD08 { u8 pad[0x44]; s32 a[12]; };

// Unit-owned .bss banks (claim 1eadd7fe: pso/boss/TBoss7TentacleNeedle .bss
// 0x80541528-0x80541918). Definition order == address order: nodes 0x310,
// segment_offsets +0x310 (0xA8), needle_offsets +0x3B8 (0x38).
// In-TU defined (twin TBoss2Tentacle precedent, 100.0): enables MWCC
// base-hoist into r31 + copy-propagation sink; externs remat instead.
Node_802EFF24 lbl_80541528[14];
V_802F0A5C TBoss7Tentacle__segment_offsets[14];
u32 TBoss7Tentacle__needle_offsets[14];
RecoveredGlobal_802EFB1C_lbl_80541918 boss7_tentacle_needle_target_state;
s32 lbl_805D6948;

// Written last-to-first: built with -inline off,deferred, which emits functions in reverse source order
// (the Needle vtable 0x804E4830 precedes the Tentacle one although every Needle virtual comes first).

void TObjPlayer__sub_802F0D30(void) {
    Node_802EFF24 *src;
    Node_802EFF24 *dst;
    s32 i;

    src = (Node_802EFF24 *)queue_boss_effect__10TObjPlayerFPv(1);
    notify_fish_obj__10TObjPlayerFPv(0x11);
    dst = lbl_80541528;
    for (i = 0; i < 12; i++) {
        copy_model_node((u8 *)dst, (u8 *)src);
        *(u32 *)&dst->pad20[0xC] = (u32)(dst + 1);
        dst++;
        src = *(Node_802EFF24 **)&src->pad20[0xC];
    }
    copy_model_node((u8 *)dst, (u8 *)src);
    *(u32 *)&dst->pad20[0x10] = (u32)(dst + 1);
    copy_model_node((u8 *)&dst[1], (u8 *)*(Node_802EFF24 **)&src->pad20[0x10]);
    for (i = 0; i < 14; i++) {
        lbl_80541528[i].flags &= ~3;
        TBoss7Tentacle__segment_offsets[i].x = (f64)lbl_80541528[i].pos.x;
        TBoss7Tentacle__segment_offsets[i].y = lbl_80541528[i].pos.y;
        TBoss7Tentacle__segment_offsets[i].z = lbl_80541528[i].pos.z;
        TBoss7Tentacle__needle_offsets[i] = (u32)lbl_80541528[i].ang;
    }
}

}

void TObjPlayer__sub_802F0D2C(void) {  }

TBoss7Tentacle::TBoss7Tentacle(TObject *object, s32 arg2, s32 arg3) : TObject(object) {
    m_name = lbl_805D3FD8;
    (*(s32 *)((s8 *)(this) + (0x1C))) = ((s32 (*)(s32))queue_boss_effect__10TObjPlayerFPv)(1);
    (*(Anim_802F0BE8 * *)((s8 *)(this) + (0x20))) = ((Anim_802F0BE8 * (*)(s32))notify_fish_obj__10TObjPlayerFPv)(0x11);
    (*(s32 *)((s8 *)(this) + (0x130))) = arg2;
    (*(s32 *)((s8 *)(this) + (0x4C))) = arg3;
    (*(s32 *)((s8 *)(this) + (0x30))) = 0;
    (*(s32 *)((s8 *)(this) + (0x34))) = 0;
    (*(s32 *)((s8 *)(this) + (0x38))) = 0;
    this->init_segments();
    (*(f32 *)((s8 *)(this) + (0x134))) = (f32)((*(Anim_802F0BE8 * *)((s8 *)(this) + (0x20)))->n - 1) * (3.0517578e-05f * (f32)rand());
    (*(f32 *)((s8 *)(this) + (0x138))) = 0.8f;
    (*(s32 *)((s8 *)(this) + (0x13C))) = 0;
    (*(s32 *)((s8 *)(this) + (0x140))) = 0;
    (*(s32 *)((s8 *)(this) + (0x144))) = 0x5EF;
    (*(s32 *)((s8 *)(this) + (0x148))) = TObjPlayer::calc_random_scaled();
    (*(f32 *)((s8 *)(this) + (0x158))) = 0.0f;
    (*(f32 *)((s8 *)(this) + (0x15C))) = 0.0f;
    (*(s32 *)((s8 *)(this) + (0x164))) = 0;
    (*(s32 *)((s8 *)(this) + (0x168))) = 0x78;
    (*(f32 *)((s8 *)(this) + (0x14C))) = 0.0f;
    (*(f32 *)((s8 *)(this) + (0x150))) = 0.0f;
    (*(f32 *)((s8 *)(this) + (0x154))) = 0.0f;
    (*(s32 *)((s8 *)(this) + (0x3C))) = 0;
    (*(f32 *)((s8 *)(this) + (0x24))) = 1.0f;
    (*(f32 *)((s8 *)(this) + (0x28))) = 1.0f;
    (*(f32 *)((s8 *)(this) + (0x2C))) = 1.0f;
}

TBoss7Tentacle::~TBoss7Tentacle() {}

void TBoss7Tentacle__sub_802F0B80(void* p) { *(u32*)((char*)p + 0x3c) &= 0xfffffffd; }

void TBoss7Tentacle__sub_802F0B70(void* p) { *(u32*)((char*)p + 0x3c) |= 0x2; }

void TBoss7Tentacle__sub_802F0B58(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = 1;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle::start_attack_at_position(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 var_r5;
    var_r5 = arg2;
    if ((var_r5 <= 0) || (var_r5 >= 0x258)) {
        var_r5 = 0x78;
    }
    *(s32 *)((s8 *)arg0 + 0x168) = var_r5;
    VecCopy((Vec *)(arg0 + 0x14C), (const Vec *)arg1);
    TBoss7Tentacle__sub_802F0A14((u8 *)(arg0));
}

void TBoss7Tentacle__sub_802F0AF0(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = 5;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle__sub_802F0AD0(void* a0) { *(float*)((char*)a0 + 0x138) = 1.6f; *(int*)((char*)a0 + 0x144) = 3038; *(int*)((char*)a0 + 0x140) = 0; *(int*)((char*)a0 + 0x34) = 0; }

void TBoss7Tentacle::init_segments() {
    Ten_802F0A5C *o = (Ten_802F0A5C *)this;
    s32 i;
    for (i = 0; i < 14; i++) {
        VecCopy((Vec *)&o->v[i], (const Vec *)&TBoss7Tentacle__segment_offsets[i]);
        o->w[i] = TBoss7Tentacle__needle_offsets[i];
    }
}

void TBoss7Tentacle__sub_802F0A44(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle__sub_802F0A2C(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = 4;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle__sub_802F0A14(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x34) = 2;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle::sub_802F09FC() {
    *(s32 *)((s8 *)((u8 *)this) + 0x34) = 3;
    *(s32 *)((s8 *)((u8 *)this) + 0x3C) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C) & 0xFFFFFFFD);
}

void TBoss7Tentacle::sub_802F09EC() { *(s32*)((char*)this + 0x140) = 0; *(s32*)((char*)this + 0x13c) = 0; }

void TBoss7Tentacle__sub_802F09C8(void* a0) { *(int*)((char*)a0 + 0x13c) = TBoss7Tentacle__target_angle_table[*(int*)((char*)a0 + 0x4c)]; *(int*)((char*)a0 + 0x140) = 0; }

void TBoss7Tentacle__sub_802F09B4(void* p) { *(s32*)((char*)p + 0x13c) = 0; *(s32*)((char*)p + 0x140) = 16384; }

void TBoss7Tentacle::setup_state() { *(int*)((char*)this + 0x13c) = TBoss7Tentacle__target_angle_table[*(int*)((char*)this + 0x4c)]; *(int*)((char*)this + 0x140) = 16384; *(int*)((char*)this + 0x38) = 0; }

void TBoss7Tentacle::reset_state() { *(int*)((char*)this + 0x13c) = 0; *(int*)((char*)this + 0x140) = 0; *(int*)((char*)this + 0x38) = 0; init_segments(); *(float*)((char*)this + 0x158) = 20.0f; *(int*)((char*)this + 0x164) = 0; *(float*)((char*)this + 0x15c) = 0.0f; *(float*)((char*)this + 0x160) = 1.0f; }

void TBoss7Tentacle__sub_802F0918(void* p) { *(s32*)((char*)p + 0x13c) = 0; *(s32*)((char*)p + 0x140) = 16384; }

u8 TBoss7Tentacle__sub_802F0904(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x30) == 4);
}

void TBoss7Tentacle::advance_path_position() {
    Ten_802F08A8 *o = (Ten_802F08A8 *)this;
    f32 lim = (f32)(o->c->n - 1);
    o->t = o->t + o->d;
    if (o->t >= lim) {
        o->t = o->t - lim;
    }
}

#pragma push
#pragma fp_contract on
void TBoss7Tentacle__sub_802F0608(TBoss7Tentacle *tentacle, f32 len) {
    s32 i;
    s32 prev, ang;
    s32 j;
    f32 scale = 0.5f;
    f32 half = scale * len;
    f32 h = 60.0f - tentacle->m_44;
    f32 a;
    f32 step = tentacle->m_158;
    a = -(h / (half * half));
    step /= 9.0f;
    f32 dx, dy, px, py, w, k;
    for (i = 0; i < 10; i++) {
        f32 t = step * (f32)i;
        f32 d = t - half;
        Vec *pt = (Vec *)((u8 *)tentacle->m_50 + (i + 2) * sizeof(Vec));
        pt->x = scale * t;
        pt->y = scale * (d * (a * d) + h);
    }
    tentacle->m_50[2].x = 0.0f;
    tentacle->m_50[2].y = 0.0f;
    tentacle->m_50[2].z = 0.0f;
    px = 0.0f;
    py = 0.0f;
    prev = 0;
    for (j = 3; j <= 11; j++) {
        f32 x = tentacle->m_50[j].x;
        f32 y = tentacle->m_50[j].y;
        dx = x - px;
        dy = y - py;
        px = x;
        py = y;
        ang = (s32)(10430.38043493439 * atan2_float(dy, dx));
        tentacle->m_f8[j - 1] = ang - prev;
        prev = ang;
        tentacle->m_50[j].x = newton_sqrtf(dy * dy + dx * dx);
        tentacle->m_50[j].y = 0.0f;
        tentacle->m_50[j].z = 0.0f;
    }
    tentacle->m_f8[11] = tentacle->m_f8[10];
    w = tentacle->m_15c;
    if (w < 1.0f) {
        k = 1.0f - w;
        k *= tentacle->m_160;
        for (i = 2; i < 12; i++) {
            tentacle->m_50[i].x = tentacle->m_50[i].x * w + k * TBoss7Tentacle__segment_offsets[i].x;
        }
        tentacle->m_f8[2] = (s32)(16384.0f * (1.0f - tentacle->m_15c) + (f32)tentacle->m_f8[2] * w);
        for (i = 3; i < 12; i++) {
            tentacle->m_f8[i] = (s32)((f32)tentacle->m_f8[i] * w);
        }
    }
}
#pragma pop

void run_task__14TBoss7TentacleFv(u8 *boss7_tentacle) {
    ((TBoss7Tentacle *)boss7_tentacle)->switch_state();
    switch (*(s32 *)((s8 *)boss7_tentacle + 0x30)) {
    case 0:
        ((TBoss7Tentacle *)boss7_tentacle)->advance_path_position();
        *(s32 *)((s8 *)boss7_tentacle + 0x148) = *(s32 *)((s8 *)boss7_tentacle + 0x148) + *(s32 *)((s8 *)boss7_tentacle + 0x144);
        *(s32 *)((s8 *)boss7_tentacle + 0x13C) = (s32)(1365.0f * (1.0f + sin_table_lookup(*(s32 *)((s8 *)boss7_tentacle + 0x148))));
        if (!(*(s32 *)((s8 *)boss7_tentacle + 0x4C) & 1)) {
            *(s32 *)((s8 *)boss7_tentacle + 0x13C) = -*(s32 *)((s8 *)boss7_tentacle + 0x13C);
        }
        break;
    case 1:
        ((TBoss7Tentacle *)boss7_tentacle)->advance_path_position();
        *(s32 *)((s8 *)boss7_tentacle + 0x140) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x140), 0x4000, 0x280);
        break;
    case 2:
        *(s32 *)((s8 *)boss7_tentacle + 0x13C) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x13C), 0, 0x80);
        if (*(s32 *)((s8 *)boss7_tentacle + 0x13C) == 0) {
            ((TBoss7Tentacle *)boss7_tentacle)->sub_802F09FC();
        }
        break;
    case 3: {
        V_802F0A5C p;
        V_802F0A5C v;
        f32 len;
        s32 i;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        push_matrix();
        set_matrix_identity(0);
        TObjPlayer::concat_matrix(0, *(s32 *)((s8 *)boss7_tentacle + 0x130));
        transform_point_by_current_matrix(&v, boss7_tentacle + 0x40);
        pop_matrix();
        VecCopy((Vec *)&v, (const Vec *)(boss7_tentacle + 0x14C));
        subtract_vector(&v, boss7_tentacle + 0x40);
        len = normalize_vector_xz((Vec *)(&v));
        *(s32 *)((s8 *)boss7_tentacle + 0x13C) = (s32)(10430.38043493439 * atan2_float(v.x, v.z)) + 0x8000;
        VecCopy((Vec *)&p, (const Vec *)(boss7_tentacle + 0x14C));
        switch (*(s32 *)((s8 *)boss7_tentacle + 0x38)) {
        case 0:
            *(f32 *)((s8 *)boss7_tentacle + 0x160) -= 0.1f;
            if (*(f32 *)((s8 *)boss7_tentacle + 0x160) <= 0.1f) {
                *(f32 *)((s8 *)boss7_tentacle + 0x160) = 0.1f;
                *(s32 *)((s8 *)boss7_tentacle + 0x164) = 0;
                *(s32 *)((s8 *)boss7_tentacle + 0x38) = 1;
            }
            for (i = 2; i < 12; i++) {
                ((Ten_802F01D0 *)boss7_tentacle)->v[i].x = *(f32 *)((s8 *)boss7_tentacle + 0x160) * TBoss7Tentacle__segment_offsets[i].x;
            }
            *(s32 *)((s8 *)boss7_tentacle + 0x100) = 0x4000;
            break;
        case 1:
            *(f32 *)((s8 *)boss7_tentacle + 0x158) += 8.0f;
            if (*(f32 *)((s8 *)boss7_tentacle + 0x158) > len) {
                *(f32 *)((s8 *)boss7_tentacle + 0x158) = len;
                *(s32 *)((s8 *)boss7_tentacle + 0x164) = 0;
                *(s32 *)((s8 *)boss7_tentacle + 0x38) = 2;
                {
                    u32 st = TBoss7Joint::get_state();
                    if (st != 0U) {
                        ((TBoss7PhotonBullet *)st)->emit_hit_effect(&p);
                    }
                }
                play_sound_effect(0x3A809, &p, 0, 0);
            }
            if (*(f32 *)((s8 *)boss7_tentacle + 0x158) >= 0.4f * len) {
                *(f32 *)((s8 *)boss7_tentacle + 0x15C) = 1.0f;
            } else {
                *(f32 *)((s8 *)boss7_tentacle + 0x15C) = *(f32 *)((s8 *)boss7_tentacle + 0x158) / (0.4f * len);
            }
            *(s32 *)((s8 *)boss7_tentacle + 0x140) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x140), boss7_tentacle_angle_table[*(s32 *)((s8 *)boss7_tentacle + 0x4C)], 0x100);
            TBoss7Tentacle__sub_802F0608((TBoss7Tentacle *)boss7_tentacle, len);
            break;
        case 2:
            *(s32 *)((s8 *)boss7_tentacle + 0x164) = *(s32 *)((s8 *)boss7_tentacle + 0x164) + 1;
            if (*(s32 *)((s8 *)boss7_tentacle + 0x164) > *(s32 *)((s8 *)boss7_tentacle + 0x168)) {
                *(s32 *)((s8 *)boss7_tentacle + 0x164) = 0;
                *(f32 *)((s8 *)boss7_tentacle + 0x160) = 1.0f;
                *(s32 *)((s8 *)boss7_tentacle + 0x38) = 3;
            }
            break;
        case 3:
            *(f32 *)((s8 *)boss7_tentacle + 0x158) -= 8.0f;
            if (*(f32 *)((s8 *)boss7_tentacle + 0x158) < 20.0f) {
                *(f32 *)((s8 *)boss7_tentacle + 0x158) = 20.0f;
                *(s32 *)((s8 *)boss7_tentacle + 0x38) = 2;
                TBoss7Tentacle__sub_802F0A2C(boss7_tentacle);
            }
            if (*(f32 *)((s8 *)boss7_tentacle + 0x158) >= 0.4f * len) {
                *(f32 *)((s8 *)boss7_tentacle + 0x15C) = 1.0f;
            } else {
                *(f32 *)((s8 *)boss7_tentacle + 0x15C) = *(f32 *)((s8 *)boss7_tentacle + 0x158) / (0.4f * len);
            }
            *(s32 *)((s8 *)boss7_tentacle + 0x140) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x140), 0, 0x100);
            TBoss7Tentacle__sub_802F0608((TBoss7Tentacle *)boss7_tentacle, len);
            break;
        }
        break;
    }
    case 4:
        ((TBoss7Tentacle *)boss7_tentacle)->advance_path_position();
        *(s32 *)((s8 *)boss7_tentacle + 0x13C) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x13C), TBoss7Tentacle__target_angle_table[*(s32 *)((s8 *)boss7_tentacle + 0x4C)], 0x80);
        break;
    case 5:
        ((TBoss7Tentacle *)boss7_tentacle)->advance_path_position();
        *(s32 *)((s8 *)boss7_tentacle + 0x140) = approach_angle_limited(*(s32 *)((s8 *)boss7_tentacle + 0x140), 0, 0x280);
        if (*(s32 *)((s8 *)boss7_tentacle + 0x140) == 0) {
            TBoss7Tentacle__sub_802F0A44(boss7_tentacle);
        }
        break;
    }
    ((TBoss7Tentacle *)boss7_tentacle)->update_extend_amount();
}

void TBoss7Tentacle::switch_state() {
    s32 state = *(s32 *)((s8 *)this + 0x34);
    if (state != (s32) *(s32 *)((s8 *)this + 0x30)) {
        switch (state) {
        case 0:
            sub_802F09EC();
            break;
        case 1:
            TBoss7Tentacle__sub_802F09C8((void*)(this));
            break;
        case 4:
            TBoss7Tentacle__sub_802F09B4((void*)(this));
            break;
        case 2:
            setup_state();
            break;
        case 3:
            reset_state();
            break;
        case 5:
            TBoss7Tentacle__sub_802F0918((void*)(this));
            break;
        }
        *(s32 *)((s8 *)this + 0x30) = (s32) *(s32 *)((s8 *)this + 0x34);
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss7Tentacle::update_extend_amount() {
    u8 *arg0 = (u8 *)this;
    if (*(s32 *)((s8 *)arg0 + 0x3C) & 2) {
        *(f32 *)((s8 *)arg0 + 0x2C) = (f32) (*(f32 *)((s8 *)arg0 + 0x2C) - 0.1f);
        if (*(f32 *)((s8 *)arg0 + 0x2C) < 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
        }
    } else {
        *(f32 *)((s8 *)arg0 + 0x2C) += 0.2f;
        if (*(f32 *)((s8 *)arg0 + 0x2C) > 1.0f) {
            *(f32 *)((s8 *)arg0 + 0x2C) = 1.0f;
        }
    }
}
#pragma pop

void render__14TBoss7TentacleFv(u8 *arg0) {
    s32 temp_r0_2;
    s32 var_ctr;
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;
    u8 *temp_r7;
    u8 *temp_r8;
    ((s32 (*)(void))draw_effect__10TObjPlayerFv)();
    ((s32 (*)(void))push_matrix)();
    switch (*(s32 *)((s8 *)arg0 + 0x30)) {
    case 0:
        set_motion_packed_rotation();
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x130)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x13C)));
        scale_current_matrix((void *) ((u8 *)(arg0) + 0x24));
        ((s32 (*)(void *, int, f32))draw_model_motion)((void *) (*(s32 **)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), (f32) (*(f32 *)((s8 *)arg0 + 0x134)));
        clear_motion_packed_rotation();
        break;
    case 1:
    case 4:
    case 5:
        set_motion_packed_rotation();
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x130)));
        rotate_matrix_zyx(0, (*(s32 *)((s8 *)arg0 + 0x140)), (*(s32 *)((s8 *)arg0 + 0x13C)), 0);
        scale_current_matrix((void *) ((u8 *)(arg0) + 0x24));
        ((s32 (*)(void *, int, f32))draw_model_motion)((void *) (*(s32 **)((s8 *)arg0 + 0x1C)), (int) (*(s32 *)((s8 *)arg0 + 0x20)), (f32) (*(f32 *)((s8 *)arg0 + 0x134)));
        clear_motion_packed_rotation();
        break;
    case 2:
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x130)));
        rotate_matrix_zyx(0, (*(s32 *)((s8 *)arg0 + 0x140)), (*(s32 *)((s8 *)arg0 + 0x13C)), 0);
        scale_current_matrix((void *) ((u8 *)(arg0) + 0x24));
        draw_chunk_object((*(s32 **)((s8 *)arg0 + 0x1C)));
        break;
    case 3:
        ((s32 (*)(void *))post_translate_matrix)((void *) ((u8 *)(arg0) + 0x40));
        scale_current_matrix((void *) (lbl_80474070));
        rotate_matrix_zyx(0, 0, (*(s32 *)((s8 *)arg0 + 0x13C)), (*(s32 *)((s8 *)arg0 + 0x140)));
        for (var_ctr = 0; var_ctr < 14; var_ctr++) {
            lbl_80541528[var_ctr].pos.x = ((Tent_802EFF24 *)arg0)->pos[var_ctr].x;
            lbl_80541528[var_ctr].pos.y = ((Tent_802EFF24 *)arg0)->pos[var_ctr].y;
            lbl_80541528[var_ctr].pos.z = ((Tent_802EFF24 *)arg0)->pos[var_ctr].z;
            lbl_80541528[var_ctr].ang = ((Tent_802EFF24 *)arg0)->ang[var_ctr];
        }
        scale_current_matrix((void *) ((u8 *)(arg0) + 0x24));
        draw_chunk_object((lbl_80541528));
        break;
    }
    ((s32 (*)(void))pop_matrix)();
}

extern "C" {

void TObjPlayer__sub_802EFEC4(void) {
    lbl_805D6948 = queue_boss_effect__10TObjPlayerFPv(5);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEC4_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 0) = notify_fish_obj__10TObjPlayerFPv(0x13);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEC4_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 4) = notify_fish_obj__10TObjPlayerFPv(0x14);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEC4_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 8) = notify_fish_obj__10TObjPlayerFPv(0x12);
}

void fn_802EFEA8(void) {
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEA8_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 0) = 0;
    lbl_805D6948 = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEA8_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 4) = 0;
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_802EFEA8_lbl_80541918 *)&boss7_tentacle_needle_target_state).value) + 8) = 0;
}

#pragma push
#pragma fp_contract on
u8 *TBoss7TentacleNeedle__ct(TBoss7TentacleNeedle *self, void *parent, V_802F0A5C *pos) {
    __ct__7TObjectFP7TObject((void *)self, parent);
    *(s32 **)((s8 *)self + 0x18) = __vt__20TBoss7TentacleNeedle;
    self->m_name = boss7_tentacle_needle_name_ptr;
    *(f32 *)((s8 *)self + 0x34) = 1e-05f;
    *(s32 *)((s8 *)self + 0x28) = 0;
    *(s32 *)((s8 *)self + 0x2C) = (s32)(65536.0f * (3.0517578e-05f * (f32)rand()));
    *(s32 *)((s8 *)self + 0x30) = 0;
    *(f32 *)((s8 *)self + 0x1C) = 5.0f * (3.0517578e-05f * (f32)rand()) + pos->x - 2.5f;
    *(f32 *)((s8 *)self + 0x20) = pos->y;
    *(f32 *)((s8 *)self + 0x24) = 5.0f * (3.0517578e-05f * (f32)rand()) + pos->z - 2.5f;
    *(s32 *)((s8 *)self + 0x38) = 0;
    *(s32 *)((s8 *)self + 0x3C) = 0;
    s32 w0; s32 w1; s32 w2; s32 v[3];
    w2 = ((s32 *)pos)[0];
    w0 = w2;
    w1 = ((s32 *)pos)[1];
    w2 = ((s32 *)pos)[2];
    v[0] = w0;
    v[1] = w1;
    v[2] = w2;
    *(s32 *)((s8 *)self + 0x40) = (s32)create_particle_emitter(v, 0x212);
    for (s32 i = 0; i < 12; i++) {
        ((Arr_802EFD08 *)self)->a[i] = 0;
    }
    *(s32 *)((s8 *)self + 0x78) = boss7_tentacle_needle_target_state.value;
    *(f32 *)((s8 *)self + 0x74) = 0.0f;
    return (u8 *)self;
}
#pragma pop

TBoss7TentacleNeedle::~TBoss7TentacleNeedle() {
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
}

void TBoss7TentacleNeedle::run_task() {

    switch (this->m_38) {
    case 0:
        ((s32 (*)(void))advance_needle_timer__20TBoss7TentacleNeedleFv)();
        return;
    case 1:
        ((s32 (*)(void))update_retract_state__14TBoss7TentacleFPv)();
        return;
    case 2:
        ((s32 (*)(void))damage_nearby_players__14TBoss7TentacleFPv)();
        return;
    case 3:
        ((s32 (*)(void))TBoss7Tentacle__sub_802EF954)();
        return;
    }
}

void TBoss7TentacleNeedle::render() {
    draw_effect__10TObjPlayerFv(this);
    set_motion_packed_rotation();
    push_matrix();
    post_translate_matrix((void *)((char *)this + 28));
    rotate_matrix_by_node_angles((void *)((char *)this + 40), 1);
    draw_model_motion((*(void * *)&lbl_805D6948), *(void * *)&this->m_78, this->m_74);
    pop_matrix();
    clear_motion_packed_rotation();
}

void TBoss7TentacleNeedle::advance_needle_timer() {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0x3C);
    if (temp_r4 == 0x1E) {
        *(s32 *)((s8 *)this + 0x38) = 1;
        *(f32 *)((s8 *)this + 0x74) = 14.0f;
        return;
    }
    *(s32 *)((s8 *)this + 0x3C) = (s32) (temp_r4 + 1);
}

void update_retract_state__14TBoss7TentacleFPv(TBoss7Tentacle *boss7_tentacle) {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)boss7_tentacle + 0x74);
    if ((24.5f < temp_f1) && (temp_f1 <= 25.5f)) {
        boss7_tentacle->restart_particle_effect();
    }
    if (boss7_tentacle->advance_toward_limit(1.0f) != 0) {
        *(s32 *)((s8 *)boss7_tentacle + 0x38) = 2;
        *(s32 *)((s8 *)boss7_tentacle + 0x3C) = 0;
        *(s32 *)((s8 *)boss7_tentacle + 0x78) = (s32) *(s32 *)((s8 *)(&boss7_tentacle_needle_target_state.value) + 4);
        *(f32 *)((s8 *)boss7_tentacle + 0x74) = 0.0f;
    }
}

void damage_nearby_players__14TBoss7TentacleFPv(u8 *boss7_tentacle) {
    s32 i;
    u8 *p;
    ((TBoss7Tentacle *)boss7_tentacle)->advance_anim_time_wrapped(0.6f);
    for (i = 0; (u16)i != 12; i++) {
        p = (u8 *)get_player_by_client_id((u16)i);
        if (p != NULL && horizontal_distance_squared(p + 0x38, boss7_tentacle + 0x1C) < 100.0f) {
            if (*(s32 *)(boss7_tentacle + 0x3C) == 0 && ((VObj_18_9935f6 *)p)->m25(*(s32 *)(boss7_tentacle + 0x10), 0, 10.0f) != 0) {
                ((VObj_18_9935f6 *)p)->m20(*(s32 *)(boss7_tentacle + 0x10), 1.0f);
            }
            if (obj_testFlags30__14TObjCollidableFUl(p, 0x801) == 0) {
                Hit_802EF99C b;
                b.a = 15;
                b.f = 100.0f;
                Hit_802EF99C a = b;
                ((VObj_18_9935f6 *)p)->m21(*(s32 *)(boss7_tentacle + 0x10), &a, 0, -1, -1);
                if (((Obj_802EF99C *)boss7_tentacle)->flags[(u16)i] == 0) {
                    spawn_particle_effect(p + 0x2FC, 0x214);
                    ((Obj_802EF99C *)boss7_tentacle)->flags[(u16)i] = 1;
                }
            }
        }
    }
    if (*(s32 *)(boss7_tentacle + 0x3C) == 0x3C) {
        *(s32 *)(boss7_tentacle + 0x38) = 3;
        *(s32 *)(boss7_tentacle + 0x3C) = 0;
        *(s32 *)(boss7_tentacle + 0x78) = *(s32 *)((u8 *)&boss7_tentacle_needle_target_state + 8);
        *(f32 *)(boss7_tentacle + 0x74) = 0.0f;
    } else {
        *(s32 *)(boss7_tentacle + 0x3C) += 1;
    }
}

void TBoss7Tentacle__sub_802EF954(void* p) { if (((TBoss7Tentacle *)p)->advance_toward_limit(1.0f) != 0) { queue_destruction__7TObjectFv(p); disallow_rendering__7TObjectFv((TObject *)p); } }

s32 TBoss7Tentacle::advance_toward_limit(f32 farg0) {
    f32 temp_f4;

    temp_f4 = *(f32 *)((s8 *)this + 0x74);
    if (temp_f4 < ((f32) *(u32 *)((s8 *)(*(void **)((s8 *)this + 0x78)) + 4) - 1.0f)) {
        *(f32 *)((s8 *)this + 0x74) = (f32) (temp_f4 + farg0);
        return 0;
    }
    *(f32 *)((s8 *)this + 0x74) = 0.0f;
    return 1;
}

s32 TBoss7Tentacle::advance_anim_time_wrapped(f32 d) {
    Ten_802EF898 *o = (Ten_802EF898 *)this;
    f32 lim = (f32)o->c->n - 1.0f;
    o->t += d;
    if (lim <= o->t) {
        o->t -= lim;
    }
}

void TBoss7Tentacle::restart_particle_effect() {
    u8 *arg0 = (u8 *)this;
  s32 particle_effect;
  s32 temp_r3;
  if (((u32) (*((u32 *) (((s8 *) arg0) + 0x40)))) != 0U)
  {
    queue_destruction__7TObjectFv((*((void **) (((s8 *) arg0) + 0x40))));
    *((u32 *) (((s8 *) arg0) + 0x40)) = 0U;
  }
  particle_effect = (s32)spawn_particle_effect((arg0 + 0x1C), 0x215);
  temp_r3 = particle_effect;
  if (temp_r3 != 0)
  {
    particle_effect = TObjPlayer__sub_802E80A0();
    attach_particle_model((int) temp_r3, (int) queue_boss_effect__10TObjPlayerFPv(4), (int) particle_effect, 0, 0, 1.0f);
  }
  play_sound_effect(0x3A809, (void *) (arg0 + 0x1C), 0, 0);
}

}
