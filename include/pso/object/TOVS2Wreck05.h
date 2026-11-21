#ifndef PSO_OBJECT_TOVS2WRECK05_H
#define PSO_OBJECT_TOVS2WRECK05_H

#include "types.h"
#include "pso/object/TOVS2.h"

struct TOVS2Wreck05 : public TOVS2 {
    TOVS2Wreck05(void *set_data);
    virtual ~TOVS2Wreck05();
};

typedef char TOVS2Wreck05_size[sizeof(TOVS2Wreck05) == 0xD0 ? 1 : -1];

extern "C" void *TOVS2Wreck05__create(void *set_data);

#endif
