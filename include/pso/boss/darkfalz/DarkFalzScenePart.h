#ifndef PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H
#define PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H

#include "types.h"

struct NJS_MOTION;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct DarkFalzScenePart {
    NJS_OBJECT *model;
    NJS_TEXLIST *texlist;
    NJS_MOTION *motion;
};

LAYOUT_ASSERT(DarkFalzScenePartSize, sizeof(DarkFalzScenePart) == 0xC);

#endif
