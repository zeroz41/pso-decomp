#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE05_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE05_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncientBrakable.h"

struct TOWreckAncientBrakable05 : public TOWreckAncientBrakable {
    TOWreckAncientBrakable05(void *set_data);
    virtual ~TOWreckAncientBrakable05();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOWreckAncientBrakable05_size, sizeof(TOWreckAncientBrakable05) == 0xBC);

#endif
