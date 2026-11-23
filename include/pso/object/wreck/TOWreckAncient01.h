#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT01_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT01_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient01 : public TOWreckAncient {
    TOWreckAncient01(void *set_data);
    virtual ~TOWreckAncient01();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient01_size, sizeof(TOWreckAncient01) == 0xB4);

#endif
