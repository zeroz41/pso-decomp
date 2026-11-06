#include "types.h"
#include "pso/player/TPlyGuildCardTag_8013ABCC.h"
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Big_801E0198 { s32 w[17]; };

struct Blk_801E0198 { s32 d; Big_801E0198 b; };

struct Pair_801E0198 { u8 bytes[8]; };

struct Tag_801E0198 { u8 b[8]; };

struct TUserAns_801E0198 {
    s32 a;
    Tag_801E0198 tag;
    s32 c;
    Pair_801E0198 p;
    Blk_801E0198 blk;
    u8 rest[0x20];
};

extern "C" {
void *fn_801DF61C(void *, void *);
TUserAns_801E0198 *__ct__8TUserAnsFRC8TUserAns(TUserAns_801E0198 *dst, TUserAns_801E0198 *src);
TUserAns_801E0198 *__ct__8TUserAnsFRC8TUserAns(TUserAns_801E0198 *dst, TUserAns_801E0198 *src) {
    dst->a = src->a;
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&dst->tag, &src->tag);
    dst->c = src->c;
    dst->p = src->p;
    dst->blk = src->blk;
    fn_801DF61C(&dst->rest, &src->rest);
    return dst;
}

}

struct packet_header { u8 command; u8 flags; u16 size; void bswap(); };
class TPlyGuildCardTag { public: static void bswap_lobby_entry(void *); };
class LobbyListEntry { public: u8 tag[8]; u32 smth; };
template <typename T, int num_entries, int num_pad_entries> class TMenuList;
template <> class TMenuList<LobbyListEntry, 16, 0> {
public:
    void bswap();
    packet_header header;
    LobbyListEntry entries[16];
};
void TMenuList<LobbyListEntry, 16, 0>::bswap() {
    header.bswap();
    for (int i = 0; i < 16; i++) {
        TPlyGuildCardTag::bswap_lobby_entry(&entries[i]);
    }
}
