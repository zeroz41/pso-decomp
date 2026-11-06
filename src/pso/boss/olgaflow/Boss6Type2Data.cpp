#include "pso/boss/olgaflow/Boss6Type2Data.h"

const char *TBoss6Type2__name = "TBoss6Type2";
// Inferred name: distance checks (> 390), sound sources and the start position all use it.
const Vec boss6_arena_center = { -10000.0f, 0.0f, 0.0f };
// Inferred names: the constructor copies these into position and rotation_x..z.
const Vec TBoss6Type2__initial_position = { -10000.0f, 0.0f, 0.0f };
const s32 TBoss6Type2__initial_rotation[3] = { 0x8000, 0, 0 };
const TBoss6Type2DefaultParams TBoss6Type2__default_battle_parameters = {
    { 20, 20, 200, 200, 200, 60, 25, 10, 60 },
    { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
    120,
};
const s32 TBoss6Type2__initial_actor_flag_masks[4] = { 0x41, 0x42, 0x44, 0x48 };
const Tbl_802B9C00 TBoss6Type2__particle_attachment_table[14] = {
    { 0x22D, 8 }, { 0x22D, 9 }, { 0x22D, 10 }, { 0x22D, 3 }, { 0x22D, 4 }, { 0x22D, 5 }, { 0x228, -1 },
    { 0x22A, -1 }, { 0x137, 16 }, { 0x138, 16 }, { 0x139, 16 }, { 0x13A, 16 }, { 0x13B, 16 }, { 0x22C, 13 },
};
const TObjFishNodeEntry boss6_type2_effect_desc_table[20] = {
    { 0x01 }, { 0x13 }, { 0x14 }, { 0x16 }, { 0x17, { 0.0f, -5.0f, 0.0f } }, { 0x18 }, { 0x1B }, { 0x1C },
    { 0x1E }, { 0x1F, { 0.0f, -5.0f, 0.0f } }, { 0x20 }, { 0x24 }, { 0x30 }, { 0x3A }, { 0x48 }, { 0x4B },
    { 0x50 }, { 0x51 }, { 0x51, { 0.0f, 1.0f, 0.0f } }, { -1 },
};
const s32 boss6_type2_variant_id_table[4] = { 1, 2, 3, 4 };
const s32 lbl_8047128C[2] = { 4, 5 };
const Ent_802B9F3C boss6_type2_plot_falz_entry_table[2] = { { 4, 0x69, 0 }, { 5, 0x69, 0 } };
const s32 boss6_type2_zero_vec[4] = { 0, 0, 0, 0 };
const Blk_802BCFD4 boss6_type2_zero_motion_block = { 0 };
const f32 boss6_type2_motion_entry_transform[7] = { 0.0f, 0.0f, 0.0f, 0.0f, 1.0f / 15.0f, 0.0f, 0.0f };
const s32 TBoss6Type2__no_target_sound_ids[4] = { 0x68528, 0x68529, 0x6852A, 0x6852B };
const Tbl_802BBE20 lbl_8047130C[3] = { { 0, 4 }, { 0, 9 }, { 0, 11 } };
const s32 TBoss6Type2__player_hit_rock_indices[6] = { 3, 4, 5, 8, 9, 10 };
const s32 lbl_8047133C[2] = { 0x1FE, 0x1FD };
const Vec_802B9A68 lbl_80471344 = { 0.0f, 19.8f, -5.0f };
