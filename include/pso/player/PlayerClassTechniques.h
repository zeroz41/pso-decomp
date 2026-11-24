#ifndef PSO_PLAYER_PLAYERCLASSTECHNIQUES_H
#define PSO_PLAYER_PLAYERCLASSTECHNIQUES_H

#include "types.h"

class PlayerTechniqueState;

extern "C" {
f32 get_class_technique_boost(s8 cls, s16 technique);
u8 get_class_technique_cap(s8 cls, s16 technique);
void init_class_technique_caps(PlayerTechniqueState *techs, s8 cls);
}

#endif
