#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/merilllia/TObjEneMerillLia.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"


#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/TObjControl.h"
#include "pso/technique/TTecKafun.h"

#include "pso/system/vector.h"

#include "pso/render/TUnk_80494938.h"

struct Obj_800D5614 { u8 pad0[0x38]; u8 pos[0xC]; u8 pad44[0x2A8 - 0x44]; void *f2a8; u8 pad2ac[0x326 - 0x2AC]; s16 f326; s16 f328; u8 pad32a[0x338 - 0x32A]; u16 f338; u8 pad33a[0x350 - 0x33A]; f32 *f350; u8 pad354[0x3D0 - 0x354]; f32 f3d0; };
struct Pl_800D5614 { u8 pad0[0x38]; u8 pos[0xC]; };

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/text_800D8830.h"
#include "pso/math/ScratchVectors.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/MatrixTransforms.h"

#pragma readonly_strings on

struct RecoveredGlobal_800D5060_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_800D5060_lbl_8058D490_size, sizeof(RecoveredGlobal_800D5060_lbl_8058D490) == 0x30);

struct RecoveredFields_800D6810_arg0
{
  u8 unknown_0[0x24];
  s32 field_24;
  u8 unknown_28[0xC];
  s32 field_34;
  u8 unknown_38[0x28];
  s32 field_60;
  u8 unknown_64[0x2C2];
  s16 field_326;
  u8 unknown_328[0x58];
  f32 field_380;
};

struct E_800D7274 { s32 f0; s32 f4; s32 f8; s32 fc; };

struct D_800D7274 { u8 pad[0x42c]; E_800D7274 *entries; };

struct O_800D7274 { u8 pad[0x24]; s32 f24; u8 pad2[0xc]; s32 f34; };

struct Sub_800D5100 { u8 pad[0x18]; s32 f18; };

struct Obj_800D5150 { u8 pad[0x334]; s32 f334; u8 pad2[0x368 - 0x338]; s32 f368; };

struct Obj_800D5570 { u8 pad0[0x38]; u8 sub38[0xB8 - 0x38]; s16 fb8; u8 padba[0x326 - 0xBA]; s16 f326; s16 state; };

typedef struct Ene_800D51C8 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Ene_800D51C8;

struct Base_800D64F0 {
    char pad[0x1C];
};

struct Ene_800D64F0 : Base_800D64F0 {
    u8 pad1C[0xB4 - 0x1C];
    u32 fB4;
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 sub;
    u8 pad32A[0x338 - 0x32A];
    s16 target;
    u8 pad33A[0x350 - 0x33A];
    f32 *param;
    u8 pad354[0x390 - 0x354];
    s32 f390;
};

typedef struct Ene_800D52DC {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 state;
    s16 f328;
    u8 pad32A[0x34C - 0x32A];
    void *f34C;
} Ene_800D52DC;

struct Vec_800D57C8 { s32 x, y, z; };

struct VBase_18_800D6110 { char pad[0x1C]; };

struct VObj_18_800D6110 : VBase_18_800D6110 {
};

struct Pl_800D6110 { u8 pad0[0x38]; Vec pos; u8 pad44[0x2FC - 0x44]; Vec p2fc; };

struct Model_800D6110 { u8 pad0[0xC]; f32 radius; u8 pad10[8]; u32 flags; };

struct Obj_800D6110 : VObj_18_800D6110 {
    u8 pad1C[0x38 - 0x1C]; Vec pos; u8 pad44[0xA4 - 0x44]; Model_800D6110 *model;
    u8 padA8[0xB8 - 0xA8]; s16 fb8; u8 padBA[0x2A8 - 0xBA]; Pl_800D6110 *f2a8;
    u8 pad2ac[0x308 - 0x2AC]; u8 ang308[0x326 - 0x308]; s16 f326; s16 f328;
    u8 pad32a[0x338 - 0x32A]; u16 f338; u8 pad33a[0x350 - 0x33A]; f32 *f350;
    u8 pad354[0x374 - 0x354]; s16 f374; u8 pad376[0x398 - 0x376]; f32 f398;
    u8 pad39c[0x3D4 - 0x39C]; f32 f3d4;
};

struct Param_800D5BCC { u8 pad0[4]; f32 speed; s32 turn; };

struct Sub_800D5BCC { u8 pad0[0xC]; f32 fC; };

struct Lia_800D5BCC {
    u8 pad0[0x38];
    Vec pos;
    Vec prev;
    Vec home;
    u8 pad5C[0x60 - 0x5C];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Sub_800D5BCC *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec f290;
    Vec f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec f2FC;
    u8 pad308[0x328 - 0x308];
    s16 state;
    u8 pad32A[0x348 - 0x32A];
    Lia_800D5BCC *partner;
    u8 pad34C[0x350 - 0x34C];
    Param_800D5BCC *param;
    u8 pad354[0x358 - 0x354];
    f32 f358;
    u8 pad35C[0x378 - 0x35C];
    s32 f378;
    s32 count;
    u8 pad380[0x394 - 0x380];
    f32 f394;
};

void move_with_wall_slide(u8 *arg0);

extern "C" {
void TObjPlayer__sub_800D92BC(s32 point, s32 delay);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
extern RecoveredGlobal_800D5060_lbl_8058D490 identity_matrix;
s32 get_current_floor();
f32 xz_distance_squared(void *, void *);
void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);
f32 post_translate_matrix(void *);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void **TObjEneMerillLia__rock_stats_table;
void **merill_lia_rock_buffer;
void **merill_lia_rock_aux_buffer;
uaddr TObjEneMerillLia__rock_param_table;
uaddr TObjEneMerillLia__entry_params_resource;
extern s32 game_difficulty_selection;
s32 minimap_render_dot(void *, int, int, int);
s32 matrix_mult_vec(int, void *, void *);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
extern "C" {
s32 enemy_move_toward(void *, s32, void *, int, f32);
f32 horizontal_distance_squared(void *, void *);
extern s32 actor_frame_tick;
f32 enemy_backstep_from_point(void *, void *, f32);
f32 fabs_float(f32);
f32 atan2_float(f32 y, f32 x);
void link_chain_nodes__10TObjPlayerFPvPvPv(void *, void *, void *);
s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, s32);
void free_collision_body_parts(void *);

