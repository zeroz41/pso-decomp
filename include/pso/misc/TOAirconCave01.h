#ifndef PSO_MISC_TOAIRCONCAVE01_H
#define PSO_MISC_TOAIRCONCAVE01_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOAirconCave01 : public TUnk_804AFBF8 {
    TOAirconCave01(TObject *parent, void *set_data);
    virtual ~TOAirconCave01();
    virtual void render();
    static void *create(void *arg0);
    static void release_static_resource();
    static void load_shared_resource();
};

typedef char TOAirconCave01_size[sizeof(TOAirconCave01) == 0xC8 ? 1 : -1];
#endif
