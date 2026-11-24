#ifndef PSO_EFFECT_ITEM_TITEMEFFEQUIP_H
#define PSO_EFFECT_ITEM_TITEMEFFEQUIP_H

#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "types.h"

class TParticleCtrl;

// An invisible collidable pinned to one animation node of a player; its
// position follows the node every frame and it answers get_center with it.
class TItemEffEquipAnchor : public TObjCollidable {
public:
    TItemEffEquipAnchor(TObject *parent, u16 client_id, s32 node);
    virtual ~TItemEffEquipAnchor();
    virtual void *get_center();
    virtual void run_task();

    u16 client_id;  // the player it follows (get_player_by_client_id)
    u8 pad_AE[0x2];
    s32 node;       // the player's animation node
    CollisionBody body;
};
LAYOUT_ASSERT(TItemEffEquipAnchor_size, sizeof(TItemEffEquipAnchor) == 0xE0);

// The effect TItemWeapon::on_equip starts at a player's node: a particle effect
// on a TItemEffEquipAnchor at the node, swapped for a second effect after 10
// frames; the effect ends after 20 frames.
class TItemEffEquip : public TObject {
public:
    TItemEffEquip(TObject *parent, u16 client_id, s32 node, s32 particle_id, s32 next_particle_id);
    virtual ~TItemEffEquip();
    virtual void run_task();

    static void create(TObject *parent, u16 client_id, s32 node, s32 particle_id, s32 next_particle_id);
    void spawn_equip_particle_effect(s32 particle_id);
    void release_effect();
    // Item timer callbacks.
    static void release_effect_timer(TObject *effect);
    static void retire_equipment_effect(TObject *effect);

    static const char *class_name;

    TItemEffEquipAnchor *anchor;
    TParticleCtrl *particle;
    s32 next_particle_id;  // spawned by release_effect, -1 for none
};
LAYOUT_ASSERT(TItemEffEquip_size, sizeof(TItemEffEquip) == 0x28);
LAYOUT_ASSERT(TItemEffEquip_attachment_offset, offsetof(TItemEffEquip, anchor) == 0x1c);
LAYOUT_ASSERT(TItemEffEquip_effect_offset, offsetof(TItemEffEquip, particle) == 0x20);
LAYOUT_ASSERT(TItemEffEquip_next_effect_id_offset, offsetof(TItemEffEquip, next_particle_id) == 0x24);
#endif
