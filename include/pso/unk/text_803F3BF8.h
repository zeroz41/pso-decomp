#ifndef PSO_UNK_TEXT_803F3BF8_H
#define PSO_UNK_TEXT_803F3BF8_H

#include "types.h"

extern u32 lobby_net_config_mode;

s32 update_network_info_request(void);

extern "C" {
s32 open_network_config(s32 backup_mode, void *buffer, s32 mode);
}
s32 close_network_config(void);

#endif
