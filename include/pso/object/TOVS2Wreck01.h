#ifndef PSO_OBJECT_TOVS2WRECK01_H
#define PSO_OBJECT_TOVS2WRECK01_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck01 : public TOVS2 {
    virtual ~TOVS2Wreck01();
};

typedef char TOVS2Wreck01_size[sizeof(TOVS2Wreck01) == 0xD0 ? 1 : -1];

extern "C" {
void *TOVS2Wreck01__create(void *arg0);
void *TOVS2Wreck01__ct(void *arg0, void *arg1);
void *__dt__12TOVS2Wreck01Fv(void *arg0, s16 arg1);
}

#endif
