#include "types.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A2358.h"
#include "pso/technique/TTecFoie.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

extern f32 lbl_805DAD3C;

void TUnk_804A2260::emit_marker_effects() {
    if (is_mode_two_and_ready() != 0) {
        if (((TObjPlayer *)((u8 *)this->owner + 0x7CC))->get_stage_strike_count() == 0) {
            ((TObjPlayer *)this)->drain_owner_hp_fraction(lbl_805DAD3C);
            sub_80124C90();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}

void TUnk_804A2260::vfunc_60() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, rotation_z);
        return;
    case 4:
        TItem::begin_effect_render();
        rotate_matrix_z(NULL, -rotation_z);
        return;
    }
}

void TUnk_804A2260::update_weapon() {
    rotation_z += 0xAAA;
}

}

TUnk_804A2260::~TUnk_804A2260() {

}

extern "C" const f32 lbl_805DAD40;

TUnk_804A2260::TUnk_804A2260(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x100022);
    shot_speed = lbl_805DAD40;
    rotation_z = 0;
}

u8 *TObjPlayer::create_state_80125154(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A2260(tl_05, item);
    }
    return NULL;
}

extern "C" {


s16 TObjPlayer::get_stage_strike_count() { return *(s16*)((char*)this + 0x12); }

}
