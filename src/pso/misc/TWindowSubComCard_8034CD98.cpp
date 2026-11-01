#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowSubComCard_8034CD98.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubInformationBoard.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjCityMainWarp.h"

struct I_8034CDE0 { u8 pad[0x10]; s8 f10; u8 pad11[0xBC - 0x11]; };

struct L_8034CDE0 { u8 f0; u8 n; u8 pad2[2]; I_8034CDE0 items[1]; };

extern "C" {
s32 draw_text_gray__17TWindowSubComCardFllll(void *, void *, int, int);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
void *draw_card_icon__17TWindowSubComCardFll(s32, int, void *);
s32 get_window_layout_position(s32);
extern const f32 lbl_805DFDD8;
extern const f32 lbl_805DFDDC;
extern s32 lbl_80478C2C[];

void TWindowSubInformationBoard::open_card_info_window() {
    s32 window_layout_position;
    window_layout_position = get_window_layout_position(0xA5);
    TWindowMessage::create((void *)window_layout_position, (s32)lbl_80478C2C, 1);
    this->m_24 = -1;
}
void *TWindowSubComCard__sub_8034CDE0(void) {
    I_8034CDE0 *it;
    void *w;
    s32 i;
    s32 n;
    it = (I_8034CDE0 *)TLobby::get_info_board_ptr();
    if (it == NULL) {
        return 0;
    }
    w = draw_card_icon__17TWindowSubComCardFll(get_window_layout_position(0xA6), 0xC, TWindowSubStatusDisp::get_message_10(0x1D));
    n = ((L_8034CDE0 *)it)->n;
    it = ((L_8034CDE0 *)it)->items;
    for (i = 0; i < n; i++, it++) {
        if (it->f10 != 0) {
            forward_trade_action_default__16TObjCityMainWarpFPviii((void *)w, (int)it, 0x16, (int)i);
        } else {
            draw_text_gray__17TWindowSubComCardFllll(w, it, 0x16, i);
        }
    }
    if (((TWindowSubComCardList *)w)->get_field_72() <= 0) {
        draw_text_gray__17TWindowSubComCardFllll(w, TWindowSubStatusDisp::get_message_10(0xD2), 6, -1);
    }
    ((TWindowSubComCardList *)w)->set_flag70_bit10();
    ((TWindowSubComCardList *)w)->set_scroll_target(lbl_805DFDD8, lbl_805DFDDC);
    return w;
}

}
