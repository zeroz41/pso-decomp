#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/SampledMotionPoints.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/enemy/gibbles/TObjEneGibbles.h"
#include "pso/technique/TTecZonde.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/moja/TObjEneMoja.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecMegid.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/unk/TLobby.h"

extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
s32 spawn_particle_effect(s32, s32);
struct Vec_800ACB58 { f32 x, y, z; };
s32 apply_actor_gravity(void *, int, f32);
}
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 spawn_dead_spot_scale15(void *, int);
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
extern u8 identity_matrix[];
}

typedef struct MojaCollision_800ADE48 {
    u8 pad[0x18];
    u32 flags;
} MojaCollision_800ADE48;

typedef struct Moja_800ADE48 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0xA4 - 0x34];
    MojaCollision_800ADE48 *collision;
    u8 padA8[0xB8 - 0xA8];
    s16 action;
    u8 padBA[0x326 - 0xBA];
    s16 mode;
    s16 phase;
    u8 pad32A[0x374 - 0x32A];
    s32 f374;
    u8 pad378[0x380 - 0x378];
    s32 attack_kind;
} Moja_800ADE48;

struct Vec_800AE18C { f32 x, y, z; };

struct Vec_800AEE54 { f32 x, y, z; };

struct V398Base_800ADAAC { char pad[0x18]; };

struct V398_800ADAAC : V398Base_800ADAAC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, void *);
};

struct Vec_800ADAAC { f32 x, y, z; };

struct VBase_18_247a8e { char pad[0x18]; };

struct VObj_18_247a8e : VBase_18_247a8e {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *);
};

struct Vec_800ACFE8 { f32 x, y, z; };
struct Hit_800ACFE8 { s32 a; f32 b; };
struct VBase_800ACFE8 { u8 pad[0x18]; };
struct VObj_800ACFE8 : VBase_800ACFE8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Hit_800ACFE8, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct Vec_800AE7F4 { f32 x, y, z; };

struct Hit_800AE7F4 {
    s32 a;
    f32 b;
};

struct VBase_800AE7F4 { char pad[0x18]; };

struct VObj_800AE7F4 : VBase_800AE7F4 {
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
    virtual void m21(void *, Hit_800AE7F4, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct FadeBase_800AF080 { u8 pad[0x14]; };

struct Fade_800AF080 : FadeBase_800AF080 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void m6(); virtual void m7();
    u32 f18;
};

struct Body_800AF080 { u8 pad[0x39C]; Fade_800AF080 fades[4]; };

struct EneBase_800AF080 { u8 pad[0x18]; };

struct Ene_800AF080 : EneBase_800AF080 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual s32 m9(f32, f32, f32);
};

struct Vec_800AE450 { f32 x, y, z; };

struct Hit_800AE450 {
    s32 a;
    f32 b;
};

struct VBase_800AE450 { char pad[0x18]; };

struct VObj_800AE450 : VBase_800AE450 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Hit_800AE450, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *);
};

struct Ang_800AD3D8 { s32 x, y, z; };

struct TgtBase_800AD3D8 { u8 pad[0x18]; };

struct Tgt_800AD3D8 : TgtBase_800AD3D8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Hit_800ACFE8, s32, s32, s32);
    u8 pad1C[0x2FC - 0x1C];
    Vec_800AE18C pos;
};

struct MojaInfo_800AD3D8 { u8 pad0[4]; f32 speed; s32 turn; };

struct Moja_800AD3D8 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x60 - 0x34];
    s32 rot_y;
    u8 pad64[0xB4 - 0x64];
    u32 anim_state;
    s16 anim;
    u8 padBA[0x2A8 - 0xBA];
    Tgt_800AD3D8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec_800AE18C pos;
    u8 pad308[0x318 - 0x308];
    u32 f318;
    u8 pad31C[0x328 - 0x31C];
    s16 phase;
    u8 pad32A[0x338 - 0x32A];
    u16 target_id;
    u8 pad33A[2];
    s16 timer;
    u8 pad33E[0x350 - 0x33E];
    MojaInfo_800AD3D8 *info;
    u8 pad354[0x368 - 0x354];
    s32 kind;
    u8 pad36C[0x384 - 0x36C];
    s32 count;
};

typedef struct Info_800AEBB8 {
    u8 pad0[4];
    f32 f4;
    s32 f8;
} Info_800AEBB8;

typedef struct Moja_800AEBB8 {
    u8 pad0[0x50];
    Vec_800AE18C pos;
    u8 pad5C[0x2FC - 0x5C];
    Vec_800AE18C f2FC;
    u8 pad308[0x328 - 0x308];
    s16 phase;
    u8 pad32A[0x350 - 0x32A];
    Info_800AEBB8 *info;
    u8 pad354[0x374 - 0x354];
    s32 f374;
} Moja_800AEBB8;

extern "C" {
s32 update_movement_status__9TObjCharaFv();
s32 update_action_hold_status__9TObjCharaFv();

f32 enemy_pursue_point(void *, s32, Vec_800AE18C *, void *, f32, f32);
s32 select_enemy_destination(void *, Vec_800AE18C *, int);
s32 copy_position_if_valid__10TObjPlayerFii(void *, Vec_800AE18C *);

f32 horizontal_distance_squared(int, void *);

u16 find_nearest_visible_player(void *, int, f32);
s32 check_path_obstructed(void *, void *);
u8 *get_player_data__10TObjPlayerFi(s32);
s32 obj_testFlags30__14TObjCollidableFUl(void *, int);
s32 get_entity_id(void *);
s32 get_current_floor();
u32 csnVector(void *, void *, int);
u8 *get_enemy_entity(u16);
s32 subtract_vector(void *, void *);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
s32 TObjPlayer__sub_800ACA0C(void *);

s32 minimap_render_dot(void *, int, int, int, f32);

f32 calc_xz_distance_sq(void *, void *, Vec_800AE18C *);
f32 atan2_float(f32, f32);
s32 angle_difference_abs(s32, s32);

s32 obj_is_hit_receivable();

s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
void set_matrix_identity(u8 *arg0);
s32 push_matrix();

s32 post_translate_matrix(void *);
s32 calc_velocity_toward_destination(void *, Vec_800ACFE8, Vec_800ACFE8, f32);
s16 get_attack_params_atp_min(s32);
s32 is_split_screen();
f32 newton_sqrtf(f32);

extern s32 local_client_id;
extern s32 lbl_805D5868;

s32 get_camera_mode__11TCameraCtrlFv();
s32 update__15RenderFadeStateFv(void *, s32, s32, s32);
s32 restore_scene_lighting(s32, s32);
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 translate_matrix(s32, f32, f32, f32);

s32 draw_chunk_object(s32);
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

s32 approach_angle_limited(s32, s32, s32);

extern Vec_800AE450 scratch_vec;

s32 enemy_turn_toward_dest(void *, s32);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);

