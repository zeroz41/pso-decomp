#include "types.h"
#include <stddef.h>
#include "pso/enemy/balclaw/TObjEneBalClawBody.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/object/TObjControl.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"

// TObjEneBalClawBody, the Bal Claw's body (the "TObjEneBalClawBody" class name).
// One TU from 0x8008DC18 to 0x80090448: the .sdata2 pool 0x805D9618-0x805D9688 is shared by all of it.

static const char balclaw_body_class_name_text[] = "TObjEneBalClawBody";

// The body's actions (TObjMotion::action_table, installed by the ctor).
TObjMotionAction balclaw_body_actions[12] = {
    {1, 0, 9, 0.8f, 0},
    {1, 1, 9, 0.8f, 1},
    {2, 0, 6, 0.5f, 4},
    {2, 0, 7, 0.6f, 8},
    {3, 4, 8, 0.5f, 0x10},
    {1, 5, 5, 0.8f, 0},
    {1, 5, 5, 0.8f, 1},
    {2, 5, 0, 0.6f, 4},
    {2, 5, 2, 0.7f, 8},
    {3, 5, 3, 0.6f, 0x10},
    {2, 5, 4, 0.5f, 1},
    {2, 5, 1, 0.6f, 1},
};

// Movement rows; TObjPlayer__sub_8008E934 points TObjEnemy::movementParameters at one.
struct BalClawBodyMovement {
    EnemyMoveParams move;
    s32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
};
BalClawBodyMovement player_attack_param_table[2] = {
    {{150.0f, 0.5555555f, 0x400}, 0x1E0000, 0, 1, 0},
    {{150.0f, 0.5555555f, 0x400}, 0x1E0000, 0, 1, 0},
};

// The body's one collision sphere (init_collision_body_parts in the ctor).
CollisionBody balclaw_body_collision = {{0.0f, 18.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

u8 *lbl_805007A8[2];
u8 *lbl_805007B0[2];
u8 *lbl_805007B8[2];
u8 *lbl_805007C0[2];
const char *balclaw_body_class_name = balclaw_body_class_name_text;

extern BmlResource *lbl_805D4F20;
extern void *tl_04;

// ---- views used by the moved state handlers ----

struct Obj_8008E098 {
    u8 pad0[0x1C];
    u16 field1C;
    u8 pad1E[0x28 - 0x1E];
    s16 field28;
    u8 pad2A[0x3C4 - 0x2A];
    s32 ids[5];
    s16 count;
};


struct Obj_8008E18C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 field60;
};


struct Info_8008DD14 { u8 pad0[4]; f32 f4; s32 f8; };

struct Obj_8008DD14 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec pos38;
    u8 pad44[0x50 - 0x44];
    Vec home;
    u8 pad5C[0xB8 - 0x5C];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec f290;
    Vec f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec pos;
    Vec vel;
    u8 pad314[0x350 - 0x314];
    Info_8008DD14 *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
};

struct Obj_8008DE9C {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xB8 - 0x34];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec f290;
    Vec f29C;
    Obj_8008DE9C *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec pos;
    Vec vel;
    u8 pad314[0x350 - 0x314];
    Info_8008DD14 *info;
    u8 pad354[0x37C - 0x354];
    s32 state;
};

struct Obj_8008E098;
struct P_8008E310 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x2FC - 0xC4];
    u8 f2FC[0x32C - 0x2FC];
    s16 f32C;
    u8 pad32E[0x33C - 0x32E];
    s16 f33C;
    u8 pad33E[0x37C - 0x33E];
    s32 state;
    u8 pad380[4];
    s32 timer;
    u32 flags;
    u8 pad38C[0x3C4 - 0x38C];
    s32 ids[4];
    s32 f3D4;
    s16 count;
    u8 pad3DA[2];
    u32 emit1;
    u32 emit2;
};

struct E_8008E310 { u8 pad[0x3C0]; f32 f3C0; };

struct Obj_8008E18C;
struct VBase_18_4841bb { char pad[0x18]; };

struct VObj_18_4841bb : VBase_18_4841bb {
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
    virtual s32 m53();
};

struct Self_8008E934 { u8 pad[0x3C4]; s32 ids[4]; };

extern "C" {
int update_if_active__15TObjEnemyCustomFl(void*, int);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
void enter_hit_state__18TObjEneBalClawClawFs(void *, u16);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
s32 TObjPlayer__sub_8008E098(Obj_8008E098 *self);
void vec3_add_to(Vec *, Vec *);
s32 push_matrix();
void calc_slot_offset_position__10TObjPlayerFPviPvPv(Obj_8008E18C *self, s32 slot, Vec *out, s32 *angle_out);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 check_path_obstructed(void *, void *);
f32 xz_distance_squared(void *, void *);
void TObjPlayer__sub_8008DD14(Obj_8008DD14 *self);
s16 get_actor_hp(u8 *p);
void queue_destruction__7TObjectFv(void *arg0);
void TObjPlayer__sub_8008E310(P_8008E310 *arg0);
void TObjPlayer__sub_8008E254(void *arg0);
void TObjEneBalClawClaw__sub_80090A10(u8 *arg0, u8 *arg1, s32 arg2, s16 arg3);
void *create__18TObjEneBalClawClawFPvPvPvPvPv(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);
u8 *get_enemy_entity(u16);
void TObjPlayer__sub_8008E934(void *arg0_, s32 arg1);
struct VBase18_8008e74c_8008DCF0 { char pad[0x18]; };
struct VObj18_8008e74c_8008DCF0 : VBase18_8008e74c_8008DCF0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual s32 m9(f32, f32, f32);
};
struct VObj390_8008e74c_8008DCF0 { char pad[0x14]; };
struct VObj390V_8008e74c_8008DCF0 : VObj390_8008e74c_8008DCF0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6();
    virtual void m7(); virtual s32 m8();
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_x(s32, s32);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 defer_render__7TObjectFv(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}


struct Row_8008ED48 { u32 *p[11]; };


struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct P_8008F730 { u8 pad[0x3C4]; s32 ids[5]; s16 n; };


struct P_8008EDE8;

struct Pair_8008EDE8 { s32 a, b; };

struct TB_8008EDE8 { u8 pad0[0x18]; };

struct T_8008EDE8 : TB_8008EDE8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(P_8008EDE8 *, f32);
    virtual void m19();
    virtual void m20(P_8008EDE8 *, f32);
    virtual void m21(P_8008EDE8 *, Pair_8008EDE8 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(P_8008EDE8 *, f32);
    u8 pad1C[0x2FC - 0x1C];
    Vec pos;
};

