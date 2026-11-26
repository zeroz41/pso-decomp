#include "types.h"
#include "pso/player/PlayerClassTechniques.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

// Technique power boost per class (19 techniques).
static const f32 no_technique_boosts[19] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
static const f32 fomarl_technique_boosts[19] = {
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.5f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
};
static const f32 fonewm_technique_boosts[19] = {
    0.0f, 0.3f, 0.3f, 0.0f, 0.3f, 0.3f, 0.0f, 0.3f, 0.3f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};
static const f32 fonewearl_technique_boosts[19] = {
    0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f,
};
static const f32 fomar_technique_boosts[19] = {
    0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.0f, 0.3f, 0.0f, 0.3f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
};

// Technique boost row per character class (12 classes).
const f32 *class_technique_boost_table[12] = {
    no_technique_boosts, no_technique_boosts, no_technique_boosts, no_technique_boosts, no_technique_boosts, no_technique_boosts,
    fomarl_technique_boosts, fonewm_technique_boosts, fonewearl_technique_boosts, no_technique_boosts, fomar_technique_boosts, no_technique_boosts,
};

f32 get_class_technique_boost(s8 cls, s16 technique) {
    return class_technique_boost_table[clamp_class_index(cls)][technique];
}
extern "C" {

u8 get_class_technique_cap(s8 cls, s16 technique) {
    return class_technique_cap_table[clamp_class_index(cls)][technique];
}
}

void init_class_technique_caps(PlayerTechniqueState *techs, s8 cls) {
    s32 i;
    s32 n = PlayerTechniqueState::technique_count();
    for (i = 0; i < n; ) {
        techs->levels[i] = get_class_technique_cap(cls, i);
        i++;
    }
}
