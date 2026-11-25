#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803435A0(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 TWindowDD__sub_803484C4(void *);

void TWindowDD__sub_80342428(TWindowDD *window_dd) {
  refresh_word_select_child_list();
  window_dd->update_selection_state();
  if (window_dd->test_input_flag_4())
  {
    TWindowDD::play_sound();
    if (window_dd->state == 0xA)
    {
      if (static_cast<s16>(window_dd->pages[window_dd->depth]->get_selected_id()) == 0x685)
      {
        window_dd->next_state = 0x14;
        window_dd->list_ids[1] = -0x3C;
        TWindowDD__sub_803435A0(window_dd);
        return;
      }
      TWindowDD__sub_803484C4(window_dd);
      return;
    }
    TWindowDD__sub_803484C4(window_dd);
    return;
  }
  if (is_word_select_cancel_input(window_dd) != 0)
  {
    TWindowDD::play_se();
    window_dd->apply_entry_layout();
  }
}
}
