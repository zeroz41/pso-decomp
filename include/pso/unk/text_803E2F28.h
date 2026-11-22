#ifndef PSO_UNK_TEXT_803E2F28_H
#define PSO_UNK_TEXT_803E2F28_H

#include "types.h"

extern "C" {
void TObjPlayer__sub_803E492C(s32 a, s32 b);
}
void apply_chunk_texture_command(s32 header, s32 arg1);
void draw_chunk_model(void *model);
extern "C" {
void draw_chunk_object(void *child);
}
void set_chunk_alpha_compare_ref(int ref);
void set_chunk_blend(u32 x);
void set_chunk_blend_depth_mode(s32 header, s32 arg1);
void set_strip_lighting_chan_ctrl(u32 flags);
void setup_chunk_tev_stages(void);
void submit_chunk_material_color(s32 type, s16 *data);

void set_chunk_render_flags(u32 flags);

void clear_chunk_render_flags();

#endif
