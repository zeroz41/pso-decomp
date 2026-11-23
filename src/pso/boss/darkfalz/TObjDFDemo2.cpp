#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TObjDFDemo3.h"
#include "pso/boss/darkfalz/TObjDFDemo2.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

extern "C" {
extern s32 boss4_zanzo_bml_index_table[];

const char *TObjDFDemo2__name = "TObjDFDemo2";
__declspec(section ".rodata") CameraAngles df_demo2_zero_camera_angles = {0, 0, 0};
__declspec(section ".data") s32 TObjDFDemo2__motion_index_table[2] = {0x12, 0x11};
CameraPlayback df_demo2_camera_playback = {0, 0, 0, 0.0f, 0.5f};

TObjDFDemo2 *TObjDFDemo2::create(TObject *parent, const Vec *position, s32 angle, s32 variant) {
    return new TObjDFDemo2(parent, position, angle, variant);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
TObjDFDemo2::TObjDFDemo2(TObject *parent, const Vec *position, s32 angle, s32 variant) : TObjBase(parent) {
    s32 k;
    BmlResource *archive;
    saddr i;

    this->m_name = TObjDFDemo2__name;
    VecCopy(&this->camera_position, position);
    this->angle = angle;
    this->variant = variant;
    archive = TBoss4Uro::get_instance_count();
    for (i = 0; i < 2; i++) {
        s32 t = boss4_zanzo_bml_index_table[i];
        k = t;
        this->parts[i].model = (NJS_OBJECT *)get_bml_model(archive, t);
        this->parts[i].texlist = get_bml_texlist(archive, k);
        this->parts[i].motion = get_bml_motion(archive, TObjDFDemo2__motion_index_table[i]);
    }
    this->frame = -0.5f;
    activate_camera_mode(5);
    {
        CameraAngles p = df_demo2_zero_camera_angles;
        p.yaw = this->angle;
        set_scripted_camera_origin(&this->camera_position, &this->camera_position, &p);
    }
    df_demo2_camera_playback.play(0x4444);
    play_sound_effect(0x4003A325, &this->camera_position, 0, 1);
    this->timer = 0;
}
#pragma pop

TObjDFDemo2::~TObjDFDemo2() {
}

void TObjDFDemo2::run_task() {
    TParticleCtrl *effect;
    if (timer == 0x90) {
        effect = (TParticleCtrl *)spawn_particle_effect(&camera_position, 0xC3);
        if (effect != NULL) {
            effect->set_flags(0x40);
        }
        play_sound_effect(0x4003AD15, &camera_position, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
    }
    while (timer >= 0xB4) {
        if (variant != 0 || timer <= 0xDC) {
            effect = (TParticleCtrl *)spawn_particle_effect(&camera_position, 0x14E);
            if (effect != NULL) {
                effect->set_flags(0x40);
            }
        }
        break;
    }
    if ((frame += 0.5f) > 119.0f) {
        frame = 119.0f;
    }
    if (++timer >= 0x118) {
        queue_destruction();
    }
}

void TObjDFDemo2::render() {
    f32 alpha;
    s32 i;
    alpha = 1.0f;
    if (variant == 0) {
        if (timer >= 0xF0) {
            return;
        }
        if (timer > 0xC8) {
            alpha = (f32)(0xF0 - timer) / 40.0f;
        }
    }
    if (alpha <= 0.0f) {
        return;
    }
    if (alpha < 1.0f) {
        TObjPlayer::begin_alpha_blend(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&camera_position.x);
    rotate_matrix_y(0, angle);
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(parts[i].texlist));
        draw_model_motion(parts[i].model, parts[i].motion, frame);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}
}
