#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/TBoss2Tentacle.h"

TBoss2Tentacle::~TBoss2Tentacle() {}

#include "types.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/system/BmlResource.h"

struct V3_80039DE0 { f32 x, y, z; };

struct Obj_80039DE0 { u8 pad[0x30]; V3_80039DE0 pts[14]; s32 vals[14]; };

struct Obj_80039C44 { u8 pad[0x114]; f32 pos; f32 speed; };

struct Vec_8003933C { f32 x, y, z; };

struct Ten_8003933C { char pad0[0x30]; Vec_8003933C pos[14]; s32 vals[14]; };

struct Obj_80039F50 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void *vt;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x2C - 0x28];
    s32 f2C;
    V3_80039DE0 pts[14];
    s32 vals[14];
    s32 f110;
    f32 f114;
    f32 f118;
    s32 f11C;
    s32 f120;
    s32 f124;
    s32 f128;
    f32 f12C;
    f32 f130;
    f32 f134;
    f32 f138;
    f32 f13C;
    u8 pad140[0x14C - 0x140];
    s32 f14C;
    u8 pad150[4];
    s32 f154;
};

struct V3_80039994 { f32 x, y, z; };

struct Obj_80039994 {
    u8 pad0[0x30];
    V3_80039994 pts[14];
    s32 vals[14];
    u8 pad110[0x138 - 0x110];
    f32 f138;
    f32 f13C;
    u8 pad140[0x144 - 0x140];
    f32 f144;
    u8 pad148[0x150 - 0x148];
    f32 f150;
};

extern "C" {
u8 TBoss2Tentacle__sub_80039CA0(u8 *arg0);
void TBoss2Tentacle__sub_80039DB0(void* p);
extern V3_80039DE0 TBoss2Tentacle__segment_points[];
extern s32 TBoss2Tentacle__segment_point_defaults[];
void TBoss2Tentacle__sub_8003A0AC(void);
extern DragonMotion *TBoss2Tentacle__motion_data;
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern DragonModelNode tentacle_model_nodes[];
extern s32 *lbl_805D4BD0;
extern s32 lbl_805D4BD8;
extern const f32 lbl_805D8528;
void render__14TBoss2TentacleFv(u8 *arg0);
f64 atan2_float(f32, f32);
s32 emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *, void *);
void *get_instance__13TBoss2DeRolLeFv(void);
void TBoss2Tentacle__sub_8003998C(void);
void TBoss2Tentacle__sub_80039CB4(void* p);
void TBoss2Tentacle__sub_80039D50(void* p);
void TBoss2Tentacle__sub_80039D64(void* a0);
void TBoss2Tentacle__sub_80039DBC(void* p);
void TBoss2Tentacle__sub_80039DD4(void* p);
s32 approach_angle_limited(s32, s32, s32);
s32 play_sound_effect(int, void *, int, int);
f32 sin_table_lookup(s32);
s32 matrix_mult_vec(int, void *, void *);
s32 set_matrix_identity(int);
s32 subtract_vector(void *, void *);
extern int TBoss2Tentacle__rest_angles[];
extern s32 boss2_tentacle_angle_limit_table[];
extern const f64 lbl_80435BA8[];
extern const f32 lbl_805D852C;
extern const float TBoss2Tentacle__data_805D8530;
extern const float TBoss2Tentacle__data_805D8534;
extern const f32 lbl_805D8538;
void run_task__14TBoss2TentacleFv(u8 *arg0);
s32 rand();
extern s32 TBoss2Tentacle__name;
extern const f32 lbl_805D855C;
extern const f32 lbl_805D8560;
f32 newton_sqrtf(f32);
void TBoss2Tentacle__sub_80039990(void);
extern const f32 lbl_805D8548;
extern const f32 lbl_805D854C;
extern const f32 lbl_805D8550;
extern const f32 lbl_805D8554;
void TBoss2Tentacle__sub_80039994(Obj_80039994 *o, f32 len);
void TBoss2Tentacle__sub_80039D98(void* p);
void TBoss2Tentacle__sub_80039DC8(void* p);
void TBoss2Tentacle__sub_80039E54(void* a0);
void TBoss2Tentacle__sub_80039E68(void* p);
void TBoss2Tentacle__sub_8003A0A8(void);

