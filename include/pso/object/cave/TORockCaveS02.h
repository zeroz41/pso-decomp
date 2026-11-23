#ifndef PSO_OBJECT_CAVE_TOROCKCAVES02_H
#define PSO_OBJECT_CAVE_TOROCKCAVES02_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveS02 : public TORockCave {
    TORockCaveS02(void *set_data);
    virtual ~TORockCaveS02();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TORockCaveS02_size, sizeof(TORockCaveS02) == 0xB4);

// The object factory entry (ObjectFactoryTables.cpp).

#endif
