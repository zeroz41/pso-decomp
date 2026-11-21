#ifndef PSO_PLAYER_TPLYCLIENTCONFIG_H
#define PSO_PLAYER_TPLYCLIENTCONFIG_H

#include "types.h"
#include <stddef.h>

class TPlyClientConfig {
public:
    TPlyClientConfig& operator=(const TPlyClientConfig& other);

    struct Config {
        u32 magic[2];
        u32 flags;
        u32 proxy_dst_addr;
        u16 proxy_dst_port;
        u8 mbr_0xe[14];
    } config;
};

LAYOUT_ASSERT(TPlyClientConfigSize, sizeof(TPlyClientConfig) == 0x20);
LAYOUT_ASSERT(TPlyClientConfigFlagsOffset, offsetof(TPlyClientConfig::Config, flags) == 8);
LAYOUT_ASSERT(TPlyClientConfigAddressOffset, offsetof(TPlyClientConfig::Config, proxy_dst_addr) == 0xC);
LAYOUT_ASSERT(TPlyClientConfigPortOffset, offsetof(TPlyClientConfig::Config, proxy_dst_port) == 0x10);

#endif
