#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecCtrl.h"
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
#include "pso/math/MatrixVector.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/technique/TechniqueRingwaveList.h"
f32 TEffClitical::alpha_approach_step = 0.15f;
const char *TEffClitical::class_name = "TEffClitical";

// The texture list TEffClitical::render() draws its ring with (one name, filled at load).
NJS_TEXNAME clitical_texture_names[1];
NJS_TEXLIST clitical_texture_list = { clitical_texture_names, 1 };

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

void TEffClitical::render() {
    TextureFrameSlot slot;
    u32 flags;
    set_depth_buffer_settings_1();
    init_texture_copy_rect(&slot, &clitical_texture_list, &technique_ringwave_texture_list, 0, frame + 1);
    flags = model_render_flags;
    saved_model_render_flags = flags;
    model_render_flags = flags | 0x10;
    TParticleCtrl::begin_effect_render();
    set_constant_material(&color);
    copy_anim_frame_to_slot(&slot);
    push_matrix();
    TObjFish::set_global_param(&clitical_texture_list);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    scale_matrix(0, scale.x, scale.y, scale.z);
    draw_chunk_object(*effect_rel);
    pop_matrix();
    copy_slot_to_anim_frame(&slot);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    restore_saved_depth_alpha_state();
}

void TEffClitical::run_task() {
    NJS_ARGB target_color = { 0.0f, 1.0f, 1.0f, 1.0f };
    Vec target_scale = { 2.0f, 2.0f, 2.0f };
    Vec pos;
    s32 i;
    switch (phase) {
    case 1:
        break;
    case 0:
        i = 0;
        do {
            switch (i) {
            case 0:
                spawn_particle_effect(&position, 7);
                break;
            case 1:
                spawn_particle_effect(&position, 0xB);
                break;
            case 2:
                pos.x = position.x;
                pos.y = position.y - 20.0f;
                pos.z = position.z;
                spawn_particle_effect(&pos, 0xC);
                break;
            case 3:
                spawn_particle_effect(&position, 0xE);
                break;
            }
            i += 1;
        } while (i < 4);
        phase = 1;
        break;
    }
    if (approach_alpha_clamped(&color.a, &target_color.a, alpha_approach_step) != 0) {
        queue_destruction();
        return;
    }
    approach_vector_in_place(&scale, &target_scale, 0.2f);
    frame = frame + 1;
    if (frame >= 7) {
        frame = 0;
    }
}
#pragma pop

TEffClitical::~TEffClitical() {}

TEffClitical::TEffClitical(Vec *pos) : TEffect() {
    m_name = class_name;
    VecCopy(&position, pos);
    frame = 0;
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    phase = 0;
}

void TEffClitical::create(Vec *pos) {
    new TEffClitical(pos);
}

void init_texture_copy_rect(TextureFrameSlot *slot, NJS_TEXLIST *texlist, NJS_TEXLIST *frames, s32 slot_index,
                            s32 frame) {
    slot->frames = frames;
    slot->texlist = texlist;
    slot->frame = frame;
    slot->slot = slot_index;
}

// Moves `from` towards `to` by `rate` of the distance between them, unless it is already within `rate`.
void approach_position_if_far(Vec *from, Vec *to, f32 rate) {
    Vec delta;
    f32 distance;
    delta.x = from->x - to->x;
    delta.y = from->y - to->y;
    delta.z = from->z - to->z;
    distance = vector_length(&delta);
    if (distance > rate) {
        approach_vector_fixed_distance(from, to, from, distance * rate);
    }
}