void *spawn_directional_particle(void *pos, void *dir, s32 id);

extern s32 game_difficulty_selection;
extern s32 tl_07;

}

extern "C" {
void *__ct__11TObjControlFP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);
extern void *tl_04;
}

// The Moja's models and motions, and the archive that holds them; the second
// set is the one Ultimate loads.
const char *lbl_80491828[] = {
    "bm2c_s_moj_body.nj",
    "bm2f_s_moj_body.nj",
    "bm2w_s_moj_body.nj",
    NULL
};
const char *lbl_80491838[] = {
    "cstand_bm2c_s_moj_body.njm",
    "cwalk_bm2c_s_moj_body.njm",
    "damage_bm2f_s_moj_body.njm",
    "deadb_bm2f_s_moj_body.njm",
    "dead_bm2f_s_moj_body.njm",
    "giva_bm2f_s_moj_body.njm",
    "hoe_bm2f_s_moj_body.njm",
    "jump_bm2f_s_moj_body.njm",
    "punch_bm2f_s_moj_body.njm",
    "stand_bm2f_s_moj_body.njm",
    "walk_bm2f_s_moj_body.njm",
    NULL
};
BmlResourceDescriptor lbl_80491868 = { "bm_ene_bm2_moja.bml", lbl_80491828, lbl_80491838, 3, 11 };
const char *lbl_80491878[] = {
    "bm2c_s_moj_body.nj",
    "bm2f_s_moj_body.nj",
    "bm2w_s_moj_body.nj",
    NULL
};
const char *lbl_80491888[] = {
    "cstand_bm2c_s_moj_body.njm",
    "cwalk_bm2c_s_moj_body.njm",
    "damage_bm2f_s_moj_body.njm",
    "deadb_bm2f_s_moj_body.njm",
    "dead_bm2f_s_moj_body.njm",
    "giva_bm2f_s_moj_body.njm",
    "hoe_bm2f_s_moj_body.njm",
    "jump_bm2f_s_moj_body.njm",
    "punch_bm2f_s_moj_body.njm",
    "stand_bm2f_s_moj_body.njm",
    "walk_bm2f_s_moj_body.njm",
    NULL
};
BmlResourceDescriptor lbl_804918B8 = { "bm_ene_bm2_moja_a.bml", lbl_80491878, lbl_80491888, 3, 11 };

// The Moja's actions (TObjMotion::action_table).
TObjMotionAction lbl_804918C8[9] = {
    { 1, 0, 9, 0.5f, 0x1 },
    { 2, 2, 6, 0.7f, 0x20 },
    { 1, 0, 10, 0.6f, 0x1 },
    { 2, 0, 8, 0.7f, 0x4 },
    { 2, 0, 5, 0.4f, 0x4 },
    { 2, 0, 7, 0.5f, 0x4 },
    { 2, 0, 2, 0.8f, 0x8 },
    { 3, 7, 4, 0.7f, 0x10 },
    { 3, 7, 3, 0.7f, 0x10 }
};
MojaMovementParameters lbl_80491958[2] = {
    { 250.0f, 0.75f, 0x400, { 0x1E0000, 0, 0, 0 } },
    { 250.0f, 0.75f, 0x400, { 0, 0x1E0000, 0, 0 } }
};
CollisionBody lbl_80491990 = { { 0.0f, 20.0f, 0.0f }, 12.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f };

const char *TObjEneMoja__name = "TObjEneMoja";

// What load_resources sets up and free_resources releases: the combat stat
// blocks of the two variants, the archive and the punch's sampled trail.
void **lbl_805D50C8;
void **lbl_805D50CC;
void **lbl_805D50D0;
void **lbl_805D50D4;
BmlResource *lbl_805D50D8;
SampledMotionPoints *lbl_805D50DC;

// The collision flags the Moja gets back when it can be hit again.
static const s32 lbl_805D9BFC = 0x8001;

