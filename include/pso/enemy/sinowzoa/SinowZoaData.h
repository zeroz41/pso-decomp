#ifndef PSO_ENEMY_SINOWZOA_SINOWZOADATA_H
#define PSO_ENEMY_SINOWZOA_SINOWZOADATA_H
#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/enemy/deldepth/DelDepthData.h"

// The Sinow Zoa code's constant objects, defined by SinowZoaData.cpp.
extern "C" {
// TObjEneMe3SinowZoa.cpp .data; both animation bindings point at it.
extern TObjMotionAction me3_sinow_zoa_animation_descriptors[13];
extern const BreakUpParamRow sinow_zoa_breakup_params;
// TLobby kind ids for the two Sinow Zoa kinds, one list per TLobby table
// load_resources registers them with.
extern const s32 sinow_zoa_base_param_ids[2];
extern const s32 sinow_zoa_attack_param_ids[2];
extern const s32 sinow_zoa_resistance_param_ids[2];
extern const s32 sinow_zoa_kind_param_ids[2];
extern const char sinow_zoa_model[];
extern const char sinow_zoa_t_wait_motion[];
extern const char sinow_zoa_apper_motion[];
extern const char sinow_zoa_backstep_motion[];
extern const char sinow_zoa_bareta_motion[];
extern const char sinow_zoa_damage_motion[];
extern const char sinow_zoa_death_motion[];
extern const char sinow_zoa_f_attack_motion[];
extern const char sinow_zoa_sword_motion[];
extern const char sinow_zoa_transform_motion[];
extern const char sinow_zoa_wait_motion[];
extern const char sinow_zoa_walk_motion[];
extern const char sinow_zoa_bml[];
extern const char sinow_zoa_low_model[];
extern const char sinow_zoa_low_bml[];
extern const char sinow_zoa_class_name[];
extern const char sinow_zoa_real_class_name[];
extern const NpcAnimationBinding sinow_zoa_attack_binding_desc_a;
extern const NpcAnimationBinding sinow_zoa_attack_binding_desc_b;
extern const Vec sinow_zoa_barta_origin_offset;
extern const char sinow_zoa_debug_stelth_enable[];
extern const char sinow_zoa_debug_stelth_disable[];
extern const char sinow_zoa_debug_appear_ground[];
extern const char sinow_zoa_debug_appear_roof[];
extern const char sinow_zoa_debug_tecniq_attack[];
extern const char sinow_zoa_debug_stelth_on[];
extern const char sinow_zoa_debug_stelth_off[];
extern const char sinow_zoa_debug_warp[];
extern const char sinow_zoa_debug_tex_spigell[];
extern const char sinow_zoa_debug_tex_berill[];
}
#endif
