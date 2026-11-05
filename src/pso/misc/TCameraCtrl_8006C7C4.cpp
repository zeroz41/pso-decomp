#include "types.h"
#include "pso/misc/TUnk_80488D70.h"
#include "pso/misc/TUnk_80488B38.h"
#include "pso/misc/TUnk_80488B68.h"
#include "pso/misc/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/CameraHelpers.h"
#include <stddef.h>
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TCameraCtrl_80067FC0.h"
#include "pso/misc/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_80488D70.h"
#include "pso/misc/TScene.h"

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
