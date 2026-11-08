#ifndef PSO_NETWORK_TLOBBY_8041112C_H
#define PSO_NETWORK_TLOBBY_8041112C_H

#include "types.h"
#include "pso/network/IPv6Send.h"

/* TLobby_8041112C.c: IPv6 neighbour discovery, routing and packet fragments. */
typedef struct RecoveredGlobal_8041552C_lbl_805C1BE0 RecoveredGlobal_8041552C_lbl_805C1BE0;
typedef struct RecoveredGlobal_80415650_lbl_805C1BF8 RecoveredGlobal_80415650_lbl_805C1BF8;
typedef struct Seg_804179A4 Seg_804179A4;
typedef struct Pkt_804179A4 Pkt_804179A4;
typedef struct Sock_804179A4 Sock_804179A4;
typedef struct RecoveredFields_804143BC_arg0 RecoveredFields_804143BC_arg0;
typedef struct A_80415B38 A_80415B38;
typedef struct C_80415B38 C_80415B38;
typedef struct B_80415B38 B_80415B38;
typedef struct G_80415B38 G_80415B38;
typedef struct E_80418BD8 E_80418BD8;
typedef struct A_80418BD8 A_80418BD8;
struct RecoveredGlobal_8041552C_lbl_805C1BE0 {
    s32 value;
    u8 remaining[0x14];
};
struct RecoveredGlobal_80415650_lbl_805C1BF8 {
    s16 value;
    u8 remaining[0xE];
};
struct Seg_804179A4 { s16 len; s16 pad; u8 buf[8]; };
struct Pkt_804179A4 { u8 pad0[4]; u32 n; s32 total; Seg_804179A4 seg[1]; };
struct Sock_804179A4 { u8 pad0[0x10]; u8 addr[0x10]; s32 f20; s16 f24; u8 f26; u8 f27; };
struct RecoveredFields_804143BC_arg0 {
    u8 field_0;
    u8 field_1;
};
struct A_80415B38 { s8 c0; s8 c1; s8 c2; s8 c3; u8 pad4[0x30]; s32 off; };
/* A default-router entry. */
struct C_80415B38 {
    s8 c0;
    s8 c1;
    s8 c2;
    u8 c3; /* state */
    s16 id;
    s16 f6;
    s16 lifetime;
    u8 padA[0xA];
    u8 addr[0x10];
};
struct B_80415B38 {
    s8 c0;
    s8 c1;
    s8 c2;
    s8 c3;
    u8 pad4[4];
    s16 id;
    u8 padA[2];
    u8 flags;
    u8 padD[3];
    A_80415B38 *link;
    u8 pad14[2];
    u8 addr[0x10];
    s16 f26;
    u8 pad28[0x20];
};
struct G_80415B38 {
    s16 na;
    s16 nb;
    s16 nc;
    u8 pad6[2];
    A_80415B38 *a;
    B_80415B38 *b;
    C_80415B38 *c;
    s16 stride;
    u8 pad16[2];
    s32 base;
    u8 pad1C[8];
    s16 maxage;
    u8 pad26[0xA];
};
struct E_80418BD8 { u8 pad[0xC]; };
struct A_80418BD8 { u8 pad[4]; u32 n; u8 pad2[8]; E_80418BD8 e[1]; };

#ifdef __cplusplus
extern "C" {
#endif
extern RecoveredGlobal_8041552C_lbl_805C1BE0 network_loopback_state;
extern RecoveredGlobal_80415650_lbl_805C1BF8 network_buffer_pool_state;
extern struct G_80415B38 ipv6_neighbor_discovery_state;
s16 alloc_conn_slot(s16 h, s16 v);
s32 clear_conn_slot(s16 i);
s32 fill_reply_buffer(s16 h, u8 *p);
s16 get_slot_offset_or_default(s16 arg0);
s16 *get_valid_entry(s16 arg0);
s32 reset_net_value(void);
s32 reset_other_connection_lists(void *obj);
void tick_entry_timers(void);
void update_timeout_entries(void);
void NetIPv6ApplyNeighborDiscoveryDefaults(u8 *arg0);
s32 TLobby__sub_80413230(u8 *arg0, s32 arg1);
s32 TLobby__sub_804136AC(s16 i);
void TLobby__sub_804136CC(s16 i);
s16 NetIPv6IsLoopback(u8 *arg0);
s32 NetIPv6IsUnspecified(u8 *arg0);
s32 NetIPv6CompareAddresses(s32 arg0, s32 arg1);
s16 TLobby__sub_8041510C(void);
void TLobby__sub_804150EC(void);
void TLobby__sub_8041615C(void);
void NetIPv6TickNeighborCache(void);
void NetIPv6TickNeighborDiscovery(void);
s16 NetIPv6EmitNeighborSolicitation(int arg0, void *arg1, void *arg2, s16 arg3, int arg4);
s32 NetIPv6SendUnspecifiedSourceNeighborSolicitation(s32 arg0, s16 arg1);
s32 TLobby__sub_804112B8(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_8041123C(s32 arg0, s32 arg1, s16 arg2);
s32 TLobby__sub_804136EC(void *self);
s16 TLobby__sub_8041579C(void *self);
s16 TLobby__sub_80415954(void *out_, int size, s16 owner);
s32 NetCompareBitsBackward(u8 *arg0, u8 *arg1, s16 arg2);
s32 NetCompareBitPrefix(u8 *a, u8 *b, s16 bits);
s32 NetIPv6MakeSolicitedNodeMulticastAddress(u8 *arg0, u8 *arg1);
s32 TLobby__sub_8041509C(void);
s32 init_ipv6_all_routers_multicast_address(u8 *address, s8 scope);
u8 init_ipv6_all_nodes_multicast_address(u8 *address, s8 scope);
s16 TLobby__sub_80416F58(u8 *self, s32 n, void *out, void *arg_);
s16 TLobby__sub_80417028(void *self, void *a, void *b, void *d);
s32 NetIPv6EmitRouterSolicitation(NetPacket *net_packet, NetIPv6SendParameters *addr, s32 arg2);
s16 NetIPv6GetInterfaceLinkLayerAddress(s32 arg0, s16 arg1, s16 id);
s16 NetIPv6SendNeighborAdvertisement(Pkt_804179A4 *arg0, u8 *address, u8 arg2, Sock_804179A4 *arg3, s16 arg4);
s32 NetIPv6IsLinkLocal(u8 *arg0);
s32 TLobby__sub_8041549C(s16 arg0);
s32 TLobby__sub_804154C0(s16 arg0);
s32 TLobby__sub_804154E4(s16 arg0);
s32 TLobby__sub_80415508(s16 arg0);
s32 TLobby__sub_80411F1C(void *out, void *dst, s16 idx);
s16 TLobby__sub_80415D0C(Pkt_804179A4 *a, u8 *b, Sock_804179A4 *c, s16 d);
s16 TLobby__sub_80411C44(u8 *addr, s16 idx);
#ifdef __cplusplus
}
#endif

#endif
