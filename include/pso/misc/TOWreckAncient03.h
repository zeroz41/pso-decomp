#ifndef PSO_MISC_TOWRECKANCIENT03_H
#define PSO_MISC_TOWRECKANCIENT03_H

#include "types.h"
#include "pso/misc/TOWreckAncient.h"

struct TOWreckAncient03 : public TOWreckAncient {
    virtual ~TOWreckAncient03();
};

typedef char TOWreckAncient03_size[sizeof(TOWreckAncient03) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient03__create(void *arg0);
void *__dt__16TOWreckAncient03Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient03.cpp ---
extern "C" {
void *TOWreckAncient03__create(void *arg0);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient03__ct(u8 *wreck_ancient, s32 arg1);
}

#endif
