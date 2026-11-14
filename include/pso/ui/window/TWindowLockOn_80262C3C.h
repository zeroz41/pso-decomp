#ifndef PSO_UI_WINDOW_TWINDOWLOCKON_80262C3C_H
#define PSO_UI_WINDOW_TWINDOWLOCKON_80262C3C_H

#include "types.h"

struct TWindowLockOn;
// Constructor and destructor stay free functions until the TWindowBase constructor and
// destructor (TWindowDD::construct_base, TWindowDD::destroy_window_base) carry their real names.
extern "C" {
u8 *TWindowLockOn__ct(TWindowLockOn *self, s32 player, u16 id);
void *__dt__13TWindowLockOnFv(void *self, s16 flags);
}

#endif
