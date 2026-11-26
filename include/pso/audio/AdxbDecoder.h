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
    s8 encoding_type; // the ADX header's encoding type; above 4 is AHX, -1 for PCM formats
    s8 bits;
    s8 channels;
    s8 block_bytes; // bytes per block: ADX block size, or channels * bits / 8 for PCM
    s32 block_samples;
    s32 rate;
    s32 samples;
    s16 cutoff; // the ADX header's high-pass cutoff frequency
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
    s32 source_offset; // never read here, zeroed with n and bytes by set_source
    // Asks where the next samples go: position and room in the output buffer, samples
    // still wanted; returns the output buffer.
    s16 *(*read)(void *obj, s32 *pos, s32 *avail, s32 *remaining);
    void *readArg;
    // Told how many bytes and samples a step decoded.
    void (*done)(void *obj, s32 bytes, s32 samples);
    void *doneArg;
    s32 total_written; // samples handed out so far, of samples
    s32 write_pos;     // next write position in the output buffer, below wrap_len
    s32 n;
    s32 bytes;
    s16 format;
    s16 encoding; // sample encoding within the format (WAVE 0 16-bit, 1 8-bit, 2 4-bit)
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
    // Back to idle once decoding ended (state 3).
    void reset();
    void stop();
    // Idle (state 0) to decoding (state 1).
    void start();
    s32 get_total_samples();
    s32 get_block_samples();
    s32 get_channels() const;
    s32 get_rate();
    // Frees every decoder channel and decoder.
    static void clear_pool();
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
// Clear the ADXB decoder pool and the WAV stream-input state (adxt_init / adxt_finish).
void adxb_init(void);
void adxb_finish(void);
// One decode step for the handle's format.
void adxb_exec_handle(AdxbDecoder *adxb);
void adxb_exec_one_adx(AdxbDecoder *adxb);
// Runs the AHX decoder's hook.
void adxb_exec_one_ahx(AdxbDecoder *adxb);
void adxb_exec_one_spsd(AdxbDecoder *adxb);
void adxb_exec_one_aiff(AdxbDecoder *adxb);
void adxb_exec_one_au(AdxbDecoder *adxb);
void adxb_exec_one_wav(AdxbDecoder *adxb);
void TLobby__sub_803C2A00(AdxbDecoder *o);

// Decodes the ADX, SPSD, WAVE, AIFF or AU header at hdr into the handle; returns the
// header size, 0 when the header is not supported.
s32 adxb_decode_header(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 ADXB_DecodeHeaderAdx(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 adxb_decode_header_spsd(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 adxb_decode_header_wav(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 adxb_decode_header_aiff(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 adxb_decode_header_au(AdxbDecoder *adxb, u8 *hdr, s32 size);
s32 adxb_is_spsd_header(const u8 *hdr);
s32 adxb_is_wav_header(const u8 *hdr);
s32 adxb_is_aiff_header(const u8 *hdr);
s32 adxb_is_au_header(const u8 *hdr);
// Reads a Sun/NeXT ".snd" (AU) header; returns the start of the sample data, NULL when the
// header is not supported.
u8 *adx_au_parse_header(u8 *hdr, s32 size, s32 *rate, s32 *channels, s32 *bits, s32 *samples, s32 *format);

void adxb_set_read_callback(AdxbDecoder *adxb, s16 *(*read)(void *, s32 *, s32 *, s32 *), void *obj);
// The callbacks a new handle starts with: decode into the handle's own output buffer.
s16 *adxb_default_read(void *obj, s32 *pos, s32 *avail, s32 *remaining);
void adxb_default_done(void *obj, s32 bytes, s32 samples);
}
void process_byteswapped_pcm_transfer(AdxbDecoder *o);
extern "C" {
s32 TLobby__sub_803C44C0(SpsdHeader *hdr, s32 size, s16 *len, s8 *out_0C, s8 *bits, s8 *block_bytes, s8 *channels, s32 *rate,
                         s32 *samples, s32 *block_samples, s16 *format);
}

#endif
