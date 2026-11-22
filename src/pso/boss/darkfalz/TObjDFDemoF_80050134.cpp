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
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/SoundEffect.h"

extern "C" {

const char *TObjDFDemoF__name = "TObjDFDemoF";

s32 TObjDFDemoF__bml_model_id_table[3] = {0x0, 0x10, 0x11};
s32 lbl_80485834[3] = {-1, 0x26, 0x27};
Vec lbl_80485840 = {-20000.0f, 0.0f, 0.0f};
CameraAngles lbl_8048584C = {0, 0, 0};
CameraPlayback lbl_80485858 = {0, 5, 0, 0.0f, 0.5f};
Vec three_part_model_translate_offset = {-20000.0f, 0.0f, 0.0f};

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
        motion_indices = lbl_80485834;
        texture_index = model_index;
        this->models[i] = (NJS_OBJECT *)get_bml_model(archive, model_index);
        this->textures[i] = (GinjaTextureList *)get_bml_texlist(archive, texture_index);
        if (motion_indices[i] < 0) {
            this->motions[i] = NULL;
        } else {
            this->motions[i] = get_bml_motion(archive, motion_indices[i]);
        }
    }
    self->frame = -1.0f;
    activate_camera_mode(5);
    set_scripted_camera_pose(&lbl_80485840, &lbl_80485840, &lbl_8048584C);
    lbl_80485858.cache_target_and_forward(0x392D);
    play_sound_effect(0x3A802, 0, 0, 0);
    start_pad_rumble_all(0x20, 0xF);
    this->timer = 0;
}

TObjDFDemoF::~TObjDFDemoF() {
    restore_player_cameras();
}

}
