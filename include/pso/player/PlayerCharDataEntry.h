#ifndef PSO_PLAYER_PLAYERCHARDATAENTRY_H
#define PSO_PLAYER_PLAYERCHARDATAENTRY_H

#include "types.h"
#include "pso/macros.h"
#include "pso/player/PlayerGuildCardTag.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/data/FlagWord.h"

class TObjPlayer;

// One of the 12 characters kept for the player slots (TObjPlayer::char_data_array);
// TObjPlayer::create builds the slot's player from it.
struct PlayerCharDataEntry {
    PlayerCharDataEntry();
    ~PlayerCharDataEntry() {}
    int has_character();
    PlayerGuildCardTag *get_lobby_header();
    TPlyCharData *get_char_data();
    s32 get_role();
    void clear();
    // Takes the role, guild card tag and character data of player.
    void copy_from_player(TObjPlayer *player);

    s32 role;              // the control role the player is created with
    PlayerGuildCardTag lobby_header;  // copied into the created player (TLobby::copy_header_struct)
    TPlyCharData char_data;
    FlagWord flags;        // bit 0: the slot holds a character
};

LAYOUT_ASSERT(PlayerCharDataEntrySize, sizeof(PlayerCharDataEntry) == 0x42C);

#endif
