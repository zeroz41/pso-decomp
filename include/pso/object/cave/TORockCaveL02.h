#ifndef PSO_OBJECT_CAVE_TOROCKCAVEL02_H
#define PSO_OBJECT_CAVE_TOROCKCAVEL02_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveL02 : public TORockCave {
    TORockCaveL02(void *set_data);
    virtual ~TORockCaveL02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveL02_size, sizeof(TORockCaveL02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
