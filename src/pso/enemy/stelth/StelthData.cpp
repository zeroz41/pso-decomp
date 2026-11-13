#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"

#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/enemy/deldepth/DelDepthData.h"
#include "pso/enemy/stelth/StelthData.h"

// String objects are named after their contents.
// .rodata 0x8043D450-0x8043D750 of the Stelth code (the SinowZoaData.cpp shape): the code
// addresses each object on its own, so it did not compile them itself.

extern "C" {
extern const NJS_ARGB me3_stelth_offset_vec = {-0.8f, 0.0f, 0.0f, 0.0f};
extern const TBoss3VoloptBreakupParams me3_stelth_breakup_params = { 0x14, { 0.07f, 2.0f, 0.97f, 0.2f, 2.0f, 1.5f } };
// TLobby kind ids, one list per TLobby table
// TObjEneMe3Stelth::load_shared_resources registers them with.
extern const s32 lbl_8043D47C[2] = { 6, 19 };
extern const s32 lbl_8043D484[2] = { 6, 71 };
extern const s32 lbl_8043D48C[2] = { 6, 19 };
extern const s32 lbl_8043D494[2] = { 6, 16 };
extern const char stelth_model[] = "me3_y_me3.gj";
extern const char stelth_t_wait_motion[] = "t_wait_me3_y_me3.njm";
extern const char stelth_apper_motion[] = "apper_me3_y_me3.njm";
extern const char stelth_backstep_motion[] = "backstep_me3_y_me3_1.njm";
extern const char stelth_bareta_motion[] = "bareta_me3_y_me3.njm";
extern const char stelth_damage_motion[] = "damage_me3_y_me3.njm";
extern const char stelth_death_motion[] = "death_me3_y_me3.njm";
extern const char stelth_f_attack_motion[] = "f_attack_me3_y_me3.njm";
extern const char stelth_sword_motion[] = "sword_me3_y_me3.njm";
extern const char stelth_transform_motion[] = "transform_me3_y_me3_1.njm";
extern const char stelth_wait_motion[] = "wait_me3_y_me3.njm";
extern const char stelth_walk_motion[] = "walk_me3_y_me3.njm";
extern const char stelth_bml[] = "bm_ene_me3_stelthshinowa.bml";
extern const char stelth_low_model[] = "lo_me3_y_me3.gj";
extern const char stelth_low_bml[] = "bm_ene_me3_beril_low.bml";
extern const char stelth_class_name[] = "TObjEneMe3Stelth";
extern const char stelth_real_class_name[] = "TObjEneMe3StelthReal";
extern const DelDepthAnimationBinding stelth_attack_binding_desc_a = {NULL, TObjEneMe3Stelth__animation_descriptors, 0x9000A, 13, 0};
extern const DelDepthAnimationBinding stelth_attack_binding_desc_b = {NULL, TObjEneMe3Stelth__animation_descriptors, 0, 13, 0};
extern const NJS_ARGB stelth_render_color_a = {-0.8f, 0.0f, 0.0f, 0.0f};
extern const NJS_ARGB stelth_render_color_b = {0.5f, 0.0f, 0.0f, 0.0f};
extern const NJS_ARGB me3_stelth_render_color = {0.5f, 0.0f, 0.0f, 0.0f};
extern const NJS_ARGB me3_stelth_secondary_render_color = {0.5f, 0.0f, 0.0f, 0.0f};
extern const s32 lbl_8043D680[3] = {0, 0, 0};
extern const char stelth_debug_stelth_enable[] = "STELTH:ENABLE";
extern const char stelth_debug_stelth_disable[] = "STELTH:DISABLE";
extern const char stelth_debug_appear_ground[] = "APPEAR:GROUND";
extern const char stelth_debug_appear_roof[] = "APPEAR:ROOF";
extern const char stelth_debug_tecniq_attack[] = "TECNIQ ATTACK % (+0.4f)";
extern const char stelth_debug_stelth_on[] = "STELTH ON %     (+0.3f)";
extern const char stelth_debug_stelth_off[] = "STELTH OFF %    (+0.1f)";
extern const char stelth_debug_warp[] = "WARP %          (+0.5f)";
extern const char stelth_debug_tex_spigell[] = "TEX:SINOWA=SPIGELL";
extern const char stelth_debug_tex_berill[] = "TEX:SINOWA=BERILL";
}
