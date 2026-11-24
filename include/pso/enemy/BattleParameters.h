#ifndef PSO_ENEMY_BATTLEPARAMETERS_H
#define PSO_ENEMY_BATTLEPARAMETERS_H

#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TPlyDispData.h"

// Movement parameters contain six float words followed by six integer words.
union BattleMovementParams {
    struct {
        f32 floats[6];
        s32 integers[6];
    } values;
    struct {
        u32 floats[6];
        u32 integers[6];
    } words;
};

struct BattleParameterBank {
    player_stats stats[96];
    AttackParams attacks[96];
    ActorParamBlock resistances[96];
    BattleMovementParams movement[96];
};

struct BattleParameterFile {
    player_stats stats[4][96];
    AttackParams attacks[4][96];
    ActorParamBlock resistances[4][96];
    BattleMovementParams movement[4][96];
};

LAYOUT_ASSERT(BattleParameterResistanceSize, sizeof(ActorParamBlock) == 0x20);
LAYOUT_ASSERT(BattleParameterMovementSize, sizeof(BattleMovementParams) == 0x30);
LAYOUT_ASSERT(BattleParameterBankSize, sizeof(BattleParameterBank) == 0x3D80);
LAYOUT_ASSERT(BattleParameterFileSize, sizeof(BattleParameterFile) == 0xF600);

extern "C" {
extern BattleParameterBank *battle_parameter_buffer;
extern player_stats *battle_param_stats;
extern AttackParams *battle_param_attacks;
extern ActorParamBlock *battle_param_resistances;
extern BattleMovementParams *battle_param_movement;
extern s32 battle_parameter_difficulty;
extern s32 battle_param_lab_variant;
}

#endif
