#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT02_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT02_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient02 : public TOWreckAncient {
    TOWreckAncient02(void *set_data);
    virtual ~TOWreckAncient02();
};

typedef char TOWreckAncient02_size[sizeof(TOWreckAncient02) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient02__create(void *set_data);
}

#endif
