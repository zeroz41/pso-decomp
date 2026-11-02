#include "types.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/unk/text_8034CEDC.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjCityMainWarp.h"
extern "C" {
s32 align_menu_entry_positions(int);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 draw_card_icon__17TWindowSubComCardFll(int, int, int);
s32 get_window_layout_position(int);
s32 create_info_board_menu(void) {
  s32 temp_r31;
  temp_r31 = draw_card_icon__17TWindowSubComCardFll((int) get_window_layout_position(0xA4), 2, (int) ((0, TWindowSubStatusDisp::get_message_10(0x1D))));
  if (get_main_phase() == 0xF)
  {
    forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) TWindowSubStatusDisp::get_message_10(0x117)), 6, 3);
  }
  else
  {
    TWindowSubComCard::draw_text_gray((int) temp_r31, (int) TWindowSubStatusDisp::get_message_10(0x117), 6, 3);
  }
  forward_trade_action_default__16TObjCityMainWarpFPviii((void *)temp_r31, (int)((int) TWindowSubStatusDisp::get_message_10(0x118)), 6, 9);
  ((TWindowSubComCardList *)temp_r31)->set_flag70_bit10();
  ((TWindowSubComCardList *)temp_r31)->update_layout_height(179.0f);
  align_menu_entry_positions((int) temp_r31);
  return temp_r31;
}

}
