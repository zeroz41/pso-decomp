#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/weapon/TItemWeapon.h"
#include <stddef.h>
#include "pso/weapon/TItemWeaponDarkFlow.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponDarkFlow::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    desc->range = 160.0f;
    desc->particle = 474;
}

void TItemWeaponDarkFlow::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (owner->get_actor_hp() * 8 < owner->get_hpmax()) {
            fire_shot_at_target(&owner->position, NULL, -0x238E);
            fire_shot_at_target(&owner->position, NULL, -0x11C7);
            fire_shot_at_target(&owner->position, NULL, 0);
            fire_shot_at_target(&owner->position, NULL, 0x11C7);
            fire_shot_at_target(&owner->position, NULL, 0x238E);
            play_sound_effect(0x4001A642, &owner->position, 0, 0);
            return;
        }
        ((TItemWeapon *)this)->update_active_game_effect();
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

void TItemWeaponDarkFlow::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child->sibling, 0x10, 0, 0);
    }
}

TItemWeaponDarkFlow::~TItemWeaponDarkFlow() {}

TItemWeaponDarkFlow::TItemWeaponDarkFlow(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

TItem *TItemWeaponDarkFlow::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponDarkFlow(tl_05, item);
    }
    return NULL;
}
