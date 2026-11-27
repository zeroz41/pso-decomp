#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaModelQueue.h"
#include "pso/system/MatrixStack.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MemoryMove.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/TextureState.h"
#include "pso/render/GinjaTextureAlloc.h"
#include "pso/render/GinjaMaterialState.h"
#include <dolphin/mtx.h>








extern "C" {
void rotate_matrix_x(Matrix34* matrix, s32 angle);

void rotate_matrix_x(Matrix34* matrix, s32 angle) {
    Matrix34 rotation;
    Matrix34* selected;
    if (angle != 0) {
        if (matrix == NULL) selected = (Matrix34*)current_matrix;
        else selected = matrix;
        PSMTXRotRad(rotation.elements, 'x', (f32)((9.587378008291125e-05) * (f64)angle));
        PSMTXConcat(selected->elements, rotation.elements, selected->elements);
    }
}
}

extern "C" void concat_matrix(MtxP dest, const f32 (*source)[4]) {
    MtxP elements = dest;
    const f32 (*selected_source)[4] = source;
    if (elements == NULL) {
        elements = *current_matrix;
    }
    if (selected_source == NULL) {
        selected_source = *current_matrix;
    }
    PSMTXConcat(elements, selected_source, elements);
}

void premultiply_matrix(MtxP dest, const f32 (*source)[4]) {
    const f32 (*selected_source)[4] = source;
    MtxP elements;
    if (dest == NULL) {
        elements = *current_matrix;
    } else {
        elements = dest;
    }
    if (selected_source == NULL) {
        selected_source = *current_matrix;
    }
    PSMTXConcat(selected_source, elements, elements);
}

extern "C" {
asm f32 normalize_vector(Vec *v) {
#include "orig_asm/pso/system/MatrixStack/normalize_vector.inc"
}

s32 push_matrix_from(void *src) {
    GC_Mtx *next = current_matrix + 1;
    if (next > matrix_stack_limit) {
        return 0;
    }
    move_data(next, (src == NULL) ? current_matrix : src, 0x30);
    current_matrix = next;
    return 1;
}
}

s32 pop_matrices(s32 count) {
    GC_Mtx *new_top;
    new_top = current_matrix - count;
    if (new_top < matrix_stack_base) {
        return 0;
    }
    current_matrix = new_top;
    return 1;
}
extern "C" {

asm void transform_point_by_current_matrix(const f32 *src, Vec *dst) {
#include "orig_asm/pso/system/MatrixStack/transform_point_by_current_matrix.inc"
}
}

void concat_quaternion_rotation(const f32 *quat) {
    Mtx34 mtx;
    ConcatQuaternionRotationQ q;
    q.w = quat[0];
    q.x = quat[1];
    q.y = quat[2];
    q.z = quat[3];
    PSMTXQuat(mtx, (const PSQuaternion *)&q);
    PSMTXConcat(*current_matrix, mtx, *current_matrix);
}

void apply_quat_rotation(f32 w, f32 *xyz) {
    Mtx34 mtx;
    ApplyQuatRotationQ q;
    q.w = w;
    q.x = xyz[0];
    q.y = xyz[1];
    q.z = xyz[2];
    PSMTXQuat(mtx, (const PSQuaternion *)&q);
    PSMTXConcat(*current_matrix, mtx, *current_matrix);
}

// {0.0f, 0.0f}: rotate_vector_by_current_matrix pairs the first with z so the translation column drops out
// (name inferred). The original keeps these zeros in .sdata, which only an aggregate gets: a scalar zero goes to .sbss.
static f32 rotation_zero[2] = {0.0f, 0.0f};
extern "C" {

asm void rotate_vector_by_current_matrix(const Vec *src, Vec *dst) {
#include "orig_asm/pso/system/MatrixStack/rotate_vector_by_current_matrix.inc"
}

asm void rotate_matrix_by_node_angles(const s32 *ang, u32 zxy) {
#include "orig_asm/pso/system/MatrixStack/rotate_matrix_by_node_angles.inc"
}

asm s32 push_matrix(void) {
#include "orig_asm/pso/system/MatrixStack/push_matrix.inc"
}

s32 pop_matrix(void) {
    GC_Mtx *new_top;
    new_top = current_matrix - 1;
    if (new_top < matrix_stack_base) {
        return 0;
    }
    current_matrix = new_top;
    return 1;
}

asm void scale_current_matrix(const f32 *v) {
#include "orig_asm/pso/system/MatrixStack/scale_current_matrix.inc"
}

asm void post_translate_matrix(const f32 *v) {
#include "orig_asm/pso/system/MatrixStack/post_translate_matrix.inc"
}
}