// The file is compiled -inline off,deferred, which emits the functions in the
// reverse of the order they are written in.
TObjEneMoja::TObjEneMoja(TObject *parent, void *setData) : TObjEnemy(parent) {
    m_name = TObjEneMoja__name;
    apply_set_data(setData);
    ((TObjPlayer *)this)->init_position_vectors();
    mode = 0;
    phase = 0;
    techniqueChance = 0.3f + parameters[1];
    if (techniqueChance < 0.0f) {
        techniqueChance = 0.0f;
    } else if (1.0f < techniqueChance) {
        techniqueChance = 1.0f;
    }
    jumpChance = 0.6f + parameters[2];
    if (jumpChance < 0.0f) {
        jumpChance = 0.0f;
    } else if (1.0f < jumpChance) {
        jumpChance = 1.0f;
    }
    ((TObjPlayer *)this)->clamp_stat_354();
    select_rare_variant();
    subtype = 1;
    action_table = lbl_804918C8;
    set_field_d8((s32)action_table);
    motion_list = lbl_805D50D8->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, &lbl_80491990, 1);
    attack = 0;
    bind_enemy_combat_stats((u8 *)lbl_805D50C8[variant], (u8 *)lbl_805D50CC[attack + variant * 3],
        (u8 *)lbl_805D50D0[variant]);
    movementParameters = &lbl_80491958[variant];
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    register_object_by_id();
    resetTimer = 0;
    timer = resetTimer;
    unused_37C = 0;
    attackSequence = -1;
    roar = 1;
    add_flags_2e4(1);
    actorFlags |= 0x40000;
    sinkOffset = 0.0f;
    unknown_398 = TUnk_80494968::create(0xFF303030, 0x0A303030);
    for (s32 i = 0; i < 4; i++) {
        unknown_39C[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneMoja::~TObjEneMoja() {
    if (unknown_398 != NULL) {
        unknown_398->queue_destruction();
        unknown_398 = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMoja::load_resources() {
    switch (game_difficulty_selection) {
    case 3: {
        void *memory = ::operator new(0x440);
        if (memory != NULL) {
            memory = load_resource_from_descriptor(memory, 1, &lbl_804918B8, 0, 0, 0);
        }
        lbl_805D50D8 = (BmlResource *)memory;
        break;
    }
    default: {
        void *memory = ::operator new(0x440);
        if (memory != NULL) {
            memory = load_resource_from_descriptor(memory, 1, &lbl_80491868, 0, 0, 0);
        }
        lbl_805D50D8 = (BmlResource *)memory;
        break;
    }
    }
    SampledMotionPoints *points = new SampledMotionPoints(2, 9.0f, 16.0f, 0.7f);
    lbl_805D50DC = points;
    Vec first;
    Vec second;
    first.x = first.y = first.z = 0.0f;
    second.x = -20.0f;
    second.y = 0.0f;
    second.z = 0.0f;
    points->sample_node_offsets((NJS_OBJECT *)lbl_805D50D8->models[1].model,
        (NJS_MOTION *)lbl_805D50D8->motions[lbl_804918C8[3].motion].motion, 38, &first, &second);
    lbl_805D50C8 = (void **)mem_alloc(8);
    lbl_805D50CC = (void **)mem_alloc(0x18);
    lbl_805D50D0 = (void **)mem_alloc(8);
    lbl_805D50D4 = (void **)mem_alloc(8);
    lbl_805D50C8[0] = TLobby::register_boss(0x49);
    lbl_805D50C8[1] = TLobby::register_boss(0x4A);
    lbl_805D50CC[0] = TLobby::dispatch_shared_handler_b(0x48);
    lbl_805D50CC[1] = TLobby::dispatch_shared_handler_b(0x49);
    lbl_805D50CC[2] = TLobby::dispatch_shared_handler_b(0x4A);
    lbl_805D50CC[3] = TLobby::dispatch_shared_handler_b(0x4B);
    lbl_805D50CC[4] = TLobby::dispatch_shared_handler_b(0x4C);
    lbl_805D50CC[5] = TLobby::dispatch_shared_handler_b(0x4D);
    lbl_805D50D0[0] = TLobby::register_object(0x48);
    lbl_805D50D0[1] = TLobby::register_object(0x49);
    lbl_805D50D4[0] = TLobby::dispatch_shared_handler_a(0x48);
    lbl_805D50D4[1] = TLobby::dispatch_shared_handler_a(0x49);
    s16 ids[3] = { 0x32, 0x33, 0x34 };
    MojaAnimationBinding binding = { lbl_805D50D8->motions, lbl_804918C8, 2, 9, 0 };
    for (s32 i = 0; i < 3; i++) {
        TLobby::spawn_npc_enemy(ids[i], lbl_805D50D8->models[i].model, (NJS_TEXLIST *)lbl_805D50D8->models[i].m_c,
            &binding, lbl_80491990.radius, 0.0f);
    }
}

void TObjEneMoja::free_resources() {
    if (lbl_805D50C8 != NULL) {
        mem_free(lbl_805D50C8);
        lbl_805D50C8 = NULL;
    }
    if (lbl_805D50CC != NULL) {
        mem_free(lbl_805D50CC);
        lbl_805D50CC = NULL;
    }
    if (lbl_805D50D0 != NULL) {
        mem_free(lbl_805D50D0);
        lbl_805D50D0 = NULL;
    }
    if (lbl_805D50D4 != NULL) {
        mem_free(lbl_805D50D4);
        lbl_805D50D4 = NULL;
    }
    if (lbl_805D50DC != NULL) {
        delete lbl_805D50DC;
        lbl_805D50DC = NULL;
    }
    if (lbl_805D50D8 != NULL) {
        free_bin_model_request(lbl_805D50D8, 1);
        lbl_805D50D8 = NULL;
    }
}

void *TObjEneMoja::create(void *arg0) {
    void *o;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    return new TObjEneMoja((TObject *)o, arg0);
}

void TObjEneMoja::run_task() {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r4;
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800ACA0C(arg0);
        return;
    }
    temp_r3 = this->targetId;
    if (temp_r3 < 0x1000U) {
        temp_r3_2 = (u8 *)(get_player_by_client_id(temp_r3));
        if (temp_r3_2 != NULL) {
            if (((TObjPlayer *)temp_r3_2)->get_floor() == get_current_floor()) {
                this->target = temp_r3_2;
                goto done;
            }
        }
        this->target = NULL;
    done:;
    } else if (temp_r3 < 0x4000U) {
        this->target = get_enemy_entity(temp_r3);
    } else {
        this->targetId = 0xFFFFU;
        this->target = NULL;
    }
    {
        switch (this->mode) {
        case 0:
            update_idle_state();
            break;
        case 1:
            update_appearance_jump();
            break;
        case 2:
            update_appearance_drop();
            break;
        case 3:
            update_approach_state();
            break;
        case 4:
            TObjEneMoja::update_punch_attack(arg0);
            break;
        case 5:
            TObjEneMoja::update_technique_state(arg0);
            break;
        case 6:
            update_attack_jump();
            break;
        case 7:
            ((TObjPlayer *)arg0)->update_invincibility();
            break;
        case 8:
            ((TObjPlayer *)arg0)->update_ground_effect();
            break;
        case 9:
            update_death_state();
            break;
        }
    }
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    submit_cursor_candidate(arg0, -1);
    temp_r4 = this->target;
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        this->attackSequence = -1;
        (this->timer) = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDFFFFF);
        this->target = NULL;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0, this->m_2b4++);
}

void TObjEneMoja::render() {
    Vec pos;
    Fade_800AF080 *fade;
    s32 cam;
    s32 vis;
    s32 draw;
    s32 id;
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    vis = ((Ene_800AF080 *)this)->m9(250.0f, 500.0f, 30.0f);
    if (vis == 0) {
        return;
    }
    select_actor_lighting(this);
    TObjFish::set_global_param(texlist);
    id = model_render_flags;
    fade = &((Body_800AF080 *)this)->fades[cam];
    saved_model_render_flags = id;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags = id | 1;
    update__15RenderFadeStateFv(fade, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask, id);
    draw = 1;
    if (((RenderFadeState *)fade)->updateFromCamera((const f32 *)&position) == 1) {
        fade->m6();
        if (defer_render__7TObjectFv(this) != 0) {
            draw = 0;
        } else {
            model_render_flags &= ~1;
        }
    }
    if (draw != 0) {
        set_motion_packed_rotation();
        push_matrix();
        translate_matrix(0, 0.0f, sinkOffset, 0.0f);
        post_translate_matrix(&position);
        rotate_matrix_y(0, (int)(rotation_y));
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object((s32)model);
        } else {
            TObjPlayer::toggle_particle_effect();
            if (vis == 1) {
                this->draw();
            } else {
                draw_motion_model();
            }
            TParticleCtrl::end_effect_render();
        }
        ((s32 (*)())pop_matrix)();
        clear_motion_packed_rotation();
    }
    model_render_flags &= ~1;
    if (((RenderFadeState *)fade)->updateFromCamera((const f32 *)&position) == 1) {
        fade->m7();
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    restore_scene_lighting(saved_chunk_polygon_flags_or_mask, saved_chunk_polygon_flags_and_mask);
    switch (mode) {
    case 0:
    case 1:
    case 9:
        break;
    default:
        pos.x = 2.0f;
        pos.y = 1.0f;
        pos.z = 2.0f;
        draw_ground_shadow(&pos, 0);
        break;
    }
}

// TObjChara's slot 28. Picks the nearest player or enemy it can reach as the
// target (inferred purpose; the slot has no evidenced name).
void TObjEneMoja::vfunc_28() {
    s32 best_id;
    s32 i;
    s32 id;
    u8 *p;
    f32 best;
    f32 d;
    u8 *q;
    u16 tid;
    if (appearance != 1 && ((mode != 0 && target == NULL) || is_actor_cadence_frame(0x1E) != 0)) {
        if (obj_testFlags30__14TObjCollidableFUl(this, 0x10) != 0) {
            i = 0;
            best_id = 0xFFFF;
            Vec_800AEE54 v = { 0.0f, 0.0f, 0.0f };
            best = ((MojaMovementParameters *)movementParameters)->unknown_00 * ((MojaMovementParameters *)movementParameters)->unknown_00;
            for (; i < registered_player_count + lbl_805D5870; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL) {
                    break;
                }
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != entity_id && !(*(s32 *)((s8 *)p + 0x30) & 0x02000800)) {
                    f32 xx;
                    f32 zz;
                    VecCopy((Vec *)&v, (const Vec *)(p + 0x2FC));
                    subtract_vector(&v, &m_2fc);
                    xx = v.x * v.x;
                    zz = v.z * v.z;
                    d = xx + zz;
                    if (d < best && check_path_obstructed(this, p + 0x2FC) != 1 && csnVector(&m_2fc, p + 0x2FC, -1) == 0U) {
                        best_id = id;
                        best = d;
                    }
                }
            }
            targetId = best_id;
        } else {
            targetId = find_nearest_visible_player(this, 0, ((MojaMovementParameters *)movementParameters)->unknown_00);
        }
        tid = targetId;
        if (tid < 0x1000U) {
            q = (u8 *)get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor()) {
                    target = q;
                    return;
                }
            }
            target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            target = get_enemy_entity(tid);
            return;
        }
        targetId = 0xFFFFU;
        target = NULL;
    }
}

