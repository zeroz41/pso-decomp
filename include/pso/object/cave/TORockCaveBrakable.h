#ifndef PSO_OBJECT_CAVE_TOROCKCAVEBRAKABLE_H
#define PSO_OBJECT_CAVE_TOROCKCAVEBRAKABLE_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveBrakable : public TORockCave {
    TORockCaveBrakable();
    virtual ~TORockCaveBrakable();
    virtual void run_task();
    virtual void vfunc_16();
    virtual void spawn_break_effect();
    virtual void vfunc_18();
    virtual void vfunc_19();
    u32 m_b4;
    s32 m_b8;  // floor switch that breaks it (0-0xFF), -1 for none
};

typedef char TORockCaveBrakable_size[sizeof(TORockCaveBrakable) == 0xBC ? 1 : -1];
#endif
