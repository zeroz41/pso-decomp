#include "types.h"
#include "pso/object/switch/TOSwitchTimer.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"
#include <stddef.h>
#include "pso/object/switch/TOChatSensor.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#pragma readonly_strings on

struct Stack_801781D8 {
    s32 sp8;
    s16 spC;
    u16 spE;
    s8 sp10;
    u8 pad_11[0x3];
    s32 sp14;
    s16 sp18;
    u16 sp1A;
    s8 sp1C;
};

void clear_floor_switch_flag(u32 id, s16 floor);
void set_floor_switch_flag(u32 id, s16 floor);
void handle_6x93_set_switch_flag_from_timer(G_SetSwitchFlagFromTimer_6x93 *command) {
    ((TOChatSensor *)command)->swap_state_endian();
    if (command->should_set == 1) {
        set_floor_switch_flag(command->switch_flag_num, command->switch_flag_floor);
    } else if (command->switch_flag_floor != get_current_floor()) {
        clear_floor_switch_flag(command->switch_flag_num, command->switch_flag_floor);
    }
}
extern "C" {

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TOSwitchTimer::send_switch_states() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_801781D8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_801781D8, spC) == 0x4);
    LAYOUT_ASSERT(spE_offset, offsetof(Stack_801781D8, spE) == 0x6);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_801781D8, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_801781D8, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_801781D8, sp18) == 0x10);
    LAYOUT_ASSERT(sp1A_offset, offsetof(Stack_801781D8, sp1A) == 0x12);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_801781D8, sp1C) == 0x14);
    Stack_801781D8 stack;
    u16 *var_r30;
    s32 i;
    if ((u32) this->m_98 == 0U) {
        if ((u16) this->m_a8 < 0x100U) {
            ((TOChatSensor *)(&stack.sp14))->init_packet_type();
            stack.sp18 = this->m_b4;
            stack.sp1A = this->m_a8;
            stack.sp1C = 0;
            ((TOChatSensor *)(&stack.sp14))->send_state();
            clear_floor_switch_flag((this->m_a8), (this->m_b4));
        }
    } else {
        var_r30 = (u16 *)(arg0 + 0xAA);
        i = 0;
        do {
            if ((u16) *var_r30 < 0x100U) {
                ((TOChatSensor *)(&stack.sp8))->init_packet_type();
                stack.spC = this->m_b4;
                stack.spE = *var_r30;
                stack.sp10 = 1;
                ((TOChatSensor *)(&stack.sp8))->send_state();
            }
            i += 1;
            var_r30 = (u16 *)((u8 *)var_r30 + (2));
        } while (i != 3);
    }
}
}
#pragma pop



void TOSwitchTimer::sub_801782A0() {
    s32 i;
    u16 *ids;

    this->m_90 = 0;
    this->m_94 = 0;
    this->m_98 = (u32)this->rotation_x;
    if (this->m_98 >= 2) {
        this->m_98 = 1;
    }
    this->m_9c = this->rotation_y;
    if ((s32)this->m_9c > 1) {
        this->m_9c = 0;
    }
    this->m_a0 = this->rotation_z;
    if ((s32)this->m_a0 < 0) {
        this->m_a0 = 0;
    }
    this->m_a4 = (s32)this->m_a0 * 3 / 4;
    this->m_a8 = this->set_params[0];
    if (this->m_a8 < 0x100) {
        this->m_b0 = is_current_floor_switch_set(this->m_a8);
    } else {
        this->m_a8 = 0xFFFF;
        this->m_b0 = 0;
    }
    ids = (u16 *)((u8 *)this + 0xAA);
    for (i = 0; i < 3; i++) {
        *ids = *(u32 *)((u8 *)this + 0x84 + i * 4) >> 16;
        if (*ids >= 0x100) {
            *ids = 0xFFFF;
        }
        ids++;
    }
    this->m_b4 = get_current_floor();
}

const char *TOSwitchTimer__name = "TOSwitchTimer";


void clear_floor_switch_flag(u32 id, s16 floor);


void TOSwitchTimer::render() {
    if (TObjPlayer::check_demo_mode() == 1) {
        NJS_ARGB color;
        color.a = 0.3f;
        color.r = 0.6f;
        color.g = 0.3f;
        color.b = 0.0f;
        debug_draw_sphere(&position, &color, 10.0f);
    }
}

void TOSwitchTimer::run_task() {
    s32 temp_r3_2;
    u32 temp_r3;

    switch (*(s32 *)&this->m_90) {
    case 0:
        temp_r3 = is_current_floor_switch_set(this->m_a8);
        if ((s32) this->m_b0 != (s32) temp_r3) {
            this->m_b0 = temp_r3;
            if (temp_r3 == 1) {
                *(s32 *)&this->m_90 = 1;
                *(s32 *)&this->m_94 = 0;
                if ((u32) this->m_98 == 0U) {
                    this->m_b0 = 0U;
                }
            }
        }
        return;
    case 1:
        if ((s32) *(s32 *)&this->m_9c == 1) {
            if ((s32) *(s32 *)&this->m_94 < (s32) *(s32 *)&this->m_a4) {
                if ((*(s32 *)&this->m_94 % 30) == 0) {
                    play_sound_effect(0x53218, 0, 0, 0);
                }
            } else {
                play_persistent_sound(0x53218, this, NULL, 0, 0);
            }
        }
        temp_r3_2 = *(s32 *)&this->m_94;
        *(s32 *)&this->m_94 = (temp_r3_2 + 1);
        if (temp_r3_2 == (s32) *(s32 *)&this->m_a0) {
            send_switch_states();
            *(s32 *)&this->m_90 = 0;
        }
        break;
    }
}


void *TOSwitchTimer::create(void *arg0) {
    void *o = (void *)new TOSwitchTimer((saddr)tl_05, (saddr)arg0);
    return o;
}

void TOSwitchTimer__sub_80178584(void) {  }
void TOSwitchTimer__sub_80178588(void) {  }
TOSwitchTimer::~TOSwitchTimer() {
    if ((u32) this->m_98 == 0U) {
        clear_floor_switch_flag(this->m_a8, (s16) this->m_b4);
    }
}
TOSwitchTimer::TOSwitchTimer(saddr parent, saddr set_data) : TObjBase((TObject *)parent) {
    *(s32 *)((s8 *)this + 0) = (s32) ((saddr)TOSwitchTimer__name);
    ((TOSwitchTimer *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    this->sub_801782A0();
}
