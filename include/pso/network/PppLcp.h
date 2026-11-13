#ifndef PSO_NETWORK_PPPLCP_H
#define PSO_NETWORK_PPPLCP_H

#include "types.h"

/* LCP option values; mask has bit N set for option type N. */
typedef struct LcpVals {
    s16 mask;
    s16 mru;
    u32 accm;
    u16 auth_proto;
    u8 pad0A[2];
    u32 magic;
    u8 pad10[4];
    u8 chap_alg;
    u8 f15;
    u8 pad16[2];
} LcpVals;
typedef char LcpVals_size_check[sizeof(LcpVals) == 0x18 ? 1 : -1];

/* One side of the LCP negotiation: the options wanted and the ones agreed. */
typedef struct LcpSide {
    s16 mask;
    u8 pad2[2];
    LcpVals want;
    LcpVals got;
} LcpSide;
typedef char LcpSide_size_check[sizeof(LcpSide) == 0x34 ? 1 : -1];

/* The LCP options object (fsm->p30, lbl_805C0400's opts). */
typedef struct LcpOpts {
    LcpSide local;
    LcpSide remote;
} LcpOpts;
typedef char LcpOpts_size_check[sizeof(LcpOpts) == 0x68 ? 1 : -1];

/* The LCP settings TLobby__sub_80400744 copies into the wanted options of both sides. auth_mode goes to
   configure_mode_by_type; f4 == 0 asks for option 8 and fE == 0 for option 7. Callers pass it at the head of a
   larger connect record. */
typedef struct LcpConfig {
    u32 accm;
    s16 f4;
    u16 auth_mode;
    u32 magic;
    u16 mru;
    s16 fE;
} LcpConfig;
typedef char LcpConfig_size_check[sizeof(LcpConfig) == 0x10 ? 1 : -1];

/* The LCP protocol header TLobby__sub_8040059C fills in: name, protocol number, timings and callbacks. */
typedef struct LcpProto_8040059C {
    const char *name;
    u16 proto;
    u16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 timeout;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
} LcpProto_8040059C;
/* lbl_805C0400: the LCP protocol header and its options. */
typedef struct LcpState {
    LcpProto_8040059C proto;
    LcpOpts opts;
    u8 padA4[4];
} LcpState;
typedef char LcpState_size_check[sizeof(LcpState) == 0xA8 ? 1 : -1];
extern LcpState lbl_805C0400;

#endif
