#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_MED_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_MED_H

#include "types.h"
#include "pso/object/TUnk_804B5BA8.h"

struct TObjCityDoor_Med : public TUnk_804B5BA8 {
    TObjCityDoor_Med(TObject *parent, void *set);
    virtual ~TObjCityDoor_Med();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Med_size, sizeof(TObjCityDoor_Med) == 0xBC);
#endif
