#include "types.h"
#include "pso/unk/TUnk_80488D70.h"
#include "pso/unk/TUnk_80488B38.h"
#include "pso/unk/TUnk_80488B68.h"
#include "pso/unk/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraHelpers.h"
#include <stddef.h>
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/camera/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/unk/TUnk_80488D70.h"
#include "pso/system/scene/TScene.h"
#include "pso/camera/TCameraCtrl_8006C254.h"

static Entry_8006C6CC lbl_80488B98[1] = { { "CommonCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488BA0[3] = { { "CommonCam.rel", 0x48 }, { "Bo01OpCam.rel", 0xC }, { "Bo01EnCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488BB8[3] = { { "CommonCam.rel", 0x48 }, { "Bo02OpCam.rel", 0xC }, { "Bo02EnCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488BD0[3] = { { "CommonCam.rel", 0x48 }, { "Bo03OpCam.rel", 0xC }, { "Bo03EnCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488BE8[2] = { { "Bo04OpCam.rel", 0x48 }, { "CommonCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488BF8[3] = { { "CommonCam.rel", 0x48 }, { "Bo05OpCam.rel", 0xC }, { "Bo05EnCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488C10[2] = { { "CommonCam.rel", 0x48 }, { "Bo06OpCam.rel", 0x48 } };
static Entry_8006C6CC lbl_80488C20[3] = { { "CommonCam.rel", 0x48 }, { "Bo07OpCam.rel", 0xC }, { "Bo07EnCam.rel", 0xC } };
static Entry_8006C6CC lbl_80488C38[3] = { { "CommonCam.rel", 0x48 }, { "Bo08OpCam.rel", 0xC }, { "Bo08EnCam.rel", 0x48 } };

// Camera path banks per floor area (get_current_floor_area()), read by TCameraCtrl::load_camera_banks.
Bank_8006C6CC camera_path_bank_table[36] = {
    { NULL, 0 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488BA0, 3 },
    { lbl_80488BB8, 3 }, { lbl_80488BD0, 3 }, { lbl_80488BE8, 2 }, { NULL, 0 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { NULL, 0 }, { lbl_80488B98, 1 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 },
    { lbl_80488B98, 1 }, { lbl_80488B98, 1 }, { lbl_80488BF8, 3 }, { lbl_80488C10, 2 },
    { lbl_80488C20, 3 }, { lbl_80488C38, 3 }, { lbl_80488B98, 1 }, { lbl_80488B98, 1 },
};

extern "C" {
void *__dt__13TUnk_80488A28Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

#pragma push
#pragma fp_contract on
#pragma pop

}

extern void *camera_ctrl_instance;
extern void* camera_controller_registry[];

void* camera_controller_registry[];

struct CameraMotionData;
#pragma push
#pragma opt_common_subs off
#pragma pop

#pragma push
#pragma fp_contract on

#pragma pop

extern "C" {

void *TCameraCtrl__vt10(void);
void *__dt__13TUnk_80488D70Fv(void *arg0, s16 arg1);
void *get_player_by_client_id(s32);
void *__nw__7TObjectFUl(int);

}

void *TCameraCtrl__vt10(void) {
    void *o = __nw__7TObjectFUl(0x6C);
    if (o != NULL) {
        o = ((TUnk_80488D70 *)o)->init_subobject();
    }
    return o;
}

void TUnk_80488D70::vfunc_6() {
    void *temp_r31;
    void *player;

    if ((u32) camera_ctrl_instance != 0U) {
        temp_r31 = ((TCameraCtrl *)camera_ctrl_instance)->get_params();
        player = get_player_by_client_id(0);
        if (player != NULL) {
            this->target.x = (f32) *(f32 *)((s8 *)player + 0x38);
            this->target.y = (f32) (19.8f + *(f32 *)((s8 *)player + 0x3C));
            *(f32 *)((s8 *)this + 0x50) = (f32) *(f32 *)((s8 *)player + 0x40);
            this->position.x = (f32) *(f32 *)((s8 *)temp_r31 + 0x1C);
            this->position.y = (f32) *(f32 *)((s8 *)temp_r31 + 0x20);
            this->position.z = (f32) *(f32 *)((s8 *)temp_r31 + 0x24);
            this->m_58 = (f32) *(f32 *)((s8 *)temp_r31 + 0x10);
        }
    }
}

extern s32 __vt__13TUnk_80488D70[];

TUnk_80488D70::~TUnk_80488D70() {

}

extern "C" {
int __ct__13TUnk_80488A28Fv(void);
}

void *TUnk_80488D70::init_subobject() {
    ((void (*)(void *))__ct__13TUnk_80488A28Fv)(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_80488D70;
    this->m_38 = 4;
    return this;
}

void TUnk_80488D70::run_task() {  }
