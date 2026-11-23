#ifndef PSO_OBJECT_CAVE_TOAIRCONCAVE02_H
#define PSO_OBJECT_CAVE_TOAIRCONCAVE02_H

#include "types.h"
#include "pso/object/base/TObjMapObject.h"

struct TOAirconCave02 : public TObjMapObject {
    TOAirconCave02(TObject *parent, void *set_data);
    virtual ~TOAirconCave02();
    virtual void render();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TOAirconCave02_size, sizeof(TOAirconCave02) == 0xC8);
#endif
