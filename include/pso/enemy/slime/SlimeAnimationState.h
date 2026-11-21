#ifndef PSO_ENEMY_SLIMEANIMATIONSTATE_H
#define PSO_ENEMY_SLIMEANIMATIONSTATE_H

#include "types.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/NinjaTypes.h"

struct GinjaTextureList;
struct TObjEneSlimeOne;

struct SlimeShapeMotion {
    s32 motion;
    s32 shape_motion;
    f32 speed;
};

struct SlimePairedMotion {
    s32 model;
    s32 motion;
    s32 second_model;
    s32 second_motion;
    f32 speed;
};

struct SlimeAnimationState {
    SlimeAnimationState(TObjEneSlimeOne *owner);
    ~SlimeAnimationState();

    void draw(s32 deferred);
    void advance();
    s32 is_finished();
    void set_state(s32 state);

    TObjEneSlimeOne *owner;
    s32 state;
    NJS_OBJECT *model;
    GinjaTextureList *texture_list;
    AnimationMotion *motion;
    AnimationMotion *shape_motion;
    NJS_OBJECT *second_model;
    GinjaTextureList *second_texture_list;
    AnimationMotion *second_motion;
    u32 unknown24;
    f32 speed;
    f32 frame_count;
    f32 frame;
};

typedef char SlimeAnimationStateSize[sizeof(SlimeAnimationState) == 0x34 ? 1 : -1];

#endif
