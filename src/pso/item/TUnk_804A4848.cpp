#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TUnk_804A4848.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804A4948.h"
#include "pso/system/MatrixOps.h"
#include "pso/TMainTask.h"

// Turns the blade by blade_angle (the name s_rank_windmill_turn_blade was inferred).
void TUnk_804A4848::vfunc_60() {
    if (TObjPlayer::get_player_list() == 3) {
        rotate_matrix_x(NULL, blade_angle);
    }
}

void TUnk_804A4848::reserved_53() {
    s32 *temp_r31;

    if ((u32) *(u32 *)((s8 *)this + 0xF0) != 0U) {
        temp_r31 = *(s32 **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this + 0xF4)) + 0x2C)) + 0x30)) + 0x30);
        if (blend_off == 0) {
            *temp_r31 |= 0x10;
        }
        draw_weapon_model();
        ((TItemWeapon *)this)->update_trail_slot(0);
        if (blend_off == 0) {
            *temp_r31 &= 0xFFFFFFEF;
        }
    }
}

void TUnk_804A4848::update_idle() {
    s32 speed;

    speed = blade_speed;
    if (speed > 0xCCC) {
        blade_speed = speed - 0xB6;
    }
}

void TUnk_804A4848::update_attack() {
    s32 speed;

    attack_frames++;
    if (!(attack_frames & 3)) {
        speed = blade_speed;
        if (speed < 0x3333) {
            blade_speed = speed + 0xB6;
        }
    }
}

void TUnk_804A4848::update_weapon() {
    advance_angle_wrap(&blade_angle, blade_speed);
}

TUnk_804A4848::~TUnk_804A4848() {}

TUnk_804A4848::TUnk_804A4848(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    set_weapon_flags(35);
    blade_angle = 0;
    blade_speed = 3276;
    attack_frames = 0;
    blend_off = 1;
}

u8 *TObjPlayer::create_state_8012a418(s32 arg0) {
    if (arg0 != 0) {
        return (u8 *)new TUnk_804A4848(tl_05, (u8 *)arg0);
    }
    return NULL;
}
