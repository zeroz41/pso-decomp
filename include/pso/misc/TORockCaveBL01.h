#ifndef PSO_MISC_TOROCKCAVEBL01_H
#define PSO_MISC_TOROCKCAVEBL01_H

#include "types.h"
#include "pso/misc/TORockCaveBrakable.h"

struct TORockCaveBL01 : public TORockCaveBrakable {
    TORockCaveBL01(void *set_data);
    virtual ~TORockCaveBL01();
};

typedef char TORockCaveBL01_size[sizeof(TORockCaveBL01) == 0xBC ? 1 : -1];

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveBL01__create(void *set_data);

#endif