s32 TObjEneMoja::update_action_hold_status() {
    void *temp_r3;
    if (update_action_hold_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->requested_action = 2;
            obj_clearFlags30(0x06040000);
            temp_r3 = this->bodies;
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneMoja::update_movement_status() {
    void *temp_r3;
    if (update_movement_status__9TObjCharaFv() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
            this->mode = 0;
            this->phase = 0;
            this->roar = 1;
            this->attackSequence = -1;
            (this->timer) = 0;
            this->appearance = 0;
            this->requested_action = 2;
            obj_clearFlags30(0x06040000);
            temp_r3 = this->bodies;
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
            break;
        }
        return 1;
    }
    return 0;
}

void TObjEneMoja::vfunc_58() {
    s32 temp_r0;

    temp_r0 = mode;
    if ((temp_r0 >= 3) || (temp_r0 < 0)) {
        phase = 0;
        roar = 1;
        (this->actorFlags) = (s32) ((this->actorFlags) | 0x40000);
    }
    switch (appearance) {
    case 0:
        mode = 0;
        this->requested_action = 2;
        return;
    case 1:
        mode = 1;
        this->requested_action = 5;
        return;
    default:
        mode = 0;
        this->requested_action = 0;
        return;
    }
}

void TObjEneMoja::update_idle_state() {
    Moja_800AEBB8 *self = (Moja_800AEBB8 *)this;
    switch (self->phase) {
    case 0:
    default: {
        Vec_800AE18C dest = self->pos;
        if (select_enemy_destination(self, &dest, 7) != 0) {
            Vec_800AE18C cur = self->f2FC;
            copy_position_if_valid__10TObjPlayerFii(self, &cur);
        }
        switch (self->f374) {
        case 0:
            self->phase = 1;
            break;
        }
        break;
    }
    case 1:
        advance_animation();
        ((TObjEnemy *)(self))->enemy_wander_home(self->info->f4, 100.0f, 100.0f, self->info->f8);
        break;
    }
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    ((TObjBase *)self)->obj_clearFlags30(0x200000);
}

void TObjEneMoja::update_appearance_jump() {
    Vec_800AE7F4 off;
    Vec_800AE7F4 tmp;
    Vec_800AE7F4 delta;
    f32 ticks;
    f32 dist;
    VObj_800AE7F4 *p;
    s32 i;
    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        off.x = 0.0f;
        off.y = -500.0f;
        off.z = 200.0f;
        ((s32 (*)(void *))push_matrix_from)(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &off, &off);
        pop_matrices(1);
        VecCopy((Vec *)&tmp, &home_position);
        subtract_vector(&tmp, &off);
        VecCopy(&position, (const Vec *)&tmp);
        if (is_passing_frame(8.0f) == 0) {
            return;
        }
        VecCopy((Vec *)&m_29c, &home_position);
        VecCopy((Vec *)&m_290, &position);
        VecCopy((Vec *)&delta, (const Vec *)&m_29c);
        subtract_vector(&delta, &position);
        rotation_y = (s32)(10430.38043493439 * atan2_float(delta.x, delta.z));
        jumpSpeed = newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
        ticks = 12.0f / play_speed;
        jumpSpeed = jumpSpeed / ticks;
        ((s32 (*)(void *, Vec_800AE7F4, Vec_800AE7F4, f32))calc_velocity_toward_destination)(this, *(Vec_800AE7F4 *)&m_290, *(Vec_800AE7F4 *)&m_29c, jumpSpeed);
        y_speed = delta.y / ticks;
        phase = 1;
        break;
    case 1:
        position.x += x_speed;
        position.y += y_speed;
        position.z += m_310;
        if (is_passing_frame(20.0f) == 0) {
            return;
        }
        phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = (VObj_800AE7F4 *)get_player_data__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if ((u16)get_entity_id(p) >= 0x1000) {
                break;
            }
            if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                dist = horizontal_distance_squared((int)((u8 *)p + 0x2FC), &m_2fc);
                if (dist <= 2500.0f) {
                    Hit_800AE7F4 hit;
                    hit.a = 0;
                    hit.b = 25.0f;
                    p->m21(this, hit, 0, -1, -1);
                    p->m23(this);
                }
                if (dist <= 10000.0f && !is_split_screen() && local_client_id == (u16)get_entity_id(p)) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xCB);
        ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xF0);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)remap_sound_for_area(0x3AD03), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= 0xF9DFFFFF;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
            appearance = 0;
        }
        break;
    }
}

