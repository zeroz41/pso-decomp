#ifndef PSO_ITEM_TITEMPROARMORPARTICLE_H
#define PSO_ITEM_TITEMPROARMORPARTICLE_H

#include "types.h"
#include "pso/item/TItemProArmor.h"

// TItemProArmorParticle::particle_mode values.
enum {
    ARMOR_PARTICLE_NONE = 0,
    ARMOR_PARTICLE_TIMER = 1,     // on_equip starts a timer event that plays the particle
    ARMOR_PARTICLE_PER_AREA = 2,  // update_equipped spawns the particle in each new area
};

// An armor of PMT model type 2 (TItemProArmor::create): a particle effect
// follows its owner while it is equipped.
struct TItemProArmorParticle : public TItemProArmor {
    TItemProArmorParticle(TObject *parent, u8 *item);
    virtual ~TItemProArmorParticle();
    virtual void update_equipped();
    virtual void on_equip();
    virtual void on_unequip();

    // Spawns a TItemEffArmorParticle playing particle on the client's
    // player while the item stays equipped; nothing without a parent.
    static void create_effect(TObject *parent, s32 item_id, u16 client, s32 particle);

    s32 last_area;      // the area the particle was last spawned in, -1 for none
    s32 particle_id;
    s32 particle_mode;  // ARMOR_PARTICLE_*
};

typedef char TItemProArmorParticle_size[sizeof(TItemProArmorParticle) == 0x1A4 ? 1 : -1];
#endif