const char *lbl_804944D0[3] = {
    "re8_b_beast_wola_body.nj", "re8_b_srbeast_wola_body.nj", 0,
};
const char *lbl_804944DC[13] = {
    "appear_re8_b_beast_wola_body.njm", "atk_a_re8_b_beast_wola_body.njm", "atk_b_re8_b_beast_wola_body.njm", "damage_re8_b_beast_wola_body.njm",
    "dead_re8_b_beast_wola_body.njm", "stand_re8_b_beast_wola_body.njm", "wait_re8_b_beast_wola_body.njm", "wakeup_re8_b_beast_wola_body.njm",
    "walk_re8_b_beast_wola_body.njm", "run_bm1_s_wala_body.njm", "kahun_re8_b_beast_wola_body.njm", "umari_re8_b_beast_wola_body.njm",
    0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_resource_descriptor = {
    "bm_ene_re8_merill_lia.bml", lbl_804944D0, lbl_804944DC, 2, 12,
};
const char *lbl_80494520[3] = {
    "lo_re8_b_beast_wola_body.nj", "lo_re8_b_srbeast_wola_body.nj", 0,
};
const char *lbl_8049452C[13] = {
    "appear_re8_b_beast_wola_body.njm", "atk_a_re8_b_beast_wola_body.njm", "atk_b_re8_b_beast_wola_body.njm", "damage_re8_b_beast_wola_body.njm",
    "dead_re8_b_beast_wola_body.njm", "stand_re8_b_beast_wola_body.njm", "wait_re8_b_beast_wola_body.njm", "wakeup_re8_b_beast_wola_body.njm",
    "walk_re8_b_beast_wola_body.njm", "run_bm1_s_wala_body.njm", "kahun_re8_b_beast_wola_body.njm", "umari_re8_b_beast_wola_body.njm",
    0,
};
BmlResourceDescriptor bm_ene_re8_merill_lia_low_resource_descriptor = {
    "bm_ene_re8_merill_lia_low.bml", lbl_80494520, lbl_8049452C, 2, 12,
};
const char *TObjEneMerillLia__class_name = "TObjEneMerillLia";
void *lbl_80494570[56] = {
    (void *)0x10000, (void *)0x5, (void *)0x3f19999a, (void *)0x1,
    (void *)0x10001, (void *)0x6, (void *)0x3f4ccccd, (void *)0x1,
    (void *)0x10002, (void *)0x8, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f800000, (void *)0x4,
    (void *)0x10000, (void *)0x9, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x8,
    (void *)0x20000, (void *)0x7, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x5, (void *)0x3f19999a, (void *)0x20,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x20,
    (void *)0x20000, (void *)0xa, (void *)0x3f333333, (void *)0x4,
    (void *)0x20001, (void *)0xb, (void *)0x3f19999a, (void *)0x20,
};
void *lbl_80494650[21] = {
    (void *)0x43610000, (void *)0x3ecccccd, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f0ccccd, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f333333,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *lbl_804946A4[33] = {
    (void *)0x0, (void *)0x40f00000, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x40f00000, (void *)0x0, (void *)0x41000000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};

// The motion set TLobby::spawn_npc_enemy copies for each spawned part.

// One 0x2C-byte record of the collision body table init_collision_body_parts reads.
struct CollisionPartRecord { u8 pad_0[0xC]; f32 radius; u8 pad_10[0x1C]; };

typedef struct RecoveredFields_800D6810_arg0 RecoveredFields_800D6810_arg0;
struct RecoveredGlobal_800D5060_lbl_8058D490;
struct O_800D7274;
struct Obj_800D5150;
s32 init_collision_body_parts(void *, void *, int);

// This unit is built with -inline off,deferred: CW then emits .text in reverse definition order, so the
// functions below are defined from the last one in the DOL (load_entry_params) back to the first (vfunc_101).
void TObjEneMerillLia::load_entry_params(s32 i) {
    O_800D7274 *self = (O_800D7274 *)this;
    self->f34 = (*(D_800D7274 * *)&TObjEneMerillLia__entry_params_resource)->entries[i].f8;
    self->f24 = (*(D_800D7274 * *)&TObjEneMerillLia__entry_params_resource)->entries[i].fc;
}

TObjEneMerillLia::TObjEneMerillLia(TObject *parent, void *setData) : TUnk_80493450(parent) {
    m_name = TObjEneMerillLia__class_name;
    apply_set_data(setData);
    init_params_from_position();
    ((TObjPlayer *)this)->init_position_vectors();
    subtype = variant;
    clamp_and_apply_mode_param();
    load_entry_params(variant);
    action_table = (TObjMotionAction *)lbl_80494570;
    set_field_d8((saddr)action_table);
    *(s32 *)((s8 *)this + 0xDC) = *(s32 *)((s8 *)TObjEneMerillLia__entry_params_resource + 0x430);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, (u8 *)lbl_804946A4 + subtype * 0x2C, 1);
    bind_enemy_combat_stats((u8 *)TObjEneMerillLia__rock_stats_table[subtype], (u8 *)merill_lia_rock_buffer[subtype], (u8 *)merill_lia_rock_aux_buffer[subtype]);
    movementParameters = (u8 *)lbl_80494650 + subtype * 0x1C;
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    register_object_by_id();
    m_2ac = (s32)(182.04445f * (360.0f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    m_374 = 0;
    m_376 = 0;
    m_378 = 0;
    m_37c = 0;
    add_flags_2e4(2);
    obj_setFlags30(this, 0x40000);
    unk_380 = 0.0f;
    m_398 = ((f32 **)TObjEneMerillLia__rock_param_table)[subtype][0];
    m_3a0 = ((f32 **)TObjEneMerillLia__rock_param_table)[subtype][1];
    unk_39C = ((f32 **)TObjEneMerillLia__rock_param_table)[subtype][2];
    unk_3A4 = ((f32 **)TObjEneMerillLia__rock_param_table)[subtype][3];
    unk_3D4 = ((f32 **)TObjEneMerillLia__rock_param_table)[subtype][5];
    unk_3CC = ((s32 **)TObjEneMerillLia__rock_param_table)[subtype][6] / 100.0f;
    m_390 = 1;
    mode = 0xD;
    requested_action = 1;
    clear_lobby_object_state();
}

TObjEneMerillLia::~TObjEneMerillLia() {
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneMerillLia::sub_800D6D64() {
    s32 i;
    u8 *res;

    if (is_split_screen() != 0) {
        res = (u8 *)new BmlResource(1, &bm_ene_re8_merill_lia_low_resource_descriptor, 0, 0, NULL);
        TObjEneMerillLia__entry_params_resource = (uaddr)res;
    } else {
        res = (u8 *)new BmlResource(1, &bm_ene_re8_merill_lia_resource_descriptor, 0, 0, NULL);
        TObjEneMerillLia__entry_params_resource = (uaddr)res;
    }
    ((CollisionPartRecord *)lbl_804946A4)[0].radius = 7.0f;
    ((CollisionPartRecord *)lbl_804946A4)[1].radius = 7.0f;
    ((CollisionPartRecord *)lbl_804946A4)[2].radius = 8.0f;
    TObjEneMerillLia__rock_stats_table = (void **)mem_alloc(8);
    merill_lia_rock_buffer = (void **)mem_alloc(8);
    merill_lia_rock_aux_buffer = (void **)mem_alloc(8);
    TObjEneMerillLia__rock_param_table = (uaddr)mem_alloc(8);
    TObjEneMerillLia__rock_stats_table[0] = TLobby::register_boss(75);
    TObjEneMerillLia__rock_stats_table[1] = TLobby::register_boss(76);
    merill_lia_rock_buffer[0] = TLobby::dispatch_shared_handler_b(78);
    merill_lia_rock_buffer[1] = TLobby::dispatch_shared_handler_b(79);
    merill_lia_rock_aux_buffer[0] = TLobby::register_object(74);
    merill_lia_rock_aux_buffer[1] = TLobby::register_object(75);
    ((void **)TObjEneMerillLia__rock_param_table)[0] = TLobby::dispatch_shared_handler_a(74);
    ((void **)TObjEneMerillLia__rock_param_table)[1] = TLobby::dispatch_shared_handler_a(75);
    {
        s16 ids[2] = {44, 46};
        NpcAnimationBinding motions = { NULL, reinterpret_cast<TObjMotionAction *>(lbl_80494570), 0, 2, 12 };
        motions.motions = reinterpret_cast<BmlMotionEntry *>(((BmlResource *)TObjEneMerillLia__entry_params_resource)->motions);
        for (i = 0; i < 2; i++) {
            NpcModelRegistry::register_animated_chunk(ids[i], reinterpret_cast<void *>(((BmlResource *)TObjEneMerillLia__entry_params_resource)->models[i].model),
                reinterpret_cast<void *>(((BmlResource *)TObjEneMerillLia__entry_params_resource)->models[i].m_c), &motions,
                ((CollisionPartRecord *)lbl_804946A4)[i].radius, 0.0f);
        }
    }
}
#pragma pop

void TObjEneMerillLia::destroy_rocks() {
    if (TObjEneMerillLia__rock_stats_table != NULL) {
        mem_free(TObjEneMerillLia__rock_stats_table);
        TObjEneMerillLia__rock_stats_table = NULL;
    }
    if (merill_lia_rock_buffer != NULL) {
        mem_free(merill_lia_rock_buffer);
        merill_lia_rock_buffer = NULL;
    }
    if (merill_lia_rock_aux_buffer != NULL) {
        mem_free(merill_lia_rock_aux_buffer);
        merill_lia_rock_aux_buffer = NULL;
    }
    if ((u32) TObjEneMerillLia__rock_param_table != 0U) {
        mem_free((void*)TObjEneMerillLia__rock_param_table);
        TObjEneMerillLia__rock_param_table = 0U;
    }
    if ((u32) TObjEneMerillLia__entry_params_resource != 0U) {
        delete (BmlResource *)TObjEneMerillLia__entry_params_resource;
        TObjEneMerillLia__entry_params_resource = 0U;
    }
}

void *TObjEneMerillLia::create(void *arg0) {
    TObjControl *parent = new TObjControl(tl_04);
    return new TObjEneMerillLia(parent, arg0);
}

void TObjEneMerillLia::run_task() {
  s16 temp_r0;
  if (TObjPlayer::check_demo_mode() == 1)
  {
    (this->run_demo_task());
    return;
  }
  temp_r0 = this->mode;
  {
    switch (temp_r0)
    {
      case 0:
        (this->beast_update_appear());
        break;
      case 1:
        (this->beast_idle_update());
        break;
      case 2:
        (this->update_turn_toward_target());
        break;
      case 3:
        (this->beast_update_approach());
        break;
      case 4:
        (this->beast_update_group_chase());
        break;
      case 5:
        (this->beast_update_attack());
        break;
      case 6:
        (this->vfunc_89());
        break;
      case 7:
        (this->beast_update_hurt());
        break;
      case 8:
        (this->beast_update_dead());
        break;
      case 9:
        (this->beast_retire_corpse());
        break;
      case 10:
        TObjEneMerillLia::update_kafun_attack((void *)this);
        break;
      case 11:
        TObjEneMerillLia::update_emerge_state((void *) ((u8 *)this));
        break;
      case 12:
        TObjEneMerillLia::search_target((void *) ((u8 *)this));
        break;
      case 13:
        this->sub_800D5570();
        break;
    }
  }
  this->update_prev_position();
  ((TBoss3VoloptHiraisin *)this)->copy_position();
  submit_cursor_candidate((void *) this, -1);
  this->m_2b4 += 1.0f;
}

void TObjEneMerillLia::select_action_by_distance() {
    u8 *self = (u8 *)this;
    if (((TObjChara *)self)->random_ratio() <= this->m_3c4) {
        init_attack_state();
        return;
    }
    if (((TObjChara *)self)->random_ratio() <= *(f32 *)((s8 *)self + 0x3C8)) {
        reset_action_state();
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneMerillLia::init_params_from_position() {
    u8 *self = (u8 *)this;
    this->m_3d8 = (s16) ((s32) *(f32 *)((s8 *)self + 0x360) + 0x12C);
    this->m_3c4 = (f32) (*(f32 *)((s8 *)self + 0x354) - 0.2f);
    if (this->m_3c4 < 0.0f) {
        this->m_3c4 = 0.0f;
    }
    *(f32 *)((s8 *)self + 0x3C8) = (f32) (*(f32 *)((s8 *)self + 0x35C) - 0.2f);
    if (*(f32 *)((s8 *)self + 0x3C8) < 0.0f) {
        *(f32 *)((s8 *)self + 0x3C8) = 0.0f;
    }
    this->m_3d0 = (f32) (100.0f + *(f32 *)((s8 *)self + 0x364));
    if (this->m_3d0 < 15.0f) {
        this->m_3d0 = 15.0f;
    }
}
#pragma pop

void TObjEneMerillLia::render() {
  Vec stack;
  s32 var_r30;
  s16 temp_r0;
  s32 temp_r3;
  s32 var_r29;
  temp_r3 = (this->classify_actor_view_detail(200.0f, 400.0f, 30.0f));
  if (temp_r3 != 0)
  {
    saved_model_render_flags = model_render_flags;
    select_actor_lighting(this);
    TObjFish::set_global_param((int) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_24);
    push_matrix();
    translate_matrix(0, 0.0f, (f32) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_380, 0.0f);
    post_translate_matrix(((u8 *)this) + 0x38);
    rotate_matrix_y(0, (int) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_60);
    if (TObjPlayer::check_demo_mode() == 1)
    {
      draw_chunk_object(model);
    }
    else
    {
      TObjPlayer::toggle_particle_effect();
      var_r30 = 1;
      var_r29 = 0;
      if (((s16) ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_326) == 0xD)
      {
        var_r29 = 1;
        var_r30 = this->fade.has_visible_opacity();
      }
      if (var_r29 != 0)
      {
        this->fade.set_flags_and_apply_damage_color();
        if (this->defer_render() != 0)
        {
          var_r30 = 0;
        }
      }
      if (var_r30 != 0)
      {
        if (temp_r3 == 1)
        {
          set_motion_packed_rotation();
          this->draw();
          clear_motion_packed_rotation();
        }
        else
        {
          set_motion_packed_rotation();
          this->draw_motion_model();
          clear_motion_packed_rotation();
        }
      }
      TParticleCtrl::end_effect_render();
      if (var_r29 != 0)
      {
        this->fade.clear_flag_and_notify();
      }
    }
    pop_matrix();
    restore_scene_lighting();
    temp_r0 = ((RecoveredFields_800D6810_arg0 *) ((u8 *)this))->field_326;
    if ((temp_r0 >= 0xA) || (temp_r0 < 8))
    {
      stack.x = 1.5f;
      stack.y = 1.0f;
      stack.z = 2.0f;
      this->TObjEnemy::draw_ground_shadow(&stack, 0);
    }
  }
}

void TObjEneMerillLia::beast_update_approach() {
    u8 *self = (u8 *)this;
    Vec sp14;
    f32 r;
    switch (this->phase) {
    case 0:
        apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        ((TObjMotion *)self)->advance_animation();
        if (this->action_flags != 0x20U) {
            this->phase = 1;
            this->requested_action = 2;
        }
        break;
    default:
        spawn_ground_effect(self);
        if (*(u32 *)&this->target != 0U) {
            if (((TUnk_80493450 *)self)->test_elt_flag(0, 0x300000) != 0) {
                if (this->m_38c++ < 60.0f) {
                    VecCopy((Vec *)&sp14, &this->home_position);
                } else {
                    VecCopy((Vec *)&sp14, (const Vec *)(*(uaddr *)&this->target + 0x2FC));
                }
            } else {
                this->m_38c = 0U;
                VecCopy((Vec *)&sp14, (const Vec *)(*(uaddr *)&this->target + 0x2FC));
            }
            ((TUnk_80493450 *)self)->update_target_near_flag();
            ((TUnk_80493450 *)self)->sub_800C4E08();
            ((TObjMotion *)self)->advance_animation();
            {
                Vec sp8 = sp14;
                enemy_move_toward(self, *(s32 *)((s8 *)(*(u8 * *)&this->movementParameters) + 8), &sp8, 0, *(f32 *)&this->unk_394);
            }
            if (this->targetId == 0xFFFF) {
                if (horizontal_distance_squared((u8 *)&this->move_destination, (u8 *)&this->position) < (r = *(f32 *)&this->unk_394 + *(f32 *)((s8 *)(*(u8 * *)&this->bodies) + 0xC)) * r ||
                    150.0f < (f32) (*(s32 *)&this->m_2ac)++) {
                    *(u32 *)&this->target = 0U;
                    *(s32 *)&this->m_2ac = 0;
                }
            }
        }
        break;
    }
    ((TObjCollidable *)self)->update_collisions();
    ((TObjCollidable *)self)->update_enemy_collision_flags();
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    ((TObjBase *)self)->obj_clearFlags30(0x200000);
}

void TObjEneMerillLia::beast_update_appear() {
    Ene_800D64F0 *self = (Ene_800D64F0 *)this;
    switch (self->sub) {
    case 0:
    default:
        if (self->f390 != 1) {
            self->sub = 2;
        } else {
            self->sub = 1;
            self->fB8 = 0xB;
            ((TObjCollidable *)self)->set_indexed_flags(0, 0xA000000);
            obj_setFlags30(self, 0x4000000);
            this->play_hurt_sound();
        }
        break;
    case 1:
        spawn_ground_effect(self);
        if (((TObjMotion *)self)->is_passing_frame(10.0f) != 0) {
            sub_800D501C();
        }
        if (self->fB4 != 0x20) {
            self->sub = 2;
            self->f390 = 0;
            self->fB8 = 0;
            ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
            ((TObjBase *)self)->obj_clearFlags30(0x4000000);
        }
        break;
    case 2:
        self->target = find_nearest_visible_player(reinterpret_cast<TObjChara *>(self), NULL, *self->param);
        self->state = 1;
        break;
    }
    ((TObjMotion *)self)->advance_animation();
}

#pragma push
#pragma fp_contract on
void TObjEneMerillLia::beast_update_group_chase() {
    Obj_800D6110 *self = (Obj_800D6110 *)this;
    Vec save;
    Vec to;
    Vec d;
    f32 dist;
    ((TObjMotion *)self)->advance_animation();
    switch (self->f328) {
    case 0:
        self->f328 = 1;
        ((TObjEneMerillLia *)self)->play_group_chase_sound();
        break;
    case 1:
        if (self->f2a8 != NULL) {
            spawn_ground_effect(self);
            save.x = self->pos.x;
            save.y = self->pos.y;
            save.z = self->pos.z;
            if (self->f3d4 <= 0.0f) {
                Vec a = self->f2a8->p2fc;
                dist = enemy_backstep_from_point(self, &a, self->f398);
            } else {
                Vec b = self->f2a8->p2fc;
                dist = enemy_backstep_from_point(self, &b, self->f3d4);
            }
            ((TObjEnemy *)self)->turn_toward_direction(((s32 *)self->f350)[2], (Vec *)self->ang308);
            self->f374--;
            if (dist < (self->f398 + self->model->radius) * (self->f398 + self->model->radius) || self->f374 < 0) {
                self->f328 = 2;
                self->f374 = 0;
            }
            ((TObjCollidable *)self)->update_collisions();
            ((TObjCollidable *)self)->update_enemy_collision_flags();
            if (self->model->flags & 0x380000) {
                self->f328 = 2;
                self->f374 = 0;
                break;
            }
            d.x = self->pos.x - save.x;
            d.y = self->pos.y - save.y;
            d.z = self->pos.z - save.z;
            normalize_vector(&d);
            to.x = 30.0f * d.x + self->pos.x;
            to.y = 30.0f * d.y + self->pos.y;
            to.z = 30.0f * d.z + self->pos.z;
            if (csnVector(&save, &to, 0x88E0) != 0) {
                self->f328 = 2;
                self->f374 = 0;
            }
            break;
        }
        if (((TObjChara *)self)->is_actor_cadence_frame(0x1E) != 0) {
            self->f338 = find_nearest_visible_player(reinterpret_cast<TObjChara *>(self), NULL, *self->f350);
        }
        if (self->f338 < 0x1000) {
            Pl_800D5614 *p = (Pl_800D5614 *)get_player_by_client_id(self->f338);
            if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
                self->f2a8 = (Pl_800D6110 *)p;
                break;
            }
            self->f2a8 = NULL;
            ((TObjEneMerillLia *)self)->reset_state_clear_status();
            break;
        }
        self->f2a8 = NULL;
        ((TObjEneMerillLia *)self)->reset_state_clear_status();
        break;
    case 2:
        ((TObjBase *)self)->obj_clearFlags30(0x1000);
        if (((TObjChara *)self)->is_actor_cadence_frame(0x1E) != 0) {
            self->f338 = find_nearest_visible_player(reinterpret_cast<TObjChara *>(self), NULL, *self->f350);
        }
        if (self->f338 < 0x1000) {
            Pl_800D5614 *p = (Pl_800D5614 *)get_player_by_client_id(self->f338);
            if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor() &&
                xz_distance_squared(p->pos, &self->pos) < 10000.0f) {
                self->f326 = 1;
                self->f328 = 0;
                self->fb8 = 0xA;
                ((TObjBase *)self)->obj_clearFlags30(0x4040000);
                ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
                break;
            }
            ((TObjEneMerillLia *)self)->reset_state_clear_status();
        } else {
            ((TObjEneMerillLia *)self)->reset_state_clear_status();
        }
        break;
    }
    ((TObjCollidable *)self)->update_collisions();
    ((TObjCollidable *)self)->update_enemy_collision_flags();
    minimap_render_dot(&self->pos, -0x5DB4, 1, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#define o ((Lia_800D5BCC *)this)
void TObjEneMerillLia::beast_idle_update() {
    ((TUnk_80493450 *)o)->update_target_near_flag();
    ((TUnk_80493450 *)o)->sub_800C4E08();
    ((TObjMotion *)o)->advance_animation();
    if (o->state != 1) {
        o->state = 1;
        ((TUnk_80493450 *)o)->link_into_group_chain();
        o->f378 = ((TObjPlayer *)o)->is_action_available();
    }
    o->count = ((TUnk_80493450 *)o)->countChildren();
    {
        Lia_800D5BCC *p = o->partner;
        if (p != NULL) {
            s32 diff = p->count - o->count;
            if (diff > 1) {
                link_chain_nodes__10TObjPlayerFPvPvPv(o, p, o);
                o->count++;
                p->count--;
            } else if (diff < -1) {
                link_chain_nodes__10TObjPlayerFPvPvPv(o, o, p);
                o->count--;
                p->count++;
            }
        }
    }
    {
    f32 dist = horizontal_distance_squared(&o->pos, &o->home);
    f32 r = o->f358 + (o->param->speed + o->fA4->fC);
    if (r * r < dist) {
        Vec *d;
        Vec *v;
        s32 ang;
        VecCopy((Vec *)&o->f29C, (const Vec *)&o->home);
        VecCopy((Vec *)&o->f290, (const Vec *)&o->f2FC);
        VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
        VecCopy((Vec *)&scratch_vec, (const Vec *)&o->home);
        subtract_vector(&scratch_vec, &o->pos);
        d = &scratch_vec;
        ang = (s32)(10430.38043493439 * atan2_float(d->x, d->z));
        v = &lbl_8050BF00;
        v->x = v->y = 0.0f;
        v->z = o->f394;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, ang);
        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
        pop_matrices(1);
        vec3_add_to(&lbl_8050BF00, &o->pos);
        if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
            o->fB8 = 2;
            VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
            o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
        } else {
            f32 rr = fabs_float(d->z);
            if (fabs_float(scratch_vec.x) < rr) {
                ang = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
            } else {
                ang = (s32)(10430.38043493439 * atan2_float(0.0f, d->z));
            }
            v->y = 0.0f;
            lbl_8050BF00.x = 0.0f;
            v->z = o->f394;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, ang);
            rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
            pop_matrices(1);
            vec3_add_to(&lbl_8050BF00, &o->pos);
            if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                o->fB8 = 2;
                VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                o->angle = approach_angle_limited(o->angle, ang, o->param->turn);
            } else {
                s32 ang2;
                rr = fabs_float(d->z);
                if (fabs_float(scratch_vec.x) < rr) {
                    ang2 = (s32)(10430.38043493439 * atan2_float(0.0f, d->z));
                } else {
                    ang2 = (s32)(10430.38043493439 * atan2_float(scratch_vec.x, 0.0f));
                }
                v->y = 0.0f;
                lbl_8050BF00.x = 0.0f;
                v->z = o->f394;
                push_matrix_from(&identity_matrix);
                rotate_matrix_y(0, ang2);
                rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                pop_matrices(1);
                vec3_add_to(&lbl_8050BF00, &o->pos);
                if (project_actor_to_ground(o, &lbl_8050BF00, 0) == 1) {
                    o->fB8 = 2;
                    VecCopy((Vec *)&o->pos, (const Vec *)&lbl_8050BF00);
                    o->angle = approach_angle_limited(o->angle, ang2, o->param->turn);
                } else {
                    o->fB8 = 2;
                }
            }
        }
    } else if (o->count == 0 && 0.0f < o->f358) {
        f32 w;
        o->fB8 = 2;
        w = o->f358;
        ((TObjEnemy *)(o))->enemy_wander_home(o->param->speed, w, w, o->param->turn);
    } else {
        ((TObjEneMerillLia *)o)->reset_state_clear_status();
    }
    }
    if (((TObjCollidable *)o)->obj_testFlags30(0x800000) == 0) {
        apply_actor_gravity((TObjEnemy *)o, (s32 *)(0), 0.0f);
    }
    ((TObjCollidable *)o)->refresh_collision_body_centers();
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    ((TObjBase *)o)->obj_clearFlags30(0x04240000);
    ((TObjCollidable *)o)->clear_player_status_flag(0, 0x0A000000);
}
#undef o
#pragma pop

void TObjEneMerillLia::beast_update_hurt() {
    Vec pos;

    this->advance_animation();
    VecCopy((Vec *)&pos, (const Vec *)(((u8 *)this) + 0x2FC));
    scratch_vec.y = 0.0f;
    scratch_vec.x = 0.0f;
    scratch_vec.z = get_collision_body_radius(0);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, -this->rotation_y);
    rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
    pop_matrix();
    vec3_add_to(&pos, &scratch_vec);
    pos.x = pos.x + *(f32 *)((s8 *)((u8 *)this) + 0x308);
    pos.z = pos.z + *(f32 *)((s8 *)((u8 *)this) + 0x310);
    if (check_path_obstructed(this, &pos) == 0) {
        move_with_wall_slide(((u8 *)this));
        *(f32 *)((s8 *)((u8 *)this) + 0x308) *= 0.5f;
        *(f32 *)((s8 *)((u8 *)this) + 0x310) *= 0.5f;
    } else {
        *(f32 *)((s8 *)((u8 *)this) + 0x310) = 0.0f;
        *(f32 *)((s8 *)((u8 *)this) + 0x308) = 0.0f;
    }
    update_collisions();
    this->update_enemy_collision_flags();
    if (this->is_passing_frame(0.0f) != 0) {
        this->play_hurt_sound();
    }
    if (this->action_flags != 8) {
        this->obj_clearFlags30(0x600);
        this->clear_player_status_flag(0, 0x04000000);
        if ((f32)this->hp <= (f32)this->hpmax * *(f32 *)((s8 *)((u8 *)this) + 0x3CC)) {
            this->select_action_by_distance();
        }
        this->referenceHp = this->hp;
    }
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
}

#define arg0 ((u8 *)p)
void TObjEneMerillLia::update_kafun_attack(void *p) {
    Vec_800D57C8 sp14;
    ((TObjMotion *)arg0)->advance_animation();
    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    default:
    case 0:
        *(s16 *)((s8 *)arg0 + 0x328) = 1;
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xC;
        obj_setFlags30(arg0, 0x200000);
        ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
        break;
    case 1:
        if (((TObjMotion *)arg0)->is_passing_frame(13.0f) != 0) {
            ((TObjMotion *)arg0)->advance_animation();
            push_matrix_from(&identity_matrix);
            post_translate_matrix(arg0 + 0x38);
            rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
            ((TObjEnemy *)arg0)->calc_joint_matrices(13.0f);
            pop_matrix();
            push_matrix_from(anim_model_matrix_array[23]);
            {
                Vec_800D57C8 sp8 = {0, 0, 0};
                matrix_mult_vec(0, &sp8, &sp14);
            }
            pop_matrix();
            TTecKafun::create((saddr)arg0, (saddr)&sp14, 0xF, 0xD3, ((TObjEneMerillLia *)arg0)->get_clamped_level(), *(f32 *)((s8 *)(((void **) TObjEneMerillLia__rock_param_table)[*(s32 *)((s8 *)arg0 + 0x334)]) + 0x10), 20.0f);
            ((TObjEneMerillLia *)arg0)->sub_800D4EC8();
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB4) != 4U) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0;
            *(s16 *)((s8 *)arg0 + 0x33C) = 0xF;
        }
        break;
    case 2:
        (*(s16 *)((s8 *)arg0 + 0x33C))--;
        if (*(s16 *)((s8 *)arg0 + 0x33C) < 0) {
            ((TObjBase *)arg0)->obj_clearFlags30(0x200000);
            *(s16 *)((s8 *)arg0 + 0x33C) = 0;
            if (((TObjChara *)arg0)->random_ratio() <= *(f32 *)((s8 *)arg0 + 0x3C4)) {
                ((TObjEneMerillLia *)arg0)->init_attack_state();
            } else {
                *(s16 *)((s8 *)arg0 + 0x326) = 1;
                *(s16 *)((s8 *)arg0 + 0x328) = 0;
                obj_setFlags30(arg0, 0x04040000);
                ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x0A000000);
            }
        }
        break;
    }
    ((TObjCollidable *)arg0)->update_collisions();
    ((TObjCollidable *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

#define arg0 ((u8 *)ov)
void TObjEneMerillLia::update_emerge_state(void *ov) {

    ((TObjMotion *)arg0)->advance_animation();
    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
    default:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x390) == 1) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
        } else {
            *(s16 *)((s8 *)arg0 + 0x328) = 1;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0xD;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x0A000000);
            obj_setFlags30(arg0, 0x04000000);
            ((TObjEneMerillLia *)arg0)->sub_800D501C();
        }
        break;
    case 1:
        spawn_ground_effect(arg0);
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB4) != 0x20U) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
            *(s32 *)((s8 *)arg0 + 0x390) = 1;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
            ((TObjBase *)arg0)->obj_clearFlags30(0x04040000);
        }
        break;
    case 2:
        *(s16 *)((s8 *)arg0 + 0x326) = 0xC;
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        break;
    }
    ((TObjCollidable *)arg0)->update_collisions();
    ((TObjCollidable *)arg0)->update_enemy_collision_flags();
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
}
#undef arg0

