#include "types.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/boss/darkfalz/TObjDFTenchuFuru.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TObjDFRecover.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/darkfalz/TObjDFJisin.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_803E1A58.h"

typedef struct Obj_8005063C {
    u8 pad0[0x2FC];
    Vec f2fc;
    u8 pad308[0x348 - 0x308];
    Vec dir;
    u8 pad354[0x364 - 0x354];
    f32 f364;
    s32 state;
    Vec f36c;
    f32 f378;
    f32 f37c;
} Obj_8005063C;

extern "C" {
f32 fabs_float(f32);
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A58;
extern const f32 lbl_805D8A5C;
void queue_destruction__7TObjectFv(void *);
void normalize_vector(void *);
extern const f32 lbl_805D8A34;
extern const f32 lbl_805D8A48;
extern const f32 lbl_805D8A4C;
extern const f32 lbl_805D8A50;
extern const f32 lbl_805D8A54;
void steer_homing_direction(Obj_8005063C *arg0);

#pragma fp_contract on
void steer_homing_direction(Obj_8005063C *arg0) {
    Vec d;
    f32 k;
    f32 inv;
    VecCopy((Vec *)&d, (const Vec *)&arg0->f36c);
    subtract_vector(&d, &arg0->f2fc);
    if (vector_length(&d) <= lbl_805D8A48 ||
        vector_length(&arg0->dir) <= lbl_805D8A48) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    normalize_vector(&d);
    normalize_vector(&arg0->dir);
    k = lbl_805D8A50 * arg0->f364 + lbl_805D8A4C;
    Vec prev = arg0->dir;
    inv = lbl_805D8A34 - k;
    arg0->dir.x = k * arg0->dir.x + inv * d.x;
    arg0->dir.y = k * arg0->dir.y + inv * d.y;
    arg0->dir.z = k * arg0->dir.z + inv * d.z;
    if (arg0->f37c <= arg0->f378 && xyz_distance(&arg0->dir, &prev) <= lbl_805D8A54) {
        arg0->state = 2;
    }
}

void TObjDFHorming::sub_8005076C() {
    f32 temp_f1;
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x370) - this->m_300;
    if (temp_f1 > lbl_805D8A30) {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x34C) + lbl_805D8A58);
    } else {
        *(f32 *)((s8 *)((u8 *)this) + 0x34C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x34C) - lbl_805D8A58);
    }
    if (fabs_float(temp_f1) < lbl_805D8A5C) {
        this->m_368 = 1;
    }
}

}

extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();




class TObjDFJisin : public TObject {
public:
    virtual void render();
    virtual ~TObjDFJisin();
    virtual void run_task();
};
class TObjDFBeamCursor : public TObject {
public:
    virtual void render();
    virtual ~TObjDFBeamCursor();
    virtual void run_task();
};
class TObjDFRecBall : public TObject {
public:
    u8 _pad1C[0x28];
 void* m_44;
public:
    virtual void render();
    virtual ~TObjDFRecBall();
    virtual void run_task();
};

struct VBase_18_0c879f { char pad[0x18]; };

struct VObj_18_0c879f : VBase_18_0c879f {
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
    virtual s32 m21(s32, void *, s32, s32, s32);
};

struct S_80050808 { s32 a; f32 b; };

struct Ang_80050808 { s32 x, y, z; };

extern "C" {
u16 find_nearest_visible_player(void *, int, f32);
s32 is_boss_active__13TObjDFHormingFv();
int TBoss4DarkFalz__sub_8004C1AC(void);
int queue_destruction__13TObjDFHormingFPv(void* p);
s32 query_teammate_state__9TObjEneDDFv();
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 minimap_render_dot(void *, int, int, int);
void vec3_add_to(void *, void *);
void run_task__13TObjDFHormingFv(u8 *arg0);
struct S_80050A68 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x358 - 0x1c];
    void *ptr[2];
};

typedef struct Hit_80050D74 {
    s32 type;
    f32 value;
} Hit_80050D74;

struct VBase_80050D74 { u8 pad[0x18]; };

struct VObj_80050D74 : VBase_80050D74 {
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
    virtual void m21(s32, Hit_80050D74 *, s32, s32, s32);
};

struct Player_80050D74 : VObj_80050D74 {
    u8 pad1c[0x38 - 0x1c];
    Vec pos;
    u8 pad44[0x890 - 0x44];
    u32 class_flags;
};

