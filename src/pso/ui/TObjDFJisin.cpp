#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/object/TObjDFHorming.h"
#include "pso/TObjDFTenchuFuru.h"
#include "pso/TObject.h"
#include "pso/boss/TObjDFRecover.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"


#include "dolphin/mtx.h"
#include <stddef.h>


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
void queue_destruction__7TObjectFv(void *);
s32 is_boss_active__13TObjDFHormingFv();
int TBoss4DarkFalz__sub_8004C1AC(void);
s32 steer_homing_direction(void *);
int queue_destruction__13TObjDFHormingFPv(void* p);
s32 query_teammate_state__9TObjEneDDFv();
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
void *get_player_by_client_id(s32 i);
s32 minimap_render_dot(void *, int, int, int);
void vec3_add_to(void *, void *);
void subtract_vector(void *, void *);
void normalize_vector(void *);
extern const f32 lbl_805D8A60;
void run_task__13TObjDFHormingFv(u8 *arg0);
struct S_80050A68 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x358 - 0x1c];
    void *ptr[2];
};

typedef struct Vec_80050D74 {
    f32 x, y, z;
} Vec_80050D74;

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
    Vec_80050D74 pos;
    u8 pad44[0x890 - 0x44];
    u32 class_flags;
};

typedef struct Vec_80050EB4 {
    f32 x, y, z;
} Vec_80050EB4;

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

struct Vec_8005123C { f32 x, y, z; };

struct Ball_8005123C {
    u8 pad0[0x1C];
    Vec_8005123C pos;
    Vec_8005123C target;
    Vec_8005123C vel;
    f32 speed;
    void *model;
    s32 timer;
};

struct Obj_80050AF8 { u8 pad[0x358]; u32 objs[2]; };

s32 __ct__13TUnk_804806E8FP7TObject(void *, s32);
Player_80050D74 * get_player_data__10TObjPlayerFi(s32);
s16 obj_getField1c(void *);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
s32 is_state_ready__14TBoss4DarkFalzFv();
s32 TBoss4DarkFalz__sub_8004C1B4();
S_80050A68 * __dt__13TObjDFHormingFv(S_80050A68 *o, s16 flag);
u8 * TObjDFHorming__ct(u8 *arg0, s32 arg1, s32 arg2, u16 arg3);
void damage_players_near_point(s32 arg0, Vec_80050D74 *arg1);
void fn_spawn_particle_f3_with_flags(s32 arg0, s32 arg1);
u8 * TObjDFJisin__ct(u8 *arg0, u8 *arg1, s32 arg2);
void * TObjDFBeamCursor__ct(void *arg0, void *arg1, void *arg2);
void * create__16TObjDFBeamCursorFPvPv(void *arg0, void *arg1);
u8 * TObjDFRecBall__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
void * create__13TObjDFRecBallFPvPvPv(void *arg0, void *arg1, void *arg2);
s32 TBoss4Type3__sub_8005254C(s16);
void *spawn_particle_effect(void *pos, s32 id);
void *create_particle_emitter(void *pos, s32 id);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __ct__7TObjectFP7TObject(void *, void *);
s32 rand(void);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
f32 vector_length(Vec_80050EB4 *);
f32 xyz_distance(Vec_80050D74 *, Vec_80050D74 *);

