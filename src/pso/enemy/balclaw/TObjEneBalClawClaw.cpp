#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/object/TObjControl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResource.h"

#include <stddef.h>
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
// Same layout as DelDepthAnimationBinding: the motion-binding block TLobby::spawn_npc_enemy takes.
struct BalClawClawAnimationBinding {
    void *motions;
    void *actions;
    u32 unknown08;
    u16 actionCount;
    u16 unknown0E;
};

extern void *TObjEneBalClawClaw__collision_body_template[11];
extern BmlResource *lbl_805D4F20;
void spawn_lobby_npc_enemy(void);


#include <stddef.h>
struct VBase_14_0d3ae4 { char pad[0x14]; };

struct VObj_14_0d3ae4 : VBase_14_0d3ae4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
    virtual void m4();
    virtual s32 m5();
};

struct RecoveredFields_8009060C_arg0 {
    u8 unknown_0[0x37C];
    s32 field_37C;
    u8 unknown_380[0x8];
    s32 field_388;
};

struct VBase_800906C8 { char pad[0x14]; };

struct VObj_800906C8 : VBase_800906C8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct Claw_800906C8 {
    u8 pad0[0xB8];
    s16 fieldB8;
    u8 padBA[0x37C - 0xBA];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 flags;
    u8 pad38C[0x390 - 0x38C];
    VObj_800906C8 motion;
};

struct Vec_80090850 { f32 x, y, z; };

struct Params_80090850 { u8 pad0[4]; f32 speed; s32 angle; };

struct Claw_80090850 {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x50 - 0x34];
    Vec_80090850 pos;
    u8 pad5C[0xB8 - 0x5C];
    s16 fieldB8;
    u8 padBA[0x290 - 0xBA];
    Vec_80090850 target;
    Vec_80090850 home;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_80090850 field2FC;
    s32 field308;
    f32 field30C;
    u8 pad310[0x350 - 0x310];
    Params_80090850 *params;
    u8 pad354[0x37C - 0x354];
    s32 state;
};

struct Vec_80090504 { f32 x, y, z; };
extern "C" {

void obj_clearFlags30__8TObjBaseFUl(void *, u32);
void sub_80090798__18TObjEneBalClawClawFv(u8 *arg0);
void obj_setFlags30(void *, u32);
int reset_active_state__18TObjEneBalClawClawFPv(void* p);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
void update_drop__18TObjEneBalClawClawFPv(Claw_800906C8 *self);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
void calc_velocity_toward_destination(void *self, Vec_80090850 pos, Vec_80090850 dest, f32 speed);
void update_move_to_target__18TObjEneBalClawClawFPv(Claw_80090850 *self);
int update_if_active__15TObjEnemyCustomFl(void*, int);
void move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff(void *, Vec_80090504, void *, f32, f32);
s32 update_collisions__10TObjPlayerFv(void *);

typedef char RecoveredFields_8009060C_arg0_37C_offset[offsetof(RecoveredFields_8009060C_arg0, field_37C) == 0x37C ? 1 : -1];
typedef char RecoveredFields_8009060C_arg0_388_offset[offsetof(RecoveredFields_8009060C_arg0, field_388) == 0x388 ? 1 : -1];
}


struct VBaseA_80090950 { char pad[0x18]; };
struct VA_80090950 : VBaseA_80090950 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual s32 m9(f32, f32, f32);
};
struct VBaseB_80090950 { char pad[0x14]; };
struct VB_80090950 : VBaseB_80090950 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
};

struct Vec_80090A70 { f32 x, y, z; };

struct Ent_80090A70 { u8 pad[0x30]; s32 flags; u8 pad34[4]; Vec_80090A70 pos; };

struct Sub_80090A70 { u8 pad[4]; f32 f4; };

struct Obj_80090A70 {
    u8 pad0[0xB8]; s16 fB8;
    u8 padBA[0x350 - 0xBA]; Sub_80090A70 *f350;
    u8 pad354[0x37C - 0x354]; s32 state;
    u8 pad380[0x3C0 - 0x380]; f32 f3C0;
    u8 pad3C4[2]; u16 f3C6;
};
extern "C" {

void TObjEneBalClawClaw__sub_80090A10(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
f32 update_enemy_wander_move(void *, Vec_80090A70 *, s32, Sub_80090A70 *, f32);
void select_enemy_destination(void *, Vec_80090A70 *, s32);
void enemy_turn_half_toward_dest(void *);
void clear_attack_flag__14TObjEneBalClawFv(void *);
u8 *get_enemy_entity(u16 arg0);
void update_follow_parent__18TObjEneBalClawClawFPv(Obj_80090A70 *arg0);
s32 post_translate_matrix(void *);
s32 draw_chunk_object(s32);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 push_matrix();
s32 set_global_param__8TObjFishFl(s32);
s32 defer_render__7TObjectFv(void *);

extern s32 model_render_flags;



void sub_80090D3C__18TObjEneBalClawClawFv(void *arg0);
}




struct VBase_80091134 { char pad[0x14]; };

struct VObj_80091134 : VBase_80091134 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct Claw_80091134 {
    u8 pad0[0x38];
    u8 pos[0xB8 - 0x38];
    s16 fieldB8;
    u8 padBA[0x2FC - 0xBA];
    u8 effects[0x37C - 0x2FC];
    s32 state;
    u8 pad380[0x390 - 0x380];
    VObj_80091134 motion;
};

struct Vec_80091200 { f32 x, y, z; };

struct Claw_80091200 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB4 - 0x34];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2FC - 0xBA];
    Vec_80091200 pos;
    Vec_80091200 vel;
    u8 pad314[0x32C - 0x314];
    s16 f32C;
    u8 pad32E[0x33E - 0x32E];
    s16 f33E;
    u8 pad340[0x37C - 0x340];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
};