typedef struct Obj_80050EB4 {
    u8 pad0[0x1C];
    f32 cx;
    f32 f20;
    f32 cz;
    f32 radius;
} Obj_80050EB4;

struct RecoveredGlobal_8005101C___vt__11TObjDFJisin {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_8005101C___vt__11TObjDFJisin_size[sizeof(RecoveredGlobal_8005101C___vt__11TObjDFJisin) == 0x18 ? 1 : -1];

struct Ball_8005123C {
    u8 pad0[0x1C];
    Vec pos;
    Vec target;
    Vec vel;
    f32 speed;
    void *model;
    s32 timer;
};

struct Obj_80050AF8 { u8 pad[0x358]; u32 objs[2]; };

s32 __ct__9TObjCharaFP7TObject(void *, s32);
Player_80050D74 * get_player_data__10TObjPlayerFi(s32);
s16 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
s32 is_state_ready__14TBoss4DarkFalzFv();
s32 TBoss4DarkFalz__sub_8004C1B4();
S_80050A68 * __dt__13TObjDFHormingFv(S_80050A68 *o, s16 flag);
u8 * TObjDFHorming__ct(u8 *arg0, s32 arg1, s32 arg2, u16 arg3);
void damage_players_near_point(s32 arg0, Vec *arg1);
void fn_spawn_particle_f3_with_flags(s32 arg0, s32 arg1);
u8 * TObjDFJisin__ct(u8 *arg0, u8 *arg1, s32 arg2);
void * TObjDFBeamCursor__ct(void *arg0, void *arg1, void *arg2);
void * create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1);
u8 * TObjDFRecBall__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
void * create__13TObjDFRecBallFPvPvPv(void *arg0, void *arg1, void *arg2);
s32 TBoss4Type3__sub_8005254C(s16);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *, void *);

extern void *__vt__11TObjDFJisin[];
extern void *__vt__13TObjDFHorming[];
extern void *__vt__13TObjDFRecBall[];
extern void *__vt__16TObjDFBeamCursor[];
extern s32 TObjDFJisin__particle_emitter_id_table[];
extern s32 TObjDFRecBall__name;
extern void *TObjDFBeamCursor__name;
extern s32 TObjDFJisin__name;
extern s32 TObjDFHorming__name;
extern s32 game_difficulty_selection;

int queue_destruction__13TObjDFHormingFPv(void* p) { return ((int (*)(void*))queue_destruction__7TObjectFv)(p); }

void run_task__13TObjDFHormingFv(u8 *arg0) {
    Ang_80050808 rot;
    Vec d;
    S_80050808 s;
    u8 *p;
    s32 i;
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    if (((TObjDFHorming *)arg0)->m_334 == 0xFFFF || (p = (u8 *)get_player_by_client_id(((TObjDFHorming *)arg0)->m_334)) == NULL) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    VecCopy((Vec *)(arg0 + 0x36C), (const Vec *)(p + 0x2FC));
    *(f32 *)((s8 *)arg0 + 0x37C) = xyz_distance((Vec *)(arg0 + 0x2FC), (Vec *)(arg0 + 0x36C));
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x2FC));
    switch (*(s32 *)&((TObjDFHorming *)arg0)->m_368) {
    case 0:
        ((TObjDFHorming *)arg0)->sub_8005076C();
        break;
    case 1:
        steer_homing_direction((Obj_8005063C *)arg0);
        break;
    case 2:
        ((TObjDFHorming *)arg0)->check_attack_trigger();
        break;
    }
    normalize_vector(arg0 + 0x348);
    *(f32 *)((s8 *)arg0 + 0x348) *= *(f32 *)((s8 *)arg0 + 0x354);
    *(f32 *)((s8 *)arg0 + 0x34C) *= *(f32 *)((s8 *)arg0 + 0x354);
    ((TObjDFHorming *)arg0)->m_350 *= *(f32 *)((s8 *)arg0 + 0x354);
    vec3_add_to(arg0 + 0x2FC, arg0 + 0x348);
    {
        s32 id = find_nearest_visible_player(arg0, 0, 7.5f);
        if (id != 0xFFFF && (p = (u8 *)get_player_by_client_id(id)) != NULL) {
            if (is_boss_active__13TObjDFHormingFv() != 0) {
                s.a = 0;
                s.b = *(s32 *)&((TObjDFHorming *)arg0)->m_360;
                {
                    S_80050808 t = s;
                    ((VObj_18_0c879f *)p)->m21(TBoss4DarkFalz__sub_8004C1AC(), &t, 0, -1, -1);
                }
            }
            queue_destruction__13TObjDFHormingFPv(arg0);
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        if (*(u32 *)((s8 *)(arg0 + i * 4) + 0x358) != 0) {
            if (i == 1) {
                VecCopy((Vec *)&d, (const Vec *)(arg0 + 0x2FC));
                subtract_vector(&d, (Vec *)(arg0 + 0x44));
                direction_to_rotation_xz((u8 *)&d, &rot.x, &rot.z);
                rot.y = 0;
                ((TParticleCtrl *)((void *)*(u32 *)((s8 *)(arg0 + i * 4) + 0x358)))->set_direction(&rot);
            }
            ((TParticleCtrl *)(void *)*(u32 *)((s8 *)(arg0 + i * 4) + 0x358))->set_position(arg0 + 0x2FC);
        }
    }
    minimap_render_dot(arg0 + 0x2FC, -0x5DB4, 1, 0);
    if (--*(s32 *)&((TObjDFHorming *)arg0)->m_338 < 0) {
        queue_destruction__7TObjectFv(arg0);
    }
}

