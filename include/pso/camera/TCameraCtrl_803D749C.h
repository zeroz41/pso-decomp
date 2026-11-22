#ifndef PSO_CAMERA_TCAMERACTRL_803D749C_H
#define PSO_CAMERA_TCAMERACTRL_803D749C_H

#include "types.h"

// --- C functions defined in TCameraCtrl_803D749C.cpp ---
extern "C" {
s32 TObjPlayer__sub_803D7FD0(void);
s32 TObjPlayer__sub_803D7FD8(void);
}
void bind_motion_blend_channels(NJS_MOTION_LINK *motion, f32 blend_factor);
void bind_motion_context(NJS_MOTION *motion, f32 frame);
void compose_motion_node_matrix(void *arg0);
// --- end of C functions

// camera_motion_context_table: layout known from its uses only.
struct CameraMotionContextTable { s32 value; u8 remaining[0x7C]; };
extern CameraMotionContextTable camera_motion_context_table;

#endif
