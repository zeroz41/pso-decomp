#ifndef PSO_UI_WINDOW_ACTIONPALETTETAG_H
#define PSO_UI_WINDOW_ACTIONPALETTETAG_H

#include <stddef.h>
#include "pso/player/TPlyGuildCardTag.h"

// Cursor and palette records share this four-byte tag prefix.
typedef gc_tag ActionPaletteTag;
typedef char ActionPaletteTagSize[sizeof(ActionPaletteTag) == 4 ? 1 : -1];
typedef char ActionPaletteTagModeOffset[offsetof(ActionPaletteTag, tag0) == 0 ? 1 : -1];
typedef char ActionPaletteTagSlotOffset[offsetof(ActionPaletteTag, tag1) == 1 ? 1 : -1];

extern "C" {
u8 get_action_palette_tag_slot(const ActionPaletteTag *tag);
u8 get_action_palette_tag_mode(const ActionPaletteTag *tag);
void set_action_palette_tag_slot(ActionPaletteTag *tag, u8 slot);
void set_action_palette_tag_mode(ActionPaletteTag *tag, u8 mode);
}

#endif
