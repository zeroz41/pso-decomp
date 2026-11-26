#ifndef PSO_SYSTEM_MODELNODEPOSITIONCAPTURETYPES_H
#define PSO_SYSTEM_MODELNODEPOSITIONCAPTURETYPES_H

#include "types.h"

struct ModelNodePositionCaptureState {
    s32 node_index;
    const ModelNodePositionEntry *entries;
    Vec *positions;
    s32 unknown_0c;
};

#endif
