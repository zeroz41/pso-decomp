#ifndef PSO_OBJECT_DOOR_TOBJDOORKEY_H
#define PSO_OBJECT_DOOR_TOBJDOORKEY_H

#include "types.h"
#include "pso/object/key/TOKey.h"

class TParticleCtrl;

struct TObjDoorKey : public TOKey {
    TObjDoorKey(TObject *parent, void *set_entry);
    virtual ~TObjDoorKey();
    virtual void trigger_activate_sound();
    virtual void update_armed_switch();
    virtual void update_switch_off();
    virtual void update_switch_on();
    virtual void trigger_deactivate_sound();
    virtual void debug_draw_key_id();
    void render();
    void draw_active_beam();
    void draw_inactive_badge();
    void run_task();
    static void free_key();
    static void load_resources();
    s32 activated;   // set by the activate sound, read by the key's plate
    s32 unk_EC;
    s32 spin_angle;  // the badge's y rotation, advanced while the switch is on
    s32 unk_F4;
    TParticleCtrl *particle;  // the continuous glow effect
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjDoorKey_size, sizeof(TObjDoorKey) == 0xFC);

extern "C" {
void TObjDoorKey__sub_8018FAEC(u16 id, u16);
}

#endif
