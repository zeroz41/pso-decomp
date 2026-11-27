#ifndef PSO_OBJECT_CAVE_TOROCKCAVESM02_H
#define PSO_OBJECT_CAVE_TOROCKCAVESM02_H

#include "types.h"
#include "pso/object/cave/TORockCaveSimple.h"

struct TORockCaveSM02 : public TORockCaveSimple {
    TORockCaveSM02(ObjectSetData *set_data);
    virtual ~TORockCaveSM02();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TORockCaveSM02_size, sizeof(TORockCaveSM02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
