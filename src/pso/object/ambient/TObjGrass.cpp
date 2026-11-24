#include "pso/enemy/EnemyTargeting.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "types.h"
#include "pso/object/ambient/TObjCGrass.h"
#include "pso/system/AreaSound.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/object/ambient/TObjGrassWeb.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_803D853C.h"

#include "pso/object/ambient/TObjGrass.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/TProtocol.h"
#include "pso/math/ScratchVectors.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"


saddr lbl_805D5140;
AttackParams **TObjGrass__bml_resource;  // the three attack parameter sets (inferred: not a BML resource)
saddr grass_combat_stats_handle;
saddr lbl_805D514C;
s32 TObjGrass__render_node_index;
BmlResource *TObjGrass__resource_bundle;
SampledMotionPoints *lbl_805D5158;
SampledMotionPoints *lbl_805D515C;

#pragma readonly_strings on

struct O_800BFB8C { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct O_800BFB68 { u8 pad[0x3d4]; s32 arr[12]; };


typedef struct Range_800BE75C {
    f32 lo;
    f32 hi;
} Range_800BE75C;

typedef struct Grass_800BE75C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x50 - 0x44];
    u8 mtx50[0x60 - 0x50];
    s32 angle;
    u8 pad64[0x2A8 - 0x64];
    s32 f2A8;
    u8 pad2AC[0x350 - 0x2AC];
    Range_800BE75C *range;
    u8 pad354[0x358 - 0x354];
    f32 f358;
    u8 pad35C[0x39C - 0x35C];
    s16 f39C;
} Grass_800BE75C;


struct VObj_800BDD70 {
    char pad[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32 *, s32 *);
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *);
};

struct Param_800BE4C0 { f32 f0; f32 f4; s32 f8; };

struct Anim_800BE4C0 { u8 pad[8]; f32 f8; u8 padc[4]; };

struct VBase_18_800BD10C { char pad[0x18]; };

struct VObj_18_800BD10C : VBase_18_800BD10C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45();
    virtual s32 m46(s32);
};

struct Tgt_800BD10C : VObj_18_800BD10C {
    u8 pad1C[0x38 - 0x1C]; Vec pos; u8 pad44[0x2FC - 0x44]; Vec p2fc;
};

struct Grass_800BD10C {
    u8 pad0[0x30]; u32 flags30; u8 pad34[0x38 - 0x34]; Vec pos;
    u8 pad44[0x60 - 0x44]; s32 rotY; u8 pad64[0xB4 - 0x64]; u32 fb4; s16 fb8;
    u8 padBA[0x2A8 - 0xBA]; Tgt_800BD10C *target; u8 pad2AC[0x2FC - 0x2AC];
    Vec p2fc; u8 pad308[0x328 - 0x308]; s16 state; u8 pad32A[0x338 - 0x32A];
    u16 client; u8 pad33A[2]; s16 timer; u8 pad33E[0x350 - 0x33E]; s32 *f350;
    u8 pad354[0x380 - 0x354]; Vec p380;
};

struct VBase_14_800BE8FC { char pad[0x14]; };

struct VObj_14_800BE8FC : VBase_14_800BE8FC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Param_800BE8FC { u8 pad0[4]; f32 speed; s32 turn; };

struct Grass_800BE8FC {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[4];
    Vec pos;
    Vec prev;
    Vec home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec f290;
    Vec f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec f2FC;
    u8 pad308[0x328 - 0x308];
    s16 state;
    u8 pad32A[0x350 - 0x32A];
    Param_800BE8FC *param;
    u8 pad354[0x39C - 0x354];
    s16 f39C;
    u8 pad39E[0x3AC - 0x39E];
    s32 f3AC;
    VObj_14_800BE8FC sub;
};

struct O_800BFB68;

struct VBase_18_800BD4D8 { char pad[0x18]; };

struct VObj_18_800BD4D8 : VBase_18_800BD4D8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *, f32);
};

struct Tgt_800BD4D8 {
    u8 pad0[0x2FC]; Vec p2fc;
};

struct Anim_800BD4D8 { u8 pad[8]; f32 f8; u8 padc[4]; };

struct Param_800BD4D8 { f32 range; f32 speed; s32 turn; };

struct Body_800BD4D8 { u8 pad[0xC]; f32 radius; };

struct Grass_800BD4D8 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Body_800BD4D8 *body;
    u8 padA8[0xB4 - 0xA8];
    u32 fb4;
    s16 fb8;
    u8 padBA[0xC8 - 0xBA];
    f32 fc8;
    u8 padCC[0xD8 - 0xCC];
    Anim_800BD4D8 *anims;
    u8 padDC[0x29C - 0xDC];
    Vec f29c;
    Tgt_800BD4D8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec p2fc;
    f32 f308;
    u8 pad30C[4];
    f32 f310;
    u8 pad314[4];
    saddr f318;
    u8 pad31C[0x328 - 0x31C];
    s16 state;
    u8 pad32A[0x338 - 0x32A];
    u16 client;
    u8 pad33A[2];
    s16 timer;
    u8 pad33E[0x350 - 0x33E];
    Param_800BD4D8 *param;
    u8 pad354[0x374 - 0x354];
    Vec f374;
    u8 pad380[0x398 - 0x380];
    f32 f398;
    u8 pad39C[0x3A4 - 0x39C];
    s32 f3a4;
    s32 f3a8;
    u8 pad3AC[0x3D4 - 0x3AC];
    VObj_18_800BD4D8 *hit[12];
};


struct E1C_800BF924 { u8 pad[0x1C]; };

struct E2C_800BF924 { u8 pad[0x2C]; };

void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {
s32 minimap_render_dot(void *, s32, s32, s32);
void TObjGrass__sub_800BFB68(O_800BFB68 *self);
s32 free_collision_body_parts(void *);
f32 step_toward_destination(void *, Vec, f32);
f32 vec3_add_to(void *, void *);
extern u8 identity_matrix[];
s32 check_path_obstructed(void *, void *);
s32 get_current_floor();
s32 subtract_vector(void *, void *);
void TObjGrass__sub_800BCA2C(void *);
s32 scale_matrix(int, f32, f32, f32);
s32 post_translate_matrix(void *);
f32 enemy_move_toward(void *, s32, void *, s32, f32);
void enemy_pursue_point(void *, s32, void *, f32, f32);
f64 atan2_float(f32, f32);
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
f32 newton_sqrtf(f32);
}
extern s32 game_difficulty_selection;
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
f32 fabs_float(f32);
s32 approach_angle_limited(s32, s32, s32);
s32 select_enemy_destination(void *, Vec, int);
s32 copy_position_if_valid(void *, Vec);
s32 is_split_screen();
extern s32 local_client_id;
s32 init_collision_body_parts(void *, void *, int);

