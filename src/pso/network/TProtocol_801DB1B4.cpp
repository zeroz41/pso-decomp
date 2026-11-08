#include "pso/network/TProtocol.h"
#include "pso/unk/text_801DF280.h"

extern "C" {
void copy_choice_search_parameters(ChoiceSearchParameters *, ChoiceSearchParameters *);
}

typedef char ProtocolConnectedOffset[(offsetof(TProtocol, m_connected) == 0x1910) ? 1 : -1];

void TProtocol::send_choice_search(ChoiceSearchParameters &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC3;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        bswap_choice_search_packet(&packet);
        send((u8*)&packet, sizeof(packet));
    }
}

void TProtocol::send_choice_search_parameters(ChoiceSearchParameters &parameters) {
    ChoiceSearchPacket packet;
    if (m_connected != 0) {
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xC2;
        packet.header.flags = 0;
        packet.header.size = sizeof(packet);
        copy_choice_search_parameters(&packet.parameters, &parameters);
        bswap_choice_search_packet(&packet);
        send((u8*)&packet, sizeof(packet));
    }
}
