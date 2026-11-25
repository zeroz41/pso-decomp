#ifndef PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H
#define PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H

#include "types.h"

class TWindowChat;

extern "C" {
s32 TWindowCtrl__sub_8024C5C4(const TWindowChat *chat);
bool TWindowCtrl__sub_8024A1A8(void);
void TWindowCtrl__sub_8024A228(saddr client_id);
s32 TWindowCtrl__sub_8024A314(void);
u8 *get_obj_8024A5AC(u16 id);
}

#endif
