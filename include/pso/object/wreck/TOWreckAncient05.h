#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT05_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT05_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient05 : public TOWreckAncient {
    TOWreckAncient05(void *set_data);
    virtual ~TOWreckAncient05();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient05_size, sizeof(TOWreckAncient05) == 0xB4);

#endif
