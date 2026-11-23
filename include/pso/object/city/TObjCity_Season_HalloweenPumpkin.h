#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_HALLOWEENPUMPKIN_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_HALLOWEENPUMPKIN_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCity_Season_HalloweenPumpkin : public TObjBase {
    TObjCity_Season_HalloweenPumpkin(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_HalloweenPumpkin();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_HalloweenPumpkin_size, sizeof(TObjCity_Season_HalloweenPumpkin) == 0x90);
#endif
