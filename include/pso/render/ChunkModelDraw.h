#ifndef PSO_RENDER_CHUNKMODELDRAW_H
#define PSO_RENDER_CHUNKMODELDRAW_H

#include "types.h"
#include "pso/system/ModelDrawCallback.h"
#include <dolphin/mtx/GeoTypes.h>

// One vertex of the chunk vertex cache: transformed position and normal, then
// the vertex colour and a pad word to 32 bytes.
struct ChunkCachedVertex {
    Vec pos;
    Vec normal;
    u32 color;
    u32 pad;
};
LAYOUT_ASSERT(ChunkCachedVertex_size, sizeof(ChunkCachedVertex) == 0x20);

// One recorded chunk vertex cache: the transformed vertices of one model draw.
struct ChunkCacheBuffer {
    void *vertices;
    s32 bytes;
};
struct ChunkCacheRecording {
    ChunkCacheBuffer buffers[32];
    s32 index;
};

// The current 3x4 matrix as the weighted-vertex transform stores it, in
// paired-single order.
struct ChunkPairedMatrix {
    f32 m00, m10;
    f32 m20, m01;
    f32 m11, m21;
    f32 m02, m12;
    f32 m22, m03;
    f32 m13, m23;
};
LAYOUT_ASSERT(ChunkPairedMatrix_size, sizeof(ChunkPairedMatrix) == 0x30);

// A chunk vertex stream entry: position then normal, untransformed.
struct ChunkVertexPosNormal {
    Vec pos;
    Vec normal;
};
LAYOUT_ASSERT(ChunkVertexPosNormal_size, sizeof(ChunkVertexPosNormal) == 0x18);

struct WeightedChunkVertex {
    ChunkVertexPosNormal vertex;
    s16 weight;
    u16 index;
};
LAYOUT_ASSERT(WeightedChunkVertex_size, sizeof(WeightedChunkVertex) == 0x1C);

// NJD_CV_VN_D8 records: position, normal and a diffuse colour.
struct ChunkVertexNormalColor {
    Vec pos;
    Vec normal;
    f32 color;
};

struct NJS_OBJECT;
struct NJS_MOTION;
struct NJS_MOTION_LINK;

void init_chunk_draw(saddr vertex_buffer, s32 vertex_buffer_size);
void apply_chunk_texture_command(s32 header, s32 texture_word);
void draw_chunk_model(void *model);
extern "C" {
void draw_chunk_object(void *child);
}
void set_chunk_alpha_compare_ref(u8 ref);
void set_chunk_blend(u32 x);
void set_chunk_blend_depth_mode(s32 header, s32 textured);
void set_strip_lighting_chan_ctrl(u32 flags);
void setup_chunk_tev_stages(void);
void submit_chunk_material_color(s32 type, s16 *data);

void set_chunk_render_flags(u32 flags);

void clear_chunk_render_flags();

// Clears the translucent (0x200) and opaque (0x400) strip marks that
// set_chunk_blend_depth_mode leaves in chunk_render_flags.
void clear_chunk_strip_blend_flags();
// Called by end_chunk_draw after every chunk model.
extern void (*player_chunk_draw_end_callback)();
void set_chunk_draw_end_callback(void (*callback)());
// A chunk model draw is setup_model_draw_state, draw_chunk_vertices_cached
// for every model in the tree, then end_chunk_draw.
void setup_model_draw_state(void *model);
s32 draw_chunk_vertices_cached(void *model);
void end_chunk_draw();

// Draws model posed by motion and deformed by shape (a Ninja shape motion) at frame.
void draw_chunk_model_with_shape_motion(void *model, void *motion, NJS_MOTION *shape, f32 frame);
void draw_blend_motion_tree(NJS_OBJECT *model, NJS_MOTION_LINK *motion, f32 blend_factor, ModelDrawCallback draw_model);
void draw_shape_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, NJS_MOTION *shape, f32 frame, ModelDrawCallback draw_model);
void draw_model_blend_motion(void *model, void *motion, f32 blend_factor);
extern "C" {
void draw_model_motion(void *model, void *motion, f32 frame);
}
void draw_motion_tree(NJS_OBJECT *model, NJS_MOTION *motion, f32 frame, ModelDrawCallback draw_model);
void draw_object_tree_recursive(NJS_OBJECT *node);
// Motions sample packed (16-bit) rotation keys while set.
extern s32 motion_packed_rotation_mode;
void set_motion_packed_rotation();
void clear_motion_packed_rotation();
void traverse_animated_node_tree(NJS_OBJECT *node);

// ShapeMotionDraw.cpp: shape motions (per-node vertex and normal keys).
// Bits of the current chunk draw (set_chunk_render_flags, and the strip marks
// set_chunk_blend_depth_mode leaves).
extern u32 chunk_render_flags;
void draw_shape_motion_node_tree(NJS_OBJECT *node);
void sample_shape_vertices(void **src, void **dst);
void interpolate_shape_vertices(void *vertex_keys, u32 vertex_key_count, void *normal_keys, u32 normal_key_count,
                                f32 frame, u32 *src, void **out);
void set_shape_motion_row_stride(s32 channels);
void advance_shape_motion_row();
void bind_shape_motion(NJS_MOTION *shape, f32 frame);
void select_shape_motion_context(s32 index);
// The buffer interpolate_shape_vertices writes vertex lists to.
void set_shape_vertex_buffer(u32 *buffer);
// sample_shape_vertices, then moves to the next node's row.
void sample_shape_node_vertices(void **src, void **dst);

#endif
