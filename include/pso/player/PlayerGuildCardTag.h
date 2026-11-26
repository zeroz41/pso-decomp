#ifndef PSO_PLAYER_PLAYERGUILDCARDTAG_H
#define PSO_PLAYER_PLAYERGUILDCARDTAG_H

#include "types.h"

// The guild card tag a player carries (tag triplet + guild card number, laid out like
// TPlyGuildCardTag): TObjPlayer::guild_card_tag, the 6x70 sync record and the player slots
// copy it from the lobby entry. Starts cleared.
struct PlayerGuildCardTag {
    u8 tag0;
    u8 tag1;
    u16 tag2;
    u32 guildcard_number;

    PlayerGuildCardTag();
    void bswap();
};

#endif
