#ifndef PSO_OBJECT_CAVE_TOROCKCAVEL01_H
#define PSO_OBJECT_CAVE_TOROCKCAVEL01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveL01 : public TORockCave {
    TORockCaveL01(void *set_data);
    virtual ~TORockCaveL01();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveL01_size, sizeof(TORockCaveL01) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
