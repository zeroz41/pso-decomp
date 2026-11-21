#ifndef PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE02_H
#define PSO_OBJECT_TRAP_TOEXPLOSIVEMACHINE02_H

#include "pso/object/trap/TOExplosiveMachine.h"

struct TOExplosiveMachine02 : public TOExplosiveMachine {
    TOExplosiveMachine02(void *set_data);
    virtual ~TOExplosiveMachine02();
};

LAYOUT_ASSERT(TOExplosiveMachine02_size, sizeof(TOExplosiveMachine02) == 0xAC);

extern "C" void *TOExplosiveMachine02__create(void *set_data);

#endif