struct H_8008EDE8 { u8 pad[8]; void *f8; };

struct P_8008EDE8 {
    u8 pad0[0x38];
    f32 pos38[3];
    u8 pad44[0xB4 - 0x44];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x2A8 - 0xBA];
    T_8008EDE8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec pos;
    Vec vel;
    u8 pad314[0x318 - 0x314];
    s32 f318;
    u8 pad31C[0x338 - 0x31C];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    H_8008EDE8 *f350;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x3C0 - 0x380];
    f32 f3C0;
    u8 pad3C4[0x3DA - 0x3C4];
    s16 f3DA;
};

struct P_8008F1DC;
#define FLD(T, off) (*(T *)((u8 *)o + (off)))
struct TB_8008F1DC { u8 pad0[0x18]; };

struct T_8008F1DC : TB_8008F1DC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(P_8008F1DC *, f32);
    virtual void m19();
    virtual void m20(P_8008F1DC *, f32);
    virtual void m21();
    virtual void m22();
    virtual void m23(P_8008F1DC *, f32);
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
    u8 pad1C[0x30 - 0x1C];
    u32 flags30;
    u8 pad34[0x2FC - 0x34];
    Vec pos;
};

struct H_8008F1DC { u8 pad[8]; void *f8; };

struct P_8008F1DC : T_8008F1DC {
 Vec vel;
    u8 pad314[0x318 - 0x314];
    s32 f318;
    u8 pad31C[0x338 - 0x31C];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    H_8008F1DC *f350;
    u8 pad354[0x37C - 0x354];
    s32 state;
    u8 pad380[0x388 - 0x380];
    u32 f388;
    u8 pad38C[0x3C0 - 0x38C];
    f32 f3C0;
    u8 pad3C4[0x3E4 - 0x3C4];
    u32 p3E4;
    u32 p3E8;
    u8 f3EC[0xC];
    s32 f3F8;
    s32 f3FC;
    s32 f400;
};

struct En0Base { char pad[0x14]; };

struct En0VObj : En0Base {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};


extern Row_8008ED48 lbl_805006F8[];
extern "C" {
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 check_path_obstructed(void *, void *);
s32 fn_80090464(void *, int);
void TObjPlayer__sub_8008F910(u8 *arg0);
void queue_destruction__7TObjectFv(void *arg0);
s32 TObjPlayer__sub_800A04F0(void *);
s32 update_enemy_wander_move(void *, Vec *, int, f32);
s32 reset_enemy_state__10TObjPlayerFv();
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_8008FAD0(u8 *arg0);
f32 random_ratio__9TObjCharaFv(s32 arg0);
void calc_velocity_toward_destination(void *, Vec, Vec, f32);
s32 select_enemy_destination(void *, Vec, s32);
void copy_position_if_valid__10TObjPlayerFii(void *, Vec);
f32 xz_distance_squared(void *, void *);
void TObjPlayer__sub_8008EDE8(P_8008EDE8 *arg0);
s32 obj_setFlags30(void *, int);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
T_8008F1DC *find_active_entity_by_id(u16);
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
s32 post_translate_matrix(void *);
extern u8 identity_matrix[];
void TObjPlayer__sub_8008F1DC(void *arg0);
s32 TObjPlayer__sub_800A0554(void *);
void TObjPlayer__sub_8008EC3C(u8 *arg0);
}

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
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
    virtual s32 m17(s32);
};

extern "C" {
f32 xz_distance_squared(void *, void *);
s32 submit_cursor_candidate(void *, int, int, f32, f32);
s32 minimap_render_dot(void *, int, int, int);
}

// (no extra declarations)
// Picks the claw's model and texture list from the Bal Claw BML.
void TObjEneBalClawClaw::sub_80090418(s32 i) {
    model = (void *)lbl_805D4F20->models[i].model;
    texlist = lbl_805D4F20->models[i].m_c;
}

TObjEneBalClawBody::TObjEneBalClawBody(TObject *parent, void *set_data) : TObjEneBalClaw(parent) {
    s32 i;
    m_name = balclaw_body_class_name;
    apply_set_data(set_data);
    VecCopy((Vec *)(&m_290), (const Vec *)(VecCopy((Vec *)(&m_29c), (const Vec *)(&position))));
    motion_list = lbl_805D4F20->motions;
    action_table = balclaw_body_actions;
    set_field_d8((s32)(action_table));
    init_collision_body_parts(this, &balclaw_body_collision, 1);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    update_prev_position();
    initialize_enemy_photon_effect(this);
    m_3b8 = 0;
    m_3bc = 0.0f;
    clear_attack_flag();
    if (*(s16 *)((s8 *)set_data + 0xA) != 0) {
        sub_800C7860();
    }
    m_3ac = 25.0f;
    m_3b0 = 40.0f;
    m_3b4 = m_3ac;
    m_3d8 = 4;
    for (i = 0; i < 4; i++) {
        child_ids[i] = 0xFFFF;
    }
    TObjPlayer__sub_8008E934(this, 1);
    bind_enemy_combat_stats(lbl_805007A8[0], lbl_805007B0[0], lbl_805007B8[0]);
    parts[0] = NULL;
    parts[1] = NULL;
    parts[2] = NULL;
    parts[3] = NULL;
    clear_lobby_object_state();
}

TObjEneBalClawBody::~TObjEneBalClawBody() {
    s32 i;
    TObject *child;
    free_collision_body_parts(this);
    if (parts[0] != NULL) {
        parts[0]->queue_destruction();
    }
    if (parts[1] != NULL) {
        parts[1]->queue_destruction();
    }
    if (parts[2] != NULL) {
        parts[2]->queue_destruction();
    }
    if (parts[3] != NULL) {
        parts[3]->queue_destruction();
    }
    if (get_flag_0x388_b24() != 0) {
        for (i = 0; i < m_3d8; i++) {
            child = find_entity_by_id(child_ids[i]);
            if (child != NULL) {
                child->queue_destruction();
            }
        }
    }
}

void *TObjEneBalClawBody::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneBalClawBody(control, set_data);
}

