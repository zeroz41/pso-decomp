#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli_C.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D2810 = "TBoss5GryphonDemo";
}


struct Obj_800665FC { s32 f0; u8 pad4[0x14]; void *f18; f32 f1c; f32 f20; s32 f24; };

struct Cam_800665FC { s8 f8; s8 f9; s16 fa; f32 fc; f32 f10; };

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
void set_camera_capture_overlay_alpha(int a0);
s32 restore_player_cameras();
u8 *get_scripted_camera_playback();

int TBoss8Dragon__sub_8005D700(void);
s32 activate_camera_mode(s32 arg0);
extern const char *lbl_805D2810;

void TBoss5GryphonDemo::render() {  }

void TBoss5GryphonDemo::run_task() {
    u8 *arg0 = (u8 *)this;
    u8 *scripted_camera_playback;
    scripted_camera_playback = get_scripted_camera_playback();
    set_camera_capture_overlay_alpha(0x8F);
    if ((*(u16 *)((s8 *)scripted_camera_playback + 2) & 1) || ((s32) **(s32 **)((s8 *)arg0 + 0x24) == 0)) {
        restore_player_cameras();
        queue_destruction__7TObjectFv((arg0));
    }
}
TBoss5GryphonDemo::~TBoss5GryphonDemo() {}
}
TBoss5GryphonDemo::TBoss5GryphonDemo(TObject *parent, s32 arg2, f32 farg0) : TObject(parent) {
    Cam_800665FC c;
    ((Obj_800665FC *)this)->f0 = ((s32)lbl_805D2810);
    ((Obj_800665FC *)this)->f1c = farg0;
    ((Obj_800665FC *)this)->f20 = 0.0f;
    ((Obj_800665FC *)this)->f24 = arg2;
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        c.f8 = 1;
        c.f9 = 0;
        c.fa = 0;
        c.fc = ((Obj_800665FC *)this)->f20;
        c.f10 = ((Obj_800665FC *)this)->f1c;
        activate_camera_mode(5);
        ((TCameraCtrl *)(&c))->cache_target_and_forward(0x238E);
        break;
    }
}
