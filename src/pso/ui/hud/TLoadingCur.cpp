#include "pso/object/trap/TOTrapAncient01_80226534.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TLoadingCur.h"
#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/unk/text_80086FE0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/ControllerInput.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/NinjaTypes.h"

struct Stack_8001CAD4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_8001CAD4_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Obj_8001CBC4 { u8 pad[0x44]; Vec pos; };

extern "C" {
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
#pragma push
#pragma readonly_strings on
const char *TLoadingCur__class_name = "TLoadingCur";
#pragma pop
extern const Stack_8001CAD4 lbl_804349FC = {0, 0, 0};
extern RecoveredGlobal_8001CAD4_lbl_8058D490 identity_matrix;

LAYOUT_ASSERT(LoadingCursorRotationSize, sizeof(Stack_8001CAD4) == 0xC);
LAYOUT_ASSERT(RecoveredGlobal_8001CAD4_lbl_8058D490_size, sizeof(RecoveredGlobal_8001CAD4_lbl_8058D490) == 0x30);
void TLoadingCur::update_camera_facing_offset() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8001CAD4, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8001CAD4, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8001CAD4, sp10) == 0x8);
    Stack_8001CAD4 stack;
    if ((u32) *(u32 *)((s8 *)arg0 + 0x1C) != 0U) {
        VecCopy((Vec *)(arg0 + 0x2C), (const Vec *)(arg0 + 0x20));
        stack.sp8 = lbl_804349FC.sp8;
        stack.spC = lbl_804349FC.spC;
        stack.sp10 = lbl_804349FC.sp10;
        *(f32 *)((s8 *)arg0 + 0x50) = (f32) -ninja_camera.vx;
        this->m_54 = (f32) -ninja_camera.vy;
        *(f32 *)&this->unk_58 = (f32) -ninja_camera.vz;
        direction_to_rotation_xy((arg0 + 0x50), (&stack.sp8), (&stack.spC));
        push_matrix_from((void *)&identity_matrix.value);
        rotate_matrix_y(0, stack.spC);
        rotate_matrix_x(0, stack.sp8);
        rotate_vector_by_matrix(0, (u8 *)&this->m_20, (u8 *)&this->_pad48);
        pop_matrices(1);
        vec3_add_to((u8 *)&this->_pad48, arg0 + 0x44);
        ((TParticleCtrl *)*(uaddr *)((s8 *)arg0 + 0x1C))->set_position((u8 *)&this->_pad48);
    }
}
#pragma push
#pragma fp_contract on
Vec calc_loading_cursor_pos(Obj_8001CBC4 *o) {
    if (camera_ctrl_instance != NULL) {
        o->pos.x = 1e+02f * ninja_camera.vx + ninja_camera.px;
        o->pos.y = 1e+02f * ninja_camera.vy + ninja_camera.py;
        o->pos.z = 1e+02f * ninja_camera.vz + ninja_camera.pz;
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

extern "C" {

s32 __ct__7TObjectFP7TObject(void *, void *);



s32 project_world_to_screen(int, void *, void *);

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
        *(f32 *)((s8 *)arg2 + 0) = 0.0f;
    }
    temp_f1_3 = *(f32 *)((s8 *)arg1 + 4);
    if (temp_f1_3 < 5e+01f) {
        *(f32 *)((s8 *)arg2 + 4) = (f32) (5e+01f - temp_f1_3);
    } else if (temp_f1_3 > 4.3e+02f) {
        *(f32 *)((s8 *)arg2 + 4) = (f32) (4.3e+02f - temp_f1_3);
    } else {
        *(f32 *)((s8 *)arg2 + 4) = 0.0f;
    }
    temp_f0 = *(f32 *)((s8 *)arg2 + 0);
    temp_f1 = *(f32 *)((s8 *)arg2 + 4);
    return (u32)__cntlzw((u32)((((temp_f0 * temp_f0) + (temp_f1 * temp_f1)) <= 0.0f))) >> 5;
}

void TLoadingCur::sub_8001CCD4() {
    Obj_8001CCD4 *self = (Obj_8001CCD4 *)this;
    f32 sp10[2];
    NJS_POINT2 v;
    push_matrix();
    project_world_to_screen(0, (u8 *)self + 0x2c, sp10);
    pop_matrix();
    if (TLoadingCur::calc_clamp_offset((s32)((saddr)self), (u8 *)((u8 *)sp10), (u8 *)((u8 *)&v)) != 0) {
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

void TLoadingCur::render() { sub_8001CCD4(); }

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TLoadingCur::run_task() {
    Self_8001CD90 *self = (Self_8001CD90 *)this;
    f32 x;
    f32 y;
    u32 flags;
    ControllerInputContext *p;
    f32 z;
    x = 0.0f;
    y = x;
    x += 0.0078125f * (f32)controller_input_state.controllers[0].stick_x;
    y -= 0.0078125f * (f32)controller_input_state.controllers[0].stick_y;
    x += 0.0078125f * (f32)controller_input_state.controllers[0].cstick_x;
    y -= 0.0078125f * (f32)controller_input_state.controllers[0].cstick_y;
    flags = controller_input_state.controllers[0].buttons;
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
    p = &controller_input_state.keyboard;
    if (test_previous_buttons_color(p, 0x10) != 0) {
        y += 1.0f;
    }
    if (test_previous_buttons_color(p, 0x20) != 0) {
        y -= 1.0f;
    }
    if (test_previous_buttons_color(p, 0x80) != 0) {
        x += 1.0f;
    }
    if (test_previous_buttons_color(p, 0x40) != 0) {
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
            play_persistent_sound(0x53C10, reinterpret_cast<saddr>(this), reinterpret_cast<uaddr>((u8 *)this + 0x2C), 0, 1);
        } else {
            play_persistent_sound(0x53C10, reinterpret_cast<saddr>(this), reinterpret_cast<uaddr>((u8 *)this + 0x2C), 0, 0);
        }
    }
}
#pragma pop

}
TLoadingCur::~TLoadingCur() {
    if (*(void **)((s8 *)this + 0x1C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x1C)))->queue_destruction(); *(s32 *)((s8 *)this + 0x1C) = 0; }
}

