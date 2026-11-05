#ifndef PSO_MISC_TOWRECKANCIENT04_H
#define PSO_MISC_TOWRECKANCIENT04_H

#include "types.h"
#include "pso/misc/TOWreckAncient.h"

struct TOWreckAncient04 : public TOWreckAncient {
    virtual ~TOWreckAncient04();
};

typedef char TOWreckAncient04_size[sizeof(TOWreckAncient04) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient04__create(void *arg0);
void *__dt__16TOWreckAncient04Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient04.cpp ---
extern "C" {
void *TOWreckAncient04__create(void *arg0);
void *__dt__16TOWreckAncient04Fv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient04__ct(u8 *wreck_ancient, s32 arg1);
}

#endif