struct Vec_80091354 { f32 x, y, z; };

struct Info_80091354 {
    u8 pad0[4];
    f32 f4;
    s32 f8;
};

struct Claw_80091354 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB8 - 0x34];
    s16 fB8;
    u8 padBA[0x29C - 0xBA];
    Vec_80091354 f29C;
    struct Claw_80091354 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_80091354 pos;
    u8 pad308[0x338 - 0x308];
    u16 targetId;
    u8 pad33A[0x350 - 0x33A];
    Info_80091354 *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
};

struct Vec_80090ECC { f32 x, y, z; };

struct Info_80090ECC { u8 pad0[8]; s32 f8; };

struct VBase_80090ECC { char pad[0x18]; };

struct VObj_80090ECC : VBase_80090ECC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual void m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *, f32);
};

struct Claw_80090ECC {
    u8 pad0[0x38];
    u8 f38[0xB4 - 0x38];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2A8 - 0xBA];
    VObj_80090ECC *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_80090ECC pos;
    u8 f308[0x318 - 0x308];
    s32 f318;
    u8 pad31C[0x33C - 0x31C];
    s16 f33C;
    u8 pad33E[0x350 - 0x33E];
    Info_80090ECC *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[0x3C0 - 0x38C];
    f32 f3C0;
};
extern "C" {

void queue_destruction__7TObjectFv(void *);
void TObjPlayer__sub_800A04F0(void *);
void TObjEneBalClawClaw__sub_80091134(Claw_80091134 *self);
s32 check_path_obstructed(void *, void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjEneBalClawClaw__sub_80091200(Claw_80091200 *self);
Claw_80091354 *find_active_entity_by_id(u16);
void update_chase__18TObjEneBalClawClawFPv(Claw_80091354 *self);
void TObjEneBalClawClaw__sub_80090ECC(Claw_80090ECC *self);
struct En0Base_80090DD0 { char pad[0x14]; };
struct En0VObj_80090DD0 : En0Base_80090DD0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

void action__18TObjEneBalClawClawFPv(u8 *arg0);
s32 play_area_se_with_particle__12TBoss3VoloptFv(void *, s32);
s32 TObjPlayer__sub_800A0554(void *);
}

#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/render/RenderFadeState.h"
struct RecoveredGlobal_80091B98_lbl_8048F148 { s32 value; u8 remaining[0x148]; };
struct RecoveredGlobal_80091C58_lbl_8048F148 {
    s32 value;
    u8 remaining[0x148];
};
struct VBase_18_b31a3c { char pad[0x18]; };
struct VObj_18_b31a3c : VBase_18_b31a3c {
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
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual s32 m80();
};
extern "C" {
s32 init_collision_body_parts(void *, void *, int);
extern s32 lbl_805D4F28;
extern s32 lbl_805D4F2C;
extern s32 lbl_805D4F30;
void *find_entity_by_id(u16 id);
s32 submit_cursor_candidate(void *, int, int, f32, f32);
s32 minimap_render_dot(void *, int, int, int);
void free_collision_body_parts(void *);
f32 xz_distance_squared(void *, void *);
void *balclaw_claw_model_node_desc[28] = {
    (void *)0x10000, (void *)0xf, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0xf, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x4,
    (void *)0x20000, (void *)0xb, (void *)0x3f333333, (void *)0x8,
    (void *)0x30000, (void *)0xc, (void *)0x3f000000, (void *)0x10,
    (void *)0x10000, (void *)0xd, (void *)0x3f333333, (void *)0x1,
    (void *)0x10000, (void *)0xe, (void *)0x3f333333, (void *)0x1,
};
void *lbl_8048F100[7] = {
    (void *)0x43160000, (void *)0x3f0e38e3, (void *)0x400, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *TObjEneBalClawClaw__collision_body_template[11] = {
    (void *)0x0, (void *)0x41900000, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};

extern void *tl_04;
}

const char *balclaw_claw_class_name = "TObjEneBalClawClaw";
#define update_collisions__10TObjPlayerFv (*(s32 (*)(void *))&update_collisions__10TObjPlayerFv)
#define update_enemy_wander_move (*(s32 (*)(void *, void *, int, void *, f32))&update_enemy_wander_move)
#define update_if_active__15TObjEnemyCustomFl (*(s32 (*)(void *, int))&update_if_active__15TObjEnemyCustomFl)
#define clear_attack_flag__14TObjEneBalClawFv (*(s32 (*)(void *))&clear_attack_flag__14TObjEneBalClawFv)
#define RESET_80090ECC(p) ((s32 (*)(void *))reset_active_state__18TObjEneBalClawClawFPv)(p)
#define SEEK_80090ECC(p, v, f) ((s32 (*)(void *, void *, int, f32))update_enemy_wander_move)(p, v, 1, f)
#define RESET(p) ((s32 (*)(void *))reset_active_state__18TObjEneBalClawClawFPv)(p)
#define update_drop__18TObjEneBalClawClawFPv (*(s32 (*)(void *))&update_drop__18TObjEneBalClawClawFPv)
#define update_move_to_target__18TObjEneBalClawClawFPv (*(s32 (*)(void *))&update_move_to_target__18TObjEneBalClawClawFPv)
#define update_follow_parent__18TObjEneBalClawClawFPv (*(s32 (*)(void *))&update_follow_parent__18TObjEneBalClawClawFPv)
#define TObjEneBalClawClaw__sub_80090ECC (*(s32 (*)(void *))&TObjEneBalClawClaw__sub_80090ECC)
#define TObjEneBalClawClaw__sub_80091134 (*(s32 (*)(void *))&TObjEneBalClawClaw__sub_80091134)
#define TObjEneBalClawClaw__sub_80091200 (*(s32 (*)(void *))&TObjEneBalClawClaw__sub_80091200)
#define update_chase__18TObjEneBalClawClawFPv (*(s32 (*)(void *))&update_chase__18TObjEneBalClawClawFPv)
#define find_active_entity_by_id (*(s32 (*)(int))&find_active_entity_by_id)

TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, void *set_data) : TObjEneBalClaw(parent) {
    apply_set_data(set_data);
    TObjEneBalClawClaw__ct(this);
    if (*(s16 *)((s8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
}

// Spawned by the body (TObjEneBalClawClaw::create): takes the body's room, group, home and wobble state.
TObjEneBalClawClaw::TObjEneBalClawClaw(TObject *parent, TObjEneBalClaw *body, s32 id, s32 index, Vec *pos,
                                       s32 rot_y, s32)
    : TObjEneBalClaw(parent) {
    entity_id = id;
    set_index = index;
    room = body->room;
    set_group = body->set_group;
    VecCopy(&position, pos);
    VecCopy(&home_position, &body->home_position);
    rotation_z = 0;
    rotation_x = 0;
    rotation_y = rot_y;
    TObjEneBalClawClaw__ct(this);
    set_entry = NULL;
    m_3b8 = body->m_3b8;
    m_3bc = body->m_3bc;
    m_3b4 = body->m_3b4;
    sub_80090798();
}

#pragma push
#pragma opt_common_subs off
#define self ((u8 *)arg0)

s32 TObjEneBalClawClaw__ct(void *arg0) {
    ((TObject *)self)->m_name = balclaw_claw_class_name;
    *(s32 *)((s8 *)self + 0xDC) = (s32)lbl_805D4F20->motions;
    *(u8 **)((s8 *)self + 0xD8) = (u8 *)balclaw_claw_model_node_desc;
    ((TObjMotion *)self)->set_field_d8((s32)(*(u8 **)((s8 *)self + 0xD8)));
    init_collision_body_parts(self, TObjEneBalClawClaw__collision_body_template, 1);
    *(s32 *)((s8 *)self + 0x368) = 0;
    *(u8 **)((s8 *)self + 0x350) = (u8 *)lbl_8048F100;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)lbl_805D4F28, (u8 *)lbl_805D4F2C, (u8 *)lbl_805D4F30);
    ((TObjEneBalClawClaw *)self)->sub_80090824();
    *(s16 *)((s8 *)self + 0xB8) = 0;
    ((TObjMotion *)self)->set_animation(*(s16 *)((s8 *)self + 0xB8));
    ((TObjMotion *)self)->set_field_b8(*(s16 *)((s8 *)self + 0xB8));
    *(s16 *)((s8 *)self + 0x32C) = *(s16 *)((s8 *)self + 0x2B8);
    *(s16 *)((s8 *)self + 0x32E) = *(s16 *)((s8 *)self + 0x2BA);
    *(s16 *)((s8 *)self + 0x33E) = *(s16 *)((s8 *)self + 0x32C);
    ((TObjEnemy *)self)->set_param(0x26);
    VecCopy((Vec *)(self + 0x2FC), (const Vec *)(self + 0x38));
    *(f32 *)((s8 *)self + 0x300) += (5.0f);
    ((TBoss3Volopt *)self)->reset_photon_effect();
    ((TObjEneBalClawClaw *)self)->sub_80090418(2);
    *(s32 *)((s8 *)self + 0x3B8) = 0;
    *(f32 *)((s8 *)self + 0x3BC) = (0.0f);
    *(f32 *)((s8 *)self + 0x3AC) = (15.0f);
    *(f32 *)((s8 *)self + 0x3B0) = (4e+01f);
    *(f32 *)((s8 *)self + 0x3B4) = *(f32 *)((s8 *)self + 0x3AC);
    clear_attack_flag__14TObjEneBalClawFv(self);
    VecCopy((Vec *)(self + 0x290), (const Vec *)((void *)VecCopy((Vec *)(self + 0x29C), (const Vec *)(self + 0x38))));
    return ((VObj_18_b31a3c *)self)->m80();
}
#undef self
#pragma pop

TObjEneBalClawClaw::~TObjEneBalClawClaw() {
    free_collision_body_parts(this);
}

void *TObjEneBalClawClaw::create() {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawClaw(control, this);
}

void *TObjEneBalClawClaw::create(void *arg1, void *arg2, void *arg3, void *arg4, void *arg5) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawClaw(control, this, (s32)arg1, (s32)arg2, (Vec *)arg3, (s32)arg4, (s32)arg5);
}

void TObjEneBalClawClaw::run_task() {
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f1;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 entity;
    u8 *temp_r5;
    u8 *arg0 = (u8 *)this;
    TObjEneBalClaw__sub_8008D68C();
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80090824();
        sub_800914A4();
        return;
    }
    temp_r3 = *(s32 *)&this->m_388;
    if (temp_r3 & 0x20000000) {
        update_if_active__15TObjEnemyCustomFl(arg0, 0xA);
    } else if (temp_r3 & 0x10000000) {
        update_if_active__15TObjEnemyCustomFl(arg0, 9);
    } else {
        ((TObjEneBalClawClaw *)arg0)->update_attack_distance_state();
    }
    if ((s16) this->mode != (s32) *(s32 *)&this->next_action) {
        if ((s32) *(s32 *)&this->state != -1) {
            *(s32 *)&this->state = -1;
            ((TObjEneBalClawClaw *)arg0)->update_state();
        }
        this->mode = (s16) *(s32 *)&this->next_action;
        *(s32 *)&this->state = 0;
    }
    *(s32 *)((s8 *)arg0 + 0x2A8) = find_active_entity_by_id(this->targetId);
    ((TObjEnemyCustom *)arg0)->release_destroyed_target();
    ((TObjEneBalClawClaw *)arg0)->update_state();
    temp_r3_2 = *(s32 *)&this->m_388;
    if (!(temp_r3_2 & 0x10000000)) {
        if (temp_r3_2 & 0x20000000) {
            *(f32 *)((s8 *)arg0 + 0x3BC) = (0.2f + *(f32 *)((s8 *)arg0 + 0x3BC) < 10.0f) ? 0.2f + *(f32 *)((s8 *)arg0 + 0x3BC) : 10.0f;
        } else {
            ((TObjEneBalClaw *)arg0)->update_wobble();
        }
        ((TObjEneBalClaw *)arg0)->update_claw_angle();
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
        temp_f2 = this->m_300;
        this->m_300 = (f32) (temp_f2 + (this->m_3b4 + *(f32 *)((s8 *)arg0 + 0x3BC)));
        temp_f1 = this->m_3b4;
        temp_r5 = (unsigned char *) (this->bodies);
        *(f32 *)((s8 *)temp_r5 + 4) = (f32) (temp_f1 + *(f32 *)((s8 *)arg0 + 0x3BC));
        submit_cursor_candidate((void *)arg0, -1, (int)temp_r5, (f32)temp_f1, (f32)temp_f2);
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
        return;
    }
    entity = (s32)find_entity_by_id((*(u16 *)&this->m_3c6));
    if (entity != 0) {
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(entity + 0x38));
    }
}

