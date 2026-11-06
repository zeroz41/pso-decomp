#ifndef PSO_TECHNIQUE_TECHNIQUECHARGEEMITTER_H
#define PSO_TECHNIQUE_TECHNIQUECHARGEEMITTER_H

#include "types.h"

struct TechniqueChargeEmitter {
    u8 task[0x1C];
    void* actor;
    float position[3];
    s32 age;
    u32 playback;
};
typedef char TechniqueChargeEmitterSize[(sizeof(TechniqueChargeEmitter)==0x34)?1:-1];

#endif
