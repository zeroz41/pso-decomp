#ifndef PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H
#define PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H

#include "types.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct DarkFalzScenePart {
    NJS_OBJECT *model;
    GinjaTextureList *texlist;
    AnimationMotion *motion;
};

LAYOUT_ASSERT(DarkFalzScenePartSize, sizeof(DarkFalzScenePart) == 0xC);

#endif
