#include "types.h"
#include "pso/unk/text_8036A3CC.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/misc/TWindowSubComCard.h"

extern "C" {

s32 forward_trade_action_default__16TObjCityMainWarpFPviii(s32, s32, s32, s32);
s32 set_flag70_bit100__21TWindowSubComCardListFv();
s32 align_menu_entry_positions(s32);
s32 draw_text_gray__17TWindowSubComCardFllll(s32, s32 *, s32, s32);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);

extern s32 lbl_8044F4AC[];
extern const f32 lbl_805DD268;
extern const f32 lbl_805DD26C;

s32 TWindowOptionCtrl::create_list_window() {
    s32 idx;
    s32 list;

    fn_8036A514(2);
    list = check_room_seq_4__16TAdChrSelASlotGCFl(get_option_entry__17TWindowOptionCtrlFi(0xCF), 0x31);
    set_flag70_bit100__21TWindowSubComCardListFv();
    idx = 0;
    do {
        if (fn_8036A620(idx) != 0) {
            if (check_flag_index_set(idx) == 0) {
                draw_text_gray__17TWindowSubComCardFllll(list, lbl_8044F4AC, 0x26, idx);
            } else {
                forward_trade_action_default__16TObjCityMainWarpFPviii(list, get_option_table_entry(idx), 0x26, idx);
            }
        }
        idx += 1;
    } while (idx < 0x31);
    ((TWindowOptionCtrl *)list)->set_flag70_bit400();
    ((TWindowSubComCardList *)list)->set_scroll_target(lbl_805DD268, lbl_805DD26C);
    align_menu_entry_positions(list);
    return list;
}

}
