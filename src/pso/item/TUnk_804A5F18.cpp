#include "types.h"
#include "pso/player/TUnk_804A5F18.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecDeband.h"
#include "pso/misc/TTecSifta.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

void TUnk_804A5F18::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)this)->get_tp() == 0) {
            TTecDeband::create((s32)owner, (s32)&owner->position, 2);
        } else {
            TTecSifta::create(owner, &owner->position, (void *)2);
        }
        roll_technique();
        return;
    }
    ((TObjPlayer *)this)->update_active_game_effect();
}

void TUnk_804A5F18::update_idle() {
    TObjPlayer::add_angle_clamped(&rotation_x, 1820, 10922);
}

void TUnk_804A5F18::update_attack() {
    TObjPlayer::add_angle_clamped(&rotation_x, -1820, 0);
}

void TUnk_804A5F18::vfunc_57() {
    roll_technique();
    roll_technique();
}

void TUnk_804A5F18::vfunc_60() {
    if (TObjPlayer::get_player_list() == 1) {
        rotate_matrix_x(NULL, rotation_x);
    }
}

TUnk_804A5F18::TUnk_804A5F18(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    rotation_x = 10922;
    set_weapon_flags(1570);
    ((TObjPlayer *)this)->set_effect_state(2);
}

u8 *TObjPlayer::create_state_variant_a(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A5F18(tl_05, item);
    }
    return NULL;
}

TUnk_804A5F18::~TUnk_804A5F18() {}
