#ifndef PSO_MISC_TOSENSOR_H
#define PSO_MISC_TOSENSOR_H

#include "types.h"
#include "pso/misc/TOKey.h"

// The base of the floor sensors: a switch that turns on for good once a
// player comes within activate_range, then rises out of the floor and is
// destroyed 100 units above its set position.
class TOSensor : public TOKey {
public:
    TOSensor(TObject *parent);
    virtual ~TOSensor();
    virtual void render();
    // mode 1: any player carrying status flag 0x400000 in range; mode 2:
    // the local player in range while it holds the window focus.
    virtual s32 is_confirm_pressed();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void update_armed_switch();
    virtual void vfunc_25();
    // The floor's looping sensor sound while off / on.
    void play_off_loop_sound();
    void play_on_loop_sound();
};

extern const char *TOSensor__class_name;

#endif