extern void *__vt__11TObjDFJisin[];
extern void *__vt__13TObjDFHorming[];
extern void *__vt__13TObjDFRecBall[];
extern void *__vt__16TObjDFBeamCursor[];
extern const f64 lbl_804374F0;
extern s32 TObjDFJisin__particle_emitter_id_table[];
extern s32 TObjDFRecBall__name;
extern void *TObjDFBeamCursor__name;
extern s32 TObjDFJisin__name;
extern s32 TObjDFHorming__name;
extern s32 game_difficulty_selection;
extern const f32 lbl_805D8A30;
extern const f32 lbl_805D8A34;
extern const f32 lbl_805D8A48;
extern const f32 lbl_805D8A64;
extern const f32 lbl_805D8A68;
extern const f32 lbl_805D8A6C;
extern const f32 lbl_805D8A70;
extern const f32 lbl_805D8A74;
extern const f32 lbl_805D8A78;
extern const f32 lbl_805D8A7C;
extern const f32 lbl_805D8A80;
extern const f32 lbl_805D8A84;
extern const f32 lbl_805D8A88;
extern const f32 lbl_805D8A8C;
extern const f32 lbl_805D8A90;
extern const f32 lbl_805D8A94;
extern const f32 lbl_805D8A98;
extern const f32 lbl_805D8A9C;
extern const f32 lbl_805D8AA0;
extern const f32 lbl_805D8AA4;
extern const f32 lbl_805D8AA8;
extern const f32 lbl_805D8AAC;
extern const f32 lbl_805D8AB4;
extern const f32 lbl_805D8AB8;
extern const f32 lbl_805D8ABC;

int queue_destruction__13TObjDFHormingFPv(void* p) { return ((int (*)(void*))queue_destruction__7TObjectFv)(p); }

