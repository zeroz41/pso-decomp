#ifndef PSO_UNK_TEXT_80145A94_H
#define PSO_UNK_TEXT_80145A94_H

#include "types.h"

s32 load_network_info(void);
s32 init_struct(u8 *info);
s32 init_work(s32 unused, u8 *info);

extern void *network_info_work;
extern u16 network_config_open;
extern int network_lease_time; /* the DHCP lease time NetworkConnect keeps */
extern "C" {
s32 TLobby__sub_80145DB4(s32 mode);
}

// 1 when the network adapter reports state 1.
s32 is_state_active();

struct LoadNetworkInfoIds { s32 v[2]; };

struct LoadNetworkInfoBuf { s32 hdr; char name[0xA0]; s8 x[0x270 - 0xA4]; };

#endif
