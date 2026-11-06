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

typedef char TPlyClientConfigSize[(sizeof(TPlyClientConfig) == 0x20) ? 1 : -1];
typedef char TPlyClientConfigFlagsOffset[(offsetof(TPlyClientConfig::Config, flags) == 8) ? 1 : -1];
typedef char TPlyClientConfigAddressOffset[(offsetof(TPlyClientConfig::Config, proxy_dst_addr) == 0xC) ? 1 : -1];
typedef char TPlyClientConfigPortOffset[(offsetof(TPlyClientConfig::Config, proxy_dst_port) == 0x10) ? 1 : -1];

#endif
