#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TObjEneBm5GibonU.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneGyaranzo.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"
#include "pso/object/TObjGyaranzoMissile.h"

#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>
typedef char GyaranzoPositionOffset[offsetof(TObjEneGyaranzo, position) == 0x38 ? 1 : -1];
typedef char GyaranzoYawOffset[offsetof(TObjEneGyaranzo, rotation_y) == 0x60 ? 1 : -1];

typedef struct Vec_800D1E4C {
    f32 x, y, z;
} Vec_800D1E4C;

typedef struct Col_800D1E4C {
    u8 pad0[0x18];
    u32 flags;
} Col_800D1E4C;

typedef struct Param_800D1E4C {
    u8 pad0[4];
    f32 speed;
    s32 turn;
} Param_800D1E4C;

typedef struct Ene_800D1E4C {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x38 - 0x34];
    Vec_800D1E4C pos;
    u8 pad44[0x50 - 0x44];
    Vec_800D1E4C target;
    u8 pad5C[0xA4 - 0x5C];
    Col_800D1E4C *col;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_800D1E4C v290;
    Vec_800D1E4C v29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800D1E4C v2FC;
    u8 v308[0x350 - 0x308];
    Param_800D1E4C *param;
    u8 pad354[0x37C - 0x354];
    s32 state;
} Ene_800D1E4C;

#include "dolphin/mtx.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct VBase_18_5c0ed3 { char pad[0x18]; };

struct VObj_18_5c0ed3 : VBase_18_5c0ed3 {
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
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s16, f32 *);
};

struct Vec_800D2900 { f32 x, y, z; };

struct Params_800D2900 {
    u8 pad0[0xC];
    Vec_800D2900 pos;
    u8 pad18[0x38 - 0x18];
    f32 x38;
    u8 pad3c[4];
    s32 x40;
    s32 x44;
    u8 pad48[4];
};

struct Inner_800D2900 { u8 pad[0x3c]; s32 x3c; };

struct Outer_800D2900 { u8 pad[0x42c]; Inner_800D2900 *p42c; };

extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
s32 spawn_particle_effect(void *, int);
u8 * TObjGyaranzoMissile__sub_800D4668(void *, void *, void *, s32, s32);
s32 play_sound_effect(int, void *, int, int);
s32 render_anim_model_at_pos__15TObjEnemyCustomFv(void *);
void * __nw__7TObjectFUl(int);
extern const f32 lbl_805DA268;
extern const f32 lbl_805DA26C;
extern const f32 lbl_805DA270;

u8 *__ct__8TObjChipFP7TObjectP14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
extern Params_800D2900 lbl_8043C35C;
extern u8 *gyaranzo_resource_ptrs[];
extern u32 gyaranzo_bml_resource;
extern u8 *tl_05;
void update_collisions__10TObjPlayerFv(void *);
#define update_collisions__10TObjPlayerFv ((void (*)(void *))update_collisions__10TObjPlayerFv)
void apply_actor_gravity(void *, int, f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void calc_velocity_toward_destination(void *, Vec_800D1E4C, Vec_800D1E4C, f32);
s32 update_if_active__15TObjEneMe1GiGueFl(void *, int);
extern const f32 lbl_805DA258;
extern const f32 lbl_805DA25C;
void update_walk_to_target__10TObjPlayerFPv(Ene_800D1E4C *arg0);

void update_walk_to_target__10TObjPlayerFPv(Ene_800D1E4C *arg0) {
    switch (arg0->state) {
    case -1:
        break;
    case 0:
        arg0->col->flags &= ~0x380000;
        arg0->flags30 &= ~0x100;
        arg0->fB8 = 1;
        VecCopy((Vec *)&arg0->v29C, (const Vec *)&arg0->target);
        arg0->state = 1;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity(arg0, 0, lbl_805DA258);
        VecCopy((Vec *)&arg0->v290, (const Vec *)&arg0->v2FC);
        calc_velocity_toward_destination(arg0, arg0->v290, arg0->v29C, arg0->param->speed);
        ((TObjEnemy *)arg0)->turn_toward_direction(arg0->param->turn, (Vec *)arg0->v308);
        move_with_wall_slide((u8 *)arg0);
        update_collisions__10TObjPlayerFv(arg0);
        if (xz_distance_squared((Vec *)&arg0->pos, (Vec *)&arg0->target) <= lbl_805DA25C) {
            update_if_active__15TObjEneMe1GiGueFl(arg0, 0);
        }
        break;
    }
}
}
#undef update_collisions__10TObjPlayerFv
#pragma push

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
struct Base_Sub_800D1F84 { char pad[0x14]; };
struct V_Sub_800D1F84 : Base_Sub_800D1F84 {
    PADV4
    PADV
    virtual s32 m5();
};

struct Entry_800D20BC { u32 id; f32 dist; };

struct Vec_800D20BC { f32 x, y, z; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct VBase_18_f1aa6a { char pad[0x18]; };

struct VObj_18_f1aa6a : VBase_18_f1aa6a {
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
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual s32 m63(s32, void *);
};

struct Vec_800D23D4 { f32 x, y, z; };

struct Desc_800D23D4 { Vec_800D23D4 *pos; s32 a; s32 angle; f32 b; f32 c; f32 d; };

f32 get_gyaranzo_missile_float_parameter(s32);
extern f32 lbl_805D51F0;
extern f32 TObjGyaranzoMissile__speed_scale;
extern f32 TObjGyaranzoMissile__max_range;
extern "C" {
void init_params_from_table__15TObjEneGyaranzoFv(u8 *arg0);
s32 check_path_obstructed(void *, void *);
u8 *get_player_data__10TObjPlayerFi(s32);
u16 get_entity_id(void *);
s32 subtract_vector(void *, void *);
extern Entry_800D20BC TObjGyaranzoMissile_target_slots[];
extern s32 registered_player_count;
extern s32 lbl_805D5870;
extern const f32 lbl_805DA260;
void select_targets__15TObjEneGyaranzoFv(u8 *arg0);
}
s32 get_gyaranzo_missile_int_parameter(s32 i);
extern "C" {
s32 TObjGyaranzoMissile__ct(void *, void *, void *, u16);
void *__nw__7TObjectFUl(int);
extern s32 gyaranzo_missile_volley_end_time;
void spawn_missile_volley__19TObjGyaranzoMissileFPv(u8 *arg0);
void update__19TObjGyaranzoMissileFPv(u8 *arg0);
s32 TBoss3Volopt__sub_800D8D88(void *, s32);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);

void TObjEneGyaranzo::init_params_from_table() {
    *(f32 *)((s8 *)this->movementParameters + 4) = get_gyaranzo_missile_float_parameter(1);
    lbl_805D51F0 = get_gyaranzo_missile_float_parameter(2);
    TObjGyaranzoMissile__speed_scale = get_gyaranzo_missile_float_parameter(3);
    TObjGyaranzoMissile__max_range = get_gyaranzo_missile_float_parameter(4);
}

void update__19TObjGyaranzoMissileFPv(u8 *arg0) {
    s32 temp_r4;
    s32 temp_r5;

    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (*(s32 *)((s8 *)arg0 + 0x388) | 4);
        temp_r4 = *(s32 *)((s8 *)arg0 + 0x30) | 0x04000000;
        *(s32 *)((s8 *)arg0 + 0x30) = temp_r4;
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        TBoss3Volopt__sub_800D8D88(arg0 + 0x2FC, temp_r4);
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x3D0);
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        if (((V_Sub_800D1F84 *) (arg0 + 0x3D0))->m5() == 1) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        }
        return;
    case -1:
        temp_r5 = *(s32 *)((s8 *)arg0 + 0x388);
        *(s32 *)((s8 *)arg0 + 0x388) = (s32) (temp_r5 & ~5);
        *(s32 *)((s8 *)arg0 + 0x30) = (s32) (*(s32 *)((s8 *)arg0 + 0x30) & 0xFBFFFFFF);
        ((s32 (*)(void *, s32, s32))update_if_active__15TObjEneMe1GiGueFl)(arg0, 0, temp_r5);
        break;
    }
}

