#include "types.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby.h"
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
void copy_entries(s32 arg0, E_802C39F8 *arg1, E_802C39F8 *arg2);

void copy_entries(s32 arg0, E_802C39F8 *arg1, E_802C39F8 *arg2) {
    s32 i;
    for (i = 0; i < arg0; i++) {
        fn_801C1BA8(arg2++, arg1++);
    }
}

void copy_item_entry_array(s32 n, struct Entry_802C3A50 *src, struct Entry_802C3A50 *dst) {
    s32 i;
    for (i = 0; i < n; i++) {
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        ((ItemData *)(dst->item))->copy_from((ItemData *)(src->item));
        dst++;
        src++;
    }
}

}
