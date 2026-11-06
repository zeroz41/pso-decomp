#include "pso/network/TProtocol.h"
#include "pso/ui/chat/TChatMessage.h"
#include "pso/player/TPlyGuildCardTag_8007B434.h"
#include "pso/unk/text_801DF280.h"
#include <stddef.h>

struct CharacterSaveInfoPacket {
    packet_header header;
    C_CharSaveInfo_DCv2_PC_V3_BB_96 payload;
};

struct ChangeShipOrBlockPacket {
    packet_header header;
    C_ChangeShipOrBlock_A0_A1 payload;
};

typedef char CharacterSaveInfoPacket_size[sizeof(CharacterSaveInfoPacket) == 0xC ? 1 : -1];
typedef char ChangeShipOrBlockPacket_size[sizeof(ChangeShipOrBlockPacket) == 0x1C ? 1 : -1];
typedef char TProtocol_connected_offset[offsetof(TProtocol, m_connected) == 0x1910 ? 1 : -1];
typedef char TProtocol_guildcard_offset[offsetof(TProtocol, m_guildcard_tag) == 0x1900 ? 1 : -1];

void TProtocol::send_character_save_info(int creation_timestamp, int event_counter) {
    CharacterSaveInfoPacket packet;
    packet.header.command = 0x96;
    packet.header.flags = 0;
    packet.header.size = sizeof(packet);
    packet.payload.creation_timestamp = creation_timestamp;
    packet.payload.event_counter = event_counter;
    bswap_save_packet((s32)&packet);
    send((u8 *)&packet, sizeof(packet));
}

void TProtocol::send_quest_menu_request() {
    packet_header header;
    if (m_connected != 0) {
        header.command = 0xA2;
        header.flags = 0;
        header.size = sizeof(header);
        header.bswap();
        send((u8 *)&header, sizeof(header));
    }
}

void TProtocol::send_block_list_request() {
    ChangeShipOrBlockPacket packet;
    u8 pad[8];
    if (m_connected != 0) {
        fn_801DF8A8((s32)&packet);
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xA1;
        packet.header.size = sizeof(packet);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&packet.payload, &m_guildcard_tag);
        fn_801DF874(&packet);
        send((u8 *)&packet, sizeof(packet));
    }
}

void TProtocol::send_ship_list_request() {
    ChangeShipOrBlockPacket packet;
    u8 pad[8];
    if (m_connected != 0) {
        fn_801DF8A8((s32)&packet);
        memset(&packet, 0, sizeof(packet));
        packet.header.command = 0xA0;
        packet.header.size = sizeof(packet);
        __as__16TPlyGuildCardTagFRC16TPlyGuildCardTag(&packet.payload, &m_guildcard_tag);
        fn_801DF874(&packet);
        send((u8 *)&packet, sizeof(packet));
    }
}

void TProtocol::send_simple_mail(TChatMessage &message) {
    if (m_connected != 0) {
        message.header.command = 0x81;
        message.header.flags = 0;
        message.header.size = 0x220;
        bswap__12TChatMessageFv((s32)&message);
        send((u8 *)&message, 0x220);
    }
}
