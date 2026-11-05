#ifndef PSO_ENEMY_SINOWZOA_DATA_H
#define PSO_ENEMY_SINOWZOA_DATA_H
#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss3VoloptP01.h"
#include "pso/enemy/DelDepthData.h"

// .rodata 0x80475DF0-0x80476098, defined by SinowZoaData.cpp (the DelDepthData.cpp
// shape): TObjEneMe3SinowZoa.cpp addresses each object on its own.
extern "C" {
// TObjEneMe3SinowZoa.cpp .data; both animation bindings point at it.
extern TObjMotionAction lbl_804E8880[13];
extern const TBoss3VoloptBreakupParams sinow_zoa_breakup_params;
// TLobby kind ids for the two Sinow Zoa kinds, one list per TLobby table
// load_resources registers them with.
extern const s32 lbl_80475E0C[2];
extern const s32 lbl_80475E14[2];
extern const s32 lbl_80475E1C[2];
extern const s32 lbl_80475E24[2];
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
extern const DelDepthAnimationBinding lbl_80475FA8;
extern const DelDepthAnimationBinding lbl_80475FB8;
extern const Vec lbl_80475FC8;
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
