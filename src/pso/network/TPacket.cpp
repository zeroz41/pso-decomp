#include "types.h"
#include "pso/network/TPacket.h"

#pragma readonly_strings on

void TPacket::clear_send_buffer() { m_send_size = 0; }

TPacket::~TPacket() {
    close();
}

OBJECT_NAME(TPacket)

TPacket::TPacket(TObject *parent) : TUdpSocket(parent) {
    m_name = TPacket_name;
    clear_send_buffer();
}
