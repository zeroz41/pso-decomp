#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/netcfg.h"
#include "pso/network/BufferRef.h"
#include "pso/network/IPv6.h"

#include "types.h"
/* The object header the stack's records share (laid out like TObject's fields). */
typedef struct TObjectFields {
    const char *m_name;
    u16 m_flags;
    u16 m_id;
    void *m_prev;
    void *m_next;
    void *m_up;
    void *m_down;
} TObjectFields;
typedef struct NetHdr_8041B974 NetHdr_8041B974;
typedef struct Self_803FD85C Self_803FD85C;
typedef struct Tbl_803FD85C Tbl_803FD85C;
typedef struct RecoveredGlobal_8041E178_lbl_805C1D48 RecoveredGlobal_8041E178_lbl_805C1D48;
typedef struct E_8041A230 E_8041A230;
typedef struct G_8041A230 G_8041A230;
typedef struct Self_803FDA68 Self_803FDA68;
typedef struct Tbl_803FDA68 Tbl_803FDA68;
typedef struct V_803FE600 V_803FE600;
typedef struct O_803FE600 O_803FE600;
typedef struct In_8040D95C In_8040D95C;
typedef struct Out_8040D95C Out_8040D95C;
typedef struct E_8041A498 E_8041A498;
typedef struct A_8041D524 A_8041D524;
/* This file's functions. */
s32 abort_tcp_connection(s16 arg0);
u8 * alloc_free_entry(void);
void clear_position(void *self);
s32 close_if_open(void *self);
s32 compare_sockaddr(void *self, u8 *arg1);
s32 dispatch_by_addr_family(s32 arg0, u8 *arg1, u8 *arg2, u8 *arg3, void *arg4, void *arg5);
s32 get_field_534(void *self);
s32 get_field_d8(void *self);
s32 get_queue_diff(void *self);
s32 get_score(void *self);
s32 get_tcp_stat(s16 arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 *arg4);
void init_msg(void *self, s32 arg1);
void insert_item_at(void *self, s16 idx, s32 a, s32 b);
s32 is_multicast_address(void *self, s16 arg1);
s32 mark_connection_closed(s16 arg0);
void release_entry(void *self);
void reset_slot_index(void *self);
void set_value_and_enable(void *self, s32 arg1);
s16 tcp_connect_start(s16 arg0, s32 arg1, s16 arg2);
s16 tcp_get_socket_handle(s16 i);
s16 validate_tcp_handle(s16 i);
s32 get_adjusted_slot_count(u8 *arg0);
s32 is_addr_unspecified(u8 *arg0);
s32 select_source_address(Out_8040D95C *arg0, In_8040D95C *arg1);
extern s32 TLobby__sub_8041F204(u8 *self, u16 a, u8 *b);
extern s32 TLobby__sub_8041F914(u8 *self, u16 a, u8 *b, u8 *c);
extern s32 TLobby__sub_8041F11C(u8 *self);
typedef struct NetHdr_8041B974 { u16 a; u16 b; u32 c; u32 d; u8 e; u8 f; u16 g; u16 h; u16 i; } NetHdr_8041B974;

struct Self_803FD85C;
struct Tbl_803FD85C {
    u8 pad[0x14];
    void (*f14)(Self_803FD85C *, Tbl_803FD85C *);
    u8 pad18[8];
    void (*f20)(Self_803FD85C *, Tbl_803FD85C *);
};
struct Self_803FD85C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[8];
    u8 f10[0x1C];
    Tbl_803FD85C *tbl;
    void *f30;
};

#include <stddef.h>

typedef struct E_805C1D48 { u8 pad[4]; u16 f4; s16 f6; u8 pad2[0x53C]; } E_805C1D48;
struct RecoveredGlobal_8041E178_lbl_805C1D48 {
    union { s32 value; E_805C1D48 *p; };
    s16 n;
    u8 remaining[0xA2];
};
typedef struct P_8041D2B8 { s32 a; s32 b; s32 c; s32 d; } P_8041D2B8;
typedef struct O_8041D2B8 { u8 pad0[0x238]; s32 f238; u8 pad23C[0x320 - 0x23C]; s16 n; u8 pad322[0xE]; P_8041D2B8 items[32]; } O_8041D2B8;
#include "pso/network/IPv6Send.h"
#include "pso/network/NetStackTypes.h"

struct E_8041A230 {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
    s16 f4;
    u8 pad6[2];
    s16 f8;
    u8 padA[0x544 - 0xA];
};
struct G_8041A230 {
    E_8041A230 *ents;
    s16 count;
    s16 avail;
    u8 pad8[8];
    s16 h10;
    s16 h12;
    s16 h14;
    u8 pad16[2];
    u8 tick[6];
    s16 h1E;
    s16 h20;
    s16 h22;
    u8 pad24[0x2C];
    u8 b50;
    u8 b51;
    u8 b52;
    u8 b53;
    u8 b54;
    u8 b55;
    u8 b56;
    u8 b57;
    u8 b58;
    u8 b59;
    u8 b5A;
    u8 b5B;
    s16 s5C;
    s16 s5E;
    s16 s60;
    s16 s62;
    s16 s64;
    s16 s66;
    s16 s68;
    s16 s6A;
    s16 s6C;
    s16 s6E;
    s16 s70;
    s16 s72;
    s16 s74;
    u8 pad76[0x2C];
    u8 bA2;
    u8 padA3[5];
};
u16 TLobby__sub_8040D8F0(u8 *arg0, u8 *arg1, s8 arg2, u8 *arg3, s16 arg4);
s16 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8041D368(u8 *arg0);
u8 * TLobby__sub_8041B5C0(void *);
extern RecoveredGlobal_8041E178_lbl_805C1D48 tcp_protocol_state;
s16 TLobby__sub_8041579C(void *);
s32 TLobby__sub_8041EB74(u8 *arg0);
s16 TLobby__sub_80415954(void *out_, int handle, s16 flag);
s32 TLobby__sub_8041ECA4(u8 *arg0);
s16 TLobby__sub_8040DC8C(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8041FFF8(int, int);
s32 TLobby__sub_80420BD0(void *, void *, s32);
s32 tcp_start_send(s16 arg0, u8 *arg1, void (*completion)(s16, s16), u8 arg3);
void TLobby__sub_8041A3CC(void);
void TLobby__sub_8041A5B4(void);
s32 NetTCPInit(void);

struct Self_803FDA68;
struct Tbl_803FDA68 {
    u8 pad[0x14];
    void (*f14)(Self_803FDA68 *, Tbl_803FDA68 *);
    u8 pad18[0xC];
    void (*f24)(Self_803FDA68 *, Tbl_803FDA68 *);
    void *(*f28)(Self_803FDA68 *, Tbl_803FDA68 *);
};
struct Self_803FDA68 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FDA68 *tbl;
    void *f30;
};

struct V_803FE600;
struct O_803FE600 {
    u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    u8 pad8[0x2C - 8];
    V_803FE600 *p2C;
};
struct V_803FE600 {
    u8 pad[0x14];
    void (*fn)(O_803FE600 *, V_803FE600 *);
};

extern void NetMemcpy(void *_w0, void *_w1, int _w2);
extern void NetMemcpy(void *_w0, void *_w1, int _w2);
#pragma dont_inline off
#pragma inline_depth(4)
RecoveredGlobal_8041E178_lbl_805C1D48 tcp_protocol_state;

s32 NetUnregisterTimer(void* p);

#pragma dont_inline off
#pragma inline_depth(4)

struct In_8040D95C { s32 type; s32 f4; };
struct Out_8040D95C { s32 type; u32 f4; };

u8 *TLobby__sub_80406F0C(void *);

#pragma push
#pragma opt_common_subs on
s32 NetTCPInit(void) {
    s16 n;
    s16 i;
    E_8041A230 *e;
    init_params((NetParamCfg *)((u8 *)&tcp_protocol_state));
    e = (*(G_8041A230 *)&tcp_protocol_state).ents;
    for (i = 0; i < (n = (*(G_8041A230 *)&tcp_protocol_state).count); i++) {
        e->f8 = -1;
        e->f4 = 0;
        e->c0 = 0x54;
        e->c1 = 0x43;
        e->c2 = 0x42;
        e->c3 = i;
        e++;
    }
    (*(G_8041A230 *)&tcp_protocol_state).avail = n;
    (*(G_8041A230 *)&tcp_protocol_state).h10 = 0;
    NetStoreTick((s32 *)(*(G_8041A230 *)&tcp_protocol_state).tick);
    (*(G_8041A230 *)&tcp_protocol_state).h14 = 0x7FF;
    (*(G_8041A230 *)&tcp_protocol_state).h12 = 0x400;
    (*(G_8041A230 *)&tcp_protocol_state).h22 = 0x3840;
    (*(G_8041A230 *)&tcp_protocol_state).h20 = 0x96;
    (*(G_8041A230 *)&tcp_protocol_state).h1E = 3;
    (*(G_8041A230 *)&tcp_protocol_state).b50 = 0;
    (*(G_8041A230 *)&tcp_protocol_state).b50 |= 1;
    (*(G_8041A230 *)&tcp_protocol_state).bA2 = 2;
    (*(G_8041A230 *)&tcp_protocol_state).b51 = 0x14;
    (*(G_8041A230 *)&tcp_protocol_state).b52 = 0;
    (*(G_8041A230 *)&tcp_protocol_state).b53 = 2;
    (*(G_8041A230 *)&tcp_protocol_state).b54 = 0x12;
    (*(G_8041A230 *)&tcp_protocol_state).b55 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b56 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b57 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b58 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b59 = 0x11;
    (*(G_8041A230 *)&tcp_protocol_state).b5A = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).b5B = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).s5C = 1;
    (*(G_8041A230 *)&tcp_protocol_state).s5E = 2;
    (*(G_8041A230 *)&tcp_protocol_state).s60 = 4;
    (*(G_8041A230 *)&tcp_protocol_state).s62 = 8;
    (*(G_8041A230 *)&tcp_protocol_state).s64 = 0x10;
    (*(G_8041A230 *)&tcp_protocol_state).s66 = 0x20;
    (*(G_8041A230 *)&tcp_protocol_state).s68 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6A = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6C = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s6E = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s70 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s72 = 0x40;
    (*(G_8041A230 *)&tcp_protocol_state).s74 = 0x40;
    NetRegisterTimer(500, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A5B4));
    NetRegisterTimer(100, (s16)(1), (NetTimerCallback)(TLobby__sub_8041A3CC));
    return 0;
}
#pragma pop

s32 TLobby__sub_8041A9AC(int);
extern void TLobby__sub_8041A3CC(void) {
    s16 i;
    u8 *g;
    u8 *e;
    extern void *alloc_free_entry(void);
    extern void release_entry(void *);

    g = (u8 *)&tcp_protocol_state;
    e = *(u8 **)g;
    for (i = 0; i < *(s16 *)(g + 4); e += 0x544, i++) {
        if (*(u16 *)(e + 4) != 0 && *(s16 *)(e + 0x538) != 0) {
            *(s16 *)(e + 0x538) -= 1;
            if (*(s16 *)(e + 0x538) == 0) {
                *(s16 *)(e + 0x538) = *(s16 *)(g + 0xa0) / 100;
                e[0xb] |= 1;
                TLobby__sub_8041A9AC((int)e);
            }
        }
    }
}

void clear_position(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s16 *)((s8 *)arg0 + 0x25C) = 0;
    *(s16 *)((s8 *)arg0 + 0x25E) = 0;
    *(s16 *)((s8 *)arg0 + 0x260) = 0;
    *(s16 *)((s8 *)arg0 + 0x262) = 0;
}