void TObjEneBalClawClaw::update_state() {
    u8 *arg0 = (u8 *)this;
  s16 temp_r0;
  void *new_var;
  void *new_var2;
  new_var = (void *) arg0;
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        new_var2 = new_var;
        sub_80090D3C__18TObjEneBalClawClawFv(new_var2);
        return;
      case 1:
        update_chase__18TObjEneBalClawClawFPv(new_var);
        return;
      case 2:
        TObjEneBalClawClaw__sub_80090ECC(new_var);
        return;
      case 4:
        TObjEneBalClawClaw__sub_80091200(new_var);
        return;
      case 5:
        TObjEneBalClawClaw__sub_80091134(new_var);
        return;
      case 7:
        new_var = arg0;
        action__18TObjEneBalClawClawFPv((u8 *)new_var);
        return;
      case 9:
        update_drop__18TObjEneBalClawClawFPv(new_var = new_var);
        return;
      case 10:
        update_follow_parent__18TObjEneBalClawClawFPv(new_var);
        return;
      case 11:
        ((TObjEneBalClawClaw *)new_var)->run_active_state();
        return;
      case 8:
        update_move_to_target__18TObjEneBalClawClawFPv(new_var);
        return;
      case 12:
        ((TObjEneBalClawClaw *)new_var)->update_chase_state();
        break;
    }
  }
}

