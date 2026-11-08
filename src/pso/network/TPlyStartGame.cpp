#include "types.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/network/TPlyStartGame.h"
#include "pso/unk/text_801E051C.h"
#include "pso/system/byteswap.h"

typedef struct TPlyStartGame_801E0580 {
    u32 header;
    u8 entries[4][0x20];
    u8 extension[0x64];
} TPlyStartGame_801E0580;

extern "C" {
void bswap__13packet_headerFv(void *);
void bswap__13TPlyStartGameFv(TPlyStartGame_801E0580 *self);
void copy_game_list_entry(void *, const void *);
int bswap__16TPlyGuildCardTagFv(void*);
s32 copy_ply_meet_user_extension(void *, void *);

void bswap__13TPlyStartGameFv(TPlyStartGame_801E0580 *self) {
    int i;
    bswap__13packet_headerFv(self);
    for (i = 0; i < 4; i++) {
        bswap__13TPlyStartGameFPv(self->entries[i]);
    }
    bswap__21TPlyMeetUserExtensionFv((s32)self->extension);
}

void bswap__13TPlyStartGameFPv(void* p) { bswap__16TPlyGuildCardTagFv(p); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }

u8 *__ct__13TPlyStartGameFRC13TPlyStartGame(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    copy_player_lobby_data_entry(arg0 + 4, arg1 + 4);
    copy_player_lobby_data_entry(arg0 + 0x24, arg1 + 0x24);
    copy_player_lobby_data_entry(arg0 + 0x44, arg1 + 0x44);
    copy_player_lobby_data_entry(arg0 + 0x64, arg1 + 0x64);
    copy_ply_meet_user_extension(arg0 + 0x84, arg1 + 0x84);
    *(u8 *)((s8 *)arg0 + 0xE8) = (u8) *(u8 *)((s8 *)arg1 + 0xE8);
    *(u8 *)((s8 *)arg0 + 0xE9) = (u8) *(u8 *)((s8 *)arg1 + 0xE9);
    *(u8 *)((s8 *)arg0 + 0xEA) = (u8) *(u8 *)((s8 *)arg1 + 0xEA);
    *(u8 *)((s8 *)arg0 + 0xEB) = (u8) *(u8 *)((s8 *)arg1 + 0xEB);
    return arg0;
}

}

struct GameListEntry {
    u8 data[0x1C];
};

template <class T, int N, int M> struct TMenuList;
template <> struct TMenuList<GameListEntry, 64, 1> {
    u32 header;
    GameListEntry head[1];
    GameListEntry entries[64];
    void bswap();
    TMenuList(const TMenuList &o);
};

void TMenuList<GameListEntry, 64, 1>::bswap() {
    bswap__13packet_headerFv(this);
    bswap_game_list_entry(&head[0]);
    for (int i = 0; i < 64; i++) {
        bswap_game_list_entry(&entries[i]);
    }
}

int bswap_game_list_entry(void* p) { return bswap__16TPlyGuildCardTagFv(p); }

TMenuList<GameListEntry, 64, 1>::TMenuList(const TMenuList &o) {
    header = o.header;
    GameListEntry *p;
    const GameListEntry *q;
    copy_game_list_entry(&head[0], &o.head[0]);
    p = entries;
    q = o.entries;
    do {
        copy_game_list_entry(p, q);
        p++;
        q++;
    } while (p < entries + 64);
}
