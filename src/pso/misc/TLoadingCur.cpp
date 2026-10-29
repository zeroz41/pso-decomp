#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TLoadingCur.h"
#include <stddef.h>
#include "pso/misc/TNowLoading.h"
#include "pso/unk/text_80086FE0.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TParticleCtrl.h"

struct Stack_8001CAD4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8001CAD4_lbl_804349FC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8001CAD4_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8001CAD4_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Vec_8001CBC4 { f32 x, y, z; };

struct Tbl_8001CBC4 { Vec_8001CBC4 base; Vec_8001CBC4 dir; };

struct Obj_8001CBC4 { u8 pad[0x44]; Vec_8001CBC4 pos; };

extern "C" {
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
extern RecoveredGlobal_8001CAD4_lbl_804349FC lbl_804349FC;
extern RecoveredGlobal_8001CAD4_lbl_804FF5E8 lbl_804FF5E8;
extern RecoveredGlobal_8001CAD4_lbl_8058D490 identity_matrix;
extern u32 camera_ctrl_instance;

typedef char RecoveredGlobal_8001CAD4_lbl_804349FC_size[sizeof(RecoveredGlobal_8001CAD4_lbl_804349FC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8001CAD4_lbl_804FF5E8_size[sizeof(RecoveredGlobal_8001CAD4_lbl_804FF5E8) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_8001CAD4_lbl_8058D490_size[sizeof(RecoveredGlobal_8001CAD4_lbl_8058D490) == 0x30 ? 1 : -1];
void TLoadingCur::update_camera_facing_offset() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_8001CAD4, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8001CAD4, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8001CAD4, sp10) == 0x8) ? 1 : -1];
    Stack_8001CAD4 stack;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) != 0U) {
        VecCopy((Vec *)(arg0 + 0x2C), (const Vec *)(arg0 + 0x20));
        stack.sp8 = *(s32 *)((s8 *)&lbl_804349FC.value + 0);
        stack.spC = *(s32 *)((s8 *)&lbl_804349FC.value + 4);
        stack.sp10 = *(s32 *)((s8 *)&lbl_804349FC.value + 8);
        *(f32 *)((s8 *)arg0 + 0x50) = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0xC);
        this->m_54 = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x10);
        *(f32 *)&this->unk_58 = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x14);
        direction_to_rotation_xy((arg0 + 0x50), (&stack.sp8), (&stack.spC));
        push_matrix_from((void *)&identity_matrix.value);
        rotate_matrix_y(0, stack.spC);
        rotate_matrix_x(0, stack.sp8);
        rotate_vector_by_matrix(0, arg0 + 0x20, (u8 *)&this->_pad48);
        pop_matrices(1);
        vec3_add_to((u8 *)&this->_pad48, arg0 + 0x44);
        ((TParticleCtrl *)*(u32 *)((s8 *)arg0 + 0x1C))->set_position((u8 *)&this->_pad48);
    }
}
#pragma push
#pragma fp_contract on
Vec_8001CBC4 calc_loading_cursor_pos(Obj_8001CBC4 *o) {
    if (camera_ctrl_instance != 0) {
        o->pos.x = 1e+02f * (*(Tbl_8001CBC4 *)&lbl_804FF5E8).dir.x + (*(Tbl_8001CBC4 *)&lbl_804FF5E8).base.x;
        o->pos.y = 1e+02f * (*(Tbl_8001CBC4 *)&lbl_804FF5E8).dir.y + (*(Tbl_8001CBC4 *)&lbl_804FF5E8).base.y;
        o->pos.z = 1e+02f * (*(Tbl_8001CBC4 *)&lbl_804FF5E8).dir.z + (*(Tbl_8001CBC4 *)&lbl_804FF5E8).base.z;
    }
    return o->pos;
}
#pragma pop

}

struct Stack_8001D0A0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8001D0A0___vt__11TLoadingCur {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8001D0A0_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};

