#ifndef PSO_MISC_TOMONITORMACHINE01_H
#define PSO_MISC_TOMONITORMACHINE01_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOMonitorMachine01 : public TObjMapObject {
    TOMonitorMachine01(void *set_data);
    virtual ~TOMonitorMachine01();
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void reset_static_state();
    static void load_resources();
    u8 pad_C8[0x4];
    f32 slide;  // the screen halves' slide offset
    f32 screen_scale;  // the screen's scale
    f32 hold_timer;  // frames in the current hold phase
};

typedef char TOMonitorMachine01_size[sizeof(TOMonitorMachine01) == 0xD8 ? 1 : -1];

#endif
