#ifndef PSO_OBJECT_CAVE_TOROCKCAVESS02_H
#define PSO_OBJECT_CAVE_TOROCKCAVESS02_H

#include "types.h"
#include "pso/object/cave/TORockCaveSimple.h"

struct TORockCaveSS02 : public TORockCaveSimple {
    TORockCaveSS02(void *set_data);
    virtual ~TORockCaveSS02();
};

LAYOUT_ASSERT(TORockCaveSS02_size, sizeof(TORockCaveSS02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveSS02__create(void *set_data);

#endif
