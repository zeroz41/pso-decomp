#ifndef PSO_ENEMY_DELDEPTH_DELDEPTHDATA_H
#define PSO_ENEMY_DELDEPTH_DELDEPTHDATA_H
#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"

struct DelDepthParameters {
    f32 accel;
    f32 maxSpeed;
    u8 pad_08[0x10];
    s32 techniqueLevel;
    s32 turnSpeed;
};

extern DelDepthParameters *TObjEneDelDepth__tune_params;
extern BmlResource *TObjEneDelDepth__shared_resource;
#endif
