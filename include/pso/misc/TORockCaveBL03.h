#ifndef PSO_MISC_TOROCKCAVEBL03_H
#define PSO_MISC_TOROCKCAVEBL03_H

#include "types.h"
#include "pso/misc/TORockCaveBrakable.h"

struct TORockCaveBL03 : public TORockCaveBrakable {
    TORockCaveBL03(void *set_data);
    virtual ~TORockCaveBL03();
};

typedef char TORockCaveBL03_size[sizeof(TORockCaveBL03) == 0xBC ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveBL03__create(void *set_data);

#endif
