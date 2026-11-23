#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT03_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT03_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient03 : public TOWreckAncient {
    TOWreckAncient03(void *set_data);
    virtual ~TOWreckAncient03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient03_size, sizeof(TOWreckAncient03) == 0xB4);

#endif
