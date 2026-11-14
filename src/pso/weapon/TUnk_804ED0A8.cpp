#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ED0A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804ED0A8::vfunc_60() {
    switch (TObjPlayer::get_player_list()) {
    case 1:
        rotate_matrix_x(NULL, pad_1f8);
        return;
    case 2:
        rotate_matrix_x(NULL, pad_1fc);
        return;
    }
}

void TUnk_804ED0A8::update_idle() {
    TObjPlayer::add_angle_clamped(&pad_1f8, 0x71C, 0x4000);
    if (pad_1f8 == 0x4000) {
        TObjPlayer::add_angle_clamped(&pad_1fc, 0x71C, 0x4000);
    }
}

void TUnk_804ED0A8::update_attack() {
    TObjPlayer::add_angle_clamped(&pad_1fc, -0xAAA, 0);
    if (pad_1fc == 0) {
        TObjPlayer::add_angle_clamped(&pad_1f8, -0xAAA, 0);
    }
}

TUnk_804ED0A8::~TUnk_804ED0A8() {}

TUnk_804ED0A8::TUnk_804ED0A8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(1536);
    pad_1f8 = 0;
    pad_1fc = 0;
}

u8 *TObjPlayer::create_state_1536() {
    if (this != NULL) {
        return (u8 *)new TUnk_804ED0A8(tl_05, (u8 *)this);
    }
    return NULL;
}
