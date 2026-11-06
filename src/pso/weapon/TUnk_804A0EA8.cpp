#include "types.h"
#include "pso/weapon/TUnk_804A0EA8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A0EA8::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        shot_callback = (WeaponShotCallback)create_shoot_model_rot_z;
        impact_callback = NULL;
    } else {
        shot_callback = (WeaponShotCallback)create_gun_shot;
        impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
    }
    if (launch_shot((u8 *)&gun_point, 0, 0, 1) != 0) {
        launch_shot((u8 *)&second_gun_point, 0, 0, 0);
    } else {
        launch_shot((u8 *)&second_gun_point, 0, 0, 1);
    }
}

void TUnk_804A0EA8::reserved_53() {
    NJS_OBJECT *model;

    model = item_model;
    draw_weapon_model();
    get_gun_point(&gun_point);
    item_model = (NJS_OBJECT *)model_data[0];
    draw_weapon_at_joint((s32)this, 0x23);
    get_gun_point(&second_gun_point);
    item_model = model;
}

TUnk_804A0EA8::~TUnk_804A0EA8() {}

TUnk_804A0EA8::TUnk_804A0EA8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)spawn_weapon_impact_effect;
}

u8 *create_guld_milla(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A0EA8(tl_05, (u8 *)arg0);
    }
    return NULL;
}