extern const char *bm_ene_grass_model_names[2];
extern const char *bm_ene_grass_motion_names[9];
__declspec(section ".data") const char *bm_ene_grass_model_names[2] = {
    "re1_b_grass_base.nj", NULL,
};
const char *bm_ene_grass_motion_names[9] = {
    "damege_re1_b_base.njm", "die_re1_b_base.njm", "lattack_re1_b_base.njm", "mad_re1_b_base.njm",
    "rattack_re1_b_base.njm", "spit_re1_b_base.njm", "wait_re1_b_base.njm", "walk_re1_b_base.njm",
    NULL,
};
BmlResourceDescriptor bm_ene_grass_resource_descriptor = {
    "bm_ene_grass.bml", bm_ene_grass_model_names, bm_ene_grass_motion_names, 1, 8,
};
TObjMotionAction TObjGrass__grass_type_param_table[8] = {
    {1, 0, 6, 0.7f, 1},
    {1, 1, 7, 1.3f, 1},
    {2, 0, 2, 0.7f, 4},
    {2, 0, 4, 0.7f, 4},
    {2, 0, 5, 0.7f, 4},
    {2, 0, 0, 0.6f, 8},
    {3, 5, 1, 0.4f, 0x10},
    {2, 1, 3, 0.5f, 0x20},
};
void *lbl_804929E4[7] = {
    (void *)0x43c80000, (void *)0x3f400000, (void *)0x100, (void *)0x1e0000,
    (void *)0x0, (void *)0x1, (void *)0x0,
};
void *lbl_80492A00[11] = {
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
const char *TObjGrass__class_name = "TObjGrass";
const NpcAnimationBinding grass_spawn_descriptor = {NULL, TObjGrass__grass_type_param_table, 0, 1, 8};
const Vec lbl_8043B790 = {0.0f, 0.0f, 0.0f};
const char *TObjGrassWeb__class_name = "TObjGrassWeb";
#pragma fp_contract on

typedef struct Web_800BC798 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x84 - 0x44];
    s32 timer;
    u8 pad88[0x90 - 0x88];
    s32 state;
} Web_800BC798;

void TObjGrassWeb__sub_800BC798(Web_800BC798 *o);

Vec grass_camera_vec;
Vec grass_render_vec;
Vec grass_origin_vec;
struct VBase_14_d701ad { char pad[0x14]; };
struct VObj_14_d701ad : VBase_14_d701ad {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6(s32, s32);
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
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
struct Grass_800BF19C : VObj_18_ca64a0 {
    u8 pad1C[0x3B0 - 0x1C];
    VObj_14_d701ad sub;
};

void TObjGrass::init_from_table_entry(s32 i) {
    O_800BFB8C *self = (O_800BFB8C *)this;
    self->f34 = (saddr)TObjGrass__resource_bundle->models[i].model;
    self->f24 = (saddr)TObjGrass__resource_bundle->models[i].texlist;
}
void TObjGrass__sub_800BFB68(O_800BFB68 *self) {
    s32 i;
    for (i = 0; i < 12; i++) {
        self->arr[i] = 0;
    }
}

TObjGrass::TObjGrass(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s32 t;
    m_name = TObjGrass__class_name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_actor_gravity(this, 0, (0.0f));
    t = (saddr)TObjGrass__resource_bundle->motions;
    *(saddr *)&motion_list = t;
    scale.y = (1.3f);
    variant = 0;
    ((TObjEnemy *)this)->set_param(0xC);
    resetTimer = 0x1E;
    timer = resetTimer;
    subtype = 0;
    init_from_table_entry(variant);
    action_table = TObjGrass__grass_type_param_table;
    set_action_table(action_table);
    if ((0.0f) < parameters[1]) {
        m_39c = 2;
    } else {
        m_39c = 1;
    }
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &((E2C_800BF924 *)lbl_80492A00)[variant], 1);
    m_39e = 0;
    bind_enemy_combat_stats(reinterpret_cast<player_stats *>(lbl_805D5140), reinterpret_cast<AttackParams *>(TObjGrass__bml_resource[m_39e]), reinterpret_cast<ActorParamBlock *>(grass_combat_stats_handle));
    movementParameters = &((E1C_800BF924 *)lbl_804929E4)[variant];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    register_object_by_id();
    m_398 = (0.0f);
    mode = 0;
    phase = 0;
    m_3a0 = 0;
    TObjGrass__sub_800BFB68((O_800BFB68 *)this);
    add_flags_2e4(2);
    set_actor_flags(0x04040000);
    fade.reset_obstruction_fade();
    m_3ac = 1;
    savers[0] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    savers[1] = TAttackTraceStrip::create(0xA0303030, 0xFFFF0088);
    m_3a8 = 0;
    clear_lobby_object_state();
}

TObjGrass::~TObjGrass() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (savers[i] != NULL) {
            savers[i]->queue_destruction();
            savers[i] = NULL;
        }
    }
    free_collision_body_parts(this);
}

void TObjGrass::load_resources() {
    BmlResource *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        TObjGrass__resource_bundle = load_enemy_bml_resource_named(&bm_ene_grass_resource_descriptor, "bm_ene_grass_a.bml");
    } else {
        p = new BmlResource(1, &bm_ene_grass_resource_descriptor, 0, 0, NULL);
        TObjGrass__resource_bundle = p;
    }
    TObjGrass__render_node_index = 0;
    grass_origin_vec.x = grass_origin_vec.y = grass_origin_vec.z = (0.0f);
    lbl_805D5158 = new SampledMotionPoints(2, (0.0f), (2e+01f), (0.7f));
    lbl_805D515C = new SampledMotionPoints(2, (0.0f), (2e+01f), (0.7f));
    lbl_805D5158->sample_two_nodes((NJS_OBJECT *)TObjGrass__resource_bundle->models[0].model,
        (NJS_MOTION *)TObjGrass__resource_bundle->motions[TObjGrass__grass_type_param_table[2].motion].motion, 0x46, 0x48);
    lbl_805D515C->sample_two_nodes((NJS_OBJECT *)TObjGrass__resource_bundle->models[0].model,
        (NJS_MOTION *)TObjGrass__resource_bundle->motions[TObjGrass__grass_type_param_table[3].motion].motion, 0x3C, 0x3E);
    TObjGrass__bml_resource = (AttackParams **)mem_alloc(0xC);
    lbl_805D5140 = (saddr)TLobby::register_boss(0x4E);
    TObjGrass__bml_resource[0] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x51);
    TObjGrass__bml_resource[2] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x52);
    TObjGrass__bml_resource[1] = (AttackParams *)TLobby::dispatch_shared_handler_b(0x53);
    grass_combat_stats_handle = (saddr)TLobby::register_object(0x4D);
    lbl_805D514C = (saddr)TLobby::dispatch_shared_handler_a(0x4D);
    {
        NpcAnimationBinding binding = grass_spawn_descriptor;
        binding.motions = TObjGrass__resource_bundle->motions;
        TObjNpcEnemy::register_animated_chunk(0x35, TObjGrass__resource_bundle->models[0].model,
            TObjGrass__resource_bundle->models[0].texlist, &binding, 10.0f, 0.0f);
    }
}