void TObjEneGyaranzo::select_targets() {
    s32 count;
    s32 n;
    s32 best;
    s32 i;
    u8 *p;
    s32 j;
    s32 k;
    f32 dist;
    Vec_800D20BC d;
    u8 *arg0 = (u8 *)this;
    TObjGyaranzoMissile_target_slots[0].id = 0xFFFF;
    TObjGyaranzoMissile_target_slots[0].dist = lbl_805DA258;
    n = 0;
    best = 0;
    k = ((TObjCollidable *)arg0)->obj_testFlags30(0x10);
    count = registered_player_count;
    if (k != 0) {
        count += lbl_805D5870;
    }
    for (i = 0; i < count; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (TObjPlayer::is_valid_and_active((u32)p) == 0) continue;
        if (p == arg0) continue;
        if (*(u32 *)((s8 *)p + 0x30) & 0x2000800) continue;
        VecCopy((Vec *)&d, (const Vec *)(p + 0x2FC));
        subtract_vector(&d, (u8 *)&this->m_2fc);
        dist = d.x * d.x + d.z * d.z;
        if (!(dist < lbl_805DA260)) continue;
        if (check_path_obstructed(arg0, p + 0x2FC) == 1) continue;
        TObjGyaranzoMissile_target_slots[n].dist = dist;
        TObjGyaranzoMissile_target_slots[n].id = get_entity_id(p);
        if (n > 0 && TObjGyaranzoMissile_target_slots[n].dist > TObjGyaranzoMissile_target_slots[best].dist) {
            best = n;
        }
        n++;
        if (n >= 4) break;
    }
    {
        Entry_800D20BC def = { 0xFFFF, 0.0f };
        switch (n) {
        case 0:
            for (i = 0; i < 4; i++) {
                ((TObjGyaranzoMissile *)(&TObjGyaranzoMissile_target_slots[i]))->copy_from(&def);
            }
            break;
        case 2:
            for (i = n; i < 4; i++) {
                ((TObjGyaranzoMissile *)(&TObjGyaranzoMissile_target_slots[i]))->copy_from(&TObjGyaranzoMissile_target_slots[i % n]);
            }
            break;
        default:
            for (i = n; i < 4; i++) {
                ((TObjGyaranzoMissile *)(&TObjGyaranzoMissile_target_slots[i]))->copy_from(&TObjGyaranzoMissile_target_slots[best]);
            }
            break;
        }
    }
    *(s32 *)((s8 *)arg0 + 0x3CC) = n;
    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 4; j++) {
            if (TObjGyaranzoMissile_target_slots[i].dist > TObjGyaranzoMissile_target_slots[j].dist) {
                Entry_800D20BC tmp;
                ((TObjGyaranzoMissile *)(&tmp))->copy_from(&TObjGyaranzoMissile_target_slots[i]);
                ((TObjGyaranzoMissile *)(&TObjGyaranzoMissile_target_slots[i]))->copy_from(&TObjGyaranzoMissile_target_slots[j]);
                ((TObjGyaranzoMissile *)(&TObjGyaranzoMissile_target_slots[j]))->copy_from(&tmp);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        *(u32 *)(arg0 + i * 4 + 0x3BC) = TObjGyaranzoMissile_target_slots[i].id;
    }
}

void TObjGyaranzoMissile::copy_from(void* q) { *(u32 *)&this->m_name = *(u32*)((char*)q + 0x0); *(f32 *)&this->m_flags = *(f32*)((char*)q + 0x4); }
#define V ((VObj_18_f1aa6a *)(arg0))
#define NEW(d, id) { void *o = __nw__7TObjectFUl(0xDC); if (o != NULL) { TObjGyaranzoMissile__ct(o, arg0, &d, id); } }
#pragma pool_data off
void spawn_missile_volley__19TObjGyaranzoMissileFPv(u8 *arg0) {
    Vec_800D23D4 pos;
    s32 i;
    gyaranzo_missile_volley_end_time = get_gyaranzo_missile_int_parameter(1) + 0x96;
    render_anim_model_at_pos__15TObjEnemyCustomFv(arg0);
    {
        Desc_800D23D4 d1 = { &pos, -0x1000, *(s32 *)((s8 *)arg0 + 0x60) + 0x800, 1024.0f, 3.0f, 0.0f };
        Desc_800D23D4 d2 = { &pos, -0x2000, *(s32 *)((s8 *)arg0 + 0x60) + 0x800, 2048.0f, 10.0f, 0.4f };
        Desc_800D23D4 d3 = { &pos, -0x1000, *(s32 *)((s8 *)arg0 + 0x60) - 0x800, 1024.0f, 3.0f, 0.0f };
        Desc_800D23D4 d4 = { &pos, -0x2000, *(s32 *)((s8 *)arg0 + 0x60) - 0x800, 2048.0f, 10.0f, 0.4f };
        u16 ids[4] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
        s32 idx[4] = { 0, 3, 1, 2 };
        for (i = 0; i < 4; i++) {
            ids[i] = *(s32 *)(arg0 + idx[i] * 4 + 0x3BC);
        }
        V->m63(0x10, &pos);
        NEW(d1, ids[0]);
        NEW(d2, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        V->m63(0x14, &pos);
        NEW(d3, ids[0]);
        NEW(d4, ids[1]);
        spawn_particle_effect(&pos, 0xF3);
        if (*(s32 *)((s8 *)arg0 + 0x3A8) >= 1) {
            V->m63(0x11, &pos);
            NEW(d1, ids[0]);
            NEW(d2, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            V->m63(0x15, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
        if (*(s32 *)((s8 *)arg0 + 0x3A8) >= 2) {
            V->m63(0x12, &pos);
            NEW(d1, ids[0]);
            NEW(d2, ids[1]);
            spawn_particle_effect(&pos, 0xF3);
            V->m63(0x16, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            V->m63(0x13, &pos);
            NEW(d1, ids[2]);
            NEW(d2, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
            V->m63(0x17, &pos);
            NEW(d3, ids[2]);
            NEW(d4, ids[3]);
            spawn_particle_effect(&pos, 0xF3);
        }
    }
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD0A)), arg0 + 0x38, 0, 0);
}
}
#pragma pool_data reset

#pragma pop
#undef V
#undef NEW

struct Vec_800D3314 { f32 x, y, z; };

struct VBase_800D3314 { char pad[0x18]; };

struct VObj_800D3314 : VBase_800D3314 {
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
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63(int, void *);
};

#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/object/TObjFish.h"

struct Vec_800D2CE4 { f32 x, y, z; };

struct Vec_800D30A8 { f32 x, y, z; };

struct Obj_800D30A8 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB4 - 0x34];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    Vec_800D30A8 pos;
    Vec_800D30A8 vel;
    u8 pad314[0x374 - 0x314];
    s32 f374;
    u8 pad378[0x37C - 0x378];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
};