void TObjEneMoja::update_appearance_drop() {
    f32 ticks;
    f32 dist;
    VObj_800AE450 *p;
    s32 i;
    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        VecCopy((Vec *)&scratch_vec, &home_position);
        subtract_vector(&scratch_vec, &position);
        rotation_y = approach_angle_limited(rotation_y,
            (s32)(10430.38043493439 * atan2_float(scratch_vec.x, scratch_vec.z)),
            ((MojaMovementParameters *)movementParameters)->unknown_08);
        if (rotation_y >= ((MojaMovementParameters *)movementParameters)->unknown_08) {
            return;
        }
        requested_action = 5;
        if (is_passing_frame(8.0f) == 0) {
            return;
        }
        VecCopy((Vec *)&m_29c, &home_position);
        VecCopy((Vec *)&m_290, &position);
        jumpSpeed = newton_sqrtf(scratch_vec.x * scratch_vec.x + scratch_vec.z * scratch_vec.z);
        ticks = 12.0f / play_speed;
        jumpSpeed = jumpSpeed / ticks;
        ((s32 (*)(void *, Vec_800AE450, Vec_800AE450, f32))calc_velocity_toward_destination)(this, *(Vec_800AE450 *)&m_290, *(Vec_800AE450 *)&m_29c, jumpSpeed);
        y_speed = scratch_vec.y / ticks;
        phase = 1;
        break;
    case 1:
        position.x += x_speed;
        position.y += y_speed;
        position.z += m_310;
        if (is_passing_frame(20.0f) == 0) {
            return;
        }
        phase = 2;
        for (i = 0; i < lbl_805D5868; i++) {
            p = (VObj_800AE450 *)get_player_data__10TObjPlayerFi(i);
            if (p == NULL) {
                break;
            }
            if ((u16)get_entity_id(p) >= 0x1000) {
                break;
            }
            if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                dist = horizontal_distance_squared((int)((u8 *)p + 0x2FC), &m_2fc);
                if (dist <= 2500.0f) {
                    Hit_800AE450 hit;
                    hit.a = 0;
                    hit.b = 25.0f;
                    p->m21(this, hit, 0, -1, -1);
                    p->m23(this);
                }
                if (dist <= 10000.0f && !is_split_screen() && local_client_id == (u16)get_entity_id(p)) {
                    TCameraCtrl::set_shake_preset(0);
                }
            }
        }
        ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xCB);
        ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xF0);
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)remap_sound_for_area(0x3AD03), &position, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= 0xF9DFFFFF;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
            appearance = 0;
        }
        break;
    }
}

void TObjEneMoja::vfunc_59() {
    MojaCollisionState *moja_collision_state;

    if ((s16) mode != 3) {
        mode = 3;
        switch ((s32) roar) {
        case 1:
            phase = 0;
            this->requested_action = 1;
            break;
        default:
            phase = 0;
            this->requested_action = 2;
            break;
        }
        attackSequence = -1;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FBFFFF);
        moja_collision_state = (*(MojaCollisionState * *)&this->bodies);
        moja_collision_state->flags = (s32) (moja_collision_state->flags | 1);
        appearance = 0;
    }
}

s32 TObjEneMoja::update_approach_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r4;
    u8 *temp_r7;
    switch (this->phase) {
    case 0:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)((void *) arg0, 0, 0.0f);
        if (((TObjMotion *)arg0)->is_passing_frame(0.0f) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD0A)), (u8 *)&this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (this->action_flags != 0x20U) {
            ((TObjEnemy *)arg0)->sub_800A7798(*(f32 *)((s8 *)lbl_805D50D4[(*(s32 *)&this->variant)] + 0xC));
            this->requested_action = 2;
            {
            Vec_800AE18C v = *(Vec_800AE18C *)(this->target + 0x2FC);
            if (select_enemy_destination(arg0, &v, 1) != 0) {
                Vec_800AE18C v2 = *(Vec_800AE18C *)(arg0 + 0x2FC);
                copy_position_if_valid__10TObjPlayerFii(arg0, &v2);
            }
            }
            this->phase = 1;
            this->roar = 0;
            (*(s16 *)&this->timer) = 0x96;
        }
        break;
    case 1:
    default:
        temp_r7 = this->target;
        if (temp_r7 != NULL) {
            Vec_800AE18C v3 = *(Vec_800AE18C *)(temp_r7 + 0x2FC);
            temp_r4 = (u8 *)lbl_805D50D4[(*(s32 *)&this->variant)];
            if (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 0) * *(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 0) < enemy_pursue_point(arg0, *(s32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 8), &v3, temp_r4, *(f32 *)((s8 *)temp_r4 + 8), 30.0f)) {
                this->target = NULL;
            }
            if (horizontal_distance_squared((int)(arg0 + 0x29C), (void *)(arg0 + 0x38)) < (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC)) * (*(f32 *)((s8 *)((*(u8 * *)&this->movementParameters)) + 4) + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC))
                || --(*(s16 *)&this->timer) < 0) {
                this->attackSequence = 0;
            }
        }
        if (((TObjMotion *)arg0)->is_passing_frame(4.0f) != 0 || ((TObjMotion *)arg0)->is_passing_frame((f32)(19.0f)) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3A801)), (u8 *)&this->position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
        break;
    }
    ((TObjMotion *)arg0)->advance_animation();
    ((TObjPlayer *)arg0)->update_collisions();
}

