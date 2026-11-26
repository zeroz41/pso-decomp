#ifndef PSO_UNK_TEXT_803D96A8_H
#define PSO_UNK_TEXT_803D96A8_H

#include "types.h"
#include <dolphin/mtx.h>
struct Vec;

struct TLobby;
void swap_gvrt_word(u32 *p);
s32 resolve_texlist_entry(s32 *texlist, u32 idx, s32 *out_surface, u32 *out_tlut);
// Multiplies the current matrix by the rotation of quat (w, x, y, z).
void concat_quaternion_rotation(const f32 *quat);
// 1 once no texture transfer is pending, -1 otherwise.
s32 is_gvm_load_ok(void);
u32 *find_gvrt_texture_chunk(TLobby *lobby, u32 *out_id, u32 *data);
s32 pop_matrices(s32 count);
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
