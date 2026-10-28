#ifndef PSO_OBJECT_TOBJCITY_SEASON_XMASWREATH_H
#define PSO_OBJECT_TOBJCITY_SEASON_XMASWREATH_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjCity_Season_XmasWreath : public TObjBase {
    virtual ~TObjCity_Season_XmasWreath();
    virtual void render();
    void *dt(s16 arg1);
};

typedef char TObjCity_Season_XmasWreath_size[sizeof(TObjCity_Season_XmasWreath) == 0x90 ? 1 : -1];
#endif
