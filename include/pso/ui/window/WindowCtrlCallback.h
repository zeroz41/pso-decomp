#ifndef PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H
#define PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H

#include "types.h"
struct TWindowCtrl;
typedef void (TWindowCtrl::*PlayerWindowCommand)();
typedef s32 (TWindowCtrl::*PlayerWindowQuery)();

typedef char PlayerWindowCommandSize[sizeof(PlayerWindowCommand) == 0xC ? 1 : -1];
typedef char PlayerWindowQuerySize[sizeof(PlayerWindowQuery) == 0xC ? 1 : -1];

extern "C" {
void call_window_method__11TWindowCtrlFPvi(s32 client_id, PlayerWindowCommand command);
s32 TWindowCtrl__sub_8024B098(s32 client_id, PlayerWindowQuery query);
}

#endif
