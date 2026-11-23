#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowSubComCard_802A5748.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/charcreate/TChCrTagPlBack.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/task/TObject.h"

extern "C" {
saddr forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, saddr a1, saddr a2, int a3);


void TWindowSubComCard::close() { queue_destruction(); }
void TWindowMessageYesNo::set_menu_selected_index(s16 index) { if (choice_menu) ((TWindowSubComCardList *)choice_menu)->set_selected_index(index); }
s32 TWindowSubComCard::get_slot_or_neg1() {
    saddr v = this->m_2c;
    if ((u32) v == 0U) {
        return -1;
    }
    return ((TWindowMenu *)v)->get_selected_value();
}
s32 TWindowSubComCard::get_card_data() {
    saddr v = this->m_2c;
    if ((u32) v == 0U) {
        return 0;
    }
    return ((TWindowMenu *)v)->is_cancelled();
}

s32 TWindowMessageYesNo::is_child_visible() {
    if (choice_menu == NULL) {
        return 0;
    }
    return choice_menu->is_decided();
}
}
saddr create_titled_window_menu(saddr position, s32 count, saddr title, s32 client_id);
void initialize_option_dialog(void *arg0, s32 message, s32 position, f32 width) {
    *(s32 *)((s8 *)arg0 + 0x28) = (saddr)create_window_menu((saddr)(position), 1, *(s32 *)((s8 *)arg0 + 0x24));
    TObjCityMainWarp::forward_trade_action_default((void *)(*(saddr *)((s8 *)arg0 + 0x28)), (int)message, 0x21, 0);
    ((TAdChrSelASlotGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)(*(saddr *)((s8 *)arg0 + 0x28)));
    ((TWindowSubComCard *)(*(saddr *)((s8 *)arg0 + 0x28)))->calc_layout_height(width);
}

void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, s32 position_id, f32 width) {
    NJS_POINT2 position;
    if (title == 0U) {
        dialog->m_28 = reinterpret_cast<uaddr>(create_window_menu(position_id, 1, dialog->client_id));
    } else {
        dialog->m_28 = static_cast<uaddr>(create_titled_window_menu(position_id, 1, title, dialog->client_id));
    }
    TObjCityMainWarp::forward_trade_action_default(reinterpret_cast<void *>(dialog->m_28), text, 0x21, 0);
    reinterpret_cast<TAdChrSelASlotGC *>(dialog->m_28)->set_flag_40();
    TQuestThread::set_status_flag_80(reinterpret_cast<void *>(dialog->m_28));
    reinterpret_cast<TWindowSubComCard *>(dialog->m_28)->calc_layout_height(width);
    reinterpret_cast<TChCrTagPlBack *>(dialog)->get_position_offset(&position);
    dialog->choice_menu = create_yes_no_window(&position, dialog->client_id,
                                              reinterpret_cast<const char *>(dialog->m_20),
                                              reinterpret_cast<const char *>(dialog->m_1c));
}
