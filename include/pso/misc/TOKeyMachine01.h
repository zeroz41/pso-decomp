#ifndef PSO_MISC_TOKEYMACHINE01_H
#define PSO_MISC_TOKEYMACHINE01_H

#include "types.h"
#include "pso/misc/TOKey.h"
struct BmlResource;
#include "pso/system/NinjaTypes.h"

// The machine floors' door panel (fs_obj_ki_doa_panel): held down while a
// player stands on it, glowing red while up.
class TOKeyMachine01 : public TOKey {
public:
    TOKeyMachine01(TObject *parent, void *set_data);
    virtual ~TOKeyMachine01();
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
    static void free_statics();
    static void load_assets();

    NJS_ARGB glow_color;  // the constant material while up
    s32 glow_rising;
};

typedef char TOKeyMachine01_size[sizeof(TOKeyMachine01) == 0xFC ? 1 : -1];

extern BmlResource *TOKeyMachine01__resource_bundle;
// The red texture list while up, the model's own while down.
extern s32 *TOKeyMachine01__texture_lists;

#endif