void TObjEneBalClawClaw::update_attack_distance_state() {
    f32 temp_f1;
    s32 temp_r0_2;
    s32 temp_r31;
    u32 temp_r3;

    if (this->is_actor_cadence_frame(0x1E) != 0) {
        find_target_in_range((f32) ((2.5e+02f)));
    }
    switch (this->mode) {
    case 8:
    case 0:
        if (this->is_actor_cadence_frame(0x1E) != 0) {
            if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x2A8) != 0U) {
                update_if_active__15TObjEnemyCustomFl(this, 1);
                *(s32 *)((s8 *)((u8 *)this) + 0x38C) = 2;
                return;
            }
            if (xz_distance_squared((void *) (((u8 *)this) + 0x38), (void *) (((u8 *)this) + 0x50)) > (1e+02f)) {
                update_if_active__15TObjEnemyCustomFl(this, 8);
                return;
            }
            reset_active_state__18TObjEneBalClawClawFPv(this);
        }
        return;
    case 1:
        temp_r3 = *(u32 *)((s8 *)((u8 *)this) + 0x2A8);
        if (temp_r3 != 0U) {
            temp_f1 = xz_distance_squared((void *)(temp_r3 + 0x38), (void *) (((u8 *)this) + 0x38));
            temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0x38C);
            switch (temp_r31) {
            case 0:
                if (temp_f1 > (1.6e+03f)) {
                    *(s32 *)((s8 *)((u8 *)this) + 0x38C) = 1;
                }
                break;
            case 1:
                if (temp_f1 < (4e+02f)) {
                    clear_attack_flag__14TObjEneBalClawFv(this);
                    *(s32 *)((s8 *)((u8 *)this) + 0x38C) = 0;
                } else if (temp_f1 > (1e+04f)) {
                    *(s32 *)((s8 *)((u8 *)this) + 0x38C) = 2;
                }
                break;
            case 2:
                if (temp_f1 < (6.4e+03f)) {
                    this->set_attack_distance_flag();
                    *(s32 *)((s8 *)((u8 *)this) + 0x38C) = 1;
                }
                break;
            }
            temp_r0_2 = *(s32 *)((s8 *)((u8 *)this) + 0x38C);
            if (temp_r31 != temp_r0_2) {
                switch (temp_r0_2) {
                case 0:
                    update_if_active__15TObjEnemyCustomFl(this, 2);
                    return;
                case 1:
                    clear_attack_flag__14TObjEneBalClawFv(this);
                    return;
                case 2:
                    this->set_attack_distance_flag();
                    return;
                }
            }
        } else {
            update_if_active__15TObjEnemyCustomFl(this, 8);
        }
        break;
    }
}
#undef update_drop__18TObjEneBalClawClawFPv
#undef update_move_to_target__18TObjEneBalClawClawFPv
#undef update_follow_parent__18TObjEneBalClawClawFPv
#undef TObjEneBalClawClaw__sub_80090ECC
#undef TObjEneBalClawClaw__sub_80091134
#undef TObjEneBalClawClaw__sub_80091200
#undef update_chase__18TObjEneBalClawClawFPv
#undef find_active_entity_by_id
#define reset_active_state__18TObjEneBalClawClawFPv (*(s32 (*)(void *, s32, s32))&reset_active_state__18TObjEneBalClawClawFPv)

