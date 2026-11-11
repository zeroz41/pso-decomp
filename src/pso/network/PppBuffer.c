/* The PPP packet buffers (.bss 805C04A8), their init/shutdown pair (80401A68/80401A90) and readers (a C
 * library, built with GC/1.2.5n). PppBuffer is an inferred name. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
typedef struct RecoveredFields_80401B8C_arg0 RecoveredFields_80401B8C_arg0;
/* This file's functions. */
u16 get_field_4(void *self);
void init_net_state_c(void);
s32 init_net_subsystem_block(void);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

struct RecoveredFields_80401B8C_arg0 {
    s32 field_0;
    u16 field_4;
};

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
    cap = *(u16*)(self_m + 4);
    t = (cap < (u16)n) ? cap : n;
    m = t;
    NetMemcpy(dst, *(void**)self_m, m);
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

u8 *alloc_from_buffer(void *self, s16 arg1) {
    struct RecoveredFields_80401B8C_arg0 *arg0 = (struct RecoveredFields_80401B8C_arg0 *)self;
    s32 temp_r6;
    if (arg0 != NULL) {
        temp_r6 = arg0->field_0;
        if ((s32) (temp_r6 - (u32)(((u8 *)(arg0) + 8))) >= arg1) {
            arg0->field_0 = temp_r6 - arg1;
            arg0->field_4 += arg1;
            return (unsigned char *) (arg0);
        }
    }
    return NULL;
}

extern s16 TLobby__sub_80401BCC(void *self, void *dst, u16 n) {
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
    u8 *arg0 = (u8 *)self;
    return *(u16 *)((s8 *)arg0 + 4);
}

#pragma push
#pragma opt_propagation off
PppFrame *init_net_buffer_entry(u16 idx) {
  PppBuffers *g = &lbl_805C04A8;
  PppFrame *t = (PppFrame *) (g->pool + ((idx * g->pool_words) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  PppFrame *e;
  e = (PppFrame *) (g->pool + ((idx * g->pool_words) * ((((4 & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu)));
  e->data = ((u8 *) t) + ((g->headroom + 0x83) & (~3));
  e->len = 0xFFFFFFFFu * 0;
  return e;
  e = t;
}
#pragma pop

PppBuffers lbl_805C04A8;
