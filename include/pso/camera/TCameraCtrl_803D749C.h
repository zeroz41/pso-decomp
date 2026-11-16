#ifndef PSO_CAMERA_TCAMERACTRL_803D749C_H
#define PSO_CAMERA_TCAMERACTRL_803D749C_H

#include "types.h"

// --- C functions defined in TCameraCtrl_803D749C.cpp ---
extern "C" {
s32 TObjPlayer__sub_803D7FD0(void);
s32 TObjPlayer__sub_803D7FD8(void);
void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor);
void bind_motion_context(NJS_MOTION *motion, f32 farg0);
void compose_motion_node_matrix(void *arg0);
}
// --- end of C functions

#endif