#pragma push
#pragma fp_contract on
#define object ((u8 *)this)
TLoadingCur::TLoadingCur(TObject *parent, Vec *pos) : TObject(parent) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8001D0A0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8001D0A0, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8001D0A0, sp10) == 0x8);
    Stack_8001D0A0 stack;
    *(s32 *)((s8 *)object + 0) = (saddr) TLoadingCur__class_name;
    *(f32 *)((s8 *)object + 0x20) = 0.0f;
    *(f32 *)((s8 *)object + 0x24) = 0.0f;
    *(f32 *)((s8 *)object + 0x28) = 0.0f;
    *(f32 *)((s8 *)object + 0x38) = 0.0f;
    *(f32 *)((s8 *)object + 0x3C) = 0.0f;
    *(f32 *)((s8 *)object + 0x40) = 0.0f;
    *(f32 *)((s8 *)object + 0x44) = (f32) ((1e+02f * ninja_camera.vx) + ninja_camera.px);
    *(f32 *)((s8 *)object + 0x48) = (f32) ((1e+02f * ninja_camera.vy) + ninja_camera.py);
    *(f32 *)((s8 *)object + 0x4C) = (f32) ((1e+02f * ninja_camera.vz) + ninja_camera.pz);
    *(f32 *)((s8 *)object + 0x50) = (f32) -ninja_camera.vx;
    *(f32 *)((s8 *)object + 0x54) = (f32) -ninja_camera.vy;
    *(f32 *)((s8 *)object + 0x58) = (f32) -ninja_camera.vz;
    stack.sp8 = 0;
    stack.spC = 0;
    stack.sp10 = 0;
    direction_to_rotation_xz((object + 0x50), (&stack.sp8), (&stack.sp10));
    *(s32 *)((s8 *)object + 0x1C) = (saddr)fn_80086FE0((object + 0x20), (&stack.sp8), 0x16, 1);
}
#undef object
#pragma pop
