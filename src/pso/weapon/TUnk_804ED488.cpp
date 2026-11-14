#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ED488.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804ED488::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->pad_3c = 160.0f;
    desc->pad_78 = 474;
}

void TUnk_804ED488::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (get_actor_hp(owner) * 8 < ((TItemProShield *)owner)->get_field_2b8()) {
            fire_shot_at_target(&owner->position, NULL, -0x238E);
            fire_shot_at_target(&owner->position, NULL, -0x11C7);
            fire_shot_at_target(&owner->position, NULL, 0);
            fire_shot_at_target(&owner->position, NULL, 0x11C7);
            fire_shot_at_target(&owner->position, NULL, 0x238E);
            play_sound_effect(0x4001A642, &owner->position, 0, 0);
            return;
        }
        ((TObjPlayer *)this)->update_active_game_effect();
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

void TUnk_804ED488::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child->sibling, 0x10, 0, 0);
    }
}

TUnk_804ED488::~TUnk_804ED488() {}

TUnk_804ED488::TUnk_804ED488(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

u8 *create_dark_flow(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804ED488(tl_05, arg0);
    }
    return NULL;
}
