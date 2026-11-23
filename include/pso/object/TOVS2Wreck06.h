#ifndef PSO_OBJECT_TOVS2WRECK06_H
#define PSO_OBJECT_TOVS2WRECK06_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck06 : public TOVS2 {
    TOVS2Wreck06(void *set_data);
    virtual ~TOVS2Wreck06();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOVS2Wreck06_size, sizeof(TOVS2Wreck06) == 0xD0);


#endif
