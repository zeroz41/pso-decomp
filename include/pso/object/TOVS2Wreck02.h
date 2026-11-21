#ifndef PSO_OBJECT_TOVS2WRECK02_H
#define PSO_OBJECT_TOVS2WRECK02_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck02 : public TOVS2 {
    TOVS2Wreck02(void *set_data);
    virtual ~TOVS2Wreck02();
};

typedef char TOVS2Wreck02_size[sizeof(TOVS2Wreck02) == 0xD0 ? 1 : -1];

extern "C" void *TOVS2Wreck02__create(void *set_data);

#endif
