#ifndef PSO_OBJECT_CAVE_TOROCKCAVESIMPLE_H
#define PSO_OBJECT_CAVE_TOROCKCAVESIMPLE_H

#include "types.h"
#include "pso/object/cave/TORockCave.h"

struct TORockCaveSimple : public TORockCave {
    TORockCaveSimple();
    virtual ~TORockCaveSimple();
    virtual void render();
};

typedef char TORockCaveSimple_size[sizeof(TORockCaveSimple) == 0xB4 ? 1 : -1];
#endif
