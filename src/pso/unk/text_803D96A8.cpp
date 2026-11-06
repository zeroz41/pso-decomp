#include "types.h"
#include "pso/render/GinjaModelQueue.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/math/AngleLookup.h"

struct Q_803D98E4 { f32 x, y, z, w; };

struct Q_803D993C { f32 x, y, z, w; };

struct A_803D9DA8 { u8 pad[0xC]; u8 *p; };

struct B_803D9DA8 { s32 a; u16 b; u16 c; };

struct G_803D9DA8 { u8 pad[8]; s32 f8; };

struct Matrix34 { f32 elements[3][4]; };

struct Ent_803D9E38 { u8 *p; s32 a; s32 b; };

struct Tbl_803D9E38 { u8 pad[8]; Ent_803D9E38 arr[1]; };

extern u32 matrix_stack_base;
extern u32 current_matrix;
extern "C" {
f32 PSMTXConcat(int, int, int);
extern u32 matrix_stack_limit;
void PSMTXQuat(void *, void *);
s32 fn_803DA12C(u8 *, s32, s32, s32);
extern G_803D9DA8 lbl_8058D470;
s32 TObjPlayer__sub_803D9DA8(A_803D9DA8 *arg0, B_803D9DA8 *arg1);
void PSMTXRotRad(Matrix34*, char, f32);
void rotate_matrix_x(Matrix34* matrix, s32 angle);
s32 find_free_slot__10TObjPlayerFPvPv(void *, int);
s32 TObjPlayer__sub_803DAD24(int, int);
extern s32 record_array_ptr;

__declspec(section ".sdata2") extern const f64 lbl_805E0F48;
void rotate_matrix_x(Matrix34* matrix, s32 angle) {
    Matrix34 rotation;
    Matrix34* selected;
    if (angle != 0) {
        if (matrix == NULL) selected = (Matrix34*)current_matrix;
        else selected = matrix;
        PSMTXRotRad(&rotation, 'x', (f32)(lbl_805E0F48 * (f64)angle));
        PSMTXConcat((int)selected, (int)&rotation, (int)selected);
    }
}

#pragma push
#pragma scheduling off
void TObjPlayer::concat_matrix(u32 arg0, u32 arg1) {
    u32 elements;
    u32 var_r4;
    elements = arg0;
    var_r4 = arg1;
    if (elements == 0U) {
        elements = current_matrix;
    }
    if (var_r4 == 0U) {
        var_r4 = current_matrix;
    }
    PSMTXConcat(elements, var_r4, elements);
}
#pragma pop

#pragma push
#pragma peephole off
#pragma fp_contract on
void TCameraCtrl::concat_matrix(u32 arg0, u32 arg1) {
    u32 var_r4;
    u32 elements;
    var_r4 = arg1;
    if (arg0 == 0U) {
        elements = current_matrix;
    } else {
        elements = arg0;
    }
    if (var_r4 == 0U) {
        var_r4 = current_matrix;
    }
    PSMTXConcat(var_r4, elements, elements);
}
#pragma pop

asm f32 normalize_vector(Vec *v) {
#include "orig_asm/pso/unk/text_803D96A8/normalize_vector.inc"
}

#pragma push
#pragma scheduling off
s32 push_matrix_from(void *src) {
    u32 next = current_matrix + 0x30;
    if (next > matrix_stack_limit) {
        return 0;
    }
    ((TLobby *)next)->move_data((src == 0) ? (void *)current_matrix : src, 0x30);
    current_matrix = next;
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
s32 pop_matrices(s32 arg0) {
    u32 temp_r3;
    temp_r3 = current_matrix - (arg0 * 0x30);
    if (temp_r3 < (u32) matrix_stack_base) {
        return 0;
    }
    current_matrix = temp_r3;
    return 1;
}
#pragma pop

asm void transform_point_by_current_matrix(const f32 *src, Vec *dst) {
#include "orig_asm/pso/unk/text_803D96A8/transform_point_by_current_matrix.inc"
}

void TObjPlayer::concat_quaternion_rotation() {
    f32 *arg0 = (f32 *)this;
    u8 sp18[0x30];
    Q_803D98E4 q;
    q.w = arg0[0];
    q.x = arg0[1];
    q.y = arg0[2];
    q.z = arg0[3];
    PSMTXQuat(sp18, &q);
    PSMTXConcat(current_matrix, (int)sp18, current_matrix);
}

void TObjPlayer::apply_quat_rotation(f32 farg0) {
    f32 *arg0 = (f32 *)this;
    u8 sp18[0x30];
    Q_803D993C q;
    q.w = farg0;
    q.x = arg0[0];
    q.y = arg0[1];
    q.z = arg0[2];
    PSMTXQuat(sp18, &q);
    PSMTXConcat(current_matrix, (int)sp18, current_matrix);
}

// 0.0f in .sdata, read by the assembly below (not yet split into this unit).
extern f32 lbl_805D46B8;

asm void rotate_vector_by_current_matrix(const Vec *src, Vec *dst) {
#include "orig_asm/pso/unk/text_803D96A8/rotate_vector_by_current_matrix.inc"
}

asm void rotate_matrix_by_node_angles(const s32 *ang, u32 zxy) {
#include "orig_asm/pso/unk/text_803D96A8/rotate_matrix_by_node_angles.inc"
}

asm s32 push_matrix(void) {
#include "orig_asm/pso/unk/text_803D96A8/push_matrix.inc"
}

#pragma push
#pragma scheduling off
s32 pop_matrix(void) {
    u32 temp_r3;
    temp_r3 = current_matrix - 0x30;
    if (temp_r3 < (u32) matrix_stack_base) {
        return 0;
    }
    current_matrix = temp_r3;
    return 1;
}
#pragma pop

asm void scale_current_matrix(const f32 *v) {
#include "orig_asm/pso/unk/text_803D96A8/scale_current_matrix.inc"
}

asm void post_translate_matrix(const f32 *v) {
#include "orig_asm/pso/unk/text_803D96A8/post_translate_matrix.inc"
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TObjPlayer__sub_803D9C60(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
}
#pragma pop

u32 *find_gvrt_texture_chunk(TLobby *lobby, u32 *arg1, u32 *arg2) {
    u32 tag;
    u32 *p = arg2;
    if (arg1 != NULL) {
        *arg1 = 0xFFFFFFFF;
    }
    do {
        tag = *p;
        TObjPlayer__sub_803D9C60(&tag);
        switch (tag) {
        case 0x54525647:
            lobby->move_data(p + 2, 8);
            return p + 4;
        case 0x58494247: {
            u32 len;
            p++;
            len = *p++;
            TObjPlayer__sub_803D9C60(&len);
            if (arg1 != NULL) {
                *arg1 = *p;
            }
            p += len >> 2;
            break;
        }
        default:
            lbl_8058D470.f8 = 4;
            return NULL;
        }
    } while (tag != 0x54525647);
    return p;
}

s32 TObjPlayer__sub_803D9DA8(A_803D9DA8 *arg0, B_803D9DA8 *arg1) {
    if (fn_803DA12C(arg0->p + 4, arg1->b, arg1->c, arg1->a) != 0) {
        lbl_8058D470.f8 = 6;
        return -1;
    }
    return 1;
}

#pragma push
#pragma peephole off
s32 TObjPlayer::is_gvm_load_ok() {
    if (TObjPlayer__sub_803DB244() == 0) {
        return 1;
    }
    return -1;
}
#pragma pop

s32 TObjPlayer__sub_803D9E38(s32 *arg0, u32 arg1, s32 *arg2, u32 *arg3) {
    s32 sp8;
    u32 j;
    s32 *temp_r4;
    s32 *temp_r4_2;
    s32 temp_r0;
    s32 temp_r3;
    s32 record_index;
    s32 temp_r6;
    u8 *temp_r29;
    u8 *temp_r31;
    temp_r6 = *(s32 *)((s8 *)arg0 + 0);
    temp_r31 = (u8 *)(temp_r6 + (arg1 * 0xC));
    temp_r3 = *(s32 *)((s8 *)temp_r31 + 4);
    if (((u32) (temp_r3 & 0x10000) != 0) && (arg1 != 0)) {
        *(u32 *)((s8 *)arg3 + 0) = (u32) (*(s32 *)((s8 *)temp_r31 + 8) & 0xFC000000) >> 0x1AU;
        j = arg1 - 1;
        temp_r29 = ((Tbl_803D9E38 *)temp_r6)->arr[j].p;
        *(s32 *)((s8 *)arg2 + 0) = *(s32 *)((s8 *)(*(s32 **)((s8 *)temp_r29 + 0xC)) + 0);
        record_index = TObjPlayer::find_record_index((int) (*(s32 *)((s8 *)arg2 + 0)), (int) (*(u32 *)((s8 *)arg3 + 0)));
        if (record_index < 0) {
            if (find_free_slot__10TObjPlayerFPvPv(&sp8, 0) < 0) {
                return -1;
            }
            *(s32 *)((s8 *)temp_r31 + 8) = sp8;
            *(u32 *)((s8 *)sp8 + 8) = (u32) *(u32 *)((s8 *)arg3 + 0);
            *(s32 **)((s8 *)sp8 + 0xC) = (s32 *) *(s32 **)((s8 *)temp_r29 + 0xC);
            *(s32 *)((s8 *)sp8 + 0x10) = 1;
            temp_r4 = (s32 *)(*(s32 **)((s8 *)sp8 + 0xC));
            *(s32 *)((s8 *)temp_r4 + 0x24) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x24) + 1);
            *(s32 *)((s8 *)sp8 + 0x14) = (s32) *(s32 *)((s8 *)temp_r29 + 0x14);
            TObjPlayer__sub_803DAD24((int)sp8, (int)temp_r4);
            goto block_7;
        }
        temp_r0 = record_array_ptr + (record_index * 0x18);
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
