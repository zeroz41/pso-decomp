#include "types.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

extern "C" {
s32 get_localized_text_entry(s32 arg0, s32 arg1);
s32 align_menu_entry_positions(int);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(void *, int);
extern const f32 lbl_805DD268;
s32 TWindowOptionCtrl::create_sub_menu_window() {
    s32 temp_r31;
    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl((void *)(TWindowOptionCtrl::get_option_entry(0xCF)), 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 0x1A)), 6, 0x12);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 0x1B)), 6, 0x14);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 0x1C)), 6, 0x15);
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD268);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

}