S_80050A68 *__dt__13TObjDFHormingFv(S_80050A68 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__13TObjDFHorming;
        for (i = 0; i < 2; i++) {
            if (o->ptr[i] != 0) {
                TParticleCtrl::release(o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        __dt__9TObjCharaFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

#pragma push
#pragma fp_contract on
u8 *TObjDFHorming__ct(u8 *arg0, s32 parent, s32 arg2, u16 arg3) {
    f32 scale;
    s32 ang;
    u8 *p;
    s32 i;

    __ct__9TObjCharaFP7TObject(arg0, parent);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *)__vt__13TObjDFHorming;
    *(s32 *)((s8 *)arg0 + 0) = TObjDFHorming__name;
    ((TObjDFHorming *)arg0)->m_334 = arg3;
    *(s32 *)&((TObjDFHorming *)arg0)->m_338 = 0x96;
    if (game_difficulty_selection == 3) {
        *(s32 *)&((TObjDFHorming *)arg0)->m_338 = 0x12C;
    }
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(VecCopy((Vec *)(arg0 + 0x33C), (const Vec *)((const Vec *)arg2))))));
    scale = newton_sqrtf(1.08f);
    ang = (s32)(16384.0f * (0.000030517578f * (f32)rand() - 0.5f));
    p = (u8 *)get_player_by_client_id(((TObjDFHorming *)arg0)->m_334);
    if (p != NULL) {
        ang = 0;
    } else {
        ang += (s32)(10430.38043493439 * atan2_float(*(f32 *)((s8 *)p + 0x38) - 10000.0f, *(f32 *)((s8 *)p + 0x40)));
    }
    *(f32 *)((s8 *)arg0 + 0x348) = 1.2f * sin_table_lookup(ang) / scale;
    ((TObjDFHorming *)arg0)->m_350 = 1.2f * cos_table_lookup(ang) / scale;
    *(f32 *)((s8 *)arg0 + 0x34C) = -6.0f / scale;
    *(f32 *)((s8 *)arg0 + 0x354) = 6.0f;
    *(s32 *)&((TObjDFHorming *)arg0)->m_360 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0x28);
    *(f32 *)((s8 *)arg0 + 0x364) = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0);
    if (*(f32 *)((s8 *)arg0 + 0x364) < lbl_805D8A30 || *(f32 *)((s8 *)arg0 + 0x364) > lbl_805D8A34) {
        *(f32 *)((s8 *)arg0 + 0x364) = 0.5f;
    }
    *(f32 *)((s8 *)arg0 + 0x378) = -50.0f * *(f32 *)((s8 *)arg0 + 0x364) + 60.0f;
    for (i = 0; i < 2; i++) {
        if ((((Obj_80050AF8 *)arg0)->objs[i] = (u32)create_particle_emitter(arg0 + 0x2FC, TObjDFJisin__particle_emitter_id_table[i])) != 0) {
            ((TParticleCtrl *)(((Obj_80050AF8 *)arg0)->objs[i]))->set_flags(0x40);
        }
    }
    *(s32 *)&((TObjDFHorming *)arg0)->m_368 = 0;
    return arg0;
}
#pragma pop

