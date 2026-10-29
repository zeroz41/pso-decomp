#include "pso/effect/TEffClitical.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"

#include "types.h"

struct Stack_80082688 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
struct Stack_800823E0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
};

struct RecoveredGlobal_800823E0_lbl_80438EB8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_800823E0_lbl_80438EC8 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
f32 vector_length(void *);
extern RecoveredGlobal_800823E0_lbl_80438EB8 clitical_vec_a;
extern RecoveredGlobal_800823E0_lbl_80438EC8 clitical_vec_b;
extern const f32 TEffClitical__alpha_approach_step;
extern const f32 lbl_805D93A8;
extern const f32 lbl_805D93AC;
s32 begin_effect_render__13TParticleCtrlFv(int);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 lbl_8048E2E0[];
extern s32 technique_ringwave_texture_list[];
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *__ct__12TEffCliticalFPv(void *arg0, void *arg1);
void *__nw__7TObjectFUl(int);

extern void *TEffClitical__class_name;
extern const f32 lbl_805D93B0;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_800823E0_lbl_80438EB8_size[sizeof(RecoveredGlobal_800823E0_lbl_80438EB8) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_800823E0_lbl_80438EC8_size[sizeof(RecoveredGlobal_800823E0_lbl_80438EC8) == 0x10 ? 1 : -1];

void TEffClitical::render() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r3;
    set_depth_buffer_settings_1();
    init_texture_copy_rect((void *)((void *)&sp8), (s32)lbl_8048E2E0, (s32)technique_ringwave_texture_list, 0, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x70) + 1)));
    temp_r3 = model_render_flags;
    saved_model_render_flags = temp_r3;
    model_render_flags = temp_r3 | 0x10;
    begin_effect_render__13TParticleCtrlFv(temp_r3);
    set_constant_material((const NJS_ARGB *)((arg0 + 0x2C)));
    copy_anim_frame_to_slot((TextureFrameSlot *)&sp8);
    push_matrix();
    TObjFish::set_global_param((s32)lbl_8048E2E0);
    post_translate_matrix(arg0 + 0x20);
    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)camera_ctrl_instance + 0x194)));
    scale_matrix(0, (f32) (*(f32 *)((s8 *)arg0 + 0x3C)), (f32) (*(f32 *)((s8 *)arg0 + 0x40)), (f32) (*(f32 *)((s8 *)arg0 + 0x44)));
    draw_chunk_object((void *)(*(s32 *)effect_rel));
    pop_matrix();
    copy_slot_to_anim_frame((TextureFrameSlot *)&sp8);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    restore_saved_depth_alpha_state();
}

void TEffClitical::run_task() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800823E0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800823E0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800823E0, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800823E0, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_800823E0, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_800823E0, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_800823E0, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_800823E0, sp24) == 0x1C) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_800823E0, sp28) == 0x20) ? 1 : -1];
    typedef char sp2C_offset[(offsetof(Stack_800823E0, sp2C) == 0x24) ? 1 : -1];
    Stack_800823E0 stack;
    s32 var_r30;
    stack.sp20 = *(s32 *)((s8 *)&clitical_vec_a.value + 0);
    stack.sp24 = *(s32 *)((s8 *)&clitical_vec_a.value + 4);
    stack.sp28 = *(s32 *)((s8 *)&clitical_vec_a.value + 8);
    stack.sp2C = *(s32 *)((s8 *)&clitical_vec_a.value + 0xC);
    stack.sp14 = *(s32 *)((s8 *)&clitical_vec_b.value + 0);
    stack.sp18 = *(s32 *)((s8 *)&clitical_vec_b.value + 4);
    stack.sp1C = *(s32 *)((s8 *)&clitical_vec_b.value + 8);
    switch (*(s32 *)((s8 *)arg0 + 0x74)) {
    case 1:
        break;
    case 0:
        var_r30 = 0;
        do {
            switch (var_r30) {
            case 0:
                spawn_particle_effect((arg0 + 0x20), 7);
                break;
            case 1:
                spawn_particle_effect((arg0 + 0x20), 0xB);
                break;
            case 2:
                stack.sp8 = *(f32 *)((s8 *)arg0 + 0x20);
                stack.spC = *(f32 *)((s8 *)arg0 + 0x24) - lbl_805D93A8;
                stack.sp10 = *(f32 *)((s8 *)arg0 + 0x28);
                spawn_particle_effect((&stack.sp8), 0xC);
                break;
            case 3:
                spawn_particle_effect((arg0 + 0x20), 0xE);
                break;
            }
            var_r30 += 1;
        } while (var_r30 < 4);
        *(s32 *)((s8 *)arg0 + 0x74) = 1;
        break;
    }
    if (approach_alpha_clamped(&color.a, (const f32 *)&stack.sp20, TEffClitical__alpha_approach_step) != 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    approach_vector_in_place(&scale, (const Vec *)&stack.sp14, lbl_805D93AC);
    *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x70) >= 7) {
        *(s32 *)((s8 *)arg0 + 0x70) = 0;
    }
}
#pragma pop

TEffClitical::~TEffClitical() {}
}
TEffClitical::TEffClitical(void *arg1) : TEffect() {
    *(void * *)&this->m_name = TEffClitical__class_name;
    VecCopy((Vec *)((char *)this + 32), (const Vec *)arg1);
    *(u32 *)((s8 *)this + 0x70) = 0;
    *(f32 *)((s8 *)this + 0x2C) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x30) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x34) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x38) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x3C) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x40) = lbl_805D93B0;
    *(f32 *)((s8 *)this + 0x44) = lbl_805D93B0;
    *(u32 *)((s8 *)this + 0x74) = 0;
}

void TEffClitical::create() {
    void *o;
    o = __nw__7TObjectFUl(0x78);
    if (o != NULL) {
        __ct__12TEffCliticalFPv(o, this);
    }
}

void init_texture_copy_rect(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)arg0 + 0) = arg2;
    *(s32 *)((s8 *)arg0 + 4) = arg1;
    *(s32 *)((s8 *)arg0 + 8) = arg4;
    *(s32 *)((s8 *)arg0 + 0xC) = arg3;
}
void approach_position_if_far(u8 *arg0, u8 *arg1, f32 farg0) {
    Stack_80082688 stack;
    f32 temp_f1;
    stack.sp8 = *(f32 *)((s8 *)arg0 + 0) - *(f32 *)((s8 *)arg1 + 0);
    stack.spC = *(f32 *)((s8 *)arg0 + 4) - *(f32 *)((s8 *)arg1 + 4);
    stack.sp10 = *(f32 *)((s8 *)arg0 + 8) - *(f32 *)((s8 *)arg1 + 8);
    temp_f1 = vector_length(&stack.sp8);
    if (temp_f1 > farg0) {
        approach_vector_fixed_distance((const Vec *)arg0, (const Vec *)arg1, (Vec *)arg0, temp_f1 * farg0);
    }
}
