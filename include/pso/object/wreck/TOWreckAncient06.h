#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT06_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT06_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient06 : public TOWreckAncient {
    TOWreckAncient06(void *set_data);
    virtual ~TOWreckAncient06();
};

typedef char TOWreckAncient06_size[sizeof(TOWreckAncient06) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient06__create(void *set_data);
}

#endif
