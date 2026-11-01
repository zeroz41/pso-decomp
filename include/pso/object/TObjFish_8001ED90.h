#ifndef PSO_OBJECT_TOBJFISH_8001ED90_H
#define PSO_OBJECT_TOBJFISH_8001ED90_H

#include "types.h"

struct BmlResource;
struct AnimationMotion;

extern "C" {
int fn_8001ED90(void *p);
}

// --- C functions defined in TObjFish_8001ED90.cpp ---
extern "C" {
int fn_8001ED90(void *p);
// The index-th motion and texture list of a loaded BML archive.
AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
s32 TObjFish__sub_8001EDB0(BmlResource *resource, s32 index);
}
// --- end of C functions

#endif
