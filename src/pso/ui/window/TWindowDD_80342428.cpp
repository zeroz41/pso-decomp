#include "pso/ui/window/TWindowDD_80341A08.h"
#include "types.h"
#include "pso/ui/window/TWindowDD_80342428.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);
s32 TWindowDD__sub_803484C4(void *);

void TWindowDD__sub_80342428(u8 *window_dd) {
  u8 *new_var;
  TWindowDD__sub_80347C50();
  ((TWindowDD *)window_dd)->update_selection_state();
  if (((TWindowDD *)window_dd)->test_input_flag_4())
  {
    TWindowDD::play_sound();
    if (((s32) (*((s32 *) (((s8 *) window_dd) + 0xB0)))) == 0xA)
    {
      new_var = window_dd;
      new_var = new_var + ((*((s32 *) (((s8 *) window_dd) + 0x20))) * 4);
      if (static_cast<s16>(TWindowDD__sub_80342158(*reinterpret_cast<TWindowDD_WS_Word **>(new_var + 0x24))) == 0x685)
      {
        *((s32 *) (((s8 *) window_dd) + 0xB4)) = 0x14;
        ((TWindowDD *)window_dd)->m_8c = -0x3C;
        TWindowDD__sub_803435A0((void *) window_dd);
        return;
      }
      TWindowDD__sub_803484C4((void *) window_dd);
      return;
    }
    TWindowDD__sub_803484C4((void *) window_dd);
    return;
  }
  if (TWindowDD__sub_803482B0((void *) window_dd) != 0)
  {
    TWindowDD::play_se();
    TWindowDD::apply_entry_layout((void *) window_dd);
  }
}

}
