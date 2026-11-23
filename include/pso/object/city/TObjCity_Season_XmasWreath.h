#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_XMASWREATH_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_XMASWREATH_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCity_Season_XmasWreath : public TObjBase {
    TObjCity_Season_XmasWreath(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_XmasWreath();
    virtual void render();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_XmasWreath_size, sizeof(TObjCity_Season_XmasWreath) == 0x90);
#endif
