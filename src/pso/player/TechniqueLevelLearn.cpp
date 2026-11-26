#include "types.h"
#include "pso/player/PlayerTechniqueState.h"

void PlayerTechniqueState::set_learned_level(s16 technique, u8 level) {
    learned_levels[technique] = level;
}
