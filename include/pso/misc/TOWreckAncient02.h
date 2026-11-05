#ifndef PSO_MISC_TOWRECKANCIENT02_H
#define PSO_MISC_TOWRECKANCIENT02_H

#include "types.h"
#include "pso/misc/TOWreckAncient.h"

struct TOWreckAncient02 : public TOWreckAncient {
    virtual ~TOWreckAncient02();
};

typedef char TOWreckAncient02_size[sizeof(TOWreckAncient02) == 0xB4 ? 1 : -1];

extern "C" {
void *TOWreckAncient02__create(void *arg0);
void *__dt__16TOWreckAncient02Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOWreckAncient02.cpp ---
extern "C" {
void *TOWreckAncient02__create(void *arg0);
}
// --- end of C functions

extern "C" {
u8 *TOWreckAncient02__ct(u8 *wreck_ancient, s32 arg1);
}

#endif