void TObjEneBalClawBody::run_task() {
    f32 temp_f1;
    f32 temp_f2;
    CollisionBody *body;

    TObjEneBalClaw__sub_8008D68C();
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_8008DC90();
        sub_8008FC0C();
        return;
    }
    if ((m_388 & 0x02000000) && get_flag_0x388_b24() == 0) {
        update_if_active(2);
    } else {
        sub_8008FC10();
    }
    if (mode != (s32)next_action) {
        if ((s32)state != -1) {
            state = -1;
            sub_8008FF50();
        }
        mode = next_action;
        state = 0;
    }
    sub_8008FF50();
    update_wobble();
    update_claw_angle();
    VecCopy((Vec *)&m_2fc, &position);
    temp_f2 = m_300;
    m_300 = temp_f2 + (m_3b4 + m_3bc);
    temp_f1 = m_3b4;
    body = bodies;
    body->offset.y = temp_f1 + m_3bc;
    submit_cursor_candidate(this, -1, (int)body, temp_f1, temp_f2);
    minimap_render_dot((u8 *)&position, -0x5DB4, 1, 0);
}

void TObjEneBalClawBody::sub_8008FF50() {
    switch (mode) {
    case 0:
        update_dragon_boss_state();
        return;
    case 1:
        TObjPlayer__sub_8008FAD0((u8 *)this);
        return;
    case 2:
        TObjPlayer__sub_8008F1DC(this);
        return;
    case 9:
        TObjPlayer__sub_8008EDE8((P_8008EDE8 *)this);
        return;
    case 4:
        TObjPlayer__sub_8008F910((u8 *)this);
        return;
    case 5:
        ((TObjPlayer *)this)->run_death_sequence();
        return;
    case 7:
        TObjPlayer__sub_8008EC3C((u8 *)this);
        return;
    case 10:
        TObjPlayer__sub_8008E310((P_8008E310 *)this);
        return;
    case 11:
        TObjPlayer__sub_8008E254(this);
        return;
    case 12:
        ((TObjPlayer *)this)->update_move_to_target();
        return;
    case 8:
        TObjPlayer__sub_8008DD14((Obj_8008DD14 *)this);
        break;
    }
}

extern "C" {

#define F(T, o) (*(T *)(((u8 *)this) + (o)))
#define VO ((VObj_18 *)(((u8 *)this)))
void TObjEneBalClawBody::sub_8008FC10() {
    f32 d;
    s32 old;
    if (F(s16, 0x326) != 0 && F(s16, 0x326) != 8) {
        F(s32, 0x3D4)++;
    }
    if (get_flag_0x388_b24() != 0) {
        switch (F(s16, 0x326)) {
        case 0:
        case 1:
            if (F(s32, 0x3D4) > 0x708 || F(s16, 0x3DA) >= 2) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xB);
                return;
            }
            break;
        }
        if (VO->m17(0x1E) != 0) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(250.0f);
        }
        switch (F(s16, 0x326)) {
        case 0:
        case 8:
            if (F(u32, 0x2A8) != 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(1);
                F(s32, 0x38C) = 2;
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->sub_800C73F4();
            }
            break;
        case 1:
            if (F(u32, 0x2A8) != 0) {
                d = xz_distance_squared((void *)(F(u32, 0x2A8) + 0x38), ((u8 *)this) + 0x38);
                old = F(s32, 0x38C);
                switch (old) {
                case 0:
                    if (d > 3600.0f) {
                        F(s32, 0x38C) = 1;
                    }
                    break;
                case 1:
                    if (d < 1600.0f) {
                        F(s32, 0x38C) = 0;
                    } else if (d > 14400.0f) {
                        F(s32, 0x38C) = 2;
                    }
                    break;
                case 2:
                    if (d < 10000.0f) {
                        F(s32, 0x38C) = 1;
                    }
                    break;
                }
                if (old != F(s32, 0x38C)) {
                    switch (F(s32, 0x38C)) {
                    case 0:
                        ((TObjEnemyCustom *)((u8 *)this))->update_if_active(9);
                        break;
                    case 1:
                        ((TObjEneBalClaw *)((u8 *)this))->clear_attack_flag();
                        break;
                    case 2:
                        ((TObjEneBalClaw *)((u8 *)this))->set_attack_distance_flag();
                        break;
                    }
                }
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(8);
            }
            break;
        }
    } else {
        if (VO->m17(0x1E) != 0 && F(s16, 0x326) != 2) {
            ((TObjEnemyCustom *)((u8 *)this))->find_target_in_range(250.0f);
        }
        switch (F(s16, 0x326)) {
        case 0:
            if (VO->m17(0x1E) != 0 && F(u32, 0x2A8) == 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xA);
                return;
            }
            break;
        case 1:
        case 12:
            if (F(s32, 0x3D4) > 0x708) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xA);
                return;
            }
            break;
        }
        switch (F(s16, 0x326)) {
        case 0:
        case 8:
            if (F(u32, 0x2A8) != 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(0xC);
            } else {
                ((TObjEnemyCustom *)((u8 *)this))->sub_800C73F4();
            }
            break;
        case 1:
            if (F(u32, 0x2A8) == 0) {
                ((TObjEnemyCustom *)((u8 *)this))->update_if_active(8);
            }
            break;
        }
    }
}
#undef F
#undef VO

}

void TObjEneBalClawBody::sub_8008FC0C() {
}

extern "C" {

void TObjPlayer__sub_8008FAD0(u8 *arg0) {
    s16 v;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)arg0 + 0x30) &= 0xFBFFFEFF;
        ((TObjEnemyCustom *)arg0)->sub_8004292C();
        v = 6;
        if (*(s32 *)((s8 *)arg0 + 0x388) & 0x01000000) {
            v = 1;
        }
        *(s16 *)((s8 *)arg0 + 0xB8) = v;
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
        if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
            VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
        }
        break;
    case 1:
        if (*(void **)((s8 *)arg0 + 0x2A8) == NULL) {
            reset_enemy_state__10TObjPlayerFv();
            break;
        }
        play_persistent_sound(0x4003B235, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
        *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
        {
            Vec pos = *(Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            update_enemy_wander_move(arg0, &pos, 1, *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x350)) + 4));
        }
        ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((u8 *)((TObjEnemy *)arg0)->movementParameters + 8), (Vec *)((u8 *)arg0 + 0x308));
        ((TObjMotion *)arg0)->advance_animation();
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->update_collisions();
        break;
    case -1:
        break;
    }
}

