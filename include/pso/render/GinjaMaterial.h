#ifndef PSO_RENDER_GINJAMATERIAL_H
#define PSO_RENDER_GINJAMATERIAL_H

#include "types.h"

extern "C" {
void draw_ginja_model(void *model);
void draw_ginja_object(void *child);
}
void end_ginja_model_draw(void);
s32 get_ginja_vertex_descriptor_type(u32 value, s32 arg1);
void ginja_load_texture_slot(u32 arg0, u32);
void ginja_set_alpha_compare(u8 ref);
void ginja_set_vertex_format(u32 arg0, u32);
void load_ginja_model_matrices(int matrix_id);
extern "C" {
void prepare_ginja_model(void);
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
