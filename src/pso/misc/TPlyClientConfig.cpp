#include "pso/player/TPlyClientConfig.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ClientConfigBytes { u8 bytes[0x20]; };

TPlyClientConfig& TPlyClientConfig::operator=(const TPlyClientConfig& other) {
    *reinterpret_cast<ClientConfigBytes*>(this) =
        *reinterpret_cast<const ClientConfigBytes*>(&other);
    return *this;
}
