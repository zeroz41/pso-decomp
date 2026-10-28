#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/player/TUnk_804A6108.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
void TItemWeapon__ct(void *);

void TObjPlayer::update_boss2tunnel_move() {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 2:
        TItem::begin_effect_render();
        rotate_matrix_z(0, -*(s32 *)&this->unk_1F8);
        return;
    case 3:
        TItem::begin_effect_render();
        return;
    }
}
void TUnk_804A6108::update_weapon() { advance_angle_wrap((s32 *)((char*)this + 0x1f8), 3276); }

extern s32 lbl_804A6108[];

void *TUnk_804A6108::init_effect_state() {
    TItemWeapon__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A6108;
    *(u32 *)&this->unk_1F8 = 0;
    return this;
}

}
