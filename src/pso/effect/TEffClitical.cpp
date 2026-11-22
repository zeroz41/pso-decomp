#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/TEffClitical.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

#include "pso/system/vector.h"
#include "pso/system/NinjaTypes.h"

#include "types.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/camera/TCameraCtrl.h"
f32 TEffClitical__alpha_approach_step = 0.15f;
const char* TEffClitical__class_name = "TEffClitical";

// The texture list TEffClitical::render() draws its ring with (one name, filled at load).
NJS_TEXNAME clitical_texture_names[1];
__declspec(section ".data") NJS_TEXLIST clitical_texture_list = { clitical_texture_names, 1 };

extern "C" {
f32 vector_length(void *);
s32 post_translate_matrix(void *);
extern s32 technique_ringwave_texture_list[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *__ct__12TEffCliticalFPv(void *arg0, void *arg1);

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

void TEffClitical::render() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r3;
    set_depth_buffer_settings_1();
    init_texture_copy_rect((void *)((void *)&sp8), (saddr)&clitical_texture_list, (saddr)technique_ringwave_texture_list, 0, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x70) + 1)));
    temp_r3 = model_render_flags;
    saved_model_render_flags = temp_r3;
    model_render_flags = temp_r3 | 0x10;
    TParticleCtrl::begin_effect_render();
    set_constant_material((const NJS_ARGB *)((arg0 + 0x2C)));
    copy_anim_frame_to_slot((TextureFrameSlot *)&sp8);
    push_matrix();
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(&clitical_texture_list));
    post_translate_matrix(arg0 + 0x20);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    scale_matrix(0, (f32) (*(f32 *)((s8 *)arg0 + 0x3C)), (f32) (*(f32 *)((s8 *)arg0 + 0x40)), (f32) (*(f32 *)((s8 *)arg0 + 0x44)));
    draw_chunk_object((void *)(*(saddr *)effect_rel));
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
                spawn_particle_effect((const Vec *)(arg0 + 0x20), 7);
                break;
            case 1:
                spawn_particle_effect((const Vec *)(arg0 + 0x20), 0xB);
                break;
            case 2:
                pos.x = position.x;
                pos.y = position.y - 20.0f;
                pos.z = position.z;
                spawn_particle_effect(&pos, 0xC);
                break;
            case 3:
                spawn_particle_effect((const Vec *)(arg0 + 0x20), 0xE);
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
    o = TObject::operator new(0x78);
    if (o != NULL) {
        __ct__12TEffCliticalFPv(o, this);
    }
}

void init_texture_copy_rect(void *arg0, saddr arg1, saddr arg2, s32 arg3, s32 arg4) {
    *(s32 *)((s8 *)arg0 + 0) = arg2;
    *(s32 *)((s8 *)arg0 + 4) = arg1;
    *(s32 *)((s8 *)arg0 + 8) = arg4;
    *(s32 *)((s8 *)arg0 + 0xC) = arg3;
}
void approach_position_if_far(u8 *from, u8 *to, f32 farg0) {
    Vec stack;
    f32 temp_f1;
    stack.x = *(f32 *)((s8 *)from + 0) - *(f32 *)((s8 *)to + 0);
    stack.y = *(f32 *)((s8 *)from + 4) - *(f32 *)((s8 *)to + 4);
    stack.z = *(f32 *)((s8 *)from + 8) - *(f32 *)((s8 *)to + 8);
    temp_f1 = vector_length(&stack.x);
    if (temp_f1 > farg0) {
        approach_vector_fixed_distance((const Vec *)from, (const Vec *)to, (Vec *)from, temp_f1 * farg0);
    }
}
