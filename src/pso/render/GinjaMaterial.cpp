#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/ModelDrawCallback.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaMaterialCache.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/GinjaParameterHandler.h"
#include "pso/render/GinjaModelQueue.h"
#include "pso/unk/text_803E2008.h"
#include "pso/render/GinjaModel.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth_803DC82C.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/render/model_render_state.h"
#include "pso/render/GinjaView.h"

#pragma scheduling off
typedef void (*GinjaPreCallback)(s32 first);
typedef void (*GinjaPostCallback)(u8 first);

extern "C" {
extern u32 ginja_draw_flags;
extern u32 gx_chan_ctrl_light_mask;
void set_ginja_vertex_arrays(GinjaVertexArray *array);
extern GinjaMaterialCache ginja_material_cache;
extern GXTexCoordID ginja_texcoord_ids[];
extern GXTexMapID ginja_texmap_ids[];
extern GXAttr ginja_vertex_attributes[];
extern GXCompCnt ginja_vertex_component_counts[];
extern GXCompType ginja_vertex_component_types[];
extern GXTexMtx ginja_texture_matrix_ids[];

u32 ginja_blend_override = 0x250F;

s32 lbl_805D76E0;
GinjaDrawEndCallback ginja_draw_end_callback;
GinjaPreCallback ginja_pre_channel_callback;
GinjaPreCallback ginja_pre_texgen_callback;
GinjaPreCallback ginja_pre_tev_callback;
GinjaPostCallback ginja_post_channel_callback;
GinjaPostCallback ginja_post_texgen_callback;
GinjaPostCallback ginja_post_tev_callback;
s32 ginja_texcoord_gen_enabled;
u32 ginja_draw_list_state;
s32 ginja_draw_list_mask;

GinjaMaterialCache ginja_material_cache;

void draw_ginja_object(void *child) {
    prepare_ginja_model();
    init_model_draw_queue(draw_ginja_model_lists);
    traverse_model_node_tree((NJS_OBJECT *)child, queue_model_draw_current_matrix);
    flush_model_draw_queue();
    if (ginja_draw_end_callback != NULL) {
        ginja_draw_end_callback();
    }
    if ((u32) (ginja_draw_flags & 2) != 0U) {
        TObjPlayer::set_effect_active();
        apply_scene_fog();
    }
}
}
void apply_ginja_material_params(const GinjaDrawRecord *);
GinjaMaterialCache *invalidate_ginja_inherited_state();
s32 queue_model_draw_current_matrix(void *model) {
    queue_model_draw_matrix(model, *current_matrix);
    return 1;
}

void draw_ginja_model(void *model) {
    load_ginja_model_matrices(0);
    prepare_ginja_model();
    draw_ginja_model_lists(model);
    end_ginja_model_draw();
}

s32 get_ginja_vertex_descriptor_type(u32 value, s32 arg1) {
    return (value >> (arg1 * 2)) & 3;
}

u32 update_ginja_cached_parameter(s32 i, u32 v) {
  u32 r = v ^ ginja_material_cache.parameters[i];
  r |= ginja_material_cache.dirty[i];
  ginja_material_cache.parameters[i] = v;
  ginja_material_cache.dirty[i] = 0;
  return r;
}

void set_ginja_indexed_vtx_desc(u32 value, u32) {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, (GXAttrType)get_ginja_vertex_descriptor_type(value, 1));
    GXSetVtxDesc(GX_VA_NRM, (GXAttrType)get_ginja_vertex_descriptor_type(value, 2));
    GXSetVtxDesc(GX_VA_CLR0, (GXAttrType)get_ginja_vertex_descriptor_type(value, 3));
    GXSetVtxDesc(GX_VA_TEX0, (GXAttrType)get_ginja_vertex_descriptor_type(value, 5));
}

void set_ginja_channel_ctrl(s32 channel, s32 flags) {
    GXColorSrc ambientSource, materialSource;
    GXBool enabled;
    if ((u32)(flags & 0x100) != 0) enabled = GX_FALSE; else enabled = GX_TRUE;
    if ((u32)(flags & 0x1000) != 0) ambientSource = GX_SRC_VTX; else ambientSource = GX_SRC_REG;
    if ((u32)(ginja_draw_flags & 2) != 0) {
        GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_CLAMP, GX_AF_NONE);
        return;
    }
    if ((u32)(model_render_flags & 0x30) != 0) materialSource = GX_SRC_REG;
    else if ((u32)(flags & 0x800) != 0) materialSource = GX_SRC_VTX;
    else materialSource = GX_SRC_REG;
    GXSetChanCtrl((GXChannelID)channel, enabled, ambientSource, materialSource, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
    GXSetChanCtrl((GXChannelID)(channel + 2), GX_FALSE, ambientSource, materialSource, gx_chan_ctrl_light_mask, GX_DF_CLAMP, GX_AF_NONE);
}

