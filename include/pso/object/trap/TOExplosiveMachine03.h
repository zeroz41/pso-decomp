#ifndef PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE03_H
#define PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE03_H

#include "pso/object/trap/TOExplosiveMachine.h"

struct TOExplosiveMachine03 : public TOExplosiveMachine {
    TOExplosiveMachine03(void *set_data);
    virtual ~TOExplosiveMachine03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOExplosiveMachine03_size, sizeof(TOExplosiveMachine03) == 0xAC);


#endif
