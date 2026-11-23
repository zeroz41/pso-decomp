#ifndef PSO_OBJECT_TOVS2WRECK01_H
#define PSO_OBJECT_TOVS2WRECK01_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck01 : public TOVS2 {
    TOVS2Wreck01(void *set_data);
    virtual ~TOVS2Wreck01();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOVS2Wreck01_size, sizeof(TOVS2Wreck01) == 0xD0);


#endif
