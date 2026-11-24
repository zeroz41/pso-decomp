#ifndef PSO_UNK_TEXT_803E4D8C_H
#define PSO_UNK_TEXT_803E4D8C_H

#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"

struct RenderCounterState {
    s32 base;
    s32 stride;
    s32 double_stride;
    s32 cursor_a;
    s32 cursor_b;
    f32 frame;
    s32 shape_aux;
    s32 count;
};

extern "C" {
void TObjPlayer__sub_803E500C(void *motA, s32 keyA, void *motB, s32 keyB, f32 t, u32 *src, u32 * *out);
void TObjPlayer__sub_803E5378(s32 n);
void TObjPlayer__sub_803E53F8(u8 *shape, f32 frame);
void TObjPlayer__sub_803E5458(s32 arg0);
}

// --- C functions defined in text_803E4D8C.cpp ---
extern "C" {
void TObjPlayer__sub_803E500C(void *motA, s32 keyA, void *motB, s32 keyB, f32 t, u32 *src, u32 * *out);
void TObjPlayer__sub_803E5378(s32 n);
void TObjPlayer__sub_803E53F8(u8 *shape, f32 frame);
void TObjPlayer__sub_803E5458(s32 arg0);
}
// --- end of C functions

#endif