s32 TObjEneMoja::is_target_in_attack_range() {
    s32 angd;
    s32 lim;
    s32 i;
    f32 sq;
    f32 dist;
    f32 radius;
    u8 *t;
    u8 *c;
    Vec_800AE18C d;
    if (this->mode > 1 && (t = this->target) != NULL &&
        this->m_318 != 0 && !(*(u32 *)((s8 *)t + 0x30) & 0x02000800)) {
        dist = calc_xz_distance_sq(this, t, &d);
        angd = angle_difference_abs(this->rotation_y,
                                    (s32)(10430.38043493439 * atan2_float(d.x, d.z)));
        c = *(u8 **)(this->target + 0xA4);
        if (c != NULL) {
            radius = *(f32 *)((s8 *)c + 0xC);
        } else {
            radius = 10.0f;
        }
        for (i = 0; i < 3; i++) {
            this->m_318 = (u32)lbl_805D50CC[i + (this->variant) * 3];
            sq = (radius + ((AttackParams *)(this->m_318))->get_attack_range()) *
                 (radius + ((AttackParams *)(this->m_318))->get_attack_range());
            lim = ((AttackParams *)(this->m_318))->get_attack_angle();
            if (dist <= sq && angd <= lim) {
                this->attack = i;
                switch (this->attack) {
                case 0:
                    if (this->attackSequence == -1) {
                        this->attackSequence = 0;
                    }
                    return 1;
                case 1:
                    if (this->attackSequence != -1 && !(this->techniqueChance < 0.00001f)) {
                        if (((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) < this->techniqueChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec_800AE18C v = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec_800AE18C v2 = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            copy_position_if_valid__10TObjPlayerFii(this, &v2);
                        }
                    }
                    break;
                case 2:
                    if (this->attackSequence != -1) {
                        if (22500.0f < dist && ((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) < this->jumpChance) {
                            return 1;
                        }
                        this->attackSequence = -1;
                        {
                            Vec_800AE18C v = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            select_enemy_destination(this, &v, 1);
                        }
                        {
                            Vec_800AE18C v2 = *(Vec_800AE18C *)(((u8 *)this) + 0x2FC);
                            copy_position_if_valid__10TObjPlayerFii(this, &v2);
                        }
                    }
                    break;
                }
            }
        }
    }
    return 0;
}

void TObjEneMoja::vfunc_60() {
    Moja_800ADE48 *self = (Moja_800ADE48 *)this;
    switch (self->attack_kind) {
    case 2:
        self->mode = 6;
        self->action = 5;
        break;
    case 1:
        self->mode = 5;
        self->action = 2;
        break;
    case 0:
    default:
        self->mode = 4;
        self->action = 3;
        break;
    }
    self->phase = 0;
    self->flags |= 0x200000;
    self->flags &= 0xF9FBFFFF;
    self->collision->flags |= 1;
    self->f374 = 0;
}

#define arg0 ((u8 *)self_800ADAAC)
s32 TObjEneMoja::update_punch_attack(void *self_800ADAAC) {
    Vec_800ADAAC sp14;
    Vec_800ADAAC sp8;
    s32 t;
    s32 n;
    s32 i;
    u8 *p;
    V398_800ADAAC *o;
    s32 e;
    switch (*(s16 *)(arg0 + 0x328)) {
    case 0:
        ((TObjEnemy *)arg0)->sub_800A7798(*(f32 *)lbl_805D50D4[*(s32 *)(arg0 + 0x368)]);
        *(s16 *)(arg0 + 0x328) = 1;
    case 1:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjMotion *)arg0)->is_passing_frame(9.0f) != 0) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD04)), arg0 + 0x38, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        if (((TObjMotion *)arg0)->is_passing_frame(12.0f) != 0) {
            t = obj_testFlags30__14TObjCollidableFUl(arg0, 0x10);
            n = registered_player_count;
            if (t != 0) {
                n += lbl_805D5870;
            }
            for (i = 0; i < n; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL || p == arg0) {
                    break;
                }
                if ((obj_is_hit_receivable() != 0) && !(*(s32 *)(p + 0x30) & 0x02000800) && (((VObj_18_247a8e *)p)->m18(arg0, 1.0f) != 0)) {
                    ((VObj_18_247a8e *)p)->m20(arg0, 1.0f);
                    ((VObj_18_247a8e *)p)->m23(arg0);
                    if (0.5f < ((f32 (*)(void *))random_ratio__9TObjCharaFv)(arg0)) {
                        *(s32 *)(arg0 + 0x388) = 1;
                    }
                }
            }
        }
        if ((9.0f <= *(f32 *)(arg0 + 0xC0)) && (*(f32 *)(arg0 + 0xC0) <= 16.0f)) {
            e = (s32)lbl_805D50DC->lookup(((TObjMotion *)self_800ADAAC)->frame);
            if (e != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
                mult_vec_array__10TObjPlayerFUll(0, e, &sp8, 2);
                ((s32 (*)())pop_matrix)();
                o = *(V398_800ADAAC **)(arg0 + 0x398);
                if (o != NULL) {
                    o->m4(&sp8, &sp14);
                }
            }
        }
        if (*(u32 *)(arg0 + 0xB4) != 4U) {
            *(s32 *)(arg0 + 0x384) += 1;
            *(s16 *)(arg0 + 0x328) = 2;
            switch (*(s32 *)(arg0 + 0x388)) {
            case 1:
                *(s16 *)(arg0 + 0xB8) = 1;
                *(s16 *)(arg0 + 0x33C) = 0;
                break;
            default:
                *(s16 *)(arg0 + 0xB8) = 0;
                *(s16 *)(arg0 + 0x33C) = (s16)((f32 *)lbl_805D50D4[*(s32 *)(arg0 + 0x368)])[1];
                break;
            }
        }
        break;
    case 2:
        ((TObjMotion *)arg0)->advance_animation();
        if ((((TObjMotion *)arg0)->is_passing_frame(0.0f) != 0) && (*(s32 *)(arg0 + 0x388) == 1)) {
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD0A)), arg0 + 0x38, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x200);
        }
        if (*(u32 *)(arg0 + 0xB4) != 0x20U) {
            if ((f32)--*(s16 *)(arg0 + 0x33C) < 0.0f) {
                *(s16 *)(arg0 + 0x33C) = 0;
                *(s16 *)(arg0 + 0x328) = 1;
                *(s32 *)(arg0 + 0x388) = 0;
                *(u16 *)(arg0 + 0x338) = 0xFFFF;
                *(s32 *)(arg0 + 0x2A8) = 0;
                if (*(s32 *)(arg0 + 0x384) >= 3) {
                    *(s32 *)(arg0 + 0x384) = -1;
                }
                *(s32 *)(arg0 + 0x30) &= 0xFFDFFFFF;
            }
        }
        break;
    }
    ((s32 (*)(void *, s32, f32))apply_actor_gravity)(arg0, 0, 0.0f);
    ((TObjPlayer *)arg0)->update_collisions();
}
#undef arg0

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((Moja_800AD3D8 *)self_800AD3D8)
s32 TObjEneMoja::update_technique_state(void *self_800AD3D8) {
    Vec_800AE18C dir;
    Vec_800AE18C pos;
    Ang_800AD3D8 ang;
    s32 ang2;
    void *obj;
    u8 *p;
    s32 a;
    u16 id;
    id = self->target_id;
    if (id < 0x1000) {
        p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor() &&
            ((TObjBase *)self)->get_room() == ((TObjBase *)p)->get_room()) {
            self->target = (Tgt_800AD3D8 *) p;
        } else {
            self->target = NULL;
        }
    } else if (id < 0x4000) {
        self->target = (Tgt_800AD3D8 *) get_enemy_entity(id);
    } else {
        self->target_id = 0xFFFF;
        self->target = NULL;
    }
    ((TObjMotion *)self)->advance_animation();
    switch (self->phase) {
    case 0:
    default:
        if (self->target == NULL) {
            self->phase = 2;
            self->count = -1;
            self->flags &= 0xFFDFFFFF;
        } else {
            Vec_800AE18C dest = self->target->pos;
            if (select_enemy_destination(self, &dest, 1) != 0) {
                Vec_800AE18C cur = self->pos;
                copy_position_if_valid__10TObjPlayerFii(self, &cur);
                a = enemy_turn_toward_dest(self, self->info->turn);
                enemy_set_heading_velocity(self->info->speed, (TObjEnemy *)((TObjEnemy *)((u8 *)self)), self->rot_y);
                move_with_wall_slide((u8 *)self);
            } else {
                VecCopy((Vec *)&dir, (const Vec *)&self->target->pos);
                subtract_vector(&dir, &self->pos);
                a = ((TObjEnemy *)self)->turn_toward_direction(self->info->turn, (Vec *)&dir);
            }
            if (a < 0x100) {
                self->phase = 1;
                self->anim = 4;
            } else {
                self->anim = 2;
            }
        }
        break;
    case 1:
        if (((TObjMotion *)self)->is_passing_frame(22.0f) != 0) {
            pos.x = 0.0f;
            pos.y = 3.0f;
            pos.z = 17.0f;
            ((s32 (*)(void *))push_matrix_from)(identity_matrix);
            rotate_matrix_y(0, self->rot_y);
            ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &pos, &pos);
            pop_matrices(1);
            ((void (*)(void *, void *))vec3_add_to)(&pos, &self->pos);
            if (self->target != NULL) {
                VecCopy((Vec *)&dir, (const Vec *)&self->target->pos);
                subtract_vector(&dir, &self->pos);
                ang2 = ((TObjEnemy *)self)->turn_toward_direction(self->info->turn, (Vec *)&dir);
            } else {
                ang2 = ((AttackParams *)(self->f318))->get_attack_angle();
            }
            if (game_difficulty_selection == 3) {
                switch (self->kind) {
                case 1:
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2 && self->target != NULL) {
                        TTecMegid::create((s32)self, (s32)&pos, (s32)&self->target->pos, (s32)(((TObjEneMoja *)self)->calc_technique_level()));
                    } else {
                        TTecMegid::create_ex((s32)self, (s32)&pos, self->rot_y, (s32)(((TObjEneMoja *)self)->calc_technique_level()));
                    }
                    ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) 0x4002A60B, &pos, 0, 0);
                    break;
                default:
                    ((s32 (*)(void *, int))spawn_particle_effect)(&pos, 0xB9);
                    ((s32 (*)(void *, int))spawn_particle_effect)(&pos, 0xBA);
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2) {
                        if (((TObjBoss2Tunnel *)(&dir))->update_scale() < 0.00001f) {
                            dir.y = dir.x = 0.0f;
                            dir.z = 1.0f;
                            ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                            rotate_matrix_y(0, self->rot_y);
                            ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                            ((s32 (*)())pop_matrix)();
                        }
                        if (self->target != NULL) {
                            Hit_800ACFE8 hit;
                            hit.a = 3;
                            hit.b = 20.0f * (f32) ((TObjEneMoja *)self)->calc_technique_level() + 240.0f;
                            self->target->m21(self, hit, 0, -1, -1);
                        }
                    } else {
                        dir.y = dir.x = 0.0f;
                        dir.z = 1.0f;
                        ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                        rotate_matrix_y(0, self->rot_y);
                        ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                        ((s32 (*)())pop_matrix)();
                    }
                    obj = __nw__7TObjectFUl(0x260);
                    if (obj != NULL) {
                        ((TTecZonde *)obj)->construct_bolt_effect((u8 *)tl_07, (u8 *)&pos, (u8 *)&dir, 0x14000000, 20, (f32)(((AttackParams *)(self->f318))->get_attack_range()), 1.8f);
                    }
                    ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *) 0x4002A408, &pos, 0, 0);
                    break;
                }
            } else {
                switch (self->kind) {
                case 1:
                    ((TTecGiBarta *)self)->create_ex(&pos, (void *)self->rot_y, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    break;
                default:
                    if (ang2 < ((AttackParams *)(self->f318))->get_attack_angle() / 2 && self->target != NULL) {
                        TTecFoie::create_ex((void *)self, &pos, &self->target->pos, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    } else {
                        TTecFoie::create((void *)self, &pos, (void *)self->rot_y, (void *)(((TObjEneMoja *)self)->calc_technique_level()));
                    }
                    break;
                }
                dir.y = dir.x = 0.0f;
                dir.z = 1.0f;
                ((s32 (*)(void *))push_matrix_from)(identity_matrix);
                rotate_matrix_y(0, self->rot_y);
                ((s32 (*)(int, void *, void *))rotate_vector_by_matrix)(0, &dir, &dir);
                pop_matrices(1);
                {
                    f32 xx = dir.x * dir.x;
                    f32 yy = dir.y * dir.y;
                    ang.x = (s32) (10430.38043493439 * atan2_float(dir.z, newton_sqrtf(xx + yy)));
                }
                ang.y = 0;
                ang.z = -(s32) (10430.38043493439 * atan2_float(dir.x, dir.y));
                spawn_directional_particle(&pos, &ang, 0xCC);
                ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(self))->remap_sound_for_area((s32)(0x3E405)), &pos, 0, 0);
            }
        }
        if (self->anim_state != 4) {
            self->phase = 2;
            self->timer = 30;
        }
        break;
    case 2:
        self->count++;
        if (self->count >= 2) {
            self->count = -1;
            self->flags &= 0xFFDFFFFF;
        } else {
            self->phase = 0;
            self->timer = 0;
        }
        break;
    }
    ((s32 (*)(void *, s32, f32))apply_actor_gravity)(self, 0, 0.0f);
    ((TObjPlayer *)self)->update_collisions();
}
#undef self
#pragma pop

