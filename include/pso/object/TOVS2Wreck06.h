#ifndef PSO_OBJECT_TOVS2WRECK06_H
#define PSO_OBJECT_TOVS2WRECK06_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck06 : public TOVS2 {
    virtual ~TOVS2Wreck06();
};

typedef char TOVS2Wreck06_size[sizeof(TOVS2Wreck06) == 0xD0 ? 1 : -1];

extern "C" {
void *TOVS2Wreck06__create(void *arg0);
void *TOVS2Wreck06__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck06Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOVS2Wreck06.cpp ---
extern "C" {
void *TOVS2Wreck06__create(void *arg0);
void *TOVS2Wreck06__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck06Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
