#include "types.h"
#include "pso/misc/TWindowSubComCardList.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowShortListCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
extern "C" {
volatile char get_type__20TWindowSubStatusDispFv(void *);
extern s32 actor_frame_tick;
void TWindowSubComCardList::draw_card_list_selection(u8 *window_key_board_soft) {
  s16 temp_r0;
  u16 *array_entry;
  if (!(actor_frame_tick & 0x10))
  {
    temp_r0 = (this->get_selected_index()) - (get_type__20TWindowSubStatusDispFv(*((u8 **) (((s8 *) ((u8 *)this)) + 0x8C))) * 7);
    if ((temp_r0 >= 0) && (temp_r0 < 7))
    {
      array_entry = (u16 *) this->get_array_entry((s32) temp_r0);
      if ((*array_entry) & 1)
      {
        draw_selection_bar(window_key_board_soft, (u8 *)array_entry, 1);
      }
    }
  }
}
}
