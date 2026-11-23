#ifndef PSO_OBJECT_CAVE_TOROCKCAVEBL03_H
#define PSO_OBJECT_CAVE_TOROCKCAVEBL03_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"

struct TORockCaveBL03 : public TORockCaveBrakable {
    TORockCaveBL03(void *set_data);
    virtual ~TORockCaveBL03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveBL03_size, sizeof(TORockCaveBL03) == 0xBC);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
