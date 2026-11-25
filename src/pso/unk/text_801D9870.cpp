#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 get_cast_technique_level(PlayerTechniqueState *techs, s16 tech);
u8 get_cast_technique_level(PlayerTechniqueState *techs, s16 tech) {
    u8 level;
    if (PlayerTechniqueState::is_valid_technique_id(tech) == 0) {
        return 0;
    }
    level = techs->learned_levels[tech];
    if (techs->check_technique_level(tech, level) == 0) {
        level = 0x1D;
    }
    return techs->clamp_to_max(level, techs->get_effective_technique_level(tech));
}

}
