#ifndef PSO_MISC_TOBARRIERENERGY01_H
#define PSO_MISC_TOBARRIERENERGY01_H

#include "types.h"
#include "pso/misc/TODoorBase.h"

// The laser guard (bm_fs_obj_lazerguard.bml): a switch-locked energy barrier
// that hums while it stands and swaps to its "open" texture list when its lock
// releases. It has no open/close motion of its own: the motion just loops.
class TOBarrierEnergy01 : public TODoorBase {
public:
    TOBarrierEnergy01(TObject *parent, void *set_data);
    virtual ~TOBarrierEnergy01();
    virtual void render();
    virtual void update_closed();
    virtual void update_opening();
    virtual void update_open();
    virtual void update_closing();
    virtual void update_demo();
    TOBarrierEnergy01 *init();
    void play_ambient_loop_sound();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
};

typedef char TOBarrierEnergy01_size[sizeof(TOBarrierEnergy01) == 0xD4 ? 1 : -1];
#endif
