#ifndef PSO_MISC_TODOORMACHINE02_H
#define PSO_MISC_TODOORMACHINE02_H

#include "types.h"
#include "pso/misc/TODoorBase.h"
#include "pso/system/NinjaTypes.h"

struct BmlResource;

// The single-switch machine-area door: its light is red and pulses while it
// is locked.
struct TODoorMachine02 : public TODoorBase {
    enum { PULSE_RISING = 0x10000 };  // door_flags: light_color.r is rising

    TODoorMachine02(TObject *parent, void *set_data);
    virtual ~TODoorMachine02();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    NJS_ARGB light_color;  // the locked light's tint

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the locked (red) light, [1] the bml's own
};

typedef char TODoorMachine02_size[sizeof(TODoorMachine02) == 0xE4 ? 1 : -1];

#endif
