#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffEquip.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_801036CC.h"
#include "pso/weapon/TItemAttacker.h"
#include "types.h"
#include "pso/object/base/TObjBase.h"

// The anchor's collision body: a sphere of radius 3.
extern const CollisionBody equip_anchor_body = {
    { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x31F0B, { 0.0f, 0.0f, 0.0f }, 0.0f
};
const char *TItemEffEquip::class_name = "TItemEffEquip";

#pragma defer_codegen on

TItemEffEquipAnchor::TItemEffEquipAnchor(TObject *parent, u16 client_id, s32 node) : TObjCollidable(parent) {
    this->client_id = client_id;
    this->node = node;
    copy_collision_body(&body, &equip_anchor_body);
    if (this->get_entity_id() == 0xFFFF) {
        set_entity_id(pop_free_entity_id());
    }
    set_collision_body(&body);
    register_object_by_id();
    disallow_rendering();
}

TItemEffEquipAnchor::~TItemEffEquipAnchor() {
    if (bodies != NULL) {
        unregister_object_by_id();
        clear_collision_bodies();
        push_free_entity_id(this->get_entity_id());
        set_entity_id(0xFFFF);
    }
}

void TItemEffEquipAnchor::run_task() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        player->get_anim_node_position(node, &position);
    }
}

void *TItemEffEquipAnchor::get_center() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        player->get_anim_node_position(node, &position);
    }
    return &position;
}

void TItemEffEquip::create(TObject *parent, u16 client_id, s32 node, s32 particle_id, s32 next_particle_id) {
    new TItemEffEquip(parent, client_id, node, particle_id, next_particle_id);
}

TItemEffEquip::TItemEffEquip(TObject *parent, u16 client_id, s32 node, s32 particle_id, s32 next_particle_id)
    : TObject(parent) {
    m_name = class_name;
    disallow_rendering();
    anchor = new TItemEffEquipAnchor(this, client_id, node);
    particle = NULL;
    this->next_particle_id = next_particle_id;
    if (anchor != NULL) {
        spawn_equip_particle_effect(particle_id);
        TItemAttacker::spawn_item_timer(this, release_effect_timer, 10);
        TItemAttacker::spawn_item_timer(this, retire_equipment_effect, 20);
    } else {
        queue_destruction();
    }
}

TItemEffEquip::~TItemEffEquip() {
    TParticleCtrl::release(particle);
}

void TItemEffEquip::run_task() {
    if (anchor->all_parents_unqueued_for_destruction() == 0) {
        anchor = NULL;
        queue_destruction();
    }
}

void TItemEffEquip::release_effect() {
    if (anchor != NULL && next_particle_id != -1) {
        TParticleCtrl::release(particle);
        spawn_equip_particle_effect(next_particle_id);
    }
}

void TItemEffEquip::release_effect_timer(TObject *effect) {
    if (effect != NULL) {
        static_cast<TItemEffEquip *>(effect)->release_effect();
    }
}

void TItemEffEquip::retire_equipment_effect(TObject *effect) {
    if (effect != NULL) {
        effect->queue_destruction();
    }
}

void TItemEffEquip::spawn_equip_particle_effect(s32 particle_id) {
    particle = spawn_continuous_particle_effect_with_flags(anchor->get_center(), particle_id, 0x10);
    if (particle != NULL) {
        particle->set_owner_id(anchor->get_entity_id());
    }
}
