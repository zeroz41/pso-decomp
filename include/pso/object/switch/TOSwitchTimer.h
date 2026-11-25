#ifndef PSO_OBJECT_SWITCH_TOSWITCHTIMER_H
#define PSO_OBJECT_SWITCH_TOSWITCHTIMER_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TOSwitchTimer : public TObjBase {
    TOSwitchTimer(saddr, saddr);
    virtual ~TOSwitchTimer();
    void init_from_set_data();
    void send_switch_states();
    s32 state;           // 0 waiting for the trigger switch, 1 counting down
    s32 timer;           // frames since the trigger
    u32 mode;            // rotation_x: 0 clears the trigger switch when it ends, 1 sets the target switches
    s32 tick_sound;      // rotation_y: 1 beeps while counting
    s32 duration;        // rotation_z: frames to count
    s32 steady_after;    // three quarters of duration: the beeps turn into one steady sound
    u16 trigger_switch;  // set_params[0]: the floor switch that starts it, 0xFFFF for none
    u16 target_switches[3];  // the high half of set_params[0..2]: switches set when it ends (mode 1)
    u8 trigger_state;    // the trigger switch's state last frame
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    u8 unk_B1[0x3];
    s32 floor;
};

LAYOUT_ASSERT(TOSwitchTimer_size, sizeof(TOSwitchTimer) == 0xB8);

extern "C" {
void TOSwitchTimer__sub_80178584(void);
void TOSwitchTimer__sub_80178588(void);
}

#endif
