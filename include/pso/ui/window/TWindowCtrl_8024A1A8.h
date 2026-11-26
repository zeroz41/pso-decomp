#ifndef PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H
#define PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H

#include "types.h"

class TWindowChat;

bool is_com_card_window_open(void);
extern "C" {
s32 TWindowCtrl__sub_8024C5C4(const TWindowChat *chat);
s32 is_chat_window_in_use(void);
u8 *get_obj_8024A5AC(u16 id);
}

#endif
