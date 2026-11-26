#ifndef PSO_SYSTEM_SCENE_TENDINGABTYPES_H
#define PSO_SYSTEM_SCENE_TENDINGABTYPES_H

#include "types.h"

struct EndingWallTextureSet {
    NJS_TEXNAME names[14];
    NJS_TEXLIST list;
};
LAYOUT_ASSERT(EndingWallTextureSetSize, sizeof(EndingWallTextureSet) == 0xB0);

#endif
