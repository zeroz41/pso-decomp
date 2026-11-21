#ifndef PSO_PLAYER_PLAYERACTIONPALETTESTATE_H
#define PSO_PLAYER_PLAYERACTIONPALETTESTATE_H

#include "pso/ui/window/ActionPaletteTag.h"

// Borrowed view of the record stored at player offset 0x340.
struct PlayerActionPaletteState {
    u32 prefix;
    ActionPaletteTag tag;
};

LAYOUT_ASSERT(PlayerActionPaletteTagOffset, offsetof(PlayerActionPaletteState, tag) == 4);

extern "C" {
u8 get_player_action_palette_slot(const PlayerActionPaletteState *state);
u8 get_player_action_palette_mode(const PlayerActionPaletteState *state);
void set_player_action_palette_slot(PlayerActionPaletteState *state, u8 slot);
void set_player_action_palette_mode(PlayerActionPaletteState *state, u8 mode);
}

#endif
