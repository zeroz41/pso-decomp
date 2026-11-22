#include "types.h"
#include "pso/animation/MotionContext.h"

// Interim data-only unit: these two .sbss words sit between MotionContext.cpp's .sbss (which ends on its
// 4 B pad) and text_803D853C's, and the .text between those two units is contiguous, so the code that defines these
// two has not been found yet. Fold this file into that unit once it is.

// Called for every node while draw_motion_node_tree_with_context walks a motion tree; init_projection_state
// sets it.
void *motion_node_draw_callback;

// The motion sampler state that select_motion_sampler, bind_motion_channel_samplers and the motion row helpers read.
MotionContext *current_motion_context;
