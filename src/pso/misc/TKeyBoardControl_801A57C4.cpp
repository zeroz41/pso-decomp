#include "types.h"
#include "pso/misc/TKeyBoardControl_80131C58.h"
#include "pso/misc/TKeyBoardControl_801A57C4.h"
#include "pso/misc/TKeyBoardControl.h"

struct RecoveredGlobal_801A58B0_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_801A58D8_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct Pad_801A57D0 { u8 pad0[0x10]; u32 f10; u8 pad14[4]; u16 f18; u16 f1A; s16 f1C; s16 f1E; };

extern s32 TKeyBoardControl__global_key_state[];
extern Pad_801A57D0 *controller_input_state[];
extern "C" {
u8 TKeyBoardControl__sub_8013239C(void *, u8);
s32 OSGetResetButtonState();
s32 TKeyBoardControl__sub_801323C8(void *, void *);

    extern unsigned char lbl_805D5D09;
void TKeyBoardControl::reset() { lbl_805D5D09 = 0; }

extern u8 keyboard_reset_button_pressed;

s32 TKeyBoardControl::any_pad_input_active() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Pad_801A57D0 *p = controller_input_state[i];
        if (p->f10 != 0 || p->f18 >= 10 || p->f1A >= 10 || p->f1C >= 10 || p->f1C <= -10 || p->f1E >= 10 || p->f1E <= -10) {
            return 1;
        }
    }
    return 0;
}

s32 TKeyBoardControl::check_reset_button() {
    if (OSGetResetButtonState() != 0) {
        keyboard_reset_button_pressed = 1;
    }
    if ((s8) keyboard_reset_button_pressed != 0) {
        if (OSGetResetButtonState() != 0) {
            return 0;
        }
        keyboard_reset_button_pressed = 0;
        return 1;
    }
    return 0;
}

typedef char RecoveredGlobal_801A58B0_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_801A58B0_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TKeyBoardControl__sub_801A58B0(void) {
    TKeyBoardControl__sub_801321B4((s32) &(*(RecoveredGlobal_801A58B0_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value);
}

typedef char RecoveredGlobal_801A58D8_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_801A58D8_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
void TKeyBoardControl__sub_801A58D8(void) {
    TKeyBoardControl__sub_80132310((s32) &(*(RecoveredGlobal_801A58D8_TKeyBoardControl__data_80506270 *)&TKeyBoardControl__global_key_state).value);
}

s32 TKeyBoardControl::check_and_read(s32 arg0) {
    if (TKeyBoardControl::check_input_ready((s32)TKeyBoardControl__global_key_state) != 0) {
        return TKeyBoardControl::is_key_down(arg0);
    }
    return 0;
}

s32 TKeyBoardControl::read_input(s32 arg0) {
    if (TKeyBoardControl::check_input_ready((s32)TKeyBoardControl__global_key_state) != 0) {
        return ((s32 (*)(s32))update_state_from_input__16TKeyBoardControlFPv)(arg0);
    }
    return 0;
}

s32 TKeyBoardControl::is_key_down(s32 arg0) {
    s32 i;
    s32 n;
    n = ((TKeyBoardControl *)((s32 *)&TKeyBoardControl__global_key_state))->get_key_state_2();
    for (i = 0; i < n; i++) {
        if ((u8)arg0 == TKeyBoardControl__sub_8013239C(((s32 *)&TKeyBoardControl__global_key_state), i)) {
            return 1;
        }
    }
    return 0;
}

void update_state_from_input__16TKeyBoardControlFPv(void *arg0) {
    TKeyBoardControl__sub_801323C8(TKeyBoardControl__global_key_state, arg0);
}

extern s32 actor_frame_tick;

s32 TKeyBoardControl::check_input_angle() {
    s32 temp_r4_2;
    void *temp_r4;
    s32 temp_r5;
    u16 temp_r0;

    temp_r4 = *(void * *)&this->m_prev;
    if (temp_r4 == NULL) {
        return 0;
    }
    if (*(f32 *)((s8 *)temp_r4 + 0x24) < 0.5f) {
        return 0;
    }
    temp_r5 = *(s32 *)&this->m_name;
    *(s32 *)&this->m_name = *(s32 *)((s8 *)temp_r4 + 0x1C);
    temp_r0 = temp_r5 - *(s32 *)&this->m_name;
    if (((s32) temp_r0 > 0x5000) && ((s32) temp_r0 < 0xB000)) {
        temp_r4_2 = *(s32 *)&this->m_flags;
        *(s32 *)&this->m_flags = (s32) actor_frame_tick;
        if ((s32) (*(s32 *)&this->m_flags - temp_r4_2) < 8) {
            return 1;
        }
    }
    return 0;
}
}

void init_stick_escape_detector(void *arg0, void *arg1) {
    if (arg1 != NULL) {
        *(void **)((s8 *)arg0 + 8) = arg1;
        *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 8)) + 0x1C);
        *(s32 *)((s8 *)arg0 + 4) = (s32) actor_frame_tick;
    }
}
