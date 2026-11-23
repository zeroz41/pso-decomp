#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"

const char *TObjDFDemoF__name = "TObjDFDemoF";

s32 TObjDFDemoF__bml_model_id_table[3] = {0x0, 0x10, 0x11};
s32 df_demof_motion_ids[3] = {-1, 0x26, 0x27};
Vec df_demof_camera_position = {-20000.0f, 0.0f, 0.0f};
CameraAngles df_demof_camera_angles = {0, 0, 0};
CameraPlayback df_demof_camera_playback = {0, 5, 0, 0.0f, 0.5f};
Vec three_part_model_translate_offset = {-20000.0f, 0.0f, 0.0f};

// With defer_codegen the functions below are emitted last to first.
TObjDFDemoF *TObjDFDemoF::create(TObject *parent) {
    return new TObjDFDemoF(parent);
}

#pragma push
#pragma opt_propagation off
#pragma opt_common_subs off
TObjDFDemoF::TObjDFDemoF(TObject *parent) : TObjBase(parent) {
    saddr texture_index;
    s32 *motion_indices;
    BmlResource *archive;
    TObjDFDemoF *self;
    saddr i;

    self = this;
    self->m_name = TObjDFDemoF__name;
    archive = TBoss4Uro::get_instance_count();
    for (i = 0; i < 3; i++) {
        s32 model_index = TObjDFDemoF__bml_model_id_table[i];
        motion_indices = df_demof_motion_ids;
        texture_index = model_index;
        this->models[i] = (NJS_OBJECT *)get_bml_model(archive, model_index);
        this->textures[i] = get_bml_texlist(archive, texture_index);
        if (motion_indices[i] < 0) {
            this->motions[i] = NULL;
        } else {
            this->motions[i] = get_bml_motion(archive, motion_indices[i]);
        }
    }
    self->frame = -1.0f;
    activate_camera_mode(5);
    set_scripted_camera_origin(&df_demof_camera_position, &df_demof_camera_position, &df_demof_camera_angles);
    df_demof_camera_playback.play(0x392D);
    play_sound_effect(0x3A802, 0, 0, 0);
    start_pad_rumble_all(0x20, 0xF);
    this->timer = 0;
}

TObjDFDemoF::~TObjDFDemoF() {
    restore_player_cameras();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TObjDFDemoF::run_task() {
    s32 count;
    if ((frame += 1.0f) >= 120.0f) {
        frame = 120.0f;
    }
    count = timer + 1;
    timer = count;
    if (count >= 120) {
        queue_destruction();
    }
}
#pragma pop

void TObjDFDemoF::render() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&three_part_model_translate_offset.x);
    s32 i = 0;
    do {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures[i]));
        AnimationMotion *motion = motions[i];
        if (motion == NULL) {
            draw_chunk_object(models[i]);
        } else {
            draw_model_motion(models[i], motion, frame);
        }
        i++;
    } while (i < 3);
    clear_motion_packed_rotation();
    pop_matrix();
}
