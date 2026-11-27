#ifndef PSO_AUDIO_ADXENCODER_H
#define PSO_AUDIO_ADXENCODER_H

#include "pso/audio/SjRingBuffer.h"
#include <stddef.h>

// CRI ADX encoder (AdxEncoder.cpp): encodes PCM read from SJ streams into an
// ADX stream; its contexts are pooled in adx_encoder_context_pool.

struct AdxEncoder;

/* ADX encoder work objects (CRI ADX encoder, statically pooled in AdxEncoder.cpp). */
struct AdxEncCoef {
    s16 coef1;
    s16 coef2;
};

struct AdxEncHistory {
    s8 used;
    u8 pad_1[3];
    AdxEncCoef coef;
    s16 hist1;
    s16 hist2;
};

struct AdxEncChannel : AdxEncHistory {
    u8 pad_c[8];
    s32 block_samples;
    s16 samples[32];
    s8 quantized[32];
    s32 peak;
    s16 scale;
    u8 pad_7e[2];
    f64 inv_scale;
    AdxEncHistory *history;
    u8 pad_8c[4];
};

struct AdxEncoder {
    s8 used;
    s8 state;
    s8 num_inputs;
    s8 end_of_input;
    SjRingBuffer *input[2];
    SjRingBuffer *output;
    u8 pad_10[0x18];
    s32 pad_28;
    s32 bytes_written;
    s32 samples_encoded;
    s32 pad_34;
    s32 pad_38;
    s32 total_samples;
    s32 padded_samples; // header_samples rounded up to whole blocks
    s32 block_samples;
    s32 data_offset;
    s32 encoding_type;
    s32 block_size;
    s32 sample_bits;
    s32 channels;
    s32 sample_rate;
    s32 header_samples;
    s32 highpass_freq;
    s32 loop_type;
    s32 loop_count;
    s32 loop_start_sample;
    s32 loop_start_byte;
    s32 loop_end_sample;
    s32 loop_end_byte;
    AdxEncChannel *channel[2];
    s16 hist1[2];
    s16 hist2[2];
    s16 pcm[2][32];
    s16 input_samples[2][32];
    s16 clamped_samples[2][32];
    s16 decoded_samples[2][32];
    s16 block_scale[2];
    u8 pad_294[4];
    f64 block_inv_scale[2];
    u8 block_data[2][16];
    s16 start_hist1[2];
    s16 start_hist2[2];
};

LAYOUT_ASSERT(AdxEncHistory_size, sizeof(AdxEncHistory) == 0x0C);
LAYOUT_ASSERT(AdxEncChannel_size, sizeof(AdxEncChannel) == 0x90);
LAYOUT_ASSERT(AdxEncoder_size, sizeof(AdxEncoder) == 0x2D0);
LAYOUT_ASSERT(AdxEncoder_channel_offset, offsetof(AdxEncoder, channel) == 0x80);
LAYOUT_ASSERT(AdxEncoder_start_history_offset, offsetof(AdxEncoder, start_hist1) == 0x2C8);

// --- C functions defined in AdxEncoder.cpp ---
extern "C" {
void adx_encoder_exec_server(void);
void adx_encoder_step_context(AdxEncoder *enc);
void adx_process_encoder_output(AdxEncoder *enc);
s32 adx_write_zero_padded_block(AdxEncoder *enc);
void adx_encoder_set_input_info(AdxEncoder *enc, s32 channels, s32 sample_rate, s32 total_samples);
void adx_encoder_end_input(AdxEncoder *enc);
void adx_encoder_start(AdxEncoder *enc);
void adx_encoder_destroy(AdxEncoder *enc);
AdxEncoder *adx_encoder_create(s32 nch, SjRingBuffer **src, SjRingBuffer *dst);
s32 adx_encode_available_blocks(AdxEncoder *enc);
s32 adx_write_encoded_blocks(AdxEncoder *enc);
s32 write_adx_header(AdxEncoder *encoder, SjRingBuffer *stream);
void adx_encoder_finish_block(AdxEncoder *enc, s32 ch);
s32 adx_encoder_process_step(AdxEncoder *enc, s32 ch);
}
// --- end of C functions

extern "C" {
void adx_encoder_pool_finish();
void adx_encoder_pool_init();
}

#endif
