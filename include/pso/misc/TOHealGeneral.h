#ifndef PSO_MISC_TOHEALGENERAL_H
#define PSO_MISC_TOHEALGENERAL_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TOHealGeneral : public TUnk_804AFBF8 {
    // The object factories' create() passes its own r3, the set entry, on.
    TOHealGeneral(void *set_data);
    virtual ~TOHealGeneral();
    virtual void *get_center();
    u8 unk_C8[0x4];
    u32 m_cc;  // the rotor angle, render turns the rotor and the ring by it
    union { u8 _padD0[0x4]; f32 ring_drop; };  // how far the heal ring has dropped, 0 to 22.3
    // The two particle effects' positions; get_center returns the second.
    // text_80169BD0's members store a script entry in m_d4.
    union { void *m_d4; Vec effect_pos[2]; };
    u32 effects[2];  // the two particle effects, released by the destructor
    u16 heal_target;     // the player being healed, 0xFFFF for none
    virtual void run_task();
    virtual void render();
    void *create();
    static void close_dialog_window();
    static void load_resources();
    void accept_player(u16 arg1);
    s32 update_active_state();
    void set_enable_count(s32 arg1);
    void set_script_entry(s32 arg1);
    s32 update_heal_gauge_state();
    void update_closing();
    void update_opening();
    void apply_heal_to_target();
    u8 unk_F6[0x2];
};

typedef char TOHealGeneral_size[sizeof(TOHealGeneral) == 0xF8 ? 1 : -1];

#endif
