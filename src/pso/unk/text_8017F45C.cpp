#include "types.h"
#include "pso/unk/text_8017F45C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_C { u8 bytes[0xc]; };

struct RecoveredGlobal_8017F45C_lbl_804B5830 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8017F45C_lbl_804B5830_size[sizeof(RecoveredGlobal_8017F45C_lbl_804B5830) == 0x10 ? 1 : -1];

struct R_8017F52C { s32 a; u8 pad[0x14]; };

struct O_8017F52C { u8 pad[0x100]; R_8017F52C recs[8]; };

struct Entry_8017F4AC { u8 vec[0xC]; f32 time; void *obj; u32 done; };

struct Self_8017F4AC { u8 pad[0xB0]; f32 t; u8 padb4[0xEC - 0xB4]; Entry_8017F4AC e[8]; };

struct Rec_8017F550 { u8 pad[0x14]; s32 f14; };

struct Obj_8017F550 { u8 pad0[0x38]; u8 pos[0x28]; s32 f60; u8 pad1[0x88]; Rec_8017F550 recs[8]; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8017F45C_lbl_804B5830 bm_o_abe_butterfly_resource_descriptor;
extern s32 butterfly_bml_resource;
void fn_8017F52C(O_8017F52C *self);
s32 play_sound_effect(s32, void *, s32, s32);
void fn_8017F4AC(Self_8017F4AC *self);
void vec3_add_to(void *, void *);
void matrix_mult_vec(int, void *, void *);
void rotate_matrix_y(int, s32);
extern Rec_8017F550 lbl_804439D8[];
extern u8 identity_matrix[];
void fn_8017F550(Obj_8017F550 *arg0);

void fn_8017F45C(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_abe_butterfly_resource_descriptor.value, 0, 0, 0));
    }
    butterfly_bml_resource = var_r0;
}

void fn_8017F4AC(Self_8017F4AC *self) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (self->e[i].done == 0 && self->t >= self->e[i].time) {
            play_sound_effect((s32)self->e[i].obj, self->e[i].vec, 0, 0);
            self->e[i].done = 1;
        }
    }
}

void fn_8017F52C(O_8017F52C *self) {
    s32 i;
    for (i = 0; i < 8; i++) {
        self->recs[i].a = 0;
    }
}

void fn_8017F550(Obj_8017F550 *arg0) {
    s32 i;
    for (i = 0; i < 8; i++) {
        fn_8017F5F0((u8 *)&arg0->recs[i], (u8 *)&lbl_804439D8[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, arg0->f60);
        matrix_mult_vec(0, &arg0->recs[i], &arg0->recs[i]);
        pop_matrix();
        vec3_add_to(&arg0->recs[i], arg0->pos);
        arg0->recs[i].f14 = 0;
    }
}

void fn_8017F5F0(u8 *arg0, u8 *arg1) {
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(f32 *)((s8 *)arg0 + 0xC) = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x10) = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
}

}
