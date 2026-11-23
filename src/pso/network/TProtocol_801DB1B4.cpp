#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DF280.h"

LAYOUT_ASSERT(ProtocolConnectedOffset, offsetof(TProtocol, m_connected) == 0x1910);

void TProtocol::send_choice_search(TPlyChoiceSearchConfig &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC3;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        packet.bswap();
        send((u8*)&packet, sizeof(packet));
    }
}

void TProtocol::send_choice_search_parameters(TPlyChoiceSearchConfig &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC2;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        packet.bswap();
        send((u8*)&packet, sizeof(packet));
    }
}
