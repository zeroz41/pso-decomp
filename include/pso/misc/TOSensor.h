#ifndef PSO_MISC_TOSENSOR_H
#define PSO_MISC_TOSENSOR_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOSensor : public TOKey {
    virtual ~TOSensor();
    virtual void update_switch_on();
    virtual s32 is_confirm_pressed();
    virtual void update_switch_off();
    virtual void update_armed_switch();
    virtual void vfunc_25();
    void render();
};

#endif
