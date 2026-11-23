#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#include "pso/system/BmlResource.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TObjDFDemo3.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"

#pragma readonly_strings on

#include "pso/system/MatrixStack.h"

extern "C" {
s32 vec3_add_to(void *, void *);
f32 vector_length(void *);

const char *TObjDFDemo3__name = "TObjDFDemo3";
__declspec(section ".rodata") CameraAngles df_demo3_zero_camera_angles = {0, 0, 0};
ModelNodePositionEntry df_demo3_node_capture_entries[2] = {{0}, {-1}};
CameraPlayback df_demo3_camera_playback = {0, 6, 0, 0.0f, 1.0f};

TObjDFDemo3 *TObjDFDemo3::create(TObject *parent, const Vec *position, s32 angle) {
    return new TObjDFDemo3(parent, position, angle);
}

TObjDFDemo3::TObjDFDemo3(TObject *parent, const Vec *position, s32 angle) : TObjBase(parent) {
    BmlResource *cnt;
    this->m_name = TObjDFDemo3__name;
    VecCopy(&this->camera_position, position);
    this->camera_position.y = 0.0f;
    {
        Vec v = this->camera_position;
        v.y = 0.0f;
        if (!(vector_length(&v) <= 0.01f)) {
            normalize_vector(&v);
            v.x *= -50.0f;
            v.z *= -50.0f;
            vec3_add_to(&this->camera_position, &v);
        }
    }
    this->angle = angle;
    cnt = TBoss4Uro::get_instance_count();
    this->part.model = (NJS_OBJECT *)get_bml_model(cnt, 0x12);
    this->part.texlist = get_bml_texlist(cnt, 0x12);
    this->part.motion = get_bml_motion(cnt, 0x45);
    this->frame = -1.0f;
    this->emitters[0] = NULL;
    activate_camera_mode(5);
    {
        CameraAngles c = df_demo3_zero_camera_angles;
        c.yaw = this->angle;
        const Vec *camera_position = &this->camera_position;
        set_scripted_camera_origin(camera_position, camera_position, &c);
    }
    df_demo3_camera_playback.play(0x1555);
    this->node_list = ModelNodePositionCapture::create(df_demo3_node_capture_entries, &this->emitter_position);
    this->timer = 0;
}

TObjDFDemo3::~TObjDFDemo3() {
    s32 i;
    if (node_list != NULL) {
        ModelNodePositionCapture::destroy(node_list);
        node_list = NULL;
    }
    for (i = 0; i < 1; i++) {
        if (emitters[i] != NULL) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = NULL;
        }
    }
    if (TBoss4DarkFalz::is_ending_or_split_screen() == 0) {
        restore_player_cameras();
    }
}

#pragma push
#pragma opt_common_subs off
void TObjDFDemo3::run_task() {
    s32 current_timer;
    s32 next_timer;
    TParticleCtrl *particle;
    if (timer >= 0x5A) {
        if (emitters[0] != NULL) {
            TParticleCtrl::release(emitters[0]);
            emitters[0] = NULL;
        }
    } else {
        particle = emitters[0];
        if (particle == NULL) {
            emitters[0] = create_particle_emitter(&emitter_position, 0x1BD);
            if (emitters[0] != NULL) {
                emitters[0]->set_flags(0x40);
            }
        } else if (particle != NULL) {
            particle->set_position(&emitter_position);
        }
    }
    if (timer == 0x86) {
        particle = (TParticleCtrl *)spawn_particle_effect(&camera_position, 0x9B);
        if (particle != NULL) {
            particle->set_flags(0x40);
        }
    }
    current_timer = timer;
    if (current_timer == 0x28 || current_timer == 0x3C) {
        play_sound_effect(0x4003D03A, &camera_position, 0, 1);
    }
    if ((frame += 1.0f) > 119.0f) {
        frame = 119.0f;
    }
    next_timer = timer + 1;
    timer = next_timer;
    if (next_timer >= 0x8C) {
        queue_destruction();
    }
}
#pragma pop

void TObjDFDemo3::render() {
    f32 a = 1.0f;
    s32 t = timer;
    if (t < 5) {
        a = (f32)t / 5.0f;
    } else if (t > 0x86) {
        a = (f32)(0x8B - t) / 5.0f;
    }
    if (a <= 0.0f) {
        return;
    }
    if (a < 1.0f) {
        TObjPlayer::begin_alpha_blend(a);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&camera_position.x);
    rotate_matrix_y(0, angle);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(part.texlist));
    node_list->install();
    set_chunk_render_flags(1);
    draw_model_motion(part.model, part.motion, frame);
    node_list->clear();
    set_chunk_render_flags(2);
    draw_model_motion(part.model, part.motion, frame);
    clear_chunk_render_flags();
    clear_motion_packed_rotation();
    pop_matrix();
    if (a < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}
}
