#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli_C.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_800666B0.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"

#pragma readonly_strings on


const char *TBoss5GryphonDemo__name = "TBoss5GryphonDemo";


void TBoss5GryphonDemo::render() {  }

void TBoss5GryphonDemo::run_task() {
    CameraPlayback *scripted_camera_playback;
    scripted_camera_playback = get_scripted_camera_playback();
    set_camera_capture_overlay_alpha(0x8F);
    if ((scripted_camera_playback->flags & 1) || *this->done_flag == 0) {
        restore_player_cameras();
        this->queue_destruction();
    }
}
TBoss5GryphonDemo::~TBoss5GryphonDemo() {}
TBoss5GryphonDemo::TBoss5GryphonDemo(TObject *parent, s32 *done_flag, f32 frame_step) : TObject(parent) {
    CameraPlayback c;
    this->m_name = TBoss5GryphonDemo__name;
    this->frame_step = frame_step;
    this->frame = 0.0f;
    this->done_flag = done_flag;
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        c.bank = 1;
        c.index = 0;
        c.flags = 0;
        c.frame = this->frame;
        c.frame_step = this->frame_step;
        activate_camera_mode(5);
        c.play(0x238E);
        break;
    }
}
