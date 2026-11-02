#ifndef PSO_MISC_TOROCKCAVES03_H
#define PSO_MISC_TOROCKCAVES03_H

#include "types.h"
#include "pso/misc/TORockCave.h"

struct TORockCaveS03 : public TORockCave {
    TORockCaveS03(void *set_data);
    virtual ~TORockCaveS03();
};

typedef char TORockCaveS03_size[sizeof(TORockCaveS03) == 0xB4 ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveS03__create(void *set_data);

#endif