struct DragonMotion;
void render__14TBoss2TentacleFv(u8 *arg0) {
    s32 temp_r0_2;
    s32 i;
    s32 var_r3;
    s32 var_r4;
    s32 var_r5;
    u8 *temp_r7;
    u8 *temp_r8;
    set_motion_packed_rotation();
    TObjFish::set_global_param(lbl_805D4BD8);
    push_matrix();
    switch (*(s32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x110)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x11C)));
        draw_model_motion((lbl_805D4BD0), (TBoss2Tentacle__motion_data), (f32) (*(f32 *)((s8 *)arg0 + 0x114)));
        break;
    case 1:
    case 4:
    case 5:
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x110)));
        rotate_matrix_x(0, (int) (*(s32 *)((s8 *)arg0 + 0x120)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x11C)));
        draw_model_motion((lbl_805D4BD0), (TBoss2Tentacle__motion_data), (f32) (*(f32 *)((s8 *)arg0 + 0x114)));
        break;
    case 2:
        TObjPlayer::concat_matrix(0, (int) (*(s32 *)((s8 *)arg0 + 0x110)));
        rotate_matrix_x(0, (int) (*(s32 *)((s8 *)arg0 + 0x120)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x11C)));
        draw_chunk_object((lbl_805D4BD0));
        break;
    case 3:
        post_translate_matrix(arg0 + 0x140);
        scale_matrix(0, lbl_805D8528, lbl_805D8528, lbl_805D8528);
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x11C)));
        rotate_matrix_z(0, (int) (*(s32 *)((s8 *)arg0 + 0x120)));
        for (i = 0; i < 14; i++) {
            tentacle_model_nodes[i].position.x = ((Ten_8003933C *)arg0)->pos[i].x;
            tentacle_model_nodes[i].position.y = ((Ten_8003933C *)arg0)->pos[i].y;
            tentacle_model_nodes[i].position.z = ((Ten_8003933C *)arg0)->pos[i].z;
            tentacle_model_nodes[i].rotation.z = ((Ten_8003933C *)arg0)->vals[i];
        }
        draw_chunk_object((tentacle_model_nodes));
        break;
    }
    pop_matrix();
    clear_motion_packed_rotation();
}

