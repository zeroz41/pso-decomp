#ifndef PSO_UNK_TLOBBYBATTLEPARAMDATA_H
#define PSO_UNK_TLOBBYBATTLEPARAMDATA_H

#include "types.h"

struct Params_8001DC30;

// The battle parameter file loaded for the current difficulty, and its tables.
extern Params_8001DC30 *TLobby__battle_parameter_buffer;
extern u8 *battle_param_stats;
extern u8 *TLobby__battle_param_attacks;
extern u8 *TLobby__battle_param_resistances;
extern u8 *battle_param_movement;
extern s32 battle_parameter_difficulty;
extern s32 battle_param_lab_variant;
extern saddr TLobby__lobby_instance;

#endif
