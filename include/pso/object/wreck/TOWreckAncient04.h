#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT04_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT04_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient04 : public TOWreckAncient {
    TOWreckAncient04(void *set_data);
    virtual ~TOWreckAncient04();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient04_size, sizeof(TOWreckAncient04) == 0xB4);

#endif
