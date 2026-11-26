#include "pso/math/ClampedStep.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponPartisan.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TPlyDispData.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"

TItemWeaponPartisan::~TItemWeaponPartisan() {}

void TItemWeaponPartisan::emit_marker_effects() {
    switch (get_item_index()) {
    case 6:
        if (is_mode_two_and_ready() && owner->get_actor_meseta() >= 10000) {
            owner->try_spend_actor_meseta(10000);
            show_meseta_label((saddr)owner, (uaddr)&owner->body_center, 0, -10000);
            apply_scale_if_active(3.0f);
            spawn_particle_effect(&owner->body_center, 0x66);
            spawn_particle_effect(&owner->body_center, 0x66);
        } else {
            ((TItemWeapon *)this)->update_active_game_effect();
        }
        break;
    default:
        ((TItemWeapon *)this)->update_active_game_effect();
        break;
    }
}

void TItemWeaponPartisan::transform_model_node() {
    switch ((s32)get_item_index()) {
    case 6:
        if (TObjPlayer::get_player_list() == 4) {
            rotate_matrix_z(NULL, rotation);
        }
        break;
    case 5:
        switch (TObjPlayer::get_player_list()) {
        case 1:
            post_translate_matrix(&first_translation.x);
            return;
        case 2:
            post_translate_matrix(&second_translation.x);
            return;
        case 3:
            scale_current_matrix(&scale.x);
            break;
        }
        break;
    }
}

void TItemWeaponPartisan::update_idle() {
    if (get_item_index() == 5) {
        ::approach_value(&scale.z, 0.2f, 0.0f);
        if (scale.z <= 0.0f) {
            ::approach_value(&first_translation.y, -0.2f, -1.055f);
            ::approach_value(&second_translation.y, 0.15f, 0.75f);
        }
    }
}

void TItemWeaponPartisan::update_attack() {
    if (get_item_index() == 5) {
        ::approach_value(&first_translation.y, 0.5f, 0.0f);
        ::approach_value(&second_translation.y, -0.25f, 0.0f);
        if (0.0f <= first_translation.y) {
            ::approach_value(&scale.z, 0.5f, 1.0f);
        }
    }
}

void TItemWeaponPartisan::update_weapon() {
    s32 speed;

    if (get_item_index() == 6) {
        speed = owner->get_actor_meseta() / 100000;
        speed = speed * 0x222;
        if (speed > 0x1555) {
            speed = 0x1555;
        }
        advance_angle_wrap(&rotation, speed + 0x1555);
    }
}

TItemWeaponPartisan::TItemWeaponPartisan(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation = 0;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    first_translation.x = 0.0f;
    first_translation.y = 0.0f;
    first_translation.z = 0.0f;
    second_translation.x = 0.0f;
    second_translation.y = 0.0f;
    second_translation.z = 0.0f;
    set_weapon_flags(2);
    if (get_item_index() == 6) {
        set_weapon_flags(0x20);
    }
}

TItem *TItemWeaponPartisan::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponPartisan(tl_05, item);
    }
    return NULL;
}
