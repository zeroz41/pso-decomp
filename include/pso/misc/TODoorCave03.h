#ifndef PSO_MISC_TODOORCAVE03_H
#define PSO_MISC_TODOORCAVE03_H

#include "types.h"
#include "pso/misc/TODoorBase.h"
#include "pso/system/NinjaTypes.h"

struct BmlResource;

// The cave door that slides up 60 units out of the floor; its light shows
// which way it is locked and pulses red while it is shut.
struct TODoorCave03 : public TODoorBase {
    enum { PULSE_RISING = 0x10000 };  // door_flags: light_color.r is rising

    TODoorCave03(TObject *parent, void *set_data);
    virtual ~TODoorCave03();
    virtual void update_demo();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    virtual void render();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    NJS_ARGB light_color;

    static BmlResource *bml_resource;
};

typedef char TODoorCave03_size[sizeof(TODoorCave03) == 0xE4 ? 1 : -1];
#endif
