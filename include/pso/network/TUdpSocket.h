#ifndef PSO_NETWORK_TUDPSOCKET_H
#define PSO_NETWORK_TUDPSOCKET_H

#include "types.h"
#include "pso/macros.h"
#include "pso/network/TSocket.h"

EXTERN_OBJECT_NAME(TUdpSocket);

struct UdpSocketEventPair { s32 w[2]; };
struct UdpSocketEventAddr { s32 w[5]; };

// The record handle_socket_event copies out of each received datagram's event.
struct UdpSocketEventRecord {
    UdpSocketEventPair ab;
    UdpSocketEventAddr c;
    UdpSocketEventAddr d;
    u16 e;
};

struct NetworkReceivePrefix;

class TUdpSocket : public TSocket {
public:
    UdpSocketEventRecord m_event;
public:
    TUdpSocket(TObject *parent) : TSocket(parent) {
        m_name = TUdpSocket_name;
    }

    virtual ~TUdpSocket();

    virtual int open();
    virtual void close();
    virtual void recv();
    virtual short send(u8 *data);
    virtual short send(u8 *data, size_t size);

    static s16 handle_socket_event(s16 received, NetworkReceivePrefix *event);
};

LAYOUT_ASSERT(TUdpSocket_size, sizeof(TUdpSocket) == 0x8B8);

extern TUdpSocket *udp_socket_slots[16];

#endif