void TObjEneBalClawClaw::sub_800914A4() {  }

void update_chase__18TObjEneBalClawClawFPv(Claw_80091354 *self) {
    switch (self->state) {
    case 0:
        ((TObjEnemyCustom *)self)->find_target_in_range((2.5e+02f));
        if (self->targetId != 0xFFFF) {
            self->f30 &= 0xFBFFFEFF;
            ((TObjEnemyCustom *)self)->sub_8004292C();
            self->state = self->fB8 = 1;
        } else {
            RESET(self);
        }
        self->target = find_active_entity_by_id(self->targetId);
        if (self->target != NULL) {
            VecCopy((Vec *)&self->f29C, (const Vec *)&self->target->pos);
        }
        break;
    case 1: {
        if (self->target == NULL) {
            RESET(self);
            break;
        }
        play_persistent_sound(0x4003B235, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
        Vec_80091354 v = self->target->pos;
        update_enemy_wander_move(self, &v, 1, self->info, self->info->f4);
        ((TObjEnemy *)self)->turn_toward_direction(self->info->f8, (Vec *)((u8 *)self + 0x308));
        ((TObjMotion *)self)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), (0.0f));
        update_collisions__10TObjPlayerFv(self);
        break;
    }
    case -1:
        break;
    }
}
#undef RESET

void TObjEneBalClawClaw__sub_80091200(Claw_80091200 *self) {
    switch (self->state) {
    case 0:
        self->f30 &= ~0x200000;
        self->fB8 = 3;
        self->state = 1;
    case 1: {
        ((TObjMotion *)self)->advance_animation();
        Vec_80091200 v = self->pos;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        } else {
            self->vel.x = self->vel.z = (0.0f);
        }
        self->vel.x *= (0.9f);
        self->vel.z *= (0.9f);
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), (0.0f));
        update_collisions__10TObjPlayerFv(self);
        play_persistent_sound(0x4003B235, (s32)self, (u32)((u8 *)self + 0x38), 0, 0);
        if (self->fB4 != 8) {
            self->f30 &= ~0x200;
            self->f388 &= ~1;
            self->f33E = self->f32C;
            ((s32 (*)(void *))reset_active_state__18TObjEneBalClawClawFPv)(self);
        }
        break;
    }
    case -1:
        break;
    }
}

