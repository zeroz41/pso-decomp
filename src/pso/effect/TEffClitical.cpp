#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffClitical.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_80087278.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"

#include "types.h"
#include "pso/system/task/TObject.h"

struct Stack_80082688 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
f32 TEffClitical__alpha_approach_step = 0.15f;
const char* TEffClitical__class_name = "TEffClitical";

// The texture list TEffClitical::render() draws its ring with (one name, filled at load).
NJS_TEXNAME clitical_texture_names[1];
__declspec(section ".data") NJS_TEXLIST clitical_texture_list = { clitical_texture_names, 1 };

extern "C" {
f32 vector_length(void *);
s32 begin_effect_render__13TParticleCtrlFv(int);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 technique_ringwave_texture_list[];
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *__ct__12TEffCliticalFPv(void *arg0, void *arg1);
void *__nw__7TObjectFUl(int);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

void TEffClitical::render() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r3;
    set_depth_buffer_settings_1();
    init_texture_copy_rect((void *)((void *)&sp8), (s32)&clitical_texture_list, (s32)technique_ringwave_texture_list, 0, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x70) + 1)));
    temp_r3 = model_render_flags;
    saved_model_render_flags = temp_r3;
    model_render_flags = temp_r3 | 0x10;
    begin_effect_render__13TParticleCtrlFv(temp_r3);
    set_constant_material((const NJS_ARGB *)((arg0 + 0x2C)));
    copy_anim_frame_to_slot((TextureFrameSlot *)&sp8);
    push_matrix();
    TObjFish::set_global_param((s32)&clitical_texture_list);
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
    NJS_ARGB target_color = { 0.0f, 1.0f, 1.0f, 1.0f };
    Vec target_scale = { 2.0f, 2.0f, 2.0f };
    Vec pos;
    s32 var_r30;
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
                pos.x = position.x;
                pos.y = position.y - 20.0f;
                pos.z = position.z;
                spawn_particle_effect(&pos, 0xC);
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
    if (approach_alpha_clamped(&color.a, &target_color.a, TEffClitical__alpha_approach_step) != 0) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    approach_vector_in_place(&scale, &target_scale, 0.2f);
    *(s32 *)((s8 *)arg0 + 0x70) = (s32) (*(s32 *)((s8 *)arg0 + 0x70) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x70) >= 7) {
        *(s32 *)((s8 *)arg0 + 0x70) = 0;
    }
}
#pragma pop

TEffClitical::~TEffClitical() {}
}
TEffClitical::TEffClitical(void *arg1) : TEffect() {
    m_name = TEffClitical__class_name;
    VecCopy((Vec *)((char *)this + 32), (const Vec *)arg1);
    *(u32 *)((s8 *)this + 0x70) = 0;
    *(f32 *)((s8 *)this + 0x2C) = 1.0f;
    *(f32 *)((s8 *)this + 0x30) = 1.0f;
    *(f32 *)((s8 *)this + 0x34) = 1.0f;
    *(f32 *)((s8 *)this + 0x38) = 1.0f;
    *(f32 *)((s8 *)this + 0x3C) = 1.0f;
    *(f32 *)((s8 *)this + 0x40) = 1.0f;
    *(f32 *)((s8 *)this + 0x44) = 1.0f;
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
