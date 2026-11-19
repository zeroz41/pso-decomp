#include "types.h"
#include "pso/network/TPacket.h"

#pragma readonly_strings on

void TPacket::clear_send_buffer() { m_send_size = 0; }

TPacket::~TPacket() {
    close();
}

const char *lbl_805D34C0 = "TPacket";

TPacket::TPacket(TObject *parent) : TUdpSocket(parent) {
    m_name = lbl_805D34C0;
    clear_send_buffer();
}
