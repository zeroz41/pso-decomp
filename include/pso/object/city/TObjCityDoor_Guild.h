#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_GUILD_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_GUILD_H

#include "types.h"
#include "pso/object/city/TObjCityDoorBase.h"

struct TObjCityDoor_Guild : public TObjCityDoorBase {
    static const char *class_name;
    TObjCityDoor_Guild(TObject *parent, ObjectSetData *set);
    virtual ~TObjCityDoor_Guild();
    virtual void render();
    virtual void run_task();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Guild_size, sizeof(TObjCityDoor_Guild) == 0xBC);
#endif
