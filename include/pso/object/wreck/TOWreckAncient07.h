#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT07_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT07_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient07 : public TOWreckAncient {
    TOWreckAncient07(void *set_data);
    virtual ~TOWreckAncient07();
};

typedef char TOWreckAncient07_size[sizeof(TOWreckAncient07) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient07__create(void *set_data);
}

#endif
