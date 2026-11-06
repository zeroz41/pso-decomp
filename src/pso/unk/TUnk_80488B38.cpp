#include "types.h"
#include "pso/unk/TUnk_80488B38.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/unk/TUnk_80488B38.h"
#include "pso/unk/TUnk_80488B68.h"
#include "pso/unk/TUnk_80488B08.h"
#include "pso/system/vector.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraHelpers.h"
#include <stddef.h>
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/camera/TCameraCtrl_8006C580.h"
#include "pso/system/memory.h"
#include "pso/unk/TUnk_80488D70.h"
#include "pso/system/scene/TScene.h"

struct Vec_8006BB1C { f32 x, y, z; };

struct Pad_8006BB1C {
    u8 pad0[0x70];
    u32 buttons;
    u8 pad74[0x84 - 0x74];
    s16 sx;
    s16 sy;
};

struct Obj_8006BB1C {
    u8 pad0[0x2c];
    s32 yaw;
    s32 pitch;
    u8 pad34[0x3c - 0x34];
    Vec_8006BB1C eye;
    Vec_8006BB1C at;
    u8 pad54[0x6c - 0x54];
    f32 dist;
};

extern "C" {
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern Pad_8006BB1C controller_input_state;
void *TCameraCtrl__vt4(void);
void *__dt__13TUnk_80488B38Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);

void *TCameraCtrl__vt4(void) {
    void *o = (void *)new TUnk_80488B38();
    return o;
}

extern s32 __vt__13TUnk_80488B38[];

#pragma push
#pragma fp_contract on
void TUnk_80488B38::run_task() {
    Obj_8006BB1C *arg0 = (Obj_8006BB1C *)this;
    Pad_8006BB1C *pad = &controller_input_state;
    u32 btn = pad->buttons;
    s16 sx = pad->sx;
    s16 sy = pad->sy;
    f32 r;
    if (btn & 0x20000) {
        arg0->dist += (2.2f);
    } else if (btn & 0x10000) {
        arg0->dist -= (2.2f);
    }
    if (arg0->dist < 10.0f) {
        arg0->dist = 10.0f;
    }
    if (arg0->dist > 300.0f) {
        arg0->dist = 300.0f;
    }
    arg0->pitch += sx * 3;
    this->m_2c += sy * 3;
    r = arg0->dist * cos_table_lookup(this->m_2c);
    arg0->eye.x = r * sin_table_lookup(arg0->pitch) + arg0->at.x;
    arg0->eye.y = arg0->at.y - arg0->dist * sin_table_lookup(this->m_2c);
    arg0->eye.z = r * cos_table_lookup(arg0->pitch) + arg0->at.z;
}
#pragma pop

}
TUnk_80488B38::~TUnk_80488B38() {

}

extern void* camera_controller_registry[];

void* camera_controller_registry[];

struct CameraMotionData;
TUnk_80488B38::TUnk_80488B38() : TUnk_80488A28() {
    *(float *)&this->unk_6C = 10.0f;
    this->m_38 = 0;
}

#pragma push
#pragma opt_common_subs off
#pragma pop

#pragma push
#pragma fp_contract on

#pragma pop
