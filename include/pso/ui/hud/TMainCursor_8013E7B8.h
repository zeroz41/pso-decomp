#ifndef PSO_UI_HUD_TMAINCURSOR_8013E7B8_H
#define PSO_UI_HUD_TMAINCURSOR_8013E7B8_H

#include "types.h"

class LockOnTargetPart;

extern "C" {
void deactivate_action_channel(void *p);
u8 get_cursor_palette_mode(void *p);
void set_target_part(LockOnTargetPart *target, u16 part, s32 index, s32 flag);
void activate_action_channel(void *p);
void set_cursor_slot(void *p, u8 v);
void set_cursor_mode(void *p, u8 v);
}


#endif