typedef V3_80039DE0 V3_800394DC;
typedef struct { u8 pad[0x30]; V3_800394DC pts[14]; } Ten_800394DC;
#define F(t, o) (*(t *)(arg0 + (o)))
void run_task__14TBoss2TentacleFv(u8 *arg0) {
    if (F(s32, 0x20) != F(s32, 0x1C)) {
        switch (F(s32, 0x20)) {
        case 0:
            ((TBoss2Tentacle *)arg0)->sub_80039D88();
            break;
        case 1:
            TBoss2Tentacle__sub_80039D64(arg0);
            break;
        case 4:
            TBoss2Tentacle__sub_80039D50(arg0);
            break;
        case 2:
            ((TBoss2Tentacle *)arg0)->init_motion_from_table();
            break;
        case 3:
            ((TBoss2Tentacle *)arg0)->reset();
            break;
        case 5:
            TBoss2Tentacle__sub_80039CB4(arg0);
            break;
        }
        F(s32, 0x1C) = F(s32, 0x20);
    }
    switch (F(s32, 0x1C)) {
    case 0:
        ((TBoss2Tentacle *)arg0)->advance_motion_position();
        F(s32, 0x128) += F(s32, 0x124);
        F(s32, 0x11C) = lbl_805D852C * ((*(const f32 *)&TBoss2Tentacle__data_805D8530) + sin_table_lookup(F(s32, 0x128)));
        if (!(F(s32, 0x2C) & 1)) {
            F(s32, 0x11C) = -F(s32, 0x11C);
        }
        break;
    case 1:
        ((TBoss2Tentacle *)arg0)->advance_motion_position();
        F(s32, 0x120) = approach_angle_limited(F(s32, 0x120), 0x4000, 0x280);
        break;
    case 2:
        F(s32, 0x11C) = approach_angle_limited(F(s32, 0x11C), 0, 0x80);
        if (F(s32, 0x11C) == 0) {
            ((TBoss2Tentacle *)arg0)->sub_80039DA4();
        }
        break;
    case 3: {
        V3_800394DC pos;
        V3_800394DC v;
        f32 len;
        v.z = v.y = v.x = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
        push_matrix();
        set_matrix_identity(0);
        TObjPlayer::concat_matrix(0, F(s32, 0x110));
        matrix_mult_vec(0, &v, arg0 + 0x140);
        pop_matrix();
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x12C));
        subtract_vector(&v, arg0 + 0x140);
        len = normalize_vector_xz((Vec *)(&v));
        F(s32, 0x11C) = (s32)(lbl_80435BA8[0] * atan2_float(v.x, v.z)) + 0x8000;
        VecCopy((Vec *)&pos, (const Vec *)(arg0 + 0x12C));
        switch (F(s32, 0x24)) {
        case 0: {
            s32 i;
            F(f32, 0x150) -= lbl_805D8538;
            if (F(f32, 0x150) <= lbl_805D8538) {
                F(f32, 0x150) = lbl_805D8538;
                F(s32, 0x14C) = 0;
                F(s32, 0x24) = 1;
            }
            for (i = 2; i < 12; i++) {
                ((Ten_800394DC *)arg0)->pts[i].x = F(f32, 0x150) * TBoss2Tentacle__segment_points[i].x;
            }
            F(s32, 0xE0) = 0x4000;
            break;
        }
        case 1:
            F(f32, 0x138) += 8.0f;
            if (F(f32, 0x138) > len) {
                void *inst;
                F(f32, 0x138) = len;
                F(s32, 0x14C) = 0;
                F(s32, 0x24) = 2;
                inst = get_instance__13TBoss2DeRolLeFv();
                if (inst != NULL) {
                    emit_effect_and_step__13TBoss2DeRolLeFPvPv(inst, &pos);
                }
                play_sound_effect(0x4003A507, &pos, 0, 0);
            }
            if (F(f32, 0x138) >= 0.4f * len) {
                F(f32, 0x13C) = (*(const f32 *)&TBoss2Tentacle__data_805D8530);
            } else {
                F(f32, 0x13C) = F(f32, 0x138) / (0.4f * len);
            }
            F(s32, 0x120) = approach_angle_limited(F(s32, 0x120), boss2_tentacle_angle_limit_table[F(s32, 0x2C)], 0x100);
            TBoss2Tentacle__sub_80039994((Obj_80039994 *)(arg0), len);
            break;
        case 2:
            F(s32, 0x14C)++;
            if (F(s32, 0x14C) > F(s32, 0x154)) {
                F(s32, 0x14C) = 0;
                F(f32, 0x150) = (*(const f32 *)&TBoss2Tentacle__data_805D8530);
                F(s32, 0x24) = 3;
            }
            ((void (*)(void *))TBoss2Tentacle__sub_8003998C)(arg0);
            break;
        case 3:
            F(f32, 0x138) -= 8.0f;
            if (F(f32, 0x138) < 20.0f) {
                F(f32, 0x138) = 20.0f;
                F(s32, 0x24) = 2;
                TBoss2Tentacle__sub_80039DBC(arg0);
            }
            if (F(f32, 0x138) >= 0.4f * len) {
                F(f32, 0x13C) = (*(const f32 *)&TBoss2Tentacle__data_805D8530);
            } else {
                F(f32, 0x13C) = F(f32, 0x138) / (0.4f * len);
            }
            F(s32, 0x120) = approach_angle_limited(F(s32, 0x120), 0, 0x100);
            TBoss2Tentacle__sub_80039994((Obj_80039994 *)(arg0), len);
            break;
        }
        break;
    }
    case 4:
        ((TBoss2Tentacle *)arg0)->advance_motion_position();
        F(s32, 0x11C) = approach_angle_limited(F(s32, 0x11C), ((s32 *)&TBoss2Tentacle__rest_angles)[F(s32, 0x2C)], 0x80);
        break;
    case 5:
        ((TBoss2Tentacle *)arg0)->advance_motion_position();
        F(s32, 0x120) = approach_angle_limited(F(s32, 0x120), 0, 0x280);
        if (F(s32, 0x120) == 0) {
            TBoss2Tentacle__sub_80039DD4(arg0);
        }
        break;
    }
}

