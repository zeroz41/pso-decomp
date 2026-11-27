#ifndef PSO_NETWORK_TPACKET_H
#define PSO_NETWORK_TPACKET_H

#include "types.h"
#include "pso/network/TUdpSocket.h"

// A UDP socket with a 0x5B4-byte send buffer; dispatch_pso_data_commands walks the subcommands of a
// received packet.
class TPacket : public TUdpSocket {
public:
    s32 m_send_size;
    u8 m_send_buffer[0x5B4];
public:
    TPacket(TObject *parent);
    virtual ~TPacket();

    void clear_send_buffer();
};

LAYOUT_ASSERT(TPacket_size, sizeof(TPacket) == 0xE70);

#endif