void TObjPlayer__sub_8008F910(u8 *arg0) {
    s32 var_r30;
    s32 var_r3;
    switch (*(s32 *)((s8 *)arg0 + 0x37C)) {
    case -1:
        break;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x30) &= ~0x200000;
        *(s16 *)((s8 *)arg0 + 0xB8) = ((TObjEneBalClaw *)arg0)->get_flag_0x388_b24() != 0 ? 3 : 8;
        *(s32 *)((s8 *)arg0 + 0x37C) = 1;
    case 1: {
        ((TObjMotion *)arg0)->advance_animation();
        *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
        Vec v = *(Vec *)((s8 *)arg0 + 0x2FC);
        v.x += *(f32 *)((s8 *)arg0 + 0x308);
        v.z += *(f32 *)((s8 *)arg0 + 0x310);
        if (check_path_obstructed(arg0, &v) == 0) {
            move_with_wall_slide(arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x308) = *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
        }
        *(f32 *)((s8 *)arg0 + 0x308) *= 0.9f;
        *(f32 *)((s8 *)arg0 + 0x310) *= 0.9f;
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
        ((TObjPlayer *)arg0)->update_collisions();
        if (*(u32 *)((s8 *)arg0 + 0xB4) != 8U) {
            var_r30 = 0;
            *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
            *(s32 *)((s8 *)arg0 + 0x30) &= ~0x200;
            *(s32 *)((s8 *)arg0 + 0x388) &= ~1;
            if (((TObjEneBalClaw *)arg0)->get_flag_0x388_b24() == 0) {
                var_r3 = fn_80090464(arg0, 0);
                if (var_r3 <= 0) {
                    var_r3 = 0xA;
                }
                if (*(s16 *)((s8 *)arg0 + 0x32C) <= (*(s16 *)((s8 *)arg0 + 0x2B8) * var_r3) / 100) {
                    if (!(*(s32 *)((s8 *)arg0 + 0x388) & 0x02000000)) {
                        *(u16 *)((s8 *)arg0 + 0x338) = *(u16 *)((s8 *)arg0 + 0x2D4);
                        *(s32 *)((s8 *)arg0 + 0x388) |= 0x02000000;
                    }
                    var_r30 = 2;
                }
            }
            ((TObjEnemyCustom *)arg0)->update_if_active(var_r30);
        }
        break;
    }
    }
}

