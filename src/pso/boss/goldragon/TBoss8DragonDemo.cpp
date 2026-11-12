#include "pso/boss/goldragon/TBoss8DragonDemo.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/camera/CameraPlayback.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/camera/TCameraCtrl.h"

#pragma readonly_strings on

struct RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo {
    s32 value;
    u8 remaining[0x14];
};

struct Obj_8002B118 { u8 pad[0x1c]; void *colli[3]; };

extern "C" {
CameraPlayback *get_scripted_camera_playback();
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo __vt__16TBoss8DragonDemo;
extern const char *TBoss8DragonDemo__name;
extern const f32 lbl_805DED18;

void TBoss8DragonDemo::render() {  }

void TBoss8DragonDemo::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((get_scripted_camera_playback()->flags & 1) || ((s32) **(s32 **)((s8 *)arg0 + 0x24) == 0)) {
        restore_player_cameras();
        queue_destruction__7TObjectFv((arg0));
    }
}
typedef char RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo_size[sizeof(RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo) == 0x18 ? 1 : -1];
TBoss8DragonDemo::~TBoss8DragonDemo() {}
u8 *__ct__16TBoss8DragonDemoFv(u8 *object, s32 arg1, s32 arg2, f32 farg0) {
    CameraPlayback playback;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__16TBoss8DragonDemo.value;
    *(s32 *)((s8 *)object + 0) = (s32) ((s32)TBoss8DragonDemo__name);
    *(f32 *)((s8 *)object + 0x1C) = farg0;
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805DED18;
    *(s32 *)((s8 *)object + 0x24) = arg2;
    playback.bank = 1;
    playback.index = 0;
    playback.flags = 0;
    playback.frame = *(f32 *)((s8 *)object + 0x20);
    playback.frame_step = *(f32 *)((s8 *)object + 0x1C);
    activate_camera_mode(5);
    playback.cache_target_and_forward(0x3333);
    return object;
}
void TBoss8Dragon::update_colli_parts() {
    Obj_8002B118 *self = (Obj_8002B118 *)this;
    s32 i;
    for (i = 0; i < 3; i++) {
        TBoss8DragonColli__sub_802F3074(self->colli[i]);
    }
}

}

extern "C" {
const char *TBoss8DragonDemo__name = "TBoss8DragonDemo";
}

