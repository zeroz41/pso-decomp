#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"


void TWindowDD::handle_final_word_state() {
  refresh_word_select_child_list();
  update_selection_state();
  if (test_input_flag_4())
  {
    TWindowDD::play_sound();
    if (state == 0xA)
    {
      if (static_cast<s16>(word_windows[depth]->get_selected_id()) == 0x685)
      {
        next_state = 0x14;
        list_ids[1] = -0x3C;
        begin_word_select_state();
        return;
      }
      finish_word_select();
      return;
    }
    finish_word_select();
    return;
  }
  if (is_word_select_cancel_input() != 0)
  {
    TWindowDD::play_se();
    apply_entry_layout();
  }
}
