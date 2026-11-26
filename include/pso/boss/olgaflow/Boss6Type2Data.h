#include "pso/boss/Boss6ScrollStrips.h"
#ifndef PSO_BOSS_OLGAFLOW_BOSS6TYPE2DATA_H
#define PSO_BOSS_OLGAFLOW_BOSS6TYPE2DATA_H

#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"

// TBoss6Type2's class name and the constructor/battle tables, first in TBoss6Type2.cpp's .rodata.
// The constructor addresses every table on its own (no shared .rodata base); TBoss6Rock reads
// boss6_arena_center as well.

struct Boss6Type2ParticleAttachment { s32 a; s32 b; };
struct Boss6Type2MotionBlock { s32 a; s32 b; s32 rest[7]; };
struct Boss6Type2CollisionBodyNode { s32 kind; s32 idx; };
struct TBoss6Type2MotionTrack;

// Fallbacks load_battle_params uses when the boss parameter entries are not positive.
struct TBoss6Type2DefaultParams {
    s32 int_params[9];
    f32 float_params[5];
    s32 last_param;
};

extern const Vec boss6_arena_center;
// TBoss6Type2.cpp defines these with its .sdata2 constants: the arena radius and the
// motion speeds the action handlers turn into durations (frames / speed).
extern "C" {
extern const f32 boss6_arena_radius;
extern const f32 boss6_type2_search_speed;      // SEARCH
extern const f32 boss6_type2_bkjump_speed;      // BKJUMP
extern const f32 boss6_type2_iai_speed;         // IAI_*
extern const f32 boss6_type2_bsk_speed;         // CHG_TO_BSK, BSK_AGAIN
extern const f32 boss6_type2_chg_to_cmn_speed;  // CHG_TO_CMN
extern const f32 boss6_type2_b_wait_speed;      // B_WAIT
}
extern const ModelNodePositionEntry boss6_type2_effect_desc_table[20];
extern const s32 boss6_type2_variant_id_table[4];
extern const s32 boss6_type2_body_model_indices[2];
extern const Boss6StripDesc boss6_type2_plot_falz_entry_table[2];
extern const s32 boss6_type2_zero_vec[4];
extern const Boss6Type2MotionBlock boss6_type2_zero_motion_block;
extern const TBoss6Type2MotionTrack boss6_type2_motion_entry_transform;
extern const Boss6Type2CollisionBodyNode boss6_type2_collision_body_nodes[3];
extern const s32 boss6_type2_mag_spawn_offsets[2];
extern const Vec boss6_type2_player_aim_offset;

#endif