void TObjEneBalClawClaw__sub_80091134(Claw_80091134 *self) {
    switch (self->state) {
    case 0:
        ((TObjPlayer *)self)->refresh_lobby_state();
        self->fieldB8 = 4;
        TObjPlayer__sub_800A04F0(&self->motion);
        fn_800D911C((Vec *)(self->effects));
        play_sound_effect(0x4003AD37, self->pos, 0, 0);
        self->state = 1;
    case 1:
        (((TObjMotion *)self)->advance_animation());
        if (self->motion.m4() == 1) {
            TObjPlayer::apply_effect_variant_a((s32)self->pos, 0);
            ((TObjEnemy *)self)->send_entity_set_flags();
            queue_destruction__7TObjectFv(self);
        }
        break;
    case -1:
        return;
    }
}

void TObjEneBalClawClaw__sub_80090ECC(Claw_80090ECC *self) {
    switch (self->state) {
    case -1:
        break;
    case 0:
        if (self->target == NULL) {
            RESET_80090ECC(self);
            return;
        }
        clear_attack_flag__14TObjEneBalClawFv(self);
        self->f388 &= ~8;
        self->state = self->fB8 = 1;
        break;
    case 1: {
        if (self->target == NULL) {
            RESET_80090ECC(self);
            return;
        }
        Vec_80090ECC v = ((Claw_80090ECC *)self->target)->pos;
        SEEK_80090ECC(self, &v, (0.7f));
        ((TObjEnemy *)self)->turn_toward_direction(self->info->f8, (Vec *)self->f308);
        if (self->f3C0 <= ((AttackParams *)(self->f318))->get_attack_range() * ((AttackParams *)(self->f318))->get_attack_range()) {
            self->state = self->fB8 = 2;
        }
        break;
    }
    case 2: {
        if (self->target == NULL) {
            RESET_80090ECC(self);
            return;
        }
        Vec_80090ECC v = ((Claw_80090ECC *)self->target)->pos;
        SEEK_80090ECC(self, &v, (0.7f));
        ((TObjEnemy *)self)->turn_toward_direction(self->info->f8, (Vec *)self->f308);
        if (((TObjMotion *)self)->is_passing_frame((f32)(8.0f)) != 0) {
            play_sound_effect(0x4003B032, self->f38, 0, 0);
            if (self->target->m18(self, (1.0f)) != 0) {
                self->target->m23(self, (3.0f));
                self->target->m20(self, (1.0f));
                self->f388 |= 8;
            }
        }
        if (self->fB4 != 4) {
            self->f33C = 0x5A;
            update_if_active__15TObjEnemyCustomFl(self, 0xC);
        }
        break;
    }
    case 3:
        self->f33C = self->f33C - 1;
        if (self->f33C <= 0) {
            RESET_80090ECC(self);
        }
        break;
    }
    ((TObjMotion *)self)->advance_animation();
    apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), (0.0f));
    update_collisions__10TObjPlayerFv(self);
}
#undef RESET_80090ECC
#undef SEEK_80090ECC

