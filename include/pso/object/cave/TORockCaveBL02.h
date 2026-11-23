#ifndef PSO_OBJECT_CAVE_TOROCKCAVEBL02_H
#define PSO_OBJECT_CAVE_TOROCKCAVEBL02_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"

struct TORockCaveBL02 : public TORockCaveBrakable {
    TORockCaveBL02(void *set_data);
    virtual ~TORockCaveBL02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveBL02_size, sizeof(TORockCaveBL02) == 0xBC);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
