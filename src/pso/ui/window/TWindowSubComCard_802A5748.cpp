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
u8 *create_yes_no_window(s32 arg0, s32 arg1, uaddr arg2, uaddr arg3);

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
saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr arg2, s32 arg3);
void initialize_option_dialog(void *arg0, s32 message, s32 position, f32 farg0) {
    *(s32 *)((s8 *)arg0 + 0x28) = (saddr)create_window_menu((saddr)(position), 1, *(s32 *)((s8 *)arg0 + 0x24));
    TObjCityMainWarp::forward_trade_action_default((void *)(*(saddr *)((s8 *)arg0 + 0x28)), (int)message, 0x21, 0);
    ((TAdChrSelASlotGC *)(*(saddr *)((s8 *)arg0 + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)(*(saddr *)((s8 *)arg0 + 0x28)));
    ((TWindowSubComCard *)(*(saddr *)((s8 *)arg0 + 0x28)))->calc_layout_height(farg0);
}

void open_yes_no_prompt(TChCrTagPlBack *ch_cr_tag_pl_back, u32 arg1, s32 text, s32 arg3, f32 width) {
    s32 sp8;
    if (arg1 == 0U) {
        *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28) = (saddr)create_window_menu((saddr)(arg3), 1, *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24));
    } else {
        *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28) = (long) (create_titled_window_menu(arg3, 1, arg1, *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24)));
    }
    TObjCityMainWarp::forward_trade_action_default(((void *) *(saddr *)((s8 *)ch_cr_tag_pl_back + 0x28)), (text), 0x21, 0);
    ((TAdChrSelASlotGC *)(*(saddr *)((s8 *)ch_cr_tag_pl_back + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)((saddr) (*(saddr *)((s8 *)ch_cr_tag_pl_back + 0x28))));
    ((TWindowSubComCard *)(*(saddr *)((s8 *)ch_cr_tag_pl_back + 0x28)))->calc_layout_height(width);
    ch_cr_tag_pl_back->get_position_offset(&sp8);
    reinterpret_cast<TWindowMessageYesNo *>(ch_cr_tag_pl_back)->choice_menu =
        reinterpret_cast<TWindowMenu *>(create_yes_no_window((saddr)&sp8, (s32)(*(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24)), (uaddr)(*(u8 **)((s8 *)ch_cr_tag_pl_back + 0x20)), (u32)(*(u32 *)((s8 *)ch_cr_tag_pl_back + 0x1C))));
}
