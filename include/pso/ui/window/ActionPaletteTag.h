#ifndef PSO_UI_WINDOW_ACTIONPALETTETAG_H
#define PSO_UI_WINDOW_ACTIONPALETTETAG_H

#include <stddef.h>
#include "pso/player/TPlyGuildCardTag.h"

// Cursor and palette records share this four-byte tag prefix.
typedef gc_tag ActionPaletteTag;
LAYOUT_ASSERT(ActionPaletteTagSize, sizeof(ActionPaletteTag) == 4);
LAYOUT_ASSERT(ActionPaletteTagModeOffset, offsetof(ActionPaletteTag, tag0) == 0);
LAYOUT_ASSERT(ActionPaletteTagSlotOffset, offsetof(ActionPaletteTag, tag1) == 1);

extern "C" {
u8 get_action_palette_tag_slot(const ActionPaletteTag *tag);
u8 get_action_palette_tag_mode(const ActionPaletteTag *tag);
void set_action_palette_tag_slot(ActionPaletteTag *tag, u8 slot);
void set_action_palette_tag_mode(ActionPaletteTag *tag, u8 mode);
}
int matches_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled);
int check_type_and_enabled(const ActionPaletteTag *tag, u8 type, u8 enabled);

#endif
