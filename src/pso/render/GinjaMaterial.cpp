#include "pso/system/ModelDrawCallback.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModelQueue.h"
#include "pso/unk/text_803E2008.h"
#include "pso/render/GinjaModel.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"

#pragma scheduling off
#pragma scheduling off
typedef s32 (*RecoveredCallback_d26337a2813d)();

typedef GinjaMaterialCache S_803DB560;

struct S_803DBB78 { u8 pad[0x7c]; u32 f7c; u32 f80; };

struct C_803DBB38 { u8 r, g, b, a; };

struct S_803DBB38 { u8 pad[0x68]; C_803DBB38 c; };

struct C_803DBAF8 { u8 r, g, b, a; };

struct S_803DBAF8 { u8 pad[0x64]; C_803DBAF8 c; };

struct GinjaTevCache { u8 reserved[0x75]; u8 stageOffset; };

struct G_803DBC1C { u8 pad[0x7C]; u32 f7c; u32 f80; u32 f84; u32 f88; };

struct Arr_803DC3BC { u8 idx; u8 stride; u8 pad[6]; void *base; u32 pad2; };

struct C_803DB9A0 { u8 r, g, b, a; };

struct S_803DB9A0 { u8 pad[0x60]; C_803DB9A0 c; };

struct F_803DB9A0 { f32 r, g, b, a; };

typedef void (*RecoveredCallback_bfe74032a8e8)(s32);
typedef void (*RecoveredCallback_bfe74032a8e8)(s32);
typedef void (*RecoveredCallback_bfe74032a8e8)(s32);
typedef void (*RecoveredCallback_b52dc2a08a00)(u8);
typedef void (*RecoveredCallback_b52dc2a08a00)(u8);
typedef void (*RecoveredCallback_b52dc2a08a00)(u8);
typedef struct GinjaCounts_803DB734 {
    u8 pad0[0x58];
    s32 tevDirty;
    s32 texGenDirty;
    u8 pad60[0x70 - 0x60];
    u8 count[3];
    u8 pre[3];
    u8 post[3];
    u8 total[3];
    u32 flags7C;
    u32 pad80;
    u32 texGenCount;
} GinjaCounts_803DB734;

