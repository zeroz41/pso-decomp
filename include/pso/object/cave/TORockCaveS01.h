#ifndef PSO_OBJECT_CAVE_TOROCKCAVES01_H
#define PSO_OBJECT_CAVE_TOROCKCAVES01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveS01 : public TORockCave {
    TORockCaveS01(void *set_data);
    virtual ~TORockCaveS01();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveS01_size, sizeof(TORockCaveS01) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
