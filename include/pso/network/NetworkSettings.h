#ifndef PSO_NETWORK_NETWORKSETTINGS_H
#define PSO_NETWORK_NETWORKSETTINGS_H

#include "types.h"

s32 load_network_info(void);
s32 init_struct(u8 *info);
s32 init_work(s32 unused, u8 *info);

extern void *network_info_work;
extern u16 network_config_open;
extern int network_lease_time; /* the DHCP lease time NetworkConnect keeps */
BOOL read_dial_prefix(char *dst);
s32 adapter_supports_connection(s32 mode);
int is_network_info_loaded(void);

// 1 when the broadband configuration's connection type is 1 (PPPoE).
s32 is_state_active();
s32 is_dhcp_connection(void);

s32 is_confirmed();
s32 has_broadband_adapter(void);

struct LoadNetworkInfoIds { s32 v[2]; };

struct LoadNetworkInfoBuf { s32 hdr; char name[0xA0]; s8 x[0x270 - 0xA4]; };

#endif
