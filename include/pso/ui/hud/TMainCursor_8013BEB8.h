#ifndef PSO_UI_HUD_TMAINCURSOR_8013BEB8_H
#define PSO_UI_HUD_TMAINCURSOR_8013BEB8_H

#include "types.h"

extern "C" {
struct CsnHit *is_target_obstructed(class LockOnActionSlot *unused, const Vec *to, const Vec *from);
s32 is_active_channel_matching(saddr cursor, u8 type, u8 enabled);
}

#endif
