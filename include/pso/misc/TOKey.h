#ifndef PSO_MISC_TOKEY_H
#define PSO_MISC_TOKEY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

// What pressing a key does (TOKey::mode).
enum {
    KEY_MODE_ONCE = 0,    // sets its switch; ignored once the switch is on
    KEY_MODE_TOGGLE = 1,  // flips its switch every press
    KEY_MODE_NONE = 2,    // no valid switch id: never pressed
};

// A map object that sets or toggles one floor switch (set param 4) when a
// player presses the action button on it, then waits press_delay frames
// before it sends the 6x05 switch command.
class TOKey : public TObjMapObject {
public:
    TOKey(TObject *parent);
    virtual ~TOKey();
    virtual void run_task();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual void interact(s32 client);
    // Copies the floor's switch state into is_on (unless mode is NONE).
    virtual void update_lock_state();
    // 1 when the local player stands in range and presses the action button.
    virtual s32 is_confirm_pressed();
    // The per-frame steps while the switch is on / off.
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void trigger_activate_sound();
    virtual void trigger_deactivate_sound();
    virtual void submit_cursor_target();
    virtual void send_switch_on();
    virtual void play_activate_sound();
    virtual void play_deactivate_sound();
    virtual void update_armed_switch();
    virtual void vfunc_25();
    virtual void debug_draw_key_id();
    // The 6x05 switch command for this key arrived.
    virtual void handle_switch_trigger(void *cmd);
    void init_switch_id();
    void init_key(void *set_entry);
    s32 is_any_player_in_range();
    s32 is_local_player_in_range();

    s32 switch_id;       // the floor switch it drives, -1 for none
    f32 activate_range;  // how near a player must stand to press it
    s32 mode;            // KEY_MODE_*
    s32 is_on;           // the switch state last read
    s32 press_delay;     // frames from a press to the 6x05 command
    s32 press_timer;
    s32 press_pending;   // pressed, the command not sent yet
    s32 in_view;         // update_object_view_visibility saw it this frame
};

typedef char TOKeySize[sizeof(TOKey) == 0xE8 ? 1 : -1];

// The 6x05 switch command handler (TGameProtocol's table).
void handle_6x05_write_switch_flag(void *cmd);

#endif