void TObjPlayer::run_death_sequence() {
    u8 *arg0 = (u8 *)this;
    s32 i;
    u8 *p;
    switch (this->m_37c) {
    case 0:
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        *(s32 *)((s8 *)arg0 + 0x388) &= ~0x20000;
        if (((TObjEneBalClaw *)arg0)->get_flag_0x388_b24() != 0) {
            this->requested_action = 4;
            this->m_37c = 1;
            for (i = 0; i < ((P_8008F730 *)arg0)->n; i++) {
                p = (u8 *)find_entity_by_id(((P_8008F730 *)arg0)->ids[i]);
                if (p != NULL) {
                    ((TObjEnemy *)p)->send_entity_set_flags();
                    queue_destruction__7TObjectFv(p);
                }
            }
        } else {
            this->requested_action = 9;
            *(f32 *)((s8 *)arg0 + 0x30C) = *(f32 *)((s8 *)arg0 + 0x3B4) / 11.666666f;
            this->m_37c = 2;
        }
        play_sound_effect(0x4003AD37, (u8 *)&this->position, 0, 0);
        break;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        if (this->frame >= 20.0f) {
            this->m_37c = 3;
        }
        break;
    case 2:
        ((TObjMotion *)arg0)->advance_animation();
        if (this->frame >= 10.0f) {
            *(f32 *)((s8 *)arg0 + 0x3B4) -= *(f32 *)((s8 *)arg0 + 0x30C);
            if (*(f32 *)((s8 *)arg0 + 0x3B4) <= 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x3B4) = 0.0f;
                this->m_37c = 3;
            }
        }
        break;
    case 3:
        TObjPlayer__sub_800A04F0((u8 *)&this->unk_390);
        spawn_effect_pair_e8_ec((Vec *)(arg0 + 0x2FC));
        *(s32 *)((s8 *)arg0 + 0x388) |= 4;
        this->m_37c = 4;
    case 4:
        ((TObjMotion *)arg0)->advance_animation();
        if (((VObj_14_c1c33b *)(arg0 + 0x390))->m4() == 1) {
            TObjPlayer::apply_effect_variant_a((s32)(arg0 + 0x38), 0);
            ((TObjEnemy *)arg0)->send_entity_set_flags();
            queue_destruction__7TObjectFv(arg0);
        }
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#define RESET(p) ((s32 (*)(void *))reset_enemy_state__10TObjPlayerFv)(p)
#define o ((P_8008F1DC *)arg0)
void TObjPlayer__sub_8008F1DC(void *arg0) {
    switch (o->state) {
    case 0:
        if (((TObjEneBalClaw *)o)->get_flag_0x388_b24() != 0) {
            RESET(o);
            return;
        }
        if (FLD(u16, 0x2D4) < 0x1000) {
            o->f338 = FLD(u16, 0x2D4);
            FLD(T_8008F1DC *, 0x2A8) = find_active_entity_by_id(o->f338);
            if (FLD(T_8008F1DC *, 0x2A8) != NULL && (FLD(T_8008F1DC *, 0x2A8)->flags30 & 0x04000800)) {
                o->f338 = 0xFFFF;
                FLD(T_8008F1DC *, 0x2A8) = NULL;
            }
        } else {
            ((TObjEnemyCustom *)o)->find_target_in_range(250.0f);
        }
        if (o->f338 != 0xFFFF) {
            o->f388 &= ~0x20000;
            FLD(s16, 0xB8) = 6;
            o->state = 1;
        } else {
            o->m56();
        }
        break;
    case 1:
        if (FLD(T_8008F1DC *, 0x2A8) == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            o->vel.y = 0.0f;
            calc_velocity_toward_destination(o, o->pos, FLD(T_8008F1DC *, 0x2A8)->pos, 0.7f);
            {
                Vec n1 = o->pos;
                n1.x += o->vel.x;
                n1.z += o->vel.z;
                if (check_path_obstructed(o, &n1) == 0) {
                    move_with_wall_slide((u8 *)o);
                }
            }
            ((TObjEnemy *)o)->turn_toward_direction((s32)o->f350->f8, (Vec *)&o->vel);
            o->f3C0 = xz_distance_squared(&o->pos, &FLD(T_8008F1DC *, 0x2A8)->pos);
            if (o->f3C0 <= ((AttackParams *)(o->f318))->get_attack_range() * ((AttackParams *)(o->f318))->get_attack_range()) {
                FLD(s16, 0xB8) = 7;
                o->state = 2;
                o->p3E4 = (u32)spawn_particle_effect_with_rotation(&o->pos, &o->f3F8, 0x12B, 2);
                ((TParticleCtrl *)(o->p3E4))->enable();
                o->p3E8 = (u32)spawn_particle_effect_with_rotation(&o->pos, &o->f3F8, 0x12C, 2);
                ((TParticleCtrl *)(o->p3E8))->enable();
            }
        }
        break;
    case 2:
        push_matrix_from(identity_matrix);
        post_translate_matrix(&o->pos);
        rotate_matrix_y(0, FLD(s32, 0x60));
        ((TObjEnemy *)o)->calc_joint_matrices(FLD(f32, 0xC0));
        pop_matrix();
        o->m63(8, o->f3EC);
        o->f3F8 = 0;
        o->f3FC = FLD(s32, 0x60) + 0x4000;
        o->f400 = -0x4000;
        if (FLD(f32, 0xC0) >= 9.0f && FLD(f32, 0xC0) < 17.0f) {
            ((TParticleCtrl *)o->p3E4)->set_position(o->f3EC);
            ((TParticleCtrl *)(o->p3E4))->set_direction(&o->f3F8);
        } else {
            ((TParticleCtrl *)(o->p3E4))->enable();
        }
        if (FLD(f32, 0xC0) >= 12.0f && FLD(f32, 0xC0) < 17.0f) {
            ((TParticleCtrl *)o->p3E8)->set_position(o->f3EC);
            ((TParticleCtrl *)(o->p3E8))->set_direction(&o->f3F8);
        } else {
            ((TParticleCtrl *)(o->p3E8))->enable();
        }
        o->vel.y = 0.0f;
        calc_velocity_toward_destination(o, o->pos, FLD(T_8008F1DC *, 0x2A8)->pos, 0.7f);
        {
            Vec n2 = o->pos;
            n2.x += o->vel.x;
            n2.z += o->vel.z;
            if (check_path_obstructed(o, &n2) == 0) {
                move_with_wall_slide((u8 *)o);
            }
        }
        ((TObjEnemy *)o)->turn_toward_direction((s32)o->f350->f8, (Vec *)&o->vel);
        if (((TObjMotion *)o)->is_passing_frame(10.0f) != 0) {
            play_sound_effect(0x4003B034, (u8 *)o + 0x38, 0, 0);
            if (FLD(T_8008F1DC *, 0x2A8)->m18(o, 1.0f) != 0) {
                FLD(T_8008F1DC *, 0x2A8)->m20(o, 1.0f);
                FLD(T_8008F1DC *, 0x2A8)->m23(o, 3.0f);
                if (!(FLD(T_8008F1DC *, 0x2A8)->flags30 & 0x800) && get_actor_hp((u8 *)FLD(T_8008F1DC *, 0x2A8)) > 0) {
                    send_6x2F_change_player_hp(FLD(u16, 0x1C), o->f338, 1);
                }
            }
        }
        if (FLD(u32, 0xB4) != 4) {
            obj_setFlags30(o, 0x800);
        }
        break;
    case -1:
        if (o->p3E4 != 0) {
            queue_destruction__7TObjectFv((void *)o->p3E4);
            o->p3E4 = 0;
        }
        if (o->p3E8 != 0) {
            queue_destruction__7TObjectFv((void *)o->p3E8);
            o->p3E8 = 0;
        }
        o->f388 |= 0x20000;
        break;
    }
    ((TObjMotion *)o)->advance_animation();
    apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
    ((TObjPlayer *)o)->check_object_collisions();
    check_enemy_body_collisions((TObjCollidable *)o);
}
#undef o
#pragma pop

#define RESET(p) ((s32 (*)(void *))reset_enemy_state__10TObjPlayerFv)(p)
void TObjPlayer__sub_8008EDE8(P_8008EDE8 *arg0) {
    switch (arg0->state) {
    case 0:
        if (((TObjEneBalClaw *)arg0)->get_flag_0x388_b24() == 0) {
            RESET(arg0);
            return;
        }
        ((TObjEnemyCustom *)arg0)->find_target_in_range(250.0f);
        if (arg0->f338 != 0xFFFF) {
            arg0->fB8 = 1;
            arg0->state = 1;
            if (select_enemy_destination(arg0, arg0->pos, 1) != 0) {
                copy_position_if_valid__10TObjPlayerFii(arg0, arg0->pos);
            }
        } else {
            RESET(arg0);
        }
        break;
    case 1:
        if (arg0->target == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            arg0->vel.y = 0.0f;
            calc_velocity_toward_destination(arg0, arg0->pos, arg0->target->pos, 0.7f);
            {
                Vec n1 = arg0->pos;
                n1.x += arg0->vel.x;
                n1.z += arg0->vel.z;
                if (check_path_obstructed(arg0, &n1) == 0) {
                    move_with_wall_slide((u8 *)arg0);
                }
            }
            ((TObjEnemy *)arg0)->turn_toward_direction((s32)arg0->f350->f8, (Vec *)&arg0->vel);
            arg0->f3C0 = xz_distance_squared(&arg0->pos, &arg0->target->pos);
            if (arg0->f3C0 <= ((AttackParams *)(arg0->f318))->get_attack_range() * ((AttackParams *)(arg0->f318))->get_attack_range()) {
                arg0->fB8 = 2;
                arg0->state = 2;
                play_sound_effect(0x4003B033, arg0->pos38, 0, 0);
            }
        }
        break;
    case 2:
        if (arg0->target == NULL) {
            reset_enemy_state__10TObjPlayerFv();
        } else {
            arg0->vel.y = 0.0f;
            calc_velocity_toward_destination(arg0, arg0->pos, arg0->target->pos, 0.7f);
            move_with_wall_slide((u8 *)arg0);
            {
                Vec n2 = arg0->pos;
                n2.x += arg0->vel.x;
                n2.z += arg0->vel.z;
                if (check_path_obstructed(arg0, &n2) == 0) {
                    move_with_wall_slide((u8 *)arg0);
                }
            }
            if (((TObjMotion *)arg0)->is_passing_frame(10.0f) != 0) {
                if (arg0->target->m18(arg0, 1.0f) != 0) {
                    if (random_ratio__9TObjCharaFv((s32)arg0) <= 0.1f) {
                        Pair_8008EDE8 q = {0xF, 0};
                        arg0->target->m21(arg0, &q, 0, -1, -1);
                    }
                    arg0->target->m20(arg0, 1.0f);
                    arg0->target->m23(arg0, 3.0f);
                }
                arg0->f3DA++;
            }
            if (arg0->fB4 != 4) {
                RESET(arg0);
            }
        }
        break;
    case -1:
        break;
    }
    ((TObjMotion *)arg0)->advance_animation();
    apply_actor_gravity((TObjEnemy *)((u8 *)arg0), (s32 *)(0), 0.0f);
    ((TObjPlayer *)arg0)->update_collisions();
}

void TObjPlayer::set_visibility_flags_by_count(void *arg0, s32 arg1) {
    s32 i;
    s32 j;
    u32 *e;
    for (i = 0; i < arg1; i++) {
        for (j = 0; (e = lbl_805006F8[i].p[j]) != NULL; j++) {
            *e &= ~8;
        }
    }
    for (; i < 4; i++) {
        for (j = 0; (e = lbl_805006F8[i].p[j]) != NULL; j++) {
            *e |= 8;
        }
    }
}

void TObjPlayer__sub_8008EC3C(u8 *enemy) {
    s32 temp_r4_2;
    s32 temp_r5;
    switch (*(s32 *)((s8 *)enemy + 0x37C)) {
    case 0:
        *(s32 *)((s8 *)enemy + 0x388) = (*(s32 *)((s8 *)enemy + 0x388) | 4);
        *(s32 *)((s8 *)enemy + 0x30) = (s32) (*(s32 *)((s8 *)enemy + 0x30) | 0x04000000);
        *(s16 *)((s8 *)enemy + 0xB8) = (*(s32 *)((s8 *)enemy + 0x388) & 0x01000000) ? 0 : 5;
        ((TBoss3Volopt *)(enemy + 0x38))->play_area_se_with_particle();
        TObjPlayer__sub_800A0554(enemy + 0x390);
        *(s32 *)((s8 *)enemy + 0x37C) = 1;
    case 1:
        ((TObjMotion *)enemy)->advance_animation();
        apply_actor_gravity((TObjEnemy *)enemy, (s32 *)(0), 0.0f);
        if (((En0VObj*)(enemy + 0x390))->m5() == 1) {
            temp_r5 = *(s32 *)((s8 *)enemy + 0x388);
            temp_r4_2 = temp_r5 & ~5;
            *(s32 *)((s8 *)enemy + 0x388) = temp_r4_2;
            *(s32 *)((s8 *)enemy + 0x37C) = -1;
            ((s32 (*)(void *, s32, s32))reset_enemy_state__10TObjPlayerFv)(enemy, temp_r4_2, temp_r5);
        }
        return;
    case -1:
        *(s32 *)((s8 *)enemy + 0x388) = (s32) (*(s32 *)((s8 *)enemy + 0x388) & ~5);
        *(s32 *)((s8 *)enemy + 0x30) = (s32) (*(s32 *)((s8 *)enemy + 0x30) & 0xFBFFFFFF);
        break;
    }
}

void TObjEneBalClawBody::update_dragon_boss_state() {

    switch (this->state) {
    case 0:
        this->actorFlags = (s32) (this->actorFlags | 0x40000);
        this->requested_action = (s16) ((((u32) this->m_388 >> 0x18U) & 1) ? 0 : 5);
        this->state = 1;
    case 1:
        advance_animation();
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
        return;
    case -1:
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
        return;
    }
}

#undef FLD
#undef RESET

#pragma push
#pragma opt_propagation off
#define arg0 ((u8 *)arg0_)
void TObjPlayer__sub_8008E934(void *arg0_, s32 arg1) {
    Vec a;
    Vec b;
    s32 angA;
    s32 angB;
    s32 i;
    s32 id;
    s32 id2;
    s32 n;
    s32 k;
    u8 *ent;
    s32 j;
    if (arg1 == 1) {
        *(u32 *)((s8 *)arg0 + 0x388) |= 0x01000000;
        ((TObjEnemy *)arg0)->set_param(0x28);
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneBalClawClaw *)arg0)->sub_80090418(1);
        *(s16 *)((s8 *)arg0 + 0x3DA) = 0;
        ((VObj_18_4841bb *)(arg0))->m53();
    } else {
        *(u32 *)((s8 *)arg0 + 0x388) &= ~0x01000000;
        ((TObjEnemy *)arg0)->set_param(0x27);
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((TObjEneBalClawClaw *)arg0)->sub_80090418(0);
        ((VObj_18_4841bb *)(arg0))->m53();
        if (!(*(u32 *)((s8 *)arg0 + 0x388) & 0x40000)) {
            *(s16 *)((s8 *)arg0 + 0x32C) = *(s16 *)((s8 *)arg0 + 0x32C) / (*(s16 *)((s8 *)arg0 + 0x3D8) + 1);
            if (*(s16 *)((s8 *)arg0 + 0x32C) <= 0) {
                *(s16 *)((s8 *)arg0 + 0x32C) = 1;
            }
            *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
            if (*(u32 *)((s8 *)arg0 + 0x80) != 0) {
                *(u32 *)((s8 *)arg0 + 0x388) |= 0x40000;
                for (i = 0; i < 4; i++) {
                    id = *(u16 *)((s8 *)arg0 + 0x1C) + i;
                    id2 = *(s16 *)((s8 *)arg0 + 0x2C) + i;
                    id++;
                    id2++;
                    calc_slot_offset_position__10TObjPlayerFPviPvPv((Obj_8008E18C *)arg0, i, &a, &angA);
                    ((void *(*)(void *, u16, void *, void *, void *, void *))create__18TObjEneBalClawClawFPvPvPvPvPv)(arg0, id, (void *)id2, &a, (void *)angA, (void *)*(s16 *)((s8 *)arg0 + 0x32C));
                }
            }
        } else {
            n = 0;
            for (k = 0; k < *(s16 *)((s8 *)arg0 + 0x3D8); k++) {
                ent = get_enemy_entity(((Self_8008E934 *)arg0)->ids[k]);
                if (ent != NULL) {
                    calc_slot_offset_position__10TObjPlayerFPviPvPv((Obj_8008E18C *)arg0, k, &b, &angB);
                    TObjEneBalClawClaw__sub_80090A10(ent, (u8 *)&b, angB, *(s16 *)((s8 *)arg0 + 0x32C));
                    n++;
                }
            }
            if (n > 0) {
                *(s16 *)((s8 *)arg0 + 0x32C) = *(s16 *)((s8 *)arg0 + 0x32C) / (n + 1);
                for (j = 0; j < *(s16 *)((s8 *)arg0 + 0x3D8); j++) {
                    if ((ent = get_enemy_entity(((Self_8008E934 *)arg0)->ids[j])) != NULL) {
                        ((TObjPlayer *)ent)->set_hp_clamped(*(s16 *)((s8 *)arg0 + 0x32C));
                    }
                }
            }
        }
        *(s16 *)((s8 *)arg0 + 0x3D8) = 0;
    }
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    *(u8 **)((s8 *)arg0 + 0x350) = (u8 *)&player_attack_param_table[arg1];
    ((TObjEneBalClawBody *)arg0)->sub_8008DC90();
    *(s32 *)((s8 *)arg0 + 0x368) = arg1;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
}
#undef arg0
#pragma pop