void action__18TObjEneBalClawClawFPv(u8 *ene_bal_claw_claw) {
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r5;

    switch (((TObjEneBalClawClaw *)ene_bal_claw_claw)->state) {
    case 0:
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388 = (s32) (((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388 | 4);
        temp_r4 = ((TObjEneBalClawClaw *)ene_bal_claw_claw)->actorFlags | 0x04000000;
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->actorFlags = temp_r4;
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->requested_action = 0;
        play_area_se_with_particle__12TBoss3VoloptFv(ene_bal_claw_claw + 0x38, temp_r4);
        TObjPlayer__sub_800A0554(ene_bal_claw_claw + 0x390);
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->state = 1;
    case 1:
        ((TObjMotion *)ene_bal_claw_claw)->advance_animation();
        apply_actor_gravity((TObjEnemy *)ene_bal_claw_claw, (s32 *)(0), (0.0f));
        if (((En0VObj_80090DD0*)(ene_bal_claw_claw + 0x390))->m5() == 1) {
            temp_r5 = ((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388;
            temp_r4_2 = temp_r5 & ~5;
            ((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388 = temp_r4_2;
            ((TObjEneBalClawClaw *)ene_bal_claw_claw)->state = -1;
            reset_active_state__18TObjEneBalClawClawFPv(ene_bal_claw_claw, temp_r4_2, temp_r5);
        }
        return;
    case -1:
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388 = (s32) (((TObjEneBalClawClaw *)ene_bal_claw_claw)->m_388 & ~5);
        ((TObjEneBalClawClaw *)ene_bal_claw_claw)->actorFlags = (s32) (((TObjEneBalClawClaw *)ene_bal_claw_claw)->actorFlags & 0xFBFFFFFF);
        break;
    }
}
#undef update_collisions__10TObjPlayerFv
#undef update_enemy_wander_move
#undef update_if_active__15TObjEnemyCustomFl
#undef clear_attack_flag__14TObjEneBalClawFv
#undef reset_active_state__18TObjEneBalClawClawFPv

void TObjEneBalClawClaw::sub_80090D3C() {

    switch (this->state) {
    case 0:
        this->actorFlags = (s32) (this->actorFlags | 0x40000);
        this->requested_action = 0;
        this->state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), (0.0f));
        return;
    case -1:
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        return;
    }
}
#define sub_80090798__18TObjEneBalClawClawFv (*(void (*)(void *))&sub_80090798__18TObjEneBalClawClawFv)
#define update_if_active__15TObjEnemyCustomFl (*(s32 (*)(void *, int))&update_if_active__15TObjEnemyCustomFl)
#define reset_active_state__18TObjEneBalClawClawFPv (*(s32 (*)())&reset_active_state__18TObjEneBalClawClawFPv)

void TObjEneBalClawClaw::render() {
    s32 var_r30;
    s32 temp_r3;
    s32 var_r29;
    u8 *arg0 = (u8 *)this;

    if (!(this->actorFlags & 0x02000000)) {
        temp_r3 = ((VA_80090950 *)arg0)->m9((1.2e+02f), (4e+02f), (1e+01f));
        if (temp_r3 != 0) {
            var_r30 = 1;
            set_global_param__8TObjFishFl(this->texlist);
            select_actor_lighting(arg0);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, this->rotation_y);
                draw_chunk_object(*(s32 *)((s8 *)arg0 + 0x34));
            } else {
                translate_matrix(0, (0.0f), this->m_3b4 + *(f32 *)((s8 *)arg0 + 0x3BC), (0.0f));
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, this->rotation_y);
                if (this->m_388 & 4) {
                    if (((VB_80090950 *)(arg0 + 0x390))->m8() != 0) {
                        ((VB_80090950 *)(arg0 + 0x390))->m6();
                        var_r29 = 1;
                        if (defer_render__7TObjectFv(arg0) != 0) {
                            var_r29 = 0;
                        }
                        if (var_r29 != 0) {
                            if (temp_r3 == 1) {
                                ((TObjMotion *)arg0)->draw();
                            } else {
                                ((TObjEnemy *)arg0)->draw_motion_model();
                            }
                        }
                        ((VB_80090950 *)(arg0 + 0x390))->m7();
                    } else {
                        var_r30 = 0;
                    }
                } else if (temp_r3 == 1) {
                    ((TObjMotion *)arg0)->draw();
                } else {
                    ((TObjEnemy *)arg0)->draw_motion_model();
                }
            }
            pop_matrix();
            restore_scene_lighting();
            TParticleCtrl::end_effect_render();
            ((TObjEneBalClaw *)arg0)->render_scaled(var_r30);
        }
    }
}

void update_follow_parent__18TObjEneBalClawClawFPv(Obj_80090A70 *arg0) {
    Ent_80090A70 *e = (Ent_80090A70 *)get_enemy_entity(arg0->f3C6);
    if (e == NULL || (e->flags & 0x800)) {
        ((TObjEneBalClawClaw *)arg0)->clear_flag();
        return;
    }
    switch (arg0->state) {
    case -1:
        break;
    case 0:
        arg0->fB8 = 1;
        clear_attack_flag__14TObjEneBalClawFv(arg0);
        arg0->state = 1;
    case 1: {
        Vec_80090A70 a = e->pos;
        select_enemy_destination(arg0, &a, 1);
        Vec_80090A70 b = e->pos;
        arg0->f3C0 = update_enemy_wander_move(arg0, &b, 1, arg0->f350, arg0->f350->f4);
        enemy_turn_half_toward_dest(arg0);
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0), (s32 *)(0), (0.0f));
        ((TObjPlayer *)arg0)->check_object_collisions();
        break;
    }
    }
}

void TObjEneBalClawClaw__sub_80090A10(u8 *ene_bal_claw_claw, u8 *arg1, s32 arg2, s16 arg3) {
    VecCopy((Vec *)(ene_bal_claw_claw + 0x38), (const Vec *)arg1);
    ((TObjEneBalClawClaw *)ene_bal_claw_claw)->rotation_y = arg2;
    ((TObjEneBalClawClaw *)ene_bal_claw_claw)->referenceHp = arg3;
    ((TObjEneBalClawClaw *)ene_bal_claw_claw)->hp = arg3;
    sub_80090798__18TObjEneBalClawClawFv(ene_bal_claw_claw);
    ((TObjEneBalClawClaw *)(ene_bal_claw_claw))->clear_all_status_effects();
}

s32 TObjEneBalClawClaw::check_active() {
    if (this->actorFlags & 0xA00) {
        return 0;
    }
    return (u32) __cntlzw(this->m_388 & 0x10000000) >> 5;
}

void TObjEneBalClawClaw::enter_hit_state(s16 arg1) {
    this->m_3c6 = arg1;
    this->targetId = arg1;
    this->m_388 = (s32) (this->m_388 | 0x20000000);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    *(f32 *)((s8 *)((u8 *)this) + 0x3C0) = (f32) (1e+05f);
    update_if_active__15TObjEnemyCustomFl(this, 0xA);
    this->clear_all_status_effects();
}

