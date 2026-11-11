#ifndef PSO_NETWORK_TLOBBY_803FCF44_H
#define PSO_NETWORK_TLOBBY_803FCF44_H

#include "types.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/NetPppLink.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_804048E8.h"

/* Shared by the PPP files split out of TLobby_803FCF44.c: NetPppLink.c, PppFsm.c, PppIpcp.c, PppLcp.c, PppBuffer.c,
 * PppMd5.c, NetByteOrder.c, PppPap.c, PppControl.c and PppVj.c (CHAP is TLobby_803FC178.c). */
typedef struct Self_803FD74C Self_803FD74C;
typedef struct Tbl_803FD74C Tbl_803FD74C;
typedef struct Self_803FD85C Self_803FD85C;
typedef struct Tbl_803FD85C Tbl_803FD85C;
typedef struct Sub_803FF858 Sub_803FF858;
typedef struct Obj_803FF858 Obj_803FF858;
typedef struct O_80400ACC O_80400ACC;
typedef struct Self_803FDA68 Self_803FDA68;
typedef struct Tbl_803FDA68 Tbl_803FDA68;
typedef struct V_803FE600 V_803FE600;
typedef struct O_803FE600 O_803FE600;
typedef struct Blk_803FF48C Blk_803FF48C;
typedef union U_803FF48C U_803FF48C;
typedef struct Names_80403168 Names_80403168;
struct Self_803FD74C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FD74C *tbl;
    void *f30;
};
struct Tbl_803FD74C {
    u8 pad[0x20];
    void (*f20)(Self_803FD74C *);
};
struct Self_803FD85C {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    u8 pad8[8];
    u8 f10[0x1C];
    Tbl_803FD85C *tbl;
    void *f30;
};
struct Tbl_803FD85C {
    u8 pad[0x14];
    void (*f14)(Self_803FD85C *, Tbl_803FD85C *);
    u8 pad18[8];
    void (*f20)(Self_803FD85C *, Tbl_803FD85C *);
};
struct Sub_803FF858 { u8 pad0[0x28]; s16 h1C; };
struct Obj_803FF858 { u8 pad0; u8 b1; u8 pad2[4]; u8 b6; u8 pad7[4]; u8 bB; u8 padC[0x24]; Sub_803FF858 *p30; };
struct O_80400ACC { u8 b0; u8 b1; u8 b2; u8 pad3[0x108 - 3]; s32 f108; };
struct Self_803FDA68 {
    u8 f0; u8 f1; u8 f2; u8 f3; u8 f4; u8 f5; u8 f6; u8 f7;
    s16 f8; u8 padA[6];
    u8 f10[0x1C];
    Tbl_803FDA68 *tbl;
    void *f30;
};
struct Tbl_803FDA68 {
    u8 pad[0x14];
    void (*f14)(Self_803FDA68 *, Tbl_803FDA68 *);
    u8 pad18[0xC];
    void (*f24)(Self_803FDA68 *, Tbl_803FDA68 *);
    void *(*f28)(Self_803FDA68 *, Tbl_803FDA68 *);
};
struct V_803FE600 {
    u8 pad[0x14];
    void (*fn)(O_803FE600 *, V_803FE600 *);
};
struct O_803FE600 {
    u8 b0; u8 b1; u8 b2; u8 b3; u8 b4; u8 b5; u8 b6; u8 b7;
    u8 pad8[0x2C - 8];
    V_803FE600 *p2C;
};
struct Blk_803FF48C { s32 w[9]; };
union U_803FF48C { s16 h4; Blk_803FF48C src; };
struct Names_80403168 {
    u8 pad[0x48];
    u8 a[0x80];
    u8 b[0x80];
};

