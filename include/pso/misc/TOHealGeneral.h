#ifndef PSO_MISC_TOHEALGENERAL_H
#define PSO_MISC_TOHEALGENERAL_H

#include "types.h"
#include "pso/object/TObjMapObject.h"

struct BmlResource;
class TParticleCtrl;

// The healing ring: a player standing in it is held while the ring drops and
// gets 9 HP and 9 TP a frame until it is back up.
struct TOHealGeneral : public TObjMapObject {
    // The object factories' create() passes its own r3, the set entry, on.
    TOHealGeneral(void *set_data);
    virtual ~TOHealGeneral();
    virtual void run_task();
    virtual void render();
    virtual void *get_center();

    static void *create(void *set_data);
    static void unload_resources();
    static void load_resources();

    s32 is_local_player(u16 client);
    void update_demo();
    void update_closing();
    void update_opening();
    void apply_heal_to_target();
    void find_heal_target();

    static const char *class_name;
    static BmlResource *model_resource;

    u8 pad_c8[0x4];
    s32 rotor_angle;  // render turns the rotor and the ring by it
    f32 ring_drop;    // how far the heal ring has dropped, 0 to 22.3
    // The two particle effects' positions; get_center returns the second.
    Vec effect_pos[2];
    TParticleCtrl *effects[2];  // the two particle effects, released by the destructor
    u16 heal_target;  // the player being healed, 0xFFFF for none
    u8 pad_f6[0x2];
};

typedef char TOHealGeneral_size[sizeof(TOHealGeneral) == 0xF8 ? 1 : -1];

#endif