void run_task__13TObjDFHormingFv(u8 *arg0) {
    Ang_80050808 rot;
    Vec_80050D74 d;
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
    *(f32 *)((s8 *)arg0 + 0x37C) = xyz_distance((Vec_80050D74 *)(arg0 + 0x2FC), (Vec_80050D74 *)(arg0 + 0x36C));
    VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x2FC));
    switch (*(s32 *)&((TObjDFHorming *)arg0)->m_368) {
    case 0:
        ((TObjDFHorming *)arg0)->sub_8005076C();
        break;
    case 1:
        steer_homing_direction(arg0);
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
        s32 id = find_nearest_visible_player(arg0, 0, lbl_805D8A60);
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
                subtract_vector(&d, arg0 + 0x44);
                direction_to_rotation_xz((u8 *)&d, &rot.x, &rot.z);
                rot.y = 0;
                ((TBoss4Type2 *)((void *)*(u32 *)((s8 *)(arg0 + i * 4) + 0x358)))->copy_vec3(&rot);
            }
            ((TNowLoading *)((void *)*(u32 *)((s8 *)(arg0 + i * 4) + 0x358)))->copy_pos(arg0 + 0x2FC);
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
                TBoss4Type2::request_destroy((u32)o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        ((TUnk_804806E8 *)o)->destroy_motion_object(0);
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

    __ct__13TUnk_804806E8FP7TObject(arg0, parent);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *)__vt__13TObjDFHorming;
    *(s32 *)((s8 *)arg0 + 0) = TObjDFHorming__name;
    ((TObjDFHorming *)arg0)->m_334 = arg3;
    *(s32 *)&((TObjDFHorming *)arg0)->m_338 = 0x96;
    if (game_difficulty_selection == 3) {
        *(s32 *)&((TObjDFHorming *)arg0)->m_338 = 0x12C;
    }
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(VecCopy((Vec *)(arg0 + 0x33C), (const Vec *)((const Vec *)arg2))))));
    scale = newton_sqrtf(lbl_805D8A64);
    ang = (s32)(lbl_805D8A68 * (lbl_805D8A6C * (f32)rand() - lbl_805D8A70));
    p = (u8 *)get_player_by_client_id(((TObjDFHorming *)arg0)->m_334);
    if (p != NULL) {
        ang = 0;
    } else {
        ang += (s32)(lbl_804374F0 * atan2_float(*(f32 *)((s8 *)p + 0x38) - lbl_805D8A74, *(f32 *)((s8 *)p + 0x40)));
    }
    *(f32 *)((s8 *)arg0 + 0x348) = lbl_805D8A78 * sin_table_lookup(ang) / scale;
    ((TObjDFHorming *)arg0)->m_350 = lbl_805D8A78 * cos_table_lookup(ang) / scale;
    *(f32 *)((s8 *)arg0 + 0x34C) = lbl_805D8A7C / scale;
    *(f32 *)((s8 *)arg0 + 0x354) = lbl_805D8A80;
    *(s32 *)&((TObjDFHorming *)arg0)->m_360 = *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0x28);
    *(f32 *)((s8 *)arg0 + 0x364) = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x38)) + 0);
    if (*(f32 *)((s8 *)arg0 + 0x364) < lbl_805D8A30 || *(f32 *)((s8 *)arg0 + 0x364) > lbl_805D8A34) {
        *(f32 *)((s8 *)arg0 + 0x364) = lbl_805D8A70;
    }
    *(f32 *)((s8 *)arg0 + 0x378) = lbl_805D8A88 * *(f32 *)((s8 *)arg0 + 0x364) + lbl_805D8A84;
    for (i = 0; i < 2; i++) {
        if ((((Obj_80050AF8 *)arg0)->objs[i] = (u32)create_particle_emitter(arg0 + 0x2FC, TObjDFJisin__particle_emitter_id_table[i])) != 0) {
            ((TBoss4Type2 *)(((Obj_80050AF8 *)arg0)->objs[i]))->set_flags(0x40);
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

void damage_players_near_point(s32 arg0, Vec_80050D74 *arg1) {
    Vec_80050D74 pos = *arg1;
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
        if (p != NULL && TBoss4Type3__sub_8005254C(obj_getField1c(p)) != 0 &&
            !(p->class_flags & CLASS_FLAG_ANDROID) &&
            !(xyz_distance(&pos, &p->pos) > lbl_805D8A8C)) {
            Hit_80050D74 h = hit;
            p->m21(TBoss4DarkFalz__sub_8004C1B4(), &h, 0, -1, -1);
        }
    }
}

void fn_spawn_particle_f3_with_flags(s32 arg0, s32 arg1) {
    Vec position;
    u32 particle_effect;
    VecCopy((Vec *)(&position.x), (const Vec *)(arg1));
    position.y += lbl_805D8A90;
    particle_effect = (u32)spawn_particle_effect((&position.x), 0xF3);
    if (particle_effect != 0U) {
        ((TBoss4Type2 *)particle_effect)->set_flags(0x40);
    }
}
}
#pragma push
#pragma fp_contract on
void TObjDFJisin::run_task() {
    Vec_80050EB4 v;
    s32 ang;
    s32 step;
    s32 count;
    f32 max;

    step = (s32)(lbl_805D8A94 / (lbl_805D8A98 * ((Obj_80050EB4 *)this)->radius));
    count = 0;
    v.y = lbl_805D8A30;
    max = lbl_805D8A9C;
    for (ang = 0; ang < 0x10000; ang += step) {
        v.x = ((Obj_80050EB4 *)this)->radius * sin_table_lookup(ang) + ((Obj_80050EB4 *)this)->cx;
        v.z = ((Obj_80050EB4 *)this)->radius * cos_table_lookup(ang) + ((Obj_80050EB4 *)this)->cz;
        if (!(vector_length(&v) > max)) {
            ((void (*)(void *, Vec_80050EB4 *))fn_spawn_particle_f3_with_flags)(this, &v);
            ((void (*)(void *, Vec_80050EB4 *))damage_players_near_point)(this, &v);
            count++;
        }
    }
    if (((Obj_80050EB4 *)this)->radius > lbl_805D8AA0 && count == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    ((Obj_80050EB4 *)this)->radius += lbl_805D8AA4;
}
#pragma pop

TObjDFJisin::~TObjDFJisin() {}

extern "C" {
u8 *TObjDFJisin__ct(u8 *object, u8 *arg1, s32 arg2) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = (s32 *)__vt__11TObjDFJisin;
    *(s32 *)((s8 *)object + 0) = (s32) TObjDFJisin__name;
    *(f32 *)((s8 *)object + 0x1C) = (f32) (lbl_805D8AA0 * sin_table_lookup(arg2));
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805D8A30;
    *(f32 *)((s8 *)object + 0x24) = (f32) (lbl_805D8AA8 * cos_table_lookup(arg2));
    *(f32 *)((s8 *)object + 0x28) = (f32) lbl_805D8AA4;
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
    Vec_8005123C d;

    if (--o->timer < 0 || o->model == 0) {
        queue_destruction__7TObjectFv(o);
        return;
    }
    f32 sp = o->speed + lbl_805D8AAC;
    o->speed = sp;
    if (sp > 9.0f) {
        o->speed = 9.0f;
    }
    VecCopy((Vec *)&d, (const Vec *)&o->target);
    subtract_vector(&d, &o->pos);
    if (((f32 (*)(void *))vector_length)(&d) > lbl_805D8A48) {
        normalize_vector(&d);
    } else {
        d.x = lbl_805D8A34;
        d.z = d.y = lbl_805D8A30;
    }
    if (((f32 (*)(void *))vector_length)(&o->vel) > lbl_805D8A48) {
        normalize_vector(&o->vel);
    } else {
        o->vel.x = lbl_805D8A34;
        o->vel.y = lbl_805D8A30;
        o->vel.z = lbl_805D8A30;
    }
    o->vel.x = o->speed * (lbl_805D8AB4 * o->vel.x + lbl_805D8AB8 * d.x);
    o->vel.y = o->speed * (lbl_805D8AB4 * o->vel.y + lbl_805D8AB8 * d.y);
    o->vel.z = o->speed * (lbl_805D8AB4 * o->vel.z + lbl_805D8AB8 * d.z);
    vec3_add_to(&o->pos, &o->vel);
    ((TNowLoading *)(o->model))->copy_pos(&o->pos);
    if (((f32 (*)(void *, void *))xyz_distance)(&o->pos, &o->target) <= o->speed) {
        queue_destruction__7TObjectFv(o);
    }
}
#pragma pop

}
TObjDFRecBall::~TObjDFRecBall() {
    if (m_44 != nullptr) TBoss4Type2::request_destroy((u32)m_44);
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
    temp_r31 = (s32) (lbl_805D8ABC * (lbl_805D8A6C * (f32) rand()));
    *(f32 *)((s8 *)object + 0x34) = sin_table_lookup(temp_r31);
    *(f32 *)((s8 *)object + 0x38) = (f32) lbl_805D8A30;
    *(f32 *)((s8 *)object + 0x3C) = cos_table_lookup(temp_r31);
    *(f32 *)((s8 *)object + 0x40) = (f32) lbl_805D8A34;
    *(s32 *)((s8 *)object + 0x48) = 0x96;
    particle_emitter = (u8 *)(create_particle_emitter((object + 0x1C), 0xAF));
    *(u8 **)((s8 *)object + 0x44) = particle_emitter;
    if (particle_emitter != NULL) {
        ((TBoss4Type2 *)(*(u8 **)((s8 *)object + 0x44)))->set_flags(0x40);
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

void vfunc_6__13TUnk_804B9870FPsl();
void vfunc_29__13TUnk_804806E8Fv();
void vfunc_74__13TUnk_804806E8Fl();
void vfunc_73__13TUnk_804806E8Fv();
void vfunc_28__13TUnk_804806E8Fv();
void consume_timer_field__13TUnk_804806E8Fl();
void vfunc_67__13TUnk_804806E8Ff();
void vfunc_66__13TUnk_804806E8Fv();
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
void vfunc_63__13TUnk_804806E8Fv();
void vfunc_62__13TUnk_804806E8Fv();
void vfunc_61__13TUnk_804806E8Fv();
void vfunc_60__13TUnk_804806E8Fv();
void vfunc_59__13TUnk_804806E8Fv();
void vfunc_58__13TUnk_804806E8Fv();
void apply_slow_status__13TUnk_804806E8Fv();
void update_shock_clock__13TUnk_804806E8Fv();
void vfunc_43__13TUnk_804806E8Fv();
void vfunc_18__13TUnk_804806E8FPUc();
void vfunc_13__13TUnk_804AF8A0Fl();
void get_name__13TUnk_804B9870Fv();
void __dt__11TObjDFJisinFv();
void __dt__13TObjDFRecBallFv();
void __dt__16TObjDFBeamCursorFv();
void add_actor_exp__13TUnk_804806E8Fl();
void apply_action_hold_status__13TUnk_804806E8Ff();
void apply_anti_technique__13TUnk_804806E8Fl();
void apply_attack_stat_status__13TUnk_804806E8FPv();
void apply_confusion_status__13TUnk_804806E8Fv();
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
void apply_movement_ailment__13TUnk_804806E8Fl();
void apply_object_set_data__13TUnk_804B9870FPv();
void apply_paralysis__13TUnk_804806E8Fv();
void apply_poison_status__13TUnk_804806E8Fv();
void apply_shock_status__13TUnk_804806E8Fv();
void apply_switch_attack__13TUnk_804806E8Fv();
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
void classify_actor_view_detail__13TUnk_804B9870Ffff();
void clear_all_status_effects__13TUnk_804806E8Fv();
void clear_harmful_statuses__13TUnk_804806E8Fv();
void cure_paralysis__13TUnk_804806E8Fv();
void cure_poison_ailment__13TUnk_804806E8Fv();
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
void vfunc_78__13TUnk_804806E8Fl();
void vfunc_77__13TUnk_804806E8Fv();
void vfunc_76__13TUnk_804806E8Fv();
void vfunc_75__13TUnk_804806E8Ff();
void vfunc_9__13TUnk_804806E8Fv();
void get_actor_level_index__13TUnk_804806E8Fv();
void get_pos__13TUnk_804806E8Fl();
void is_actor_cadence_frame__13TUnk_804806E8Fl();
void is_target_in_attack_range__13TUnk_804806E8Fv();
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
void receive_physical_attack__13TUnk_804806E8FPvf();
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();
void reset_motion_fields__13TUnk_804806E8Fv();
void reset_pose__13TUnk_804806E8Fv();
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
void run_task__11TObjDFJisinFv();
void run_task__13TObjDFRecBallFv();
void select_melee_contact_body__13TUnk_804806E8FPvf();
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
void try_start_action__13TUnk_804806E8Fll();
void update_action_hold_status__13TUnk_804806E8Fv();
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
void update_actor_ground_y__13TUnk_804806E8Fv();
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
void update_flag30_timer__13TUnk_804806E8Fv();
void update_movement_status__13TUnk_804806E8Fv();
void update_object_view_visibility__13TUnk_804B9870Fff();
void update_poison_status__13TUnk_804806E8Fv();
void *__vt__13TObjDFHorming[] = {
    0,
    0,
    (void *)__dt__13TObjDFHormingFv,
    (void *)run_task__13TObjDFHormingFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__13TUnk_804B9870FPsl,
    (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv,
    (void *)vfunc_9__13TUnk_804806E8Fv,
    (void *)update_object_view_visibility__13TUnk_804B9870Fff,
    (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__13TUnk_804B9870Fv,
    (void *)vfunc_13__13TUnk_804AF8A0Fl,
    (void *)add_actor_exp__13TUnk_804806E8Fl,
    (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv,
    (void *)update_actor_ground_y__13TUnk_804806E8Fv,
    (void *)vfunc_18__13TUnk_804806E8FPUc,
    (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)select_melee_contact_body__13TUnk_804806E8FPvf,
    (void *)calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf,
    (void *)receive_physical_attack__13TUnk_804806E8FPvf,
    (void *)receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__13TUnk_804806E8FPvPv,
    (void *)apply_knockback_from_attacker__13TUnk_804806E8FPUc,
    (void *)try_start_action__13TUnk_804806E8Fll,
    (void *)roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)vfunc_28__13TUnk_804806E8Fv,
    (void *)vfunc_29__13TUnk_804806E8Fv,
    (void *)is_target_in_attack_range__13TUnk_804806E8Fv,
    (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv,
    (void *)&has_flag_0x800__13TUnk_804806E8Fv,
    (void *)&test_flag_1000__13TUnk_804806E8Fv,
    (void *)update_poison_status__13TUnk_804806E8Fv,
    (void *)update_action_hold_status__13TUnk_804806E8Fv,
    (void *)vfunc_37__13TUnk_804806E8Fv,
    (void *)update_flag30_timer__13TUnk_804806E8Fv,
    (void *)update_movement_status__13TUnk_804806E8Fv,
    (void *)update_shock_clock__13TUnk_804806E8Fv,
    (void *)update_attack_stat_status__13TUnk_804806E8Fv,
    (void *)update_defense_stat_status__13TUnk_804806E8Fv,
    (void *)vfunc_43__13TUnk_804806E8Fv,
    (void *)apply_poison_status__13TUnk_804806E8Fv,
    (void *)apply_paralysis__13TUnk_804806E8Fv,
    (void *)apply_slow_status__13TUnk_804806E8Fv,
    (void *)apply_confusion_status__13TUnk_804806E8Fv,
    (void *)apply_movement_ailment__13TUnk_804806E8Fl,
    (void *)apply_shock_status__13TUnk_804806E8Fv,
    (void *)clear_harmful_statuses__13TUnk_804806E8Fv,
    (void *)apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)apply_defense_stat_status__13TUnk_804806E8FPv,
    (void *)cure_poison_ailment__13TUnk_804806E8Fv,
    (void *)cure_paralysis__13TUnk_804806E8Fv,
    (void *)clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)apply_action_hold_status__13TUnk_804806E8Ff,
    (void *)apply_anti_technique__13TUnk_804806E8Fl,
    (void *)vfunc_58__13TUnk_804806E8Fv,
    (void *)vfunc_59__13TUnk_804806E8Fv,
    (void *)vfunc_60__13TUnk_804806E8Fv,
    (void *)vfunc_61__13TUnk_804806E8Fv,
    (void *)vfunc_62__13TUnk_804806E8Fv,
    (void *)vfunc_63__13TUnk_804806E8Fv,
    (void *)reset_pose__13TUnk_804806E8Fv,
    (void *)get_anim_node_position__13TUnk_804806E8FlP3Vec,
    (void *)vfunc_66__13TUnk_804806E8Fv,
    (void *)vfunc_67__13TUnk_804806E8Ff,
    (void *)get_pos__13TUnk_804806E8Fl,
    (void *)apply_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_jellen_effect__13TUnk_804806E8Fv,
    (void *)trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_zalure_effect__13TUnk_804806E8Fv,
    (void *)vfunc_73__13TUnk_804806E8Fv,
    (void *)vfunc_74__13TUnk_804806E8Fl,
    (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv,
    (void *)vfunc_77__13TUnk_804806E8Fv,
    (void *)vfunc_78__13TUnk_804806E8Fl,
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
s32 play_sound_effect(int, int, int, int);
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
            ((TBoss4Type2 *)effect)->set_flags(0x40);
            countdown = 0xA;
            phase = 1;
        }
        break;
    case 1:
        ((TNowLoading *)effect)->copy_pos(position);
        if (countdown <= 0) {
            TBoss4Type2::request_destroy((u32)effect);
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
        if (((TObjDFRecover *)arg0)->effect != 0) TBoss4Type2::request_destroy((u32)(((TObjDFRecover *)arg0)->effect));
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

struct RecoveredGlobal_80051A18_lbl_804FF240 {
    s32 value;
    u8 remaining[0x5C];
};

#include <stddef.h>
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
extern RecoveredGlobal_80051A18_lbl_804FF240 df_captured_matrix_pair;
extern int TObjDFTenchuFuru__matrix_node_index;
extern "C" {
s32 matrix_mult_vec(int, void *, void *);
f32 rotate_matrix_by_node_angles(void *, int);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(void *);
f32 post_translate_matrix(void *);
extern RecoveredGlobal_80051AD0_lbl_804858B4 dark_falz_jisin_zero_vec;
extern RecoveredGlobal_80051AD0_lbl_804FF228 lbl_804FF228;
extern RecoveredGlobal_80051AD0_lbl_804FF234 lbl_804FF234;
s32 is_active__14TBoss4DarkFalzFv();
extern const f32 lbl_805D8AC0;
int TObjDFTenchuFuru__sub_80051A7C(void);
void *__nw__7TObjectFUl(int);
int set_global_state__16TObjEneRe7BeruraFl(void*);

#pragma push
#pragma fp_contract on
void TObjDFTenchuFuru::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    this->m_20 = (f32) (this->m_20 + lbl_805D8AC0);
    if ((u32) this->m_2c != 0U) {
        ((TNowLoading *)(this->m_2c))->copy_pos((u8 *)&this->unk_1C);
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
    if (m_2c != nullptr) TBoss4Type2::request_destroy((u32)m_2c);
}
u8 *TObjDFTenchuFuru__ct(u8 *object, u8 *arg1, u8 *arg2) {
    u8 *particle_emitter;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__16TObjDFTenchuFuru.value;
    *(s32 *)((s8 *)object + 0) = (s32) TObjDFTenchuFuru__name;
    ((TObjDFTenchuFuru *)object)->m_28 = 5;
    VecCopy((Vec *)(object + 0x1C), (const Vec *)arg2);
    ((TObjDFTenchuFuru *)object)->m_20 = (f32) (((TObjDFTenchuFuru *)object)->m_20 + lbl_805D8AA0);
    particle_emitter = (u8 *)(create_particle_emitter((object + 0x1C), 0x134));
    ((TObjDFTenchuFuru *)object)->m_2c = particle_emitter;
    if (particle_emitter != NULL) {
        ((TBoss4Type2 *)(((TObjDFTenchuFuru *)object)->m_2c))->set_flags(0x40);
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

typedef char RecoveredGlobal_80051A18_lbl_804FF240_size[sizeof(RecoveredGlobal_80051A18_lbl_804FF240) == 0x60 ? 1 : -1];
void TObjDFTenchuFuru::capture_matrix_by_frame() {
    switch ((s32) (*(s32 *)&TObjDFTenchuFuru__matrix_node_index)) {
    case 0x3B:
        get_current_matrix((&df_captured_matrix_pair.value));
        break;
    case 0x3A:
        get_current_matrix(((u8 *)&df_captured_matrix_pair.value + 0x30));
        break;
    }
    (*(s32 *)&TObjDFTenchuFuru__matrix_node_index) += 1;
}

int TObjDFTenchuFuru__sub_80051A7C(void) { return set_global_state__16TObjEneRe7BeruraFl((void*)(0)); }

void TObjDFTenchuFuru::register_callback() { TObjDFTenchuFuru__matrix_node_index = 0; set_global_state__16TObjEneRe7BeruraFl(((unsigned char *)TObjDFTenchuFuru::capture_matrix_by_frame)); }
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
        post_translate_matrix(var_r31 + 8);
        rotate_matrix_by_node_angles(var_r31 + 0x14, (int) (((RecoveredFields_80051AD0_var_r31 *)var_r31)->field_0 & 0x20));
        scale_current_matrix(var_r31 + 0x20);
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

extern char lbl_8043748C[];
extern char lbl_8043749C[];
extern char lbl_804374AC[];
extern char lbl_804374C0[];
extern char lbl_804374CC[];
const char *TObjDFRecover__name = lbl_8043748C;
s32 TObjDFRecBall__name = (s32)lbl_8043749C;
void *TObjDFBeamCursor__name = lbl_804374AC;
s32 TObjDFJisin__name = (s32)lbl_804374C0;
s32 TObjDFHorming__name = (s32)lbl_804374CC;
