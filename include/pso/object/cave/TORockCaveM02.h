#ifndef PSO_OBJECT_CAVE_TOROCKCAVEM02_H
#define PSO_OBJECT_CAVE_TOROCKCAVEM02_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveM02 : public TORockCave {
    TORockCaveM02(void *set_data);
    virtual ~TORockCaveM02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveM02_size, sizeof(TORockCaveM02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
