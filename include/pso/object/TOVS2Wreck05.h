#ifndef PSO_OBJECT_TOVS2WRECK05_H
#define PSO_OBJECT_TOVS2WRECK05_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck05 : public TOVS2 {
    virtual ~TOVS2Wreck05();
};

typedef char TOVS2Wreck05_size[sizeof(TOVS2Wreck05) == 0xD0 ? 1 : -1];

extern "C" {
void *TOVS2Wreck05__create(void *arg0);
void *TOVS2Wreck05__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck05Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOVS2Wreck05.cpp ---
extern "C" {
void *TOVS2Wreck05__create(void *arg0);
void *TOVS2Wreck05__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck05Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
