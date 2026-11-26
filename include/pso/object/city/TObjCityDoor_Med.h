#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_MED_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_MED_H

#include "types.h"
#include "pso/object/TObjCityDoorBase.h"

struct TObjCityDoor_Med : public TObjCityDoorBase {
    static const char *class_name;
    TObjCityDoor_Med(TObject *parent, void *set);
    virtual ~TObjCityDoor_Med();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Med_size, sizeof(TObjCityDoor_Med) == 0xBC);
#endif
