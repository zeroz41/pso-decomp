#ifndef PSO_OBJECT_CAVE_TOROCKCAVEL02_H
#define PSO_OBJECT_CAVE_TOROCKCAVEL02_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveL02 : public TORockCave {
    TORockCaveL02(void *set_data);
    virtual ~TORockCaveL02();
};

LAYOUT_ASSERT(TORockCaveL02_size, sizeof(TORockCaveL02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveL02__create(void *set_data);

#endif
