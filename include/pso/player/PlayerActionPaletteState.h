#ifndef PSO_PLAYER_PLAYERACTIONPALETTESTATE_H
#define PSO_PLAYER_PLAYERACTIONPALETTESTATE_H

#include "pso/ui/window/ActionPaletteTag.h"

// The player's action palette selection (TObjPlayer::action_palette_state):
// the tag's mode/slot pick the palette entry the player last used.
struct PlayerActionPaletteState {
    u32 prefix;
    ActionPaletteTag tag;

    PlayerActionPaletteState();
    virtual ~PlayerActionPaletteState();
    void init_tag();
};

LAYOUT_ASSERT(PlayerActionPaletteTagOffset, offsetof(PlayerActionPaletteState, tag) == 4);

extern "C" {
u8 get_player_action_palette_slot(const PlayerActionPaletteState *state);
u8 get_player_action_palette_mode(const PlayerActionPaletteState *state);
void set_player_action_palette_slot(PlayerActionPaletteState *state, u8 slot);
void set_player_action_palette_mode(PlayerActionPaletteState *state, u8 mode);
}

#endif
