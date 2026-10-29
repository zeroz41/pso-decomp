#ifndef PSO_MISC_TODOORCAVE02_H
#define PSO_MISC_TODOORCAVE02_H

#include "types.h"
#include "pso/misc/TODoorBase.h"
#include "pso/system/NinjaTypes.h"

struct BmlResource;

// The cave door with two lights on one floor switch; the lights pulse red
// while it is closed.
struct TODoorCave02 : public TODoorBase {
    enum { PULSE_RISING = 0x100000 };  // door_flags: light_color.r is rising

    TODoorCave02(TObject *parent, void *set_data);
    virtual ~TODoorCave02();
    virtual void update_demo();
    virtual void update_open();
    virtual void update_closed();
    void draw_light(NJS_OBJECT *node);
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    NJS_ARGB light_color;

    static BmlResource *bml_resource;
    static s32 *texture_lists;  // [0] locked (red), [1] the bml's own
};

typedef char TODoorCave02_size[sizeof(TODoorCave02) == 0xE4 ? 1 : -1];
#endif
