#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/dragon/TBoss1DragonDemo.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/camera/CameraPlayback.h"

#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/CameraHelpers.h"

#pragma readonly_strings on

extern "C" {
const char *TBoss1DragonDemo__name = "TBoss1DragonDemo";

void TBoss1DragonDemo__sub_8002B68C(void) {  }
void TBoss1DragonDemo__sub_8002B690(void) {  }

void TBoss1DragonDemo::render() {  }

void TBoss1DragonDemo::run_task() {
    if ((get_scripted_camera_playback()->flags & CameraPlayback::FLAG_DONE) || *this->flag == 0) {
        restore_player_cameras();
        queue_destruction();
    }
}
TBoss1DragonDemo::~TBoss1DragonDemo() {}
TBoss1DragonDemo::TBoss1DragonDemo(TObject *parent, s32 *flag, f32 frame_step) : TObject(parent) {
    CameraPlayback playback;
    m_name = TBoss1DragonDemo__name;
    this->frame_step = frame_step;
    this->frame = 0.0f;
    this->flag = flag;
    switch (TBoss1Dragon::isV2Mode()) {
    case 0:
        playback.bank = 1;
        playback.index = 0;
        playback.flags = 0;
        playback.frame = this->frame;
        playback.frame_step = this->frame_step;
        activate_camera_mode(5);
        playback.play(0x238E);
        break;
    case 1:
        playback.bank = 1;
        playback.index = 1;
        playback.flags = 0;
        playback.frame = this->frame;
        playback.frame_step = this->frame_step;
        activate_camera_mode(5);
        playback.play(0x3333);
        break;
    }
}

}