void TObjGrass::destroy_all() {
    if (TObjGrass__bml_resource != NULL) {
        mem_free(TObjGrass__bml_resource);
        TObjGrass__bml_resource = NULL;
    }
    if (lbl_805D515C != NULL) {
        delete lbl_805D515C;
        lbl_805D515C = NULL;
    }
    if (lbl_805D5158 != NULL) {
        delete lbl_805D5158;
        lbl_805D5158 = NULL;
    }
    if (TObjGrass__resource_bundle != NULL) {
        delete TObjGrass__resource_bundle;
        TObjGrass__resource_bundle = NULL;
    }
}

void *TObjGrass::create(void *set_data) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjGrass(parent, set_data);
}

void TObjGrass::run_task() {
    u8 *arg0 = (u8 *)this;
    s16 mode;
    s32 temp_r30;
    u16 client;
    TObjPlayer *temp_r3_2;
    TObjChara *target;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjGrass__sub_800BCA2C(arg0);
        return;
    }
    client = this->targetId;
    if (client < 0x1000U) {
        temp_r3_2 = get_player_by_client_id(client);
        if (temp_r3_2 != NULL) {
            if (temp_r3_2->get_floor() == get_current_floor()) {
                this->target = temp_r3_2;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (client < 0x4000U) {
        this->target = get_enemy_entity(client);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    mode = this->mode;
    {
        switch (this->mode) {
        case 0:
            TObjGrass::update_ai(arg0);
            break;
        case 1:
            ((TObjGrass *)arg0)->sub_800BE75C();
            break;
        case 2:
            update_chase_target();
            break;
        case 3:
            ((TObjGrass *)arg0)->sub_800BDD70();
            break;
        case 4:
            ((TObjGrass *)arg0)->sub_800BD4D8();
            break;
        case 5:
            update_web_attack();
            break;
        case 6:
            update();
            break;
        case 7:
            ((TObjGrass *)arg0)->sub_800BCE44();
            break;
        case 8:
            update_dying();
            break;
        case 9:
            break;
        }
    }
    target = this->target;
    if ((target != NULL) && (target->actorFlags & 0x02000800)) {
        this->timer = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        this->target = NULL;
    }
    ((TObjEnemy *)arg0)->update_prev_position();
    reinterpret_cast<TObjChara *>(arg0)->copy_position();
    submit_cursor_candidate(arg0, -1);
    this->frame_timer += (1.0f);
}

void TObjGrass::render() {
    Grass_800BF19C *self = (Grass_800BF19C *)this;
    u8 *arg0 = (u8 *)self;

    if (*(s32 *)((s8 *)arg0 + 0x30) & 0x02000000) {
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3A8) = self->m9((2.5e+02f), (5e+02f), (4e+01f));
    if (*(s32 *)((s8 *)arg0 + 0x3A8) == 0) {
        return;
    }
    select_actor_lighting(this);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(*(s32 *)((s8 *)arg0 + 0x24)));
    push_matrix();
    translate_matrix(0, (0.0f), *(f32 *)((s8 *)arg0 + 0x35C), (0.0f));
    post_translate_matrix(arg0 + 0x38);
    rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
    scale_matrix(0, (1.3f), *(f32 *)((s8 *)arg0 + 0x6C), (1.3f));
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(*(void **)((s8 *)arg0 + 0x34));
    } else {
        TObjPlayer::toggle_particle_effect();
        TObjGrass__render_node_index = 0;
        set_chunk_model_node_callback(TObjGrass::update_camera_vec_by_stage);
        if (*(s32 *)((s8 *)arg0 + 0x3AC) == 1) {
            if ((&self->sub)->m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                (&self->sub)->m6(chunk_polygon_flags_and_mask, model_render_flags);
                if (((TObject *)self)->defer_render() == 0) {
                    ((TObjMotion *)self)->draw();
                }
                (&self->sub)->m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            model_render_flags |= 0x01000000;
            if (*(s32 *)((s8 *)arg0 + 0x3A8) == 1) {
                ((TObjMotion *)self)->draw();
            } else {
                ((TObjEnemy *)self)->draw_motion_model();
            }
            model_render_flags &= 0xFEFFFFFF;
        }
        TParticleCtrl::end_effect_render();
    }
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    restore_scene_lighting();
    VecCopy((Vec *)(arg0 + 0x374), (const Vec *)&grass_camera_vec);
    VecCopy((Vec *)(arg0 + 0x380), (const Vec *)&grass_render_vec);
    VecCopy((Vec *)(arg0 + 0x38C), (const Vec *)&grass_origin_vec);
    switch (*(s16 *)((s8 *)arg0 + 0x326)) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default: {
        Vec v;
        v.x = (1.0f);
        v.y = (1.0f);
        v.z = (4.0f);
        ((TObjEnemy *)self)->draw_ground_shadow(&v, 0);
        break;
    }
    }
}

void TObjGrass::refresh_target() {
    u16 best_id;
    s32 i;
    u16 id;
    u8 *p;
    f32 best;
    f32 d;
    TObjPlayer *q;
    u16 tid;
    u8 *arg0 = (u8 *)this;
    if (((TObjGrass *)(arg0))->is_actor_cadence_frame(0x1E) != 0) {
        if (*(s32 *)&this->m_3ac == 1) {
            this->targetId = 0xFFFFU;
            this->target = NULL;
            return;
        }
        if (((TObjCollidable *)arg0)->test_actor_flags(0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec v = lbl_8043B790;
            best = *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0) * *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0);
            for (; i < registered_player_count + registered_enemy_count; i++) {
                p = (u8 *)TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                id = ((TObjBase *)(p))->get_entity_id();
                if (id < 0x4000 && id != this->entity_id && !(*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy((Vec *)&v, (const Vec *)(p + 0x2FC));
                    subtract_vector(&v, (u8 *)&this->body_center);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(arg0, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            this->targetId = best_id;
        } else {
            this->targetId = find_nearest_visible_player(this, NULL, *(f32 *)((s8 *)(*(f32 * *)&this->movementParameters) + 0));
        }
        tid = this->targetId;
        if (tid < 0x1000U) {
            q = get_player_by_client_id(tid);
            if (q != NULL) {
                if (q->get_floor() == get_current_floor()) {
                    this->target = q;
                    ((TObjBase *)arg0)->clear_actor_flags(0x04040000);
                    return;
                }
            }
            this->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            this->target = get_enemy_entity(tid);
            ((TObjBase *)arg0)->clear_actor_flags(0x04040000);
        }
    }
}


s32 TObjGrass::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
            this->m_3ac = 0;
            this->phase = 2;
            this->requested_action = 1;
            clear_actor_flags((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}


s32 TObjGrass::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
            this->m_3ac = 0;
            this->phase = 2;
            this->requested_action = 1;
            clear_actor_flags((u32)(0x04040000));
        }
        return 1;
    }
    return 0;
}

void TObjGrass::run_idle_action() {
    TObjGrass *self = this;
    switch (self->mode) {
    case 0:
        switch (self->phase) {
        case 0:
        case 1:
            break;
        default:
            self->phase = 2;
        case 2:
            if (*(s32 *)&self->m_3ac != 0) {
                self->phase = 0;
            }
            break;
        }
        break;
    default:
        self->mode = 0;
        if (*(s32 *)&self->m_3ac != 0) {
            self->phase = 0;
        } else {
            self->phase = 2;
        }
        self->requested_action = 1;
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#define o ((Grass_800BE8FC *)arg0)
void TObjGrass::update_ai(void *arg0) {
    ((TObjMotion *)o)->advance_animation();
    switch (o->state) {
    case 0:
        ((TObjBase *)o)->set_actor_flags(0x04040000);
        ((TUnk_80494938 *)(&o->sub))->start_fade_in();
        play_area_sound_effect(&o->pos);
        o->state = 1;
        break;
    case 1:
        ((TObjBase *)o)->set_actor_flags(0x04040000);
        if (o->sub.m5() == 1) {
            o->state = 2;
            o->fB8 = 1;
            o->f3AC = 0;
        }
        break;
    default:
        o->state = 2;
    case 2:
        ((TObjBase *)o)->clear_actor_flags(0x04040000);
        switch (o->f39C) {
        case 1:
            o->fB8 = 1;
            if ((1e+04f) < horizontal_distance_squared(&o->pos, &o->home)) {
                Vec *d;
                Vec *v;
                s32 ang;
                VecCopy((Vec *)&o->f29C, (const Vec *)&o->home);
                VecCopy((Vec *)&o->f290, (const Vec *)&o->f2FC);
                VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
                VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home);
                subtract_vector(&scratch_vec, &o->pos);
                d = &scratch_vec;
                ang = (s32)((10430.38043493439) * atan2_float(d->x, d->z));
                v = &lbl_8050BF00;
                v->x = v->y = (0.0f);
                v->z = o->param->speed;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                pop_matrices(1);
                vec3_add_to(&lbl_8050BF00, &o->pos);
                if (project_actor_to_ground(static_cast<TObjCollidable *>(arg0), &lbl_8050BF00, NULL) == 1) {
                    o->fB8 = 1;
                    VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                    o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
                } else {
                    f32 r = fabs_float(d->z);
                    if (fabs_float(scratch_vec.x) < r) {
                        ang = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                    } else {
                        ang = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                    }
                    v->y = (0.0f);
                    lbl_8050BF00.x = (0.0f);
                    v->z = o->param->speed;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, ang);
                    rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                    pop_matrices(1);
                    vec3_add_to(&lbl_8050BF00, &o->pos);
                    if (project_actor_to_ground(static_cast<TObjCollidable *>(arg0), &lbl_8050BF00, NULL) == 1) {
                        o->fB8 = 1;
                        VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                        o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
                    } else {
                        s32 ang2;
                        r = fabs_float(d->z);
                        if (fabs_float(scratch_vec.x) < r) {
                            ang2 = (s32)((10430.38043493439) * atan2_float((0.0f), d->z));
                        } else {
                            ang2 = (s32)((10430.38043493439) * atan2_float(scratch_vec.x, (0.0f)));
                        }
                        v->y = (0.0f);
                        lbl_8050BF00.x = (0.0f);
                        v->z = o->param->speed;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, ang2);
                        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                        pop_matrices(1);
                        vec3_add_to(&lbl_8050BF00, &o->pos);
                        if (project_actor_to_ground(static_cast<TObjCollidable *>(arg0), &lbl_8050BF00, NULL) == 1) {
                            o->fB8 = 1;
                            VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                            o->angle = approach_angle_limited(o->angle, ang2, o->param->turn);
                        } else {
                            o->fB8 = 1;
                        }
                    }
                }
                ((TObjEnemy *)o)->enemy_turn_toward_dest(o->param->turn);
                enemy_set_heading_velocity(o->param->speed, (TObjEnemy *)(o), o->angle);
                move_with_wall_slide(reinterpret_cast<TObjChara *>(o));
            } else {
                ((TObjEnemy *)(o))->enemy_wander_home((0.25f) * o->param->speed, (1e+02f), (5e+01f), o->param->turn);
            }
            ((TObjCollidable *)o)->refresh_collision_body_centers();
            break;
        default:
            o->fB8 = 0;
            if (!(o->flags30 & 0x800000)) {
                apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), (0.0f));
            }
            break;
        }
        break;
    }
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    ((TObjBase *)o)->clear_actor_flags(0x200000);
}
#undef o
#pragma pop

