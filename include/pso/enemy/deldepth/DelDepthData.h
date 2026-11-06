#ifndef PSO_ENEMY_DELDEPTH_DELDEPTHDATA_H
#define PSO_ENEMY_DELDEPTH_DELDEPTHDATA_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

struct DelDepthParameters {
    f32 accel;
    f32 maxSpeed;
    u8 unknown08[0x10];
    s32 techniqueLevel;
    s32 turnSpeed;
};

struct DelDepthAnimationBinding {
    void *motions;
    TObjMotionAction *actions;
    u32 unknown08;
    u16 actionCount;
    u16 unknown0E;
};

extern "C" {
extern DelDepthParameters *TObjEneDelDepth__tune_params;
extern BmlResource *TObjEneDelDepth__shared_resource;
extern const DelDepthAnimationBinding deldepth_anim_binding;
extern const DelDepthAnimationBinding deldepth_anim_binding_b;
}
#endif
