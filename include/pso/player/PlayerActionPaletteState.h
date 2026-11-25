#ifndef PSO_PLAYER_PLAYERACTIONPALETTESTATE_H
#define PSO_PLAYER_PLAYERACTIONPALETTESTATE_H

#include "pso/ui/window/ActionPaletteTag.h"

// The player's action palette selection (TObjPlayer::action_palette_state):
// the tag's mode/slot pick the palette entry the player last used.
struct PlayerActionPaletteState {
    u32 disabled_slots;  // bit n blocks palette slot n
    ActionPaletteTag tag;

    PlayerActionPaletteState();
    virtual ~PlayerActionPaletteState();
    void init_tag();
    u8 get_mode() const;
    u8 get_slot() const;
    void set_mode(u8 mode);
    void set_slot(u8 slot);
    s32 is_slot_enabled(s32 slot);
    void enable_all_slots();
    void enable_slot(s32 slot);
    void disable_slot(s32 slot);
};

LAYOUT_ASSERT(PlayerActionPaletteTagOffset, offsetof(PlayerActionPaletteState, tag) == 4);

#endif
