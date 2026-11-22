#include "types.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/TUnk_80488838.h"
#include "pso/unk/TUnk_80488E00.h"
#include "pso/camera/TCameraCtrl_80067CE8.h"
#include "pso/camera/TCameraCtrl_80067FC0.h"
#include "pso/unk/TUnk_80488DA0.h"
#include "pso/system/ControllerInputState.h"

#include <stddef.h>
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/AngleLookup.h"

struct Pad_80067D20 {
    u32 buttons;
    u8 pad4[0x14 - 0x4];
    s16 sx;
    s16 sy;
};

struct Obj_80067D20 {
    u8 pad0[0x2c];
    s32 yaw;
    s32 pitch;
    u8 pad34[0x3c - 0x34];
    Vec eye;
    Vec at;
    u8 pad54[0x6c - 0x54];
    Pad_80067D20 *pad;
    f32 dist;
};

extern "C" {
s32 set_target_pos__13TUnk_80488DA0FPv(void *, void *, f32);
void *get_player_by_client_id(s32 i);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
void * TCameraCtrl__vt7(void) {
    void *o;
    o = new TUnk_80488838();
    return o;
}

#pragma push
#pragma fp_contract on
void TUnk_80488838::update_orbit_camera() {
    Obj_80067D20 *arg0 = (Obj_80067D20 *)this;
    Pad_80067D20 *pad = arg0->pad;
    f32 d = this->m_70;
    u32 btn = pad->buttons;
    s16 sx = pad->sx;
    s16 sy = pad->sy;
    f32 r;
    if (btn & 0x400) {
        if (btn & 0x20000) {
            d += 2.0f;
            if (d > 1000.0f) {
                d = 1000.0f;
            }
            this->m_70 = d;
        } else if (btn & 0x10000) {
            d = d - 2.0f;
            if (d < 15.0f) {
                d = 15.0f;
            }
            this->m_70 = d;
        }
        arg0->pitch += sx * 3;
        this->m_2c += sy * 3;
    }
    r = this->m_70 * cos_table_lookup(this->m_2c);
    arg0->eye.x = r * sin_table_lookup(arg0->pitch) + arg0->at.x;
    arg0->eye.y = arg0->at.y - this->m_70 * sin_table_lookup(this->m_2c);
    arg0->eye.z = r * cos_table_lookup(arg0->pitch) + arg0->at.z;
}
#pragma pop

void TUnk_80488838::reset_behind_player() {
    Vec stack;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(0));
    if (player != NULL) {
        yaw = *(s32 *)((s8 *)player + 0x60);
        stack.x = 0.0f;
        stack.y = 0.0f;
        stack.z = m_70;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, yaw);
        matrix_mult_vec(0, &stack.x, &stack.x);
        pop_matrix();
        position.x = target.x + stack.x;
        position.y = target.y + stack.y;
        position.z = target.z + stack.z;
    }
}

void target_player0__11TCameraCtrlFi(saddr arg0) {
    Vec stack;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(0));
    if (player != NULL) {
        stack.x = *(f32 *)((s8 *)player + 0x38);
        stack.y = 10.0f + *(f32 *)((s8 *)player + 0x3C);
        stack.z = *(f32 *)((s8 *)player + 0x40);
        set_target_pos__13TUnk_80488DA0FPv((void *)arg0, &stack.x, 10.0f);
    }
}

void TUnk_80488838::reset_state() {
    m_70 = 25.0f;
    m_2c = 0;
    m_34 = 0;
    TCameraCtrl::target_player0((saddr)this);
    reset_behind_player();
}

void TUnk_80488838::run_task() { TCameraCtrl::target_player0((saddr)this); this->update_orbit_camera(); }

}

TUnk_80488838::~TUnk_80488838() {}

TUnk_80488838::TUnk_80488838() : TCameraController() {
    m_38 = 0;
    controller = &controller_input_state.controllers[0];
    reset_state();
}


void TUnk_80488DA0::set_target_pos(void*q) { this->target.x = *(f32*)((char*)q + 0x0); this->target.y = *(f32*)((char*)q + 0x4); this->target.z = *(f32*)((char*)q + 0x8); }
