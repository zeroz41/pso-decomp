#ifndef PSO_OBJECT_TOVS2WRECK02_H
#define PSO_OBJECT_TOVS2WRECK02_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck02 : public TOVS2 {
    TOVS2Wreck02(void *set_data);
    virtual ~TOVS2Wreck02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOVS2Wreck02_size, sizeof(TOVS2Wreck02) == 0xD0);


#endif