void TObjEneMoja::update_attack_jump() {
    Vec_800ACFE8 delta;
    u8 *p;
    s32 i;
    f32 d;

    actorFlags |= 0x06000000;
    bodies->flags &= ~1;
    advance_animation();
    switch (phase) {
    case 0:
    default:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, 0.0f);
        if (is_passing_frame(8.0f) != 0) {
            if (target != NULL) {
                Vec_800ACFE8 dest = *(Vec_800ACFE8 *)(target + 0x2FC);
                if (select_enemy_destination(this, (Vec_800AE18C *)&dest, 1) != 0) {
                    Vec_800ACFE8 pos = *(Vec_800ACFE8 *)&m_2fc;
                    copy_position_if_valid__10TObjPlayerFii(this, (Vec_800AE18C *)&pos);
                    VecCopy((Vec *)&delta, (const Vec *)&m_29c);
                    subtract_vector(&delta, &m_2fc);
                    jumpSpeed = -20.0f + newton_sqrtf(delta.x * delta.x + delta.z * delta.z);
                    jumpSpeed = jumpSpeed / (12.0f / play_speed);
                    phase = 1;
                } else {
                    phase = 2;
                }
            } else {
                phase = 2;
            }
            ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xF3);
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)remap_sound_for_area(0x3A802), &position, 0, 0);
        }
        break;
    case 1:
        calc_velocity_toward_destination(this, *(Vec_800ACFE8 *)&m_290, *(Vec_800ACFE8 *)&m_29c, jumpSpeed);
        move_with_wall_slide((u8 *)this);
        if (is_passing_frame(20.0f) != 0) {
            phase = 2;
            for (i = 0; i < lbl_805D5868; i++) {
                p = get_player_data__10TObjPlayerFi(i);
                if (p == NULL || (u16)get_entity_id(p) >= 0x1000) {
                    break;
                }
                if (((s32 (*)(void *))obj_is_hit_receivable)(p) != 0) {
                    d = horizontal_distance_squared((s32)(p + 0x2FC), &m_2fc);
                    if (d <= ((AttackParams *)(m_318))->get_damage_radius() * ((AttackParams *)(m_318))->get_damage_radius()) {
                        Hit_800ACFE8 hit;
                        hit.a = 0;
                        hit.b = get_attack_params_atp_min(m_318);
                        ((VObj_800ACFE8 *)p)->m21(this, hit, 0, -1, -1);
                        ((VObj_800ACFE8 *)p)->m23(this);
                    }
                    if (d <= 10000.0f && is_split_screen() == 0 && local_client_id == (u16)get_entity_id(p)) {
                        TCameraCtrl::set_shake_preset(0);
                    }
                }
            }
            ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xCB);
            ((s32 (*)(void *, int))spawn_particle_effect)(&position, 0xF0);
            ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)remap_sound_for_area(0x3AD03), &position, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x300);
        }
        break;
    case 2:
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, 0.0f);
        if (action_flags != 4) {
            actorFlags &= ~0x06200000;
            bodies->flags |= 1;
            attackSequence = -1;
            timer = 0;
        }
        break;
    }
}

