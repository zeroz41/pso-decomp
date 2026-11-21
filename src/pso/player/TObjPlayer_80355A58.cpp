#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804F1320.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/item/TItem.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"


#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TUnk_804F1320::activate_effect(s32 item) {
    if (owner != NULL && is_current_area_item_enabled() != 0) {
        s32 owner_floor = owner->get_floor();
        s32 floor = get_current_floor();
        if (floor == owner_floor && get_mode() == 2) {
            spawn_pg_effect(&owner->body_center, item, effect_radius);
        }
    }
}

#pragma pop

void TUnk_804F1320::emit_marker_effects() {
    s32 temp_r3;
    if (is_mode_two_and_ready() != 0) {
        temp_r3 = owner->get_photon_blast_charge();
        if (temp_r3 >= 0x14) {
            send_activate_effect(temp_r3);
            return;
        }
        update_active_game_effect();
        return;
    }
    update_active_game_effect();
}

TUnk_804F1320::~TUnk_804F1320() {}

TUnk_804F1320::TUnk_804F1320(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x22);
    if (get_item_group() == 0x3D) {
        effect_radius = 70.0f;
        set_weapon_flags(0x100000);
    } else {
        effect_radius = 100.0f;
    }
}