void TObjGrass::run_move_action() {
    s16 mode;

    mode = this->mode;
    if ((mode >= 3) || (mode < 1)) {
        this->requested_action = 1;
        if ((s16) this->m_39c == 2) {
            this->mode = 1;
        } else {
            this->mode = 2;
        }
        this->phase = 0;
        clear_actor_flags((u32)(0x04040000));
    }
}

void TObjGrass::sub_800BE75C() {
    Grass_800BE75C *o = (Grass_800BE75C *)this;
    Vec v;
    f32 d;
    f32 lo2;
    f32 hi2;
    ((TObjBase *)o)->set_actor_flags(0x04040000);
    ((TObjMotion *)o)->advance_animation();
    v.y = (0.0f);
    v.x = (0.0f);
    v.z = o->f358;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, o->angle);
    rotate_vector_by_matrix(0, &v, &v);
    pop_matrices(1);
    vec3_add_to(&v, o->mtx50);
    d = step_toward_destination(o, v, (2.0f) * o->range->hi);
    lo2 = o->range->lo * o->range->lo;
    hi2 = o->range->hi * o->range->hi;
    if (lo2 < d || d < hi2) {
        o->f2A8 = 0;
        o->f39C = 0;
    }
    apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), (0.0f));
    play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area(0x4003A801), o, &o->pos, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}

