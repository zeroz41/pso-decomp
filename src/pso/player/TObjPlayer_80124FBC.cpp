#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);

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
        rotate_matrix_z(0, *(s32 *)&this->unk_1F8);
        return;
    case 4:
        TItem::begin_effect_render();
        rotate_matrix_z(0, -*(s32 *)&this->unk_1F8);
        return;
    }
}

void TUnk_804A2260::update_weapon() {
    *(s32 *)&this->unk_1F8 = (s32) (*(s32 *)&this->unk_1F8 + 0xAAA);
}

}
