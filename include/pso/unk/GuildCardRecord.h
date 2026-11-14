#ifndef PSO_UNK_GUILDCARDRECORD_H
#define PSO_UNK_GUILDCARDRECORD_H

#include "types.h"

// inferred: one com-card list record (0xBC bytes). TLobby keeps the selected card and an
// 8-entry list; serial comes from a running counter (init_player_entry__6TLobbyFPvPv).
struct GuildCardRecord {
    s32 id;
    s32 serial;
    char name[0x11];
    char s19[0x11];
    char s2A[0x11];
    char s3B[0x11];
    u8 f4C[0xC];
    u8 ext[0x64];

    GuildCardRecord();
    s32 get_serial() const;
};

#endif
