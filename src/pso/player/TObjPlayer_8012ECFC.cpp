#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012ECFC.h"
#include "pso/item/TUnk_804A6010.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rotate_matrix_y(s32, s32);
}

void twinkle_star_turn_stars(void *arg0) {
    s32 player_list;

    player_list = TObjPlayer::get_player_list();
    switch (player_list) {
    case 1:
        TItem::begin_effect_render();
        rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x1F8));
        return;
    case 3:
        TItem::begin_effect_render();
        rotate_matrix_y(0, -*(s32 *)((s8 *)arg0 + 0x1F8));
    case 2:
        return;
    }
}

void TUnk_804A6010::update_weapon() {
    *(s32 *)&this->unk_1F8 = (s32) (*(s32 *)&this->unk_1F8 + 0xCCC);
}

extern s32 tl_05;

void TUnk_804A6010::emit_marker_effects() {
    s32 item = (s32)this;
    if (((TItemWeapon *)this)->get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effects((TItem*)item, 2, 4);
    }
}