extern "C" {
u16 find_nearest_visible_player(void *, int, int, f32);
#define select_targets__15TObjEneGyaranzoFv ((s32 (*)(void *))select_targets__15TObjEneGyaranzoFv)
extern const f32 lbl_805DA290;
void enemy_turn_toward_dest(void *, s32);
void move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff(void *, Vec_800D3314, void *, f32, f32);
#define render_anim_model_at_pos__15TObjEnemyCustomFv ((void (*)(void *))render_anim_model_at_pos__15TObjEnemyCustomFv)
u8 *find_active_entity_by_id(u16);
#define play_sound_effect ((s32 (*)(void *, void *, int, int))play_sound_effect)
extern s32 actor_frame_tick;
void TObjPlayer__sub_800D3314(u8 *arg0);
#define spawn_missile_volley__19TObjGyaranzoMissileFPv ((s32 (*)())spawn_missile_volley__19TObjGyaranzoMissileFPv)
extern const f32 lbl_805DA274;
extern const f32 lbl_805DA278;
#define check_path_obstructed ((s32 (*)(void *, Vec_800D30A8 *))check_path_obstructed)
extern const f32 lbl_805DA280;
void TObjPlayer__sub_800D30A8(Obj_800D30A8 *arg0);
typedef struct Ene_800D2E8C {
    u8 pad0[0x38C];
    s32 count;
    u8 pad390[0x3A8 - 0x390];
    s32 f3A8;
} Ene_800D2E8C;

typedef struct Ene_800D2F6C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    f32 pos[3];
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    f32 v2FC[3];
    u8 pad308[0x33C - 0x308];
    s16 timer;
    u8 pad33E[0x37C - 0x33E];
    s32 state;
} Ene_800D2F6C;

struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct VBase_18_ca64a0 { char pad[0x18]; };

struct VObj_18_ca64a0 : VBase_18_ca64a0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

struct Elem_800D35D8 { u8 pad[0x1C]; };

struct Obj_800D35D8 { u8 pad[0x3D0]; VObj_14_fddec9 light; u8 pad2[0x3EC - 0x3D0 - sizeof(VObj_14_fddec9)]; Elem_800D35D8 arr[2]; };

struct Vec_800D35D8 { s32 x, y, z; };

struct Ene_800D2E8C;

struct Base_800D3BA0_800D3B38 { char pad[0xC]; };

struct VObj_800D3BA0_800D3B38 : Base_800D3BA0_800D3B38 {
    virtual void m0(s32);
};

struct Pos_800D3C04 { s32 w[4]; };

struct Res_800D3C04 { u8 pad0[0x38]; s32 r38; s32 r3C; u8 pad40[8]; s32 r48; };

struct Area_800D3C04 { u8 pad0[0x42C]; Res_800D3C04 *res; s32 f430; };

struct Obj_800D3E54 { u8 pad0[0x18]; void *vt; };

struct E_800D3ED8 { u8 pad[0x1C]; };

struct Gy_800D3ED8 { u8 pad[0x3EC]; E_800D3ED8 e3EC[4]; };

