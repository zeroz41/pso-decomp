#pragma readonly_strings on

#include "pso/object/TObjVoloptShutter.h"
#include "pso/TMainTask.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/GinjaTextureMatrices.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
s32 push_matrix(void);
void rotate_matrix_y(s32 matrix, s32 angle);
}

static const char *TObjVoloptShutter_name = "TObjVoloptShutter";

void *volopt_shutter_model_a;
void *volopt_shutter_model_b;
s32 volopt_shutter_global_param;

void TObjVoloptShutter::update_shutter_slide() {
    switch (substate) {
    case 0:
        offset_z -= -1.8f;
        if (offset_z >= 0.0f) {
            offset_z = 0.0f;
            substate = 1;
        }
        break;
    case 1:
        offset_y -= -0.3f;
        if (offset_y >= 0.0f) {
            offset_y = 0.0f;
            state = 0;
        }
        break;
    }
}

void TObjVoloptShutter::update_shutter_state() {
    switch (substate) {
    case 0:
        offset_y += -0.3f;
        if (offset_y <= -3.0f) {
            offset_y = -3.0f;
            substate = 1;
        }
        break;
    case 1:
        offset_z += -1.8f;
        if (offset_z <= -18.0f) {
            offset_z = -18.0f;
            state = 0;
        }
        break;
    }
}

void TObjVoloptShutter::render() {
    TObjPlayer::toggle_particle_effect();
    TObjFish::set_global_param(volopt_shutter_global_param);
    push_matrix();
    model_render_flags &= ~0x400;
    rotate_matrix_y(0, rotation_y);
    push_matrix();
    translate_matrix(0, 0.0f, 0.0f, offset_z);
    draw_chunk_model(volopt_shutter_model_b);
    translate_matrix(0, 0.0f, offset_y, 0.0f);
    draw_chunk_model(volopt_shutter_model_a);
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TObjVoloptShutter::run_task() {
    switch (state) {
    case 0:
        break;
    case 1:
        update_shutter_slide();
        break;
    case 2:
        update_shutter_state();
        break;
    }
}

TObjVoloptShutter::~TObjVoloptShutter() {}

TObjVoloptShutter::TObjVoloptShutter(s32 index) : TObject(tl_04) {
    m_name = TObjVoloptShutter_name;
    this->index = index;
    rotation_y = (s32)(182.04445f * (f32)(-90 - index * 60));
    offset_y = 0.0f;
    offset_z = 0.0f;
}