#define arg0 ((u8 *)this)
void TObjGrass::update_chase_target() {
    f32 speed;
    f32 dist;
    s32 turn;
    Param_800BE4C0 *prm;
    ((TObjBase *)arg0)->clear_actor_flags(0x04040000);
    prm = *(Param_800BE4C0 **)((s8 *)arg0 + 0x350);
    speed = prm->f4;
    turn = prm->f8;
    if (*(s32 *)((s8 *)arg0 + 0x30) & 0x2000) {
        speed *= (2.0f);
        *(f32 *)((s8 *)arg0 + 0xC8) = (2.0f) * (*(Anim_800BE4C0 **)((s8 *)arg0 + 0xD8))[*(s16 *)((s8 *)arg0 + 0xB8)].f8;
        { f32 ft = (f32)turn; ft *= (2.0f); turn = (s32)ft; }
        play_persistent_sound(remap_sound_for_area(0x4003A300), this, &position, 0, 0);
    } else {
        play_persistent_sound(remap_sound_for_area(0x4003A801), this, &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
    }
    ((TObjMotion *)arg0)->advance_animation();
    if (*(u8 **)((s8 *)arg0 + 0x2A8) != NULL) {
        switch (*(s16 *)((s8 *)arg0 + 0x328)) {
        default:
            *(s16 *)((s8 *)arg0 + 0x328) = 0;
        case 0: {
            Vec v;
            Vec t = *(Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            dist = enemy_move_toward(arg0, turn, &t, 0, (0.125f) * speed);
            VecCopy((Vec *)&v, (const Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC));
            subtract_vector(&v, arg0 + 0x2FC);
            turn = angle_difference_abs(*(s32 *)((s8 *)arg0 + 0x60), (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
            if (turn < ((AttackParams *)(*(saddr *)((s8 *)arg0 + 0x318)))->get_attack_angle()) {
                *(s16 *)((s8 *)arg0 + 0x328) = 1;
            }
            break;
        }
        case 1: {
            Vec t = *(Vec *)(*(u8 **)((s8 *)arg0 + 0x2A8) + 0x2FC);
            f32 r;
            enemy_pursue_point(arg0, turn, &t, speed, (4e+01f));
            dist = horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x2FC);
            r = speed + *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 0xC);
            if (dist < r * r) {
                if (*(u16 *)((s8 *)arg0 + 0x338) == 0xFFFF) {
                    *(u8 **)((s8 *)arg0 + 0x2A8) = NULL;
                } else {
                    *(s16 *)((s8 *)arg0 + 0x328) = 0;
                }
            }
            break;
        }
        }
        if ((*(Param_800BE4C0 **)((s8 *)arg0 + 0x350))->f0 * (*(Param_800BE4C0 **)((s8 *)arg0 + 0x350))->f0 < dist) {
            *(u8 **)((s8 *)arg0 + 0x2A8) = NULL;
        }
    }
    ((TObjCollidable *)arg0)->update_collisions();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

#define TBL TObjGrass__bml_resource
#define T318 attack_params
#define IN_RANGE() (dist <= (r + T318->get_attack_range()) * (r + T318->get_attack_range()) && ang <= T318->get_attack_angle())
#define BIND(n) m_39e = (n); bind_enemy_combat_stats(NULL, TBL[m_39e], NULL); return 1;

s32 TObjGrass::is_target_in_attack_range() {
    f32 dist;
    TObjChara *t;
    s32 ang;
    f32 r;
    TObjChara *tgt;
    s32 i;
    u16 kind;
    Vec v;

    tgt = this->target;
    if (tgt != NULL && T318 != NULL && !(tgt->actorFlags & 0x02000800)) {
    if (test_actor_flags(0x2000) != 0) {
        BIND(2)
    }
    dist = calc_xz_distance_sq(this, target, &v);
    ang = angle_difference_abs(this->rotation_y, (s32)((10430.38043493439) * atan2_float(v.x, v.z)));
    t = this->target;
    if (t->bodies != NULL) {
        r = t->bodies->radius;
    } else {
        r = (1e+01f);
    }
    kind = ((TObjBase *)(t))->get_entity_id();
    if (kind < 0x1000) {
        t = this->target;
        if (((TObjPlayer *)t)->check_player_flag1() == 1 || (enable_v2_features == 1 && t->test_actor_flags(0x20) != 0)) {
            T318 = TBL[0];
            if (IN_RANGE()) {
                BIND(0)
            }
            return 0;
        }
        for (i = 0; i < 2; i++) {
            T318 = TBL[i];
            if (IN_RANGE()) {
                BIND(i)
            }
        }
    } else if (kind < 0x4000) {
        T318 = TBL[0];
        if (IN_RANGE()) {
            BIND(0)
        }
    }
    }
    return 0;
}

#undef BIND
#undef IN_RANGE
#undef T318
#undef TBL

void TObjGrass::run_attack_action() {

    switch (this->m_39e) {
    default:
        this->m_39e = 0;
    case 0:
        this->mode = 3;
        break;
    case 1:
        this->mode = 5;
        break;
    case 2:
        this->mode = 4;
        this->m_398 = (f32) (0.0f);
        TObjGrass__sub_800BFB68((O_800BFB68 *)(this));
        break;
    }
    this->phase = 0;
    this->requested_action = 1;
    this->actorFlags = (s32) (this->actorFlags | 0x200000);
    this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
}

void TObjGrass::sub_800BDD70() {
    u8 *arg0 = (u8 *)this;
    Vec sp20;
    Vec dst;
    Vec sp8;
    s32 ang;
    Vec *ent;
    s32 idx;
    ((TObjBase *)arg0)->clear_actor_flags(0x04040000);
    ((TObjMotion *)arg0)->advance_animation();
    switch (this->phase) {
    default:
        this->phase = 0;
    case 0:
        if (this->target == NULL) {
            this->actorFlags &= ~0x200000;
            this->timer = 0;
        } else {
            VecCopy((Vec *)&sp8, &this->target->body_center);
            subtract_vector(&sp8, (u8 *)&this->body_center);
            ang = ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((s8 *)this->movementParameters + 8), (Vec *)&sp8);
            apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
            if (ang < this->attack_params->get_attack_angle()) {
                this->phase = 1;
                if ((0.5f) < ((TObjChara *)arg0)->random_ratio()) {
                    this->requested_action = 2;
                } else {
                    this->requested_action = 3;
                }
            }
        }
        break;
    case 1:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(14.0f)) != 0) {
            if (*(VObj_800BDD70 * *)&this->target != NULL && (*(VObj_800BDD70 * *)&this->target)->m18(arg0, (1.0f)) != 0) {
                (*(VObj_800BDD70 * *)&this->target)->m20(arg0, (1.0f));
                (*(VObj_800BDD70 * *)&this->target)->m23(arg0);
            }
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3:
                play_sound_effect(0x4003A60D, &this->position, 0, 0);
                break;
            case AREA_BATTLE1:
            case AREA_BATTLE2:
                if (enable_v2_features == 1) {
                    play_sound_effect(0x30022, &this->position, 0, 0);
                }
                break;
            case AREA_PIONEER2_EP2:
                break;
            case AREA_VR_TEMPLE_ALPHA:
            case AREA_VR_TEMPLE_BETA:
                play_sound_effect(0x3A316, &this->position, 0, 0);
                break;
            }
        }
        if (this->frame < (2e+01f)) {
            switch (this->requested_action) {
            case 2:
                ent = lbl_805D5158->lookup(this->frame);
                idx = 0;
                break;
            case 3:
                ent = lbl_805D515C->lookup(this->frame);
                idx = 1;
                break;
            default:
                ent = NULL;
                break;
            }
            if (ent != NULL) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, this->rotation_y);
                scale_matrix(0, (1.3f), (1.3f), (1.3f));
                matrix_mult_vec_array(NULL, ent, &dst, 2);
                pop_matrix();
                if (((VObj_800BDD70 **)(arg0 + 0x3CC))[idx] != NULL) {
                    ((VObj_800BDD70 **)(arg0 + 0x3CC))[idx]->m4((s32 *)&dst, (s32 *)&sp20);
                }
            }
        }
        if (this->action_flags != 4U) {
            this->phase = 2;
            this->requested_action = 0;
            this->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
        (this->timer)--;
        if (this->timer < 0) {
            this->actorFlags &= ~0x200000;
            this->timer = 0;
        }
        break;
    }
    update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