#define arg0 ((Obj_800D5614 *)ov)
void TObjEneMerillLia::search_target(void *ov) {
    Pl_800D5614 *p;
    s32 v;
    arg0->f338 = find_nearest_visible_player(reinterpret_cast<TObjChara *>(arg0), NULL, *arg0->f350);
    if (arg0->f338 < 0x1000) {
        p = (Pl_800D5614 *)get_player_by_client_id(arg0->f338);
        if (p != NULL) {
            s32 w;
            v = get_current_floor();
            w = ((TObjPlayer *)p)->get_floor();
            if (w == v) {
                if (xz_distance_squared(p->pos, arg0->pos) < arg0->f3d0 * arg0->f3d0) {
                    arg0->f2a8 = p;
                    arg0->f326 = 0;
                    arg0->f328 = 0;
                }
            }
        }
    }
    ((TObjMotion *)arg0)->advance_animation();
}
#undef arg0

void TObjEneMerillLia::sub_800D5570() {
    Obj_800D5570 *self = (Obj_800D5570 *)this;
    switch (this->phase) {
    case 0:
    default:
        this->phase = 1;
        this->requested_action = 1;
        this->fade.start_fade_in();
        play_area_sound_effect((Vec *)(self->sub38));
        break;
    case 1:
        spawn_ground_effect(self);
        if (this->fade.advance_toward_max() != 0) {
            this->phase = 2;
        }
        break;
    case 2:
        this->mode = 12;
        break;
    }
    ((TObjMotion *)self)->advance_animation();
}