void swap_gvrt_word(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}

u32 *find_gvrt_texture_chunk(TLobby *lobby, u32 *out_id, u32 *data) {
    u32 tag;
    u32 *p = data;
    if (out_id != NULL) {
        *out_id = 0xFFFFFFFF;
    }
    do {
        tag = *p;
        swap_gvrt_word(&tag);
        switch (tag) {
        case 0x54525647:
            move_data(lobby, p + 2, 8);
            return p + 4;
        case 0x58494247: {
            u32 len;
            p++;
            len = *p++;
            swap_gvrt_word(&len);
            if (out_id != NULL) {
                *out_id = *p;
            }
            p += len >> 2;
            break;
        }
        default:
            texture_error.code = 4;
            return NULL;
        }
    } while (tag != 0x54525647);
    return p;
}

s32 init_texture_from_gvr_desc(GinjaTextureState *texture, GvrTextureDesc *desc) {
    if (init_texture_header_and_alloc(&texture->surface->header, desc->width, desc->height, desc->format) != 0) {
        texture_error.code = 6;
        return -1;
    }
    return 1;
}

s32 is_gvm_load_ok() {
    if (texture_transfer_pending() == 0) {
        return 1;
    }
    return -1;
}

s32 resolve_texlist_entry(s32 *texlist_arg, u32 idx, s32 *out_surface, u32 *out_tlut) {
    GinjaTextureState *slot;
    u32 j;
    GinjaSurfaceState *surface;
    GinjaSurfaceState *surface_hit;
    GinjaTextureState *state;
    s32 flags;
    s32 record_index;
    NJS_TEXNAME *table;
    GinjaTextureState *prev_entry;
    NJS_TEXNAME *entry;
    NJS_TEXLIST *texlist = (NJS_TEXLIST *)texlist_arg;
    table = texlist->textures;
    entry = &table[idx];
    flags = entry->attr;
    if (((u32) (flags & 0x10000) != 0) && (idx != 0)) {
        *out_tlut = (u32) (entry->texaddr & 0xFC000000) >> 0x1AU;
        j = idx - 1;
        prev_entry = (GinjaTextureState *)((ResolveTexlistEntryTable *)table)->arr[j].p;
        *out_surface = prev_entry->surface->id;
        record_index = find_texture_by_surface_and_tlut((int) (*out_surface), (int) (*out_tlut));
        if (record_index < 0) {
            if (find_free_texture_slot(&slot, NULL) < 0) {
                return -1;
            }
            entry->texture = slot;
            slot->tlut_name = *out_tlut;
            slot->surface = prev_entry->surface;
            slot->ref_count = 1;
            surface = slot->surface;
            surface->ref_count = surface->ref_count + 1;
            slot->reserved14 = prev_entry->reserved14;
            notify_texture_state_ready(slot);
            goto done;
        }
        state = &texture_states[record_index];
        slot = state;
        entry->texture = state;
        surface_hit = slot->surface;
        surface_hit->ref_count = surface_hit->ref_count + 1;
        slot->ref_count = slot->ref_count + 1;
    done:
        return 1;
    }
    if ((u32) (flags & 0x800000) != 0) {
        *out_surface = entry->texaddr;
        *out_tlut = -1U;
    } else if ((u32) (flags & 0x01000000) != 0) {
        *out_surface = entry->texaddr & 0x03FFFFFF;
        *out_tlut = (u32) (entry->texaddr & 0xFC000000) >> 0x1AU;
    } else {
        *out_surface = -1;
        *out_tlut = (u32) (entry->texaddr & 0xFC000000) >> 0x1AU;
    }
    return 0;
}
