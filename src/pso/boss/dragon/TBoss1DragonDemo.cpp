#include "pso/boss/dragon/TBoss1DragonDemo.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/camera/CameraPlayback.h"

#include "pso/camera/TCameraCtrl.h"

struct RecoveredGlobal_8002B744___vt__16TBoss1DragonDemo {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
CameraPlayback *get_scripted_camera_playback();
s32 isV2Mode__12TBoss1DragonFv();
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8002B744___vt__16TBoss1DragonDemo __vt__16TBoss1DragonDemo;
extern s32 TBoss1DragonDemo__name;

void TBoss1DragonDemo__sub_8002B68C(void) {  }
void TBoss1DragonDemo__sub_8002B690(void) {  }

void TBoss1DragonDemo::render() {  }

void TBoss1DragonDemo::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((get_scripted_camera_playback()->flags & 1) || ((s32) **(s32 **)((s8 *)arg0 + 0x24) == 0)) {
        restore_player_cameras();
        queue_destruction__7TObjectFv((arg0));
    }
}
typedef char RecoveredGlobal_8002B744___vt__16TBoss1DragonDemo_size[sizeof(RecoveredGlobal_8002B744___vt__16TBoss1DragonDemo) == 0x18 ? 1 : -1];
TBoss1DragonDemo::~TBoss1DragonDemo() {}
u8 *__ct__16TBoss1DragonDemoFv(u8 *object, s32 arg1, s32 arg2, f32 farg0) {
    CameraPlayback playback;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__16TBoss1DragonDemo.value;
    *(s32 *)((s8 *)object + 0) = TBoss1DragonDemo__name;
    *(f32 *)((s8 *)object + 0x1C) = farg0;
    *(f32 *)((s8 *)object + 0x20) = 0.0f;
    *(s32 *)((s8 *)object + 0x24) = arg2;
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        playback.bank = 1;
        playback.index = 0;
        playback.flags = 0;
        playback.frame = *(f32 *)((s8 *)object + 0x20);
        playback.frame_step = *(f32 *)((s8 *)object + 0x1C);
        activate_camera_mode(5);
        playback.cache_target_and_forward(0x238E);
        break;
    case 1:
        playback.bank = 1;
        playback.index = 1;
        playback.flags = 0;
        playback.frame = *(f32 *)((s8 *)object + 0x20);
        playback.frame_step = *(f32 *)((s8 *)object + 0x1C);
        activate_camera_mode(5);
        playback.cache_target_and_forward(0x3333);
        break;
    }
    return object;
}

}
