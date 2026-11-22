#include "pso/boss/Boss6ScrollStrips.h"
#ifndef PSO_BOSS_OLGAFLOW_BOSS6TYPE2DATA_H
#define PSO_BOSS_OLGAFLOW_BOSS6TYPE2DATA_H

#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"

// TBoss6Type2's class name and the constructor/battle tables. They live in their own unit ahead of
// TBoss6Type2.cpp: its code addresses every table on its own (no shared .rodata base) and TBoss6Rock
// reads boss6_arena_center as well.

struct Tbl_802B9C00 { s32 a; s32 b; };
struct Ent_802B9F3C { s32 a; s32 b; s32 c; };
struct Blk_802BCFD4 { s32 a; s32 b; s32 rest[7]; };
struct Tbl_802BBE20 { s32 kind; s32 idx; };
struct TBoss6Type2MotionTrack;

// Fallbacks load_battle_params uses when the boss parameter entries are not positive.
struct TBoss6Type2DefaultParams {
    s32 int_params[9];
    f32 float_params[5];
    s32 last_param;
};

extern const char *TBoss6Type2__name;
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
extern const Vec TBoss6Type2__initial_position;
extern const s32 TBoss6Type2__initial_rotation[3];
extern const TBoss6Type2DefaultParams TBoss6Type2__default_battle_parameters;
extern const s32 TBoss6Type2__initial_actor_flag_masks[4];
extern const Tbl_802B9C00 TBoss6Type2__particle_attachment_table[14];
extern const ModelNodePositionEntry boss6_type2_effect_desc_table[20];
extern const s32 boss6_type2_variant_id_table[4];
extern const s32 lbl_8047128C[2];
extern const Boss6StripDesc boss6_type2_plot_falz_entry_table[2];
extern const s32 boss6_type2_zero_vec[4];
extern const Blk_802BCFD4 boss6_type2_zero_motion_block;
extern const TBoss6Type2MotionTrack boss6_type2_motion_entry_transform;
extern const s32 TBoss6Type2__no_target_sound_ids[4];
extern const Tbl_802BBE20 lbl_8047130C[3];
extern const s32 TBoss6Type2__player_hit_rock_indices[6];
extern const s32 lbl_8047133C[2];
extern const Vec lbl_80471344;

#endif
