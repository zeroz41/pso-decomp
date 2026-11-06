#ifndef PSO_OBJECT_CAVE_TOROCKCAVESL02_H
#define PSO_OBJECT_CAVE_TOROCKCAVESL02_H

#include "types.h"
#include "pso/object/cave/TORockCaveSimple.h"

struct TORockCaveSL02 : public TORockCaveSimple {
    TORockCaveSL02(void *set_data);
    virtual ~TORockCaveSL02();
};

typedef char TORockCaveSL02_size[sizeof(TORockCaveSL02) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveSL02__create(void *set_data);

#endif