void *TBoss4Type3::create_horming(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x380);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *, void *))TObjDFHorming__ct)(o, arg0, arg1, arg2);
    }
    return o;
}

void damage_players_near_point(s32 arg0, Vec *arg1) {
    Vec pos = *arg1;
    Hit_80050D74 hit;
    s32 i;
    Player_80050D74 *p;
    if (is_state_ready__14TBoss4DarkFalzFv() == 0) {
        return;
    }
    hit.type = 0x11;
    hit.value = lbl_805D8A30;
    for (i = 0; i < TLobby::get_game_mode(); i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (p != NULL && TBoss4Type3__sub_8005254C(get_entity_id(p)) != 0 &&
            !(p->class_flags & CLASS_FLAG_ANDROID) &&
            !(xyz_distance(&pos, &p->pos) > 20.0f)) {
            Hit_80050D74 h = hit;
            p->m21(TBoss4DarkFalz__sub_8004C1B4(), &h, 0, -1, -1);
        }
    }
}

void fn_spawn_particle_f3_with_flags(s32 arg0, s32 arg1) {
    Vec position;
    u32 particle_effect;
    VecCopy((Vec *)(&position.x), (const Vec *)(arg1));
    position.y += 2.0f;
    particle_effect = (u32)spawn_particle_effect((&position.x), 0xF3);
    if (particle_effect != 0U) {
        ((TParticleCtrl *)particle_effect)->set_flags(0x40);
    }
}
}
#pragma push
#pragma fp_contract on
void TObjDFJisin::run_task() {
    Vec v;
    s32 ang;
    s32 step;
    s32 count;
    f32 max;

    step = (s32)(1638400.0f / (6.28f * ((Obj_80050EB4 *)this)->radius));
    count = 0;
    v.y = lbl_805D8A30;
    max = 255.0f;
    for (ang = 0; ang < 0x10000; ang += step) {
        v.x = ((Obj_80050EB4 *)this)->radius * sin_table_lookup(ang) + ((Obj_80050EB4 *)this)->cx;
        v.z = ((Obj_80050EB4 *)this)->radius * cos_table_lookup(ang) + ((Obj_80050EB4 *)this)->cz;
        if (!(vector_length(&v) > max)) {
            ((void (*)(void *, Vec *))fn_spawn_particle_f3_with_flags)(this, &v);
            ((void (*)(void *, Vec *))damage_players_near_point)(this, &v);
            count++;
        }
    }
    if (((Obj_80050EB4 *)this)->radius > 300.0f && count == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    ((Obj_80050EB4 *)this)->radius += 25.0f;
}
#pragma pop

TObjDFJisin::~TObjDFJisin() {}

extern "C" {
u8 *TObjDFJisin__ct(u8 *object, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__11TObjDFJisin;
    *(s32 *)((s8 *)object + 0) = (s32) TObjDFJisin__name;
    *(f32 *)((s8 *)object + 0x1C) = (f32) (300.0f * sin_table_lookup(arg2));
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805D8A30;
    *(f32 *)((s8 *)object + 0x24) = (f32) (-300.0f * cos_table_lookup(arg2));
    *(f32 *)((s8 *)object + 0x28) = (f32) 25.0f;
    return object;
}

void *TBoss4Type2::create_jisin(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TObjDFJisin__ct)(o, arg0, arg1);
    }
    return o;
}

void run_task__16TObjDFBeamCursorFv(u8 *arg0) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x1C) - 1;
    *(s32 *)((s8 *)arg0 + 0x1C) = temp_r0;
    if (temp_r0 <= 0) {
        spawn_particle_effect((arg0 + 0x20), 0x38);
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
    }
}
TObjDFBeamCursor::~TObjDFBeamCursor() {}

void *TObjDFBeamCursor__ct(void *arg0, void *arg1, void *arg2) {
    ((void (*)(void *))__ct__7TObjectFP7TObject)(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__16TObjDFBeamCursor;
    *(void **)((s8 *)arg0 + 0x0) = TObjDFBeamCursor__name;
    *(u32 *)((s8 *)arg0 + 0x1C) = 32;
    VecCopy((Vec *)((char *)arg0 + 32), (const Vec *)arg2);
    return arg0;
}

void * create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = TObjDFBeamCursor__ct(o, arg0, arg1);
    }
    return o;
}

