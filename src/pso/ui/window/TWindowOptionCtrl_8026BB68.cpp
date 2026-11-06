#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

extern "C" {

int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 align_menu_entry_positions(s32);
s32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);

extern const f32 lbl_805DD268;

s32 TWindowOptionCtrl::create_menu() {
    s32 temp_r31;

    temp_r31 = check_room_seq_4__16TAdChrSelASlotGCFl(get_option_entry__17TWindowOptionCtrlFi(0xCE), 9);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 0)), 6, 3);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 1)), 6, 7);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 2)), 6, 5);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 3)), 6, 9);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 4)), 6, 0xB);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 5)), 6, 0x10);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 6)), 6, 0x19);
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)(get_localized_text_entry(0xF, 7)), 6, 0x1B);
    ((TWindowSubComCardList *)temp_r31)->update_layout_height(lbl_805DD268);
    align_menu_entry_positions(temp_r31);
    return temp_r31;
}

}
