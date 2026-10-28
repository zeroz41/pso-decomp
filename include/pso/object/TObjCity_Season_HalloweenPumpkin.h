#ifndef PSO_OBJECT_TOBJCITY_SEASON_HALLOWEENPUMPKIN_H
#define PSO_OBJECT_TOBJCITY_SEASON_HALLOWEENPUMPKIN_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjCity_Season_HalloweenPumpkin : public TObjBase {
    virtual ~TObjCity_Season_HalloweenPumpkin();
    virtual void render();
    virtual void run_task();
    void *dt(s16 arg1);
};

typedef char TObjCity_Season_HalloweenPumpkin_size[sizeof(TObjCity_Season_HalloweenPumpkin) == 0x90 ? 1 : -1];
#endif