#pragma push
#pragma fp_contract on
void TObjDFRecBall::run_task() {
    Ball_8005123C *o = (Ball_8005123C *)this;
    Vec d;

    if (--o->timer < 0 || o->model == 0) {
        queue_destruction__7TObjectFv(o);
        return;
    }
    if ((o->speed += 0.26666668f) > 9.0f) {
        o->speed = 9.0f;
    }
    VecCopy((Vec *)&d, (const Vec *)&o->target);
    subtract_vector(&d, &o->pos);
    if (vector_length(&d) > lbl_805D8A48) {
        normalize_vector(&d);
    } else {
        d.x = lbl_805D8A34;
        d.z = d.y = lbl_805D8A30;
    }
    if (vector_length(&o->vel) > lbl_805D8A48) {
        normalize_vector(&o->vel);
    } else {
        o->vel.x = lbl_805D8A34;
        o->vel.y = lbl_805D8A30;
        o->vel.z = lbl_805D8A30;
    }
    o->vel.x = o->speed * (0.9f * o->vel.x + 0.100000024f * d.x);
    o->vel.y = o->speed * (0.9f * o->vel.y + 0.100000024f * d.y);
    o->vel.z = o->speed * (0.9f * o->vel.z + 0.100000024f * d.z);
    vec3_add_to(&o->pos, &o->vel);
    ((TParticleCtrl *)o->model)->set_position(&o->pos);
    if (xyz_distance(&o->pos, &o->target) <= o->speed) {
        queue_destruction__7TObjectFv(o);
    }
}
#pragma pop

}
TObjDFRecBall::~TObjDFRecBall() {
    if (m_44 != nullptr) TParticleCtrl::release(m_44);
}

extern "C" {
u8 *TObjDFRecBall__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3) {
    s32 temp_r31;
    u8 *particle_emitter;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__13TObjDFRecBall;
    *(s32 *)((s8 *)object + 0) = (s32) TObjDFRecBall__name;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg3);
    temp_r31 = (s32) (65536.0f * (0.000030517578f * (f32) rand()));
    *(f32 *)((s8 *)object + 0x34) = sin_table_lookup(temp_r31);
    *(f32 *)((s8 *)object + 0x38) = (f32) lbl_805D8A30;
    *(f32 *)((s8 *)object + 0x3C) = cos_table_lookup(temp_r31);
    *(f32 *)((s8 *)object + 0x40) = (f32) lbl_805D8A34;
    *(s32 *)((s8 *)object + 0x48) = 0x96;
    particle_emitter = (u8 *)(create_particle_emitter((object + 0x1C), 0xAF));
    *(u8 **)((s8 *)object + 0x44) = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)(*(u8 **)((s8 *)object + 0x44)))->set_flags(0x40);
    }
    return object;
}

void * create__13TObjDFRecBallFPvPvPv(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x4C);
    if (o != NULL) {
        o = TObjDFRecBall__ct((u8 *)o, (u8 *)arg0, (u8 *)arg1, (u8 *)arg2);
    }
    return o;
}

