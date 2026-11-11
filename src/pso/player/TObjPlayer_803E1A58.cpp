#include "types.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"

typedef struct TexObj_803E1D90 { u32 dummy[8]; } TexObj_803E1D90;

typedef struct TexHdr_803E1D90 {
    u32 f0;
    s32 format;
    u32 f8;
    u32 fC;
    u32 width;
    u32 height;
    u32 f18;
    u32 flags;
    void *image;
} TexHdr_803E1D90;

typedef struct TexInfo_803E1D90 { u32 f0; u32 f4; u32 tlut; TexHdr_803E1D90 *hdr; } TexInfo_803E1D90;

typedef struct TexEnt_803E1D90 { u32 f0; u32 f4; TexInfo_803E1D90 *info; } TexEnt_803E1D90;

typedef struct TexList_803E1D90 { TexEnt_803E1D90 *ents; } TexList_803E1D90;

typedef struct Ctx_803E1D90 { u8 pad[0x20]; TexList_803E1D90 *list; } Ctx_803E1D90;

extern "C" {
s32 GXLoadPosMtxImm(void *, int);
/* GX_PNMTX0..GX_PNMTX9 */
s32 gx_pos_mtx_index_table[10] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27};
extern s32 current_matrix;
/* GX_TEXMTX0..GX_TEXMTX9 */
s32 tex_matrix_id_table[10] = {30, 33, 36, 39, 42, 45, 48, 51, 54, 57};
void GXLoadTexMtxImm(void *mtx, u32 id, s32 type);
void OSPanic(const char *, int, const char *, ...);
extern char lbl_805D46F0[6]; /* "sorry"; .sdata not split into this unit yet */
void Dolphin_GXInitTexObj(TexObj_803E1D90 *, void *, u16, u16, s32, s32, s32, u8);
void GXInitTexObjCI(TexObj_803E1D90 *, void *, u16, u16, s32, s32, s32, u8, u32);
void GXLoadTexObj(TexObj_803E1D90 *, s32);
/* GX_TEXMAP0..GX_TEXMAP7, GX_TEXMAP_NULL */
s32 list_texture_map_table[10] = {0, 1, 2, 3, 4, 5, 6, 7, 0xFF};
extern TexObj_803E1D90 list_texture_tex_obj;
extern Ctx_803E1D90 *current_render_context;

#pragma push
#pragma scheduling off
f32 xyz_distance(Vec *a, Vec *b) {
    f32 x = (a->z - b->z) * (a->z - b->z) + ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
    f32 r;
    if (x < 0.025f) {
        return 0.0f;
    }
    if (x > 0.0f) {
        volatile f32 y;
        f64 g = __frsqrte(x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        g = 0.5 * g * (3.0 - g * g * x);
        y = (f32)(x * g);
        r = y;
    } else {
        r = x;
    }
    return r;
}
#pragma pop
}

void calc_bounds_min_max__10TObjPlayerFPvPvPv(struct Vec_803E1B1C *pts, struct Vec_803E1B1C *mn, struct Vec_803E1B1C *mx) {
    s32 i;
    mn->x = pts->x;
    mn->y = pts->y;
    mn->z = pts->z;
    mx->x = pts->x;
    mx->y = pts->y;
    mx->z = pts->z;
    pts++;
    for (i = 1; i < 8; i++, pts++) {
        if (pts->x < mn->x) mn->x = pts->x;
        if (pts->y < mn->y) mn->y = pts->y;
        if (pts->z < mn->z) mn->z = pts->z;
        if (pts->x > mx->x) mx->x = pts->x;
        if (pts->y > mx->y) mx->y = pts->y;
        if (pts->z > mx->z) mx->z = pts->z;
    }
}

void TObjPlayer::calc_bounds(u8 *arg1, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 0) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg1 + 4) = (f32) (*(f32 *)((s8 *)arg0 + 4) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) - *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 0) = (f32) (*(f32 *)((s8 *)arg0 + 0) + *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 4) = (f32) (*(f32 *)((s8 *)arg0 + 4) + *(f32 *)((s8 *)arg0 + 0xC));
    *(f32 *)((s8 *)arg2 + 8) = (f32) (*(f32 *)((s8 *)arg0 + 8) + *(f32 *)((s8 *)arg0 + 0xC));
}

// 1.0f constants in .sdata, read by the assembly below (not yet split into this unit).
extern "C" f32 lbl_805D46EC;
extern "C" f32 lbl_805D46FC;

asm void translate_current_matrix_ps(f32 x, f32 y, f32 z) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/translate_current_matrix_ps.inc"
}

asm f32 TObjPlayer__sub_803E1CA4(s32 angle) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/TObjPlayer__sub_803E1CA4.inc"
}

asm void rotate_current_matrix_x_ps(s32 angle) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/rotate_current_matrix_x_ps.inc"
}

extern s8 scene_fog_enable_flag;

#pragma push
#pragma scheduling off
void load_current_pos_matrix(s32 arg0) {
    GXLoadPosMtxImm((void *)current_matrix, gx_pos_mtx_index_table[arg0]);
}
#pragma pop

#pragma push
#pragma scheduling off
void load_current_tex_matrix(s32 i) {
    GXLoadTexMtxImm((void *)current_matrix, tex_matrix_id_table[i], 0);
}
#pragma pop

void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map) {
    TexInfo_803E1D90 *info = current_render_context->list->ents[idx].info;
    TexHdr_803E1D90 *hdr = info->hdr;
    u32 flags = hdr->flags;
    u8 mip;
    if (flags & 0x80000000) {
        mip = 1;
    } else {
        mip = 0;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&list_texture_tex_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip, info->tlut);
    } else {
        Dolphin_GXInitTexObj(&list_texture_tex_obj, hdr->image, hdr->width, hdr->height, hdr->format, wrapS, wrapT, mip);
    }
    GXLoadTexObj(&list_texture_tex_obj, list_texture_map_table[map]);
}

asm void reorder_current_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/reorder_current_matrix_ps.inc"
}

asm void push_reordered_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/push_reordered_matrix_ps.inc"
}

void TObjPlayer::reload_texture(s32 arg1, u32 arg2, void *arg3) {
    s32 size;
    if ((arg2 & 0x40000000) != 0) {
        size = arg1;
    } else {
        OSPanic("nuReLoadTexture.c", 48, lbl_805D46F0); /* __FILE__ in the original */
    }
    TObjPlayer__sub_803DAE1C((s32)this, size, (u32)arg3);
}

asm void TObjPlayer__sub_803E1F60(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/TObjPlayer__sub_803E1F60.inc"
}

asm void push_identity_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/push_identity_matrix_ps.inc"
}

void TObjPlayer::set_effect_active() {
    scene_fog_enable_flag = 1;
}

void TObjPlayer::reset_particle_counter() {
    scene_fog_enable_flag = 0;
}

TexObj_803E1D90 list_texture_tex_obj;