s32 TLobby__sub_8041D460(u8 *self, s32 *p1, s32 *p2);
s32 TLobby__sub_80420410(s32 a, s32 b, u8 *c, u8 *d);
void TLobby__sub_8041D398();
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
s32 TLobby__sub_8041A9AC(int arg0)
{
    u8 *self = (u8 *)arg0;
    u8 *out = self + 0x268;
    u8 *base = (u8 *)&tcp_protocol_state;
    u8 *buf;
    u8 *ent;
    u8 *q;
    u8 *r20;
    s32 r15, r16, r17, r18, r19, r21, r23, r24, r25, r26, r27, r28;
    s32 t, u, lim, avail;
    s16 a;
    u16 b;
    s32 pa0, pa1, pa2;
    s32 t24, t20;
    u16 tmp;
    s32 tmp4, tmp4b;
    s32 pb0, pb1;

    if (*(s16 *)(self + 0x6) < 0) {
        return -1;
    }
    if (TLobby__sub_8040DA54(self + 0x27c, self + 0x290) == 0) {
        NetDispatchSocketEvent((s16)(((s32)self - *(s32 *)base) / 0x544), *(s32 *)(self + 0x2d0), 3, 0xc);
        return -6;
    }
    a = TLobby__sub_8040DC8C(self + 0x27c, self + 0x290);
    b = *(u16 *)(self + 0x264);
    r23 = (s16)(b < a ? (s16)b : a);
    if ((s16)r23 < 0) {
        return r23;
    }
    r15 = !(*(u32 *)(self + 0x208) - *(u32 *)(self + 0x238));
    if ((u32)*(u32 *)(self + 0x238) == (u32)*(u32 *)(self + 0x208) && *(s16 *)(self + 0x244) >= *(u16 *)(self + 0x254)) {
        switch (*(s32 *)(self + 0x540)) {
        case 1:
            *(u32 *)(self + 0x23c) = b;
            break;
        case 2:
            *(u32 *)(self + 0x23c) = b * 2;
            break;
        case 3:
            *(u32 *)(self + 0x23c) = ((s32)(b * 4) < (((s32)(b * 2) > 0x111c) ? (s32)(b * 2) : 0x111c)) ? (b * 4) : ((((s32)(b * 2) > 0x111c) ? (s32)(b * 2) : 0x111c));
            break;
        default:
            *(u32 *)(self + 0x23c) = get_adjusted_slot_count(self);
            break;
        }
    }
    for (;;) {
        buf = base + 0x28;
        r24 = 0;
        r28 = 0;
        if (*(u32 *)(self + 0x2f4) != *(u32 *)(self + 0x208)) {
            r28 = TLobby__sub_8041D460(self, &t24, &t20);
            if (r28 != 0) {
                r24 = 1;
                r27 = t24 - *(u32 *)(self + 0x208);
            } else {
                r27 = *(u32 *)(self + 0x20c) - *(u32 *)(self + 0x208);
            }
        } else {
            r27 = *(u32 *)(self + 0x20c) - *(u32 *)(self + 0x208);
        }
        r26 = (base)[*(s16 *)(self + 0x6) + 0x51];
        r16 = *(s32 *)(self + 0x220);
        if (self[0xc] != 0) {
            if (r16 == 0) {
                r16 = 1;
            } else {
                *(s16 *)(self + 0x25e) = 0;
                *(s32 *)(self + 0x258) = 0;
            }
        }
        if (r28 == 0) {
            r28 = ((u32)get_score(self) < (u32)r16 ? get_score(self) : r16) - r27;
        }
        t = *(u32 *)(self + 0x23c) - *(u32 *)(self + 0x2f0);
        if (*(u32 *)(self + 0x2f4) == *(u32 *)(self + 0x208)) {
            t -= *(u32 *)(self + 0x20c) - *(u32 *)(self + 0x208);
        }
        if (t < 0) {
            t = 0;
        }
        if (r28 > t) {
            r28 = t;
            r24 = 0;
        }
        if (r27 + r28 < get_score(self)) {
            r26 &= ~1;
        }
        if (r28 < 0) {
            r28 = 0;
            if (r16 == 0) {
                *(s16 *)(self + 0x25c) = 0;
                *(u32 *)(self + 0x20c) = *(u32 *)(self + 0x208);
            }
        }
        if ((u32)r28 > *(u16 *)(self + 0x264)) {
            r28 = *(u16 *)(self + 0x264);
            r24 = 1;
        }
        if ((s32)((*(u32 *)(self + 0x20c) + r28) - (*(u32 *)(self + 0x208) + get_score(self))) < 0) {
            r26 &= ~1;
        }
        r25 = get_queue_diff(self);
        r21 = r26 & 1;

        if (r21 != 0) {
            if ((self[0xb] & 0x10) == 0) {
                goto L316;
            }
            if (*(u32 *)(self + 0x20c) == *(u32 *)(self + 0x208)) {
                goto L316;
            }
        }
        if (self[0xb] & 1) {
            goto L316;
        }
        if (r26 & 6) {
            goto L316;
        }
        if ((s32)(*(u32 *)(self + 0x210) - *(u32 *)(self + 0x208)) > 0) {
            goto L316;
        }
        if (r28 != 0) {
            if ((u32)r28 == *(u16 *)(self + 0x264)) {
                goto L316;
            }
            if (r24 != 0) {
                goto L316;
            }
            if ((u32)((self[0x204] >> 7) & 1) == 1) {
                t = get_score(self);
            } else {
                t = ((u32)get_score(self) < *(u32 *)(self + 0x530)) ? get_score(self) : *(s32 *)(self + 0x530);
            }
            if ((r15 != 0 || (self[0xb] & 4)) && r27 + r28 >= t) {
                goto L316;
            }
            if (self[0xc] != 0) {
                goto L316;
            }
            if ((u32)r28 >= ((u32)*(s32 *)(self + 0x250) >> 1)) {
                goto L316;
            }
            if ((s32)(*(u32 *)(self + 0x20c) - *(u32 *)(self + 0x238)) < 0) {
                goto L316;
            }
        }
        if (r25 > 0) {
            r16 = r25 - (*(s32 *)(self + 0x234) - *(s32 *)(self + 0x228));
            if (r16 < 0) {
                r16 = -r16;
            }
            lim = ((*(u16 *)(self + 0x264) > 0x28) ? (*(u16 *)(self + 0x264) - 0x28) : 1) << 1;
            if ((u32)r16 >= (u32)lim) {
                goto L316;
            }
        }
        if (r16 * 2 >= get_field_534(self)) {
            goto L316;
        }
        if ((u32)get_score(self) != 0 && *(s16 *)(self + 0x25c) == 0 && *(s16 *)(self + 0x25e) == 0) {
            *(s32 *)(self + 0x258) = 0;
            *(s16 *)(self + 0x25e) = (s16)(((*(s16 *)(self + 0x24e) + (*(s16 *)(self + 0x24c) >> 2)) >> 1)
                * ((s16 *)(base + 0x5c))[*(s32 *)(self + 0x258)]);
            if (*(s16 *)(self + 0x25e) < 10) {
                *(s16 *)(self + 0x25e) = 10;
            } else if (*(s16 *)(self + 0x25e) > 0x78) {
                *(s16 *)(self + 0x25e) = 0x78;
            }
            if ((u32)*(s32 *)(self + 0x258) < 0xc) {
                *(s32 *)(self + 0x258) = *(s32 *)(self + 0x258) + 1;
                return 0;
            }
        }

L316:
        if (r21 != 0 && (self[0xb] & 0x10) && *(u32 *)(self + 0x20c) == *(u32 *)(self + 0x238)) {
            *(u32 *)(self + 0x20c) = *(u32 *)(self + 0x20c) - 1;
            r27 -= 1;
        }
        *(s32 *)(out + 4) = *(u32 *)(self + 0x208) + r27;
        r20 = 0;
        r19 = 0;
        *(s32 *)(out + 8) = *(s32 *)(self + 0x228);
        if (r26 & 2) {
            *(s32 *)(self + 0x2ec) = 0;
            reset_slot_index(self);
            buf[0] = 2;
            r20 = buf;
            buf[1] = 4;
            tmp = ((u32)*(s32 *)(self + 0x534) < (u32)r23) ? *(s32 *)(self + 0x534) : r23;
            NetMemcpy(r20 + 2, &tmp, 2);
            r19 = 4;
            if (self[0x2e8] & 1) {
                r20[4] = 4;
                r20[5] = 2;
                r20[6] = 1;
                r20[7] = 1;
                r19 = 8;
            }
        }
        if ((self[0x2e8] & 2) && *(u32 *)(self + 0x2f8) != *(u32 *)(self + 0x2fc)) {
            buf[(u16)r19++] = 1;
            buf[(u16)r19++] = 1;
            buf[(u16)r19] = 5;
            r18 = r19 + 1;
            r20 = buf;
            q = self;
            r16 = 2;
            r17 = 0;
            r19 += 2;
            while ((u16)r17 < 5 && (u32)(lim = *(s32 *)(q + 0x2f8)) != *(u32 *)(q + 0x2fc) && (s32)(u16)r19 + 8 <= 0x28) {
                tmp4 = lim;
                tmp4b = *(s32 *)(q + 0x2fc);
                NetMemcpy(r20 + (u16)r19, &tmp4, 4);
                NetMemcpy(r20 + (u16)(r19 + 4), &tmp4b, 4);
                r19 += 8;
                r16 += 8;
                q += 8;
                r17++;
            }
            buf[(u16)r18] = (u8)r16;
        }
        while (((u16)r19 % 4) != 0) {
            buf[(u16)r19] = 1;
            r19++;
        }
        r17 = (u16)r19;
        avail = *(u16 *)(self + 0x264) - r17;
        if (r28 > avail) {
            r28 = avail;
            r26 &= ~1;
            r24 = 1;
        }
        *(u8 *)(out + 0xd) = (u8)r26;
        if ((u32)r25 < ((u32)get_field_534(self) >> 2) && (u32)r25 < *(u16 *)(self + 0x264)) {
            r25 = 0;
        }
        if (r25 < *(s32 *)(self + 0x234) - *(s32 *)(self + 0x228)) {
            r25 = *(s32 *)(self + 0x234) - *(s32 *)(self + 0x228);
        }
        if ((u32)r25 > *(u32 *)(self + 0x534)) {
            r25 = *(s32 *)(self + 0x534);
        }
        *(u16 *)(out + 0xe) = r25;
        if ((s32)(*(u32 *)(self + 0x210) - *(u32 *)(self + 0x20c)) > 0) {
            *(u16 *)(out + 0x12) = *(u32 *)(self + 0x210) - *(u32 *)(self + 0x20c);
            r26 |= 0x20;
        } else {
            *(u32 *)(self + 0x210) = *(u32 *)(self + 0x208);
        }
        if (r28 != 0 && r27 + r28 == get_score(self)) {
            r26 |= 8;
        }
        r16 = 0;
        *(s16 *)(out + 0x10) = (s16)r16;
        *(u8 *)(out + 0xd) = (u8)r26;
        *(u8 *)(out + 0xc) = (u8)((((r17 + 0x14) >> 2) << 4) & 0xf0);
        ent = alloc_free_entry();
        if (ent == 0) {
            return -0x101;
        }
        *(s32 *)(ent + 4) = 0;
        *(s32 *)(ent + 8) = 0;
        if (TLobby__sub_80420410(r27, r28, ent, self) < 0) {
            *(s32 *)(ent + 4) = 0;
            *(s32 *)(ent + 8) = 0;
        }
        if ((u16)r19 != 0) {
            *(s32 *)(ent + 8) += *(s32 *)(ent + 8);
            *(u16 *)(ent + *(s32 *)(ent + 4) * 12 + 12) = (u16)r19;
            set_value_and_enable(ent + *(s32 *)(ent + 4) * 12 + 16, (s32)r20);
            *(s32 *)(ent + 4) += 1;
            *(s32 *)(ent + 8) += 0x14;
            *(u16 *)(ent + *(s32 *)(ent + 4) * 12 + 12) = 0x14;
            set_value_and_enable(ent + *(s32 *)(ent + 4) * 12 + 16, (s32)out);
            *(s32 *)(ent + 4) += 1;
            *(s16 *)(out + 0x10) = (s16)TLobby__sub_8040D8F0(self + 0x290, self + 0x27c, 6, ent, 1);
        }
        if (self[0xc] == 0 || *(s16 *)(self + 0x25e) == 0) {
            r16 = *(u32 *)(self + 0x20c);
            if (r26 & 2) {
                *(u32 *)(self + 0x20c) = r16 + 1;
            }
            if (r26 & 1) {
                *(u32 *)(self + 0x20c) += 1;
                self[0xb] |= 0x10;
            }
            if (*(u32 *)(self + 0x208) != *(u32 *)(self + 0x2f4)) {
                *(u32 *)(self + 0x2f0) += r28;
            }
            if (r28 > 0) {
                if ((s32)(r27 + r28 + *(u32 *)(self + 0x208) - *(u32 *)(self + 0x20c)) > 0) {
                    *(u32 *)(self + 0x20c) += r28;
                } else {
                    TLobby__sub_8041D398(self);
                }
            }
            if ((s32)(*(u32 *)(self + 0x20c) - *(u32 *)(self + 0x238)) > 0) {
                *(u32 *)(self + 0x238) = *(u32 *)(self + 0x20c);
                if (*(s16 *)(self + 0x246) == 0) {
                    *(s16 *)(self + 0x246) = 1;
                    *(s32 *)(self + 0x248) = r16;
                }
            }
            if (*(s16 *)(self + 0x25c) == 0 && *(u32 *)(self + 0x20c) != *(u32 *)(self + 0x208)) {
                *(s16 *)(self + 0x25c) = *(s16 *)(self + 0x254);
                if (*(s16 *)(self + 0x25e) != 0) {
                    *(s16 *)(self + 0x25e) = 0;
                    *(s32 *)(self + 0x258) = 0;
                }
            }
        } else if ((s32)(*(u32 *)(self + 0x20c) + r28 - *(u32 *)(self + 0x238)) > 0) {
            *(u32 *)(self + 0x238) = *(u32 *)(self + 0x20c) + r28;
        }
        {
            s16 rc = dispatch_by_addr_family((s32)ent, self + 0x27c, self + 0x290, self + 0x2d6, self + 0x2dc, (void *)6);
            release_entry(ent);
            if (rc < 0) {
                return rc;
            }
        }
        if (r25 > 0) {
            if (*(s32 *)(self + 0x228) + r25 - *(s32 *)(self + 0x234) > 0) {
                *(s32 *)(self + 0x234) = *(s32 *)(self + 0x228) + r25;
            }
        }
        self[0xb] &= ~1;
        *(s16 *)(self + 0x538) = 0;
        if (r24 == 0) {
            break;
        }
        NetYieldOutsideDispatcherThread();
    }
    return 0;
}
#pragma pop
s32 TLobby__sub_8041B3D4(void* a, void* b, s16 c, s16 d, s32 e, s32 f, u8 g_m) {
    struct {
        s16 s0;
        s16 s1;
        u32 w0;
        u32 w1;
        u8 b0;
        u8 b1;
        s16 h0;
        s16 h1;
        s16 h2;
    } src;
    struct {
        s16 s0;
        s16 s1;
        u32 w0;
        u32 w1;
        u8 b0;
        u8 b1;
        s16 h0;
        s16 h1;
        s16 h2;
    } hdr;
    void *p1;
    void *p2;
    void *p3;
    void *p4;
    void *p5;
    void *p6;
    void *p7;
    void *p8;
    void *ph;
    u8 *ctx;
    u8 buf[0x10];
    s16 dispatch_by_addr_family(void* a, void* b, void* c, void* d, void* e, u32 n);

    NetMemset((void *)(buf), (int)(0), (int)(0x10));
    if (!TLobby__sub_8040DA54((u8 *)(a), (u8 *)(b))) {
        return -1;
    }
    src.s0 = c;
    src.s1 = d;
    p1 = &src.s1;
    p2 = &src.w0;
    src.w0 = e;
    p3 = &src.w1;
    p4 = &src.b0;
    src.w1 = f;
    p5 = &src.b1;
    p8 = &src.h2;
    src.b0 = 0x50;
    p7 = &src.h1;
    p6 = &src.h0;
    src.b1 = g_m;
    src.h2 = 0;
    src.h1 = 0;
    src.h0 = 0;
    ctx = alloc_free_entry();
    if (ctx == NULL) {
        return -0x101;
    }
    *(u32*)(ctx + 4) = 1;
    *(u32*)(ctx + 8) = 0x14;
    *(s16*)(ctx + 0xc) = 0x14;
    NetMemcpy((void *)(&hdr.s0), (void *)(&src.s0), (int)(2));
    NetMemcpy((void *)(&hdr.s1), p1, (int)(2));
    NetMemcpy((void *)(&hdr.w0), p2, (int)(4));
    NetMemcpy((void *)(&hdr.w1), p3, (int)(4));
    NetMemcpy((void *)(&hdr.b0), p4, (int)(1));
    NetMemcpy((void *)(&hdr.b1), p5, (int)(1));
    NetMemcpy((void *)(&hdr.h0), p6, (int)(2));
    ph = &hdr.h1;
    NetMemcpy(ph, p7, (int)(2));
    NetMemcpy((void *)(&hdr.h2), p8, (int)(2));
    set_value_and_enable(ctx + 0x10, (s32)&hdr);
    src.h1 = ((s16)TLobby__sub_8040D8F0((u8 *)(b), (u8 *)(a), (s8)(6), (u8 *)(ctx), (s16)(1)));
    NetMemcpy(ph, (void *)(&src.h1), (int)(2));
    if ((s16)dispatch_by_addr_family((void*)(ctx), (void*)(a), (void*)(b), (void*)(buf + 4), (void*)(buf + 4), (u32)(6)) < 0) {
        release_entry((void*)(ctx));
        return -1;
    }
    release_entry((void*)(ctx));
    return 0;
}

