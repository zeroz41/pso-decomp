#ifndef PSO_OBJECT_CAVE_TOROCKCAVEM03_H
#define PSO_OBJECT_CAVE_TOROCKCAVEM03_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveM03 : public TORockCave {
    TORockCaveM03(void *set_data);
    virtual ~TORockCaveM03();
};

typedef char TORockCaveM03_size[sizeof(TORockCaveM03) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveM03__create(void *set_data);

#endif
