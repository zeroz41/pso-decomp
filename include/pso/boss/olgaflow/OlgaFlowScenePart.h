#ifndef PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H
#define PSO_BOSS_OLGAFLOW_OLGAFLOWSCENEPART_H

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct OlgaFlowScenePart {
    NJS_OBJECT *model;
    GinjaTextureList *texture;
    AnimationMotion *motion;
};

typedef char OlgaFlowScenePart_size[sizeof(OlgaFlowScenePart) == 0xC ? 1 : -1];

#endif
