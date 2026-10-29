#ifndef PSO_MISC_TOAIRCONCAVE02_H
#define PSO_MISC_TOAIRCONCAVE02_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOAirconCave02 : public TObjMapObject {
    TOAirconCave02(TObject *parent, void *set_data);
    virtual ~TOAirconCave02();
    virtual void render();
    static void *create(void *arg0);
    static void release_static_resource();
    static void load_shared_resource();
};

typedef char TOAirconCave02_size[sizeof(TOAirconCave02) == 0xC8 ? 1 : -1];
#endif