extern u8 *TLobby__sub_8041B5C0(void *arg0) {
    u8 *self;
    p8040EE4C_Unk805BDF48 *g = (p8040EE4C_Unk805BDF48 *)&tcp_protocol_state;
    s16 idx;
    s32 tmp;
    s32 pad[2];

    (void)pad;
    if ((self = (u8 *)arg0) == NULL) {
        return NULL;
    }
    if (self[0xb] & 0x80) {
        if (!(self[0xb] & 0x20)) {
            idx = (s16)(((s32)(self - (u8 *)g->entries)) / 0x544);
            NetDispatchSocketEvent(idx, *(s32 *)(self + 0x2d0), 3, 3);
            self[0xb] |= 0x20;
        }
        close_if_open((void *)self);
        TLobby__sub_8041EB74(self);
        idx = *(s16 *)(self + 8);
        tmp = (u32)idx;
        if (tmp != 0xffff) {
            p8040EE4C_Unk805BDF48Rec *e;
            e = g->entries;
            e += idx;
            if (e->flags == 1) {
                e->unk2C6 -= 1;
            }
        }
        NetDispatchSocketEvent((s16)(((s32)(self - (u8 *)g->entries)) / 0x544), *(s32 *)(self + 0x2d0), 3, 0xff);
        *(s16 *)(self + 4) = 0;
        g->cur = (s16)(((s32)(self - (u8 *)g->entries)) / 0x544);
        return NULL;
    }
    *(s16 *)(self + 6) = 0;
    *(s16 *)(self + 0x25C) = 0;
    *(s16 *)(self + 0x25E) = 0;
    *(s16 *)(self + 0x260) = 0;
    *(s16 *)(self + 0x262) = 0;
    return self;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_propagation off
#pragma pool_data off
extern s16 TLobby__sub_8041B724(u8 * self_) {
  s32 r;
  s32 new_var;
  u16 a;
    s32 TLobby__sub_8040DC8C(void*, void*);
  r = TLobby__sub_8040DC8C(((u8 *) ((void *)self_)) + 0x27c, ((u8 *) ((void *)self_)) + 0x290);
  a = *((u16 *) (((u8 *) ((void *)self_)) + 0x264));
  new_var = r;
  return (s16)((s16) ((a < (r = (s16) new_var)) ? (a) : ((s16) new_var)));
}
#pragma pop

extern s32 TLobby__sub_8041E780(void);
s32 TLobby__sub_8041EC14(u8 *arg0);
extern s32 TLobby__sub_8041B774(u8 *self, u8 *src, u8 *a, u8 *b) {
    u16 v;
    u8 *dst;
    s32 w;
    s32 n;
    s16 idx;
    u8 *sp;
    s16 TLobby__sub_8041ECA4(u8 *);
    s16 TLobby__sub_8041EC14(u8 *);
    s16 is_addr_unspecified(u8 *);
    s16 TLobby__sub_8041E780(void);

    if (*(s16 *)(self + 0x2c4) <= *(s16 *)(self + 0x2c6)) return 0;
    idx = TLobby__sub_8041E780();
    if (idx < 0) return 0;

    dst = *(u8 **)&tcp_protocol_state;
    dst += idx * 0x544;
    *(u16 *)(dst + 0x268) = *(u16 *)(self + 0x268);
    v = *(u16 *)(self + 0x26a);
    if (v == 0) {
        v = *(u16 *)src;
        *(u16 *)(dst + 0x26a) = v;
    } else {
        *(u16 *)(dst + 0x26a) = v;
    }

    if (is_addr_unspecified(self + 0x27c)) {
        NetMemcpy(dst + 0x27c, a, 0x14);
    } else {
        NetMemcpy(dst + 0x27c, self + 0x27c, 0x14);
    }
    NetMemcpy(dst + 0x290, b, 0x14);
    NetMemcpy(dst + 0x2d6, self + 0x2d6, 3);
    NetMemcpy(dst + 0x2dc, self + 0x2dc, 12);

    n = TLobby__sub_8040DC8C(dst + 0x27c, dst + 0x290);
    w = *(u16 *)(dst + 0x264);
    w = (w < n) ? w : n;
    if ((s16)w < 0) {
        *(s16 *)(dst + 0x4) = 0;
        return 0;
    }

    *(u32 *)(dst + 0x530) = *(u32 *)(self + 0x530);
    *(u32 *)(dst + 0x534) = *(u32 *)(self + 0x534);
    if (TLobby__sub_8041ECA4(dst) < 0) {
        *(s16 *)(dst + 0x4) = 0;
        return 0;
    }
    if (TLobby__sub_8041EC14(dst) < 0) {
        close_if_open((void *)dst);
        *(s16 *)(dst + 0x4) = 0;
        return 0;
    }

    *(u32 *)(dst + 0x2d0) = *(u32 *)(self + 0x2d0);
    *(s16 *)(dst + 0x8) = (s16)((s32)(self - *(u8 **)&tcp_protocol_state) / 0x544);
    *(s16 *)(self + 0x2c6) += 1;
    *(u8 *)(dst + 0x2e8) = *(u8 *)(self + 0x2e8);
    *(u32 *)(dst + 0x53c) = *(u32 *)(self + 0x53c);
    *(u32 *)(dst + 0x540) = *(u32 *)(self + 0x540);
    *(u8 *)(dst + 0xb) = *(u8 *)(self + 0xb);
    *(u16 *)(dst + 0x264) = *(u16 *)(self + 0x264);
    return (s32)dst;
}
extern s32 TLobby__sub_8041D0C8(u8* self, u8* data, s16 total, u8* p6);
extern s32 TLobby__sub_8041D0C8(u8* self, u8* data, s16 total, u8* p6);
struct E_8041A498;
void TLobby__sub_8041A498(E_8041A498 *arg0, s16 arg1);
#define TCP_IDX(tp) ((s16)((s32)((tp) - *(u8 **)&tcp_protocol_state) / 0x544))
#define TCP_MIN(a, b) ((a) < (b) ? (a) : (b))
#define TCP_MAX(a, b) ((a) > (b) ? (a) : (b))
#define TCP_REXMTTHRESH (*(s16 *)((u8 *)&tcp_protocol_state + 0x1e))
#pragma push
#pragma pool_data off
void set_slot_state_and_resume(s16, s32, s16);
void set_thread_state_and_resume(s16, s32, s16);
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
extern s32 TLobby__sub_8041B974(u8 *self, u8 *a, u8 *b) {
    s32 changed = 0;
    u32 flag = 0;
    u32 total = 0;
    u8 *found = 0;
    s16 kind;
    s16 ti_flags;
    s16 blen;
    NetHdr_8041B974 *ti;
    s32 st;
    u32 tmp;
    NetHdr_8041B974 hdr;
    u8 *p = self + 0x18;
    u8 *src;
    u8 *body;
    u16 len;
    u32 rem;
    u8 *ent_new;
    s32 todrop;
    s32 acked;
    s32 ourfinisacked;
    s32 ack;
    s16 rtt;
    s16 srtt;
    s32 TLobby__sub_80422AB8(s32, void (*)(s16, s16, s32, s32), s16, s32, s32, s32);
    s16 compare_sockaddr(u8 *, u8 *);
    s16 is_addr_unspecified(u8 *);
    s16 TLobby__sub_8041B3D4(void *, void *, u16, u16, s32, s32, u8);
    s16 TLobby__sub_8041D368(u8 *);

    *(s32 *)(self + 0x8) = *(s32 *)(self + 0x8) - *(s16 *)(self + 0xc);
    *(s16 *)(self + 0xc) = 0;
    src = TLobby__sub_80406F0C(p + 4);
    NetMemcpy(&hdr.a, src, 2);
    NetMemcpy(&hdr.b, src + 0x2, 2);
    NetMemcpy(&hdr.c, src + 0x4, 4);
    NetMemcpy(&hdr.d, src + 0x8, 4);
    NetMemcpy(&hdr.e, src + 0xc, 1);
    NetMemcpy(&hdr.f, src + 0xd, 1);
    NetMemcpy(&hdr.g, src + 0xe, 2);
    NetMemcpy(&hdr.h, src + 0x10, 2);
    NetMemcpy(&hdr.i, src + 0x12, 2);
    ti = &hdr;
    kind = ti->f;
    ti_flags = kind;
    len = ti->e >> 2;
    if ((u32)*(s32 *)(self + 0x8) < 0x14) {
        return -1;
    }
    if ((u16)TLobby__sub_8040D8F0(a, b, 6, self, 0)) {
        goto drop;
    }
    blen = (s16)(len - 0x14);
    if (blen != 0) {
        body = TLobby__sub_80406F0C(p + 4) + 0x14;
    } else {
        body = 0;
    }
    if (len < 0x14) {
        goto drop;
    }
    if ((u16)*(s32 *)(self + 0x8) < len) {
        goto drop;
    }
    NetMemcpy(&tmp, &ti->c, 4);
    NetMemcpy(&ti->c, &tmp, 4);
    NetMemcpy(&tmp, &ti->d, 4);
    NetMemcpy(&ti->d, &tmp, 4);
    rem = *(s32 *)(self + 0x8) - len;
retry:
    found = 0;
    {
        u8 *ent = *(u8 **)&tcp_protocol_state;
        s16 i;
        for (i = 0; i < *(s16 *)((u8 *)&tcp_protocol_state + 4); ent += 0x544, i++) {
            if (*(u16 *)(ent + 0x4) == 0) {
                continue;
            }
            if (*(s16 *)(ent + 0x6) == 1) {
                continue;
            }
            if (*(s16 *)(ent + 0x6) == -1) {
                continue;
            }
            if (compare_sockaddr(ent + 0x27c, a)) {
                continue;
            }
            if (*(u16 *)(ent + 0x26a) != hdr.a) {
                continue;
            }
            if (*(u16 *)(ent + 0x268) != hdr.b) {
                continue;
            }
            found = ent;
            break;
        }
    }
    if (found == 0) {
        u8 *ent = *(u8 **)&tcp_protocol_state;
        s16 i;
        for (i = 0; i < *(s16 *)((u8 *)&tcp_protocol_state + 4); ent += 0x544, i++) {
            if (*(u16 *)(ent + 0x4) == 0) {
                continue;
            }
            if (*(s16 *)(ent + 0x6) != 1) {
                continue;
            }
            if (*(u16 *)(ent + 0x268) != hdr.b) {
                continue;
            }
            if (compare_sockaddr(ent + 0x27c, a)) {
                if (!is_addr_unspecified(ent + 0x27c)) {
                    continue;
                }
            }
            if (*(u16 *)(ent + 0x26a) == hdr.a || *(u16 *)(ent + 0x26a) == 0) {
                found = ent;
                break;
            }
        }
    }
    if (found == 0) {
        goto dropwithreset;
    }
    st = *(s16 *)(found + 0x6);
    if (!(s16)st) {
        if (found[0xb] & 0x80) {
            goto drop;
        }
        if (found[0xa] & 0x4) {
            goto drop;
        }
    }
    if (st != 1) {
        *(u16 *)(found + 0x244) = 0;
        *(s16 *)(found + 0x260) = *(s16 *)(found + 0x2d4);
    }
    if (body != 0 && *(s16 *)(found + 0x6) != 1) {
        TLobby__sub_8041D0C8(found, body, blen, (u8 *)ti);
    }
    *(u32 *)(found + 0x224) = (u16)(*(u32 *)(found + 0x234) - *(u32 *)(found + 0x228));
    switch (*(s16 *)(found + 0x6)) {
    case 1:
        if (kind & 4) {
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 0xa);
            goto drop;
        }
        if (kind & 0x10) {
            goto dropwithreset;
        }
        if (!(kind & 2)) {
            goto drop;
        }
        if ((s16)is_multicast_address((void *)b, 0) == 1) {
            goto drop;
        }
        ent_new = (u8 *)TLobby__sub_8041B774(found, (u8 *)ti, a, b);
        if (ent_new == 0) {
            goto drop;
        }
        if (body != 0) {
            TLobby__sub_8041D0C8(ent_new, body, blen, (u8 *)ti);
        }
        if (flag) {
            *(u32 *)(ent_new + 0x21c) = flag;
        } else {
            *(u32 *)(ent_new + 0x21c) = *(u32 *)((u8 *)&tcp_protocol_state + 0x18);
        }
        *(u32 *)((u8 *)&tcp_protocol_state + 0x18) += 0xFA00;
        *(u32 *)(ent_new + 0x230) = hdr.c;
        *(u32 *)(ent_new + 0x208) = *(u32 *)(ent_new + 0x20c) = *(u32 *)(ent_new + 0x238) =
            *(u32 *)(ent_new + 0x210) = *(u32 *)(ent_new + 0x2f4) = *(u32 *)(ent_new + 0x324) =
            *(u32 *)(ent_new + 0x21c);
        *(u32 *)(ent_new + 0x234) = *(u32 *)(ent_new + 0x228) = *(u32 *)(ent_new + 0x230) + 1;
        ent_new[0xb] |= 1;
        *(s16 *)(ent_new + 0x6) = 3;
        *(s16 *)(ent_new + 0x260) = 0x96;
        switch (*(s32 *)(ent_new + 0x540)) {
        case 1:
            *(u32 *)(ent_new + 0x23c) = *(u16 *)(ent_new + 0x264);
            break;
        case 2:
            *(u32 *)(ent_new + 0x23c) = *(u16 *)(ent_new + 0x264) * 2;
            break;
        case 3:
            {
                u16 m = *(u16 *)(ent_new + 0x264);
                s32 m2 = m * 2;

                *(u32 *)(ent_new + 0x23c) = TCP_MIN(m * 4, TCP_MAX(m2, 0x111c));
            }
            break;
        default:
            *(u32 *)(ent_new + 0x23c) = get_adjusted_slot_count(ent_new);
            break;
        }
        *(u32 *)(ent_new + 0x2d0) = *(u32 *)(found + 0x2cc);
        *(u32 *)(found + 0x2cc) = 0;
        TLobby__sub_80422AB8((s32)(s16)((s32)(found - *(u8 **)&tcp_protocol_state) / 0x544),
                             (void (*)(s16, s16, s32, s32))*(u32 *)(found + 0x2c8),
                             (s16)((s32)(ent_new - *(u8 **)&tcp_protocol_state) / 0x544), (s32)(ent_new + 0x27c),
                             (s32)*(u16 *)(ent_new + 0x268), (s32)*(u16 *)(ent_new + 0x26a));
        found = ent_new;
        goto trimthenstep6;
    case 2:
        ack = kind & 0x10;
        if (ack && ((s32)(hdr.d - *(u32 *)(found + 0x21c)) <= 0 || (s32)(ti->d - *(u32 *)(found + 0x238)) > 0)) {
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 0xe);
            goto dropwithreset;
        }
        if (kind & 4) {
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 0xa);
            if (ack) {
                TLobby__sub_8041A498((E_8041A498 *)found, 1);
            }
            goto drop;
        }
        if (!(kind & 2)) {
            goto drop;
        }
        if (ack) {
            *(u32 *)(found + 0x208) = hdr.d;
            *(u32 *)(found + 0x2f4) = hdr.d;
            if ((s32)(*(u32 *)(found + 0x20c) - *(u32 *)(found + 0x208)) < 0) {
                *(u32 *)(found + 0x20c) = *(u32 *)(found + 0x208);
            }
        }
        *(s16 *)(found + 0x25c) = 0;
        *(u32 *)(found + 0x230) = hdr.c;
        *(u32 *)(found + 0x234) = *(u32 *)(found + 0x228) = *(u32 *)(found + 0x230) + 1;
        found[0xb] |= 1;
        if (ack && (s32)(*(u32 *)(found + 0x208) - *(u32 *)(found + 0x21c)) > 0) {
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 1);
            *(s16 *)(found + 0x6) = 4;
            *(u16 *)(found + 0x264) = TLobby__sub_8041B724(found);
            switch (*(s32 *)(found + 0x540)) {
            case 1:
                *(u32 *)(found + 0x23c) = *(u16 *)(found + 0x264);
                break;
            case 2:
                *(u32 *)(found + 0x23c) = *(u16 *)(found + 0x264) * 2;
                break;
            case 3:
                {
                u16 m = *(u16 *)(found + 0x264);
                s32 m2 = m * 2;

                *(u32 *)(found + 0x23c) = TCP_MIN(m * 4, TCP_MAX(m2, 0x111c));
            }
                break;
            default:
                *(u32 *)(found + 0x23c) = get_adjusted_slot_count(found);
                break;
            }
            if ((rtt = *(s16 *)(found + 0x246)) != 0) {
                *(s16 *)(found + 0x24c) = rtt << 3;
                *(s16 *)(found + 0x24e) = *(s16 *)(found + 0x246) << 1;
                *(s16 *)(found + 0x254) = (*(s16 *)(found + 0x24c) >> 3) + *(s16 *)(found + 0x24e);
                if (*(u16 *)(found + 0x254) < 2) {
                    *(u16 *)(found + 0x254) = 2;
                } else if (*(u16 *)(found + 0x254) > 0x80) {
                    *(u16 *)(found + 0x254) = 0x80;
                }
                *(s16 *)(found + 0x246) = 0;
            }
        } else {
            *(s16 *)(found + 0x6) = 3;
        }
    trimthenstep6:
        hdr.c++;
        if ((u16)rem > *(u32 *)(found + 0x224)) {
            rem = (u16)*(u32 *)(found + 0x224);
            kind &= ~1;
        }
        *(u32 *)(found + 0x214) = hdr.c - 1;
        *(u32 *)(found + 0x22c) = hdr.c;
        goto step6;
    }
    todrop = *(u32 *)(found + 0x228) - hdr.c;
    if (todrop > 0) {
        if (kind & 2) {
            hdr.c++;
            kind &= ~2;
            if (hdr.i > 1) {
                hdr.i--;
            } else {
                kind &= ~0x20;
            }
            todrop--;
        }
        if (todrop > (u16)rem || (todrop == (u16)rem && !(kind & 1))) {
            if (!(kind & 1) || todrop != (u16)rem + 1) {
                goto dropafterack;
            }
            todrop = (u16)rem;
            kind &= ~1;
            found[0xb] |= 1;
        }
        total += todrop;
        hdr.c += todrop;
        rem -= (u16)todrop;
        if (hdr.i > (u16)todrop) {
            hdr.i -= (u16)todrop;
        } else {
            hdr.i = 0;
            kind &= ~0x20;
        }
    }
    todrop = (hdr.c + (u16)rem) - (*(u32 *)(found + 0x228) + *(u32 *)(found + 0x224));
    if (todrop > 0) {
        if (todrop >= (u16)rem) {
            if ((kind & 2) && *(s16 *)(found + 0x6) == 10 && *(u32 *)(found + 0xd8) == 0 &&
                (s32)(hdr.c - *(u32 *)(found + 0x228)) > 0) {
                flag = *(u32 *)(found + 0x228) + 0x1F400;
                NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 4);
                found[0xb] |= 0x80;
                TLobby__sub_8041B5C0(found);
                goto retry;
            }
            if (*(u32 *)(found + 0x224) == 0 && hdr.c == *(u32 *)(found + 0x228)) {
                found[0xb] |= 1;
            } else {
                goto dropafterack;
            }
        }
        rem -= (u16)todrop;
        kind &= ~(8 | 1);
    }
    if (kind & 4) {
        NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 0xa);
        switch (*(s16 *)(found + 0x6)) {
        case 3:
        case 4:
        case 5:
        case 6:
        case 9:
            *(s16 *)(found + 0x6) = 0;
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 4);
            set_thread_state_and_resume(TCP_IDX(found), *(s32 *)(found + 0x1fc), -5);
            set_slot_state_and_resume(TCP_IDX(found), *(s32 *)(found + 0x200), -5);
            if (TLobby__sub_8041B5C0(found) != 0) {
                *(s16 *)(found + 0x6) = -1;
            }
            goto drop;
        case 7:
        case 8:
        case 10:
            NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 4);
            found[0xb] |= 0x80;
            TLobby__sub_8041B5C0(found);
            goto drop;
        }
    }
    if (kind & 2) {
        goto dropafterack;
    }
    if (!(kind & 0x10)) {
        goto drop;
    }
    switch (*(s16 *)(found + 0x6)) {
    case 3:
        if ((s32)(*(u32 *)(found + 0x208) - hdr.d) > 0 || (s32)(hdr.d - *(u32 *)(found + 0x238)) > 0) {
            goto dropwithreset;
        }
        NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 1);
        *(s16 *)(found + 0x6) = 4;
        *(u16 *)(found + 0x264) = TLobby__sub_8041B724(found);
        switch (*(s32 *)(found + 0x540)) {
        case 1:
            *(u32 *)(found + 0x23c) = *(u16 *)(found + 0x264);
            break;
        case 2:
            *(u32 *)(found + 0x23c) = *(u16 *)(found + 0x264) * 2;
            break;
        case 3:
            {
                u16 m = *(u16 *)(found + 0x264);
                s32 m2 = m * 2;

                *(u32 *)(found + 0x23c) = TCP_MIN(m * 4, TCP_MAX(m2, 0x111c));
            }
            break;
        default:
            *(u32 *)(found + 0x23c) = get_adjusted_slot_count(found);
            break;
        }
        *(u32 *)(found + 0x23c) -= *(u16 *)(found + 0x264);
        *(u32 *)(found + 0x214) = hdr.c - 1;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        if ((s32)(hdr.d - *(u32 *)(found + 0x208)) <= 0 && *(u32 *)(found + 0x208) == *(u32 *)(found + 0x2f4)) {
            if ((u16)rem == 0 && hdr.g == *(u32 *)(found + 0x220)) {
                if (*(s16 *)(found + 0x25c) == 0 || hdr.d != *(u32 *)(found + 0x208)) {
                    found[0xd] = 0;
                } else if (++found[0xd] == (u8)TCP_REXMTTHRESH) {
                    u32 onxt = *(u32 *)(found + 0x20c);
                    u32 win = TCP_MIN(*(u32 *)(found + 0x220), *(u32 *)(found + 0x23c)) / 2 / *(u16 *)(found + 0x264);

                    if (TLobby__sub_8041D368(found) == 0) {
                        *(u32 *)(found + 0x2f4) = *(u32 *)(found + 0x20c);
                        found[0xd]--;
                        goto newreno;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    *(u32 *)(found + 0x240) = win * *(u16 *)(found + 0x264);
                    *(s16 *)(found + 0x25c) = 0;
                    *(s16 *)(found + 0x246) = 0;
                    *(u32 *)(found + 0x20c) = hdr.d;
                    *(u32 *)(found + 0x23c) = *(u16 *)(found + 0x264);
                    TLobby__sub_8041A9AC((int)found);
                    *(u32 *)(found + 0x23c) = *(u32 *)(found + 0x240) + *(u16 *)(found + 0x264) * found[0xd];
                    if ((s32)(onxt - *(u32 *)(found + 0x20c)) > 0) {
                        *(u32 *)(found + 0x20c) = onxt;
                    }
                    goto drop;
                } else if (found[0xd] > (u8)TCP_REXMTTHRESH) {
                    *(u32 *)(found + 0x23c) += *(u16 *)(found + 0x264);
                    TLobby__sub_8041A9AC((int)found);
                    goto drop;
                }
            } else {
                found[0xd] = 0;
            }
            break;
        }
    newreno:
        if ((s32)(*(u32 *)(found + 0x208) - *(u32 *)(found + 0x2f4)) < 0 && (s32)(hdr.d - *(u32 *)(found + 0x2f4)) < 0) {
            if ((u16)rem == 0 && hdr.g <= *(u32 *)(found + 0x220)) {
                if (hdr.d != *(u32 *)(found + 0x208)) {
                    acked = hdr.d - *(u32 *)(found + 0x208);
                    TLobby__sub_8041FFF8(acked, (int)found);
                    *(u32 *)(found + 0x220) -= acked;
                    if (hdr.g > *(u32 *)(found + 0x220)) {
                        *(u32 *)(found + 0x220) = hdr.g;
                    }
                    *(u32 *)(found + 0x208) = hdr.d;
                }
                if (++found[0xd] == (u8)TCP_REXMTTHRESH) {
                    u32 win = TCP_MIN(*(u32 *)(found + 0x220), *(u32 *)(found + 0x23c)) / 2 / *(u16 *)(found + 0x264);

                    *(s32 *)(found + 0x2f0) = *(u32 *)(found + 0x20c) - *(u32 *)(found + 0x208) -
                                              *(u16 *)(found + 0x264) * found[0xd] - *(u16 *)(found + 0x264);
                    if (*(s32 *)(found + 0x2f0) < 0) {
                        *(s32 *)(found + 0x2f0) = 0;
                    }
                    if (win < 2) {
                        win = 2;
                    }
                    *(u32 *)(found + 0x240) = win * *(u16 *)(found + 0x264);
                    *(s16 *)(found + 0x25c) = 0;
                    *(s16 *)(found + 0x246) = 0;
                    *(u32 *)(found + 0x23c) = *(s32 *)(found + 0x2f0) + *(u16 *)(found + 0x264);
                    TLobby__sub_8041A9AC((int)found);
                    *(u32 *)(found + 0x23c) = *(u32 *)(found + 0x240);
                    goto drop;
                } else if (found[0xd] > (u8)TCP_REXMTTHRESH) {
                    *(s32 *)(found + 0x2f0) -= *(u16 *)(found + 0x264);
                    TLobby__sub_8041A9AC((int)found);
                    goto drop;
                }
            } else if (hdr.g > *(u32 *)(found + 0x220)) {
                *(u32 *)(found + 0x220) = hdr.g;
            } else {
                found[0xd] = 0;
            }
            break;
        }
        reset_slot_index((void *)found);
        *(s32 *)(found + 0x2f0) = 0;
        *(u32 *)(found + 0x2f4) = hdr.d;
        if (found[0xd] > TCP_REXMTTHRESH && *(u32 *)(found + 0x23c) > *(u32 *)(found + 0x240)) {
            *(u32 *)(found + 0x23c) = *(u32 *)(found + 0x240);
        }
        found[0xd] = 0;
        if ((s32)(hdr.d - *(u32 *)(found + 0x238)) > 0) {
            goto dropafterack;
        }
        acked = hdr.d - *(u32 *)(found + 0x208);
        if ((rtt = *(s16 *)(found + 0x246)) != 0 && (s32)(hdr.d - *(u32 *)(found + 0x248)) > 0) {
            s16 delta;

            if ((srtt = *(s16 *)(found + 0x24c)) != 0) {
                delta = rtt - 1 - (srtt >> 3);
                if ((*(s16 *)(found + 0x24c) += delta) <= 0) {
                    *(s16 *)(found + 0x24c) = 1;
                }
                if (delta < 0) {
                    delta = -delta;
                }
                delta -= *(s16 *)(found + 0x24e) >> 2;
                if ((*(s16 *)(found + 0x24e) += delta) <= 0) {
                    *(s16 *)(found + 0x24e) = 1;
                }
            } else {
                *(s16 *)(found + 0x24c) = rtt << 3;
                *(s16 *)(found + 0x24e) = *(s16 *)(found + 0x246) << 1;
            }
            *(s16 *)(found + 0x246) = 0;
        }
        if (acked > 0 && *(u32 *)(found + 0x258) != 0) {
            *(u32 *)(found + 0x258) = 0;
            *(s16 *)(found + 0x254) = (*(s16 *)(found + 0x24c) >> 3) + *(s16 *)(found + 0x24e);
            if (*(u16 *)(found + 0x254) < 2) {
                *(u16 *)(found + 0x254) = 2;
            } else if (*(u16 *)(found + 0x254) > 0x80) {
                *(u16 *)(found + 0x254) = 0x80;
            }
        }
        if (hdr.d == *(u32 *)(found + 0x238)) {
            if (*(s16 *)(found + 0x25c) != 0) {
                *(s16 *)(found + 0x25c) = 0;
                *(u32 *)(found + 0x258) = 0;
            }
            changed = 1;
        } else if (*(s16 *)(found + 0x25e) == 0) {
            *(s16 *)(found + 0x25c) = *(s16 *)(found + 0x254);
        }
        if (acked == 0) {
            break;
        }
        {
            u32 cw = *(u32 *)(found + 0x23c);
            u16 incr = *(u16 *)(found + 0x264);

            if (cw > *(u32 *)(found + 0x240)) {
                incr = TCP_MAX(incr * incr / cw, 1);
            }
            *(u32 *)(found + 0x23c) = (u16)TCP_MIN((s32)(cw + incr), 0xFFFF);
        }
        {
            s32 n = get_score((void *)found);

            if (acked > n) {
                ourfinisacked = 1;
            } else {
                n = acked;
                ourfinisacked = 0;
            }
            TLobby__sub_8041FFF8(n, (int)found);
            *(u32 *)(found + 0x220) -= (u16)n;
        }
        *(u32 *)(found + 0x208) = hdr.d;
        if ((s32)(*(u32 *)(found + 0x20c) - *(u32 *)(found + 0x208)) < 0) {
            *(u32 *)(found + 0x20c) = *(u32 *)(found + 0x208);
        }
        switch (*(s16 *)(found + 0x6)) {
        case 6:
            if (ourfinisacked) {
                if (found[0xa] & 4) {
                    *(s16 *)(found + 0x262) = *(s16 *)((u8 *)&tcp_protocol_state + 0x24);
                }
                *(s16 *)(found + 0x6) = 9;
            }
            break;
        case 7:
            if (ourfinisacked) {
                *(s16 *)(found + 0x6) = 10;
                if ((u32)get_score((void *)found) == 0) {
                    close_if_open((void *)found);
                }
                if ((u32)get_field_d8((void *)found) == 0) {
                    TLobby__sub_8041EB74(found);
                }
                clear_position((void *)found);
                *(s16 *)(found + 0x262) = 0x78;
            }
            break;
        case 8:
            if (ourfinisacked) {
                NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 4);
                TLobby__sub_8041B5C0(found);
                goto drop;
            }
            break;
        case 10:
            *(s16 *)(found + 0x262) = 0x78;
            goto dropafterack;
        }
        break;
    }
