#include "types.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTransform.h>
#include <dolphin/gx/GXTexture.h>
#include <dolphin/gx/GXPixel.h>
#include <dolphin/os.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/render/RenderSbssGlobals.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer_803E112C.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803E1FC8.h"
#include "pso/unk/text_803E2008.h"

extern "C" {
/* GX_PNMTX0..GX_PNMTX9 */
s32 gx_pos_mtx_index_table[10] = {0, 3, 6, 9, 12, 15, 18, 21, 24, 27};
/* GX_TEXMTX0..GX_TEXMTX9 */
s32 tex_matrix_id_table[10] = {30, 33, 36, 39, 42, 45, 48, 51, 54, 57};
/* GX_TEXMAP0..GX_TEXMAP7, GX_TEXMAP_NULL */
s32 list_texture_map_table[10] = {0, 1, 2, 3, 4, 5, 6, 7, 0xFF};
extern GXTexObj list_texture_tex_obj;

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

void calc_box_bounds(Vec *corners, Vec *min, Vec *max) {
    s32 i;
    min->x = corners->x;
    min->y = corners->y;
    min->z = corners->z;
    max->x = corners->x;
    max->y = corners->y;
    max->z = corners->z;
    corners++;
    for (i = 1; i < 8; i++, corners++) {
        if (corners->x < min->x) min->x = corners->x;
        if (corners->y < min->y) min->y = corners->y;
        if (corners->z < min->z) min->z = corners->z;
        if (corners->x > max->x) max->x = corners->x;
        if (corners->y > max->y) max->y = corners->y;
        if (corners->z > max->z) max->z = corners->z;
    }
}

void calc_sphere_bounds(CollisionSphere *sphere, Vec *min, Vec *max) {
    min->x = sphere->center.x - sphere->radius;
    min->y = sphere->center.y - sphere->radius;
    min->z = sphere->center.z - sphere->radius;
    max->x = sphere->center.x + sphere->radius;
    max->y = sphere->center.y + sphere->radius;
    max->z = sphere->center.z + sphere->radius;
}

// {0.0f, 1.0f} pair in .sdata; the assembly below loads only the 1.0f. A lone 0.0f would go to .sbss,
// so the zero word before it is the pair's first element.
f32 lbl_805D46E8[2] = {0.0f, 1.0f};

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
    GXLoadPosMtxImm(*current_matrix, gx_pos_mtx_index_table[arg0]);
}
#pragma pop

#pragma push
#pragma scheduling off
void load_current_tex_matrix(s32 i) {
    GXLoadTexMtxImm(*current_matrix, tex_matrix_id_table[i], GX_MTX3x4);
}
#pragma pop

void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map) {
    GinjaTextureState *info = current_render_context->textures->textures[idx].texture;
    GinjaTextureHeader *hdr = &info->surface->header;
    u32 flags = hdr->flags;
    u8 mip;
    if (flags & 0x80000000) {
        mip = 1;
    } else {
        mip = 0;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&list_texture_tex_obj, hdr->pixels, hdr->width, hdr->height, (GXCITexFmt)hdr->format, (GXTexWrapMode)wrapS, (GXTexWrapMode)wrapT, mip, info->tlut_name);
    } else {
        GXInitTexObj(&list_texture_tex_obj, hdr->pixels, hdr->width, hdr->height, (GXTexFmt)hdr->format, (GXTexWrapMode)wrapS, (GXTexWrapMode)wrapT, mip);
    }
    GXLoadTexObj(&list_texture_tex_obj, (GXTexMapID)list_texture_map_table[map]);
}

asm void reorder_current_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/reorder_current_matrix_ps.inc"
}

asm void push_reordered_matrix_ps(void) {
#include "orig_asm/pso/player/TObjPlayer_803E1A58/push_reordered_matrix_ps.inc"
}

void TObjPlayer::reload_texture(saddr arg1, u32 arg2, void *arg3) {
    s32 size;
    if ((arg2 & 0x40000000) != 0) {
        size = arg1;
    } else {
        OSPanic("nuReLoadTexture.c", 48, "sorry"); /* __FILE__ in the original */
    }
    TObjPlayer__sub_803DAE1C((saddr)this, size, (uaddr)arg3);
}

// The second {0.0f, 1.0f} pair (TObjPlayer__sub_803E1F60 loads the 1.0f).
f32 lbl_805D46F8[2] = {0.0f, 1.0f};

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

GXTexObj list_texture_tex_obj;

extern f32 scene_fog_end_distance;
extern f32 scene_fog_start_distance;
extern GXColor scene_fog_color;

#pragma push
#pragma scheduling off
#pragma peephole off

void fn_803E1FC8(u32 c) {
    scene_fog_color.r = (c & 0xFF000000) >> 24;
    scene_fog_color.g = (c & 0x00FF0000) >> 16;
    scene_fog_color.b = (c & 0x0000FF00) >> 8;
}
#pragma pop

void set_scene_fog_distances(f32 farg0, f32 farg1) {
    scene_fog_start_distance = farg0;
    scene_fog_end_distance = farg1;
}

struct G_803E2010 { u8 pad[0x44]; f32 f44; f32 f48; };
extern G_803E2010 scene_projection_state;

s32 scene_fog_type;
f32 scene_fog_end_distance;
f32 scene_fog_start_distance;
GXColor scene_fog_color;
s8 scene_fog_enable_flag;

void set_scene_fog_type(s32 arg0) {
    scene_fog_type = arg0;
}

void apply_scene_fog(void) {
    s32 type;
    if (scene_fog_enable_flag != 0) {
        type = scene_fog_type;
    } else {
        type = 0;
    }
    GXSetFog((GXFogType)type, scene_fog_start_distance, scene_fog_end_distance, scene_projection_state.f44, scene_projection_state.f48, scene_fog_color);
}
