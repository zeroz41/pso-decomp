#include "types.h"
#include "pso/item/TUnk_804A09B0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TMainTask.h"

void TUnk_804A09B0::emit_marker_effects() {
    WeaponVector pos;

    if (is_mode_two_and_ready() != 0) {
        get_gun_point(&pos);
        launch_shot((u8 *)&pos, 0, 0, 1);
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

TUnk_804A09B0::~TUnk_804A09B0() {}

TUnk_804A09B0::TUnk_804A09B0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)TObjPlayer::create_item_shoot_model;
    shot_speed = 10.0f;
}

u8 *TObjPlayer::create_substate(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A09B0(tl_05, arg0);
    }
    return NULL;
}
