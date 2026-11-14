#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT04_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT04_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient04 : public TOWreckAncient {
    TOWreckAncient04(void *set_data);
    virtual ~TOWreckAncient04();
};

typedef char TOWreckAncient04_size[sizeof(TOWreckAncient04) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient04__create(void *set_data);
}

#endif