void TObjEneBalClawClaw::clear_flag() {
    this->m_388 = (s32) (this->m_388 & 0xDFFFFFFF);
    reset_active_state__18TObjEneBalClawClawFPv();
}
#undef sub_80090798__18TObjEneBalClawClawFv
#undef update_if_active__15TObjEnemyCustomFl
#undef reset_active_state__18TObjEneBalClawClawFPv

void update_move_to_target__18TObjEneBalClawClawFPv(Claw_80090850 *self) {
    switch (self->state) {
    case -1:
        break;
    case 0:
        self->flags30 &= ~0x100;
        self->fieldB8 = 1;
        VecCopy((Vec *)&self->home, (const Vec *)&self->pos);
        self->state = 1;
    case 1:
        self->field30C = (0.0f);
        VecCopy((Vec *)&self->target, (const Vec *)&self->field2FC);
        calc_velocity_toward_destination(self, self->target, self->home, self->params->speed);
        ((TObjEnemy *)self)->turn_toward_direction(self->params->angle, (Vec *)&self->field308);
        move_with_wall_slide((u8 *)self);
        ((TObjMotion *)self)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), (0.0f));
        break;
    }
}

int reset_active_state__18TObjEneBalClawClawFPv(void* p) { return update_if_active__15TObjEnemyCustomFl(p, 0); }

void TObjEneBalClawClaw::vfunc_58() {  }

void TObjEneBalClawClaw::sub_80090824() {  }

void TObjEneBalClawClaw::set_claw_flags() {
    obj_setFlags30(this, 0x04040000U);
    this->m_388 = (s32) (this->m_388 & 0xDFFFFFFF);
    this->m_388 = (s32) (this->m_388 | 0x10000000);
}

void TObjEneBalClawClaw::sub_80090798() {
    this->m_388 = (s32) (this->m_388 & 0xEFFFFFFF);
    obj_clearFlags30__8TObjBaseFUl(this, 0x06040000U);
    this->next_action = 0xB;
}

void update_drop__18TObjEneBalClawClawFPv(Claw_800906C8 *self) {
    switch (self->state) {
    case -1:
        break;
    case 0:
        self->fieldB8 = 0;
        self->motion.m2();
        self->flags |= 4;
        self->state = 1;
    case 1:
        ((TObjMotion *)self)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), (0.0f));
        if (self->motion.m4() == 1) {
            self->flags &= ~4;
            obj_setFlags30(self, 0x02000000);
            self->state = 2;
        }
        break;
    case 2:
        break;
    }
}

void TObjEneBalClawClaw::run_active_state() {
    switch (((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_37C) {
    case 0:
        ((VObj_14_0d3ae4 *)(((u8 *)this) + (912)))->m3();
        ((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 = (s32) (((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 | 5);
        ((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_37C = 1;
    case 1:
        if (((VObj_14_0d3ae4 *)(((u8 *)this) + (912)))->m5() == 1) {
            ((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 = (s32) (((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 & ~5);
            reset_active_state__18TObjEneBalClawClawFPv(this);
        }
        return;
    case -1:
        ((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 = (s32) (((RecoveredFields_8009060C_arg0 *)((u8 *)this))->field_388 & 0xFFFFFFFB);
        break;
    }
}

void TObjEneBalClawClaw::update_chase_state() {
    u8 *temp_r5;
    switch (this->state) {
    case -1:
        break;
    case 0:
        this->actorFlags &= ~0x100;
        this->requested_action = 1;
        this->state = 1;
        *(s16 *)((s8 *)((u8 *)this) + 0x3C8) = 0x78;
        break;
    case 1:
        if (this->target == NULL || --*(s16 *)((s8 *)((u8 *)this) + 0x3C8) <= 0) {
            update_if_active__15TObjEnemyCustomFl(this, 0);
            break;
        }
        *(f32 *)((s8 *)((u8 *)this) + 0x30C) = (0.0f);
        move_along_ground_avoiding_walls__15TObjEnemyCustomF3Vecff(this, *(Vec_80090504 *)((s8 *)this->target + 0x2FC), this->bodies, (-0.6f), *(f32 *)((s8 *)this->bodies + 0xC));
        turn_toward_direction(*(s32 *)((s8 *)this->movementParameters + 8), (Vec *)unk_308);
        advance_animation();
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), (0.0f));
        update_collisions__10TObjPlayerFv(this);
        break;
    }
}

void spawn_lobby_npc_enemy(void) {
    BalClawClawAnimationBinding binding = {lbl_805D4F20->motions, balclaw_claw_model_node_desc, 1, 7, 0};
    BmlModelEntry *models;
    models = lbl_805D4F20->models;
    TLobby::spawn_npc_enemy(0x14, models[2].model, (NJS_TEXLIST *)models[2].m_c, &binding,
                            *(f32 *)((u8 *)TObjEneBalClawClaw__collision_body_template + 0xC), 15.0f);
}
