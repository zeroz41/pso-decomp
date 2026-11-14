#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT01_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT01_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient01 : public TOWreckAncient {
    TOWreckAncient01(void *set_data);
    virtual ~TOWreckAncient01();
};

typedef char TOWreckAncient01_size[sizeof(TOWreckAncient01) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient01__create(void *set_data);
}

#endif
