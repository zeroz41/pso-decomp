#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT06_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT06_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient06 : public TOWreckAncient {
    TOWreckAncient06(void *set_data);
    virtual ~TOWreckAncient06();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient06_size, sizeof(TOWreckAncient06) == 0xB4);

#endif
