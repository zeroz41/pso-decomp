#ifndef PSO_QUEST_CHALLENGE_CHALLENGESTAGELOADOUTS_H
#define PSO_QUEST_CHALLENGE_CHALLENGESTAGELOADOUTS_H
#include "pso/player/TPlyInventory.h"

struct ChallengeTechniqueLevel {
    s32 technique;
    s32 level;
};
struct ChallengeStageStart {
    s32 level;
    s32 item_count;
    TPlyInventoryItem* items;
    ChallengeTechniqueLevel* techniques;
};

extern "C" {
extern ChallengeStageStart force_stage_start_parameters[16];
extern ChallengeStageStart hunter_stage_start_parameters[16];
extern ChallengeStageStart ranger_stage_start_parameters[16];
}
#endif
