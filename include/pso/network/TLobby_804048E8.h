#ifndef PSO_NETWORK_TLOBBY_804048E8_H
#define PSO_NETWORK_TLOBBY_804048E8_H

#include "types.h"

/* TLobby_804048E8.c: the stack's connection list (node pools). */

/* A cursor over a packet buffer: data pointer and remaining length. */
typedef struct Strm_80405A74 {
    u8 *p;
    u16 len;
} Strm_80405A74;
typedef char Strm_80405A74_size_check[sizeof(Strm_80405A74) == 8 ? 1 : -1];

/* An IPv4 header decoded by TLobby__sub_803FEA88. */
typedef struct A_80403F4C {
    u32 src;
    u32 dst;
    u16 len;
    u16 id;
    u16 frag;
    u16 cksum;
    u8 pad10;
    u8 df;
    u8 mf;
    u8 version;
    u8 tos;
    u8 ttl;
    u8 proto; /* IP protocol (VJ compression stores the slot id here) */
    u8 optlen;
    u8 opts[0x40 - 0x18];
} A_80403F4C;
typedef char A_80403F4C_size_check[sizeof(A_80403F4C) == 0x40 ? 1 : -1];

/* A TCP header decoded for VJ compression. */
typedef struct B_80403F4C {
    u16 src_port;
    u16 dst_port;
    u32 seq;
    u32 ack;
    u16 window;
    u16 checksum;
    u16 urgent;
    u16 mss;
    u8 pad_14;
    u8 urg;
    u8 ack_flag;
    u8 psh;
    u8 rst;
    u8 syn;
    u8 fin;
    u8 option_len;
    u8 options[0x28];
} B_80403F4C;
typedef char B_80403F4C_size_check[sizeof(B_80403F4C) == 0x44 ? 1 : -1];

/* A VJ compression connection state. */
typedef struct Ent_80403F4C {
    u8 id;
    u8 pad1[3];
    struct Ent_80403F4C *next;
    A_80403F4C a;
    B_80403F4C b;
} Ent_80403F4C;
typedef char Ent_80403F4C_size_check[sizeof(Ent_80403F4C) == 0x8C ? 1 : -1];

/* The VJ compression state. */
typedef struct Obj_80403F4C {
    Ent_80403F4C *tstate;
    Ent_80403F4C *ents;
    u8 pad8;
    u8 max;
    u8 last_cs;
    u8 last_xmit;
    u8 cur;
    u8 flags;
    u8 padE[2];
    s32 n10;
    s32 n14;
    s32 n18;
    s32 n1C;
    s32 n20;
    s32 n24;
    s32 n28;
    s32 n2C;
    s32 n30;
    s32 n34;
} Obj_80403F4C;
typedef char Obj_80403F4C_size_check[sizeof(Obj_80403F4C) == 0x38 ? 1 : -1];

#ifdef __cplusplus
extern "C" {
#endif
void TLobby__sub_80405000(u32 arg0);
s32 init_net_list(s16 count2, s16 count1);
s32 TLobby__sub_803FEA88(A_80403F4C *out, Strm_80405A74 **src);
#ifdef __cplusplus
}
#endif

#endif
