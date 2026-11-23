#ifndef PSO_OBJECT_TOVS2WRECK04_H
#define PSO_OBJECT_TOVS2WRECK04_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck04 : public TOVS2 {
    TOVS2Wreck04(void *set_data);
    virtual ~TOVS2Wreck04();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TOVS2Wreck04_size, sizeof(TOVS2Wreck04) == 0xD0);


#endif
