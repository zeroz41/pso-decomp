#ifndef PSO_MISC_TOWRECKANCIENT05_H
#define PSO_MISC_TOWRECKANCIENT05_H

#include "types.h"
#include "pso/misc/TOWreckAncient.h"

struct TOWreckAncient05 : public TOWreckAncient {
    virtual ~TOWreckAncient05();
};

typedef char TOWreckAncient05_size[sizeof(TOWreckAncient05) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient05__create(void *arg0);
void *__dt__16TOWreckAncient05Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient05.cpp ---
extern "C" {
void *TOWreckAncient05__create(void *arg0);
void *__dt__16TOWreckAncient05Fv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient05__ct(u8 *arg0, s32 arg1);
}

#endif
