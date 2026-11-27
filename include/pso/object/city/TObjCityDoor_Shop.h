#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H

#include "types.h"
#include "pso/object/city/TObjCityDoorBase.h"

struct TObjCityDoor_Shop : public TObjCityDoorBase {
    static const char *class_name;
    TObjCityDoor_Shop(TObject *parent, ObjectSetData *set);
    virtual ~TObjCityDoor_Shop();
    virtual void render();
    virtual void run_task();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Shop_size, sizeof(TObjCityDoor_Shop) == 0xBC);
#endif
