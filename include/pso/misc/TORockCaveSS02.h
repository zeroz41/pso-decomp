#ifndef PSO_MISC_TOROCKCAVESS02_H
#define PSO_MISC_TOROCKCAVESS02_H

#include "types.h"
#include "pso/misc/TORockCaveSimple.h"

struct TORockCaveSS02 : public TORockCaveSimple {
    TORockCaveSS02(void *set_data);
    virtual ~TORockCaveSS02();
};

typedef char TORockCaveSS02_size[sizeof(TORockCaveSS02) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveSS02__create(void *set_data);

#endif
