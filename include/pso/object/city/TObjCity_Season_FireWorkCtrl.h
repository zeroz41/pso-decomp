#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORKCTRL_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORKCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCity_Season_FireWorkCtrl : public TObjBase {
    TObjCity_Season_FireWorkCtrl(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_FireWorkCtrl();
    virtual void vfunc_13(s32);
    // Draws the area the fireworks start in as a debug box (name inferred).
    void sub_8018355C();
    virtual void run_task();

    // Frames until the next firework: run_task counts it down and rolls a new
    // delay from set_params[0] (name inferred).
    s32 spawn_delay;
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCity_Season_FireWorkCtrl_size, sizeof(TObjCity_Season_FireWorkCtrl) == 0x94);
#endif
