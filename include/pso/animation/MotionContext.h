#ifndef PSO_ANIMATION_MOTIONCONTEXT_H
#define PSO_ANIMATION_MOTIONCONTEXT_H

#include "types.h"

struct NJS_MOTION;
struct NJS_MOTION_LINK;

void bind_motion_context(NJS_MOTION *motion, f32 frame);

void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor);

#endif
