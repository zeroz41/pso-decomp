#ifndef PSO_OBJECT_CAVE_TOROCKCAVES03_H
#define PSO_OBJECT_CAVE_TOROCKCAVES03_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveS03 : public TORockCave {
    TORockCaveS03(void *set_data);
    virtual ~TORockCaveS03();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveS03_size, sizeof(TORockCaveS03) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
