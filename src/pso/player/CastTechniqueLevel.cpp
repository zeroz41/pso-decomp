#include "types.h"
#include "pso/player/TObjPlayer.h"

u8 PlayerTechniqueState::get_cast_technique_level(s16 tech) {
    u8 level;
    if (is_valid_technique_id(tech) == 0) {
        return 0;
    }
    level = learned_levels[tech];
    if (check_technique_level(tech, level) == 0) {
        level = 0x1D;
    }
    return clamp_to_max(level, get_effective_technique_level(tech));
}
