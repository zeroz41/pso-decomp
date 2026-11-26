#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponMarinasBag.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemTimerEventHpRegen.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponMarinasBag::emit_marker_effects() {
    Vec pos;

    if (is_mode_two_and_ready() != 0) {
        get_joint_position(2, &pos);
        spawn_particle_effect(&pos, 0x1BE);
    }
}

// Starts a 90-frame timer event on the effect objects (named
// marina_bag_start_regen before; vtable slot 57).
void TItemWeaponMarinasBag::on_equipped() {
    if (effect_objects != NULL) {
        new TItemTimerEventHpRegen(effect_objects, get_owner_client(), 0x5A);
    }
}

TItemWeaponMarinasBag::~TItemWeaponMarinasBag() {}

TItemWeaponMarinasBag::TItemWeaponMarinasBag(TObject *parent, u8 *item) : TItemWeapon(parent, item) {}

TItem *TItemWeaponMarinasBag::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMarinasBag(tl_05, item);
    }
    return NULL;
}
