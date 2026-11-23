#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/effect/photon/TPhotonMagicSquare.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on

const char *photon_magic_square_class_name = "TPhotonMagicSquare";

void TPhotonMagicSquare::render() {
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(0, rotation_y);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    scale_current_matrix(&scale.x);
    NJS_ARGB saved = color;
    if ((age % flash_period) == 0) {
        color.r = 0.5f;
        color.g = 0.5f;
        color.b = 0.5f;
    }
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    if (color.a > 1.0f) {
        color.a = 1.0f;
    }
    set_constant_material(&color);
    set_motion_packed_rotation();
    draw_model_motion(model, motion, frame);
    clear_motion_packed_rotation();
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    copy_argb(&color, &saved);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

#pragma push
#pragma fp_contract on
void TPhotonMagicSquare::run_task() {
    if (age > duration) {
        state = 1;
    }
    switch (state) {
    case 0:
        if (color.a < 1.0f) {
            color.a = 2.0f * fade_rate + color.a;
        }
        if (scale.x < 1.0f) {
            scale.x = 2.0f * fade_rate + scale.x;
            scale.z = 2.0f * fade_rate + scale.z;
        }
        break;
    case 1:
        if (color.a > 0.0f) {
            color.a = color.a - fade_rate;
        }
        if (scale.x > 0.0f) {
            scale.x = scale.x - fade_rate;
            scale.z = scale.z - fade_rate;
        }
        if ((f32)age > (f32)duration + 1.0f / fade_rate) {
            queue_destruction();
            return;
        }
        break;
    }
    age++;
    if (frame < last_frame) {
        frame = frame + frame_step;
    } else {
        frame = 0.0f;
    }
}
#pragma pop

NJS_ARGB TPhotonMagicSquare::color_palette[6] = {
    { 0.0f, 1.0f, 0.15f, 0.5f },
    { 0.0f, 0.0f, 0.65f, 1.0f },
    { 0.0f, 0.85f, 0.4f, 1.0f },
    { 0.0f, 0.85f, 0.4f, 1.0f },
    { 0.0f, 0.0f, 1.0f, 0.4f },
    { 0.0f, 0.0f, 1.0f, 0.75f },
};

TPhotonMagicSquare::~TPhotonMagicSquare() {
}

TPhotonMagicSquare::TPhotonMagicSquare(TObject *parent, s32 palette_index, const Vec *pos, s32 duration, f32 fade_rate)
    : TObjBase(parent) {
    m_name = photon_magic_square_class_name;
    model = photon_blast_shared_resource->models[2].model;
    motion = photon_blast_shared_resource->motions[2].motion;
    frame = 0.0f;
    last_frame = (f32)motion->frameCount - 1.0f;
    frame_step = 0.1f;
    texlist = photon_blast_shared_resource->models[2].texlist;
    scale.x = 0.0f;
    scale.y = 0.0f;
    scale.z = 0.0f;
    copy_argb(&color, &color_palette[palette_index]);
    VecCopy(&this->pos, pos);
    age = 0;
    state = 0;
    this->duration = duration;
    this->fade_rate = fade_rate;
    flash_period = 0xFFFFFF;
}

TPhotonMagicSquare::TPhotonMagicSquare(TObject *parent, s32 palette_index, const Vec *pos, s32 duration)
    : TObjBase(parent) {
    m_name = photon_magic_square_class_name;
    model = photon_blast_shared_resource->models[2].model;
    motion = photon_blast_shared_resource->motions[2].motion;
    frame = 0.0f;
    last_frame = (f32)motion->frameCount - 1.0f;
    frame_step = 0.1f;
    texlist = photon_blast_shared_resource->models[2].texlist;
    scale.x = 0.0f;
    scale.y = 0.0f;
    scale.z = 0.0f;
    copy_argb(&color, &color_palette[palette_index]);
    VecCopy(&this->pos, pos);
    age = 0;
    state = 0;
    this->duration = duration;
    fade_rate = 0.04f;
    flash_period = 0xFFFFFF;
}

// The circle under the player who starts a photon blast (start_photon_blast).
TPhotonMagicSquare::TPhotonMagicSquare(TObject *parent, s32 palette_index, u16 owner_id) : TObjBase(parent) {
    TObjCollidable *owner;
    m_name = photon_magic_square_class_name;
    model = photon_blast_shared_resource->models[2].model;
    motion = photon_blast_shared_resource->motions[2].motion;
    frame = 0.0f;
    last_frame = (f32)motion->frameCount - 1.0f;
    frame_step = 0.1f;
    texlist = photon_blast_shared_resource->models[2].texlist;
    scale.x = 0.0f;
    scale.y = 0.0f;
    scale.z = 0.0f;
    copy_argb(&color, &color_palette[palette_index]);
    owner = find_entity_by_id(owner_id);
    if (owner != NULL) {
        VecCopy(&pos, &owner->position);
    }
    pos.y += 2.0f;
    age = 0;
    state = 0;
    duration = 0x37;
    fade_rate = 0.1f;
    flash_period = 2;
    play_sound_effect(0x4002AD2E, 0, 0, 0);
}