s32 is_split_screen();
void queue_destruction__7TObjectFv(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 get_bml_motion(u32, int);
s32 TLobby__sub_8001FE7C(u32, s32);
u32 load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 get_camera_mode__11TCameraCtrlFv();
s32 copy_position__20TBoss3VoloptHiraisinFv(void *);
VObj_800D3BA0_800D3B38 * init__11TBreakUpMdlFPviif(void *, s32, s32, f32);
u32 load_enemy_bml_resource_named(void *, void *);
void __dt__15TObjEnemyCustomFv(void *, int);
s32 __ct__15TObjEnemyCustomFP7TObject(void *);
#define update_walk_to_target__10TObjPlayerFPv ((s32 (*)(void *))update_walk_to_target__10TObjPlayerFPv)
#define init_params_from_table__15TObjEneGyaranzoFv ((s32 (*)(void *))init_params_from_table__15TObjEneGyaranzoFv)
#define update__19TObjGyaranzoMissileFPv ((s32 (*)(void *))update__19TObjGyaranzoMissileFPv)
s32 fn_800D2A68(void *);
void TObjPlayer__sub_800D2E8C(Ene_800D2E8C *arg0);
void vfunc_63__15TObjEneGyaranzoFv(u8 *arg0);
void vfunc_62__15TObjEneGyaranzoFv(u8 *arg0);
void TObjPlayer__sub_800D35D4(void);
void render__15TObjEneGyaranzoFv(u8 *arg0);
void run_task__15TObjEneGyaranzoFv(u8 *arg0);
Obj_800D3E54 * fn_800D3E54(Obj_800D3E54 *arg0, s16 arg1);
u8 *TObjEneGyaranzo__ct(TObjEneGyaranzo *arg0, s32 arg1, u8 *arg2);
s32 __dt__13TUnk_80494938Fv(void *, s16);
s32 update_fast__15RenderFadeStateFv(int);
void __dt__15RenderFadeStateFv();
void __ct__15RenderFadeStateFv(void *);
void create_dead_spot__10TObjPlayerFllf(void *, s32, f32);
s32 set_param__9TObjEnemyFl(void *, int, int, int);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void * __ct__11TObjControlFP7TObject(void *, void *);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, void *, int);
s32 submit_cursor_candidate(void *, s32);
s32 minimap_render_dot(void *, s32, s32, s32);
s32 defer_render__7TObjectFv(void *);
s32 __dl__7TObjectFPv(void *);
s32 spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
void __destroy_arr(void *, void *, int, int);
s32 __construct_array(void *, void *, void *, int, int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
s32 draw_chunk_object(int);

extern Pos_800D3C04 lbl_8043C25C;
extern Vec_800D35D8 lbl_8043C26C;
extern s32 lbl_8043C428[];
extern u32 *gyaranzo_model_resources[];
extern s32 lbl_805D2A78;
extern s32 gyaranzo_boss_stats_handle;
extern s32 gyaranzo_boss_stats_ptr_b;
extern s32 gyaranzo_object_handle;
extern s32 gyaranzo_missile_param_table;
extern u32 *lbl_805D5200;
extern u32 *lbl_805D5204;
extern s32 gyaranzo_breakup_model_obj;
extern s32 saved_model_render_flags;
extern const f32 lbl_805DA27C;
extern const f32 lbl_805DA284;
extern const f32 lbl_805DA288;
extern const f32 lbl_805DA28C;
extern const f32 lbl_805DA294;
extern const f32 lbl_805DA298;
extern s32 model_render_flags;
extern void *tl_04;

extern "C" {
void get_anim_node_position__15TObjEnemyCustomFlP3Vec();
}
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void vfunc_28__15TObjEnemyCustomFv();
}
extern "C" {
void vfunc_61__15TObjEneGyaranzoFv();
}
extern "C" {
void vfunc_59__15TObjEneGyaranzoFv();
}
extern "C" {
void is_target_in_attack_range__15TObjEneGyaranzoFv();
}
extern "C" {
void vfunc_58__15TObjEneGyaranzoFv();
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_confusion_status__9TObjCharaFv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUcf();
}
extern "C" {
void apply_movement_ailment__9TObjCharaFl();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_paralysis__9TObjCharaFv();
}
extern "C" {
void apply_poison_status__9TObjCharaFv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__9TObjCharaFv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void vfunc_79__15TObjEnemyCustomFPl();
}
extern "C" {
void check_and_update__16TObjEneBm5GibonUFv();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void clear_harmful_statuses__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFv();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__9TObjCharaFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
extern u8 lbl_8043C100[];
}
extern "C" {
extern u8 lbl_8043C114[];
}
extern "C" {
extern u8 lbl_8043C128[];
}
extern "C" {
extern u8 lbl_8043C13C[];
}
extern "C" {
extern u8 lbl_8043C14C[];
}
extern "C" {
extern u8 lbl_8043C15C[];
}
extern "C" {
extern u8 lbl_8043C16C[];
}
extern "C" {
extern u8 lbl_8043C180[];
}
extern "C" {
extern u8 lbl_8043C198[];
}
extern "C" {
extern u8 lbl_8043C1B0[];
}
extern "C" {
extern u8 lbl_8043C1C8[];
}
extern "C" {
extern u8 lbl_8043C1DC[];
}
extern "C" {
extern u8 lbl_8043C1F0[];
}
extern "C" {
extern u8 lbl_8043C208[];
}
extern "C" {
extern u8 lbl_8043C220[];
}
extern "C" {
extern u8 lbl_8043C238[];
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv();
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv();
}
extern "C" {
void try_activate__16TObjEneBm5GibonUFv();
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void update_action_hold_status__9TObjCharaFv();
}
extern "C" {
void vfunc_37__9TObjCharaFv();
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
void update_attack_stat_status__9TObjCharaFv();
}
extern "C" {
void update_defense_stat_status__9TObjCharaFv();
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void vfunc_60__15TObjEnemyCustomFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
extern void *bm_ene_gyaranzo_model_names[8];
extern void *bm_ene_gyaranzo_motion_names[9];
void *bm_ene_gyaranzo_model_names[8] = {
    (void *)&lbl_8043C100, (void *)&lbl_8043C114, (void *)&lbl_8043C128, (void *)&lbl_8043C13C,
    (void *)&lbl_8043C14C, (void *)&lbl_8043C15C, (void *)&lbl_8043C16C, (void *)0x0,
};
void *bm_ene_gyaranzo_motion_names[9] = {
    (void *)&lbl_8043C180, (void *)&lbl_8043C198, (void *)&lbl_8043C1B0, (void *)&lbl_8043C1C8,
    (void *)&lbl_8043C1DC, (void *)&lbl_8043C1F0, (void *)&lbl_8043C208, (void *)&lbl_8043C220,
    (void *)0x0,
};
void *bm_ene_gyaranzo_resource_descriptor[4] = {
    (void *)&lbl_8043C238, (void *)&bm_ene_gyaranzo_model_names, (void *)&bm_ene_gyaranzo_motion_names, (void *)0x70008,
};
TObjMotionAction gyaranzo_action_table[8] = {
    {2, 0, 4, 0.7f, 0},
    {2, 5, 5, 0.7f, 1},
    {2, 0, 0, 1.0f, 4},
    {2, 0, 2, 0.8f, 8},
    {3, 4, 3, 1.0f, 0x10},
    {1, 5, 6, 0.7f, 1},
    {2, 0, 7, 0.8f, 1},
    {2, 0, 1, 1.0f, 8},
};
void *lbl_804941DC[7] = {
    (void *)0x43160000, (void *)0x3f0e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_804941F8[11] = {
    (void *)0x0, (void *)0x41900000, (void *)0x0, (void *)0x41900000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *gyaranzo_resource_index_table[11] = {
    (void *)0x60007, (void *)0xa000b, (void *)0xc000f, (void *)0xe0009,
    (void *)0x80025, (void *)0x210036, (void *)0x2c0010, (void *)0x110012,
    (void *)0x130014, (void *)0x150016, (void *)0x170018,
};
void *gyaranzo_flagged_resource_index_table[7] = {
    (void *)0x20003, (void *)0x4000b, (void *)0xc0000, (void *)0x10005,
    (void *)0x60007, (void *)0x80009, (void *)0xa0000,
};
void *gyaranzo_death_breakup_params[7] = {
    (void *)0x14, (void *)0x3d75c28f, (void *)0x3fc00000, (void *)0x3f666666,
    (void *)0x3df5c28f, (void *)0x3f0ccccd, (void *)0x3f000000,
};
void *gyaranzo_actor_vtable_ops[83] = {
    (void *)0x0, (void *)0x0, (void *)&fn_800D3E54, (void *)&run_task__15TObjEneGyaranzoFv,
    (void *)&render__15TObjEneGyaranzoFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__15TObjEnemyCustomFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__15TObjEneGyaranzoFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&check_and_update__16TObjEneBm5GibonUFv,
    (void *)&try_activate__16TObjEneBm5GibonUFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__15TObjEneGyaranzoFv, (void *)&vfunc_59__15TObjEneGyaranzoFv,
    (void *)&vfunc_60__15TObjEnemyCustomFv, (void *)&vfunc_61__15TObjEneGyaranzoFv, (void *)&vfunc_62__15TObjEneGyaranzoFv, (void *)&vfunc_63__15TObjEneGyaranzoFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__15TObjEnemyCustomFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__15TObjEnemyCustomFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
#define bm_ene_gyaranzo_resource_descriptor ((s32 *)bm_ene_gyaranzo_resource_descriptor)
#define gyaranzo_resource_index_table ((s16 *)gyaranzo_resource_index_table)
#define gyaranzo_flagged_resource_index_table ((s16 *)gyaranzo_flagged_resource_index_table)
#define gyaranzo_death_breakup_params ((u8 *)gyaranzo_death_breakup_params)
#define gyaranzo_actor_vtable_ops ((u8 *)gyaranzo_actor_vtable_ops)

#pragma push
#pragma fp_contract on
void TObjEneGyaranzo::spawn_missile() {
    Vec launch_position;
    s32 temp_r31;
    u8 *temp_r3;
    render_anim_model_at_pos__15TObjEnemyCustomFv(this);
    ((VObj_18_f1aa6a *)(this))->m63(0x18, &launch_position);
    temp_r31 = (s32) (lbl_805DA268 * ((lbl_805DA26C * random_ratio__9TObjCharaFv((s32) this)) - lbl_805DA270));
    temp_r3 = (u8 *)(((u8 *)__nw__7TObjectFUl(0xF0)));
    if (temp_r3 != NULL) {
        TObjGyaranzoMissile__sub_800D4668(temp_r3, this, &launch_position, rotation_y, temp_r31);
    }
    spawn_particle_effect((void *)((s32) &launch_position), 0xF3);
    play_sound_effect((void *)(((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x4003B20D))), &position, 0, 0);
}
#pragma pop

void TObjEneGyaranzo::sub_800D2900() {
    s32 start;
    s32 end;
    s32 i;
    s32 idx;
    Vec_800D2900 v;
    void *obj;
    if (*(s32 *)&this->m_3a8 < 2) {
        (*(s32 *)&this->m_3a8)++;
        switch (*(s32 *)&this->m_3a8) {
        case 1:
            start = 0;
            *(s32 *)&this->m_38c = 5;
            end = 5;
            break;
        case 2:
            start = 5;
            *(s32 *)&this->m_38c = 0xD;
            end = 0xD;
            break;
        }
        render_anim_model_at_pos__15TObjEnemyCustomFv(this);
        for (i = start; i < end; i++) {
            idx = gyaranzo_flagged_resource_index_table[i];
            ((VObj_18_5c0ed3 *)(this))->m63(gyaranzo_resource_index_table[idx], &v.x);
            {
                Params_800D2900 p = lbl_8043C35C;
                p.pos.x = v.x;
                p.pos.y = v.y;
                p.pos.z = v.z;
                p.x38 = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
                p.x40 = ((s32 *)&gyaranzo_resource_ptrs)[idx];
                p.x44 = (*(Outer_800D2900 * *)&gyaranzo_bml_resource)->p42c->x3c;
                obj = __nw__7TObjectFUl(0x234);
                if (obj != NULL) {
                    __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)obj, tl_05, (u8 *)&p);
                }
            }
        }
    }
}

void TObjPlayer::update_aim_and_fire() {
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;
    s32 var_r30;
    u8 *temp_r6;
    void *uninit;
    switch (this->m_37c) {
    case 0:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 | 0x40000);
        this->requested_action = 0;
        this->m_37c = 1;
    case 1:
        var_r30 = 0;
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(lbl_805DA274);
        }
        temp_r6 = this->target;
        if (temp_r6 != NULL) {
            Vec_800D2CE4 v = *(Vec_800D2CE4 *)(temp_r6 + 0x38);
            subtract_vector(&v, (void *) (((u8 *)this) + 0x38));
            temp_r3 = ((TObjEnemy *)this)->turn_toward_direction((*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x350)) + 8)), (Vec *)&v);
            temp_r4 = temp_r3 >> 0x1F;
            if ((s32) ((temp_r4 ^ temp_r3) - temp_r4) < 0xE38) {
                var_r30 = 1;
            }
        } else {
            var_r30 = 1;
        }
        if (var_r30 != 0) {
            *(s16 *)&this->unk_33C = get_gyaranzo_missile_int_parameter(0);
            this->requested_action = 2;
            this->m_37c = 2;
        }
        break;
    case 2:
        if (this->frame >= lbl_805DA278) {
            spawn_missile_volley__19TObjGyaranzoMissileFPv();
            this->m_37c = 3;
        }
        break;
    case 3:
        *(s16 *)&this->unk_33C = (s16) (*(s16 *)&this->unk_33C - 1);
        if (*(s16 *)&this->unk_33C <= 0) {
            this->m_37c = -1;
            update_if_active__15TObjEneMe1GiGueFl(uninit, 0);
        }
        break;
    case -1:
        *(s32 *)&this->unk_388 = (s32) (*(s32 *)&this->unk_388 & 0xFFFBFFFF);
        break;
    }
    advance_animation();
    apply_actor_gravity(this, 0, lbl_805DA258);
    update_collisions__10TObjPlayerFv(this);
}

