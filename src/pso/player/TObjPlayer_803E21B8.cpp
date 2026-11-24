#include "types.h"
#include "pso/player/TObjPlayer_803E21B8.h"
#include "pso/player/TObjPlayer.h"

typedef struct TexObj_803E224C { u32 dummy[8]; } TexObj_803E224C;

typedef struct TexHdr_803E224C {
    s32 format;
    u32 f4;
    u32 f8;
    u32 width;
    u32 height;
    u32 f14;
    u32 flags;
    void *image;
} TexHdr_803E224C;

typedef struct Ctx_803E224C {
    u32 f0;
    u32 f4;
    TexHdr_803E224C *hdr;
    u32 mode;
    u32 f10;
    u32 f14;
    u32 tlut;
} Ctx_803E224C;

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
s32 GXSetTevOp(int, int);
s32 GXSetTevColorIn(int, int, int, int, int);
s32 GXSetTevColorOp(int, int, int, int, int, int);
s32 GXSetTevOrder(int, int, int, int);
void GXSetNumTevStages(u8 nStages);
s32 apply_cached_blend_mode(s32 arg0);
s32 GXSetNumTexGens(s32 arg0);
s32 GXSetTexCoordGen2(int, int, int, int, int, int);
void GXInitTexObj(TexObj_803E224C *, void *, u16, u16, s32, s32, s32, u8);
void GXInitTexObjCI(TexObj_803E224C *, void *, u16, u16, s32, s32, s32, u8, u32);
void GXLoadTexObj(TexObj_803E224C *, s32);
extern TexObj_803E224C context_texture_obj;
extern Ctx_803E224C *current_render_context;
void GXBegin(int, int, u16);
void draw_projected_line_strip__10TObjPlayerFPvii(Vtx_803E26A4 *v, s32 n, s32 mode);
void GXSetNumChans(u8);
void GXSetChanCtrl(int, int, int, int, int, int, int);
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
    Ctx_803E224C *ctx = current_render_context;
    TexHdr_803E224C *hdr = ctx->hdr;
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
    mode = ctx->mode;
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
        GXInitTexObjCI(&context_texture_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip, ctx->tlut);
    } else {
        GXInitTexObj(&context_texture_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip);
    }
    GXLoadTexObj(&context_texture_obj, 0);
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


void TObjPlayer::setup_color_channels(int total) {
    GXSetNumChans(total);
    GXSetChanCtrl(4, 0, 0, 1, 0, 0, 2);
    if (total == 2) {
        GXSetChanCtrl(5, 0, 0, 1, 0, 0, 2);
    }
}

s32 apply_opaque_blend_mode() { return apply_cached_blend_mode(0x0); }

s32 TObjPlayer::apply_blend_mode_1() { return apply_cached_blend_mode(0x1); }

void TObjPlayer::set_tev_passclr() {
    GXSetNumTevStages(1);
    GXSetTevOrder(0, 0xFF, 0xFF, 4);
    GXSetTevOp(0, 4);
}

void set_tev_stage_mode(s32 arg0) {
    s32 nStages = arg0;
    GXSetNumTevStages(nStages);
    switch (nStages) {
    case 1:
        GXSetTevOrder(0, 0, 0, 4);
        GXSetTevOp(0, 0);
        return;
    case 2:
        GXSetTevOrder(0, 0, 0, 4);
        GXSetTevOrder(1, 0xFF, 0xFF, 5);
        GXSetTevOp(0, 0);
        GXSetTevColorOp(1, 0, 0, 0, 1, 0);
        GXSetTevColorIn(1, 0xF, 0xA, 0xC, 0);
        return;
    }
}

#pragma push
extern "C" {
s32 TObjPlayer::set_num_tex_gens_zero() { return GXSetNumTexGens(0x0); }
void TObjPlayer::setup_tex_gen() {
    GXSetNumTexGens((s32)(1U));
    GXSetTexCoordGen2(0, 1, 4, 0x3C, 0, 0x7D);
}

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

TexObj_803E224C context_texture_obj;
