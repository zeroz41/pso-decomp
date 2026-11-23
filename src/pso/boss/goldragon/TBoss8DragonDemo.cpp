#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/goldragon/TBoss8DragonDemo.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/camera/CameraPlayback.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/CameraHelpers.h"

#pragma readonly_strings on

extern "C" {
extern const char *TBoss8DragonDemo__name;

void TBoss8DragonDemo::render() {  }

void TBoss8DragonDemo::run_task() {
    if ((get_scripted_camera_playback()->flags & CameraPlayback::FLAG_DONE) || *this->flag == 0) {
        restore_player_cameras();
        queue_destruction();
    }
}
TBoss8DragonDemo::~TBoss8DragonDemo() {}
TBoss8DragonDemo::TBoss8DragonDemo(TObject *parent, s32 *flag, f32 frame_step) : TObject(parent) {
    CameraPlayback playback;
    m_name = TBoss8DragonDemo__name;
    this->frame_step = frame_step;
    this->frame = 0.0f;
    this->flag = flag;
    playback.bank = 1;
    playback.index = 0;
    playback.flags = 0;
    playback.frame = this->frame;
    playback.frame_step = this->frame_step;
    activate_camera_mode(5);
    playback.play(0x3333);
}
void TBoss8DragonColli::disable_blocking_bodies() {
    s32 i;
    for (i = 0; i < 3; i++) {
        objects[i]->disable();
    }
}

void TBoss8DragonColli::enable_blocking_bodies(Vec *pos, s32 angle) {
    s32 i;
    for (i = 0; i < 3; i++) {
        objects[i]->enable_at(pos, angle);
    }
}

const char *TBoss8DragonDemo__name = "TBoss8DragonDemo";
}

