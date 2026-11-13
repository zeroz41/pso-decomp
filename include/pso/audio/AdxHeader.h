#ifndef PSO_AUDIO_ADX_HEADER_H
#define PSO_AUDIO_ADX_HEADER_H

#include "types.h"

// Block of an ADX header at 0x14, or at 0x20 when the byte at 0x12 is 4.
struct AdxHeaderBlock {
    s16 m_00;
    s16 m_02;
    s16 m_04;
    s16 m_06;
    s32 m_08;
    s32 m_0C;
    s32 m_10;
    s32 m_14;
};

// Packet header checked by parse_packet_header_len.
struct AdxPacketHeader {
    u16 type;
    s16 len;
};

// Big-endian ADX file header, read in place.
struct AdxHeader {
    u16 m_00;
    s16 m_02;
    u8 pad_04[0xC];
    u16 m_10;
    u8 m_12;
    u8 pad_13;
    u8 pad_14[0x4];
    u16 m_18[4];
};

#endif
