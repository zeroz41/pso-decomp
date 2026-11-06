#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE05_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENTBRAKABLE05_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncientBrakable.h"

struct TOWreckAncientBrakable05 : public TOWreckAncientBrakable {
    virtual ~TOWreckAncientBrakable05();
};

typedef char TOWreckAncientBrakable05_size[sizeof(TOWreckAncientBrakable05) == 0xBC ? 1 : -1];

extern "C" {
u8 *TOWreckAncientBrakable05__ct(TOWreckAncientBrakable05 *arg0, s32 arg1);
}

#endif