extern "C" {
s32 Dolphin_GXSetVtxDesc(int, void *);
s32 GXClearVtxDesc();
void GXSetZMode(u8, s32, s32);
void GXSetZCompLoc(s32);
void GXSetBlendMode(s32, s32, s32, s32);
extern RecoveredCallback_d26337a2813d ginja_draw_end_callback;
extern u32 ginja_draw_flags;
extern u32 model_render_flags;
void queue_model_draw_matrix(s32, s32);
extern s32 current_matrix;
extern S_803DB560 ginja_material_cache;
extern u32 ginja_blend_override;
void GXSetAlphaCompare(s32 comp0, s32 ref0, s32 op, s32 comp1, s32 ref1);
extern s32 ginja_texcoord_ids[];
extern s32 ginja_texmap_ids[];
void GXSetTevOp(s32, s32);
void GXSetTevOrder(s32, s32, s32, s32);
extern s32 ginja_vertex_attributes[];
extern s32 ginja_vertex_component_counts[];
extern s32 ginja_vertex_component_types[];
void GXSetVtxAttrFmt(s32, s32, s32, s32, u8);
void GXSetArray(s32, void *, u8);
void set_ginja_vertex_arrays(Arr_803DC3BC *arg0);
void apply_ginja_material_params(GinjaDrawRecord *);
s32 GXCallDisplayList(void *, u32);
extern u32 ginja_draw_list_state, ginja_draw_flags;
extern s32 ginja_draw_list_mask;
void GXSetTexCoordGen2(s32 dst, u32 func, u32 src, s32 mtx, s32 normalize, s32 pt);
extern s32 ginja_texture_matrix_ids[];
extern s32 ginja_texcoord_gen_enabled;
void PSMTXConcat(void *, void *, void *);
void PSMTXTranspose(void *, void *);
void PSMTXInverse(void *, void *);
void PSMTXTrans(void *, f32, f32, f32);
void PSMTXScale(void *, f32, f32, f32);
void GXLoadPosMtxImm(void *, void *);
void GXLoadNrmMtxImm(void *, void *);
void GXLoadTexMtxImm(void *, int, int);
void GXSetChanMatColor(s32, C_803DB9A0);
void convert_color_f32_to_u8(const F_803DB9A0 *, C_803DB9A0 *);
void convert_color_u8_to_f32(const C_803DB9A0 *, F_803DB9A0 *);
extern F_803DB9A0 model_material_color;
extern const C_803DB9A0 lbl_805E0F68;
void traverse_model_node_tree(void *, void *);
void GXSetChanCtrl(s32,s32,s32,s32,s32,s32,s32);
extern s32 gx_chan_ctrl_light_mask;
void GXSetNumChans(u8);
void GXSetNumTexGens(u8);
void GXSetNumTevStages(u8);
extern RecoveredCallback_bfe74032a8e8 ginja_pre_channel_callback;
extern RecoveredCallback_bfe74032a8e8 ginja_pre_texgen_callback;
extern RecoveredCallback_bfe74032a8e8 ginja_pre_tev_callback;
extern RecoveredCallback_b52dc2a08a00 ginja_post_channel_callback;
extern RecoveredCallback_b52dc2a08a00 ginja_post_texgen_callback;
extern RecoveredCallback_b52dc2a08a00 ginja_post_tev_callback;

void draw_ginja_object(void *child) {
    prepare_ginja_model();
    init_model_draw_queue(draw_ginja_model_lists);
    traverse_model_node_tree(child, (void *) queue_model_draw_current_matrix);
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
GinjaMaterialCache *invalidate_ginja_inherited_state();
#pragma push
#pragma scheduling off
s32 queue_model_draw_current_matrix(s32 model) {
    queue_model_draw_matrix(model, current_matrix);
    return 1;
}
#pragma pop

void draw_ginja_model(s32 model) {
    load_ginja_model_matrices(0);
    prepare_ginja_model();
    draw_ginja_model_lists((GinjaModel *)model);
    end_ginja_model_draw();
}

s32 get_ginja_vertex_descriptor_type(u32 arg0, s32 arg1) {
    return (arg0 >> (arg1 * 2)) & 3;
}

#pragma push
#pragma scheduling off
#pragma peephole off
u32 update_ginja_cached_parameter(s32 i, u32 v) {
  u32 r = v ^ ginja_material_cache.parameters[i];
  r |= ginja_material_cache.dirty[i];
  ginja_material_cache.parameters[i] = v;
  ginja_material_cache.dirty[i] = 0;
  return r;
}
#pragma pop

void set_ginja_indexed_vtx_desc(s32 arg0) {
    GXClearVtxDesc();
    Dolphin_GXSetVtxDesc(9, (void *) (get_ginja_vertex_descriptor_type(arg0, 1)));
    Dolphin_GXSetVtxDesc(0xA, (void *) (get_ginja_vertex_descriptor_type(arg0, 2)));
    Dolphin_GXSetVtxDesc(0xB, (void *) (get_ginja_vertex_descriptor_type(arg0, 3)));
    Dolphin_GXSetVtxDesc(0xD, (void *) (get_ginja_vertex_descriptor_type(arg0, 5)));
}

void set_ginja_channel_ctrl(s32 channel,s32 flags) {
    s32 ambientSource,materialSource,enabled;
    if((u32)(flags&0x100)!=0)enabled=0;else enabled=1;
    if((u32)(flags&0x1000)!=0)ambientSource=1;else ambientSource=0;
    if((u32)(ginja_draw_flags&2)!=0) {
        GXSetChanCtrl(4,0,0,0,0,2,2);return;
    }
    if((u32)(model_render_flags&0x30)!=0)materialSource=0;
    else if((u32)(flags&0x800)!=0)materialSource=1;
    else materialSource=0;
    GXSetChanCtrl(channel,enabled,ambientSource,materialSource,gx_chan_ctrl_light_mask,2,2);
    GXSetChanCtrl(channel+2,0,ambientSource,materialSource,gx_chan_ctrl_light_mask,2,2);
}

#define GC ((GinjaCounts_803DB734 *)&ginja_material_cache)
#pragma push
#pragma use_lmw_stmw off
void set_ginja_channel_counts(s32 flags, s32 arg1) {
    s32 sum;
    s32 sum2;
    s32 i;
    if ((u32)(arg1 & 0x1903) != 0) {
        s32 n = flags & 3;
        if ((u32)(model_render_flags & 0x80000) != 0) {
            s32 pre = GC->pre[0];
            s32 post = GC->post[0];
            GC->count[0] = n;
            sum = pre + n;
            GXSetNumChans(GC->total[0] = post + sum);
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
            s32 pre = GC->pre[1];
            s32 post = GC->post[1];
            GC->count[1] = n;
            sum = pre + n;
            GXSetNumTexGens(GC->total[1] = post + sum);
            if (pre != 0 && ginja_pre_texgen_callback != NULL) {
                ginja_pre_texgen_callback(0);
            }
            if (post != 0 && ginja_post_texgen_callback != NULL) {
                ginja_post_texgen_callback(sum);
            }
        } else {
            GXSetNumTexGens(n);
        }
        GC->texGenDirty = -1;
        GC->flags7C |= 4;
        GC->texGenCount = n;
    }
    if ((u32)(arg1 & 0xF0000) != 0) {
        u8 n = (u32)(flags & 0xF0000) >> 16;
        if ((u32)(model_render_flags & 0x80000) != 0) {
            s32 pre = GC->pre[2];
            s32 post = GC->post[2];
            GC->count[2] = n;
            sum2 = pre + n;
            GXSetNumTevStages(GC->total[2] = post + sum2);
            if (pre != 0 && ginja_pre_tev_callback != NULL) {
                ginja_pre_tev_callback(0);
            }
            if (post != 0 && ginja_post_tev_callback != NULL) {
                ginja_post_tev_callback(sum2);
            }
        } else {
            GXSetNumTevStages(n);
        }
        GC->tevDirty = -1;
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_material_color(u32 v) {
    C_803DB9A0 fallback = lbl_805E0F68;
    C_803DB9A0 *mat;
    F_803DB9A0 add;
    C_803DB9A0 converted;
    C_803DB9A0 convertedAdd;
    (mat = &(*(S_803DB9A0 *)&ginja_material_cache).c)->r = (v & 0xFF000000) >> 24;
    (*(S_803DB9A0 *)&ginja_material_cache).c.g = (v & 0xFF0000) >> 16;
    (*(S_803DB9A0 *)&ginja_material_cache).c.b = (v & 0xFF00) >> 8;
    (*(S_803DB9A0 *)&ginja_material_cache).c.a = v & 0xFF;
    if ((u32) (ginja_draw_flags & 2) != 0U) {
        GXSetChanMatColor(4, fallback);
    } else if ((u32) (model_render_flags & 0x10) != 0U) {
        convert_color_f32_to_u8(&model_material_color, &converted);
        GXSetChanMatColor(4, converted);
    } else if ((u32) (model_render_flags & 0x20) != 0U) {
        convert_color_u8_to_f32(mat, &add);
        add.r += model_material_color.r;
        add.g += model_material_color.g;
        add.b += model_material_color.b;
        add.a += model_material_color.a;
        convert_color_f32_to_u8(&add, &convertedAdd);
        GXSetChanMatColor(4, convertedAdd);
    } else {
        GXSetChanMatColor(4, *mat);
    }
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

void TObjPlayer::set_global_color_rgba(u32 v) {
    (*(S_803DBAF8 *)&ginja_material_cache).c.r = (v & 0xFF000000) >> 24;
    (*(S_803DBAF8 *)&ginja_material_cache).c.g = (v & 0xFF0000) >> 16;
    (*(S_803DBAF8 *)&ginja_material_cache).c.b = (v & 0xFF00) >> 8;
    (*(S_803DBAF8 *)&ginja_material_cache).c.a = v & 0xFF;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void TObjPlayer::set_global_color_rgba_alt_b(u32 v) {
    (*(S_803DBB38 *)&ginja_material_cache).c.r = (v & 0xFF000000) >> 24;
    (*(S_803DBB38 *)&ginja_material_cache).c.g = (v & 0xFF0000) >> 16;
    (*(S_803DBB38 *)&ginja_material_cache).c.b = (v & 0xFF00) >> 8;
    (*(S_803DBB38 *)&ginja_material_cache).c.a = v & 0xFF;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void set_ginja_blend_param(u32 x) {
    if ((u32)model_render_flags & 0x8000) {
        x = ginja_blend_override;
    }
    (*(S_803DBB78 *)&ginja_material_cache).f80 = x;
    (*(S_803DBB78 *)&ginja_material_cache).f7c |= 1;
}
#pragma pop

void ginja_set_vertex_format(u32 arg0) {
    GXSetVtxAttrFmt(0, ginja_vertex_attributes[(arg0 & 0xFF0000) >> 16], ginja_vertex_component_counts[(arg0 & 0xF000) >> 12], ginja_vertex_component_types[(arg0 & 0xF00) >> 8], arg0);
}

void ginja_load_texture_slot(u32 arg0) {
    (*(G_803DBC1C *)&ginja_material_cache).f88 = arg0;
    (*(G_803DBC1C *)&ginja_material_cache).f7c |= 2;
    load_list_texture(arg0 & 0x1FFF, (arg0 & 0xC0000) >> 18, (arg0 & 0x30000) >> 16, (arg0 & 0x6000) >> 13);
}

void set_ginja_tev_order(u32 parameter) {
    u32 selectedStage = (parameter & 0xF000) >> 12;
    if ((u32)model_render_flags & 0x80000)
        selectedStage += (*(GinjaTevCache *)&ginja_material_cache).stageOffset;
    s32 stage = selectedStage;
    s32 coordinate = ginja_texcoord_ids[(parameter & 0xF00) >> 8];
    s32 texture = ginja_texmap_ids[(parameter & 0xF0) >> 4];
    s32 channel = parameter & 0xF;
    if (texture == 0xFF)
        GXSetTevOp(selectedStage, 4);
    else
        GXSetTevOp(selectedStage, 0);
    GXSetTevOrder(stage, coordinate, texture, channel);
}

void set_ginja_texcoord_gen(u32 arg0) {
    u32 idx;
    s32 coord;
    u32 func;
    u32 src;
    s32 mtx;
    idx = (arg0 & 0xF0000) >> 16;
    if ((u32)model_render_flags & 0x80000) {
        idx += ginja_material_cache.reserved70[4];
    }
    coord = ginja_texcoord_ids[idx];
    func = (arg0 & 0xF000) >> 12;
    src = (arg0 & 0xFF0) >> 4;
    mtx = ginja_texture_matrix_ids[arg0 & 0xF];
    if (ginja_texcoord_gen_enabled != 0 && mtx == 0x3C) {
        mtx = 0x1E;
    }
    GXSetTexCoordGen2(coord, func, src, mtx, 0, 0x7D);
}

#pragma push
#pragma scheduling off
#pragma peephole off
void ginja_set_alpha_compare(s32 ref) {
    GXSetAlphaCompare(4, ref, 0, 7, 0);
}
#pragma pop


extern GinjaSceneState *current_render_context;
// Each handler gets the parameter's value and the bits that changed (update_ginja_cached_parameter).
typedef void (*GinjaParameterHandler)(u32 value, u32 changed);
extern GinjaParameterHandler ginja_parameter_handlers[11];
extern s32 material_alpha_compare_reference;

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma use_lmw_stmw off
void apply_ginja_material_params(GinjaDrawRecord *record) {
    s32 src;
    s32 dst;
    GinjaSurfaceState *surface;
    GinjaParameter *param = (GinjaParameter *)record->parameters;
    s32 count = record->parameter_count;
    u32 blend;
    s32 type;
    s32 op;

    for (; count > 0; count--, param++) {
        u32 changed = update_ginja_cached_parameter(param->kind, param->value);
        if (changed) {
            ginja_parameter_handlers[param->kind](param->value, changed);
        }
    }
    if (ginja_draw_flags & 2) {
        GXSetBlendMode(0, 0, 0, 0);
    } else if (model_render_flags & 0x800000) {
        GXSetZCompLoc(0);
        GXSetZMode(1, 7, 0);
    } else if (ginja_material_cache.textured == 0) {
        blend = ginja_material_cache.blend;
        if (model_render_flags & 0x8000) {
            blend = ginja_blend_override;
        }
        type = (blend & 0xC000) >> 14;
        GXSetBlendMode(type, (blend & 0x3800) >> 11, (blend & 0x700) >> 8, blend & 0xFF);
        GXSetZCompLoc(0);
        if (type != 0) {
            GXSetZMode(1, 3, 0);
        } else {
            GXSetZMode(1, 1, 1);
        }
    } else if (ginja_material_cache.blend_valid != 0) {
        type = (ginja_material_cache.blend & 0xC000) >> 14;
        src = (ginja_material_cache.blend & 0x3800) >> 11;
        dst = (ginja_material_cache.blend & 0x700) >> 8;
        op = ginja_material_cache.blend & 0xFF;
        if (model_render_flags & 0x400) {
            GXSetBlendMode(type, src, dst, op);
            GXSetZCompLoc(0);
            GXSetZMode(1, 3, 0);
        } else if (model_render_flags & 1) {
            if (model_render_flags & 0x8000) {
                u16 texture = ginja_material_cache.texture & 0x1FFF;
                u8 opaque = 1;
                if (!(ginja_draw_list_state & 8) && (ginja_draw_list_state & 2) && (ginja_draw_list_mask & 1)) {
                    ginja_draw_list_state |= 4;
                } else {
                    if ((model_render_flags & 0x10) && model_material_color.r != 1.0f) {
                        opaque = 0;
                    }
                    if ((model_render_flags & 0x20) && model_material_color.r != 0.0f) {
                        opaque = 0;
                    }
                    surface = current_render_context->textures->entries[texture].texture->surface;
                    GXSetZCompLoc(0);
                    if (opaque) {
                        GXSetZMode(1, 3, 0);
                        ginja_set_alpha_compare(0);
                    } else if (surface->format == 14) {
                        GXSetZCompLoc(0);
                        GXSetZMode(1, 3, 1);
                        ginja_set_alpha_compare(0);
                    } else {
                        GXSetZMode(1, 3, 1);
                    }
                    GXSetBlendMode(type, src, dst, op);
                }
            } else if ((ginja_draw_list_state & 2) && (ginja_draw_list_mask & 1)) {
                ginja_draw_list_state |= 4;
            } else {
                GXSetBlendMode(type, src, dst, op);
            }
        } else if (type != 0) {
            surface = current_render_context->textures->entries[ginja_material_cache.texture & 0x1FFF].texture->surface;
            if (ginja_material_cache.textured != 0 && surface->format == 14 && src == 4 && dst == 5 &&
                (surface->flags & 0x40000000)) {
                if (!(ginja_draw_list_state & 8) && (ginja_draw_list_state & 2) && (ginja_draw_list_mask & 2)) {
                    ginja_draw_list_state |= 4;
                } else {
                    GXSetBlendMode(0, 4, 5, 15);
                    GXSetZCompLoc(0);
                    GXSetZMode(1, 3, 1);
                    ginja_set_alpha_compare(material_alpha_compare_reference & 0xFF);
                }
            } else if (!(ginja_draw_list_state & 8) && (ginja_draw_list_state & 2) && (ginja_draw_list_mask & 1)) {
                ginja_draw_list_state |= 4;
            } else if ((model_render_flags & 0x1000000) && !(ginja_draw_flags & 2)) {
                GXSetBlendMode(type, src, dst, op);
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
                ginja_set_alpha_compare(material_alpha_compare_reference & 0xFF);
            } else {
                GXSetBlendMode(type, src, dst, op);
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 0);
                ginja_set_alpha_compare(0);
            }
        } else {
            surface = current_render_context->textures->entries[ginja_material_cache.texture & 0x1FFF].texture->surface;
            if (surface->format == 14 && !(surface->flags & 0x40000000)) {
                GXSetBlendMode(0, 4, 5, 15);
                GXSetZCompLoc(1);
                GXSetZMode(1, 1, 1);
            } else {
                GXSetAlphaCompare(7, 0, 0, 7, 0);
                GXSetBlendMode(1, 4, 5, 0);
                GXSetZCompLoc(0);
                GXSetZMode(1, 3, 1);
            }
        }
    }
}
#pragma pop
void set_ginja_vertex_arrays(Arr_803DC3BC *arg0) {
    while (arg0->idx != 0xFF) {
        GXSetArray(ginja_vertex_attributes[arg0->idx], arg0->base, arg0->stride);
        arg0++;
    }
}

#pragma push
#pragma scheduling off
#pragma peephole off
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
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off

s32 draw_ginja_model_lists(void *model_data) {
  GinjaModel *model = (GinjaModel *)model_data;
  s32 secondaryCount;
  GinjaDrawRecord *secondary;
  GinjaDrawRecord *primary;
  s32 primaryCount;
  invalidate_ginja_inherited_state();
  if (model->vertices) {
    set_ginja_vertex_arrays((Arr_803DC3BC *)model->vertices);
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
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void prepare_ginja_model(void) {
    if ((*(u32 *)&ginja_draw_flags) & 2) {
        TObjPlayer::reset_particle_counter();
        apply_scene_fog();
    }
    for (s32 i = 0; i < 11; ++i) {
        (*(GinjaMaterialCache *)&ginja_material_cache).parameters[i] = 0;
        (*(GinjaMaterialCache *)&ginja_material_cache).dirty[i] = -1;
    }
    *(u32 *)((*(GinjaMaterialCache *)&ginja_material_cache).prefix + 0) = 0;
    *(u32 *)((*(GinjaMaterialCache *)&ginja_material_cache).prefix + 4) = -1;
    (*(GinjaMaterialCache *)&ginja_material_cache).inherited_flags = (*(u32 *)&model_render_flags);
    (*(GinjaMaterialCache *)&ginja_material_cache).blend_valid = 0;
}
#pragma pop

#pragma push
#pragma peephole off
void end_ginja_model_draw(void) {
    if ((u32) (ginja_draw_flags & 2) != 0) {
        TObjPlayer::set_effect_active();
        apply_scene_fog();
    }
    if ((u32) (model_render_flags & 1) == 0) {
        GXSetZCompLoc(1);
        GXSetZMode(1U, 1, 1);
        ginja_set_alpha_compare(0);
        if (((s32 (*)()) ginja_draw_end_callback) != NULL) {
            ginja_draw_end_callback();
        }
    }
}
#pragma pop

s32 load_ginja_model_matrices(int arg0) {
    f32 s[3][4];
    f32 t[3][4];
    f32 m[3][4];
    GXLoadPosMtxImm((void *)current_matrix, (void *)arg0);
    GXLoadNrmMtxImm((void *)current_matrix, (void *)arg0);
    if ((u32)model_render_flags & 0x100000) {
        PSMTXScale(s, -0.5f, -0.5f, 0.0f);
        PSMTXTrans(t, 0.5f, 0.5f, 1.0f);
        PSMTXInverse((void *)current_matrix, m);
        PSMTXTranspose(m, m);
        PSMTXConcat(s, m, m);
        PSMTXConcat(t, m, m);
        GXLoadTexMtxImm(m, 0x2A, 0);
    }
}

GinjaParameterHandler ginja_parameter_handlers[11] = {
    (GinjaParameterHandler)ginja_set_vertex_format, (GinjaParameterHandler)set_ginja_indexed_vtx_desc,
    (GinjaParameterHandler)set_ginja_channel_counts, NULL,
    (GinjaParameterHandler)set_ginja_blend_param, (GinjaParameterHandler)set_ginja_material_color,
    (GinjaParameterHandler)TObjPlayer::set_global_color_rgba, (GinjaParameterHandler)TObjPlayer::set_global_color_rgba_alt_b,
    (GinjaParameterHandler)ginja_load_texture_slot, (GinjaParameterHandler)set_ginja_tev_order,
    (GinjaParameterHandler)set_ginja_texcoord_gen,
};
s32 ginja_vertex_attributes[14] = {
    0x0, 0x9, 0xa, 0xb,
    0xc, 0xd, 0xe, 0xf,
    0x10, 0x11, 0x12, 0x13,
    0x14, 0xff,
};
s32 ginja_texcoord_ids[9] = {
    0x0, 0x1, 0x2, 0x3,
    0x4, 0x5, 0x6, 0x7,
    0xff,
};
s32 ginja_texmap_ids[9] = {
    0x0, 0x1, 0x2, 0x3,
    0x4, 0x5, 0x6, 0x7,
    0xff,
};
s32 ginja_vertex_component_counts[9] = {
    0x0, 0x1, 0x0, 0x1,
    0x2, 0x0, 0x1, 0x0,
    0x1,
};
s32 ginja_vertex_component_types[11] = {
    0x0, 0x1, 0x2, 0x3,
    0x4, 0x0, 0x1, 0x2,
    0x3, 0x4, 0x5,
};
s32 ginja_texture_matrix_ids[11] = {
    0x1e, 0x21, 0x24, 0x27,
    0x2a, 0x2d, 0x30, 0x33,
    0x36, 0x39, 0x3c,
};
