#ifndef PSO_MISC_TOKEYCOL_H
#define PSO_MISC_TOKEYCOL_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TOKeyCol : public TOKey {
    virtual ~TOKeyCol();
    virtual void trigger_activate_sound();
    virtual s32 is_confirm_pressed();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void trigger_deactivate_sound();
    virtual void vfunc_25();
    void send_switch_changed(s32 flags);
    void run_task();
    void render();
    static void *create(void *arg0);
};

typedef char TOKeyCol_size[sizeof(TOKeyCol) == 0xE8 ? 1 : -1];
#endif
