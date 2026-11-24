#include "types.h"
#include "pso/network/protocol/protocol.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TRegister.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/packet_classes.h"

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {
s32 __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();

void bswap__9TRegisterFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    bswap_ply_smth_pair((void *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 0xC));
}

s32 __ct__9TRegisterFv(saddr arg0) {
    __ct__8TPlySmthFv((void *)(arg0 + 4));
    return arg0;
}

}

template <> void TPlyText<288>::bswap() {
    header.bswap();
}

class QuestListEntry;
template <typename T, int num_entries, int num_pad_entries> class TMenuList;
template <> class TMenuList<QuestListEntry, 30, 0> {
public:
    TMenuList(const TMenuList &);
    void bswap();
    union {
        packet_header header;
        TRegisterHeaderCopy raw_header;
    };
    u8 entries[30][sizeof(QuestListEntry)];
};
void TMenuList<QuestListEntry, 30, 0>::bswap() {
    header.bswap();
    for (int i = 0; i < 30; i++) {
        bswap_quest_list_entry(entries[i]);
    }
}

void bswap_quest_list_entry(void *p) { ((TPlyGuildCardTag *)p)->bswap(); }

TMenuList<QuestListEntry, 30, 0>::TMenuList(const TMenuList &o) {
    QuestListEntryCopy *end;
    QuestListEntryCopy *d;
    const QuestListEntryCopy *s;
    d = (QuestListEntryCopy *)entries;
    s = (const QuestListEntryCopy *)o.entries;
    end = (QuestListEntryCopy *)(entries + 30);
    raw_header = o.raw_header;
    do {
        __ct__14QuestListEntryFRC14QuestListEntry((saddr)d, (saddr)s);
        d++;
        s++;
    } while (d < end);
}

s32 __ct__14QuestListEntryFRC14QuestListEntry(saddr arg0, saddr arg1) {
    QuestListEntryCopy *dst = (QuestListEntryCopy *)arg0;
    const QuestListEntryCopy *src = (const QuestListEntryCopy *)arg1;
    __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag();
    dst->name = src->name;
    dst->short_description = src->short_description;
    return arg0;
}
