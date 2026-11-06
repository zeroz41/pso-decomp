#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncientBrakable : public TOWreckAncient {
    virtual ~TOWreckAncientBrakable();
    virtual void run_task();
    u32 m_b4;
    u32 m_b8;
    void spawn_debris();
};

typedef char TOWreckAncientBrakable_size[sizeof(TOWreckAncientBrakable) == 0xBC ? 1 : -1];
#endif
