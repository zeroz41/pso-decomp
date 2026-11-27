#ifndef PSO_ENEMY_SHINOWA_SHINOWADATA_H
#define PSO_ENEMY_SHINOWA_SHINOWADATA_H
#include "types.h"
#include "pso/effect/TBreakUpMdl.h"

// The Shinowa code's constant objects, defined by ShinowaData.cpp.
// What state_break_apart hands to create_breakup_mdl.
extern const BreakUpParamRow shinowa_mirage_breakup_params;
// TLobby kind ids, one list per TLobby table load_shinowa_mirage_resources registers them with
// (inferred: the base/attack/resistance/behavior_params_by_variant tables they fill).
extern const s32 shinowa_mirage_base_param_ids[2];
extern const s32 shinowa_mirage_attack_param_ids[2];
extern const s32 shinowa_mirage_resistance_param_ids[2];
extern const s32 shinowa_mirage_behavior_param_ids[2];
extern const char shinowa_model[];
extern const char shinowa_apper_motion[];
extern const char shinowa_backstep_motion[];
extern const char shinowa_damage_motion[];
extern const char shinowa_death_motion[];
extern const char shinowa_f_attack_motion[];
extern const char shinowa_sword_motion[];
extern const char shinowa_transform_motion[];
extern const char shinowa_t_wait_motion[];
extern const char shinowa_wait_motion[];
extern const char shinowa_walk_motion[];
extern const char shinowa_bml[];
#endif