step6:
    if ((kind & 0x10) &&
        ((s32)(*(u32 *)(found + 0x214) - hdr.c) < 0 ||
         (*(u32 *)(found + 0x214) == hdr.c &&
          ((s32)(*(u32 *)(found + 0x218) - hdr.d) < 0 ||
           (*(u32 *)(found + 0x218) == hdr.d && hdr.g > *(u32 *)(found + 0x220)))))) {
        *(u32 *)(found + 0x220) = hdr.g;
        *(u32 *)(found + 0x214) = hdr.c;
        *(u32 *)(found + 0x218) = hdr.d;
        if (*(u32 *)(found + 0x220) > *(u32 *)(found + 0x250)) {
            *(u32 *)(found + 0x250) = *(u32 *)(found + 0x220);
        }
        changed = 1;
    }
    if ((kind & 0x20) && hdr.i != 0 && !(found[0xb] & 0x08)) {
        if ((u32)get_queue_diff((void *)found) + hdr.i > 0x10000) {
            hdr.i = 0;
            kind &= ~0x20;
        } else {
            u32 t = hdr.c + hdr.i;

            if ((s32)(t - *(u32 *)(found + 0x22c)) > 0) {
                *(u32 *)(found + 0x22c) = t;
            }
        }
    } else if (*(u32 *)(found + 0x228) != *(u32 *)(found + 0x22c)) {
        *(u32 *)(found + 0x22c) = *(u32 *)(found + 0x228);
    }
    if (((u16)rem != 0 || (kind & 1)) && !(found[0xb] & 0x08)) {
        if (hdr.c == *(u32 *)(found + 0x228) && (*(s16 *)(found + 6) == 4 || (found[0xa] & 0x0c))) {
            s32 off;

            kind = ti_flags & 1;
            *(u32 *)(found + 0x228) += (u16)rem;
            off = len + total;
            if (!(found[0xa] & 0x04)) {
                TLobby__sub_8041F204(self, off, found);
            }
            if (*(u32 *)(found + 0x53c) == 0) {
                if (*(s16 *)(found + 0x538) == 0) {
                    *(s16 *)(found + 0x538) = (s16)(*(s16 *)((u8 *)&tcp_protocol_state + 0xa0) / 100);
                }
            } else {
                found[0xb] |= 1;
            }
            goto L1397;
        } else if ((s32)(hdr.c - *(u32 *)(found + 0x228)) > 0) {
            TLobby__sub_8041F914(self, (u16)(len + total), found, (u8 *)ti);
            kind &= ~1;
            found[0xb] |= 1;
            goto L1397;
        }
    }
    kind &= ~1;
