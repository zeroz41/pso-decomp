#ifndef PSO_OBJECT_TOVS2WRECK03_H
#define PSO_OBJECT_TOVS2WRECK03_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck03 : public TOVS2 {
    TOVS2Wreck03(void *set_data);
    virtual ~TOVS2Wreck03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOVS2Wreck03_size, sizeof(TOVS2Wreck03) == 0xD0);


#endif