void TObjPlayer__sub_800D2E8C(Ene_800D2E8C *arg0) {
    s32 i;
    for (i = 0; i < arg0->count; i++) {
        *gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]] |= 8;
    }
    for (; i < 13; i++) {
        *gyaranzo_model_resources[gyaranzo_flagged_resource_index_table[i]] &= ~8;
    }
    if (arg0->f3A8 >= 1) {
        *lbl_805D5200 |= 8;
        *lbl_805D5204 |= 8;
    } else {
        *lbl_805D5200 &= ~8;
        *lbl_805D5204 &= ~8;
    }
}

void TObjPlayer::update_death_breakup() {
    Ene_800D2F6C *arg0 = (Ene_800D2F6C *)this;
    switch (this->m_37c) {
    case 0:
        this->requested_action = 4;
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        arg0->timer = 0x5A;
        create_dead_spot__10TObjPlayerFllf(arg0->v2FC, 0x5A, lbl_805DA27C);
        create_dead_spot__10TObjPlayerFllf(arg0->v2FC, 0x5A, lbl_805DA27C);
        this->m_37c = 1;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        arg0->timer--;
        if (arg0->timer < 0) {
            TBoss3Volopt::create_breakup_mdl((s32)gyaranzo_breakup_model_obj, (s32)gyaranzo_death_breakup_params, (s32)this->texlist, (s32)arg0->v2FC, (s32)this->rotation_y);
            ((TObjEnemy *)arg0)->send_entity_set_flags();
            ((TObjPlayer *)(arg0->v2FC))->trigger_dell_biter_events();
            play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003AD10)), arg0->pos, 0, 0);
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    case -1:
        return;
    }
}

