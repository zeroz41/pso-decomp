#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT03_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT03_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient03 : public TOWreckAncient {
    TOWreckAncient03(ObjectSetData *set_data);
    virtual ~TOWreckAncient03();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOWreckAncient03_size, sizeof(TOWreckAncient03) == 0xB4);

#endif
