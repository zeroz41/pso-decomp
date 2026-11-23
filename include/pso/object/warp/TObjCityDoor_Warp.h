#ifndef PSO_OBJECT_WARP_TOBJCITYDOOR_WARP_H
#define PSO_OBJECT_WARP_TOBJCITYDOOR_WARP_H

#include "types.h"
#include "pso/object/TUnk_804B5BA8.h"

struct TObjCityDoor_Warp : public TUnk_804B5BA8 {
    TObjCityDoor_Warp(TObject *parent, void *set);
    virtual ~TObjCityDoor_Warp();
    s32 is_rader_map_active();
    virtual void city_door_play_close_sound();
    virtual void city_door_tick_opening();
    virtual void city_door_play_open_sound();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoor_Warp_size, sizeof(TObjCityDoor_Warp) == 0xBC);
#endif
