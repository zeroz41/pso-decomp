#ifndef PSO_RENDER_GINJAMATERIAL_H
#define PSO_RENDER_GINJAMATERIAL_H

#include "types.h"

// Called once a Ginja model draw ends (install_depth_alpha_state sets it).
typedef void (*GinjaDrawEndCallback)(void);
extern GinjaDrawEndCallback ginja_draw_end_callback;
void set_ginja_draw_end_callback(GinjaDrawEndCallback callback);
void set_ginja_post_tev_stage_count(s32 x);
void set_ginja_post_texgen_count(s32 x);

extern "C" {
void draw_ginja_model(void *model);
void draw_ginja_object(void *child);
}
void end_ginja_model_draw(void);
s32 get_ginja_vertex_descriptor_type(u32 value, s32 attribute);
void ginja_load_texture_slot(u32 texture_word, u32);
void ginja_set_alpha_compare(u8 ref);
void ginja_set_vertex_format(u32 format, u32);
void load_ginja_model_matrices(int matrix_id);
extern "C" {
void prepare_ginja_model(void);
// Global colour parameters, packed 0xRRGGBBAA.
void set_global_color_rgba(u32 v, u32);
void set_global_color_rgba_alt_b(u32 v, u32);
void set_global_effect_state(s32 global_effect_state);
}
s32 queue_model_draw_current_matrix(void *model);
void set_ginja_blend_param(u32 x, u32);
void set_ginja_channel_counts(u32 value, u32 changed);
void set_ginja_channel_ctrl(s32 channel, s32 flags);
void set_ginja_indexed_vtx_desc(u32 value, u32);
void set_ginja_material_color(u32 v, u32);
void set_ginja_tev_order(u32 parameter, u32);
void set_ginja_texcoord_gen(u32 ginja_texcoord_gen, u32);
u32 update_ginja_cached_parameter(s32 i, u32 v);

#endif
