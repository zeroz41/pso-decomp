#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H

#include "types.h"
#include "pso/object/TUnk_804B5BA8.h"

struct TObjCityDoor_Shop : public TUnk_804B5BA8 {
    TObjCityDoor_Shop(TObject *parent, void *set);
    virtual ~TObjCityDoor_Shop();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Shop_size, sizeof(TObjCityDoor_Shop) == 0xBC);
#endif
