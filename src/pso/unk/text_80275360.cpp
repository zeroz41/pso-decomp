#include "types.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/chat/ShortMail.h"

extern "C" {
void TWindowSubComCardList__sub_80275360(TWindowSubComCardList *list) {
    TWindowSubComCard *card;
    s32 n;
    s32 index;
    s32 msg;

    list->reset_entries();
    index = ((TWindowSubStatusDisp *)list->m_8c)->get_type();
    index *= 7;
    for (n = 0; n < 7; n++, index++) {
        if (index >= (s32)list->m_98) {
            break;
        }
        if (list->m_90 != 0) {
            card = (TWindowSubComCard *)(list->m_90 + index * 0x90);
        } else if (list->m_94 != 0) {
            card = (TWindowSubComCard *)(list->m_94 + index * 0x100);
        } else {
            return;
        }
        if (card->is_active() == 0) {
            break;
        }
        forward_trade_action_default__16TObjCityMainWarpFPviii(list, (int)get_com_card_list__6TLobbyFPv(card), 7, index);
    }
    if (list->get_field_72() <= 0) {
        switch ((s8)list->m_9c) {
        case 0:
            msg = (s32)TWindowSubStatusDisp::get_message_10(0xD4);
            break;
        case 1:
            msg = (s32)TWindowSubStatusDisp::get_message_10(0xD2);
            break;
        }
        TWindowSubComCard::draw_text_gray((s32)list, msg, 4, -1);
    }
}
}
