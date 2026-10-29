#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TOSwitchTimer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3188 = "TOSwitchTimer";
}



struct RecoveredGlobal_8017858C___vt__13TOSwitchTimer { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_8017858C___vt__13TOSwitchTimer_size[sizeof(RecoveredGlobal_8017858C___vt__13TOSwitchTimer) == 0x38 ? 1 : -1];

struct RecoveredGlobal_80178604___vt__13TOSwitchTimer {
    s32 value;
    u8 remaining[0x34];
};

void clear_floor_switch_flag(u32 id, s16 floor);
extern "C" {
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_8017858C___vt__13TOSwitchTimer __vt__13TOSwitchTimer;
s32 __ct__8TObjBaseFP7TObject(void *);
extern const char *lbl_805D3188;
s32 play_sound_effect(s32, s32, s32, s32);
u8 is_current_floor_switch_set(u16);
void *__nw__7TObjectFUl(int);

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
                play_persistent_sound(0x53218, (s32)this, 0, 0, 0);
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

extern void *tl_05;

void *TOSwitchTimer::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB8);
    if (o != NULL) {
        o = TOSwitchTimer__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOSwitchTimer__sub_80178584(void) {  }
void TOSwitchTimer__sub_80178588(void) {  }
u8 *__dt__13TOSwitchTimerFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TOSwitchTimer.value;
        if ((u32) ((TOSwitchTimer *)arg0)->m_98 == 0U) {
            clear_floor_switch_flag(((TOSwitchTimer *)arg0)->m_a8, (s16) ((TOSwitchTimer *)arg0)->m_b4);
        }
        __dt__8TObjBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80178604___vt__13TOSwitchTimer_size[sizeof(RecoveredGlobal_80178604___vt__13TOSwitchTimer) == 0x38 ? 1 : -1];
u8 *TOSwitchTimer__ct(u8 *switch_timer, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject(switch_timer);
    *(s32 **)((s8 *)switch_timer + 0x18) = &(*(RecoveredGlobal_80178604___vt__13TOSwitchTimer *)&__vt__13TOSwitchTimer).value;
    *(s32 *)((s8 *)switch_timer + 0) = (s32) ((s32)lbl_805D3188);
    ((TOSwitchTimer *)(switch_timer))->apply_object_set_data((void *)arg2);
    ((TOSwitchTimer *)switch_timer)->sub_801782A0();
    return switch_timer;
}
}