void TObjEneMoja::vfunc_61() {

    switch (mode) {
    case 4:
        (this->actorFlags) &= 0xFFFFFEFF;
        ((*(MojaCollisionState * *)&this->bodies))->flags |= lbl_805D9BFC;
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 7;
        (this->timer) = 0xF;
    case 7:
        this->requested_action = 0;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFF9BFFFF);
        break;
    }
    appearance = 0;
}

void TObjPlayer::update_invincibility() {
    s16 temp_r4;

    advance_animation();
    if (!(this->actorFlags & 0x800000)) {
        ((s32 (*)(void *, s32, f32))apply_actor_gravity)(this, 0, 0.0f);
    }
    update_collisions();
    temp_r4 = *(s16 *)&this->unk_33C;
    *(s16 *)&this->unk_33C = (temp_r4 - 1);
    if (temp_r4 < 0) {
        this->actorFlags &= 0xFFFFFEFF;
        *(s32 *)((s8 *)this->bodies + 0x18) |= lbl_805D9BFC;
        *(s16 *)&this->unk_33C = (s16) *(s16 *)((s8 *)this + 0x33A);
        this->m_33e = (s16) this->hp;
    }
}

void TObjEneMoja::vfunc_62() {
    MojaCollisionState *moja_collision_state;

    switch (mode) {
    case 4:
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xF9FFF9FF);
        moja_collision_state = (*(MojaCollisionState * *)&this->bodies);
        moja_collision_state->flags = (s32) (moja_collision_state->flags & 0xFBFFFFFF);
        referenceHp = (s16) hp;
        roar = 0;
        break;
    default:
        mode = 8;
    case 8:
        this->requested_action = 6;
        (this->actorFlags) = (s32) ((this->actorFlags) & 0xFFDBFFFF);
        break;
    }
    appearance = 0;
}

void TObjPlayer::update_ground_effect() {
    u8 *temp_r4;

    advance_animation();
    if (is_passing_frame(0.0f) != 0) {
        ((s32 (*)(void *, void *, int, int))play_sound_effect)((void *)((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x3A807)), (void *) (((u8 *)this) + 0x38), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
    }
    this->m_310 = 0.0f;
    *(f32 *)&this->unk_308 = 0.0f;
    apply_actor_gravity(this, 0, 0.0f);
    this->update_collisions();
    if ((u32) this->action_flags != 8U) {
        this->actorFlags = (s32) (this->actorFlags & 0xFBFFF9FF);
        temp_r4 = (unsigned char *) (this->bodies);
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFBFFFFFF);
        this->m_33e = (s16) this->hp;
        *(s32 *)&this->unk_388 = 0;
    }
}

void TObjEneMoja::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    if ((s16) this->mode != 9) {
        this->mode = 9;
        this->requested_action = 7;
        temp_r6 = (u8 *)this->bodies;
        *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xFFFF7FFE);
        spawn_particle_effect((s32)(arg0 + 0x2FC), 0xF1);
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        this->appearance = 0;
    }
}

void TObjEneMoja::update_death_state() {
    u8 *arg0 = (u8 *)this;
    Vec_800ACB58 v;

    ((TObjMotion *)arg0)->advance_animation();
    if (((TObjMotion *)arg0)->is_passing_frame(0.0f) != 0) {
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3A809)), (u8 *)&this->position, 0, 0);
    }
    if (((TObjMotion *)arg0)->is_passing_frame((f32)27.0f) != 0) {
        v.x = 0.0f;
        v.y = 10.0f;
        v.z = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->rotation_y);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        vec3_add_to(&v, (u8 *)&this->position);
        play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD03)), &v, 0, 0);
        TObjPlayer::play_effect_if_v2(-0x300);
        spawn_particle_effect((s32) &v, 0xF0);
        spawn_dead_spot_scale15(&v, 0x14);
        ((TObjPlayer *)(&v))->spawn_effect_at_ground(0x32);
    }
    if (this->frame < 0.5f * (30.0f * this->play_speed)) {
        move_with_wall_slide(arg0);
        (*(f32 *)&this->unk_308) *= 0.5f;
        this->m_310 *= 0.5f;
    } else if (!((this->actorFlags) & 0x800000)) {
        apply_actor_gravity(arg0, 0, 0.0f);
    }
    this->sinkOffset -= 0.1f;
    if (this->sinkOffset < -20.0f) {
        queue_destruction();
    }
}

void TObjEneMoja::select_rare_variant() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = (this->variant);
    if (temp_r0 >= 1) {
        (this->variant) = 1;
        ((TObjEnemy *)arg0)->set_param(2);
        ((TObjEneMoja *)arg0)->bindModel(2);
        return;
    }
    if (temp_r0 <= 0) {
        if (random_ratio__9TObjCharaFv((s32) arg0) < 0.002f) {
            (this->variant) = 1;
            ((TObjEnemy *)arg0)->set_param(2);
            ((TObjEneMoja *)arg0)->bindModel(2);
            return;
        }
        (this->variant) = 0;
        ((TObjEnemy *)arg0)->set_param(1);
        ((TObjEneMoja *)arg0)->bindModel(1);
    }
}

void TObjPlayer::clamp_stat_354() {
    f32 lo = 0.0f;
    if (this->m_354 < lo) {
        this->m_354 = lo;
    } else if (1.0f < this->m_354) {
        this->m_354 = 1.0f;
    }
    *(s32 *)&this->m_374 = (s32) this->m_354;
}
