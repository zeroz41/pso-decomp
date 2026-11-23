#ifndef PSO_OBJECT_CAVE_TOROCKCAVEM01_H
#define PSO_OBJECT_CAVE_TOROCKCAVEM01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveM01 : public TORockCave {
    TORockCaveM01(void *set_data);
    virtual ~TORockCaveM01();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveM01_size, sizeof(TORockCaveM01) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
