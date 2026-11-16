#ifndef PSO_UI_WINDOW_TWINDOWLOCKON_80262C3C_H
#define PSO_UI_WINDOW_TWINDOWLOCKON_80262C3C_H

#include "types.h"

struct TWindowLockOn;
// The constructor stays a free function until the TWindowBase constructor
// (TWindowDD::construct_base) carries its real name.
extern "C" {
u8 *TWindowLockOn__ct(TWindowLockOn *self, s32 player, u16 id);
}

#endif
