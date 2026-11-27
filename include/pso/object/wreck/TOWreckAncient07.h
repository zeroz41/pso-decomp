#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT07_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT07_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient07 : public TOWreckAncient {
    TOWreckAncient07(ObjectSetData *set_data);
    virtual ~TOWreckAncient07();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TOWreckAncient07_size, sizeof(TOWreckAncient07) == 0xB4);

#endif
