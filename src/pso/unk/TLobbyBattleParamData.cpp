#include "pso/unk/TLobbyBattleParamData.h"

// The lobby battle parameter statics.

u8 auto_reply_flags[0x8];
BattleParameterBank *battle_parameter_buffer;
player_stats *battle_param_stats;
AttackParams *battle_param_attacks;
ActorParamBlock *battle_param_resistances;
BattleMovementParams *battle_param_movement;
s32 battle_parameter_difficulty;
s32 battle_param_lab_variant;
saddr lobby_instance;
