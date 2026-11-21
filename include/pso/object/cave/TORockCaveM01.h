#ifndef PSO_OBJECT_CAVE_TOROCKCAVEM01_H
#define PSO_OBJECT_CAVE_TOROCKCAVEM01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveM01 : public TORockCave {
    TORockCaveM01(void *set_data);
    virtual ~TORockCaveM01();
};

LAYOUT_ASSERT(TORockCaveM01_size, sizeof(TORockCaveM01) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveM01__create(void *set_data);

#endif
