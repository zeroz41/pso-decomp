#ifndef PSO_MISC_TOMONITORMACHINE01_H
#define PSO_MISC_TOMONITORMACHINE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOMonitorMachine01 : public TUnk_804AFBF8 {
    // The object factories' create() passes its own r3, the set entry, on.
    TOMonitorMachine01(void *set_data);
    virtual ~TOMonitorMachine01();
    virtual void run_task();
    virtual void render();
    void *create();
    static void reset_static_state();
    static void load_resources();
    u8 unk_C8[0x4];
    f32 slide;  // the screen halves' slide offset
    f32 screen_scale;  // the screen's scale
    f32 hold_timer;  // frames in the current hold phase
};

typedef char TOMonitorMachine01_size[sizeof(TOMonitorMachine01) == 0xD8 ? 1 : -1];

#endif
