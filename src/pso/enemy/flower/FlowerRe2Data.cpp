#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/DragonAttackParams.h"

// Data-only unit split off the flower enemy: the .rodata block at 0x8043BA68.
// The referencing units (TObjEneRe2Flower, TObjEneDD) keep these extern so
// their per-object lis/addi codegen is unchanged; this unit only provides bytes.

extern TObjMotionAction TObjEneRe2Flower__animation_descriptors[8];

// The normal and rare variants' self-destruct blast (state_self_destruct hands it to TObjEneDD__sub_800BA5A4).
__declspec(section ".rodata") extern const DragonAttackParams enemy_dd_attack_param_block ATTRIBUTE_ALIGN(4) = {
    0x10, 0.0f, 30.0f, {0.0f, 1},
};

// Per variant (0 normal, 1 rare, 2 the tower's), as Gibon's twins: the reset_hp blocks and the param block.
__declspec(section ".rodata") extern const u32 re2_flower_base_stat_ids[3] ATTRIBUTE_ALIGN(4) = {
    0x00000004, 0x00000005, 0x00000025,
};

__declspec(section ".rodata") extern const u32 re2_flower_attack_stat_ids[3] ATTRIBUTE_ALIGN(4) = {
    0x00000004, 0x00000005, 0x00000025,
};

__declspec(section ".rodata") extern const u32 re2_flower_resist_stat_ids[3] ATTRIBUTE_ALIGN(4) = {
    0x00000004, 0x00000005, 0x00000025,
};

__declspec(section ".rodata") extern const u32 re2_flower_param_ids[3] ATTRIBUTE_ALIGN(4) = {
    0x00000004, 0x00000005, 0x00000025,
};

__declspec(section ".rodata") extern const char re2_flower_model_name_re2_b_flower_root_nj[] ATTRIBUTE_ALIGN(4) = "re2_b_flower_root.nj";
__declspec(section ".rodata") extern const char re2_flower_motion_name_attack_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "attack_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_damege_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "damege_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_die_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "die_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_laugh_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "laugh_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_waitc_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "waitc_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_waito_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "waito_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_motion_name_wake_re2_b_root_njm[] ATTRIBUTE_ALIGN(4) = "wake_re2_b_root.njm";
__declspec(section ".rodata") extern const char re2_flower_bml_name_bm_ene_re2_flower_bml[] ATTRIBUTE_ALIGN(4) = "bm_ene_re2_flower.bml";
__declspec(section ".rodata") extern const char TObjEneRe2Flower__class_name_string[] ATTRIBUTE_ALIGN(4) = "TObjEneRe2Flower";

__declspec(section ".rodata") extern const NpcAnimationBinding re2_flower_animation_binding = {
    NULL, TObjEneRe2Flower__animation_descriptors, 1, 6, 8,
};

// The tower variant's self-destruct blast; state_self_destruct sets power and recoil from its param block.
__declspec(section ".rodata") extern const DragonAttackParams re2_flower_tower_attack_params ATTRIBUTE_ALIGN(4) = {
    0, 0.0f, 30.0f, {0.0f, 1},
};

// draw_ground_shadow scales: render, then render_demo.
__declspec(section ".rodata") extern const f32 re2_flower_shadow_scale[3] ATTRIBUTE_ALIGN(4) = {
    2.0f, 1.0f, 2.0f,
};

__declspec(section ".rodata") extern const f32 re2_flower_demo_shadow_scale[4] ATTRIBUTE_ALIGN(4) = {
    2.0f, 1.0f, 2.0f, 0.0f,
};
