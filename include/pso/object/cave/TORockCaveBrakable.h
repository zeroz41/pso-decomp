#ifndef PSO_OBJECT_CAVE_TOROCKCAVEBRAKABLE_H
#define PSO_OBJECT_CAVE_TOROCKCAVEBRAKABLE_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveBrakable : public TORockCave {
    TORockCaveBrakable();
    virtual ~TORockCaveBrakable();
    virtual void run_task();
    virtual void throw_debris();
    virtual void spawn_break_effect();
    virtual void play_break_sound();
    virtual void run_demo_task();
    u32 state;
    s32 switch_id;  // floor switch that breaks it (0-0xFF), -1 for none
};

LAYOUT_ASSERT(TORockCaveBrakable_size, sizeof(TORockCaveBrakable) == 0xBC);
#endif
