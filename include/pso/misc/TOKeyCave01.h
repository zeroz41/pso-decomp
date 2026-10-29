#ifndef PSO_MISC_TOKEYCAVE01_H
#define PSO_MISC_TOKEYCAVE01_H

#include "types.h"
#include "pso/misc/TOKey.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"

// The cave door panel (fs_obj_do_doa_panel), or on the jungle and seabed
// floors the jungle key (fs_obj_key_jungle) whose lid turns open: held down
// while a player stands on it, glowing red while up.
class TOKeyCave01 : public TOKey {
public:
    TOKeyCave01(TObject *parent, void *set_data);
    virtual ~TOKeyCave01();
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
    static void free_objects();
    static void load_resources();

    NJS_ARGB glow_color;  // the constant material while up
    s32 glow_rising;
    s32 lid_angle;        // the jungle key's lid, 0 to 0x2000
};

typedef char TOKeyCave01_size[sizeof(TOKeyCave01) == 0x100 ? 1 : -1];

extern BmlResource *TOKeyCave01__resource_bundle;
// The red texture list while up, the model's own while down.
extern s32 *TOKeyCave01__texture_lists;
// 1: the jungle key is loaded (its lid turns), 0: the door panel (it slides).
extern s32 key_cave_render_state;

#endif
