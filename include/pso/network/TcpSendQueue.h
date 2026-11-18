#ifndef PSO_NETWORK_TCPSENDQUEUE_H
#define PSO_NETWORK_TCPSENDQUEUE_H

#include "pso/network/BufferRef.h"

typedef void (*TcpCompletion)(s16 status, s16 handle);
typedef void (*TcpSendCallback)(s16 status, s16 handle, s32 value);

/* Entry in the TCP send ring while it holds queued user buffers. */
typedef struct TcpSendRequest {
    NetBufferRef buffer;
    s16 length;
    s16 offset;
    TcpSendCallback callback;
} TcpSendRequest;
typedef char TcpSendRequest_size_check[sizeof(TcpSendRequest) == 0x10 ? 1 : -1];

#endif
