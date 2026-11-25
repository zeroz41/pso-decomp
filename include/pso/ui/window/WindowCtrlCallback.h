#ifndef PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H
#define PSO_UI_WINDOW_WINDOWCTRLCALLBACK_H

#include "types.h"
struct TWindowCtrlPlayer;
typedef void (TWindowCtrlPlayer::*PlayerWindowCommand)();
typedef s32 (TWindowCtrlPlayer::*PlayerWindowQuery)();

LAYOUT_ASSERT(PlayerWindowCommandSize, sizeof(PlayerWindowCommand) == 0xC);
LAYOUT_ASSERT(PlayerWindowQuerySize, sizeof(PlayerWindowQuery) == 0xC);

#endif
