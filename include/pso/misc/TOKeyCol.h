#ifndef PSO_MISC_TOKEYCOL_H
#define PSO_MISC_TOKEYCOL_H

#include "types.h"
#include "pso/misc/TOKey.h"

// An invisible floor switch: held on while a player stands within
// activate_range (10 plus set param 1).
class TOKeyCol : public TOKey {
public:
    TOKeyCol(TObject *parent, void *set_data);
    virtual ~TOKeyCol();
    virtual void run_task();
    virtual void render();
    virtual s32 is_confirm_pressed();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void trigger_activate_sound();
    virtual void trigger_deactivate_sound();
    virtual void vfunc_25();
    void send_switch_changed(s32 flags);
    static void *create(void *set_data);
};

typedef char TOKeyCol_size[sizeof(TOKeyCol) == 0xE8 ? 1 : -1];
#endif
