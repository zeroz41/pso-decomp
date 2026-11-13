#ifndef PSO_AUDIO_ADXB_DECODER_H
#define PSO_AUDIO_ADXB_DECODER_H

#include "types.h"

class TLobby;

// One ADXB decoder ("ADXB_DecodeHeaderAdx"), shared by the ADX, SPSD, AIFF and AU decoders.
struct AdxbDecoder {
    u8 pad_00[0x2];
    s16 m_02;
    s32 state;
    TLobby *id;
    s8 m_0C;
    s8 bits;
    s8 channels;
    s8 block_bytes; // bytes per block: ADX block size, or channels * bits / 8 for PCM
    s32 block_samples;
    s32 rate;
    s32 samples;
    s16 m_1C;
    u8 pad_1E[0x2];
    s32 m_20;
    s16 m_24;
    s16 m_26;
    s32 m_28;
    s32 m_2C;
    s32 m_30;
    s32 m_34;
    u8 pad_38[0x4];
    s16 *m_3C;
    s32 wrap_len;    // samples; data past it is copied back to the buffer start
    s32 wrap_offset; // second channel's offset for that copy
    s16 m_48;
    s16 m_4A;
    u8 m_4C[0x4];
    u8 *src;
    s32 maxLen;
    s32 stream_channels; // 2 = two channel buffers, rOff apart
    s32 stream_block_bytes;
    s32 stream_block_samples;
    s16 *buf;
    s32 bufLen;
    s32 rOff;
    s32 pos;
    s32 avail;
    s32 x78;
    s16 m_7C;
    s16 m_7E;
    u8 *m_80;
    u8 pad_84[0x4];
    void (*read)(s32, s32 *, s32 *, s32 *);
    s32 readArg;
    void (*done)(s32, s32, s32);
    s32 doneArg;
    s32 m_98;
    s32 m_9C;
    s32 n;
    s32 bytes;
    s16 m_A8;
    s16 m_AA;
};

// SPSD header fields read by the SPSD decoder.
struct SpsdHeader {
    u8 pad_00[0x7];
    u8 m_07;
    u8 m_08;
    u8 m_09;
    u8 pad_0A[0x2];
    s32 m_0C;
    u8 pad_10[0x1A];
    u16 m_2A;
};

extern "C" {
void TLobby__sub_803C2A00(AdxbDecoder *o);
void process_byteswapped_pcm_transfer(AdxbDecoder *o);
void TLobby__sub_803C40D0(AdxbDecoder *o);
s32 TLobby__sub_803C44C0(SpsdHeader *hdr, s32 size, s16 *len, s8 *out_0C, s8 *bits, s8 *block_bytes, s8 *channels, s32 *rate,
                         s32 *samples, s32 *block_samples, s16 *format);
}

#endif
