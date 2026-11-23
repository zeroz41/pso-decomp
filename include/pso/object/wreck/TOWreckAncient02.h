#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT02_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT02_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient02 : public TOWreckAncient {
    TOWreckAncient02(void *set_data);
    virtual ~TOWreckAncient02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncient02_size, sizeof(TOWreckAncient02) == 0xB4);

#endif
