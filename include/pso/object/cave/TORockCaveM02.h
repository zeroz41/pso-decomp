#ifndef PSO_OBJECT_CAVE_TOROCKCAVEM02_H
#define PSO_OBJECT_CAVE_TOROCKCAVEM02_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveM02 : public TORockCave {
    TORockCaveM02(void *set_data);
    virtual ~TORockCaveM02();
};

typedef char TORockCaveM02_size[sizeof(TORockCaveM02) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveM02__create(void *set_data);

#endif
