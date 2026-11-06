#ifndef PSO_OBJECT_CAVE_TOROCKCAVES01_H
#define PSO_OBJECT_CAVE_TOROCKCAVES01_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveS01 : public TORockCave {
    TORockCaveS01(void *set_data);
    virtual ~TORockCaveS01();
};

typedef char TORockCaveS01_size[sizeof(TORockCaveS01) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveS01__create(void *set_data);

#endif
