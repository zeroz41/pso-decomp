#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncientBrakable : public TOWreckAncient {
    TOWreckAncientBrakable(s32 model_index);
    virtual ~TOWreckAncientBrakable();
    virtual void run_task();
    void spawn_debris();
    u32 state;      // inferred: 0 standing, 1 broken (run_task's switch)
    s32 switch_id;  // inferred: the floor switch that breaks it, -1 for none (is_current_floor_switch_set)
};

typedef char TOWreckAncientBrakable_size[sizeof(TOWreckAncientBrakable) == 0xBC ? 1 : -1];
#endif
