#ifndef PSO_AUDIO_ADXENCODER_H
#define PSO_AUDIO_ADXENCODER_H

#include "pso/audio/SjRingBuffer.h"

// CRI ADX encoder (AdxEncoder.cpp): encodes PCM read from SJ streams into an
// ADX stream; its contexts are pooled in adx_encoder_context_pool.

struct AdxEncoder;


// Defined in TLobby_803C4698.cpp: predictor coefficients for a high-pass cutoff at a sample rate.
void calc_adx_predictor_coeffs(s32 cutoff, s32 rate, s16 *k0, s16 *k1);
extern "C" {
void TLobby__sub_803C5E78(void);
void adx_process_encoder_output(u8 *arg0p);
void TLobby__sub_803C60F0(AdxEncoder *enc, s32 channels, s32 sample_rate, s32 total_samples);
void TLobby__sub_803C610C(AdxEncoder *enc);
void TLobby__sub_803C6118(AdxEncoder *enc);
void TLobby__sub_803C6138(AdxEncoder *enc);
AdxEncoder *TLobby__sub_803C61C4(s32 nch, SjRingBuffer **src, SjRingBuffer *dst);
}

// --- C functions defined in AdxEncoder.cpp ---
extern "C" {
void TLobby__sub_803C5E78(void);
void TLobby__sub_803C60F0(AdxEncoder *enc, s32 channels, s32 sample_rate, s32 total_samples);
void TLobby__sub_803C610C(AdxEncoder *enc);
void TLobby__sub_803C6118(AdxEncoder *enc);
AdxEncoder *TLobby__sub_803C61C4(s32 nch, SjRingBuffer **src, SjRingBuffer *dst);
void adx_process_encoder_output(u8 *arg0p);
s32 put16_803C6860(SjRingBuffer *s, const void *v);
s32 put32_803C6860(SjRingBuffer *s, const void *v);
s32 put8_803C6860(SjRingBuffer *s, const void *v);
void put_803C7C10(SjRingBuffer *s, void *src, s32 n);
s32 putn_803C6860(SjRingBuffer *s, void *src, s32 n);
}
// --- end of C functions

#endif
