#include "pso/boss/goldragon/TBoss8DragonDemo.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/camera/CameraPlayback.h"

#include <stddef.h>
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/camera/TCameraCtrl.h"

#pragma readonly_strings on
struct Stack_802F2D8C {
    s8 sp8;
    s8 sp9;
    s16 spA;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_802F2CC4_lbl_804E4A44 {
    s32 value;
    u8 remaining[0x8C];
};

struct Obj_8002B118 { u8 pad[0x1c]; void *colli[3]; };

extern "C" {
u8 *get_scripted_camera_playback();
s32 __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo __vt__16TBoss8DragonDemo;
extern const char *TBoss8DragonDemo__name;
extern const f32 lbl_805DED18;
extern RecoveredGlobal_802F2CC4_lbl_804E4A44 lbl_804E4A44;
extern const f32 lbl_805DE9F4;
int VecCopy__FP3VecPC3Vec(void*);

int TBoss8DragonDemo::copy_position() { return VecCopy__FP3VecPC3Vec((char*)this + 0x78); }
f32 TBoss8DragonDemo__sub_802F2CB4(void* p) { return *(f32*)((char*)p + 0x5c); }
f32 TBoss8DragonDemo__sub_802F2CBC(void* p) { return *(f32*)((char*)p + 0x54); }

typedef char RecoveredGlobal_802F2CC4_lbl_804E4A44_size[sizeof(RecoveredGlobal_802F2CC4_lbl_804E4A44) == 0x90 ? 1 : -1];
void __sinit_TBoss8DragonDemo_cpp(void) {
    *(f32 *)((s8 *)&lbl_804E4A44.value + 4) = (f32) lbl_805DE9F4;
    *(f32 *)((s8 *)&lbl_804E4A44.value + 0x10) = (f32) lbl_805DE9F4;
}

void TBoss8DragonDemo::render() {  }

void TBoss8DragonDemo::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((*(u16 *)((s8 *)(get_scripted_camera_playback()) + 2) & 1) || ((s32) **(s32 **)((s8 *)arg0 + 0x24) == 0)) {
        restore_player_cameras();
        queue_destruction__7TObjectFv((arg0));
    }
}
typedef char RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo_size[sizeof(RecoveredGlobal_802F2D8C___vt__16TBoss8DragonDemo) == 0x18 ? 1 : -1];
TBoss8DragonDemo::~TBoss8DragonDemo() {}
u8 *__ct__16TBoss8DragonDemoFv(u8 *object, s32 arg1, s32 arg2, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_802F2D8C, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_802F2D8C, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_802F2D8C, spA) == 0x2) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802F2D8C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802F2D8C, sp10) == 0x8) ? 1 : -1];
    Stack_802F2D8C stack;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__16TBoss8DragonDemo.value;
    *(s32 *)((s8 *)object + 0) = (s32) ((s32)TBoss8DragonDemo__name);
    *(f32 *)((s8 *)object + 0x1C) = farg0;
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805DED18;
    *(s32 *)((s8 *)object + 0x24) = arg2;
    stack.sp8 = 1;
    stack.sp9 = 0;
    stack.spA = 0;
    stack.spC = *(f32 *)((s8 *)object + 0x20);
    stack.sp10 = *(f32 *)((s8 *)object + 0x1C);
    activate_camera_mode(5);
    ((CameraPlayback *)(&stack.sp8))->cache_target_and_forward(0x3333);
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

__declspec(section ".ctors") static void *const __sinit_TBoss8DragonDemo_cpp_ref = (void *)__sinit_TBoss8DragonDemo_cpp;

extern "C" {
const char *TBoss8DragonDemo__name = "TBoss8DragonDemo";
}

