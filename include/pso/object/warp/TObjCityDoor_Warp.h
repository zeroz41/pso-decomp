#ifndef PSO_OBJECT_WARP_TOBJCITYDOOR_WARP_H
#define PSO_OBJECT_WARP_TOBJCITYDOOR_WARP_H

#include "types.h"
#include "pso/object/TUnk_804B5BA8.h"

struct TObjCityDoor_Warp : public TUnk_804B5BA8 {
    virtual ~TObjCityDoor_Warp();
    virtual void city_door_play_close_sound();
    virtual void city_door_tick_opening();
    virtual void city_door_play_open_sound();
    virtual void render();
    virtual void run_task();
};

typedef char TObjCityDoor_Warp_size[sizeof(TObjCityDoor_Warp) == 0xBC ? 1 : -1];
#endif