void TObjEneBalClawBody::render() {
    s32 var_r30;
    s32 temp_r3;
    s32 var_r29;
    u8 *arg0 = (u8 *)this;

    if (!(((TObjEneBalClawBody *)arg0)->actorFlags & 0x02000000)) {
        saved_model_render_flags = model_render_flags;
        temp_r3 = ((VObj18_8008e74c_8008DCF0*)arg0)->m9(150.0f, 400.0f, 30.0f);
        if (temp_r3 != 0) {
            var_r30 = 1;
            TObjFish::set_global_param(((TObjEneBalClawBody *)arg0)->texlist);
            select_actor_lighting((s32)arg0);
            TObjPlayer::toggle_particle_effect();
            push_matrix();
            model_render_flags &= 0xFFFFFBFF;
            if (TObjPlayer::check_demo_mode() == 1) {
                TObjPlayer::set_visibility_flags_by_count(arg0, 4);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, ((TObjEneBalClawBody *)arg0)->rotation_y);
                draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
            } else {
                TObjPlayer::set_visibility_flags_by_count(arg0, ((TObjEneBalClawBody *)arg0)->m_3d8);
                translate_matrix(0, 0.0f, ((TObjEneBalClawBody *)arg0)->m_3b4 + *(f32 *)((s8 *)arg0 + 0x3BC), 0.0f);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_x(0, *(s32 *)((s8 *)arg0 + 0x5C));
                rotate_matrix_y(0, ((TObjEneBalClawBody *)arg0)->rotation_y);
                if (((TObjEneBalClawBody *)arg0)->m_388 & 4) {
                    if (((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m8() != 0) {
                        ((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m6();
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
                        ((VObj390V_8008e74c_8008DCF0*)(arg0 + 0x390))->m7();
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
            model_render_flags = saved_model_render_flags;
            ((TObjEneBalClaw *)arg0)->render_scaled(var_r30);
        }
    }
}

}

void TObjEneBalClawBody::vfunc_60() {
    update_if_active(get_flag_0x388_b24() ? 9 : 2);
}

extern "C" {

void TObjPlayer__sub_8008E310(P_8008E310 *arg0_) {
    s32 all;
    s32 cnt;
    E_8008E310 *e;
    f32 lim;
    switch (arg0_->state) {
    case 0:
        if (((TObjEneBalClaw *)arg0_)->get_flag_0x388_b24() != 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        arg0_->f3D4 = 0;
        if (TObjPlayer__sub_8008E098((Obj_8008E098 *)arg0_) == 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        arg0_->flags |= 1;
        arg0_->flags &= ~0x04020000;
        arg0_->timer = 0x258;
        arg0_->state = 1;
        arg0_->fB8 = 5;
        arg0_->emit1 = (u32)create_particle_emitter(arg0_->f2FC, 0x128);
        break;
    case 1:
        ((TParticleCtrl *)arg0_->emit1)->set_position(arg0_->f2FC);
        ((TObjMotion *)arg0_)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), 0.0f);
        all = 1;
        cnt = 0;
        lim = 225.0f;
        for (s32 i = 0; i < arg0_->count; i++) {
            e = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
            if (e != NULL) {
                cnt++;
                if (e->f3C0 > lim) {
                    all = 0;
                }
            } else {
                arg0_->ids[i] = 0xFFFF;
            }
        }
        if (--arg0_->timer <= 0 || cnt == 0) {
            arg0_->flags &= ~1;
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        if (all == 1) {
            for (s32 i = 0; i < arg0_->count; i++) {
                E_8008E310 *e2 = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
                if (e2 != NULL) {
                    ((TObjEneBalClawClaw *)e2)->set_claw_flags();
                    arg0_->f32C += get_actor_hp((u8 *)e2);
                }
            }
            arg0_->emit2 = (u32)create_particle_emitter(arg0_->f2FC, 0x12A);
            ((TParticleCtrl *)(arg0_->emit2))->enable();
            arg0_->fB8 = 0xB;
            arg0_->flags |= 0x04000000;
            arg0_->state = 2;
        }
        break;
    case 2:
        ((TParticleCtrl *)arg0_->emit1)->set_position(arg0_->f2FC);
        ((TObjMotion *)arg0_)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), 0.0f);
        if (arg0_->fC0 < 9.0f) {
            ((TParticleCtrl *)(arg0_->emit2))->enable();
        } else {
            ((TParticleCtrl *)(arg0_->emit2))->clear_active_flag();
            ((TParticleCtrl *)arg0_->emit2)->set_position(arg0_->f2FC);
        }
        if (arg0_->fB8 != 0xB) {
            queue_destruction__7TObjectFv((void *)arg0_->emit1);
            arg0_->emit1 = 0;
            spawn_particle_effect(arg0_->f2FC, 0x129);
            TObjPlayer__sub_8008E934(arg0_, 1);
            ((TObjMotion *)arg0_)->advance_animation();
            arg0_->flags &= ~0x04000000;
            arg0_->f33C = 0x1E;
            arg0_->state = 3;
            play_sound_effect(0x4003AD30, arg0_->pos, 0, 0);
        }
        break;
    case 3:
        ((TParticleCtrl *)arg0_->emit2)->set_position(arg0_->f2FC);
        ((TObjMotion *)arg0_)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), 0.0f);
        if (--arg0_->f33C <= 0) {
            arg0_->flags &= ~1;
            ((TObjPlayer *)arg0_)->reset_enemy_state();
        }
        break;
    case -1:
        if (arg0_->flags & 0x04000000) {
            TObjPlayer__sub_8008E934(arg0_, 1);
            ((TObjMotion *)arg0_)->advance_animation();
        }
        if (((TObjEneBalClaw *)arg0_)->get_flag_0x388_b24() == 0) {
            for (s32 i = 0; i < arg0_->count; i++) {
                e = (E_8008E310 *)find_entity_by_id(arg0_->ids[i]);
                if (e != NULL) {
                    ((TObjEneBalClawClaw *)e)->clear_flag();
                }
            }
        }
        arg0_->flags |= 0x20000;
        if (arg0_->emit1 != 0) {
            queue_destruction__7TObjectFv((void *)arg0_->emit1);
            arg0_->emit1 = 0;
        }
        if (arg0_->emit2 != 0) {
            queue_destruction__7TObjectFv((void *)arg0_->emit2);
            arg0_->emit2 = 0;
        }
        break;
    }
}

void TObjPlayer__sub_8008E254(void *arg0_) {
    switch (((TObjPlayer *)arg0_)->m_37c) {
    case -1:
        break;
    case 0:
        if (((TObjEneBalClaw *)arg0_)->get_flag_0x388_b24() == 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
            return;
        }
        *(s32 *)((s8 *)arg0_ + 0x3D4) = 0;
        TObjPlayer__sub_8008E934(arg0_, 0);
        *(s16 *)((s8 *)arg0_ + 0x33C) = 0x1E;
        ((TObjPlayer *)arg0_)->m_37c = 1;
        return;
    case 1:
        ((TObjMotion *)arg0_)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)arg0_), (s32 *)(0), 0.0f);
        (*(s16 *)((s8 *)arg0_ + 0x33C))--;
        if (*(s16 *)((s8 *)arg0_ + 0x33C) <= 0) {
            ((TObjPlayer *)arg0_)->reset_enemy_state();
        }
        return;
    }
}

