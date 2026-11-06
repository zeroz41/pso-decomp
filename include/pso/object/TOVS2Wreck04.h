#ifndef PSO_OBJECT_TOVS2WRECK04_H
#define PSO_OBJECT_TOVS2WRECK04_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck04 : public TOVS2 {
    virtual ~TOVS2Wreck04();
};

typedef char TOVS2Wreck04_size[sizeof(TOVS2Wreck04) == 0xD0 ? 1 : -1];

extern "C" {
void *TOVS2Wreck04__create(void *arg0);
void *TOVS2Wreck04__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck04Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOVS2Wreck04.cpp ---
extern "C" {
void *TOVS2Wreck04__create(void *arg0);
void *TOVS2Wreck04__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck04Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
