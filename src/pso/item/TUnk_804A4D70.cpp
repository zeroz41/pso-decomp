#include "types.h"
#include "pso/item/TUnk_804A4D70.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffOrgaFlowShot.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/TMainTask.h"

TUnk_804A4D70::~TUnk_804A4D70() {}

void TUnk_804A4D70::emit_marker_effects() {
    switch (get_item_index()) {
    case 6:
        if (is_mode_two_and_ready() && obj_getPtr2B0_20((u8 *)owner) >= 10000) {
            try_spend_actor_meseta((u8 *)owner, 10000);
            show_meseta_label((s32)owner, (u32)&owner->m_2fc, 0, -10000);
            apply_scale_if_active(3.0f);
            spawn_particle_effect(&owner->m_2fc, 0x66);
            spawn_particle_effect(&owner->m_2fc, 0x66);
        } else {
            ((TObjPlayer *)this)->update_active_game_effect();
        }
        break;
    default:
        ((TObjPlayer *)this)->update_active_game_effect();
        break;
    }
}

void TUnk_804A4D70::vfunc_60() {
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

void TUnk_804A4D70::update_idle() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&scale.z, 0.2f, 0.0f);
        if (scale.z <= 0.0f) {
            TItemEffOrgaFlowShot::approach_value(&first_translation.y, -0.2f, -1.055f);
            TItemEffOrgaFlowShot::approach_value(&second_translation.y, 0.15f, 0.75f);
        }
    }
}

void TUnk_804A4D70::update_attack() {
    if (get_item_index() == 5) {
        TItemEffOrgaFlowShot::approach_value(&first_translation.y, 0.5f, 0.0f);
        TItemEffOrgaFlowShot::approach_value(&second_translation.y, -0.25f, 0.0f);
        if (0.0f <= first_translation.y) {
            TItemEffOrgaFlowShot::approach_value(&scale.z, 0.5f, 1.0f);
        }
    }
}

void TUnk_804A4D70::update_weapon() {
    s32 speed;

    if (get_item_index() == 6) {
        speed = obj_getPtr2B0_20((u8 *)owner) / 100000;
        speed = speed * 0x222;
        if (speed > 0x1555) {
            speed = 0x1555;
        }
        advance_angle_wrap(&rotation, speed + 0x1555);
    }
}

TUnk_804A4D70::TUnk_804A4D70(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
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

u8 *create_partisan_weapon(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A4D70(tl_05, item);
    }
    return NULL;
}