#pragma push
#pragma opt_common_subs off
void TObjGrass::sub_800BD4D8() {
    Grass_800BD4D8 *o = (Grass_800BD4D8 *)this;
    if (o->client < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(o->client);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            o->target = (Tgt_800BD4D8 *)p;
        } else {
            o->target = NULL;
        }
    } else {
        o->client = 0xFFFF;
        o->target = NULL;
    }
    ((TObjBase *)o)->clear_actor_flags(0x40000);
    if (o->target == NULL) {
        o->client = 0xFFFF;
        ((TObjBase *)o)->clear_actor_flags(0x4202000);
        o->timer = 0;
        return;
    }
    switch (o->state) {
    default:
        o->state = 0;
    case 0:
        ((TObjBase *)o)->clear_actor_flags(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area(0x4003A801), o, &o->pos, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x200);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), (0.0f));
        if (o->target != NULL) {
            Vec v;
            s32 d;
            VecCopy((Vec *)&v, (const Vec *)&o->target->p2fc);
            subtract_vector(&v, &o->p2fc);
            d = ((TObjEnemy *)o)->turn_toward_direction((s32)((2.0f) * (f32)o->param->turn), (Vec *)&v);
            if (d < ((AttackParams *)(o->f318))->get_attack_angle()) {
                s32 ang = (s32)((10430.38043493439) * atan2_float(v.x, v.z));
                o->f398 = (3e+01f) + (newton_sqrtf(TObjPlayer::calc_distance_to_client(reinterpret_cast<const TObjBase *>(o), o->client, NULL)) + ((TObjCollidable *)o)->get_collision_body_radius(0));
                if (o->f398 < (1e+02f)) {
                    o->f398 = (1e+02f);
                }
                v.z = (0.0f);
                v.x = (0.0f);
                v.z = o->f398;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, ang);
                rotate_vector_by_matrix(0, &v, &v);
                pop_matrices(1);
                vec3_add_to(&v, &o->p2fc);
                if (select_enemy_destination(o, v, 1) != 0 || select_enemy_destination(o, o->target->p2fc, 1) != 0) {
                    o->state = 3;
                    o->fb8 = 7;
                    ((TObjBase *)o)->set_actor_flags(0x4000000);
                    ((TObjCollidable *)o)->set_indexed_flags(0, 0x80);
                    copy_position_if_valid(o, o->p2fc);
                    play_sound_effect(((TObjEnemy *)o)->remap_sound_for_area(0x4003A806), &o->pos, 0, 0);
                    TObjPlayer::play_effect_if_v2(-0x200);
                } else {
                    if (o->client == 0xFFFF) {
                        o->target = NULL;
                    } else {
                        o->state = 2;
                        o->fb8 = 0;
                        o->timer = 0x5A;
                    }
                    TObjGrass__sub_800BFB68((O_800BFB68 *)o);
                }
            }
        }
        break;
    case 3:
        ((TObjBase *)o)->set_actor_flags(0x4000000);
        ((TObjCollidable *)o)->set_indexed_flags(0, 0x80);
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), (0.0f));
        if (o->fb4 != 0x20) {
            o->state = 1;
            o->fb8 = 1;
            ((TObjBase *)o)->clear_actor_flags(0x4000000);
            ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        }
        break;
    case 1: {
        s32 k;
        s32 i;
        ((TObjBase *)o)->clear_actor_flags(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        ((TObjMotion *)o)->advance_animation();
        for (i = 0; i < 12; i++) {
            k = i * 4 + 0x3D4;
            if (*(VObj_18_800BD4D8 **)((u8 *)o + k) == NULL) {
                VObj_18_800BD4D8 *p = (VObj_18_800BD4D8 *)TObjPlayer::get_player_data(i);
                if (p == NULL) {
                    break;
                }
                if ((u16)((TObjBase *)(p))->get_entity_id() >= 0x1000) {
                    break;
                }
                if (obj_is_hit_receivable(reinterpret_cast<TObjCollidable *>(p)) != 0 && ((TObjCollidable *)o)->find_actor_body_contact(reinterpret_cast<TObjCollidable *>(p), (f32)((1e+04f))) != 0 &&
                    p->m18(o, (1.0f)) != 0) {
                    f32 dmg = p->m20(o, (1.0f));
                    ((TObjBase *)p)->set_actor_flags(0x400);
                    p->m23(o, (2.0f) * dmg);
                    if (is_split_screen() == 0 && local_client_id == (u16)((TObjBase *)(p))->get_entity_id()) {
                        TCameraCtrl::set_shake_preset(1);
                    }
                    *(VObj_18_800BD4D8 **)((u8 *)o + k) = p;
                }
            }
        }
        if (o->target != NULL) {
            Param_800BD4D8 *prm = o->param;
            f32 spd = (2.0f) * prm->speed;
            f32 d2;
            f32 t;
            if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                spd *= (2.0f);
            }
            ((TObjEnemy *)o)->enemy_turn_toward_dest((s32)((2.0f) * (f32)prm->turn));
            enemy_set_heading_velocity(spd, (TObjEnemy *)(o), o->angle);
            move_with_wall_slide(reinterpret_cast<TObjChara *>(o));
            d2 = horizontal_distance_squared(&o->f29c, &o->p2fc);
            if (o->client == 0xFFFF) {
                o->f3a4++;
            }
            t = spd + o->body->radius;
            if (d2 < t * t || o->param->range * o->param->range < d2 || (1.5e+02f) < (f32)o->f3a4) {
                if (o->client == 0xFFFF) {
                    o->target = NULL;
                } else {
                    o->state = 2;
                    o->fb8 = 0;
                    o->timer = 0x5A;
                }
                TObjGrass__sub_800BFB68((O_800BFB68 *)o);
                o->f3a4 = 0;
            }
        }
        play_persistent_sound(((TObjEnemy *)(o))->remap_sound_for_area(0x4003A300), o, &o->pos, 0, 0);
        if (o->f3a8 != 0) {
            Vec w;
            s32 ang[3];
            w.y = (0.0f);
            w.x = (0.0f);
            w.z = (4.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, o->angle);
            rotate_vector_by_matrix(0, &w, &w);
            pop_matrix();
            vec3_add_to(&o->f374, &w);
            ang[0] = -(s32)((10430.38043493439) * atan2_float(o->f310, newton_sqrtf(o->f308 * o->f308)));
            ang[1] = 0;
            ang[2] = (s32)((10430.38043493439) * atan2_float(o->f308, (0.0f)));
            spawn_directional_particle(&o->f374, ang, 0x150);
        }
        break;
    }
    case 2:
        ((TObjBase *)o)->clear_actor_flags(0x4000000);
        ((TObjCollidable *)o)->clear_player_status_flag(0, 0x80);
        o->fc8 = (2.0f) * o->anims[o->fb8].f8;
        ((TObjMotion *)o)->advance_animation();
        apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), (0.0f));
        o->timer--;
        if (o->timer < 0) {
            ((TObjBase *)o)->clear_actor_flags(0x200000);
            o->timer = 0;
            o->client = 0xFFFF;
            o->target = NULL;
        }
        break;
    }
    ((TObjCollidable *)o)->refresh_collision_body_centers();
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
}
#pragma pop