#ifdef __cplusplus
extern "C" {
#endif
extern Names_80403168 lbl_805C04D8;
extern u8 lobby_ppp_read_buf;
s16 TLobby__sub_803FFB84(void *self, void *p, void *a, u8 *hdr, s16 c);
u32 TLobby__sub_803FE9F8(u32 sum, PppFrame* buf, u16 count);
void TLobby__sub_803FD0C0(void);
/* Called across the PPP files; each line names its defining file. */
void TLobby__sub_803FD694(u8 *arg0); /* PppFsm.c */
void TLobby__sub_803FE600(O_803FE600 *o); /* PppFsm.c */
s16 TLobby__sub_803FED78(u8 *self); /* PppIpcp.c */
s16 TLobby__sub_80400744(int a0, void *a1); /* PppLcp.c */
s32 TLobby__sub_80401ABC(u8 *self_m, void *dst, s32 n); /* PppBuffer.c */

/* The protocol header that opens the IPCP and LCP state objects (.bss 805C0328 and 805C0400). */
typedef struct Obj_803FEF4C {
    u32 w0;
    u16 h4;
    s16 h6;
    u8 b8;
    u8 b9;
    u8 bA;
    u8 bB;
    s32 wC;
    void *fn[11];
} Obj_803FEF4C;
void TLobby__sub_803FE820(s32 arg0);
s32 set_socket_flags_by_mode(s16 arg0, u8 *arg1);
s16 TLobby__sub_803FF304(u8 *lobby);
void TLobby__sub_803FF468(s32 arg0);
void TLobby__sub_803FD85C(void *arg0);
s32 TLobby__sub_80403D28(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 TLobby__sub_803FE6CC(void *self, int a, int b, void *c);
s32 TLobby__sub_803FE658(u8 *arg0);
void TLobby__sub_803FD958(u8 *arg0);
void TLobby__sub_80401CAC(PppFrame **o, u16 v);
u16 read_network_u16_be(u8 *p);
u32 TLobby__sub_80402AFC(u8 *p);
u8 *write_network_u16_be(u8 *p, u16 v);
void TLobby__sub_803FF384(u8 *arg0);
s32 wait_for_connection(Conn_804004DC *c);
s32 TLobby__sub_80403168(u8 *arg0, u8 *arg1, u8 *arg2);
s32 TLobby__sub_80403B04(u8 *arg0, u8 *arg1, s32 arg2);
s16 TLobby__sub_80402BB4(void *arg0, u32 timeout);
s32 TLobby__sub_80403BA8(u8 *arg0, u8 *arg1, s32 arg2);
void TLobby__sub_8040098C(Conn_804004DC *c);
s16 TLobby__sub_80403F4C(void *ov, PppFrame **spp);
PppFrame *init_net_buffer_entry(u16 idx);
void TLobby__sub_80400270(u32 *self, void *opt, s32 mask);
s32 TLobby__sub_803FF858(Obj_803FF858 *arg0, Msg_803FA664 *arg1, u32 arg2);
s16 TLobby__sub_803FD5A4(s16 h, s16 v);
s32 TLobby__sub_803FD21C(s16 arg0, s32 arg1, s32 arg2, u8 *arg3);
s32 TLobby__sub_803FD310(s16 arg0, s32 arg1, u8 *arg2);
s32 TLobby__sub_803FD490(s16 arg0);
s32 TLobby__sub_803FD4B4(s16 arg0);
s32 TLobby__sub_803FD4D8(s16 arg0);
s32 TLobby__sub_803FD4FC(s16 arg0);
s32 TLobby__sub_803FE844(void);
void TLobby__sub_803FE84C(void);
s32 TLobby__sub_803FF2CC(u8 *arg0, s32 arg1);
void TLobby__sub_803FF374(u8 *arg0);
void TLobby__sub_80400988(void);
void TLobby__sub_80400B98(u8 *arg0);
s32 set_filter_id(u8 *arg0, s32 arg1);
s32 set_filter_index(u8 *arg0, s32 arg1);
s32 set_target_id(u8 *arg0, s32 arg1);
s32 set_target_index(u8 *arg0, s32 arg1);
s32 set_target_slot(u8 *arg0, s32 arg1);
void *build_avetcp_net_buffer(Conn_804004DC *c);
s32 TLobby__sub_803FE8BC(u8 *dst, void *src);
void TLobby__sub_80400ACC(O_80400ACC *o);
PppFrame *TLobby__sub_80401B20(void *src, u16 n);
void TLobby__sub_80401EB8(u8* self_m, u8* src, u32 len);
void TLobby__sub_80401D2C(u8 *dst, u32 *self_m);
#ifdef __cplusplus
}
#endif

#endif
