#ifndef PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H
#define PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H

#include "types.h"

struct AnimationMotion;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct OlgaFlowScenePart {
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;
    AnimationMotion *motion;
};

LAYOUT_ASSERT(OlgaFlowScenePart_size, sizeof(OlgaFlowScenePart) == 0xC);

// The demos' TBoss6Demo*__name .sdata entries: the class name the ctor stores in m_name, padded to 8.
struct AppearanceClassTag { const char *value; u32 padding; };

#endif
