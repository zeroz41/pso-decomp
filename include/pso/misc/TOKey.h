#ifndef PSO_MISC_TOKEY_H
#define PSO_MISC_TOKEY_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct TOKey : public TObjMapObject {
    TOKey(TObject *parent);
    virtual ~TOKey();
    virtual void run_task();
    virtual void update_lock_state();
    virtual s32 is_confirm_pressed();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void trigger_activate_sound();
    virtual void vfunc_19();
    virtual void submit_cursor_target();
    virtual void send_switch_on();
    virtual void play_activate_sound();
    virtual void vfunc_23();
    virtual void update_armed_switch();
    virtual void vfunc_25();
    virtual void debug_draw_key_id();
    virtual void handle_switch_trigger(void *);
    void interact(s32 client);
    s32 update_object_view_visibility(f32, f32);
    u32 m_e4;
    void init_switch_id();
    void init_key();
    void bswap_6x05_switch_flag();
    s32 is_any_player_in_range();
    s32 is_local_player_in_range();
    u32 m_cc;
    u32 m_d0;
    u32 m_d4;
};

#endif