void vfunc_6__8TObjBaseFPsl();
void vfunc_29__9TObjCharaFv();
void vfunc_74__9TObjCharaFl();
void recalc_stats__9TObjCharaFv();
void vfunc_28__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_63__9TObjCharaFv();
void vfunc_62__9TObjCharaFv();
void vfunc_61__9TObjCharaFv();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void get_name__8TObjBaseFv();
void __dt__11TObjDFJisinFv();
void __dt__13TObjDFRecBallFv();
void __dt__16TObjDFBeamCursorFv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFf();
void vfunc_75__9TObjCharaFf();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void run_task__11TObjDFJisinFv();
void run_task__13TObjDFRecBallFv();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
void *__vt__13TObjDFHorming[] = {
    0,
    0,
    (void *)__dt__13TObjDFHormingFv,
    (void *)run_task__13TObjDFHormingFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__8TObjBaseFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf,
    (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (void *)receive_physical_attack__9TObjCharaFPvf,
    (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv,
    (void *)apply_knockback_from_attacker__9TObjCharaFPUcf,
    (void *)try_start_action__9TObjCharaFll,
    (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__9TObjCharaFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__9TObjCharaFv,
    (void *)vfunc_62__9TObjCharaFv,
    (void *)vfunc_63__9TObjCharaFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjCharaFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFf,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
};
void *__vt__11TObjDFJisin[] = {
    0,
    0,
    (void *)__dt__11TObjDFJisinFv,
    (void *)run_task__11TObjDFJisinFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__vt__16TObjDFBeamCursor[] = {
    0,
    0,
    (void *)__dt__16TObjDFBeamCursorFv,
    (void *)run_task__16TObjDFBeamCursorFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
void *__vt__13TObjDFRecBall[] = {
    0,
    0,
    (void *)__dt__13TObjDFRecBallFv,
    (void *)run_task__13TObjDFRecBallFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};

void *__dt__13TObjDFRecoverFv(void *arg0, s16 arg1);
void run_task__13TObjDFRecoverFv();
void __dt__7TObjectFv(void *, s16);
void *__vt__13TObjDFRecover[] = {
    0,
    0,
    (void *)__dt__13TObjDFRecoverFv,
    (void *)run_task__13TObjDFRecoverFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
};
}

#pragma push
#pragma fp_contract on
void TObjDFRecover::run_task() {
    f32 position[3];
    s32 current_phase;
    s32 target_address;
    u32 effect_address;
    u16 id;
    if (is_state_ready__14TBoss4DarkFalzFv() == 0) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(this);
        return;
    }
    id = target_id;
    if ((id == 0xFFFF) || ((target_address = (s32)get_player_by_client_id(id)) == 0)) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(this);
        return;
    }
    VecCopy((Vec *)position, (const Vec *)(target_address + 0x2FC));
    countdown = countdown - 1;
    current_phase = phase;
    switch (current_phase) {
    case 0:
        if (countdown <= 0) {
            effect_address = (u32)create_particle_emitter(position, 0xEB);
            effect = (void*)effect_address;
            if (effect_address == 0U) {
                ((s32 (*)(void *))queue_destruction__7TObjectFv)(this);
                return;
            }
            ((TParticleCtrl *)effect)->set_flags(0x40);
            countdown = 0xA;
            phase = 1;
        }
        break;
    case 1:
        ((TParticleCtrl *)effect)->set_position(position);
        if (countdown <= 0) {
            TParticleCtrl::release(effect);
            effect = NULL;
            start_pad_rumble_client(0xC0, 0xF, (int) ((s16) target_id));
            countdown = 0xB;
            phase = 2;
            return;
        }
        break;
    case 2:
        if ((countdown % 5) == 0) {
            play_sound_effect(0x4003AD19, 0, 0, 0);
            ((s32 (*)(int, void *, void *))create__13TObjDFRecBallFPvPvPv)((int)m_up, position, cached_position);
        }
        if (countdown <= 0) {
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(this);
        }
        break;
    }
}
#pragma pop

void *__dt__13TObjDFRecoverFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = __vt__13TObjDFRecover;
        if (((TObjDFRecover *)arg0)->effect != 0) TParticleCtrl::release(((TObjDFRecover *)arg0)->effect);
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern const char *TObjDFRecover__name;
TObjDFRecover::TObjDFRecover(TObject *parent, u16 id, const f32 *position) : TObject(parent) {
    m_name = TObjDFRecover__name;
    target_id = id;
    effect = NULL;
    VecCopy((Vec *)cached_position, (const Vec *)position);
    phase = 0;
    countdown = 5;
}

TObjDFRecover *TObjDFRecover::create(TObject *parent, u16 id, const f32 *position) {
    return new TObjDFRecover(parent, id, position);
}

struct RecoveredGlobal_80051938___vt__16TObjDFTenchuFuru {
    s32 value;
    u8 remaining[0x14];
};


struct RecoveredGlobal_80051AD0_lbl_804858B4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80051AD0_lbl_804FF228 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80051AD0_lbl_804FF234 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredFields_80051AD0_var_r31 {
    s32 field_0;
    u8 unknown_4[0x28];
    u8 * field_2C;
    u8 * field_30;
};

extern RecoveredGlobal_80051938___vt__16TObjDFTenchuFuru __vt__16TObjDFTenchuFuru;
extern s32 TObjDFTenchuFuru__name;
extern "C" {
u8 *TObjDFTenchuFuru__ct(u8 *arg0, u8 *arg1, u8 *arg2);
}
void get_current_matrix(void *m);
extern Mtx34 df_captured_matrix_pair[2];
extern int TObjDFTenchuFuru__matrix_node_index;
extern "C" {
s32 matrix_mult_vec(int, void *, void *);
extern RecoveredGlobal_80051AD0_lbl_804858B4 dark_falz_jisin_zero_vec;
RecoveredGlobal_80051AD0_lbl_804FF228 lbl_804FF228;
RecoveredGlobal_80051AD0_lbl_804FF234 lbl_804FF234;
Mtx34 df_captured_matrix_pair[2];
s32 is_active__14TBoss4DarkFalzFv();
void TObjDFTenchuFuru__sub_80051A7C(void);

#pragma push
#pragma fp_contract on
void TObjDFTenchuFuru::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    this->m_20 += -60.0f;
    if ((u32) this->m_2c != 0U) {
        ((TParticleCtrl *)this->m_2c)->set_position((u8 *)&this->unk_1C);
    }
    temp_r0 = this->m_28 - 1;
    this->m_28 = temp_r0;
    if ((temp_r0 < 0) || ((is_active__14TBoss4DarkFalzFv() == 0) && (is_state_ready__14TBoss4DarkFalzFv() == 0))) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
    }
}
#pragma pop

typedef char RecoveredGlobal_80051938___vt__16TObjDFTenchuFuru_size[sizeof(RecoveredGlobal_80051938___vt__16TObjDFTenchuFuru) == 0x18 ? 1 : -1];
TObjDFTenchuFuru::~TObjDFTenchuFuru() {
    if (m_2c != nullptr) TParticleCtrl::release(m_2c);
}
u8 *TObjDFTenchuFuru__ct(u8 *object, u8 *arg1, u8 *arg2) {
    u8 *particle_emitter;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__16TObjDFTenchuFuru.value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjDFTenchuFuru__name;
    ((TObjDFTenchuFuru *)object)->m_28 = 5;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    ((TObjDFTenchuFuru *)object)->m_20 += 300.0f;
    particle_emitter = (u8 *)(create_particle_emitter((object + 0x1C), 0x134));
    ((TObjDFTenchuFuru *)object)->m_2c = particle_emitter;
    if (particle_emitter != NULL) {
        ((TParticleCtrl *)(((TObjDFTenchuFuru *)object)->m_2c))->set_flags(0x40);
    }
    return object;
}

void *TObjDFTenchuFuru::create(void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TObjDFTenchuFuru__ct((u8 *)o, (u8 *)this, (u8 *)arg1);
    }
    return o;
}

