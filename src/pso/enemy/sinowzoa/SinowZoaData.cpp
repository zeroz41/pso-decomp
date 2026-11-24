#include "pso/effect/TBreakUpMdl.h"
#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/enemy/sinowzoa/SinowZoaData.h"

// String objects are named after their contents.
// .rodata 0x80475DF0-0x80476098 of the Sinow Zoa code (the DelDepthData.cpp shape): the code
// addresses each object on its own, so it did not compile them itself.


extern const BreakUpParamRow sinow_zoa_breakup_params = { 0x14, 0.07f, 2.0f, 0.97f, 0.2f, 2.0f, 1.5f };
// TLobby kind ids for the two Sinow Zoa kinds, one list per TLobby table
// TObjEneMe3SinowZoa::load_resources registers them with.
extern const s32 sinow_zoa_base_param_ids[2] = { 0x43, 0x44 };
extern const s32 sinow_zoa_attack_param_ids[2] = { 0x43, 0x44 };
extern const s32 sinow_zoa_resistance_param_ids[2] = { 0x43, 0x44 };
extern const s32 sinow_zoa_kind_param_ids[2] = { 0x43, 0x44 };
extern const char sinow_zoa_model[] = "me3_y_me3.nj";
extern const char sinow_zoa_t_wait_motion[] = "t_wait_me3_y_me3.njm";
extern const char sinow_zoa_apper_motion[] = "apper_me3_y_me3.njm";
extern const char sinow_zoa_backstep_motion[] = "backstep_me3_y_me3_1.njm";
extern const char sinow_zoa_bareta_motion[] = "bareta_me3_y_me3.njm";
extern const char sinow_zoa_damage_motion[] = "damage_me3_y_me3.njm";
extern const char sinow_zoa_death_motion[] = "death_me3_y_me3.njm";
extern const char sinow_zoa_f_attack_motion[] = "f_attack_me3_y_me3.njm";
extern const char sinow_zoa_sword_motion[] = "sword_me3_y_me3.njm";
extern const char sinow_zoa_transform_motion[] = "transform_me3_y_me3_1.njm";
extern const char sinow_zoa_wait_motion[] = "wait_me3_y_me3.njm";
extern const char sinow_zoa_walk_motion[] = "walk_me3_y_me3.njm";
extern const char sinow_zoa_bml[] = "bm_ene_me3_shinowa_zoa.bml";
extern const char sinow_zoa_low_model[] = "lo_me3_y_me3.nj";
extern const char sinow_zoa_low_bml[] = "bm_ene_me3_zoa_low.bml";
extern const char sinow_zoa_class_name[] = "TObjEneMe3SinowZoa";
extern const char sinow_zoa_real_class_name[] = "TObjEneMe3SinowZoaReal";
extern const NpcAnimationBinding sinow_zoa_attack_binding_desc_a = { NULL, TObjEneMe3SinowZoa__animation_descriptors, 9, 10, 13 };
extern const NpcAnimationBinding sinow_zoa_attack_binding_desc_b = { NULL, TObjEneMe3SinowZoa__animation_descriptors, 0, 0, 13 };
extern const Vec sinow_zoa_barta_origin_offset = {0.0f, 0.0f, 0.0f};
extern const char sinow_zoa_debug_stelth_enable[] = "STELTH:ENABLE";
extern const char sinow_zoa_debug_stelth_disable[] = "STELTH:DISABLE";
extern const char sinow_zoa_debug_appear_ground[] = "APPEAR:GROUND";
extern const char sinow_zoa_debug_appear_roof[] = "APPEAR:ROOF";
extern const char sinow_zoa_debug_tecniq_attack[] = "TECNIQ ATTACK % (+0.4f)";
extern const char sinow_zoa_debug_stelth_on[] = "STELTH ON %     (+0.3f)";
extern const char sinow_zoa_debug_stelth_off[] = "STELTH OFF %    (+0.1f)";
extern const char sinow_zoa_debug_warp[] = "WARP %          (+0.5f)";
extern const char sinow_zoa_debug_tex_spigell[] = "TEX:SINOWA=SPIGELL";
extern const char sinow_zoa_debug_tex_berill[] = "TEX:SINOWA=BERILL";
