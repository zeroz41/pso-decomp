#include "types.h"
#include "pso/misc/TUnk_80488838.h"
#include "pso/misc/TUnk_80488E00.h"

struct Stack_80067EE0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

#include <stddef.h>
#include "pso/misc/TCameraCtrl.h"
struct Stack_80067E30 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80067E30_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80067E30_lbl_8058D490_size[sizeof(RecoveredGlobal_80067E30_lbl_8058D490) == 0x30 ? 1 : -1];

struct Vec_80067D20 { f32 x, y, z; };

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
    Vec_80067D20 eye;
    Vec_80067D20 at;
    u8 pad54[0x6c - 0x54];
    Pad_80067D20 *pad;
    f32 dist;
};

extern "C" {
s32 set_target_pos__13TUnk_80488DA0FPv(void *, void *, f32);
void *get_player_by_client_id(s32 i);
void target_player0__11TCameraCtrlFi(s32 arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern RecoveredGlobal_80067E30_lbl_8058D490 identity_matrix;
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
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

void TCameraCtrl::reset_behind_player() {
    typedef char sp8_offset[(offsetof(Stack_80067E30, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80067E30, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80067E30, sp10) == 0x8) ? 1 : -1];
    Stack_80067E30 stack;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(0));
    if (player != NULL) {
        this->m_30 = (s32) *(s32 *)((s8 *)player + 0x60);
        stack.sp8 = 0.0f;
        stack.spC = 0.0f;
        stack.sp10 = this->m_70;
        push_matrix_from(&identity_matrix.value);
        rotate_matrix_y(0, this->m_30);
        matrix_mult_vec(0, &stack.sp8, &stack.sp8);
        pop_matrix();
        this->m_3c = (f32) (*(f32 *)&this->unk_48 + stack.sp8);
        *(f32 *)&this->unk_40 = (f32) (this->m_4c + stack.spC);
        this->m_44 = (f32) (*(f32 *)&this->unk_50 + stack.sp10);
    }
}

void target_player0__11TCameraCtrlFi(s32 arg0) {
    Stack_80067EE0 stack;
    u8 *player;
    player = (u8 *)(get_player_by_client_id(0));
    if (player != NULL) {
        stack.sp8 = *(f32 *)((s8 *)player + 0x38);
        stack.spC = 10.0f + *(f32 *)((s8 *)player + 0x3C);
        stack.sp10 = *(f32 *)((s8 *)player + 0x40);
        set_target_pos__13TUnk_80488DA0FPv((void *)arg0, &stack.sp8, 10.0f);
    }
}

}