void TObjDFTenchuFuru::capture_matrix_by_frame() {
    switch ((s32) (*(s32 *)&TObjDFTenchuFuru__matrix_node_index)) {
    case 0x3B:
        get_current_matrix(df_captured_matrix_pair[0]);
        break;
    case 0x3A:
        get_current_matrix(df_captured_matrix_pair[1]);
        break;
    }
    (*(s32 *)&TObjDFTenchuFuru__matrix_node_index) += 1;
}

void TObjDFTenchuFuru__sub_80051A7C(void) { set_chunk_model_node_callback(0); }

void TObjDFTenchuFuru::register_callback() { TObjDFTenchuFuru__matrix_node_index = 0; set_chunk_model_node_callback((s32)TObjDFTenchuFuru::capture_matrix_by_frame); }
typedef char RecoveredGlobal_80051AD0_lbl_804858B4_size[sizeof(RecoveredGlobal_80051AD0_lbl_804858B4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80051AD0_lbl_804FF228_size[sizeof(RecoveredGlobal_80051AD0_lbl_804FF228) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80051AD0_lbl_804FF234_size[sizeof(RecoveredGlobal_80051AD0_lbl_804FF234) == 0xC ? 1 : -1];
typedef char RecoveredFields_80051AD0_var_r31_0_offset[offsetof(RecoveredFields_80051AD0_var_r31, field_0) == 0x0 ? 1 : -1];
typedef char RecoveredFields_80051AD0_var_r31_2C_offset[offsetof(RecoveredFields_80051AD0_var_r31, field_2C) == 0x2C ? 1 : -1];
typedef char RecoveredFields_80051AD0_var_r31_30_offset[offsetof(RecoveredFields_80051AD0_var_r31, field_30) == 0x30 ? 1 : -1];
void TObjDFTenchuFuru::transform_node_tree() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r31;
    var_r31 = arg0;
    do {
        push_matrix();
        post_translate_matrix((f32 *)(var_r31 + 8));
        rotate_matrix_by_node_angles((s32 *)(var_r31 + 0x14), (u32) (((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_0 & 0x20));
        scale_current_matrix((f32 *)(var_r31 + 0x20));
        switch ((s32) (*(s32 *)&TObjDFTenchuFuru__matrix_node_index)) {
        case 0x3B:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec.value, &lbl_804FF228.value);
            break;
        case 0x3A:
            matrix_mult_vec(0, &dark_falz_jisin_zero_vec.value, &lbl_804FF234.value);
            break;
        }
        (*(s32 *)&TObjDFTenchuFuru__matrix_node_index) += 1;
        temp_r3 = (u8 *)(((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_2C);
        if (temp_r3 != NULL) {
            ((TObjDFTenchuFuru *)temp_r3)->transform_node_tree();
        }
        pop_matrix();
        var_r31 = (u8 *)(((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_30);
    } while (var_r31 != NULL);
}
}

extern char TObjDFRecover__class_name_string[];
extern char TObjDFRecBall__class_name_string[];
extern char TObjDFBeamCursor__class_name_string[];
extern char TObjDFJisin__class_name_string[];
extern char TObjDFHorming__class_name_string[];
extern char TObjDFYutai__class_name_string[];
const char *TObjDFRecover__name = TObjDFRecover__class_name_string;
s32 TObjDFRecBall__name = (s32)TObjDFRecBall__class_name_string;
void *TObjDFBeamCursor__name = TObjDFBeamCursor__class_name_string;
s32 TObjDFJisin__name = (s32)TObjDFJisin__class_name_string;
s32 TObjDFHorming__name = (s32)TObjDFHorming__class_name_string;
const char *TObjDFYutai__name = TObjDFYutai__class_name_string;

extern "C" {
s32 TCharaMaking__draw_colored_hair(int, void *, int, f32);

void TObjDFTenchuFuru::draw_node_tree() { TObjDFTenchuFuru__matrix_node_index = 0; push_matrix(); set_matrix_identity((u8 *)((void*)0)); transform_node_tree(); pop_matrix(); }
void TObjPlayer::draw_player_model_by_client(u16 arg0, s32 arg1, f32 farg0, f32 farg1) {
    u8 *p;
    u32 a;
    u32 b;
    u8 *c;
    u32 d;
    u8 *e;
    s32 f;
    u8 *g;
    if (lbl_805D8A30 == farg1) {
        return;
    }
    if (arg0 == 0xFFFF) {
        return;
    }
    p = (u8 *)get_player_by_client_id(arg0);
    if (p == NULL || *(s32 *)((s8 *)p + 0xCFC) != 0) {
        return;
    }
    c = p + 0xA1C;
    a = *(u32 *)((s8 *)p + 0x8B0);
    e = p + 0xB88;
    b = *(u32 *)((s8 *)p + 0x8AC);
    d = *(u32 *)((s8 *)p + 0x8B4);
    g = p + 0xCF4;
    f = *(s32 *)((s8 *)p + 0x34);
    if (farg1 < lbl_805D8A34) {
        TObjPlayer__sub_80052390(farg1);
    }
    TObjFish::set_global_param((s32)g);
    TObjDFTenchuFuru::register_callback();
    draw_model_motion((void *)f, (void *)arg1, farg0);
    TObjDFTenchuFuru__sub_80051A7C();
    if (d != 0) {
        push_matrix_from(df_captured_matrix_pair[1]);
        TObjFish::set_global_param((s32)e);
        draw_chunk_object((void *)d);
        pop_matrix();
    }
    if (a != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param((s32)c);
        draw_chunk_object((void *)a);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
    if (farg1 < lbl_805D8A34) {
        TObjPlayer::sync_player_globals();
    }
    if (b != 0) {
        TCharaMaking::enable_making();
        push_matrix_from(df_captured_matrix_pair[0]);
        TObjFish::set_global_param((s32)c);
        TCharaMaking__draw_colored_hair(b, p + 0x85C, 0, farg1);
        pop_matrix();
        TCharaMaking::clear_flag_bit0();
    }
}

}
