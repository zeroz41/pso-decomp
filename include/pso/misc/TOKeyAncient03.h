#ifndef PSO_MISC_TOKEYANCIENT03_H
#define PSO_MISC_TOKEYANCIENT03_H

#include "types.h"
#include "pso/misc/TOKey.h"
struct BmlResource;
#include "pso/system/NinjaTypes.h"

// The ruins door panel (fs_obj_o_doorpanel): held down while a player
// stands on it, its glow pulsing while it is up. The panel's slide is kept
// in scale (y from 0 down to -0.7).
class TOKeyAncient03 : public TOKey {
public:
    TOKeyAncient03(TObject *parent, void *set_data);
    virtual ~TOKeyAncient03();
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
    static void cleanup_refs();
    static void load_resources();

    NJS_ARGB glow_color;  // the constant material while up
    s32 glow_rising;
};

typedef char TOKeyAncient03_size[sizeof(TOKeyAncient03) == 0xFC ? 1 : -1];

extern BmlResource *TOKeyAncient03__model_archive;
// The red texture list while up, the model's own while down.
extern s32 *TOKeyAncient03__texture_variants;
#endif
