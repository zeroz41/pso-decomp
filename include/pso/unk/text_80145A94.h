#ifndef PSO_UNK_TEXT_80145A94_H
#define PSO_UNK_TEXT_80145A94_H

#include "types.h"

s32 load_network_info(void);
extern "C" {
s32 TLobby__sub_80145DB4(s32 mode);
}

// 1 when the network adapter reports state 1.
s32 is_state_active();

struct LoadNetworkInfoIds { s32 v[2]; };

struct LoadNetworkInfoBuf { s32 hdr; s8 name[0xA0]; s8 x[0x270 - 0xA4]; };

#endif
