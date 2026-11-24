#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/ScreenPrimitiveDraw.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/system/NinjaTypes.h"

GXTexObj context_texture_obj;

void setup_opaque_color_draw() {
    apply_opaque_blend_mode();
    setup_color_vertex_format();
}

void setup_blended_color_draw() {
    apply_blended_blend_mode();
    setup_color_vertex_format();
}

void setup_opaque_textured_draw() {
    apply_opaque_blend_mode();
    setup_textured_vertex_format();
}

void setup_blended_textured_draw() {
    apply_blended_blend_mode();
    setup_textured_vertex_format();
}

void end_primitive_draw() {

}

void load_context_texture_obj() {
    GinjaSceneState *context = current_render_context;
    GinjaTextureHeader *header = context->texture_header;
    u32 flags = header->flags;
    GXBool mipmap;
    u32 attr;
    GXTexWrapMode wrap_t;
    GXTexWrapMode wrap_s;
    if (flags & 0x80000000) {
        mipmap = GX_TRUE;
    } else {
        mipmap = GX_FALSE;
    }
    attr = context->blend_mode;
    wrap_t = GX_REPEAT;
    wrap_s = GX_REPEAT;
    if (attr & NJD_FLAG_CLAMP_U) {
        wrap_s = GX_CLAMP;
    } else if (attr & NJD_FLAG_FLIP_U) {
        wrap_s = GX_MIRROR;
    }
    if (attr & NJD_FLAG_CLAMP_V) {
        wrap_t = GX_CLAMP;
    } else if (attr & NJD_FLAG_FLIP_V) {
        wrap_t = GX_MIRROR;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&context_texture_obj, header->pixels, header->width, header->height, (GXCITexFmt)header->format,
                       wrap_s, wrap_t, mipmap, context->tlut_name);
    } else {
        GXInitTexObj(&context_texture_obj, header->pixels, header->width, header->height, (GXTexFmt)header->format,
                     wrap_s, wrap_t, mipmap);
    }
    GXLoadTexObj(&context_texture_obj, GX_TEXMAP0);
}

void setup_color_vertex_format() {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    setup_color_channels(1);
    set_tev_passclr();
    clear_tex_gens();
}

void setup_textured_vertex_format() {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_CLR0, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_CLR0, GX_CLR_RGBA, GX_RGBA8, 0);
    GXSetVtxAttrFmt(GX_VTXFMT4, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    setup_color_channels(1);
    set_tev_stage_mode(1);
    setup_tex_gen();
}

#pragma push
#pragma scheduling off

void setup_color_channels(int count) {
    GXSetNumChans(count);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    if (count == 2) {
        GXSetChanCtrl(GX_COLOR1A1, GX_FALSE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    }
}

void apply_opaque_blend_mode() { apply_cached_blend_mode(0); }

void apply_blended_blend_mode() { apply_cached_blend_mode(1); }

void set_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
}

#pragma push
#pragma peephole off
void set_tev_stage_mode(s32 count) {
    s32 stages = count;
    GXSetNumTevStages(stages);
    switch (stages) {
    case 1:
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
        return;
    case 2:
        GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD0, GX_TEXMAP0, GX_COLOR0A0);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR1A1);
        GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
        GXSetTevColorOp(GX_TEVSTAGE1, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
        GXSetTevColorIn(GX_TEVSTAGE1, GX_CC_ZERO, GX_CC_RASC, GX_CC_ONE, GX_CC_CPREV);
        return;
    }
}
#pragma pop

void clear_tex_gens() { GXSetNumTexGens(0); }

void setup_tex_gen() {
    GXSetNumTexGens(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
}

#pragma dont_inline off
#pragma inline_depth(4)
void draw_screen_color_strip(ScreenColorVertex *vertices, s32 count, s32 blended) {
    f32 inv_w;
    u32 color;
    load_screen_space_matrix();
    if (blended != 0) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(GX_TRIANGLESTRIP, GX_VTXFMT4, count);
    for (; count > 0; count--) {
        inv_w = -1.0f / vertices->w;
        GXPosition3f32(vertices->x * inv_w, vertices->y * inv_w, inv_w);
        color = vertices->color;
        GXColor1u32(((color & 0xFFFFFF) << 8) | ((color & 0xFF000000) >> 24));
        vertices++;
    }
    end_primitive_draw();
}

#pragma pop
