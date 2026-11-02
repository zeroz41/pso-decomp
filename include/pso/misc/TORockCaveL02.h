#ifndef PSO_MISC_TOROCKCAVEL02_H
#define PSO_MISC_TOROCKCAVEL02_H

#include "types.h"
#include "pso/misc/TORockCave.h"

struct TORockCaveL02 : public TORockCave {
    TORockCaveL02(void *set_data);
    virtual ~TORockCaveL02();
};

typedef char TORockCaveL02_size[sizeof(TORockCaveL02) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveL02__create(void *set_data);

#endif
