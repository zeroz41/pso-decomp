#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponSRankCard.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include <stddef.h>
#include "pso/item/TItem.h"
#include "pso/system/NinjaTypes.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/effect/item/TItemEffCane.h"

extern "C" void get_weapon_color__11TItemWeaponFv(void *, void *);

void TItemWeaponSRankCard::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    NJS_ARGB color;
    desc->scale = 5.0f;
    desc->spin[2] = 0xC000;
    desc->flags |= 0x282;
    get_weapon_color__11TItemWeaponFv(&color, this);
    copy_argb(&desc->color, &color);
    desc->hit_effect = create_network_object;
    desc->wall_effect = start_wall_card;
}

void TItemWeaponSRankCard::update_weapon() {
    if (get_attack_stage() == 2) {
        fan_flags |= 1;
        return;
    }
    fan_flags &= ~1;
}

void TItemWeaponSRankCard::create_cane_if_ready(Vec *pos) {
    if (get_attack_stage() == 0) {
        TItemEffCane::create(tl_05, this, -1, 0x1BD);
    }
}

void TItemWeaponSRankCard::emit_marker_effects() {
    Vec pos;
    owner->get_anim_node_position(0x30, &pos);
    if (owner->attack_state.get_validated_attack_stage() == 2) {
        fire_shot_at_target(&pos, item_model, 0);
        fire_shot_at_target(&pos, item_model, 0x1555);
        fire_shot_at_target(&pos, item_model, -0x1555);
    } else {
        fire_shot_at_target(&pos, item_model, 0);
    }
    create_cane_if_ready(&pos);
}

void TItemWeaponSRankCard::transform_model_node() {
    if (get_model_node_counter() == 0) {
        Vec offset = {0.0f, 0.0f, 0.5f};
        post_translate_matrix(&offset.x);
        rotate_matrix_x(0, 0x18E3);
        if (fan_flags & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            draw_model();
            pop_matrix();
        }
    }
}

void TItemWeaponSRankCard::draw_held_model() {
    if (test_weapon_flags(0x01000000U) == 0U) {
        draw_weapon_model();
    }
}

TItemWeaponSRankCard::TItemWeaponSRankCard(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    set_weapon_flags(3);
    fan_flags = 0;
}

TItem *TItemWeaponSRankCard::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankCard(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRankCard::~TItemWeaponSRankCard() {}
