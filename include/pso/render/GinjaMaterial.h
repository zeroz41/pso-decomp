#ifndef PSO_RENDER_GINJAMATERIAL_H
#define PSO_RENDER_GINJAMATERIAL_H

#include "types.h"

extern "C" {
void draw_ginja_model(s32 model);
void draw_ginja_object(void *child);
}
void end_ginja_model_draw(void);
s32 get_ginja_vertex_descriptor_type(u32 arg0, s32 arg1);
void ginja_load_texture_slot(u32 arg0);
void ginja_set_alpha_compare(s32 ref);
void ginja_set_vertex_format(u32 arg0);
s32 load_ginja_model_matrices(int arg0);
extern "C" {
void prepare_ginja_model(void);
}
s32 queue_model_draw_current_matrix(s32 model);
void set_ginja_blend_param(u32 x);
void set_ginja_channel_counts(s32 flags, s32 arg1);
void set_ginja_channel_ctrl(s32 channel, s32 flags);
void set_ginja_indexed_vtx_desc(s32 arg0);
void set_ginja_material_color(u32 v);
void set_ginja_tev_order(u32 parameter);
void set_ginja_texcoord_gen(u32 arg0);
u32 update_ginja_cached_parameter(s32 i, u32 v);

#endif
