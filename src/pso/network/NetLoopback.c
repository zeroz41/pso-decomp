#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/netcfg.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"

s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, void *pkt);
s32 TLobby__sub_80415320(s32 id, s32 unused, u8 *arr);
s32 TLobby__sub_80415410(s16 id, u8 *addr);

/* Inline the helpers below; this applies to the rest of the file. */
#pragma dont_inline off
#pragma inline_depth(4)

s32 TLobby__sub_8041509C(void) {
    u8 unused[8];
    clear_table_entry_locked(network_loopback_state.handler);
    network_loopback_state.handler = -1;
    TLobby__sub_803F8B78(&network_loopback_state);
    network_loopback_state.slot_count = 0;
    return 0;
}

void TLobby__sub_804150EC(void) {
    TLobby__sub_8041510C();
}

s16 TLobby__sub_8041510C(void)
{
    s16 TLobby__sub_80409A3C(Fn_8040881C *, s16); /* declared here with other parameter types; the definition is s16 (u8 *, s16) */
    Fn_8040881C tbl[11];
    u8* base;
    LoopbackState* p;
    s16 r;
    s16 i;
    s16* e;

    base = (u8*)&network_loopback_state;
    p = (LoopbackState*)base;
    tbl[0] = (Fn_8040881C)fill_reply_buffer;
    tbl[1] = (Fn_8040881C)alloc_conn_slot;
    tbl[2] = (Fn_8040881C)clear_conn_slot;
    tbl[3] = (Fn_8040881C)get_slot_offset_or_default;
    tbl[4] = (Fn_8040881C)TLobby__sub_80415508;
    tbl[5] = (Fn_8040881C)TLobby__sub_804154E4;
    tbl[6] = (Fn_8040881C)TLobby__sub_804154C0;
    tbl[7] = (Fn_8040881C)TLobby__sub_8041549C;
    tbl[8] = (Fn_8040881C)TLobby__sub_80415410;
    tbl[9] = (Fn_8040881C)TLobby__sub_80415320;
    tbl[10] = (Fn_8040881C)TLobby__sub_80415230;

    r = TLobby__sub_80409A3C(tbl, 1);
    if (r < 0) {
        return r;
    }
    init_net_recv_desc((LoopbackState *)base);
    p->handler = r;
    p->protos[0].used = 0;
    p->protos[0].type = 0;
    p->protos[1].used = 0;
    p->protos[1].type = 0;
    e = p->slot_used;
    i = 0;
    while (i < p->slot_count) {
        *e = 0;
        i++;
        e++;
    }
    return r;
}

#pragma push
#pragma opt_common_subs on
s32 TLobby__sub_80415230(s16 idx, s16 mode, u8 *addr, void *pkt) {
    LoopbackState *g = &network_loopback_state;
    u8 *slot;
    s16 len;
    s16 i;
    s16 *used;

    if (idx != 0 && idx != 1) {
        return -0x110;
    }
    len = TLobby__sub_804098B4(pkt);
    if (g->slot_size < len) {
        return -0x110;
    }
    used = g->slot_used;
    slot = g->slots;
    for (i = 0; i < g->slot_count; i++, used++) {
        if (*used == 0) {
            *used = 1;
            TLobby__sub_80409908(slot, pkt);
            TLobby__sub_80409818((s32)slot, len, g->handler, idx, g->protos[idx].type);
            return 0;
        }
        slot += g->slot_size;
    }
    return -0x110;
}
#pragma pop

s32 TLobby__sub_80415320(id, unused, arr)
    s16 id;
    s32 unused;
    u8 *arr;
{
    s32 TLobby__sub_804098B4(void *); /* declared s32 here; the definition returns s16 */
    void TLobby__sub_80409818(s32, s32, s16, s16, u16); /* declared here with an s32 2nd argument; the definition takes s16 */
    LoopbackState *p = &network_loopback_state;
    u8 *base;
    s32 sum;
    s16 i;
    s16 *cnt;
    s16 sz;

    if (id != 0 && id != 1) {
        return -0x110;
    }
    sum = TLobby__sub_804098B4(arr);
    if (p->slot_size < (s16)sum) {
        return -0x110;
    }
    sz = p->slot_size;
    cnt = p->slot_used;
    base = p->slots;
    for (i = 0; i < p->slot_count; i++, cnt++) {
        if (*cnt == 0) {
            *cnt = 1;
            TLobby__sub_80409908(base, arr);
            TLobby__sub_80409818((s32)base, sum, p->handler, id, p->protos[id].type);
            return 0;
        }
        base += sz;
    }
    return -0x110;
}

s32 TLobby__sub_80415410(s16 id, u8 *addr) {
    LoopbackState *p = &network_loopback_state;
    s16 size;
    s16 count;
    s16 i;
    s16 *used;
    s16 step;
    u8 *base;

    if (id != 0 && id != 1) {
        return -0x110;
    }
    used = p->slot_used;
    i = 0;
    base = p->slots;
    size = p->slot_size;
    count = p->slot_count;
    for (; i < count; i++, used++) {
        if (*used != 0 && base <= addr && addr < base + size) {
            *used = 0;
            return 0;
        }
        base += (step = size);
    }
    return -0x110;
}

s32 TLobby__sub_8041549C(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154C0(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_804154E4(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}

s32 TLobby__sub_80415508(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return 0;
}
s16 get_slot_offset_or_default(s16 arg0) {
    if ((arg0 != 0) && (arg0 != 1)) {
        return -0x110;
    }
    return network_loopback_state.slot_size;
}

s32 clear_conn_slot(s16 i) {
    LoopbackState *g;
    if (i != 0 && i != 1) { return -0x110; }
    g = &network_loopback_state;
    g->protos[i].used = 0;
    g->protos[i].type = 0;
    return 0;
}

s16 alloc_conn_slot(s16 h, s16 v) {
    s16 r;
    LoopbackState *g = &network_loopback_state;
    if (h != g->handler) { return -0x110; }
    if (g->protos[0].used == 0) {
        r = 0;
    } else if (g->protos[1].used == 0) {
        r = 1;
    } else {
        return -0x110;
    }
    g->protos[r].used = 1;
    g->protos[r].type = v;
    return r;
}

s32 fill_reply_buffer(s16 h, u8 *p) {
    if (h != network_loopback_state.handler) { return -0x110; }
    p[0] = 0;
    *++p = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 1;
    return 0;
}

LoopbackState network_loopback_state;
