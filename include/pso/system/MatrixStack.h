#ifndef PSO_SYSTEM_MATRIXSTACK_H
#define PSO_SYSTEM_MATRIXSTACK_H

#include "types.h"
#include <dolphin/mtx.h>

// The model matrix stack the Ninja-style draw code works on, and the
// screen projection it feeds.
extern "C" {
// Copies source into dest. A null argument uses the current matrix.
void copy_matrix(MtxP dest, const f32 (*source)[4]);
// Post-multiplies dest by source. A null argument uses the current matrix.
void concat_matrix(MtxP dest, const f32 (*source)[4]);
void post_translate_matrix(const f32 *v);
void scale_current_matrix(const f32 *v);
// ang is an NJS_OBJECT ang[3]; zxy != 0 applies the angles in Z, X, Y order.
void rotate_matrix_by_node_angles(const s32 *ang, u32 zxy);
void transform_point_by_current_matrix(const f32 *src, Vec *dst);
// dst = the current matrix's rotation applied to src.
void rotate_vector_by_current_matrix(const Vec *src, Vec *dst);
// Projects a world point through `mtx` (the current view when NULL) to
// screen x/y.
void project_world_to_screen(u8 *mtx, const Vec *pos, f32 *screen);
}

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

struct ConcatQuaternionRotationQ { f32 x, y, z, w; };

struct ApplyQuatRotationQ { f32 x, y, z, w; };

struct InitTextureFromGvrDescA { u8 pad[0xC]; u8 *p; };

struct InitTextureFromGvrDescB { s32 a; u16 b; u16 c; };

struct Matrix34 { f32 elements[3][4]; };

struct Ent_803D9E38 { u8 *p; s32 a; s32 b; };

struct ResolveTexlistEntryTable { u8 pad[8]; Ent_803D9E38 arr[1]; };

#endif