struct Pad_8001CD90 {
    char pad0[0x20];
    u32 f20;
    char pad24[0x10];
    s16 s34;
    s16 s36;
    s16 s38;
    s16 s3A;
    char pad3C[0x124];
    u8 f160[0x20];
};

struct Self_8001CD90 {
    char pad0[0x20];
    f32 f20;
    f32 f24;
    f32 f28;
    char pad2C[0xC];
    f32 f38;
    f32 f3C;
    f32 f40;
    u8 f44[0xC];
};

struct Obj_8001CCD4 { u8 pad0[0x38]; f32 f38; f32 f3c; f32 f40; };

struct V2_8001CCD4 { f32 x, y; };

extern "C" {

s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__11TLoadingCur[];

extern s32 TLoadingCur__class_name;

s32 is_split_screen(void);

s32 is_flag_set__11TLoadingCurFv(void *, s32);
s32 play_persistent_sound(int, void *, void *, int, int);
extern Pad_8001CD90 controller_input_state;

s32 project_world_to_screen(int, void *, void *);
void push_matrix(void);

s32 TLoadingCur::calc_clamp_offset(s32 arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    temp_f1_2 = *(f32 *)((s8 *)arg1 + 0);
    if (temp_f1_2 < 3e+01f) {
        *(f32 *)((s8 *)arg2 + 0) = (f32) (3e+01f - temp_f1_2);
    } else if (temp_f1_2 > 6.1e+02f) {
        *(f32 *)((s8 *)arg2 + 0) = (f32) (6.1e+02f - temp_f1_2);
    } else {
        *(f32 *)((s8 *)arg2 + 0) = (f32) 0.0f;
    }
    temp_f1_3 = *(f32 *)((s8 *)arg1 + 4);
    if (temp_f1_3 < 5e+01f) {
        *(f32 *)((s8 *)arg2 + 4) = (f32) (5e+01f - temp_f1_3);
    } else if (temp_f1_3 > 4.3e+02f) {
        *(f32 *)((s8 *)arg2 + 4) = (f32) (4.3e+02f - temp_f1_3);
    } else {
        *(f32 *)((s8 *)arg2 + 4) = (f32) 0.0f;
    }
    temp_f0 = *(f32 *)((s8 *)arg2 + 0);
    temp_f1 = *(f32 *)((s8 *)arg2 + 4);
    return (u32)__cntlzw((u32)((((temp_f0 * temp_f0) + (temp_f1 * temp_f1)) <= 0.0f))) >> 5;
}

int TLoadingCur::sub_8001CCD4() {
    Obj_8001CCD4 *self = (Obj_8001CCD4 *)this;
    f32 sp10[2];
    V2_8001CCD4 v;
    push_matrix();
    project_world_to_screen(0, (u8 *)self + 0x2c, sp10);
    pop_matrix();
    if (TLoadingCur::calc_clamp_offset((s32)((s32)self), (u8 *)((u8 *)sp10), (u8 *)((u8 *)&v)) != 0) {
        f32 t[3];
        t[0] = v.x;
        t[1] = v.y;
        t[2] = 0.0f;
        t[0] *= 0.07f;
        t[1] *= (-0.07f);
        t[2] *= 0.07f;
        self->f38 += t[0];
        this->m_3c += t[1];
        self->f40 += t[2];
    }
}

void TLoadingCur::render() { { (void)(sub_8001CCD4()); return; } }

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TLoadingCur::run_task() {
    Self_8001CD90 *self = (Self_8001CD90 *)this;
    f32 x;
    f32 y;
    u32 flags;
    void *p;
    f32 z;
    x = 0.0f;
    y = x;
    x += 0.0078125f * (f32)controller_input_state.s34;
    y -= 0.0078125f * (f32)controller_input_state.s36;
    x += 0.0078125f * (f32)controller_input_state.s38;
    y -= 0.0078125f * (f32)controller_input_state.s3A;
    flags = controller_input_state.f20;
    if (flags & 0x10) {
        y += 1.0f;
    }
    if (flags & 0x20) {
        y -= 1.0f;
    }
    if (flags & 0x80) {
        x += 1.0f;
    }
    if (flags & 0x40) {
        x -= 1.0f;
    }
    p = controller_input_state.f160;
    if (is_flag_set__11TLoadingCurFv(p, 0x10) != 0) {
        y += 1.0f;
    }
    if (is_flag_set__11TLoadingCurFv(p, 0x20) != 0) {
        y -= 1.0f;
    }
    if (is_flag_set__11TLoadingCurFv(p, 0x80) != 0) {
        x += 1.0f;
    }
    if (is_flag_set__11TLoadingCurFv(p, 0x40) != 0) {
        x -= 1.0f;
    }
    self->f38 += 0.51f * x;
    this->m_3c += 0.51f * y;
    self->f40 += (z = 0.0f);
    this->m_20 += self->f38;
    self->f24 += this->m_3c;
    self->f28 += self->f40;
    self->f38 *= 0.9f;
    this->m_3c *= 0.9f;
    self->f40 *= 0.9f;
    VecCopy((Vec *)self->f44, (const Vec *)&calc_loading_cursor_pos((Obj_8001CBC4 *)this));
    update_camera_facing_offset();
    if (0.0f != x || 0.0f != y) {
        if (is_split_screen() != 0) {
            play_persistent_sound(0x53C10, this, (u8 *)this + 0x2C, 0, 1);
        } else {
            play_persistent_sound(0x53C10, this, (u8 *)this + 0x2C, 0, 0);
        }
    }
}
#pragma pop

}
TLoadingCur::~TLoadingCur() {
    if (*(void **)((s8 *)this + 0x1C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x1C)); *(s32 *)((s8 *)this + 0x1C) = 0; }
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8001D0A0___vt__11TLoadingCur_size[sizeof(RecoveredGlobal_8001D0A0___vt__11TLoadingCur) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8001D0A0_lbl_804FF5E8_size[sizeof(RecoveredGlobal_8001D0A0_lbl_804FF5E8) == 0x28 ? 1 : -1];
u8 *TLoadingCur__ct(u8 *object, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_8001D0A0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8001D0A0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8001D0A0, sp10) == 0x8) ? 1 : -1];
    Stack_8001D0A0 stack;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &(*(RecoveredGlobal_8001D0A0___vt__11TLoadingCur *)&__vt__11TLoadingCur).value;
    *(s32 *)((s8 *)object + 0) = (s32) TLoadingCur__class_name;
    *(f32 *)((s8 *)object + 0x20) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x24) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x28) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x38) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x3C) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x40) = (f32) 0.0f;
    *(f32 *)((s8 *)object + 0x44) = (f32) ((1e+02f * *(f32 *)((s8 *)&lbl_804FF5E8.value + 0xC)) + *(f32 *)((s8 *)&lbl_804FF5E8.value + 0));
    *(f32 *)((s8 *)object + 0x48) = (f32) ((1e+02f * *(f32 *)((s8 *)&lbl_804FF5E8.value + 0x10)) + *(f32 *)((s8 *)&lbl_804FF5E8.value + 4));
    *(f32 *)((s8 *)object + 0x4C) = (f32) ((1e+02f * *(f32 *)((s8 *)&lbl_804FF5E8.value + 0x14)) + *(f32 *)((s8 *)&lbl_804FF5E8.value + 8));
    *(f32 *)((s8 *)object + 0x50) = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0xC);
    *(f32 *)((s8 *)object + 0x54) = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x10);
    *(f32 *)((s8 *)object + 0x58) = (f32) -*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x14);
    stack.sp8 = 0;
    stack.spC = 0;
    stack.sp10 = 0;
    direction_to_rotation_xz((object + 0x50), (&stack.sp8), (&stack.sp10));
    *(s32 *)((s8 *)object + 0x1C) = (s32)fn_80086FE0((object + 0x20), (&stack.sp8), 0x16, 1);
    return object;
}
#pragma pop
