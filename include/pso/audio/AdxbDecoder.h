#ifndef PSO_AUDIO_ADXB_DECODER_H
#define PSO_AUDIO_ADXB_DECODER_H

#include "types.h"

struct AdxDecoderChannel;

// One ADXB decoder ("ADXB_DecodeHeaderAdx"), shared by the ADX, SPSD, AIFF and AU decoders.
struct AdxbDecoder {
    s16 used;
    s16 m_02;
    s32 state;
    AdxDecoderChannel *channel;
    s8 m_0C;
    s8 bits;
    s8 channels;
    s8 block_bytes; // bytes per block: ADX block size, or channels * bits / 8 for PCM
    s32 block_samples;
    s32 rate;
    s32 samples;
    s16 m_1C;
    u8 pad_1E[0x2];
    s32 loop_enabled;
    s16 loop_type;
    s16 loop_count;
    s32 loop_start_sample;
    s32 loop_start_byte;
    s32 loop_end_sample;
    s32 loop_end_byte;
    s32 m_38;
    s16 *output_buffer;
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
    s32 source_offset; // inferred: never read here, zeroed with n and bytes by set_source
    void (*read)(s32, s32 *, s32 *, s32 *);
    saddr readArg;
    void (*done)(s32, s32, s32);
    s32 doneArg;
    s32 m_98;
    s32 m_9C;
    s32 n;
    s32 bytes;
    s16 format;
    s16 m_AA;
    void *ahx_handle; // "can't play AHX data by this handle" when null
    s32 max_samples;      // the stream input's max_samples
    s32 max_sample_units; // max_samples / 96

    static AdxbDecoder *alloc_record(s32 channels, saddr buffer, s32 size, s32 wrap_offset);
    void clear_record();
    void invoke_notify_callback();
    void set_max_samples(s32 limit);
    void set_source(u8 *data, s32 size);
    s32 get_state();
    s32 get_format();
    s32 get_loop_type();
    s32 get_loop_start_sample();
    s32 get_loop_start_byte();
    s32 get_loop_end_sample();
    s32 get_loop_end_byte();
    s16 *get_output_buffer();
    s32 get_decoded_samples();
    s32 get_decoded_bytes();
    s32 get_packet_flag_for_state();
};
LAYOUT_ASSERT(AdxbDecoder_size_check, sizeof(AdxbDecoder) == 0xB8);

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
s32 sub_803C1668(AdxbDecoder *decoder, u8 *buffer, s32 len);
void TLobby__sub_803C34F4(AdxbDecoder *decoder);
s32 TLobby__sub_803C3B38(const AdxbDecoder *decoder);
}
void process_byteswapped_pcm_transfer(AdxbDecoder *o);
extern "C" {
void TLobby__sub_803C40D0(AdxbDecoder *o);
s32 TLobby__sub_803C44C0(SpsdHeader *hdr, s32 size, s16 *len, s8 *out_0C, s8 *bits, s8 *block_bytes, s8 *channels, s32 *rate,
                         s32 *samples, s32 *block_samples, s16 *format);
}

#endif
