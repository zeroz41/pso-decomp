#ifndef PSO_OBJECT_TOVS2WRECK02_H
#define PSO_OBJECT_TOVS2WRECK02_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck02 : public TOVS2 {
    virtual ~TOVS2Wreck02();
};

typedef char TOVS2Wreck02_size[sizeof(TOVS2Wreck02) == 0xD0 ? 1 : -1];

extern "C" {
void *TOVS2Wreck02__create(void *arg0);
void *TOVS2Wreck02__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck02Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TOVS2Wreck02.cpp ---
extern "C" {
void *TOVS2Wreck02__create(void *arg0);
void *TOVS2Wreck02__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck02Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
