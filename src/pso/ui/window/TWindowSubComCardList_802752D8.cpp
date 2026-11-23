#include "pso/ui/window/PageIndicator.h"
#include "types.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowShortListCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"


extern s32 actor_frame_tick;
void TWindowSubComCardList::draw_card_list_selection(u8 *window_key_board_soft) {
  s16 page_row;
  u16 *array_entry;
  if (!(actor_frame_tick & 0x10))
  {
    page_row = (this->get_selected_index()) - (storage->get_type() * 7);
    if ((page_row >= 0) && (page_row < 7))
    {
      array_entry = (u16 *) this->get_array_entry((s32) page_row);
      if ((*array_entry) & 1)
      {
        draw_selection_bar(reinterpret_cast<WindowDrawContext *>(window_key_board_soft), (u8 *)array_entry, 1);
      }
    }
  }
}
