#ifndef PSO_PLAYER_PLAYERCLASSTECHNIQUES_H
#define PSO_PLAYER_PLAYERCLASSTECHNIQUES_H

#include "types.h"

class PlayerTechniqueState;

f32 get_class_technique_boost(s8 cls, s16 technique);
extern "C" {
u8 get_class_technique_cap(s8 cls, s16 technique);
}
void init_class_technique_caps(PlayerTechniqueState *techs, s8 cls);

// Technique level caps per character class; defined in TObjPlayer_801D8ADC.cpp (as const u8 *, but
// get_class_technique_cap reads it as u8 *: the const declaration changes its code).
extern u8 *class_technique_cap_table[12];

#endif
