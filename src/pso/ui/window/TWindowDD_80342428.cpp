#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 begin_word_select_state(void *);
s32 refresh_word_select_child_list();
s32 is_word_select_cancel_input(void *);
s32 finish_word_select(void *);

void TWindowDD__sub_80342428(u8 *window_dd) {
  TWindowDD *w = (TWindowDD *)window_dd;
  refresh_word_select_child_list();
  w->update_selection_state();
  if (w->test_input_flag_4())
  {
    TWindowDD::play_sound();
    if (((s32) w->state) == 0xA)
    {
      if (static_cast<s16>(get_word_select_selected_id(reinterpret_cast<TWindowDD_WS_Word *>(w->word_windows[w->depth]))) == 0x685)
      {
        w->next_state = 0x14;
        w->m_8c = -0x3C;
        begin_word_select_state((void *) window_dd);
        return;
      }
      finish_word_select((void *) window_dd);
      return;
    }
    finish_word_select((void *) window_dd);
    return;
  }
  if (is_word_select_cancel_input((void *) window_dd) != 0)
  {
    TWindowDD::play_se();
    TWindowDD::apply_entry_layout((void *) window_dd);
  }
}

}