void calc_slot_offset_position__10TObjPlayerFPviPvPv(Obj_8008E18C *self, s32 slot, Vec *out, s32 *angle_out) {
    s32 angle;
    push_matrix();
    angle = (s32)(182.04445f * (f32)(slot * 0x5A + 0x2D));
    *angle_out = self->field60 + angle;
    out->x = 0.0f;
    out->y = 0.0f;
    out->z = 13.0f;
    set_matrix_identity(0);
    rotate_matrix_y(0, angle);
    matrix_mult_vec(0, out, out);
    vec3_add_to(out, &self->pos);
    pop_matrix();
}

s32 TObjPlayer__sub_8008E098(Obj_8008E098 *self) {
    s32 i;
    Obj_8008E098 *p;
    s32 j;
    self->count = 0;
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        p = (Obj_8008E098 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && ((TWindowLockOn *)p)->get_target_id() == 0x26 &&
            self->field28 == p->field28 && ((TObjEneBalClawClaw *)p)->check_active() != 0) {
            self->ids[self->count++] = get_entity_id(p);
            if (self->count >= 4) {
                break;
            }
        }
    }
    for (j = 0; j < self->count; j++) {
        enter_hit_state__18TObjEneBalClawClawFs(find_entity_by_id(self->ids[j]), self->field1C);
    }
    return self->count;
}

