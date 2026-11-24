#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include <dolphin/os.h>
#include "pso/render/GinjaDrawUtil.h"
#include "pso/render/GinjaView.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/BoxCollision.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803DA798.h"

GXPosNrmMtx gx_pos_mtx_index_table[10] = {
    GX_PNMTX0, GX_PNMTX1, GX_PNMTX2, GX_PNMTX3, GX_PNMTX4, GX_PNMTX5, GX_PNMTX6, GX_PNMTX7, GX_PNMTX8, GX_PNMTX9,
};
GXTexMtx tex_matrix_id_table[10] = {
    GX_TEXMTX0, GX_TEXMTX1, GX_TEXMTX2, GX_TEXMTX3, GX_TEXMTX4, GX_TEXMTX5, GX_TEXMTX6, GX_TEXMTX7, GX_TEXMTX8, GX_TEXMTX9,
};
GXTexMapID list_texture_map_table[10] = {
    GX_TEXMAP0, GX_TEXMAP1, GX_TEXMAP2, GX_TEXMAP3, GX_TEXMAP4, GX_TEXMAP5, GX_TEXMAP6, GX_TEXMAP7, GX_TEXMAP_NULL,
};
GXTexObj list_texture_tex_obj;
s32 scene_fog_type;
f32 scene_fog_end_distance;
f32 scene_fog_start_distance;
GXColor scene_fog_color;
s8 scene_fog_enable_flag;

extern "C" {
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
f32 translate_matrix_ps_constants[2] = {0.0f, 1.0f};

asm void translate_current_matrix_ps(f32 x, f32 y, f32 z) {
#include "orig_asm/pso/render/GinjaDrawUtil/translate_current_matrix_ps.inc"
}

asm f32 lookup_sin_cos(s32 angle) {
#include "orig_asm/pso/render/GinjaDrawUtil/lookup_sin_cos.inc"
}

asm void rotate_current_matrix_x_ps(s32 angle) {
#include "orig_asm/pso/render/GinjaDrawUtil/rotate_current_matrix_x_ps.inc"
}

#pragma push
#pragma scheduling off
void load_current_pos_matrix(s32 index) {
    GXLoadPosMtxImm(*current_matrix, gx_pos_mtx_index_table[index]);
}
#pragma pop

#pragma push
#pragma scheduling off
void load_current_tex_matrix(s32 index) {
    GXLoadTexMtxImm(*current_matrix, tex_matrix_id_table[index], GX_MTX3x4);
}
#pragma pop

void load_list_texture(s32 index, s32 wrap_s, s32 wrap_t, s32 map) {
    GinjaTextureState *texture = current_render_context->textures->textures[index].texture;
    GinjaSurfaceState *surface = texture->surface;
    u32 flags = surface->header.flags;
    GXBool mipmap;
    if (flags & 0x80000000) {
        mipmap = GX_TRUE;
    } else {
        mipmap = GX_FALSE;
    }
    if (flags & 0x8000) {
        GXInitTexObjCI(&list_texture_tex_obj, surface->header.pixels, surface->header.width, surface->header.height,
                       (GXCITexFmt)surface->header.format, (GXTexWrapMode)wrap_s, (GXTexWrapMode)wrap_t, mipmap,
                       texture->tlut_name);
    } else {
        GXInitTexObj(&list_texture_tex_obj, surface->header.pixels, surface->header.width, surface->header.height,
                     (GXTexFmt)surface->header.format, (GXTexWrapMode)wrap_s, (GXTexWrapMode)wrap_t, mipmap);
    }
    GXLoadTexObj(&list_texture_tex_obj, list_texture_map_table[map]);
}

asm void reorder_current_matrix_ps(void) {
#include "orig_asm/pso/render/GinjaDrawUtil/reorder_current_matrix_ps.inc"
}

asm void push_reordered_matrix_ps(void) {
#include "orig_asm/pso/render/GinjaDrawUtil/push_reordered_matrix_ps.inc"
}

void reload_texture_num(s32 n, saddr texaddr, u32 attr, u32 lod) {
    saddr src;
    if ((attr & NJD_TEXATTR_TYPE_MEMORY) != 0) {
        src = texaddr;
    } else {
        OSPanic("nuReLoadTexture.c", 48, "sorry");
    }
    TObjPlayer__sub_803DAE1C(n, src, lod);
}

// The second {0.0f, 1.0f} pair (identity_current_matrix_ps loads the 1.0f).
f32 identity_matrix_ps_constants[2] = {0.0f, 1.0f};

asm void identity_current_matrix_ps(void) {
#include "orig_asm/pso/render/GinjaDrawUtil/identity_current_matrix_ps.inc"
}

asm void push_identity_matrix_ps(void) {
#include "orig_asm/pso/render/GinjaDrawUtil/push_identity_matrix_ps.inc"
}

void enable_scene_fog() {
    scene_fog_enable_flag = 1;
}

void disable_scene_fog() {
    scene_fog_enable_flag = 0;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void set_scene_fog_color(u32 color) {
    scene_fog_color.r = (color & 0xFF000000) >> 24;
    scene_fog_color.g = (color & 0x00FF0000) >> 16;
    scene_fog_color.b = (color & 0x0000FF00) >> 8;
}
#pragma pop

void set_scene_fog_distances(f32 start, f32 end) {
    scene_fog_start_distance = start;
    scene_fog_end_distance = end;
}

void set_scene_fog_type(s32 type) {
    scene_fog_type = type;
}

void apply_scene_fog() {
    s32 type;
    if (scene_fog_enable_flag != 0) {
        type = scene_fog_type;
    } else {
        type = GX_FOG_NONE;
    }
    GXSetFog((GXFogType)type, scene_fog_start_distance, scene_fog_end_distance, scene_projection_state.near_z,
             scene_projection_state.far_z, scene_fog_color);
}
