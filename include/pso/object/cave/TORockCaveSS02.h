#ifndef PSO_OBJECT_CAVE_TOROCKCAVESS02_H
#define PSO_OBJECT_CAVE_TOROCKCAVESS02_H

#include "types.h"
#include "pso/object/cave/TORockCaveSimple.h"

struct TORockCaveSS02 : public TORockCaveSimple {
    TORockCaveSS02(void *set_data);
    virtual ~TORockCaveSS02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveSS02_size, sizeof(TORockCaveSS02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
