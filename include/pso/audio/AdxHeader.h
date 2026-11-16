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

// --- C functions defined in AdxHeader.cpp ---
extern "C" {
s32 ARStartDMA(u8 *hdr, s32 size, s16 *len, u8 *out_0C, s8 *bits, s8 *block_bytes, u8 *channels, s32 *rate, s32 *samples, s32 *block_samples);
s32 TLobby__sub_803C48C8(u8 *hdr, s32 size, u16 *out);
s32 __DVDPrepareResetAsync(u8 *hdr, s32 size, s32 *o1, s16 *o2, s16 *o3, s32 *o4, s32 *o5, s32 *o6, s32 *o7);
void calc_adx_predictor_coeffs(s32 cutoff, s32 rate, s16 *k0, s16 *k1);
}
// --- end of C functions

#endif