L1397:
    if (!(kind & 1)) {
        goto L1469;
    }
    NetDispatchSocketEvent(TCP_IDX(found), *(s32 *)(found + 0x2d0), 3, 2);
    if (!(found[0xb] & 0x08)) {
        TLobby__sub_8041F11C(found);
    }
    found[0xb] |= 1;
    *(u32 *)(found + 0x228) += 1;
    found[0xb] |= 8;
    switch (*(s16 *)(found + 6)) {
    case 3:
    case 4:
        *(s16 *)(found + 6) = 5;
        break;
    case 6:
        *(s16 *)(found + 6) = 7;
        break;
    case 9:
        *(s16 *)(found + 6) = 10;
        if ((u32)get_score((void *)found) == 0) {
            close_if_open((void *)found);
        }
        if ((u32)get_field_d8((void *)found) == 0) {
            TLobby__sub_8041EB74(found);
        }
        clear_position((void *)found);
        *(s16 *)(found + 0x262) = 0x78;
        break;
    case 10:
        *(s16 *)(found + 0x262) = 0x78;
        break;
    }
L1469:
    if (changed != 0 || (found[0xb] & 1)) {
        TLobby__sub_8041A9AC((int)found);
    }
    return 0;

dropafterack:
    if (kind & 4) {
        goto drop;
    }
    found[0xb] |= 1;
    TLobby__sub_8041A9AC((int)found);
    return 0;

dropwithreset:
    if (kind & 4) {
        goto drop;
    }
    if ((s16)is_multicast_address((void *)b, 0) == 1) {
        goto drop;
    }
    if (kind & 0x10) {
        if (TLobby__sub_8041B3D4(a, b, hdr.b, hdr.a, hdr.d, 0, 4) < 0) {
            return -1;
        }
    } else {
        if (!(kind & 2)) {
            goto drop;
        }
        rem++;
        if (TLobby__sub_8041B3D4(a, b, hdr.b, hdr.a, 0, (u16)rem + hdr.c, 0x14) < 0) {
            return -1;
        }
    }
    return 0;

drop:
    return 0;
}
#pragma pop
#pragma pop

#pragma push
#pragma cplusplus off
s32 TLobby__sub_8041D524(A_8041D524 *a, s32 x);
#pragma pop
#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimize_for_size off
#pragma dont_inline off
s32 TLobby__sub_8041D0C8(u8 *self, u8 *data, s16 total, u8 *p6)
{
  void TLobby__sub_8041D584(u8 *self, u8 *p6, u8 *tbl, s16 n);
  s16 TLobby__sub_8041D524(u8 *, s32);
  s32 n;
  s16 done = 0;
  u8 sz;
  s16 k;
  s32 last;
  u8 *p;
  u8 *e;
  u16 tmp16;
  u32 tmp;
  while (done < total)
  {
    if (data[0] == 0)
    {
      break;
    }
    if (data[0] == 1)
    {
      sz = 1;
    }
    else
    {
      sz = data[1];
      switch (data[0])
      {
        case 2:
          e = p6;
          if ((sz == 4) && (e[0xd] & 2))
        {
          NetMemcpy(&tmp16, data + 2, 2);
          *((u16 *) (self + 0x266)) = tmp16;
        }
          break;

        case 4:
          if ((sz == 2) && (self[0x2e8] & 1))
        {
          self[0x2e8] |= 2;
        }
          break;

        case 5:
        {
          u8 *tbl = (*((u8 (*)[]) (&tcp_protocol_state))) + 0x78;
          last = *((s32 *) (self + 0x208));
          if (((sz - 2) % 8) != 0)
          {
            break;
          }
          if ((sz > 0x22) || (sz < 0xa))
          {
            break;
          }
          e = tbl;
          p = data + 2;
          n = (sz - 2) / 8;
          for (k = 0; k < n; k++)
          {
            NetMemcpy(&tmp, p, 4);
            *((u32 *) e) = tmp;
            NetMemcpy(&tmp, p + 4, 4);
            p += 8;
            *((u32 *) (e + 4)) = tmp;
            if (((*((s32 *) (e + 4))) - last) > 0)
            {
              last = *((s32 *) (e + 4));
            }
            e += 8;
          }

          TLobby__sub_8041D584(self, e, tbl, (s16) n);
          if (TLobby__sub_8041D524(self, last) != 0)
          {
            *((s32 *) (self + 0x328)) = *((s32 *) (self + 0x208));
          }
        }
          break;

      }

    }
    done += sz;
    data += sz;
  }

  *((u16 *) (self + 0x264)) = ((*((u16 *) (self + 0x266))) < ((s16) TLobby__sub_8041B724(self))) ? (*((u16 *) (self + 0x266))) : ((s16) TLobby__sub_8041B724(self));
  return 0;
}
#pragma pop

typedef struct G_8041A1D8 { u8 pad[4]; s16 n; } G_8041A1D8;
s32 TLobby__sub_8041A1D8(void) {
    NetUnregisterTimer((void *)TLobby__sub_8041A5B4);
    NetUnregisterTimer((void *)TLobby__sub_8041A3CC);
    TLobby__sub_803F8794((void *)&tcp_protocol_state);
    ((G_8041A1D8 *)&tcp_protocol_state)->n = 0;
    return 0;
}

