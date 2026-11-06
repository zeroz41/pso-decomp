#ifndef PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H
#define PSO_OBJECT_CITY_TOBJCITYDOOR_SHOP_H

#include "types.h"
#include "pso/object/TUnk_804B5BA8.h"

struct TObjCityDoor_Shop : public TUnk_804B5BA8 {
    virtual ~TObjCityDoor_Shop();
    virtual void render();
    virtual void run_task();
};

typedef char TObjCityDoor_Shop_size[sizeof(TObjCityDoor_Shop) == 0xBC ? 1 : -1];
#endif
