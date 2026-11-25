#include "pso/system/memory.h"
#include "types.h"
#include "pso/render/GinjaModelQueue.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/TLobby_803DE778.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/render/GinjaTexture.h"
#include <dolphin/mtx.h>

struct ConcatQuaternionRotationQ { f32 x, y, z, w; };

struct ApplyQuatRotationQ { f32 x, y, z, w; };

struct InitTextureFromGvrDescA { u8 pad[0xC]; u8 *p; };

struct InitTextureFromGvrDescB { s32 a; u16 b; u16 c; };

struct Matrix34 { f32 elements[3][4]; };

struct Ent_803D9E38 { u8 *p; s32 a; s32 b; };

struct ResolveTexlistEntryTable { u8 pad[8]; Ent_803D9E38 arr[1]; };

extern "C" {
s32 fn_803DA12C(u8 *, s32, s32, s32);
s32 init_texture_from_gvr_desc(InitTextureFromGvrDescA *texture, InitTextureFromGvrDescB *desc);
void rotate_matrix_x(Matrix34* matrix, s32 angle);
s32 notify_texture_state_ready(int, int);

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
#include "orig_asm/pso/unk/text_803D96A8/normalize_vector.inc"
}

s32 push_matrix_from(void *src) {
    GC_Mtx *next = current_matrix + 1;
    if (next > matrix_stack_limit) {
        return 0;
    }
    move_data(next, (src == NULL) ? (void *)current_matrix : src, 0x30);
    current_matrix = next;
    return 1;
}
}

s32 pop_matrices(s32 arg0) {
    GC_Mtx *new_top;
    new_top = current_matrix - arg0;
    if (new_top < matrix_stack_base) {
        return 0;
    }
    current_matrix = new_top;
    return 1;
}
extern "C" {

asm void transform_point_by_current_matrix(const f32 *src, Vec *dst) {
#include "orig_asm/pso/unk/text_803D96A8/transform_point_by_current_matrix.inc"
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

void apply_quat_rotation(f32 farg0, f32 *xyz) {
    Mtx34 mtx;
    ApplyQuatRotationQ q;
    q.w = farg0;
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
#include "orig_asm/pso/unk/text_803D96A8/rotate_vector_by_current_matrix.inc"
}

asm void rotate_matrix_by_node_angles(const s32 *ang, u32 zxy) {
#include "orig_asm/pso/unk/text_803D96A8/rotate_matrix_by_node_angles.inc"
}

asm s32 push_matrix(void) {
#include "orig_asm/pso/unk/text_803D96A8/push_matrix.inc"
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
#include "orig_asm/pso/unk/text_803D96A8/scale_current_matrix.inc"
}

asm void post_translate_matrix(const f32 *v) {
#include "orig_asm/pso/unk/text_803D96A8/post_translate_matrix.inc"
}
}

void swap_gvrt_word(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}

u32 *find_gvrt_texture_chunk(TLobby *lobby, u32 *arg1, u32 *arg2) {
    u32 tag;
    u32 *p = arg2;
    if (arg1 != NULL) {
        *arg1 = 0xFFFFFFFF;
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
            if (arg1 != NULL) {
                *arg1 = *p;
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

s32 init_texture_from_gvr_desc(InitTextureFromGvrDescA *texture, InitTextureFromGvrDescB *desc) {
    if (fn_803DA12C(texture->p + 4, desc->b, desc->c, desc->a) != 0) {
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

s32 resolve_texlist_entry(s32 *arg0, u32 idx, s32 *arg2, u32 *arg3) {
    saddr sp8;
    u32 j;
    s32 *temp_r4;
    s32 *temp_r4_2;
    s32 temp_r0;
    s32 temp_r3;
    s32 record_index;
    saddr temp_r6;
    u8 *temp_r29;
    u8 *temp_r31;
    temp_r6 = *(s32 *)((s8 *)arg0 + 0);
    temp_r31 = (u8 *)(temp_r6 + (idx * 0xC));
    temp_r3 = *(s32 *)((s8 *)temp_r31 + 4);
    if (((u32) (temp_r3 & 0x10000) != 0) && (idx != 0)) {
        *(u32 *)((s8 *)arg3 + 0) = (u32) (*(s32 *)((s8 *)temp_r31 + 8) & 0xFC000000) >> 0x1AU;
        j = idx - 1;
        temp_r29 = ((ResolveTexlistEntryTable *)temp_r6)->arr[j].p;
        *(s32 *)((s8 *)arg2 + 0) = *(s32 *)((s8 *)(*(s32 **)((s8 *)temp_r29 + 0xC)) + 0);
        record_index = find_texture_by_surface_and_tlut((int) (*(s32 *)((s8 *)arg2 + 0)), (int) (*(u32 *)((s8 *)arg3 + 0)));
        if (record_index < 0) {
            if (find_free_texture_slot((GinjaTextureState **)&sp8, NULL) < 0) {
                return -1;
            }
            *(s32 *)((s8 *)temp_r31 + 8) = sp8;
            *(u32 *)((s8 *)sp8 + 8) = (u32) *(u32 *)((s8 *)arg3 + 0);
            *(s32 **)((s8 *)sp8 + 0xC) = (s32 *) *(s32 **)((s8 *)temp_r29 + 0xC);
            *(s32 *)((s8 *)sp8 + 0x10) = 1;
            temp_r4 = (s32 *)(*(s32 **)((s8 *)sp8 + 0xC));
            *(s32 *)((s8 *)temp_r4 + 0x24) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x24) + 1);
            *(s32 *)((s8 *)sp8 + 0x14) = (s32) *(s32 *)((s8 *)temp_r29 + 0x14);
            notify_texture_state_ready((int)sp8, (saddr)temp_r4);
            goto block_7;
        }
        temp_r0 = (saddr)&texture_states[record_index];
        sp8 = temp_r0;
        *(s32 *)((s8 *)temp_r31 + 8) = temp_r0;
        temp_r4_2 = (s32 *)(*(s32 **)((s8 *)sp8 + 0xC));
        *(s32 *)((s8 *)temp_r4_2 + 0x24) = (s32) (*(s32 *)((s8 *)temp_r4_2 + 0x24) + 1);
        *(s32 *)((s8 *)sp8 + 0x10) = (s32) (*(s32 *)((s8 *)sp8 + 0x10) + 1);
block_7:
        return 1;
    }
    if ((u32) (temp_r3 & 0x800000) != 0) {
        *(s32 *)((s8 *)arg2 + 0) = *(s32 *)((s8 *)temp_r31 + 8);
        *(u32 *)((s8 *)arg3 + 0) = -1U;
    } else if ((u32) (temp_r3 & 0x01000000) != 0) {
        *(s32 *)((s8 *)arg2 + 0) = *(s32 *)((s8 *)temp_r31 + 8) & 0x03FFFFFF;
        *(u32 *)((s8 *)arg3 + 0) = (u32) (*(s32 *)((s8 *)temp_r31 + 8) & 0xFC000000) >> 0x1AU;
    } else {
        *(s32 *)((s8 *)arg2 + 0) = -1;
        *(u32 *)((s8 *)arg3 + 0) = (u32) (*(s32 *)((s8 *)temp_r31 + 8) & 0xFC000000) >> 0x1AU;
    }
    return 0;
}