void TBoss2Tentacle__sub_8003998C(void) {  }
void TBoss2Tentacle__sub_80039990(void) {  }

#pragma push
#pragma fp_contract on
void TBoss2Tentacle__sub_80039994(Obj_80039994 *o, f32 len) {
    s32 i;
    s32 prev, ang;
    s32 j;
    f32 scale = lbl_805D8548;
    f32 half = scale * len;
    f32 h = lbl_805D854C - o->f144;
    f32 a;
    f32 step = o->f138;
    a = -(h / (half * half));
    step /= lbl_805D8550;
    f32 dx, dy, px, py, w, k;
    for (i = 0; i < 10; i++) {
        f32 t = step * (f32)i;
        f32 d = t - half;
        u8 *q = (u8 *)o + (i + 2) * 12;
        *(f32 *)(q + 0x30) = scale * t;
        *(f32 *)(q + 0x34) = scale * (d * (a * d) + h);
    }
    ((void (*)(void *))TBoss2Tentacle__sub_80039990)(o);
    o->pts[2].x = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    o->pts[2].y = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    o->pts[2].z = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    px = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    py = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    prev = 0;
    for (j = 3; j <= 11; j++) {
        f32 x = o->pts[j].x;
        f32 y = o->pts[j].y;
        dx = x - px;
        dy = y - py;
        px = x;
        py = y;
        ang = (s32)(10430.38043493439 * atan2_float(dy, dx));
        o->vals[j - 1] = ang - prev;
        prev = ang;
        o->pts[j].x = newton_sqrtf(dy * dy + dx * dx);
        o->pts[j].y = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
        o->pts[j].z = (*(const f32 *)&TBoss2Tentacle__data_805D8534);
    }
    o->vals[11] = o->vals[10];
    ((void (*)(void *))TBoss2Tentacle__sub_80039990)(o);
    w = o->f13C;
    if (w < (*(const f32 *)&TBoss2Tentacle__data_805D8530)) {
        k = (*(const f32 *)&TBoss2Tentacle__data_805D8530) - w;
        k *= o->f150;
        for (i = 2; i < 12; i++) {
            o->pts[i].x = o->pts[i].x * w + k * ((V3_80039994 *)&TBoss2Tentacle__segment_points)[i].x;
        }
        o->vals[2] = (s32)(lbl_805D8554 * ((*(const f32 *)&TBoss2Tentacle__data_805D8530) - o->f13C) + (f32)o->vals[2] * w);
        for (i = 3; i < 12; i++) {
            o->vals[i] = (s32)((f32)o->vals[i] * w);
        }
    }
}
#pragma pop

void TBoss2Tentacle::advance_motion_position() {
    Obj_80039C44 *self = (Obj_80039C44 *)this;
    f32 n = (TBoss2Tentacle__motion_data->frameCount - 1);
    self->pos += self->speed;
    if (self->pos >= n) {
        self->pos -= n;
    }
}

