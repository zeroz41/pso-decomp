#ifndef PSO_MISC_TOBARRIERENERGY01_H
#define PSO_MISC_TOBARRIERENERGY01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

struct TOBarrierEnergy01 : public TODoorBase {
    virtual ~TOBarrierEnergy01();
    virtual void update_demo();
    virtual void update_closing();
    virtual void update_open();
    virtual void update_opening();
    virtual void update_closed();
    void*init();
    void play_ambient_loop_sound();
    virtual void render();
    static void *create(void *arg0);
    static void free_resources();
    static void load_resources();
};

typedef char TOBarrierEnergy01_size[sizeof(TOBarrierEnergy01) == 0xD4 ? 1 : -1];
#endif
