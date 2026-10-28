#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80124C90.h"
#include "pso/item/TUnk_804A2260.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rotate_matrix_z(s32, s32);
s32 is_mode_two_and_ready__10TObjPlayerFv();

extern f32 lbl_805DAD3C;

void TObjPlayer::launch_double_cannon_extra() {
    if (is_mode_two_and_ready__10TObjPlayerFv() != 0) {
        if (((TObjPlayer *)(*(s32 *)&this->unk_F0 + 0x7CC))->get_stage_strike_count() == 0) {
            drain_owner_hp_fraction(lbl_805DAD3C);
            sub_80124C90__13TUnk_804A2260Fv((u8 *)this);
        }
    } else {
        update_active_game_effect();
    }
}

void TObjPlayer::play_side_step_particle() {
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
