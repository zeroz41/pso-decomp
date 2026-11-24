#ifndef PSO_PLAYER_PLAYERCHARDATAENTRY_H
#define PSO_PLAYER_PLAYERCHARDATAENTRY_H

#include "types.h"
#include "pso/macros.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/data/FlagWord.h"

// One of the 12 characters kept for the player slots (TObjPlayer__char_data_array);
// TObjPlayer::create builds the slot's player from it.
struct PlayerCharDataEntry {
    s32 role;              // the control role the player is created with
    u8 lobby_header[8];    // copied into the created player (TLobby::copy_header_struct)
    TPlyCharData char_data;
    FlagWord flags;        // bit 0: the slot holds a character
};

LAYOUT_ASSERT(PlayerCharDataEntrySize, sizeof(PlayerCharDataEntry) == 0x42C);

extern PlayerCharDataEntry TObjPlayer__char_data_array[12];

#endif
