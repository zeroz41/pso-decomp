#ifndef PSO_MISC_TODOORMACHINE01_H
#define PSO_MISC_TODOORMACHINE01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"
#include "pso/system/NinjaTypes.h"

struct BmlResource;

// The machine-area door with four lights: set_params[1] of them are lit from
// the start, the floor switches from switch_id on light the rest; it unlocks
// when all four are lit. The unlit lights pulse red.
struct TODoorMachine01 : public TODoorBase {
    // door_flags bits above DOOR_FLAG_UNLOCKED.
    enum {
        LIGHT_LIT_SHIFT = 16,      // bits 16-19: light i is lit
        LIGHT_LIT_MASK = 0xF0000,
        PULSE_RISING = 0x100000    // light_color.r is rising
    };

    TODoorMachine01(TObject *parent, void *set_data);
    virtual ~TODoorMachine01();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    virtual void update_door_switch_state();
    void draw_switch_light(NJS_OBJECT *node, s32 lit);
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    s32 lit_count;     // lights lit
    s32 switch_count;  // lights that wait for a switch: 4 - set_params[1]
    NJS_ARGB light_color;  // the unlit lights' tint

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] the unlit (red) lights, [1] the bml's own
};

typedef char TODoorMachine01_size[sizeof(TODoorMachine01) == 0xEC ? 1 : -1];

#endif
