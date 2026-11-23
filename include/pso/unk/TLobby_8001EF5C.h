#ifndef PSO_UNK_TLOBBY_8001EF5C_H
#define PSO_UNK_TLOBBY_8001EF5C_H

#include "pso/system/BmlAccessors.h"

#include "types.h"

extern "C" {
void *allocate_bml_chunk(BmlResource *resource, u8 *file, u32 *offset, u32 *tag);
void increment_ref_and_set_flag__6TLobbyFPv(void *context);
}
struct BmlModelLoadRequest;
struct BmlMotionLoadRequest;
struct AnimationMotion;
void load_bin_model_callback(BmlModelLoadRequest *request);
void load_bin_motion_callback(BmlMotionLoadRequest *request);

// --- C functions defined in TLobby_8001EF5C.cpp ---
extern "C" {

int fn_8001ED90(void *p);

AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
void increment_ref_and_set_flag__6TLobbyFPv(void *context);
}
// --- end of C functions

#endif
