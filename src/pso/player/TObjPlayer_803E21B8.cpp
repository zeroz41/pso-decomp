#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTev.h>
#include <dolphin/gx/GXTexture.h>
#include <dolphin/gx/GXLighting.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/render/RenderSbssGlobals.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/player/TObjPlayer.h"

typedef struct Vtx_803E26A4 { f32 x, y, w; u32 color; } Vtx_803E26A4;

typedef union WGPipe_803E26A4 {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} WGPipe_803E26A4;

extern "C" {
s32 GXClearVtxDesc();
s32 GXSetVtxDesc(int, int);
s32 GXSetVtxAttrFmt(int, int, int, int, int);
s32 apply_cached_blend_mode(s32 arg0);
s32 GXSetNumTexGens(s32 arg0);
s32 GXSetTexCoordGen2(int, int, int, int, int, int);
extern GXTexObj context_texture_obj;
void GXBegin(int, int, u16);
void draw_projected_line_strip__10TObjPlayerFPvii(Vtx_803E26A4 *v, s32 n, s32 mode);
}
void setup_opaque_color_draw(void) {
    apply_opaque_blend_mode();
    TObjPlayer::setup_vertex_format();
}

void setup_blended_color_draw() {
    TObjPlayer::apply_blend_mode_1();
    TObjPlayer::setup_vertex_format();
}

void TObjPlayer::setup_render() {
    apply_opaque_blend_mode();
    TObjPlayer::setup_vtx_desc();
}

void setup_blended_textured_draw(void) {
    TObjPlayer::apply_blend_mode_1();
    TObjPlayer::setup_vtx_desc();
}

void end_primitive_draw() {

}

void load_context_texture_obj(void) {
    GinjaSceneState *ctx = current_render_context;
    GinjaTextureHeader *hdr = ctx->texture_header;
    u32 flags = hdr->flags;
    u8 mip;
    u32 mode;
    s32 wrapT;
    s32 wrapS;
    if (flags & 0x80000000) {
        mip = 1;
    } else {
        mip = 0;
    }
    mode = ctx->blend_mode;
    wrapT = 1;
    wrapS = 1;
    if (mode & 0x10000) {
        wrapS = 0;
    } else if (mode & 0x40000) {
        wrapS = 2;
    }
    if (mode & 0x8000) {
        wrapT = 0;
    } else if (mode & 0x20000) {
        wrapT = 2;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&context_texture_obj, hdr->pixels, hdr->width, hdr->height, (GXCITexFmt)hdr->format, (GXTexWrapMode)wrapS, (GXTexWrapMode)wrapT, mip, ctx->tlut_name);
    } else {
        GXInitTexObj(&context_texture_obj, hdr->pixels, hdr->width, hdr->height, (GXTexFmt)hdr->format, (GXTexWrapMode)wrapS, (GXTexWrapMode)wrapT, mip);
    }
    GXLoadTexObj(&context_texture_obj, GX_TEXMAP0);
}

void TObjPlayer::setup_vertex_format() {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    TObjPlayer::setup_color_channels(1);
    TObjPlayer::set_tev_passclr();
    TObjPlayer::set_num_tex_gens_zero();
}
void TObjPlayer::setup_vtx_desc() {
    GXClearVtxDesc();
    GXSetVtxDesc(9, 1);
    GXSetVtxDesc(0xB, 1);
    GXSetVtxDesc(0xD, 1);
    GXSetVtxAttrFmt(4, 9, 1, 4, 0);
    GXSetVtxAttrFmt(4, 0xB, 1, 5, 0);
    GXSetVtxAttrFmt(4, 0xD, 1, 4, 0);
    TObjPlayer::setup_color_channels(1);
    set_tev_stage_mode(1);
    TObjPlayer::setup_tex_gen();
}

#pragma push
#pragma scheduling off

void TObjPlayer::setup_color_channels(int total) {
    GXSetNumChans(total);
    GXSetChanCtrl(GX_COLOR0A0, GX_DISABLE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    if (total == 2) {
        GXSetChanCtrl(GX_COLOR1A1, GX_DISABLE, GX_SRC_REG, GX_SRC_VTX, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    }
}

s32 apply_opaque_blend_mode() { return apply_cached_blend_mode(0x0); }
#pragma pop

#pragma push
#pragma scheduling off
s32 TObjPlayer::apply_blend_mode_1() { return apply_cached_blend_mode(0x1); }
#pragma pop

#pragma push
#pragma scheduling off
void TObjPlayer::set_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
    GXSetTevOp(GX_TEVSTAGE0, GX_PASSCLR);
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
void set_tev_stage_mode(s32 arg0) {
    s32 nStages = arg0;
    GXSetNumTevStages(nStages);
    switch (nStages) {
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

#pragma push
#pragma scheduling off
extern "C" {
s32 TObjPlayer::set_num_tex_gens_zero() { return GXSetNumTexGens(0x0); }
#pragma push
#pragma scheduling off
void TObjPlayer::setup_tex_gen() {
    GXSetNumTexGens((s32)(1U));
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void GXPosition3f32_803E26A4(f32 x, f32 y, f32 z) {
    (*(volatile WGPipe_803E26A4 *)0xCC008000).f32 = x;
    (*(volatile WGPipe_803E26A4 *)0xCC008000).f32 = y;
    (*(volatile WGPipe_803E26A4 *)0xCC008000).f32 = z;
}
static inline void GXColor1u32_803E26A4(u32 c) {
    (*(volatile WGPipe_803E26A4 *)0xCC008000).u32 = c;
}
void draw_projected_line_strip__10TObjPlayerFPvii(Vtx_803E26A4 *v, s32 n, s32 mode) {
    f32 inv;
    u32 c;
    TObjPlayer::load_screen_space_matrix();
    if (mode != 0) {
        setup_blended_color_draw();
    } else {
        setup_opaque_color_draw();
    }
    GXBegin(0x98, 4, n);
    for (; n > 0; n--) {
        inv = -1.0f / v->w;
        GXPosition3f32_803E26A4(v->x * inv, v->y * inv, inv);
        c = v->color;
        GXColor1u32_803E26A4(((c & 0xFFFFFF) << 8) | ((c & 0xFF000000) >> 24));
        v++;
    }
    end_primitive_draw();
}
#pragma pop

}

#pragma pop

GXTexObj context_texture_obj;