typedef struct E_8041A498 { u8 pad0[6]; s16 f6; u8 pad8[6]; u8 fE; u8 padF[0x1ED]; s32 f1FC; s32 f200; u8 pad204[0xCC]; s32 f2D0; u8 pad2D4[0x270]; } E_8041A498;
void set_slot_state_and_resume(s16, s32, s16);
void set_thread_state_and_resume(s16, s32, s16);
void TLobby__sub_8041A498(E_8041A498 *arg0, s16 arg1) {
    s16 idx = arg0 - (E_8041A498 *)tcp_protocol_state.p;

    if (arg0->f6 >= 3) {
        arg0->f6 = 0;
        TLobby__sub_8041A9AC((int)arg0);
    }
    arg0->fE = arg1;
    switch (arg1) {
    case 4:
        set_thread_state_and_resume(idx, arg0->f1FC, -8);
        set_slot_state_and_resume(idx, arg0->f200, -8);
        NetDispatchSocketEvent(idx, arg0->f2D0, 3, 0xB);
        break;
    default:
        set_thread_state_and_resume(idx, arg0->f1FC, -5);
        set_slot_state_and_resume(idx, arg0->f200, -5);
        NetDispatchSocketEvent(idx, arg0->f2D0, 3, 0xA);
        break;
    }
    if (TLobby__sub_8041B5C0(arg0) != 0) {
        arg0->f6 = -1;
    }
}

extern void TLobby__sub_8041A5B4(void) {
    s32 TLobby__sub_8041A6A4(p8040EE4C_Unk805BDF48Rec* rec, s32 idx);
    s16* t;
    p8040EE4C_Unk805BDF48* g = (p8040EE4C_Unk805BDF48*)((u8*)&tcp_protocol_state);
    p8040EE4C_Unk805BDF48Rec* rec;
    s16 i;
    s32 j;

    g->unk24 = g->unk20 << 3;
    rec = g->entries;
    for (i = 0; i < g->count; rec++, i++) {
        if (rec->flags != 0 && rec->flags == 1) {
            t = (s16*)rec;
            for (j = 0; (s16)j < 4; t++, j++) {
                if (t[0x12e] > 0) {
                    t[0x12e]--;
                    if (t[0x12e] == 0) {
                        TLobby__sub_8041A6A4(rec, j);
                    }
                }
            }
            rec->unk244++;
            if (rec->unk246 != 0) {
                rec->unk246++;
            }
        }
    }
    g->unk18 += 0x10000 - 0x600;
}

#pragma push
#pragma opt_common_subs on
typedef struct Tcb_8041A6A4 Tcb_8041A6A4;
struct Tcb_8041A6A4 {
    u8 pad0[4];
    u16 state;
    s16 t_state;
    u8 pad8[3];
    u8 flags;
    u8 force;
    u8 padD[0x1FB];
    u32 snd_una;
    u32 snd_nxt;
    u8 pad210[0x10];
    u32 snd_wnd;
    u8 pad224[4];
    u32 rcv_nxt;
    u8 pad22C[0x10];
    u32 snd_cwnd;
    u32 snd_ssthresh;
    s16 idle;
    s16 rtt;
    u8 pad248[4];
    s16 srtt;
    s16 rttvar;
    u8 pad250[4];
    u16 rxtcur;
    u8 pad256[2];
    u32 rxtshift;
    s16 timers[4];
    u16 maxseg;
    u8 pad266[2];
    u16 f268;
    u16 f26A;
    u8 pad26C[0x10];
    u8 remote[0x14];
    u8 local[0x14];
    u8 pad2A4[0x30];
    s16 f2D4;
    u8 pad2D6[0x16];
    s32 f2EC;
    s32 f2F0;
    u32 f2F4;
    u8 pad2F8[0x240];
    s16 ack_delay;
    u8 pad53A[0xA];
};
typedef struct G_8041A6A4 G_8041A6A4;
struct G_8041A6A4 {
    Tcb_8041A6A4 *ents;
    s16 count;
    u8 pad6[0x12];
    s32 iss;
    u8 pad1C[4];
    s16 keepintvl;
    s16 keepidle;
    s16 maxidle;
    u8 pad26[0x36];
    s16 backoff[13];
    u8 pad76[0x2A];
    s16 ack_ticks;
};
extern s32 TLobby__sub_8041A6A4(Tcb_8041A6A4 *tcb, s16 timer) {
    void TLobby__sub_8041B3D4(u8 *, u8 *, u16, u16, u32, u32, s32);
    G_8041A6A4 *g = (G_8041A6A4 *)&tcp_protocol_state;
    s16 keep;
    s32 win;
    s32 rexmt;
    s32 t;

    switch (timer) {
    case 3:
        if (tcb->t_state != 10 && tcb->idle <= g->maxidle) {
            tcb->timers[3] = g->keepintvl;
        } else {
            TLobby__sub_8041B5C0(tcb);
        }
        break;
    case 0:
        tcb->rxtshift++;
        if (tcb->rxtshift > 12) {
            tcb->rxtshift = 12;
            TLobby__sub_8041A498((E_8041A498 *)tcb, 4);
            break;
        }
        rexmt = (tcb->srtt >> 3) + tcb->rttvar;
        rexmt *= g->backoff[tcb->rxtshift];
        tcb->rxtcur = rexmt;
        if (tcb->rxtcur < 2) {
            tcb->rxtcur = 2;
        } else if (tcb->rxtcur > 128) {
            tcb->rxtcur = 128;
        }
        tcb->timers[0] = tcb->rxtcur;
        if (tcb->rxtshift > 3) {
            tcb->rttvar += tcb->srtt >> 3;
            tcb->srtt = 0;
        }
        reset_slot_index((void *)tcb);
        tcb->f2EC = 0;
        tcb->f2F0 = 0;
        tcb->f2F4 = tcb->snd_una;
        tcb->snd_nxt = tcb->snd_una;
        tcb->rtt = 0;
        win = ((tcb->snd_wnd < tcb->snd_cwnd) ? tcb->snd_wnd : tcb->snd_cwnd) / 2 / tcb->maxseg;
        if (win < 2) {
            win = 2;
        }
        tcb->snd_cwnd = tcb->maxseg;
        tcb->snd_ssthresh = win * tcb->maxseg;
        TLobby__sub_8041A9AC((int)tcb);
        break;
    case 1:
        t = ((tcb->srtt >> 2) + tcb->rttvar) >> 1;
        tcb->timers[1] = t * g->backoff[tcb->rxtshift];
        if (tcb->timers[1] < 10) {
            tcb->timers[1] = 10;
        } else if (tcb->timers[1] > 120) {
            tcb->timers[1] = 120;
        }
        if (tcb->rxtshift < 12) {
            tcb->rxtshift++;
        }
        tcb->force = 1;
        TLobby__sub_8041A9AC((int)tcb);
        tcb->force = 0;
        break;
    case 2:
        if (tcb->t_state < 4) {
            goto drop;
        }
        keep = tcb->f2D4;
        if (keep != 0 && tcb->t_state <= 5) {
            if (tcb->idle >= keep + ((g->maxidle < keep * 8) ? g->maxidle : keep * 8)) {
                goto drop;
            }
            TLobby__sub_8041B3D4(tcb->remote, tcb->local, tcb->f268, tcb->f26A, tcb->snd_una - 1, tcb->rcv_nxt, 16);
            tcb->timers[2] = (g->keepintvl < tcb->f2D4) ? g->keepintvl : tcb->f2D4;
        } else if (keep != 0) {
            tcb->timers[2] = keep;
        } else {
            tcb->timers[2] = g->keepidle;
        }
        break;
    drop:
        TLobby__sub_8041A498((E_8041A498 *)tcb, 4);
        break;
    }
    return 0;
}
#pragma pop

void insert_item_at(void *self, s16 idx, s32 a, s32 b) {
    O_8041D2B8 *o = (O_8041D2B8 *)self;
    s16 i;
    s16 n;
    if (idx < 0) {
        return;
    }
    n = o->n;
    if (idx > n + 1) {
        return;
    }
    if (idx > 0x1F) {
        return;
    }
    if (n >= 0x1F) {
        o->n = 0x1E;
    }
    for (i = o->n; i >= idx; i--) {
        o->items[i + 1] = o->items[i];
    }
    o->items[idx].a = a;
    o->items[idx].b = b;
    o->items[idx].c = b;
    o->items[idx].d = o->f238;
    o->n++;
}

s32 TLobby__sub_8041D368(u8 *arg0) {
    typedef struct Fields_arg0 { u8 pad_0[800]; s16 field_320; } Fields_arg0;
    if ((s16) ((Fields_arg0*)arg0)->field_320 == -1) {
        return 1;
    }
    return 0;
}

void reset_slot_index(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s16 *)((s8 *)arg0 + 0x320) = -1;
    *(s32 *)((s8 *)arg0 + 0x328) = (s32) *(s32 *)((s8 *)arg0 + 0x324);
}

void TLobby__sub_8041D398(u8* self, s32 a, s32 b) {
    u8* p = self;
    u8* q = self;
    s16 i;
    s32 key;
    *(s32*)(self + 0x2ec) += b - a;
    for (i = 0; i <= *(s16*)(self + 0x320); p += 0x10, q += 0x10, i++) {
        key = *(s32*)(p + 0x330);
        if (a - key < 0) {
            if (i == 0) {
                if (b - key <= 0) {
                    if (b - *(s32*)(self + 0x328) < 0) {
                        return;
                    }
                    *(s32*)(self + 0x328) = b;
                    *(s32*)(self + 0x32c) = *(s32*)(self + 0x238);
                    return;
                } else {
                    *(s32*)(self + 0x328) = key;
                    *(s32*)(self + 0x32c) = *(s32*)(self + 0x238);
                }
            } else {
                if (b - key <= 0) {
                    u8* e = self;
                    s32 off = i * 16;
                    e += off;
                    if (b - *(s32*)(e += 0x328) < 0) {
                        return;
                    }
                    *(s32*)e = b;
                    e = self;
                    e += off;
                    *(s32*)(e + 0x32c) = *(s32*)(self + 0x238);
                    return;
                } else {
                    *(s32*)(q + 0x328) = key;
                    *(s32*)(q + 0x32c) = *(s32*)(self + 0x238);
                }
            }
        }
    }
}

#pragma push
#pragma cplusplus off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma optimize_for_size off
#pragma dont_inline off
s32 TLobby__sub_8041D460(u8* self, s32* p1, s32* p2) {
    u8* f;
    u8* e;
    s32 cnt = (*(s16 *)((u8 *)self + 0x320));
    s16 i;
    if (cnt == -1) {
        *p2 = 0;
        *p1 = 0;
        return 0;
    }
    if ((*(s32 *)((u8 *)self + 0x328)) - (*(s32 *)((u8 *)self + 0x330)) < 0) {
        *p1 = (*(s32 *)((u8 *)self + 0x328));
        *p2 = (*(s32 *)((u8 *)self + 0x330));
        return *p2 - *p1;
    }
    e = self;
    f = self;
    for (i = 0; i < cnt; i++) {
        if ((*(s32 *)((u8 *)f + 0x338)) - (*(s32 *)((u8 *)e + 0x340)) < 0) {
            e = self + i * 0x10;
            *p1 = (*(s32 *)((u8 *)e + 0x338));
            *p2 = (*(s32 *)((u8 *)e + 0x340));
            return *p2 - *p1;
        }
        e += 0x10;
        f += 0x10;
    }
    *p2 = 0;
    *p1 = 0;
    return 0;
}
#pragma pop

