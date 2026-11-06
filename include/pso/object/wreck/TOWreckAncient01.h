#ifndef PSO_OBJECT_WRECK_TOWRECKANCIENT01_H
#define PSO_OBJECT_WRECK_TOWRECKANCIENT01_H

#include "types.h"
#include "pso/object/wreck/TOWreckAncient.h"

struct TOWreckAncient01 : public TOWreckAncient {
    virtual ~TOWreckAncient01();
};

typedef char TOWreckAncient01_size[sizeof(TOWreckAncient01) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient01__create(void *arg0);
void *__dt__16TOWreckAncient01Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient01.cpp ---
extern "C" {
void *TOWreckAncient01__create(void *arg0);
void *__dt__16TOWreckAncient01Fv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient01__ct(u8 *wreck_ancient, s32 arg1);
}

#endif
