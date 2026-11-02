#ifndef PSO_MISC_TOROCKCAVESM02_H
#define PSO_MISC_TOROCKCAVESM02_H

#include "types.h"
#include "pso/misc/TORockCaveSimple.h"

struct TORockCaveSM02 : public TORockCaveSimple {
    TORockCaveSM02(void *set_data);
    virtual ~TORockCaveSM02();
};

typedef char TORockCaveSM02_size[sizeof(TORockCaveSM02) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveSM02__create(void *set_data);

#endif