typedef struct A_8041D524 { u8 pad[0x320]; s16 n; u8 pad2[0xA]; s32 v0; u8 pad3[0xC]; s32 v1; } A_8041D524;
s32 TLobby__sub_8041D524(A_8041D524 *a, s32 x) {
    s16 n = a->n;
    s16 i;
    if (n == -1) { return 0; }
    if (a->v0 - x < 0) { return 1; }
    for (i = 0; i < n; i++) {
        if (a->v1 - x < 0) { return 1; }
        a = (A_8041D524 *)((u8 *)a + 0x10);
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
typedef struct Th_8041D584 {
    u8 pad0[8];
    s32 ack;
} Th_8041D584;
typedef struct Sack_8041D584 {
    s32 start;
    s32 end;
} Sack_8041D584;
typedef struct Seg_8041D584 { s32 start; s32 end; s32 edge; s32 stamp; } Seg_8041D584;
typedef struct Tcb_8041D584 {
    u8 pad0[0x238];
    s32 now;
    u8 pad23C[0xB0];
    s32 f2EC;
    u8 pad2F0[0x30];
    s16 n;
    u8 pad322[2];
    s32 una;
    s32 edge;
    s32 stamp;
    Seg_8041D584 items[32];
} Tcb_8041D584;
inline void remove_8041D584(Tcb_8041D584 *tcb, s16 idx) {
    s16 n = tcb->n;
    s16 i;
    if (n >= 0 && idx >= 0 && idx <= n) {
        for (i = idx; i < tcb->n; i++) {
            tcb->items[i] = tcb->items[i + 1];
        }
        tcb->n--;
    }
}
void TLobby__sub_8041D584(Tcb_8041D584 *tcb, Th_8041D584 *th, Sack_8041D584 *blocks, s16 n) {
    s16 i;
    s16 j;
    s32 d;

    if (th->ack - tcb->una > 0) {
        for (;;) {
            if (tcb->n < 0) {
                break;
            }
            if (th->ack - tcb->edge > 0) {
                tcb->f2EC -= tcb->edge - tcb->una;
                tcb->edge = th->ack;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            } else {
                tcb->f2EC -= th->ack - tcb->una;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            if (th->ack - tcb->items[0].end >= 0) {
                tcb->edge = tcb->items[0].edge;
                tcb->stamp = tcb->items[0].stamp;
                tcb->una = tcb->items[0].end;
                remove_8041D584(tcb, 0);
                continue;
            }
            if (th->ack - tcb->items[0].start >= 0) {
                tcb->n = -1;
                tcb->edge = tcb->una;
            }
            break;
        }
        tcb->una = th->ack;
    }

    for (i = 0; i < n; i++) {
        s32 end = blocks[i].end;
        s32 start = blocks[i].start;
        Sack_8041D584 *b = &blocks[i];
        if (start - end >= 0) {
            continue;
        }
        if (tcb->n == -1) {
            tcb->edge = th->ack;
            tcb->stamp = tcb->now;
            insert_item_at(tcb, 0, b->start, b->end);
            continue;
        }
        if (end - tcb->una <= 0) {
            continue;
        }
        if (start - tcb->una <= 0) {
            tcb->n = -1;
            tcb->edge = tcb->una;
            continue;
        }
        if (start - tcb->items[0].start <= 0) {
            if (start - tcb->edge < 0) {
                tcb->f2EC -= tcb->edge - start;
                tcb->edge = b->start;
                if (tcb->f2EC < 0) {
                    tcb->f2EC = 0;
                }
            }
            insert_item_at(tcb, 0, b->start, b->end);
            j = 0;
        } else {
            for (j = 1; j <= tcb->n; j++) {
                if (b->start - tcb->items[j].start > 0) {
                    continue;
                }
                if (b->start - tcb->items[j - 1].end < 0) {
                    if (b->end - tcb->items[j - 1].end < 0) {
                        continue;
                    }
                    if (end - tcb->items[j - 1].edge > 0) {
                        tcb->f2EC -= tcb->items[j - 1].edge - tcb->items[j - 1].end;
                        tcb->items[j - 1].end = b->end;
                        tcb->items[j - 1].edge = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    } else {
                        tcb->f2EC -= end - tcb->items[j - 1].end;
                        tcb->items[j - 1].end = b->end;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    j = j - 1;
                } else {
                    if (start - tcb->items[j - 1].edge < 0) {
                        tcb->f2EC -= tcb->items[j - 1].edge - start;
                        tcb->items[j - 1].edge = b->start;
                        if (tcb->f2EC < 0) {
                            tcb->f2EC = 0;
                        }
                    }
                    insert_item_at(tcb, j, b->start, b->end);
                }
                break;
            }
            if (j == tcb->n + 1) {
                insert_item_at(tcb, j, b->start, b->end);
                continue;
            }
        }
        while (j + 1 <= tcb->n && tcb->items[j].end - tcb->items[j + 1].start >= 0) {
            d = tcb->items[j].end - tcb->items[j + 1].end;
            if (0 <= d) {
                if (tcb->items[j + 1].edge - tcb->items[j].end > 0) {
                    tcb->f2EC -= d;
                    tcb->items[j].edge = tcb->items[j + 1].edge;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                } else {
                    tcb->f2EC -= tcb->items[j + 1].edge - tcb->items[j + 1].end;
                    remove_8041D584(tcb, j + 1);
                    if (tcb->f2EC < 0) {
                        tcb->f2EC = 0;
                    }
                }
            } else {
                tcb->items[j].end = tcb->items[j + 1].end;
                tcb->items[j].edge = tcb->items[j + 1].edge;
                remove_8041D584(tcb, j + 1);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma pool_data off
s16 tcp_get_socket_handle(s16 i) {
    s16 r;
    if (i < 0 || i >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[i].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) { return -4; }
    return tcp_protocol_state.p[i].f6;
}
#pragma pop

s32 TLobby__sub_8041ED8C(int, void *, void *, void *);
#pragma push
#pragma pool_data off
s32 TLobby__sub_8041DBD4(s16 arg0, s32 arg1, s32 len, s32 arg3) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    switch (e->f6) {
    case 0:
    case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        if ((*(u8 *)((s8 *)e + 0xA) & 4) && (*(u8 *)((s8 *)e + 0xCC) == 0 || (u32)get_field_d8((void *)e) == 0)) {
            return -4;
        }
        break;
    }
    return TLobby__sub_8041ED8C((int)e, (void *)arg1, (void *)len, (void *)arg3);
}
#pragma pop

#pragma push
#pragma pool_data off
s32 tcp_start_send(s16 arg0, u8 *arg1, void (*completion)(s16, s16), u8 arg3) {
    s16 r;
    s16 v;
    s32 ret;
    E_805C1D48 *e;
    s32 TLobby__sub_8041A9AC(int);
    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    v = e->f6;
    if (v <= 1) {
        return -4;
    }
    if (v < 4) {
        return -4;
    }
    if (v > 5 && (*(u8 *)((s8 *)e + 0xA) & 8)) {
        return -4;
    }
    TLobby__sub_80420BD0(arg1, e, (s32)completion);
    if (arg3 != 0) {
        *(s32 *)((s8 *)e + 0x210) = *(s32 *)((s8 *)e + 0x20C) + *(s32 *)((s8 *)arg1 + 8);
    }
    ret = ((s32)TLobby__sub_8041A9AC((int)e));
    TLobby__sub_8041FFF8(0, (int)e);
    return ret;
}
#pragma pop

#pragma push
#pragma pool_data off
typedef struct TcpRecord_805BDF48 {
    u8 pad0[4];
    u16 flags;
    s16 type;
    u8 pad8[3];
    u8 unkB;
    u8 padC[0x244 - 0xC];
    s16 unk244;
    s16 unk246;
    u8 pad248[0x25C - 0x248];
    s16 timers[4];
    u8 pad264[0x544 - 0x264];
} TcpRecord_805BDF48;
typedef struct TcpTable_805BDF48 {
    TcpRecord_805BDF48 *entries;
    s16 count;
    s16 cur;
} TcpTable_805BDF48;
s32 TLobby__sub_8041DE1C(s16 idx, s16 cmd, u32 *arg)
{
  u8 *e;
  u8 *g;
  u16 v;
  s16 rc;
  if ((idx < 0) || (idx >= ((TcpTable_805BDF48 *)&tcp_protocol_state)->count))
  {
    rc = -4;
  }
  else
    if (((TcpTable_805BDF48 *)&tcp_protocol_state)->entries[idx].flags != 1)
  {
    rc = -4;
  }
  else
  {
    rc = 0;
  }
  if (rc < 0)
  {
    return -4;
  }
  g = (u8 *)&tcp_protocol_state;
  e = *((u8 **) g);
  e = e + (idx * 0x544);
  switch (cmd)
  {
    case 0x8:
      *((s16 *) (((u8 *) e) + 0x2d4)) = (*arg) << 1;
      *((s16 *) (((u8 *) e) + 0x260)) = *((s16 *) (((u8 *) e) + 0x2d4));
      *((s16 *) (((u8 *) e) + 0x244)) = 0;
      break;

    case 0x1001:
      if ((*arg) > (*((u32 *) (((u8 *) g) + 0x8))))
    {
      return -2;
    }
      *((s32 *) (((u8 *) e) + 0x530)) = *arg;
      break;

    case 0x1002:
      if ((*arg) > (*((u32 *) (((u8 *) g) + 0xc))))
    {
      return -2;
    }
      *((s32 *) (((u8 *) e) + 0x534)) = *arg;
      break;

    case 0x2001:
      if ((*arg) != 0)
    {
      *((s32 *) (((u8 *) e) + 0x53c)) = 1;
    }
    else
    {
      *((s32 *) (((u8 *) e) + 0x53c)) = 0;
    }
      break;

    case 0x2002:
      if ((*arg) != 0)
    {
      *((s8 *) (((u8 *) e) + 0x2e8)) |= 1;
    }
    else
    {
      *((s8 *) (((u8 *) e) + 0x2e8)) &= ~1;
    }
      break;

    case 0x2004:
      if ((*arg) > 3)
    {
      return -2;
    }
      *((s32 *) (((u8 *) e) + 0x540)) = *arg;
      break;

    case 0x2008:
      if ((*arg) != 0)
    {
      *((s8 *) (((u8 *) e) + 0xb)) |= 4;
    }
    else
    {
      *((s8 *) (((u8 *) e) + 0xb)) &= ~4;
    }
      break;

    case 0x2010:
      v = *arg;
      if ((v < 0x28) || (v > (*((u16 *) (((u8 *) e) + 0x264)))))
    {
      return -2;
    }
      *((s16 *) (((u8 *) e) + 0x264)) = v;
      break;

    case 0x2020:
      if ((*arg) != 0)
    {
      *((s8 *) (((u8 *) e) + 0xb)) |= 0x40;
    }
    else
    {
      *((s8 *) (((u8 *) e) + 0xb)) &= ~0x40;
    }
      break;

    default:
      return -2;

  }

  return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s32 get_tcp_stat(s16 arg0, s16 *arg1, s16 *arg2, s32 *arg3, s32 *arg4) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (arg1 != NULL) {
        *arg1 = e->f6;
    }
    if (arg2 != NULL) {
        if (e->f6 == 1) {
            *arg2 = *(s16 *)((s8 *)e + 0x2C6);
        } else {
            *arg2 = 0;
        }
    }
    if (arg3 != NULL) {
        *arg3 = get_adjusted_slot_count((u8 *)e);
    }
    if (arg4 != NULL) {
        *arg4 = get_field_d8((void *)e);
    }
    return 0;
}
#pragma pop

#pragma pop
#pragma push
#pragma pool_data off
s32 mark_connection_closed(s16 arg0) {
    typedef struct Fields_var_r4 { u8 pad_0[4]; u16 field_4; } Fields_var_r4;
    typedef struct Fields_var_r3 { u8 pad_0[6]; s16 field_6; u8 pad_8[3]; u8 field_B; } Fields_var_r3;
    s32 *var_r3;
    s32 *var_r4;
    s16 var_r0;
    s16 var_r5;
    if ((arg0 < 0) || (var_r4 = &tcp_protocol_state.value, var_r4 = &tcp_protocol_state.value, var_r5 = arg0, ((var_r5 < (s16) *(s16 *)((s8 *)(&tcp_protocol_state.value) + 4)) == 0))) {
        var_r0 = -4;
    } else {
        var_r4 = (s32 *)(*(s32 **)((s8 *)(&tcp_protocol_state.value) + 0));
        var_r4 = (s32 *)((u8 *)var_r4 + (var_r5 * 0x544));
        if ((u16) ((Fields_var_r4*)var_r4)->field_4 != 1) {
            var_r0 = -4;
        } else {
            var_r0 = 0;
        }
    }
    if (var_r0 < 0) {
        var_r3 = (s32 *)((u8 *)((s32 *)-4));
        return -4;
    }
    var_r3 = (s32 *)(&tcp_protocol_state.value);
    var_r3 = (s32 *)(&tcp_protocol_state.value);
    var_r3 = (s32 *)(*(s32 **)((s8 *)(&tcp_protocol_state.value) + 0));
    var_r3 = (s32 *)((u8 *)var_r3 + (arg0 * 0x544));
    ((Fields_var_r3*)var_r3)->field_6 = 0;
    ((Fields_var_r3*)var_r3)->field_B = (u8) (((Fields_var_r3*)var_r3)->field_B | 0x80);
    TLobby__sub_8041B5C0(var_r3);
    var_r3 = (s32 *)(NULL);
    return 0;
}
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s32 abort_tcp_connection(s16 arg0) {
    s16 r;
    E_805C1D48 *e;

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (e->f6 < 4) {
        e->f6 = 0;
    } else {
        e->f6 = 0;
        TLobby__sub_8041A9AC((int)e);
    }
    clear_position((void *)e);
    return 0;
}
#pragma pop

#pragma push
#pragma dont_inline off
extern void TLobby__sub_8041E2EC(s16 idx, void* a, void* b) {
u8* e;
e = *(u8**)(*(u8(*)[])&tcp_protocol_state);
e = e + idx * 0x544;
NetMemcpy((void *)(e + 0x2d6), (void *)(a), (int)(3));
NetMemcpy((void *)(e + 0x2dc), (void *)(b), (int)(0xc));
}
#pragma pop
#pragma pop

u16 TLobby__sub_8041EA14(void);
#pragma push
#pragma opt_propagation off
#pragma push
#pragma pool_data off
s16 tcp_connect_start(s16 arg0, s32 arg1, s16 arg2) {
    s16 r;
    E_805C1D48 *e;
    s16 TLobby__sub_8040DA54(u8 *arg0, u8 *arg1);
    s16 is_addr_unspecified(u8 *arg0);
    s16 select_source_address(void *, void *);
    s16 TLobby__sub_8041A9AC(void *);
    s16 TLobby__sub_8041EC14(u8 *);
    s16 TLobby__sub_8041ECA4(u8 *arg0);
    u16 get_adjusted_slot_count(u8 *arg0);
    void NetDispatchSocketEvent(s16, s32, s32, s16);

    if (arg0 < 0 || arg0 >= tcp_protocol_state.n) {
        r = -4;
    } else if (tcp_protocol_state.p[arg0].f4 != 1) {
        r = -4;
    } else {
        r = 0;
    }
    if (r < 0) {
        return -4;
    }
    e = tcp_protocol_state.p;
    e += arg0;
    if (TLobby__sub_8040DA54((u8 *)arg1, (u8 *)e + 0x290) == 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.p), *(s32 *)((s8 *)e + 0x2D0), 3, 0xC);
        return -6;
    }
    if (is_addr_unspecified((u8 *)e + 0x290) != 0 && select_source_address((u8 *)e + 0x290, (void *)arg1) < 0) {
        NetDispatchSocketEvent((s16)(e - tcp_protocol_state.p), *(s32 *)((s8 *)e + 0x2D0), 3, 0xC);
        return -6;
    }
    if (*(u16 *)((s8 *)e + 0x268) == 0) {
        *(u16 *)((s8 *)e + 0x268) = TLobby__sub_8041EA14();
    }
    NetMemcpy((u8 *)e + 0x27C, (void *)arg1, 0x14);
    *(s16 *)((s8 *)e + 0x26A) = arg2;
    if (TLobby__sub_8041B724((u8 *)e) < 0) {
        return -6;
    }
    r = TLobby__sub_8041ECA4((u8 *)e);
    if (r < 0) {
        return r;
    }
    r = TLobby__sub_8041EC14((u8 *)e);
    if (r < 0) {
        close_if_open((void *)e);
        return r;
    }
    *(u32 *)((s8 *)e + 0x23C) = get_adjusted_slot_count((u8 *)e);
    e->f6 = 2;
    *(s16 *)((s8 *)e + 0x260) = 0x96;
    {
        s32 *t = (s32 *)((u8 *)&tcp_protocol_state + 0x18);
        s32 v = *t;
        *(s32 *)((s8 *)e + 0x21C) = v;
        *(s32 *)((s8 *)e + 0x324) = v;
        *(s32 *)((s8 *)e + 0x2F4) = v;
        *(s32 *)((s8 *)e + 0x210) = v;
        *(s32 *)((s8 *)e + 0x238) = v;
        *(s32 *)((s8 *)e + 0x20C) = v;
        *(s32 *)((s8 *)e + 0x208) = v;
        *t += 0xFA00;
    }
    return TLobby__sub_8041A9AC(e);
}
#pragma pop

extern s32 TLobby__sub_8041E590(s16 idx) {
  s16 new_var3;
  u8 *e = (*((u8 **) (&(*(u8(*)[])&tcp_protocol_state)))) + (idx * 0x544);
  u8 **new_var;
  u8 **new_var2;
  s16 s;
  new_var = (u8 **) (&(*(u8(*)[])&tcp_protocol_state));
  new_var2 = new_var;
  new_var3 = *((s16 *) (e + 0x8));
  if (new_var3 >= 0)
  {
    u8 *f = (*new_var2) + (337 * ((*((s16 *) (e + 0x8))) * 4));
    if ((*((u16 *) (f + 0x4))) == 1)
    {
      *((s16 *) (f + 0x2c6)) -= 1;
    }
  }
  *((s16 *) (e + 0x8)) = -1;
  return 0;
}

extern s32 TLobby__sub_8041E5E4(s16 idx, u8 *a, u16 id) {
    s16 is_addr_unspecified(u8 *);
    s16 compare_sockaddr(void *, u8 *);
    s16 i;
    u8 *e;
    p8040EE4C_Unk805BDF48 *g;
    u8 *p;
    s16 rc;
    s32 k;

    if (idx < 0 || idx >= (g = (p8040EE4C_Unk805BDF48 *)&tcp_protocol_state)->count) {
        rc = -4;
    } else {
        u8 *p;
        p = (u8 *)g->entries + idx * 0x544;
        if (*(u16 *)(p + 4) != 1) {
            rc = -4;
        } else {
            rc = 0;
        }
    }
    if (rc < 0) {
        return -4;
    }
    g = (p8040EE4C_Unk805BDF48 *)&tcp_protocol_state;
    e = (u8 *)g->entries;
    e += idx * 0x544;
    if (*(u16 *)((s8 *)e + 0x268) != 0) {
        return -3;
    }
    if (NetValidateLocalAddress((NetworkAddress *)a) < 0) {
        return -6;
    }
    if (id == 0) {
        *(u16 *)((s8 *)e + 0x268) = TLobby__sub_8041EA14();
    } else {
        p = (u8 *)g->entries;
        for (i = 0; i < g->count; i++) {
            if (*(u16 *)(p + 4) != 0 && p != e && *(u16 *)((s8 *)p + 0x268) == id) {
                if (is_addr_unspecified(a) != 0 || is_addr_unspecified(p + 0x290) != 0 ||
                    compare_sockaddr((void *)(p + 0x290), a) == 0) {
                    if (*(s16 *)((s8 *)p + 6) == 10 && (p[0xB] & 0x80) != 0) {
                        TLobby__sub_8041B5C0(p);
                    } else {
                        return -3;
                    }
                }
            }
            p += 0x544;
        }
        *(u16 *)((s8 *)e + 0x268) = id;
    }
    NetMemcpy(e + 0x290, a, 0x14);
    return 0;
}
extern void TLobby__sub_8041E8A8(s16 idx);
extern s32 TLobby__sub_8041E780(void)
{
    void TLobby__sub_8041E8A8(s32);
  p8040EE4C_Unk805BDF48 *g_m = (p8040EE4C_Unk805BDF48 *) (*(u8(*)[])&tcp_protocol_state);
  p8040EE4C_Unk805BDF48Rec *rec;
  s32 bestIdx = 0;
  p8040EE4C_Unk805BDF48Rec *best = NULL;
  s32 idx;
  s16 count;
  p8040EE4C_Unk805BDF48Rec *new_var;
  p8040EE4C_Unk805BDF48Rec *entries;
  s16 i = 0;
  idx = g_m->cur;
  count = g_m->count;
  entries = g_m->entries;
  for (; i < count; i++)
  {
    idx++;
    if (count <= ((s16) idx))
    {
      idx = 0;
    }
    rec = (p8040EE4C_Unk805BDF48Rec *) (((u8 *) (new_var = entries)) + (((s16) idx) * 0x544));
    if (rec->flags == 0)
    {
      NetMemset(rec, 0, 0x544);
      TLobby__sub_8041E8A8(idx);
      return idx;
    }
    if ((rec->type == 10) && ((rec->unkB & 0x80) != 0))
    {
      if (best != NULL)
      {
        if (rec->timers[3] < best->timers[3])
        {
          best = rec;
          bestIdx = idx;
        }
      }
      else
      {
        best = rec;
        bestIdx = idx;
      }
    }
  }

  if (best != NULL)
  {
    TLobby__sub_8041B5C0(best);
    NetMemset(best, 0, 0x544);
    TLobby__sub_8041E8A8(bestIdx);
    return bestIdx;
  }
  return -0x103;
}

#pragma pop

#pragma push
#pragma pool_data off
void TLobby__sub_8041E8A8(s16 idx) {
    u32 *p;
    u16 v;
    s16 i;
    u8 *t;
    u8 *b;

    b = *(u8 **)&tcp_protocol_state;
    b += idx * 0x544;
    b[0] = 'T';
    b[1] = 'C';
    b[2] = 'B';
    b[3] = idx;
    *(s16 *)(b + 0x4) = 1;
    *(s16 *)(b + 0x6) = 0;
    *(s16 *)(b + 0x264) = 0x7fff;
    *(s16 *)(b + 0x266) = 0x218;
    b[0xb] = 0;
    b[0xa] = 0;
    *(s16 *)(b + 0x24c) = 0;
    *(s16 *)(b + 0x24e) = 0x18;
    *(s16 *)(b + 0x254) = 0xc;
    v = *(u16 *)(b + 0x254);
    if (v < 2) {
        *(s16 *)(b + 0x254) = 2;
    } else if (v > 0x80) {
        *(s16 *)(b + 0x254) = 0x80;
    }
    *(s32 *)(b + 0x240) = 0x10000 - 1;
    *(s16 *)(b + 0x8) = -1;
    clear_position((void *)b);
    NetMemset(b + 0x2d6, 0, 3);
    NetMemset(b + 0x2dc, 0, 0xc);
    *(u8 *)(b + 0x2e8) = ((u8 *)&tcp_protocol_state)[0x50];
    p = (u32 *)(b + 0x2f8);
    for (i = 0; i < 5; i++, p += 2) {
        p[1] = 0;
        p[0] = 0;
    }
    *(s16 *)(b + 0x320) = -1;
    t = (u8 *)&tcp_protocol_state;
    *(u32 *)(b + 0x530) = *(u32 *)(t + 0x8);
    *(u32 *)(b + 0x534) = *(u32 *)(t + 0xc);
    *(s32 *)(b + 0x2d0) = 0;
    *(s32 *)(b + 0x53c) = *(s16 *)(t + 0x26);
    *(s16 *)(b + 0x538) = 0;
    *(s32 *)(b + 0x540) = t[0xa2];
}
#pragma pop

u16 TLobby__sub_8041EA14(void)
{
    s32 tmp;
    p8040EE4C_Unk805BDF48Rec *e;
    s16 i;
    s16 n;
    s16 found;
    u16 *x;
    u16 cur;
    p8040EE4C_Unk805BDF48 *h;
    register p8040EE4C_Unk805BDF48 *g = (p8040EE4C_Unk805BDF48 *)&tcp_protocol_state;

    x = &g->unk10;
    if (g->unk10 == 0) {
        NetStoreTick(&tmp);
        *x = g->unk12;
        *x |= tmp & 0x3FF;
    } else if (g->unk10 < g->unk14) {
        *x = g->unk10 + 1;
    } else {
        *x = g->unk12;
    }
    found = 0;
    h = (p8040EE4C_Unk805BDF48 *)&tcp_protocol_state;
    goto search;
    do {
        if (cur < h->unk14) {
            *x = *x + 1;
        } else {
            *x = h->unk12;
        }
    search:
        cur = *x;
        e = h->entries;
        n = h->count;
        for (i = 0; i < n; i++, e++) {
            if (e->flags == 1 && cur == *(u16 *)((s8 *)e + 0x268)) {
                found = 1;
                goto out;
            }
        }
        found = 0;
    out:;
    } while (found != 0);
    return cur;
}

s16 validate_tcp_handle(s16 i) {
    if (i < 0 || i >= tcp_protocol_state.n) { return -4; }
    if (tcp_protocol_state.p[i].f4 != 1) { return -4; }
    return 0;
}

s32 TLobby__sub_8041EB74(u8 *arg0) {
    typedef struct Fields_arg0 { u8 pad_0[204]; u8 field_CC; } Fields_arg0;
    if ((u8) ((Fields_arg0*)arg0)->field_CC == 0) {
        return -1;
    }
    TLobby__sub_8041579C((void *) (arg0 + 0xD0));
    ((Fields_arg0*)arg0)->field_CC = 0U;
    return 0;
}

s32 close_if_open(void *self) {
    u8 *arg0 = (u8 *)self;
    if ((u8) *(u8 *)&((TObjectFields *)self)->m_down == 0) {
        return -1;
    }
    TLobby__sub_8041579C((void *) (arg0 + 0x18));
    *(u8 *)&((TObjectFields *)self)->m_down = 0U;
    return 0;
}

s32 TLobby__sub_8041EC14(u8 *arg0) {
    s32 spC[3];

    if ((u8) *(u8 *)((s8 *)arg0 + 0xCC) == 0) {
        if (TLobby__sub_80415954((void *) (&spC[0]), (int) (*(s32 *)((s8 *)arg0 + 0x534)), 1) < 0) {
            return -0x102;
        }
        init_msg((void *)(arg0 + 0xD0), spC[0]);
        set_value_and_enable((void *)(arg0 + 0xC8), spC[0]);
        goto block_4;
    }
block_4:
    *(s32 *)((s8 *)arg0 + 0xD8) = 0;
    *(s32 *)((s8 *)arg0 + 0xDC) = 0;
    *(s32 *)((s8 *)arg0 + 0xE0) = 0;
    *(s32 *)((s8 *)arg0 + 0xF4) = 0;
    *(s16 *)((s8 *)arg0 + 0xF8) = -1;
    *(s16 *)((s8 *)arg0 + 0xFA) = -1;
    return 0;
}

s32 TLobby__sub_8041ECA4(u8 *arg0) {
  unsigned char new_var;
  s32 spC;
  if (((u8) (*((u8 *) (((s8 *) arg0) + 0x14)))) == 0)
  {
    if (TLobby__sub_80415954((void *) (&spC), (int) (*((s32 *) (((s8 *) arg0) + 0x530))), 1) < 0)
    {
      return -0x102;
    }
    init_msg((void *)(((u8 *) arg0) + 0x18), (s32)((int) spC));
    set_value_and_enable((void *)(((u8 *) arg0) + 0x10), (s32)((int) spC));
    goto block_4;
  }
  block_4:
  *((s32 *) (((s8 *) arg0) + 0x20)) = 0;
  new_var = 0x24;
  *((s32 *) (((s8 *) arg0) + new_var)) = 0;
  *((s32 *) (((s8 *) arg0) + 0x28)) = 0;
  return 0;
}

s32 get_field_534(void *self) {
    u8 *arg0 = (u8 *)self;
    return *(s32 *)((s8 *)arg0 + 0x534);
}

s32 get_field_d8(void *self) {
    u8 *arg0 = (u8 *)self;
    return *(s32 *)((s8 *)arg0 + 0xD8);
}

s32 get_score(void *self) {
    u8 *arg0 = (u8 *)self;
    if (((u8) *(u8 *)((s8 *)arg0 + 0x204) >> 7U) & 1) {
        return *(s32 *)((s8 *)arg0 + 0x34);
    }
    return *(s32 *)((s8 *)arg0 + 0x20) + *(s32 *)((s8 *)arg0 + 0x34);
}

s32 get_queue_diff(void *self) {
    u8 *arg0 = (u8 *)self;
    return *(s32 *)((s8 *)arg0 + 0x534) - *(s32 *)((s8 *)arg0 + 0xD8);
}

s32 get_adjusted_slot_count(u8 *arg0) {
    if (((u8) *(u8 *)((s8 *)arg0 + 0x204) >> 7U) & 1) {
        return *(s32 *)((s8 *)arg0 + 0x530);
    }
    return *(s32 *)((s8 *)arg0 + 0x530) - *(s32 *)((s8 *)arg0 + 0x20);
}
