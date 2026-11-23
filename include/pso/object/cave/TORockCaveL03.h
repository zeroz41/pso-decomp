#ifndef PSO_OBJECT_CAVE_TOROCKCAVEL03_H
#define PSO_OBJECT_CAVE_TOROCKCAVEL03_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveL03 : public TORockCave {
    TORockCaveL03(void *set_data);
    virtual ~TORockCaveL03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveL03_size, sizeof(TORockCaveL03) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