u8 TBoss2Tentacle__sub_80039CA0(u8 *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x1C) == 4);
}

void TBoss2Tentacle__sub_80039CB4(void* p) { *(s32*)((char*)p + 0x11c) = 0; *(s32*)((char*)p + 0x120) = 16384; }

    extern const float lbl_805D8544;
void TBoss2Tentacle::reset() { *(int*)((char*)this + 0x11c) = 0; *(int*)((char*)this + 0x120) = 0; *(int*)((char*)this + 0x24) = 0; reset_segment_points(); *(float*)((char*)this + 0x138) = lbl_805D8544; *(int*)((char*)this + 0x14c) = 0; *(float*)((char*)this + 0x13c) = TBoss2Tentacle__data_805D8534; *(float*)((char*)this + 0x150) = TBoss2Tentacle__data_805D8530; }

void TBoss2Tentacle::init_motion_from_table() { *(int*)((char*)this + 0x11c) = TBoss2Tentacle__rest_angles[*(int*)((char*)this + 0x2c)]; *(int*)((char*)this + 0x120) = 16384; *(int*)((char*)this + 0x24) = 0; }

void TBoss2Tentacle__sub_80039D50(void* p) { *(s32*)((char*)p + 0x11c) = 0; *(s32*)((char*)p + 0x120) = 16384; }

void TBoss2Tentacle__sub_80039D64(void* a0) { *(int*)((char*)a0 + 0x11c) = TBoss2Tentacle__rest_angles[*(int*)((char*)a0 + 0x2c)]; *(int*)((char*)a0 + 0x120) = 0; }

void TBoss2Tentacle::sub_80039D88() { *(s32*)((char*)this + 0x120) = 0; *(s32*)((char*)this + 0x11c) = 0; }
void TBoss2Tentacle__sub_80039D98(void* p) { *(s32*)((char*)p + 0x20) = 5; }
void TBoss2Tentacle::sub_80039DA4() { *(s32*)((char*)this + 0x20) = 3; }
void TBoss2Tentacle__sub_80039DB0(void* p) { *(s32*)((char*)p + 0x20) = 2; }
void TBoss2Tentacle__sub_80039DBC(void* p) { *(s32*)((char*)p + 0x20) = 4; }
void TBoss2Tentacle__sub_80039DC8(void* p) { *(s32*)((char*)p + 0x20) = 1; }
void TBoss2Tentacle__sub_80039DD4(void* p) { *(s32*)((char*)p + 0x20) = 0; }

    extern const float lbl_805D8558;

void TBoss2Tentacle::reset_segment_points() {
    Obj_80039DE0 *self = (Obj_80039DE0 *)this;
    s32 i;
    for (i = 0; i < 14; i++) {
        VecCopy((Vec *)&self->pts[i], (const Vec *)&TBoss2Tentacle__segment_points[i]);
        self->vals[i] = TBoss2Tentacle__segment_point_defaults[i];
    }
}

void TBoss2Tentacle__sub_80039E54(void* a0) { *(float*)((char*)a0 + 0x118) = lbl_805D8558; *(int*)((char*)a0 + 0x124) = 3038; }

void TBoss2Tentacle__sub_80039E68(void* p) { TBoss2Tentacle__sub_80039D98(p); }

void TBoss2Tentacle::start_attack_at_target(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 var_r5;
    var_r5 = arg2;
    if ((var_r5 <= 0) || (var_r5 >= 0x258)) {
        var_r5 = 0x78;
    }
    *(s32 *)((s8 *)arg0 + 0x154) = var_r5;
    VecCopy((Vec *)(arg0 + 0x12C), (const Vec *)arg1);
    TBoss2Tentacle__sub_80039DB0(arg0);
}

