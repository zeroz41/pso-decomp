#ifndef PSO_OBJECT_TOVS2WRECK04_H
#define PSO_OBJECT_TOVS2WRECK04_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck04 : public TOVS2 {
    TOVS2Wreck04(void *set_data);
    virtual ~TOVS2Wreck04();
};

LAYOUT_ASSERT(TOVS2Wreck04_size, sizeof(TOVS2Wreck04) == 0xD0);

extern "C" void *TOVS2Wreck04__create(void *set_data);

#endif
