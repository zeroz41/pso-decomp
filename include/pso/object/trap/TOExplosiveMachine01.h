#ifndef PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE01_H
#define PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE01_H

#include "pso/object/trap/TOExplosiveMachine.h"

struct TOExplosiveMachine01 : public TOExplosiveMachine {
    TOExplosiveMachine01(ObjectSetData *set_data);
    virtual ~TOExplosiveMachine01();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOExplosiveMachine01_size, sizeof(TOExplosiveMachine01) == 0xAC);


#endif
