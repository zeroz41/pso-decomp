#ifndef PSO_MISC_TOWRECKANCIENT06_H
#define PSO_MISC_TOWRECKANCIENT06_H

#include "types.h"
#include "pso/misc/TOWreckAncient.h"

struct TOWreckAncient06 : public TOWreckAncient {
    virtual ~TOWreckAncient06();
};

typedef char TOWreckAncient06_size[sizeof(TOWreckAncient06) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient06__create(void *arg0);
void *__dt__16TOWreckAncient06Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient06.cpp ---
extern "C" {
void *TOWreckAncient06__create(void *arg0);
void *__dt__16TOWreckAncient06Fv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient06__ct(u8 *arg0, s32 arg1);
}

#endif
