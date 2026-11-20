#ifndef PSO_OBJECT_CAVE_TOROCKCAVEL01_H
#define PSO_OBJECT_CAVE_TOROCKCAVEL01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveL01 : public TORockCave {
    TORockCaveL01(void *set_data);
    virtual ~TORockCaveL01();
};

LAYOUT_ASSERT(TORockCaveL01_size, sizeof(TORockCaveL01) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveL01__create(void *set_data);

#endif