void TObjEneGyaranzo::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    ((TObjEneMe1GiGue *)arg0)->set_state(5);
    this->m_388 = (s32) (this->m_388 | 1);
}

void TObjPlayer__sub_800D30A8(Obj_800D30A8 *enemy) {
    switch (enemy->state) {
    case 0:
        enemy->f30 &= ~0x200000;
        enemy->fB8 = 3;
        enemy->state = 1;
    case 1: {
        ((TObjMotion *)enemy)->advance_animation();
        Vec_800D30A8 v = enemy->pos;
        v.x += enemy->vel.x;
        v.z += enemy->vel.z;
        if (check_path_obstructed(enemy, &v) == 0) {
            move_with_wall_slide((u8 *)enemy);
        } else {
            enemy->vel.x = enemy->vel.z = lbl_805DA258;
        }
        enemy->vel.x *= lbl_805DA280;
        enemy->vel.z *= lbl_805DA280;
        apply_actor_gravity(enemy, 0, lbl_805DA258);
        update_collisions__10TObjPlayerFv(enemy);
        if (enemy->fB4 != 8) {
            enemy->state = -1;
        }
        break;
    }
    case -1:
        enemy->f30 &= ~0x200;
        enemy->f388 &= ~1;
        enemy->f374 = 1;
        break;
    }
}

void TObjEneGyaranzo::vfunc_62() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r0;
  unsigned long var_r3;
  if ((this->mode) != 4)
  {
    if (((s32)this->m_3b8) <= 0)
    {
      this->m_3b8 = 0x3C;
      fn_800D2A68((void *) arg0);
    }
    temp_r0 = this->m_3a8;
    var_r3 = 0;
    switch (temp_r0)
    {
      case 0:
        var_r3 = (this->hp) <= ((this->hpmax) / 3);
        break;
      case 1:
        var_r3 = (this->hp) <= ((this->hpmax) / 4);
        break;
    }
    if (((s32) var_r3) != 0)
    {
      ((TObjEneGyaranzo *)arg0)->sub_800D2900();
    }
    this->referenceHp = this->hp;
    play_sound_effect((void *) ((TObjEnemy *)((void *) arg0))->remap_sound_for_area((s32)(0x4003AD0F)), (u8 *)&this->position, 0, 0);
    if (!((this->m_388) & 0x40000))
    {
      ((TObjEneMe1GiGue *)arg0)->set_state(4);
      this->m_388 = (s32) ((this->m_388) | 1);
      return;
    }
    ((TObjBase *)arg0)->obj_clearFlags30(0x200200);
  }
}

void TObjPlayer__sub_800D3314(u8 *arg0) {
    Vec_800D3314 v;
    u8 *p;
    *(u8 **)((s8 *)arg0 + 0x2A8) = find_active_entity_by_id(*(u16 *)((s8 *)arg0 + 0x338));
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        p = *(u8 **)((s8 *)arg0 + 0xA4);
        *(u32 *)((s8 *)p + 0x18) &= ~0x380000;
        *(u32 *)((s8 *)arg0 + 0x30) &= ~0x100;
        ((TObjEnemyCustom *)arg0)->sub_8004292C();
        *(f32 *)((s8 *)arg0 + 0x39C) = lbl_805DA258;
        *(f32 *)((s8 *)arg0 + 0x3A4) = lbl_805DA258;
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        if (*(s16 *)((s8 *)arg0 + 0x326) == 1) {
            *(f32 *)((s8 *)arg0 + 0x3A0) = get_gyaranzo_missile_float_parameter(0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x3A0) = lbl_805DA270;
            (*(s32 *)((s8 *)arg0 + 0x3B4))++;
        }
        play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003B209)))), arg0 + 0x38, 0, 0);
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        break;
    case 1:
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x390), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        } else {
            ((TObjEnemyCustom *)arg0)->vfunc_58();
            return;
        }
        enemy_turn_toward_dest(arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 8));
        ((void (*)(void *, Vec_800D3314, f32, f32))move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff)(arg0, *(Vec_800D3314 *)((s8 *)arg0 + 0x390), *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4), *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC));
        *(f32 *)((s8 *)arg0 + 0x39C) += *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity(arg0, 0, lbl_805DA258);
        if (*(s16 *)((s8 *)arg0 + 0x326) == 9) {
            *(f32 *)((s8 *)arg0 + 0x3A4) += *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4);
            if (*(f32 *)((s8 *)arg0 + 0x3A4) >= 20.0f) {
                *(f32 *)((s8 *)arg0 + 0x3A4) -= 20.0f;
                ((TObjEneGyaranzo *)arg0)->spawn_missile();
            }
        }
        if (!(actor_frame_tick & 3)) {
            render_anim_model_at_pos__15TObjEnemyCustomFv(arg0);
            ((VObj_800D3314 *)arg0)->m63(0x1F, &v);
            spawn_particle_effect(&v, 0xF3);
            ((VObj_800D3314 *)arg0)->m63(0x27, &v);
            spawn_particle_effect(&v, 0xF3);
        }
        update_collisions__10TObjPlayerFv(arg0);
        if (*(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0x18) & 0x380000) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        } else if (*(f32 *)((s8 *)arg0 + 0x39C) >= *(f32 *)((s8 *)arg0 + 0x3A0)) {
            *(s32 *)((s8 *)arg0 + 0x37C) = -1;
        }
        break;
    case -1:
        update_if_active__15TObjEneMe1GiGueFl(arg0, *(s32 *)((s8 *)arg0 + 0x378));
        break;
    }
}

