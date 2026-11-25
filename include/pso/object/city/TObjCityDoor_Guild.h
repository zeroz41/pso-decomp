#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_GUILD_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_GUILD_H

#include "types.h"
#include "pso/object/TObjCityDoorBase.h"

struct TObjCityDoor_Guild : public TObjCityDoorBase {
    TObjCityDoor_Guild(TObject *parent, void *set);
    virtual ~TObjCityDoor_Guild();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Guild_size, sizeof(TObjCityDoor_Guild) == 0xBC);
#endif
