#ifndef PSO_NETWORK_NETCFG_H
#define PSO_NETWORK_NETCFG_H
/* The network stack's configuration (src/pso/network/TLobby_803F86BC.c). The stack is a C library built with
 * GC/1.2.5n, separate from the game's C++: each function here fills one of its configuration records with
 * counts, sizes and static buffers. Record and field names are ours (no symbols survive). */
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct NetSizes { s16 a; s16 b; s16 c; } NetSizes;

typedef struct NetConfig {
    s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fA; NetSizes *fC;
    s16 f10; s16 f12; u8 *f14; s16 f18; s16 f1A; s16 f1C; s16 f1E; u8 *f20;
    s16 f24; s16 f26; u8 *f28; s16 f2C; s16 f2E; s16 f30; s16 f32;
    u8 *f34; u8 *f38; u8 *f3C; s16 f40; s16 f42; u8 *f44;
} NetConfig;

typedef struct NetParamCfg {
    s32 buffer;          /* 0x00 */
    s16 count;           /* 0x04 */
    u8 pad6[2];
    s32 f8;              /* 0x08 */
    s32 fC;              /* 0x0C */
    u8 pad10[0x90];
    s16 fA0;             /* 0xA0 */
} NetParamCfg;

typedef struct NetBufDescA {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    u8 *f8;
    u8 *fC;
    u8 *f10;
} NetBufDescA;


typedef struct NetBufferCfg {
    s16 f0, f2, f4, f6, f8, fA, fC;
    u8 padE[2];
    u8 *f10;
    u8 *f14;
    u8 *f18;
    u8 *f1C;
    u8 *f20;
    u8 *f24;
} NetBufferCfg;

typedef struct NetFuncTableCfg {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    void *funcs;
    void *x;
    void *y;
    void *z;
} NetFuncTableCfg;

typedef struct NetBufferLayout {
    s16 a;
    s16 b;
    u16 n1;
    u16 n2;
    s32 c;
    s32 d;
    s32 e;
    u32 f;
    u32 g;
} NetBufferLayout;

void TLobby__sub_803F86BC(void *cfg);
void init_net_config(NetConfig *cfg);
void TLobby__sub_803F8794(void *cfg);
void init_params(NetParamCfg *cfg);
void TLobby__sub_803F87C4(void *cfg);
void TLobby__sub_803F87C8(u8 *cfg);
void TLobby__sub_803F87DC(void *cfg);
struct Ipv6ProtocolState;
void init_ipv6_interface_config(struct Ipv6ProtocolState *cfg);
void TLobby__sub_803F8864(void *cfg);
struct Ipv6State;
void init_udp_socket_config(struct Ipv6State *cfg);
void TLobby__sub_803F88E0(void *cfg);
struct Ipv6NdState;
void init_buffer_descriptor_b(struct Ipv6NdState *cfg);
void TLobby__sub_803F892C(void *cfg);
void TLobby__sub_803F8930(u8 *cfg);
void TLobby__sub_803F8958(void *cfg);
void init_buffer_descriptor_a(NetBufDescA *cfg);
struct NetFragPool;
void TLobby__sub_803F89A0(struct NetFragPool *cfg);
void TLobby__sub_803F89A4(struct NetFragPool *cfg);
struct NetBufferPool;
void TLobby__sub_803F89D8(struct NetBufferPool *cfg);
void init_buffer_desc_a(struct NetBufferPool *cfg);
void TLobby__sub_803F8A08(void *cfg);
void TLobby__sub_803F8A0C(u8 *cfg);
void TLobby__sub_803F8A24(void *cfg);
void init_net_buffer_config(NetBufferCfg *cfg);
void TLobby__sub_803F8A9C(void *cfg);
void TLobby__sub_803F8AA0(u8 *cfg);
void TLobby__sub_803F8AB8(void *cfg);
void init_net_func_table(NetFuncTableCfg *cfg);
void TLobby__sub_803F8B78(void *cfg);
struct LoopbackState;
void init_net_recv_desc(struct LoopbackState *cfg);
u8 *layout_buffers(NetBufferLayout *h, u8 *p, u8 *end);
s32 TLobby__sub_803F8D24(NetBufferLayout *h);
void TLobby__sub_803F8D84(u32 key);
s32 alloc_buffer_slot(s32 size);

#ifdef __cplusplus
}
#endif

#endif
