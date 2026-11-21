#ifndef PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H
#define PSO_BOSS_DARKFALZ_DARKFALZSCENEPART_H

struct AnimationMotion;
struct GinjaTextureList;
struct NJS_OBJECT;

struct DarkFalzScenePart {
    NJS_OBJECT *model;
    GinjaTextureList *texlist;
    AnimationMotion *motion;
};

typedef char DarkFalzScenePartSize[sizeof(DarkFalzScenePart) == 0xC ? 1 : -1];

#endif
