#ifndef PSO_UNK_TLOBBY_8006F278_H
#define PSO_UNK_TLOBBY_8006F278_H

#include "types.h"

extern "C" {
s32 TLobby__sub_8006F38C(s32 total);
void TLobby__sub_8006F48C(void);
s32 TLobby__sub_8006F5B0(saddr clear_time);
u16 TLobby__sub_8006FAE4(void);
s32 TLobby__sub_8006FBE4(void);
s32 decode_slot__6TLobbyFUi(u32 id);
s32 is_id_out_of_range__6TLobbyFi(s32 arg0);
s32 mix_seed__6TLobbyFUs(u16 arg0);
s32 mix_seed_checked__6TLobbyFi(s32 seed);
}

// Decodes a stored name (each byte is the running sum of the previous ones
// xored with 0x7F) into dst, at most length - 1 characters plus a terminator.
void decode_obfuscated_string(char *dst, const void *src, int length);

// lobby_name_string_buffer: layout known from its uses only.
struct LobbyNameStringBuffer { s32 value; u8 remaining[0x1C]; };
extern LobbyNameStringBuffer lobby_name_string_buffer;

struct ChallengePhaseView {
    u8 pad0[0x28];
    s32 phase;
};

struct ChallengeStageEntry {
    char key[12];
    char name[12];
    s32 id;
};

struct ChallengeStageTableView {
    u8 pad0[0x18];
    s32 defaultId;
    s32 count;
    u8 pad20[0x30];
    char defaultName[12];
    ChallengeStageEntry entries[1];
};

struct ChallengeRankEntry {
    s32 value;
    u32 mask;
    u8 pad[0x14];
};

struct ChallengeRankTableView {
    u8 pad[0x21C];
    ChallengeRankEntry entries[3];
};

#endif
