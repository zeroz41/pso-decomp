#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT07_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT07_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient07 : public TOWreckAncient {
    virtual ~TOWreckAncient07();
};

typedef char TOWreckAncient07_size[sizeof(TOWreckAncient07) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient07__create(void *arg0);
void *__dt__16TOWreckAncient07Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient07.cpp ---
extern "C" {
void *TOWreckAncient07__create(void *arg0);
void *__dt__16TOWreckAncient07Fv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient07__ct(u8 *arg0, s32 arg1);
}

#endif
