#include "types.h"
#include "pso/misc/TWindowSubComCard_802A5748.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/TChCrTagPlBack.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/object/TObjCityMainWarp.h"
#include "pso/ui/TAdChrSelASlotGC.h"
#include "pso/quest/TQuestThread.h"

extern "C" {
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
s32 create_window_menu(s32, s32, s32);
s32 get_selected_menu_value(s32);
int queue_destruction__7TObjectFv(void*);
int set_selected_index__21TWindowSubComCardListFs(void*);

int TWindowSubComCard::close() { return queue_destruction__7TObjectFv(this); }
void TWindowSubComCard::free_member() { void* m = *(void* *)&this->m_2c; if (m) set_selected_index__21TWindowSubComCardListFs(m); }
s32 TWindowSubComCard::get_slot_or_neg1() {
    s32 v = this->m_2c;
    if ((u32) v == 0U) {
        return -1;
    }
    return get_selected_menu_value(v);
}
s32 TWindowSubComCard::get_card_data() {
    s32 v = this->m_2c;
    if ((u32) v == 0U) {
        return 0;
    }
    return ((TWindowSubComCard *)v)->get_status_flag();
}

s32 TWindowMessageYesNo::is_child_visible() {
    if ((u32) this->m_2c == 0U) {
        return 0;
    }
    return ((TWindowMenu *)(this->m_2c))->is_visible();
}
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void initialize_option_dialog(void *arg0, s32 arg1, s32 arg2, f32 farg0) {
    *(s32 *)((s8 *)arg0 + 0x28) = create_window_menu(arg2, 1, *(s32 *)((s8 *)arg0 + 0x24));
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(s32 *)((s8 *)arg0 + 0x28)), (int)arg1, 0x21, 0);
    ((TAdChrSelASlotGC *)(*(s32 *)((s8 *)arg0 + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)(*(s32 *)((s8 *)arg0 + 0x28)));
    ((TWindowSubComCard *)(*(s32 *)((s8 *)arg0 + 0x28)))->calc_layout_height(farg0);
}

void open_yes_no_prompt(TChCrTagPlBack *ch_cr_tag_pl_back, u32 arg1, s32 arg2, s32 arg3, f32 farg0) {
    s32 sp8;
    if (arg1 == 0U) {
        *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28) = create_window_menu(arg3, 1, *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24));
    } else {
        *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28) = (long) (create_titled_window_menu(arg3, 1, arg1, *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24)));
    }
    forward_trade_action_default__16TObjCityMainWarpFPviii(((void *) *(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28)), (arg2), 0x21, 0);
    ((TAdChrSelASlotGC *)(*(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28)))->set_flag_40();
    TQuestThread::set_status_flag_80((void *)((int) (*(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28))));
    ((TWindowSubComCard *)(*(s32 *)((s8 *)ch_cr_tag_pl_back + 0x28)))->calc_layout_height(farg0);
    ch_cr_tag_pl_back->get_position_offset(&sp8);
    *(u8 **)((s8 *)ch_cr_tag_pl_back + 0x2C) = create_yes_no_window((s32)&sp8, (s32)(*(s32 *)((s8 *)ch_cr_tag_pl_back + 0x24)), (u32)(*(u8 **)((s8 *)ch_cr_tag_pl_back + 0x20)), (u32)(*(u32 *)((s8 *)ch_cr_tag_pl_back + 0x1C)));
}
