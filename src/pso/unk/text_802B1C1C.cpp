#include "types.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubComCard_80265410.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
TWindowSubComCardList *draw_card_icon__17TWindowSubComCardFll(s32 layout, s32 kind, void *title);
s32 get_window_layout_position(s32 id);
TObjPlayer *get_player_by_client_id(s32 id);
extern s32 local_client_id;
s32 draw_text_gray__17TWindowSubComCardFllll(void *list, void *text, int kind, int id);
s32 is_trade_range_bit_set(s32 client);
s32 is_script_controlled__10TObjPlayerFv(TObjPlayer *player);
s32 obj_isState3_324__13TUnk_804806E8Fv(TObjPlayer *player);
extern const f32 lbl_805DE29C;
extern const f32 lbl_805DE2A0;

TWindowSubComCardList *TWindowSubComCard__sub_802B1C1C(void) {
    s32 i;
    TObjPlayer *player;
    TWindowSubComCardList *list;

    list = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0x5A), 4, TWindowSubStatusDisp::get_message_10(0x1F));
    for (i = 0; i < 4; i++) {
        if (i == local_client_id) {
            continue;
        }
        player = get_player_by_client_id(i);
        if (player == NULL) {
            continue;
        }
        if (is_script_controlled__10TObjPlayerFv(player) != 0) {
            continue;
        }
        if (obj_isState3_324__13TUnk_804806E8Fv(player) != 0) {
            continue;
        }
        if (is_trade_range_bit_set(i)) {
            forward_trade_action_default__16TObjCityMainWarpFPviii(list, (s32)player->get_name(), 7, i);
        } else {
            draw_text_gray__17TWindowSubComCardFllll(list, (void *)player->get_name(), 7, i);
        }
    }
    if (list->get_field_72() <= 0) {
        draw_text_gray__17TWindowSubComCardFllll(list, TWindowSubStatusDisp::get_message_10(0xD2), 7, 0);
    }
    list->set_flag70_bit10();
    list->set_scroll_target(lbl_805DE29C, lbl_805DE2A0);
    return list;
}

}