void TObjEneMerillLia::reset_action_state() {
    this->mode = 0xA;
    this->phase = 0;
    obj_setFlags30(this, 0x200000);
    obj_clearFlags30(0x04040000);
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::init_attack_state() {
    this->mode = 4;
    this->phase = 0;
    this->m_374 = (s16) this->m_3d8;
    obj_clearFlags30(0x04240000);
    clear_player_status_flag(0, 0x0A000000);
}

void TObjEneMerillLia::reset_state_clear_status() {
    u8 *self = (u8 *)this;
    this->mode = 0xB;
    this->phase = 0;
    this->target = 0;
    ((TObjCollidable *)self)->clear_player_status_flag(0, (s32)(0x0A000000U));
}

void TObjEneMerillLia::run_idle_action() {
    s32 temp_r0;

    temp_r0 = this->mode;
    if (temp_r0 != 4) {
        if (temp_r0 < 4) {
            if (temp_r0 < 3) {
                if (temp_r0 >= 0) {
                    goto block_end;
                }
                goto block_7;
            } else {
                goto block_7;
            }
        } else if ((temp_r0 >= 0xE) || (temp_r0 < 0xB)) {
block_7:
            if ((s32) this->m_390 != 0) {
                this->mode = 0;
            } else {
                this->mode = 1;
            }
            this->phase = 0;
            obj_setFlags30(this, 0x04040000);
            set_indexed_flags(0, 0x0A000000);
        }
    }
block_end:
    ;
}

void TObjEneMerillLia::run_attack_action() {
    Ene_800D52DC *self = (Ene_800D52DC *)this;
    switch (this->mode) {
    case 0:
    case 2:
    case 4:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        this->phase = 0;
        if (this->children == NULL) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 10;
        }
        ((TObjBase *)self)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
        break;
    default:
        this->mode = 5;
        this->phase = 1;
        if (0.5f < ((TObjChara *)self)->random_ratio()) {
            this->requested_action = 3;
        } else {
            this->requested_action = 4;
        }
        obj_setFlags30(self, 0x200000);
        ((TObjBase *)self)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::run_move_action() {
    Ene_800D51C8 *self = (Ene_800D51C8 *)this;
    if (((TObjCollidable *)self)->obj_testFlags30(0x1000) != 0) {
        this->mode = 4;
    }
    switch (this->mode) {
    case 0:
    case 2:
    case 3:
    case 10:
    case 11:
    case 12:
    case 13:
        break;
    case 1:
        this->phase = 0;
        if (this->children == NULL) {
            this->mode = 3;
            this->requested_action = 7;
        } else {
            this->mode = 2;
            this->requested_action = 10;
        }
        ((TObjBase *)self)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
        break;
    case 4:
        this->requested_action = 5;
        break;
    default:
        this->mode = 3;
        this->phase = 1;
        this->requested_action = 2;
        ((TObjBase *)self)->obj_clearFlags30(0x4040000);
        ((TObjCollidable *)self)->clear_player_status_flag(0, 0xA000000);
        break;
    }
}

void TObjEneMerillLia::clamp_and_apply_mode_param() {
    Obj_800D5150 *self = (Obj_800D5150 *)this;
    if (self->f334 < 0) {
        self->f334 = 0;
    } else if (self->f334 > 1) {
        self->f334 = 1;
    }
    switch (self->f334) {
    case 1:
        self->f368 = 1;
        ((TObjEnemy *)self)->set_param(0x35);
        break;
    default:
        self->f368 = 0;
        ((TObjEnemy *)self)->set_param(0x34);
        break;
    }
}

s32 TObjEneMerillLia::get_clamped_level() {
    TObjEneMerillLia *self = this;
    Sub_800D5100 *p = *(Sub_800D5100 * *)&self->m_2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->f18;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

void TObjEneMerillLia::update_attack_trail() {  }

void TObjEneMerillLia::spawn_death_effect() {
    u8 *self = (u8 *)this;
    Vec stack;
    stack.x = 0.0f;
    stack.y = 10.0f;
    stack.z = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, (void *)&stack.x, (void *)&stack.x);
    pop_matrix();
    vec3_add_to((void *)&stack.x, (void *)(self + 0x38));
    ((TObjPlayer *)(&stack.x))->spawn_ground_effect(0x23);
    TObjPlayer__sub_800D92BC((saddr)&stack.x, 0xF);
}

void TObjEneMerillLia::sub_800D501C() {
    play_sound_effect(remap_sound_for_area(0x3B206), &position, 0, 0);
}

void TObjEneMerillLia::play_attack_sound() {
    play_sound_effect(remap_sound_for_area(0x3AB02), &position, 0, 0);
}

void TObjEneMerillLia::play_hurt_sound() {
    play_sound_effect(remap_sound_for_area(0x3B201), &position, 0, 0);
}

void TObjEneMerillLia::play_death_sound() {
    play_sound_effect(remap_sound_for_area(0x3AD00), &position, 0, 0);
}

void TObjEneMerillLia::play_group_chase_sound() {
    play_sound_effect(remap_sound_for_area(0x3B205), &position, 0, 0);
}

void TObjEneMerillLia::sub_800D4EC8() {
    play_sound_effect(remap_sound_for_area(0x3AD04), &position, 0, 0);
}

void TObjEneMerillLia::spawn_ground_effect(void *motion) {
    Vec pos;
    saddr particle_effect;
    u8 *hit;
    VecCopy(&pos, &((TObjEneMerillLia *)motion)->position);
    pos.y += 15.0f;
    hit = (u8 *)csnVectorUnder(&pos, (CsnGroup **)&((TObjEneMerillLia *)motion)->m_120, 5);
    if ((hit != NULL) && (*(s32 *)((s8 *)hit + 0) & 4)) {
        if (((s32) ((f32) actor_frame_tick * (3.0517578125e-05f * (f32) rand())) % 5) == 0) {
            particle_effect = (saddr)spawn_particle_effect((const Vec *)(*(saddr *)((s8 *)hit + 4) + 0x38), 0x49);
            if (particle_effect != 0) {
                attach_particle_model((u8 *)particle_effect, TParticleCtrl::get_particle_model(2), TParticleCtrl::get_instance(), 0, 1, 1.0f);
            }
            spawn_particle_effect((const Vec *)(*(saddr *)((s8 *)hit + 4) + 0x38), 0xA4);
        }
        if ((((TObjEneMerillLia *)motion)->is_passing_frame(7.0f) != 0) || (((TObjEneMerillLia *)motion)->is_passing_frame(22.0f) != 0)) {
            fn_800D88E4((u8 *)motion + 0x38);
        }
    }
}
}

void TObjEneMerillLia::run_demo_task() {  }