void TObjGrass::update_web_attack() {
    Grass_800BD10C *arg0 = (Grass_800BD10C *)this;
    Vec v;
    Vec v2;
    s32 ang[3];
    if (arg0->client < 0x1000) {
        TObjPlayer *p = get_player_by_client_id(arg0->client);
        if (p != NULL && p->get_floor() == get_current_floor()) {
            arg0->target = (Tgt_800BD10C *)p;
        } else {
            arg0->target = NULL;
        }
    } else {
        arg0->client = 0xFFFF;
        arg0->target = NULL;
    }
    ((TObjBase *)arg0)->clear_actor_flags(0x4040000);
    ((TObjMotion *)arg0)->advance_animation();
    switch (arg0->state) {
    case 0:
        if (arg0->target == NULL) {
            arg0->flags30 &= ~0x200000;
            arg0->timer = 0;
        } else {
            s32 d;
            VecCopy((Vec *)&v, (const Vec *)&arg0->target->p2fc);
            subtract_vector(&v, &arg0->p2fc);
            d = ((TObjEnemy *)arg0)->turn_toward_direction(arg0->f350[2], (Vec *)&v);
            apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
            if (d < TObjGrass__bml_resource[1]->get_attack_angle()) {
                arg0->state = 1;
                arg0->fb8 = 4;
                arg0->timer = 0;
            }
        }
        break;
    case 1:
        play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area(0x40039E07), arg0, &arg0->pos, 0, 0);
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
        if (arg0->target != NULL) {
            s32 d;
            VecCopy((Vec *)&v2, (const Vec *)&arg0->target->p2fc);
            subtract_vector(&v2, &arg0->p2fc);
            d = angle_difference_abs(arg0->rotY, (s32)((10430.38043493439) * atan2_float(v2.x, v2.z)));
            if (d < TObjGrass__bml_resource[1]->get_attack_angle()) {
                VecCopy((Vec *)&v2, (const Vec *)&arg0->target->pos);
                subtract_vector(&v2, &arg0->p380);
                ang[0] = (s32)((10430.38043493439) * atan2_float(v2.z, newton_sqrtf(v2.x * v2.x + v2.y * v2.y)));
                ang[1] = 0;
                ang[2] = -(s32)((10430.38043493439) * atan2_float(v2.x, v2.y));
                spawn_directional_particle(&arg0->p380, ang, 0xCA);
                if (arg0->fb4 != 4 && ((TObjCollidable *)arg0->target)->test_actor_flags(0x4000000) == 0) {
                    if (enable_v2_features == 1 && game_difficulty_selection == 3) {
                        arg0->target->m46(0);
                    } else {
                        new TObjGrassWeb(tl_05, (TObjCollidable *)arg0->target);
                    }
                }
            } else {
                arg0->fb4 &= ~4;
            }
        } else {
            arg0->fb4 &= ~4;
        }
        if (arg0->fb4 != 4) {
            arg0->state = 2;
            arg0->fb8 = 1;
            arg0->timer = 0xF;
        }
        break;
    case 2:
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
        arg0->timer--;
        if (arg0->timer < 0) {
            arg0->flags30 &= ~0x200000;
            arg0->timer = 0;
        }
        break;
    }
    update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0, &arg0->pos, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    minimap_render_dot(&arg0->pos, -0x5DB4, 1, 0);
}

void TObjGrass::run_miss_reaction() {
    if ((s16) this->mode != 6) {
        this->mode = 6;
        this->requested_action = 0;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFF9BFFFF);
}

void TObjGrass::update() {
    u8 *arg0 = (u8 *)this;
    s16 timer;

    ((TObjBase *)arg0)->clear_actor_flags((u32)(0x04040000));
    ((TObjMotion *)arg0)->advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), (0.0f));
    }
    update_collisions();
    play_persistent_sound(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0, &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
    timer = this->timer;
    this->timer = (timer - 1);
    if (timer < 0) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->timer = (s16) this->resetTimer;
        this->referenceHp = (s16) this->hp;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::run_hit_reaction() {
    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->requested_action = 5;
        this->actorFlags = (s32) (this->actorFlags & 0xFFFBFFFF);
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}

void TObjGrass::sub_800BCE44() {
    u8 *arg0 = (u8 *)this;
  CollisionBody *bodies;
  ((TObjBase *)arg0)->clear_actor_flags((u32)(0x04040000));
  ((TObjMotion *)arg0)->advance_animation();
  this->velocity.z = (f32) (0.0f);
  *((f32 *) (((s8 *) arg0) + 0x308)) = (f32) (0.0f);
  apply_actor_gravity((TObjEnemy *)((void *) arg0), (s32 *)(0), (f32) (0.0f));
  update_collisions();
  if (((TObjMotion *)arg0)->is_passing_frame((f32) (0.0f)) != 0)
  {
    play_sound_effect(remap_sound_for_area(0x4003A603), &this->position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
  }
  if ((this->action_flags) != 8U)
  {
    this->actorFlags = (s32) ((this->actorFlags) & 0xFFFFF9FF);
    bodies = this->bodies;
    bodies->flags &= 0xFBFFFFFF;
    if ((this->hp) < ((this->hpmax) * (this->parameters[0])))
    {
      this->actorFlags = (s32) ((this->actorFlags) | 0x2000);
      *((s32 *) (((s8 *) arg0) + 0x2A8)) = 0;
      this->targetId = (float) 0xFFFF;
      VecCopy((Vec *)(0x290 + arg0), (const Vec *)(arg0 + 0x2FC));
      VecCopy((Vec *)(arg0 + 0x29C), (const Vec *)(arg0 + 0x2FC));
      this->m_398 = (f32) (0.0f);
    }
    this->referenceHp = this->hp;
  }
  play_persistent_sound(remap_sound_for_area(0x4003A801), this, &this->position, 0, 0);
  TObjPlayer::play_effect_if_v2(-0x200);
  minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjGrass::run_death_reaction() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 8) {
        *(s16 *)((s8 *)arg0 + 0x326) = 8;
        *(s16 *)((s8 *)arg0 + 0x328) = 0;
        *(s16 *)((s8 *)arg0 + 0xB8) = 6;
        temp_r6 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xA4));
        *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xFFFF7FFE);
        spawn_particle_effect((const Vec *)(arg0 + 0x2FC), 0xF2);
        refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
    }
}

