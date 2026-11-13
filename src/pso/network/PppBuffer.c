/* The PPP packet buffers, their init/shutdown pair and readers (a C library, built with GC/1.2.5n). PppBuffer is an
 * inferred name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_803F79BC(void *);
#include "pso/network/PppBuffer.h"

void init_net_state_c(void) {
    TLobby__sub_803F79BC(&lbl_805C04A8);
}

s32 init_net_subsystem_block(void) {
    init_net_buffer_desc(&lbl_805C04A8);
    return 0;
}

s32 TLobby__sub_80401ABC(u8* self_m, void* dst, s32 n)
{
    void NetMemcpy(void*, const void*, s16);
    s32 m; u16 cap; u32 t;

    if (dst == NULL) {
        return 0;
    }
    cap = ((PppFrame *)self_m)->len;
    t = (cap < (u16)n) ? cap : n;
    m = t;
    NetMemcpy(dst, ((PppFrame *)self_m)->data, m);
    return m;
}

#pragma opt_propagation off
PppFrame *TLobby__sub_80401B20(void *src, u16 n) {
    PppBuffers *g = &lbl_805C04A8;
    PppFrame *t = g->packet;
    PppFrame *e;
    t->data = (u8 *)t + ((g->headroom + 0x83) & ~3);
    e = t;
    NetMemcpy(e->data, src, n);
    e->len = n;
    return e;
}
#pragma opt_propagation reset

u8 *alloc_from_buffer(void *self, s16 n) {
    PppFrame *frame = (PppFrame *)self;
    u8 *data;
    if (frame != NULL) {
        data = frame->data;
        if ((s32)(data - (u8 *)(frame + 1)) >= n) {
            frame->data = data - n;
            frame->len += n;
            return (u8 *)frame;
        }
    }
    return NULL;
}

s16 TLobby__sub_80401BCC(void *self, void *dst, u16 n) {
    PppFrame *p;
    s16 m;
    s16 total = 0;

    if (self == 0) {
        return 0;
    }
    while (n != 0 && (p = *(PppFrame **)self) != 0) {
        m = (n < p->len) ? n : p->len;
        if (dst != 0) {
            if (m == 1) {
                ((u8 *)dst)[0] = p->data[0];
            } else if (m > 1) {
                NetMemcpy(dst, p->data, m);
            }
            dst = (u8 *)dst + m;
        }
        p->data += m;
        total += m;
        n -= m;
        p->len -= m;
        if (p->len == 0) {
            n = 0;
        }
    }
    return total;
}

void TLobby__sub_80401CAC(PppFrame **o, u16 v) {
    if (o == NULL || *o == NULL) return;
    if (v == 0) return;
    if ((*o)->len < v) return;
    (*o)->len = v;
}

u16 get_field_4(void *self) {
    return ((PppFrame *)self)->len;
}

#pragma push
#pragma opt_propagation off
PppFrame *init_net_buffer_entry(u16 idx) {
    PppBuffers *g = &lbl_805C04A8;
    PppFrame *t = (PppFrame *)(g->pool + idx * g->pool_words * 4);
    PppFrame *e;
    e = (PppFrame *)(g->pool + idx * g->pool_words * 4);
    e->data = (u8 *)t + ((g->headroom + 0x83) & ~3);
    e->len = 0;
    return e;
}
#pragma pop

PppBuffers lbl_805C04A8;