void TBoss2Tentacle::forward_80039DC8() { TBoss2Tentacle__sub_80039DC8(this); }

}
TBoss2Tentacle::TBoss2Tentacle(TObject *parent, s32 arg2, s32 arg3) : TObject(parent) {
    s32 i;
    ((Obj_80039F50 *)this)->f0 = TBoss2Tentacle__name;
    ((Obj_80039F50 *)this)->f110 = arg2;
    ((Obj_80039F50 *)this)->f2C = arg3;
    ((Obj_80039F50 *)this)->f1C = 0;
    ((Obj_80039F50 *)this)->f20 = 0;
    ((Obj_80039F50 *)this)->f24 = 0;
    for (i = 0; i < 14; i++) {
        VecCopy((Vec *)&((Obj_80039F50 *)this)->pts[i], (const Vec *)&TBoss2Tentacle__segment_points[i]);
        ((Obj_80039F50 *)this)->vals[i] = TBoss2Tentacle__segment_point_defaults[i];
    }
    ((Obj_80039F50 *)this)->f114 = (TBoss2Tentacle__motion_data->frameCount - 1) * (lbl_805D855C * (f32)rand());
    ((Obj_80039F50 *)this)->f118 = lbl_805D8560;
    ((Obj_80039F50 *)this)->f11C = 0;
    ((Obj_80039F50 *)this)->f120 = 0;
    ((Obj_80039F50 *)this)->f124 = 0x5EF;
    ((Obj_80039F50 *)this)->f128 = TObjPlayer::calc_random_scaled();
    ((Obj_80039F50 *)this)->f138 = TBoss2Tentacle__data_805D8534;
    ((Obj_80039F50 *)this)->f13C = TBoss2Tentacle__data_805D8534;
    ((Obj_80039F50 *)this)->f14C = 0;
    ((Obj_80039F50 *)this)->f154 = 0x78;
    ((Obj_80039F50 *)this)->f12C = TBoss2Tentacle__data_805D8534;
    ((Obj_80039F50 *)this)->f130 = TBoss2Tentacle__data_805D8534;
    ((Obj_80039F50 *)this)->f134 = TBoss2Tentacle__data_805D8534;
}


void TBoss2Tentacle__sub_8003A0A8(void) {  }

extern BmlResource *lbl_805D4BA4;

DragonModelNode tentacle_model_nodes[14];
V3_80039DE0 TBoss2Tentacle__segment_points[14];
s32 TBoss2Tentacle__segment_point_defaults[14];

void TBoss2Tentacle__sub_8003A0AC(void) {
    DragonModelNode *src;
    DragonModelNode *dst;
    s32 i;
    dst = tentacle_model_nodes;
    lbl_805D4BD0 = (s32 *)lbl_805D4BA4->models[4].model;
    src = (DragonModelNode *)lbl_805D4BD0;
    TBoss2Tentacle__motion_data = ((DragonMotionEntry *)lbl_805D4BA4->motions)[17].motion;
    lbl_805D4BD8 = lbl_805D4BA4->models[2].m_c;
    for (i = 0; i < 12; i++) {
        copy_model_node((u8 *)dst, (u8 *)src);
        dst->child = dst + 1;
        dst++;
        src = src->child;
    }
    copy_model_node((u8 *)dst, (u8 *)src);
    dst->sibling = dst + 1;
    copy_model_node((u8 *)&dst[1], (u8 *)src->sibling);
    for (i = 0; i < 14; i++) {
        tentacle_model_nodes[i].flags &= ~3;
        TBoss2Tentacle__segment_points[i].x = (f64)tentacle_model_nodes[i].position.x;
        TBoss2Tentacle__segment_points[i].y = tentacle_model_nodes[i].position.y;
        TBoss2Tentacle__segment_points[i].z = tentacle_model_nodes[i].position.z;
        TBoss2Tentacle__segment_point_defaults[i] = tentacle_model_nodes[i].rotation.z;
    }
}
