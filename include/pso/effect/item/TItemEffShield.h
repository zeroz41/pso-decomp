#ifndef PSO_EFFECT_ITEM_TITEMEFFSHIELD_H
#define PSO_EFFECT_ITEM_TITEMEFFSHIELD_H
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"

class TParticleCtrl;
struct ShieldEffectEntry;

// The effect a shield plays when it blocks (TItemProShield::perform_action):
// bursts of the entry's particles at a node of the player, the first after
// entry->first_delay frames and the rest every entry->interval frames.
class TItemEffShield : public TObject {
public:
    TItemEffShield(TObject *parent, u16 client_id, ShieldEffectEntry *entry);
    virtual ~TItemEffShield();
    virtual void run_task();

    void spawn_recipe_particles();

    static const char *class_name;

    Vec position;  // the player's node
    s32 rotation_x;  // the player's rotation, the particles' direction
    s32 rotation_y;
    s32 rotation_z;
    ShieldEffectEntry *entry;
    s32 timer;
    s32 burst;  // bursts played; the effect ends at entry->burst_count
    s32 node;
    u16 client_id;
    u8 pad_46[0x2];
};
LAYOUT_ASSERT(TItemEffShield_size, sizeof(TItemEffShield) == 0x48);

// The particle an equipped shield with item index 0x53-0x82 plays on its
// wearer every 120 frames while players nearby hold the same shield.
class TItemEffShieldPulse : public TObject {
public:
    TItemEffShieldPulse(TObject *parent, u16 client_id, u8 item_index);
    virtual ~TItemEffShieldPulse();
    virtual void run_task();

    s32 timer;
    s32 particle_id;  // -1 for none
    s32 oneshot;      // 0 plays a timed emitter instead of a one-shot effect
    u16 client_id;
    u8 item_index;
    u8 pad_2B;
    u32 item_generation;  // get_item_system_generation when it was made
};
LAYOUT_ASSERT(TItemEffShieldPulse_size, sizeof(TItemEffShieldPulse) == 0x30);

// The particle an equipped shield with item index 26 plays at its wearer's
// node 0x24 while the player is on the current floor; hidden while the player
// holds an item of group 0x1A.
class TItemEffShieldAura : public TObject {
public:
    TItemEffShieldAura(TObject *parent, u16 client_id);
    virtual ~TItemEffShieldAura();
    virtual void run_task();

    TParticleCtrl *particle;
    s32 floor;  // the current floor when the particle was made
    u16 client_id;
    u8 pad_26[0x2];
    u32 item_generation;  // get_item_system_generation when it was made
};
LAYOUT_ASSERT(TItemEffShieldAura_size, sizeof(TItemEffShieldAura) == 0x2C);

#endif