void TObjPlayer__sub_800D35D4(void) {  }

#pragma push
#pragma opt_common_subs off
void TObjEneGyaranzo::render() {
    s32 temp_r3;
    s32 var_r30;
    s32 var_r29;
    if (!(this->actorFlags & 0x02000000)) {
        var_r30 = 0;
        if (is_split_screen() != 0) {
            var_r30 = get_camera_mode__11TCameraCtrlFv();
        }
        var_r29 = 1;
        temp_r3 = ((VObj_18_ca64a0 *)(this))->m9(lbl_805DA284, lbl_805DA288, lbl_805DA28C);
        if (temp_r3 != 0) {
            saved_model_render_flags = model_render_flags;
            var_r30 = (s32)&((Obj_800D35D8 *)((u8 *)this))->arr[var_r30];
            update_fast__15RenderFadeStateFv(var_r30);
            if (((RenderFadeState *)var_r30)->updateFromCamera((const f32*)(((u8 *)this) + 0x2FC)) != 0) {
                ((VObj_14_fddec9 *)(var_r30))->m6();
                if (defer_render__7TObjectFv(this) != 0) {
                    model_render_flags = saved_model_render_flags;
                    return;
                }
            }
            TObjPlayer__sub_800D2E8C((Ene_800D2E8C *) (this));
            TObjFish::set_global_param(this->texlist);
            select_actor_lighting(this);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            if (TObjPlayer::check_demo_mode() == 1) {
                draw_chunk_object((int) (*(s32 *)((s8 *)((u8 *)this) + 0x34)));
            } else if (this->m_388 & 4) {
                if (((Obj_800D35D8 *)((u8 *)this))->light.m8() != 0) {
                    ((Obj_800D35D8 *)((u8 *)this))->light.m6();
                    if (temp_r3 == 1) {
                        this->draw();
                    } else {
                        this->draw_motion_model();
                    }
                    ((Obj_800D35D8 *)((u8 *)this))->light.m7();
                } else {
                    var_r29 = 0;
                }
            } else if (temp_r3 == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            if (!(this->actorFlags & 0x800) && (var_r29 != 0)) {
                Vec_800D35D8 sp8 = lbl_8043C26C;
                this->render_with_position_override((u8 *)&sp8, 0);
            }
            ((VObj_14_fddec9 *)(var_r30))->m7();
        }
    }
}
#pragma pop

void TObjEneGyaranzo::sub_800D37F4() {
    s32 a;
    u16 r;
    switch (this->mode) {
    case 0:
    case 8:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            select_targets__15TObjEneGyaranzoFv(this);
            if (*(s32 *)&this->unk_3CC > 0) {
                switch (*(s32 *)&this->m_3a8) {
                case 0:
                    if (this->hp <= *(s32 *)&this->m_3b0) {
                        this->targetId = this->m_3c8;
                        a = 9;
                    } else {
                        this->targetId = this->m_3c0;
                        a = 1;
                    }
                    if (this->targetId != 0xFFFF) {
                        update_if_active__15TObjEneMe1GiGueFl(this, a);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                case 1:
                    this->targetId = this->m_3c0;
                    if (this->targetId != 0xFFFF) {
                        update_if_active__15TObjEneMe1GiGueFl(this, 9);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                case 2:
                    this->targetId = *(s32 *)((s8 *)((u8 *)this) + 0x3BC);
                    if (this->targetId != 0xFFFF) {
                        update_if_active__15TObjEneMe1GiGueFl(this, 9);
                        *(s32 *)&this->m_378 = 2;
                    }
                    break;
                }
            } else if (this->is_actor_cadence_frame(0x1E) != 0 &&
                       xz_distance_squared((Vec *)(((u8 *)this) + 0x38), (Vec *)(((u8 *)this) + 0x50)) > lbl_805DA25C) {
                update_if_active__15TObjEneMe1GiGueFl(this, 8);
            }
        }
        break;
    case 1:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            f32 *p = *(f32 * *)&this->movementParameters;
            r = find_nearest_visible_player(this, 0, (int)p, lbl_805DA290 + *p);
            if (this->targetId == 0xFFFF) {
                this->targetId = r;
            }
            if (this->targetId == 0xFFFF) {
                update_if_active__15TObjEneMe1GiGueFl(this, 8);
            }
        }
        break;
    }
}

void TObjPlayer::dispatch_state_update() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        ((TObjEnemyCustom *)arg0)->update_state();
        return;
      case 1:
        TObjPlayer__sub_800D3314((u8 *)((void *) arg0));
        return;
      case 2:
        ((TObjPlayer *)arg0)->update_aim_and_fire();
        return;
      case 4:
        TObjPlayer__sub_800D30A8((Obj_800D30A8 *)((void *) arg0));
        return;
      case 5:
        update_death_breakup();
        return;
      case 7:
        update__19TObjGyaranzoMissileFPv((void *) arg0);
        return;
      case 9:
        TObjPlayer__sub_800D3314((u8 *)((void *) arg0));
        return;
      case 8:
        update_walk_to_target__10TObjPlayerFPv((void *) arg0);
        break;
    }
  }
}

void TObjEneGyaranzo::run_task() {
    s32 temp_r3;

    if (TObjPlayer::check_demo_mode() == 1) {
        ((s32 (*)(void *))TObjPlayer__sub_800D35D4)(this);
        return;
    }
    this->sub_800D37F4();
    temp_r3 = this->m_3b8;
    if (temp_r3 >= 0) {
        this->m_3b8 = (temp_r3 - 1);
    }
    if ((s16) this->mode != (s32) this->next_action) {
        if ((s32) this->state != -1) {
            this->state = -1;
            ((TObjPlayer *)((u8 *)this))->dispatch_state_update();
        }
        this->mode = (s16) this->next_action;
        this->state = 0;
    }
    ((TObjPlayer *)((u8 *)this))->dispatch_state_update();
    this->update_prev_position();
    copy_position__20TBoss3VoloptHiraisinFv(this);
    submit_cursor_candidate(this, -1);
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
}

void *TObjEneGyaranzo::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x45C);
    if (o2 != NULL) {
        o2 = ((void * (*)(void *, void *, void *))TObjEneGyaranzo__ct)(o2, o, arg0);
    }
    return o2;
}

