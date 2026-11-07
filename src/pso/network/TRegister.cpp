#include "types.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TRegister.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/packet_classes.h"

struct ByteBlock_20 { u8 bytes[0x20]; };

struct ByteBlock_70 { u8 bytes[0x70]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
s32 __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
s32 bswap__13packet_headerFv();
int bswap__16TPlyGuildCardTagFv(void*);

void bswap__9TRegisterFv(s32 arg0) {
    bswap__13packet_headerFv();
    bswap_ply_smth_pair((void *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 0xC));
}

s32 __ct__9TRegisterFv(s32 arg0) {
    __ct__8TPlySmthFv((void *)(arg0 + 4));
    return arg0;
}

}

template <unsigned long size> struct TPlyText;
template <> struct TPlyText<288> {
    packet_header header;
    char text[288];
    void bswap();
};
void TPlyText<288>::bswap() {
    header.bswap();
}

class QuestListEntry;
template <typename T, int num_entries, int num_pad_entries> class TMenuList;
template <> class TMenuList<QuestListEntry, 30, 0> {
public:
    TMenuList(const TMenuList &);
    void bswap();
    packet_header header;
    u8 entries[30][sizeof(QuestListEntry)];
};
void TMenuList<QuestListEntry, 30, 0>::bswap() {
    header.bswap();
    for (int i = 0; i < 30; i++) {
        bswap_quest_list_entry(entries[i]);
    }
}

int bswap_quest_list_entry(void* p) { return bswap__16TPlyGuildCardTagFv(p); }

struct PacketHeaderCopy_801E0038 { u8 bytes[sizeof(packet_header)]; };
struct QuestListEntryRaw_801E0038 { u8 bytes[sizeof(QuestListEntry)]; };
TMenuList<QuestListEntry, 30, 0>::TMenuList(const TMenuList &o) {
    QuestListEntryRaw_801E0038 *end;
    QuestListEntryRaw_801E0038 *d;
    const QuestListEntryRaw_801E0038 *s;
    d = (QuestListEntryRaw_801E0038 *)entries;
    s = (const QuestListEntryRaw_801E0038 *)o.entries;
    end = (QuestListEntryRaw_801E0038 *)(entries + 30);
    *(PacketHeaderCopy_801E0038 *)&header = *(const PacketHeaderCopy_801E0038 *)&o.header;
    do {
        __ct__14QuestListEntryFRC14QuestListEntry((s32)d, (s32)s);
        d++;
        s++;
    } while (d < end);
}

s32 __ct__14QuestListEntryFRC14QuestListEntry(s32 arg0, s32 arg1) {
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
    *(ByteBlock_20 *)(arg0 + 4 + 4) = *(const ByteBlock_20 *)(arg1 + 4 + 4);
    *(ByteBlock_70 *)(arg0 + 0x24 + 4) = *(const ByteBlock_70 *)(arg1 + 0x24 + 4);
    return arg0;
}
