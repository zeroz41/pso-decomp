#include "types.h"
#include "pso/weapon/TUnk_804A3548.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A3548::emit_marker_effects() {
    s32 sp8;
    TObjPlayer *owner;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(1, &sp8) != 0) {
            owner = this->owner;
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)5);
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

TUnk_804A3548::~TUnk_804A3548() {}

TUnk_804A3548::TUnk_804A3548(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

u8 *TObjPlayer::create_vtable_804A3548(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A3548(tl_05, arg0);
    }
    return NULL;
}