void TObjGrass::update_camera_vec_by_stage(NJS_OBJECT *) {
    Vec *v;

    switch (TObjGrass__render_node_index) {
    case 0x31:
        v = &grass_camera_vec;
        grass_camera_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 0x32:
        break;
    case 0x34:
        break;
    case 0x35:
        v = &grass_render_vec;
        grass_render_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    case 0x3F:
        break;
    case 0x49:
        break;
    case 0xC:
        v = &grass_origin_vec;
        grass_origin_vec.x = (0.0f);
        v->y = (0.0f);
        v->z = (0.0f);
        transform_vec_by_camera(&ninja_camera, v, v);
        break;
    }
    TObjGrass__render_node_index++;
}

#pragma push
#pragma opt_common_subs off
#define arg0 ((u8 *)this)
void TObjGrass::update_dying() {
    ((TObjBase *)arg0)->set_actor_flags(0x04040000);
    ((TObjMotion *)arg0)->advance_animation();
    switch (((TObjEnePanarms *)arg0)->phase) {
    default:
        ((TObjEnePanarms *)arg0)->phase = 0;
    case 0:
        apply_actor_gravity(this, (s32 *)(0), (0.0f));
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(0.0f)) != 0) {
            play_sound_effect(remap_sound_for_area(0x4003A804), &position, 0, 0);
            ((TObjEnePanarms *)arg0)->phase = 1;
        }
        break;
    case 1:
        move_with_wall_slide(this);
        *(f32 *)((s8 *)arg0 + 0x308) *= (0.5f);
        ((TObjEnePanarms *)arg0)->velocity.z *= (0.5f);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(23.0f)) != 0) {
            ((TObjEnePanarms *)arg0)->phase = 2;
            spawn_particle_effect((const Vec *)(arg0 + 0x38), 0xF0);
        }
        break;
    case 2:
        if (((TObjMotion *)arg0)->is_passing_frame((f32)(32.0f)) != 0) {
            Vec v;
            v.y = (0.0f);
            v.x = (0.0f);
            v.z = (-15.0f);
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, ((TObjEnePanarms *)arg0)->rotation_y);
            rotate_vector_by_matrix(0, &v, &v);
            pop_matrices(1);
            vec3_add_to(&v, arg0 + 0x38);
            switch (get_current_floor_area()) {
            case AREA_CAVE1:
            case AREA_CAVE2:
            case AREA_CAVE3: {
                new TObjCGrass(v, (s32)((12.0f) + *(f32 *)((s8 *)arg0 + 0x360)), 0xF0);
                break;
            }
            }
            play_sound_effect(remap_sound_for_area(0x4003AB0A), &position, 0, 0);
            TObjPlayer::spawn_dead_spot_default(&position, 0xA);
            spawn_ground_effect((const Vec *)(arg0 + 0x38), 0x1E);
        }
        ((TObjEnePanarms *)arg0)->scale.y -= 0.01f;
        if (((TObjEnePanarms *)arg0)->scale.y < 0.0f) {
            ((TObjEnePanarms *)arg0)->scale.y = 0.0f;
        }
        *(f32 *)((s8 *)arg0 + 0x35C) -= (0.01f);
        if (*(f32 *)((s8 *)arg0 + 0x35C) < (-5.0f)) {
            ((TObjEnePanarms *)arg0)->actorFlags |= 0x02000000;
            *(f32 *)((s8 *)arg0 + 0x35C) = (-5.0f);
            ((TObject *)arg0)->queue_destruction();
        }
        break;
    }
    if (((TObjEnePanarms *)arg0)->frame < (32.0f)) {
        (*(s32 *)((s8 *)arg0 + 0x3A0))++;
        if (*(s32 *)((s8 *)arg0 + 0x3A0) == 4) {
            *(s32 *)((s8 *)arg0 + 0x3A0) = 0;
            spawn_particle_effect((const Vec *)(arg0 + 0x38C), 0xF2);
        }
    }
}
#undef arg0
#pragma pop


void TObjGrass__sub_800BCA2C(void * _w0) {  }

TObjGrassWeb::TObjGrassWeb(TObject *parent, TObjCollidable *target) : TObjBase(parent) {
    if (target != NULL) {
        m_name = TObjGrassWeb__class_name;
        VecCopy(&position, &target->position);
        m_90 = 0;
        m_a4 = target->get_entity_id();
        set_params[0] = 0xB4;
    } else {
        TObject::queue_destruction();
    }
}

TObjGrassWeb::~TObjGrassWeb() {
}

void TObjGrassWeb::render() {  }

void TObjGrassWeb::run_task() {
    switch (this->m_90) {
    case 0:
        apply_to_player();
        return;
    case 1:
        TObjGrassWeb__sub_800BC798((Web_800BC798 *)this);
        return;
    default:
        queue_destruction();
        return;
    }
}

void TObjGrassWeb::apply_to_player() {
    TObjPlayer *player;

    this->m_90 = 1;
    player = get_player_by_client_id(this->m_a4);
    if ((player != NULL) && (TObjPlayer::is_locally_controlled(player) != 0) && (player->all_parents_unqueued_for_destruction() != 0) && (player->test_actor_flags(0x800) == 0)) {
        TObjPlayer::play_effect(player, this->set_params[0], 1);
    }
}

void TObjGrassWeb__sub_800BC798(Web_800BC798 *o) {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_persistent_sound(0x4003A809, o, &o->pos, 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            play_persistent_sound(0x3051E, o, &o->pos, 0, 0);
        }
        break;
    case AREA_PIONEER2_EP2:
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_persistent_sound(0x3A81D, o, &o->pos, 0, 0);
        break;
    }
    if (o->timer-- < 0) {
        o->state = 2;
    }
}
}

void TObjGrassWeb::queue_destruction() { TObject::queue_destruction(); }
