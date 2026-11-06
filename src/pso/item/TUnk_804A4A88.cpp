#include "types.h"
#include "pso/player/TUnk_804A4A88.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffLavis.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A4A88::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        ((TObjPlayer *)this)->drain_owner_hp_fraction(0.05f);
        ((TObjPlayer *)this)->launch_rare_weapon_special(0, 1, 1.0f);
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

void TUnk_804A4A88::vfunc_60() {
    if (TObjPlayer::get_player_list() == 2) {
        rotate_matrix_z(NULL, rotation_z);
        advance_angle_wrap(&rotation_z, 0x1999);
    }
}

TUnk_804A4A88::TUnk_804A4A88(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
    shot_callback = (WeaponShotCallback)create_lavis_shot;
    shot_speed = 10.0f;
    rotation_z = 0;
}

extern "C" {
u8 *TObjPlayer__sub_8012AB1C(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A4A88(tl_05, item);
    }
    return NULL;
}
}

TUnk_804A4A88::~TUnk_804A4A88() {}
