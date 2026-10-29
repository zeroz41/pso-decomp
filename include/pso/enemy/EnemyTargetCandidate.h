#ifndef PSO_ENEMY_ENEMYTARGETCANDIDATE_H
#define PSO_ENEMY_ENEMYTARGETCANDIDATE_H
#include "types.h"

struct EnemyTargetCandidate {
    u32 id;
    f32 distance_squared;
    void copy_from(const EnemyTargetCandidate *source);
};

typedef char EnemyTargetCandidate_size[sizeof(EnemyTargetCandidate) == 8 ? 1 : -1];

#endif
