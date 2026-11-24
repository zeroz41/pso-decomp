#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONPOISON_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONPOISON_H

#include "types.h"
#include "pso/object/collision/TObjFogCollisionSwitch.h"

struct TObjFogCollisionPoison : public TObjFogCollisionSwitch {
    TObjFogCollisionPoison(TObject *parent, void *set);
    virtual ~TObjFogCollisionPoison();
    virtual void vfunc_14();
    virtual void vfunc_13(s32);
    virtual void run_task();
    u32 m_98;
    static void create();
    static void *create(void *set_data);
    static void clear_state_array();
    s32 check_switch();
    void apply_poison_damage(s32 client);
    void record_poison_hit(u16 client);
    void play_poison_sound();
    void play_poison_persistent_sound();
};

LAYOUT_ASSERT(TObjFogCollisionPoison_size, sizeof(TObjFogCollisionPoison) == 0x9C);

// inferred name: one per client under a TObjFogCollisionPoison, whose constructor is
// the only creator. While the poison's switch is on it counts the client's ticks inside
// the fog, deals the poison damage and plays the poison sounds.
class TObjFogCollisionPoison_Ticker : public TObject {
public:
    TObjFogCollisionPoison_Ticker(TObject *parent, u16 client);
    virtual ~TObjFogCollisionPoison_Ticker();
    virtual void run_task();
    s32 damage_interval;  // ticks between poison damage (150 first, then 30)
    s32 damage_timer;     // ticks since the last damage
    s32 contact_ticks;    // consecutive ticks inside the fog
    u16 client;
    u8 pad_2A[0x2];
};
LAYOUT_ASSERT(TObjFogCollisionPoison_Ticker_size, sizeof(TObjFogCollisionPoison_Ticker) == 0x2C);
extern "C" {
void TObjFogCollisionPoison__sub_801533BC(void);
void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2);
}

#endif