void TObjPlayer::update_move_to_target() {
    Obj_8008DE9C *self = (Obj_8008DE9C *)this;
    switch (self->state) {
    case -1:
        break;
    case 0: {
        self->f30 &= ~0x100;
        self->fB8 = ((TObjEneBalClaw *)self)->get_flag_0x388_b24() != 0 ? 1 : 6;
        Vec d = self->pos;
        subtract_vector(&d, &self->target->pos);
        ((TObjEnemyCustom *)self)->pick_open_direction((f32 *)&d, 60.0f, 30.0f);
        self->state = 1;
        break;
    }
    case 1: {
        if (self->target == NULL) {
            reset_enemy_state();
            break;
        }
        if (this->is_actor_cadence_frame(0x5A) != 0) {
            Vec d2 = self->pos;
            subtract_vector(&d2, &self->target->pos);
            ((TObjEnemyCustom *)self)->pick_open_direction((f32 *)&d2, 60.0f, 30.0f);
        }
        VecCopy((Vec *)&self->f290, (const Vec *)&self->pos);
        calc_velocity_toward_destination(self, self->f290, self->f29C, self->info->f4);
        ((TObjEnemy *)self)->turn_toward_direction(self->info->f8, (Vec *)&self->vel);
        Vec v = self->pos;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        ((TObjMotion *)self)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), 0.0f);
        ((TObjPlayer *)self)->update_collisions();
        break;
    }
    }
}

void TObjPlayer__sub_8008DD14(Obj_8008DD14 *self) {
    s16 mode;
    switch (self->state) {
    case 0:
        self->f30 &= 0xFFFBFEFF;
        mode = 6;
        if (self->f388 & 0x01000000) {
            mode = 1;
        }
        self->fB8 = mode;
        self->state = 1;
        VecCopy((Vec *)&self->f29C, (const Vec *)&self->home);
        break;
    case 1: {
        self->vel.y = 0.0f;
        VecCopy((Vec *)&self->f290, (const Vec *)&self->pos);
        calc_velocity_toward_destination(self, self->f290, self->f29C, self->info->f4);
        ((TObjEnemy *)self)->turn_toward_direction(self->info->f8, (Vec *)&self->vel);
        Vec v = self->pos;
        v.x += self->vel.x;
        v.z += self->vel.z;
        if (check_path_obstructed(self, &v) == 0) {
            move_with_wall_slide((u8 *)self);
        }
        if (xz_distance_squared(&self->pos38, &self->home) < 100.0f) {
            ((TObjPlayer *)self)->reset_enemy_state();
        }
        ((TObjMotion *)self)->advance_animation();
        apply_actor_gravity((TObjEnemy *)((u8 *)self), (s32 *)(0), 0.0f);
        break;
    }
    case -1:
        break;
    }
}

int TObjPlayer::reset_enemy_state() { return update_if_active__15TObjEnemyCustomFl(this, 0); }

}

void TObjEneBalClawBody::vfunc_58() {
    if (xz_distance_squared(&position, &home_position) > 100.0f) {
        update_if_active(8);
        return;
    }
    update_if_active(0);
}

void TObjEneBalClawBody::sub_8008DC90() {
}

// What TLobby::spawn_npc_enemy reads to set up a spawned Bal Claw.
struct BalClawSpawnParams {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    s32 pad_8;
    s32 pad_c;
};

void TObjEneBalClawClaw::spawn_child_enemy() {
    BalClawSpawnParams params = {lbl_805D4F20->motions, balclaw_body_actions, 1, 0xC0000};
    TLobby::spawn_npc_enemy(0x13, lbl_805D4F20->models[1].model, (NJS_TEXLIST *)lbl_805D4F20->models[1].m_c, &params,
                            balclaw_body_collision.radius, 15.0f);
}
