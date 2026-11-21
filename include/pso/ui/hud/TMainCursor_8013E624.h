#ifndef PSO_UI_HUD_TMAINCURSOR_8013E624_H
#define PSO_UI_HUD_TMAINCURSOR_8013E624_H

#include "pso/ui/window/ActionPaletteTag.h"
#include "types.h"

struct TMainCursor;

extern "C" {
void TMainCursor__sub_8013E694(void *p, s16 v);
void set_cursor_action_palette_mode(TMainCursor *cursor, u8 mode);
void set_cursor_palette_slot(ActionPaletteTag *tag, u8 slot);
void set_cursor_palette_mode(ActionPaletteTag *tag, u8 mode);
}

#endif
