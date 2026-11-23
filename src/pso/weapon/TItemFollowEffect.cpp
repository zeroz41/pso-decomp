#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/weapon/TItemFollowEffect.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/object/base/TObjMotion.h"
#include "types.h"

void TItemFollowEffect::run_task() {
    s32 pos[5];
    s32 var_r31;
    saddr item;

    if (item_generation != get_item_system_generation()) {
        queue_destruction();
        return;
    }
    var_r31 = 0;
    if (particle != NULL) {
        item = (saddr)find_item_by_id(item_id);
        if ((item != 0) && (((TItem *)item)->get_mode() == 2)) {
            var_r31 = 1;
            if (((TItemWeapon *)item)->get_joint_position(joint, pos) != 0) {
                particle->set_position(pos);
                if ((((TItem *)item)->is_hidden() == 0) || (((TObjCollidable *)item)->test_actor_flags(0x08000000) == 0)) {
                    particle->clear_active_flag();
                } else {
                    particle->enable();
                }
            } else {
                particle->enable();
            }
        }
    }
    if (var_r31 == 0) {
        queue_destruction();
    }
}

TItemFollowEffect::~TItemFollowEffect() {
    if (particle != NULL) {
        particle->queue_destruction();
    }
}

TItemFollowEffect::TItemFollowEffect(TObject *parent, TItemWeapon *weapon, s32 joint, s32 effect_id) : TObject(parent) {
    Vec position;
    disallow_rendering();
    item_id = weapon->get_item_id();
    this->joint = joint;
    weapon->get_joint_position(this->joint, &position);
    particle = create_particle_emitter(&position, effect_id);
    item_generation = get_item_system_generation();
}

void spawn_item_follow_effect(TObject *parent, TItemWeapon *weapon, s32 joint, s32 effect_id) {
    if (parent != NULL && weapon != NULL) {
        new TItemFollowEffect(parent, weapon, joint, effect_id);
    }
}
