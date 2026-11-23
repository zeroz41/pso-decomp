#ifndef PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H
#define PSO_UI_WINDOW_TWINDOWCTRL_8024A1A8_H

#include "types.h"

class TWindowChat;

extern "C" {
s32 TWindowCtrl__sub_8024C5C4(const TWindowChat *chat);
void TLobby__sub_8024AAA0(s32 local_client_id, s32 arg1);
bool TWindowCtrl__sub_8024A1A8(void);
void TWindowCtrl__sub_8024A228(saddr client_id);
s32 TWindowCtrl__sub_8024A314(void);
u8 *get_obj_8024A5AC(u16 id);
}

#endif
