#ifndef PSO_UI_HUD_TMAINCURSOR_8013E7B8_H
#define PSO_UI_HUD_TMAINCURSOR_8013E7B8_H

#include "types.h"

extern "C" {
void TMainCursor__sub_8013E8A0(void *p);
u8 get_cursor_palette_mode(void *p);
s16 get_action_entry_index(void *p);
void set_action_entry_index(void *p, s16 v);
void set_action_entry_priority(void *p, s16 v);
void set_target_part(u8 *arg0, u16 arg1, s32 arg2, s32 arg3);
void TMainCursor__sub_8013E9A0(void *p);
void set_cursor_slot(void *p, u8 v);
void set_cursor_mode(void *p, u8 v);
void set_cursor_count(void *p, s32 v);
void copy_target_record__11TMainCursorFPvPv(u8 *arg0, u8 *arg1);
}


#endif
