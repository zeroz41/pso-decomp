#ifndef PSO_NETWORK_NETWORKCONFIG_H
#define PSO_NETWORK_NETWORKCONFIG_H

#include "types.h"

extern u32 lobby_net_config_mode;

s32 update_network_info_request(void);

s32 open_network_config(s32 backup_mode, void *buffer, s32 mode);
s32 close_network_config(void);

#endif