void TObjEneGyaranzo::free_static_instances() {
    if (gyaranzo_bml_resource != 0U) {
        TLobby__sub_8001FE7C(gyaranzo_bml_resource, 1);
        gyaranzo_bml_resource = 0U;
    }
    if ((*(struct VObj_800D3BA0_800D3B38 * *)&gyaranzo_breakup_model_obj) != 0) {
        if ((*(struct VObj_800D3BA0_800D3B38 * *)&gyaranzo_breakup_model_obj) != 0) {
            (*(struct VObj_800D3BA0_800D3B38 * *)&gyaranzo_breakup_model_obj)->m0(1);
        }
        (*(struct VObj_800D3BA0_800D3B38 * *)&gyaranzo_breakup_model_obj) = 0;
    }
}

#define AREA ((Area_800D3C04 *)gyaranzo_bml_resource)
void TLobby::load_gyaranzo_resources() {
    s32 i;
    void *p;

    if (TObjEneDD::check_v2_mode() != 0) {
        gyaranzo_bml_resource = load_enemy_bml_resource_named(bm_ene_gyaranzo_resource_descriptor, lbl_8043C428);
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = (void *)load_resource_from_descriptor(p, 5, bm_ene_gyaranzo_resource_descriptor, 0, 0, 0);
        }
        gyaranzo_bml_resource = (u32)p;
    }
    for (i = 0; i < 0x16; i++) {
        ((s32 *)gyaranzo_model_resources)[i] = (s32)find_model_node(AREA->res->r38, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        gyaranzo_resource_ptrs[i] = (u8 *)find_model_node(AREA->res->r48, gyaranzo_resource_index_table[i]);
    }
    for (i = 0; i < 0xD; i++) {
        *(s32 *)((s8 *)gyaranzo_resource_ptrs[i] + 0x30) = 0;
    }
    (*(s32 *)&lbl_805D5200) = (s32)find_model_node(AREA->res->r38, 0x19);
    (*(s32 *)&lbl_805D5204) = (s32)find_model_node(AREA->res->r38, 0xD);
    p = ::operator new(0x10);
    if (p != NULL) {
        p = init__11TBreakUpMdlFPviif(p, AREA->res->r38, get_bml_motion(gyaranzo_bml_resource, 3), lbl_805DA294);
    }
    (*(struct VObj_800D3BA0_800D3B38 * *)&gyaranzo_breakup_model_obj) = (VObj_800D3BA0_800D3B38 *)p;
    gyaranzo_boss_stats_handle = register_boss__6TLobbyFl(0x1D);
    gyaranzo_boss_stats_ptr_b = dispatch_shared_handler_b__6TLobbyFl(0x1D);
    gyaranzo_object_handle = register_object__6TLobbyFl(0x1D);
    gyaranzo_missile_param_table = dispatch_shared_handler_a__6TLobbyFl(0x1D);
    {
        Pos_800D3C04 pos = lbl_8043C25C;
        pos.w[0] = AREA->f430;
        spawn_npc_enemy__6TLobbyFslllff(0x20, AREA->res->r38, AREA->res->r3C, &pos, lbl_805DA298, lbl_805DA258);
        spawn_npc_enemy__6TLobbyFslllff(0x21, AREA->res->r48, AREA->res->r3C, &pos, lbl_805DA298, lbl_805DA258);
    }
}

#undef AREA
Obj_800D3E54 *fn_800D3E54(Obj_800D3E54 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vt = gyaranzo_actor_vtable_ops;
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x3EC, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80494938Fv((u8 *)arg0 + 0x3D0, -1);
        __dt__15TObjEnemyCustomFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneGyaranzo__ct(TObjEneGyaranzo *arg0, s32 arg1, u8 *arg2) {
    s16 temp_r6;
    s32 temp_r5;
    s32 i;
    s32 var_r31;

    ((void (*)(void *, s32, void *)) __ct__15TObjEnemyCustomFP7TObject)(arg0, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x18) = (u8 *) ((void * *)gyaranzo_actor_vtable_ops);
    __ct__13TUnk_80494938Fv(((u8 *)arg0 + 0x3D0));
    __construct_array((u8 *)arg0 + 0x3EC, &__ct__15RenderFadeStateFv, &__dt__15RenderFadeStateFv, 0x1C, 4);
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2A78;
    ((TObjEneGyaranzo *)(arg0))->apply_set_data(arg2);
    VecCopy((Vec *)((u8 *)arg0 + 0x290), (const Vec *)(VecCopy((Vec *)((u8 *)arg0 + 0x29C), (const Vec *)((u8 *)arg0 + 0x38))));
    *(s32 *)((s8 *)arg0 + 0xDC) = (s32) *(s32 *)((s8 *)(*(u8 * *)&gyaranzo_bml_resource) + 0x430);
    arg0->action_table = gyaranzo_action_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)arg0->action_table);
    init_collision_body_parts(arg0, (void *) lbl_804941F8, 1);
    arg0->variant = 0;
    arg0->movementParameters = (u8 *) lbl_804941DC;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)gyaranzo_boss_stats_handle, (u8 *)gyaranzo_boss_stats_ptr_b, (u8 *)gyaranzo_object_handle);
    init_params_from_table__15TObjEneGyaranzoFv(arg0);
    arg0->requested_action = 0;
    ((TObjMotion *)arg0)->set_animation(arg0->requested_action);
    ((TObjMotion *)arg0)->set_field_b8(arg0->requested_action);
    arg0->hp = (s16) arg0->hpmax;
    arg0->tp = (s16) arg0->tpmax;
    arg0->referenceHp = (s16) arg0->hp;
    temp_r6 = arg0->hp;
    temp_r5 = temp_r6 / 3;
    arg0->m_3b0 = temp_r5;
    arg0->m_38c = 0;
    arg0->m_3a8 = 0;
    arg0->m_3ac = 0;
    arg0->m_3b4 = 0;
    arg0->m_3b8 = 0;
    set_param__9TObjEnemyFl(arg0, 0x19, temp_r5, temp_r6);
    ((TObjChara *)arg0)->add_flags_2e4(4);
    ((TObjEnemy *)arg0)->update_prev_position();
    initialize_enemy_photon_effect(arg0);
    arg0->actorFlags = (s32) (arg0->actorFlags | 0x40000);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&gyaranzo_bml_resource) + 0x42C)) + 0x38);
    arg0->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&gyaranzo_bml_resource) + 0x42C)) + 0x3C);
    if (*(s16 *)((s8 *)arg2 + 0xA) != 0) {
        ((TObjEnemyCustom *)arg0)->sub_800C7860();
    }
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&((Gy_800D3ED8 *) arg0)->e3EC[i]))->activate_and_dispatch();
    }
    ((TObjEneGyaranzo *)(arg0))->clear_lobby_object_state();
    return (u8 *)arg0;
}
}
