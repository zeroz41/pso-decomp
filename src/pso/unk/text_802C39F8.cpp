#include "types.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby.h"
struct Entry_802C3A50 {
    u8 a;
    u8 b;
    u8 pad[2];
    s32 c;
    u8 item[0x14];
};

struct E_802C39F8 { u8 b[0x1C]; };

extern "C" {
void copy_item_entry_array(s32 n, struct Entry_802C3A50 *src, struct Entry_802C3A50 *dst);
s32 fn_801C1BA8(void *, void *);
void copy_entries(s32 count, E_802C39F8 *source, E_802C39F8 *destination);

void copy_entries(s32 count, E_802C39F8 *source, E_802C39F8 *destination) {
    s32 i;
    for (i = 0; i < count; i++) {
        fn_801C1BA8(destination++, source++);
    }
}

void copy_item_entry_array(s32 n, struct Entry_802C3A50 *src, struct Entry_802C3A50 *dst) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        ((TItemData *)(dst->item))->copy_from((TItemData *)(src->item));
        dst++;
        src++;
    }
}

}
