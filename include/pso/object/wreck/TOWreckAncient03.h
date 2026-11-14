#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT03_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT03_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient03 : public TOWreckAncient {
    TOWreckAncient03(void *set_data);
    virtual ~TOWreckAncient03();
};

typedef char TOWreckAncient03_size[sizeof(TOWreckAncient03) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient03__create(void *set_data);
}

#endif