#pragma push
#pragma use_lmw_stmw off
void set_ginja_channel_counts(u32 flags, u32 arg1) {
    s32 sum;
    s32 sum2;
    s32 i;
    if ((u32)(arg1 & 0x1903) != 0) {
        s32 n = flags & 3;
        if ((u32)(model_render_flags & 0x80000) != 0) {
            s32 pre = ginja_material_cache.channel_offset;
            s32 post = ginja_material_cache.post_channel_count;
            ginja_material_cache.material_channel_count = n;
            sum = pre + n;
            GXSetNumChans(ginja_material_cache.channel_total = post + sum);
            if (pre != 0 && ginja_pre_channel_callback != NULL) {
                ginja_pre_channel_callback(0);
            }
            for (i = 0; i < n; i++) {
                set_ginja_channel_ctrl(pre + i, flags);
            }
            if (post != 0 && ginja_post_channel_callback != NULL) {
                ginja_post_channel_callback(sum);
            }
        } else {
            GXSetNumChans(n);
            for (i = 0; i < n; i++) {
                set_ginja_channel_ctrl(i, flags);
            }
        }
    }
    if ((u32)(arg1 & 0xF0) != 0) {
        u8 n = (u32)(flags & 0xF0) >> 4;
        if ((u32)(model_render_flags & 0x80000) != 0) {
            s32 pre = ginja_material_cache.texgen_offset;
            s32 post = ginja_material_cache.post_texgen_count;
            ginja_material_cache.material_texgen_count = n;
            sum = pre + n;
            GXSetNumTexGens(ginja_material_cache.texgen_total = post + sum);
            if (pre != 0 && ginja_pre_texgen_callback != NULL) {
                ginja_pre_texgen_callback(0);
            }
            if (post != 0 && ginja_post_texgen_callback != NULL) {
                ginja_post_texgen_callback(sum);
            }
        } else {
            GXSetNumTexGens(n);
        }
        ginja_material_cache.dirty[10] = -1;
        ginja_material_cache.blend_valid |= 4;
        ginja_material_cache.textured = n;
    }
    if ((u32)(arg1 & 0xF0000) != 0) {
        u8 n = (u32)(flags & 0xF0000) >> 16;
        if ((u32)(model_render_flags & 0x80000) != 0) {
            s32 pre = ginja_material_cache.tev_stage_offset;
            s32 post = ginja_material_cache.post_tev_stage_count;
            ginja_material_cache.material_tev_stage_count = n;
            sum2 = pre + n;
            GXSetNumTevStages(ginja_material_cache.tev_stage_total = post + sum2);
            if (pre != 0 && ginja_pre_tev_callback != NULL) {
                ginja_pre_tev_callback(0);
            }
            if (post != 0 && ginja_post_tev_callback != NULL) {
                ginja_post_tev_callback(sum2);
            }
        } else {
            GXSetNumTevStages(n);
        }
        ginja_material_cache.dirty[9] = -1;
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_material_color(u32 v, u32) {
    GXColor fallback = {0, 0, 0, 0x7F};
    GXColor *mat;
    NJS_ARGB add;
    GXColor converted;
    GXColor convertedAdd;
    (mat = &ginja_material_cache.material_color)->r = (v & 0xFF000000) >> 24;
    ginja_material_cache.material_color.g = (v & 0xFF0000) >> 16;
    ginja_material_cache.material_color.b = (v & 0xFF00) >> 8;
    ginja_material_cache.material_color.a = v & 0xFF;
    if ((u32) (ginja_draw_flags & 2) != 0U) {
        GXSetChanMatColor(GX_COLOR0A0, fallback);
    } else if ((u32) (model_render_flags & 0x10) != 0U) {
        convert_color_f32_to_u8(&model_material_color, &converted);
        GXSetChanMatColor(GX_COLOR0A0, converted);
    } else if ((u32) (model_render_flags & 0x20) != 0U) {
        convert_color_u8_to_f32(mat, &add);
        add.a += model_material_color.a;
        add.r += model_material_color.r;
        add.g += model_material_color.g;
        add.b += model_material_color.b;
        convert_color_f32_to_u8(&add, &convertedAdd);
        GXSetChanMatColor(GX_COLOR0A0, convertedAdd);
    } else {
        GXSetChanMatColor(GX_COLOR0A0, *mat);
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

void TObjPlayer::set_global_color_rgba(u32 v, u32) {
    ginja_material_cache.global_color.r = (v & 0xFF000000) >> 24;
    ginja_material_cache.global_color.g = (v & 0xFF0000) >> 16;
    ginja_material_cache.global_color.b = (v & 0xFF00) >> 8;
    ginja_material_cache.global_color.a = v & 0xFF;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void TObjPlayer::set_global_color_rgba_alt_b(u32 v, u32) {
    ginja_material_cache.global_color_alt_b.r = (v & 0xFF000000) >> 24;
    ginja_material_cache.global_color_alt_b.g = (v & 0xFF0000) >> 16;
    ginja_material_cache.global_color_alt_b.b = (v & 0xFF00) >> 8;
    ginja_material_cache.global_color_alt_b.a = v & 0xFF;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_blend_param(u32 x, u32) {
    if ((u32)model_render_flags & 0x8000) {
        x = ginja_blend_override;
    }
    ginja_material_cache.blend = x;
    ginja_material_cache.blend_valid |= 1;
}
#pragma pop

void ginja_set_vertex_format(u32 arg0, u32) {
    GXSetVtxAttrFmt(GX_VTXFMT0, ginja_vertex_attributes[(arg0 & 0xFF0000) >> 16], ginja_vertex_component_counts[(arg0 & 0xF000) >> 12], ginja_vertex_component_types[(arg0 & 0xF00) >> 8], arg0);
}

void ginja_load_texture_slot(u32 arg0, u32) {
    ginja_material_cache.texture = arg0;
    ginja_material_cache.blend_valid |= 2;
    load_list_texture(arg0 & 0x1FFF, (arg0 & 0xC0000) >> 18, (arg0 & 0x30000) >> 16, (arg0 & 0x6000) >> 13);
}

void set_ginja_tev_order(u32 parameter, u32) {
    u32 selectedStage = (parameter & 0xF000) >> 12;
    if ((u32)model_render_flags & 0x80000)
        selectedStage += ginja_material_cache.tev_stage_offset;
    GXTevStageID stage = (GXTevStageID)selectedStage;
    GXTexCoordID coordinate = ginja_texcoord_ids[(parameter & 0xF00) >> 8];
    GXTexMapID texture = ginja_texmap_ids[(parameter & 0xF0) >> 4];
    GXChannelID channel = (GXChannelID)(parameter & 0xF);
    if (texture == GX_TEXMAP_NULL)
        GXSetTevOp((GXTevStageID)selectedStage, GX_PASSCLR);
    else
        GXSetTevOp((GXTevStageID)selectedStage, GX_MODULATE);
    GXSetTevOrder(stage, coordinate, texture, channel);
}

void set_ginja_texcoord_gen(u32 ginja_texcoord_gen, u32) {
    u32 idx;
    GXTexCoordID coord;
    u32 func;
    u32 src;
    GXTexMtx mtx;
    idx = (ginja_texcoord_gen & 0xF0000) >> 16;
    if ((u32)model_render_flags & 0x80000) {
        idx += ginja_material_cache.texgen_offset;
    }
    coord = ginja_texcoord_ids[idx];
    func = (ginja_texcoord_gen & 0xF000) >> 12;
    src = (ginja_texcoord_gen & 0xFF0) >> 4;
    mtx = ginja_texture_matrix_ids[ginja_texcoord_gen & 0xF];
    if (ginja_texcoord_gen_enabled != 0 && mtx == GX_IDENTITY) {
        mtx = GX_TEXMTX0;
    }
    GXSetTexCoordGen2(coord, (GXTexGenType)func, (GXTexGenSrc)src, mtx, GX_FALSE, GX_PTIDENTITY);
}

#pragma push
#pragma scheduling off
#pragma peephole off
void ginja_set_alpha_compare(u8 ref) {
    GXSetAlphaCompare(GX_GREATER, ref, GX_AOP_AND, GX_ALWAYS, 0);
}
#pragma pop


// Each handler gets the parameter's value and the bits that changed (update_ginja_cached_parameter).
extern GinjaParameterHandler ginja_parameter_handlers[11];

#pragma push
#pragma use_lmw_stmw off
void apply_ginja_material_params(const GinjaDrawRecord *record) {
    GinjaSurfaceState *surface;
    const GinjaParameter *parameter = record->parameters;
    s32 count = record->parameter_count;
    for (; count > 0; --count, ++parameter) {
        u32 changed = update_ginja_cached_parameter(parameter->kind, parameter->value);
        if (changed != 0) {
            ginja_parameter_handlers[parameter->kind](parameter->value, changed);
        }
    }
    if ((u32)(ginja_draw_flags & 2) != 0) {
        GXSetBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_CLEAR);
    } else if ((u32)(model_render_flags & 0x800000) != 0) {
        GXSetZCompLoc(GX_FALSE);
        GXSetZMode(GX_TRUE, GX_ALWAYS, GX_FALSE);
    } else if (ginja_material_cache.textured == 0) {
        u32 blend = ginja_material_cache.blend;
        if ((u32)(model_render_flags & 0x8000) != 0) {
            blend = ginja_blend_override;
        }
        GXBlendMode mode = (GXBlendMode)((blend & 0xC000) >> 14);
        GXSetBlendMode(mode, (GXBlendFactor)((blend & 0x3800) >> 11), (GXBlendFactor)((blend & 0x700) >> 8),
                       (GXLogicOp)(blend & 0xFF));
        GXSetZCompLoc(GX_FALSE);
        if (mode != GX_BM_NONE) {
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
        } else {
            GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
        }
    } else if (ginja_material_cache.blend_valid != 0) {
        u32 blend = ginja_material_cache.blend;
        GXBlendMode mode = (GXBlendMode)((blend & 0xC000) >> 14);
        GXBlendFactor source = (GXBlendFactor)((blend & 0x3800) >> 11);
        GXBlendFactor destination = (GXBlendFactor)((blend & 0x700) >> 8);
        GXLogicOp operation = (GXLogicOp)(blend & 0xFF);
        if ((u32)(model_render_flags & 0x400) != 0) {
            GXSetBlendMode(mode, source, destination, operation);
            GXSetZCompLoc(GX_FALSE);
            GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
        } else if ((u32)(model_render_flags & 1) != 0) {
            if ((u32)(model_render_flags & 0x8000) != 0) {
                u16 texture = ginja_material_cache.texture & 0x1FFF;
                u8 opaque = 1;
                if ((u32)(ginja_draw_list_state & 8) == 0 &&
                    (u32)(ginja_draw_list_state & 2) != 0 &&
                    (ginja_draw_list_mask & 1)) {
                    ginja_draw_list_state |= 4;
                    return;
                }
                if ((u32)(model_render_flags & 0x10) != 0 &&
                    1.0f != model_material_color.a) {
                    opaque = 0;
                }
                if ((u32)(model_render_flags & 0x20) != 0 &&
                    0.0f != model_material_color.a) {
                    opaque = 0;
                }
                const u32 &format = current_render_context->textures->textures[texture].texture->surface->header.format;
                GXSetZCompLoc(GX_FALSE);
                if (opaque) {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
                    ginja_set_alpha_compare(0);
                } else if (format == GX_TF_CMPR) {
                    GXSetZCompLoc(GX_FALSE);
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                    ginja_set_alpha_compare(0);
                } else {
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                }
                GXSetBlendMode(mode, source, destination, operation);
            } else {
                if ((u32)(ginja_draw_list_state & 2) != 0 && (ginja_draw_list_mask & 1)) {
                    ginja_draw_list_state |= 4;
                    return;
                }
                GXSetBlendMode(mode, source, destination, operation);
            }
        } else if (mode != GX_BM_NONE) {
            surface = current_render_context->textures->textures[
                ginja_material_cache.texture & 0x1FFF].texture->surface;
            if (ginja_material_cache.textured != 0 && surface->header.format == GX_TF_CMPR &&
                source == GX_BL_SRCALPHA && destination == GX_BL_INVSRCALPHA && (surface->header.flags & 0x40000000) != 0) {
                if ((u32)(ginja_draw_list_state & 8) == 0 &&
                    (u32)(ginja_draw_list_state & 2) != 0 && (ginja_draw_list_mask & 2)) {
                    ginja_draw_list_state |= 4;
                    return;
                }
                GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
                GXSetZCompLoc(GX_FALSE);
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                ginja_set_alpha_compare(material_alpha_compare_reference);
            } else {
                if ((u32)(ginja_draw_list_state & 8) == 0 &&
                    (u32)(ginja_draw_list_state & 2) != 0 && (ginja_draw_list_mask & 1)) {
                    ginja_draw_list_state |= 4;
                    return;
                }
                if ((u32)(model_render_flags & 0x1000000) != 0 &&
                    (u32)(ginja_draw_flags & 2) == 0) {
                    GXSetBlendMode(mode, source, destination, operation);
                    GXSetZCompLoc(GX_FALSE);
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
                    ginja_set_alpha_compare(material_alpha_compare_reference);
                } else {
                    GXSetBlendMode(mode, source, destination, operation);
                    GXSetZCompLoc(GX_FALSE);
                    GXSetZMode(GX_TRUE, GX_LEQUAL, GX_FALSE);
                    ginja_set_alpha_compare(0);
                }
            }
        } else {
            surface = current_render_context->textures->textures[
                ginja_material_cache.texture & 0x1FFF].texture->surface;
            if (surface->header.format == GX_TF_CMPR && (surface->header.flags & 0x40000000) == 0) {
                GXSetBlendMode(GX_BM_NONE, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
                GXSetZCompLoc(GX_TRUE);
                GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
            } else {
                GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_AND, GX_ALWAYS, 0);
                GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
                GXSetZCompLoc(GX_FALSE);
                GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
            }
        }
    }
}
#pragma pop
void set_ginja_vertex_arrays(GinjaVertexArray *array) {
    while (array->attribute != 0xFF) {
        GXSetArray(ginja_vertex_attributes[array->attribute], array->data, array->stride);
        array++;
    }
}

GinjaMaterialCache *invalidate_ginja_inherited_state() {
  GinjaMaterialCache *state = &ginja_material_cache;
  if ((state->inherited_flags ^ model_render_flags) & 0x80000) {
    state->inherited_flags = model_render_flags;
    state->dirty[2] |= 0xF00F3;
    state->dirty[9] = -1;
    state->dirty[10] = -1;
  }
  return state;
}


s32 draw_ginja_model_lists(void *model_data) {
  const GinjaModel *model = static_cast<const GinjaModel *>(model_data);
  s32 secondaryCount;
  const GinjaDrawRecord *secondary;
  const GinjaDrawRecord *primary;
  s32 primaryCount;
  invalidate_ginja_inherited_state();
  if (model->vertices) {
    set_ginja_vertex_arrays(model->vertices);
  }
  ginja_draw_list_state = 0;
  if ((ginja_draw_list_mask & 1) && (ginja_draw_list_mask & 2)) {
    ginja_draw_list_state |= 8;
  }
  if (ginja_draw_list_mask & 1) {
    ginja_draw_list_state |= 1;
    primaryCount = model->primary_count;
    primary = model->primary;
    for (; primaryCount > 0; primaryCount--, primary++) {
      ginja_draw_list_state &= ~4;
      apply_ginja_material_params(primary);
      if ((ginja_draw_list_state & 8) || !(ginja_draw_list_state & 4)) {
        GXCallDisplayList(primary->display_list, primary->display_list_size);
      }
    }
  }
  if (!(ginja_draw_flags & 2)) {
    ginja_draw_list_state = 0;
    if ((ginja_draw_list_mask & 1) && (ginja_draw_list_mask & 2)) {
      ginja_draw_list_state |= 8;
    }
    if ((ginja_draw_list_mask & 2) || (ginja_draw_list_mask & 1)) {
      ginja_draw_list_state |= 2;
      secondaryCount = model->secondary_count;
      secondary = model->secondary;
      for (; secondaryCount > 0; secondaryCount--, secondary++) {
        ginja_draw_list_state &= ~4;
        apply_ginja_material_params(secondary);
        if ((ginja_draw_list_state & 8) || !(ginja_draw_list_state & 4)) {
          GXCallDisplayList(secondary->display_list, secondary->display_list_size);
        }
      }
    }
    return 0;
  }
}

void prepare_ginja_model(void) {
    if (ginja_draw_flags & 2) {
        TObjPlayer::reset_particle_counter();
        apply_scene_fog();
    }
    for (s32 i = 0; i < 11; ++i) {
        ginja_material_cache.parameters[i] = 0;
        ginja_material_cache.dirty[i] = -1;
    }
    ginja_material_cache.prefix[0] = 0;
    ginja_material_cache.prefix[1] = -1;
    ginja_material_cache.inherited_flags = model_render_flags;
    ginja_material_cache.blend_valid = 0;
}

void end_ginja_model_draw(void) {
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::set_effect_active();
        apply_scene_fog();
    }
    if ((u32) (model_render_flags & 1) == 0) {
        GXSetZCompLoc(GX_TRUE);
        GXSetZMode(GX_TRUE, GX_LESS, GX_TRUE);
        ginja_set_alpha_compare(0);
        if (ginja_draw_end_callback != NULL) {
            ginja_draw_end_callback();
        }
    }
}

void load_ginja_model_matrices(int matrix_id) {
    GC_Mtx s;
    GC_Mtx t;
    GC_Mtx m;
    GXLoadPosMtxImm(*current_matrix, matrix_id);
    GXLoadNrmMtxImm(*current_matrix, matrix_id);
    if ((u32)model_render_flags & 0x100000) {
        PSMTXScale(s, -0.5f, -0.5f, 0.0f);
        PSMTXTrans(t, 0.5f, 0.5f, 1.0f);
        PSMTXInverse(*current_matrix, m);
        PSMTXTranspose(m, m);
        PSMTXConcat(s, m, m);
        PSMTXConcat(t, m, m);
        GXLoadTexMtxImm(m, GX_TEXMTX4, GX_MTX3x4);
    }
}

GinjaParameterHandler ginja_parameter_handlers[11] = {
    ginja_set_vertex_format, set_ginja_indexed_vtx_desc,
    set_ginja_channel_counts, NULL,
    set_ginja_blend_param, set_ginja_material_color,
    TObjPlayer::set_global_color_rgba, TObjPlayer::set_global_color_rgba_alt_b,
    ginja_load_texture_slot, set_ginja_tev_order,
    set_ginja_texcoord_gen,
};
GXAttr ginja_vertex_attributes[14] = {
    GX_VA_PNMTXIDX, GX_VA_POS, GX_VA_NRM, GX_VA_CLR0,
    GX_VA_CLR1, GX_VA_TEX0, GX_VA_TEX1, GX_VA_TEX2,
    GX_VA_TEX3, GX_VA_TEX4, GX_VA_TEX5, GX_VA_TEX6,
    GX_VA_TEX7, GX_VA_NULL,
};
GXTexCoordID ginja_texcoord_ids[9] = {
    GX_TEXCOORD0, GX_TEXCOORD1, GX_TEXCOORD2, GX_TEXCOORD3,
    GX_TEXCOORD4, GX_TEXCOORD5, GX_TEXCOORD6, GX_TEXCOORD7,
    GX_TEXCOORD_NULL,
};
GXTexMapID ginja_texmap_ids[9] = {
    GX_TEXMAP0, GX_TEXMAP1, GX_TEXMAP2, GX_TEXMAP3,
    GX_TEXMAP4, GX_TEXMAP5, GX_TEXMAP6, GX_TEXMAP7,
    GX_TEXMAP_NULL,
};
GXCompCnt ginja_vertex_component_counts[9] = {
    GX_POS_XY, GX_POS_XYZ, GX_NRM_XYZ, GX_NRM_NBT,
    GX_NRM_NBT3, GX_CLR_RGB, GX_CLR_RGBA, GX_TEX_S,
    GX_TEX_ST,
};
GXCompType ginja_vertex_component_types[11] = {
    GX_U8, GX_S8, GX_U16, GX_S16,
    GX_F32, GX_RGB565, GX_RGB8, GX_RGBX8,
    GX_RGBA4, GX_RGBA6, GX_RGBA8,
};
GXTexMtx ginja_texture_matrix_ids[11] = {
    GX_TEXMTX0, GX_TEXMTX1, GX_TEXMTX2, GX_TEXMTX3,
    GX_TEXMTX4, GX_TEXMTX5, GX_TEXMTX6, GX_TEXMTX7,
    GX_TEXMTX8, GX_TEXMTX9, GX_IDENTITY,
};

void set_ginja_draw_list_mask(s32 arg0) {
    ginja_draw_list_mask = arg0;
}

void TObjPlayer::set_global_effect_state(s32 global_effect_state) {
    lbl_805D76E0 = global_effect_state;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_post_texgen_count(s32 x) {
    ginja_material_cache.post_texgen_count = (u8)x;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_post_tev_stage_count(s32 x) {
    ginja_material_cache.post_tev_stage_count = (u8)x;
}
#pragma pop

void set_ginja_draw_end_callback(GinjaDrawEndCallback callback) {
    ginja_draw_end_callback = callback;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void set_color_blend_mode(s32 a, s32 b, s32 c, s32 d) {
    ginja_blend_override = (a << 14) | (b << 11) | (c << 8) | d;
}
#pragma pop
