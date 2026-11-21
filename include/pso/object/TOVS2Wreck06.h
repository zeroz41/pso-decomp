#ifndef PSO_OBJECT_TOVS2WRECK06_H
#define PSO_OBJECT_TOVS2WRECK06_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck06 : public TOVS2 {
    TOVS2Wreck06(void *set_data);
    virtual ~TOVS2Wreck06();
};

typedef char TOVS2Wreck06_size[sizeof(TOVS2Wreck06) == 0xD0 ? 1 : -1];

extern "C" void *TOVS2Wreck06__create(void *set_data);

#endif
