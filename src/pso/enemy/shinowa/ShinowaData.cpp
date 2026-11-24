#include "pso/effect/TBreakUpMdl.h"
#include "types.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"

#include "pso/enemy/shinowa/ShinowaData.h"

// String objects are named after their contents.
// .rodata 0x8043CE00-0x8043CF40 of the Shinowa code (the StelthData.cpp shape): the code
// addresses each object on its own, so it did not compile them itself.

extern const BreakUpParamRow shinowa_mirage_breakup_params = { 0x14, 0.07f, 2.0f, 0.97f, 0.2f, 2.0f, 1.5f };
extern const s32 shinowa_mirage_base_param_ids[2] = { 6, 19 };
extern const s32 shinowa_mirage_attack_param_ids[2] = { 6, 71 };
extern const s32 shinowa_mirage_resistance_param_ids[2] = { 6, 19 };
extern const s32 shinowa_mirage_behavior_param_ids[2] = { 6, 16 };
extern const char shinowa_model[] = "me3_y_me3.nj";
extern const char shinowa_apper_motion[] = "apper_me3_y_me3.njm";
extern const char shinowa_backstep_motion[] = "backstep_me3_y_me3.njm";
extern const char shinowa_damage_motion[] = "damage_me3_y_me3.njm";
extern const char shinowa_death_motion[] = "death_me3_y_me3.njm";
extern const char shinowa_f_attack_motion[] = "f_attack_me3_y_me3.njm";
extern const char shinowa_sword_motion[] = "sword_me3_y_me3.njm";
extern const char shinowa_transform_motion[] = "transform_me3_y_me3.njm";
extern const char shinowa_t_wait_motion[] = "t_wait_me3_y_me3.njm";
extern const char shinowa_wait_motion[] = "wait_me3_y_me3.njm";
extern const char shinowa_walk_motion[] = "walk_me3_y_me3.njm";
extern const char shinowa_bml[] = "bm_ene_me3_shinowa.bml";
