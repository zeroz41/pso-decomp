#ifndef PSO_UNK_TEXT_803D96A8_H
#define PSO_UNK_TEXT_803D96A8_H

#include "types.h"
#include <dolphin/mtx.h>
struct Vec;

struct TLobby;
extern "C" {
void TObjPlayer__sub_803D9C60(u32 *p);
s32 TObjPlayer__sub_803D9E38(s32 *arg0, u32 idx, s32 *arg2, u32 *arg3);
}
u32 *find_gvrt_texture_chunk(TLobby *arg0, u32 *arg1, u32 *arg2);
s32 pop_matrices(s32 arg0);
void apply_quat_rotation(f32 w, f32 *xyz);
// dst = src * dst; a 0 dst or src stands for the top of the matrix stack.
void premultiply_matrix(MtxP dest, const f32 (*source)[4]);
extern "C" {
// Both return TRUE (pop_matrix FALSE when the stack is already empty).
s32 push_matrix(void);
s32 pop_matrix(void);
s32 push_matrix_from(void *src);
// Scales v to unit length in place and returns its original length.
f32 normalize_vector(Vec *v);
}

#endif
