#ifndef PSO_OBJECT_CAVE_TOROCKCAVEBL01_H
#define PSO_OBJECT_CAVE_TOROCKCAVEBL01_H

#include "types.h"
#include "pso/object/cave/TORockCaveBrakable.h"

struct TORockCaveBL01 : public TORockCaveBrakable {
    TORockCaveBL01(void *set_data);
    virtual ~TORockCaveBL01();
};

LAYOUT_ASSERT(TORockCaveBL01_size, sizeof(TORockCaveBL01) == 0xBC);

// The object factory entry (ObjectFactoryTables.cpp).
extern "C" void *TORockCaveBL01__create(void *set_data);

#endif
