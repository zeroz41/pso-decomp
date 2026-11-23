#ifndef PSO_NETWORK_RECEIVE_CALLBACK_H
#define PSO_NETWORK_RECEIVE_CALLBACK_H

#include <stddef.h>
#include "types.h"

/* The leading fields of raw IPv4, raw IPv6 and UDP receive records. */
typedef struct NetworkReceivePrefix {
    s16 socket;
    s16 len;
    u8 *buf;
} NetworkReceivePrefix;

LAYOUT_ASSERT(NetworkReceivePrefix_size, sizeof(NetworkReceivePrefix) == 8);
LAYOUT_ASSERT(NetworkReceivePrefix_socket, offsetof(NetworkReceivePrefix, socket) == 0);
LAYOUT_ASSERT(NetworkReceivePrefix_len, offsetof(NetworkReceivePrefix, len) == 2);
LAYOUT_ASSERT(NetworkReceivePrefix_buf, offsetof(NetworkReceivePrefix, buf) == 4);

typedef s16 (*NetworkReceiveCallback)(s16 mode, NetworkReceivePrefix *record);

#endif
