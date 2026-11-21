#ifndef PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H
#define PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H

#include "types.h"

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct OlgaFlowScenePart {
    NJS_OBJECT *model;
    GinjaTextureList *texture;
    AnimationMotion *motion;
};

LAYOUT_ASSERT(OlgaFlowScenePart_size, sizeof(OlgaFlowScenePart) == 0xC);

#endif
