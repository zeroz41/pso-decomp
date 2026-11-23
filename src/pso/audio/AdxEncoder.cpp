#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#undef PSO_SDK_COMPACT_MATH
#include <string.h>
#include "pso/audio/AdxEncoder.h"

#include "types.h"

#define ADXENC_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define ADXENC_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern "C" {
s32 adx_encoder_max_scale = 0x1000;
char *adx_encoder_copyright_tag = "(c)CRI";

/* The encoder's file-local work pools: 61C4 addresses all three from one .bss base register, which CW
   only does for static data of one TU. */
static AdxEncChannel adx_encoder_channel_work_pools[16];
static AdxEncHistory adx_encoder_history_pool[16];
static AdxEncoder adx_encoder_context_pool[8];

void TLobby__sub_803C5E78(void) {
    s32 i;
    AdxEncoder *enc;

    enc = adx_encoder_context_pool;
    i = 0;
    do {
        if (enc[i].used == 1) {
            adx_encoder_step_context(&enc[i]);
        }
        i++;
    } while (i < 8);
}

inline void set_coef_5ED4(AdxEncCoef *d, s16 coef1, s16 coef2) {
    d->coef1 = coef1;
    d->coef2 = coef2;
}

/* Reads each input's first sample as the start history; returns the channels read (inferred). */
inline s32 read_start_history_5ED4(AdxEncoder *enc) {
    SjChunk b;
    s32 i;

    for (i = 0; i < enc->channels; i++) {
        enc->input[i]->interface->get_chunk(enc->input[i], 1, 2, &b);
        if (b.size == 0) {
            break;
        }
        enc->start_hist1[i] = enc->start_hist2[i] = *(s16 *)b.data;
        enc->input[i]->interface->unget_chunk(enc->input[i], 1, &b);
    }
    return i;
}

inline SjRingBuffer *adxenc_get_output(AdxEncoder *enc) {
    return enc->output;
}

/* Encoder step: state 1 primes the history and writes the ADX header, state 2 encodes (inferred). */
void adx_encoder_step_context(AdxEncoder *enc) {
    s16 coef2;
    s16 coef1;
    SjRingBuffer *out;
    s32 i;
    s32 n;

    if (enc->state == 1) {
        out = adxenc_get_output(enc);
        if (read_start_history_5ED4(enc) < enc->channels) {
            return;
        }
        for (i = 0; i < enc->channels; i++) {
            enc->hist1[i] = enc->start_hist1[i];
            enc->hist2[i] = enc->start_hist2[i];
        }
        n = write_adx_header(enc, out);
        if (n == 0) {
            return;
        }
        enc->bytes_written += n;
        for (i = 0; i < enc->channels; i++) {
            AdxEncChannel *c = enc->channel[i];
            calc_adx_predictor_coeffs((s16)enc->highpass_freq, enc->sample_rate, &coef1, &coef2);
            set_coef_5ED4(&c->coef, coef1, coef2);
            set_coef_5ED4(&c->history->coef, coef1, coef2);
        }
        enc->state = 2;
    } else if (enc->state == 2) {
        adx_process_encoder_output((u8 *)enc);
    }
}

void adx_process_encoder_output(u8 *encoder_buf) {
    AdxEncoder *enc = (AdxEncoder *)encoder_buf;
    s32 encoded_samples;
loop_1:
    if ((s8)enc->end_of_input == 0) {
loop_2:
        encoded_samples = adx_encode_available_blocks(enc);
        if (encoded_samples != 0) {
            enc->bytes_written += encoded_samples;
            if (enc->samples_encoded >= enc->total_samples) {
                enc->end_of_input = 1U;
                goto loop_1;
            }
            goto loop_2;
        }
    } else if (adx_write_zero_padded_block(enc) > 0) {
        enc->state = 3;
    }
}

void TLobby__sub_803C60F0(AdxEncoder *enc, s32 channels, s32 sample_rate, s32 total_samples) {
    enc->channels = channels;
    enc->sample_rate = sample_rate;
    enc->total_samples = total_samples;
    enc->header_samples = total_samples;
    enc->data_offset = 0x11C;
}

void TLobby__sub_803C610C(AdxEncoder *enc) {
    enc->end_of_input = 1;
}

void TLobby__sub_803C6118(AdxEncoder *enc) {
    enc->pad_28 = 0;
    enc->bytes_written = 0;
    enc->samples_encoded = 0;
    enc->end_of_input = 0;
    enc->state = 1;
}

void TLobby__sub_803C6138(AdxEncoder *enc) {
    AdxEncChannel *c;
    if (enc != NULL) {
        TLobby::init_once();
        c = enc->channel[0];
        if (c != NULL && c != NULL) {
            c->used = 0;
            memset(c, 0, sizeof(AdxEncChannel));
        }
        c = enc->channel[1];
        if (c != NULL && c != NULL) {
            c->used = 0;
            memset(c, 0, sizeof(AdxEncChannel));
        }
        memset(enc, 0, 4);
        TLobby::release_ref();
    }
}

inline AdxEncHistory *alloc_history_61C4(void) {
    AdxEncHistory *h;
    s32 i;
    for (i = 0; i < 16; i++) {
        h = &adx_encoder_history_pool[i];
        if (h->used == 0) {
            break;
        }
    }
    return (i < 16) ? h : NULL;
}

inline AdxEncChannel *alloc_channel_61C4(s32 block_samples) {
    AdxEncHistory *h = alloc_history_61C4();
    AdxEncChannel *c;
    s32 i;
    if (h == NULL) {
        return NULL;
    }
    for (i = 0; i < 16; i++) {
        c = &adx_encoder_channel_work_pools[i];
        if (c->used == 0) {
            break;
        }
    }
    c->block_samples = block_samples;
    c->history = h;
    if (i < 16) {
        c->used = 1;
    } else {
        c = NULL;
    }
    return c;
}

/* Creates an encoder reading nch PCM inputs and writing ADX to dst (inferred: CRI ADX encoder create). */
AdxEncoder *TLobby__sub_803C61C4(s32 nch, SjRingBuffer **src, SjRingBuffer *dst) {
    AdxEncoder *enc;
    s32 len;
    s32 i;

    len = strlen(adx_encoder_copyright_tag);
    for (i = 0; i < 8; i++) {
        if (adx_encoder_context_pool[i].used == 0) {
            break;
        }
    }
    if (i == 8) {
        return NULL;
    }
    enc = &adx_encoder_context_pool[i];
    enc->num_inputs = nch;
    for (i = 0; i < nch; i++) {
        enc->input[i] = src[i];
    }
    enc->output = dst;
    enc->state = 0;
    enc->pad_28 = 0;
    enc->bytes_written = 0;
    enc->samples_encoded = 0;
    enc->pad_34 = 0x7FFF0000;
    enc->data_offset = len + 0x20;
    enc->data_offset = (enc->data_offset + 3) / 4 * 4;
    enc->data_offset = (enc->data_offset - 4 > 14) ? enc->data_offset - 4 : 14;
    enc->encoding_type = 3;
    enc->channels = nch;
    enc->sample_rate = 44100;
    enc->sample_bits = 4;
    enc->block_size = 18;
    enc->block_samples = (enc->block_size - 2) * 8 / enc->sample_bits;
    enc->header_samples = 0x7FFF0000;
    enc->highpass_freq = 500;
    enc->loop_type = 0;
    enc->loop_count = 0;
    enc->loop_start_sample = 0;
    enc->loop_start_byte = 0;
    enc->loop_end_sample = 0;
    enc->loop_end_byte = 0;
    enc->pad_38 = 0;
    enc->total_samples = 0;
    enc->pad_40 = enc->block_samples * ((enc->header_samples - 1) / enc->block_samples + 1);
    enc->channel[0] = alloc_channel_61C4(enc->block_samples);
    enc->channel[1] = alloc_channel_61C4(enc->block_samples);
    enc->start_hist2[0] = 0;
    enc->start_hist1[0] = 0;
    enc->start_hist2[1] = 0;
    enc->start_hist1[1] = 0;
    enc->used = 1;
    return enc;
}

void TLobby::clear_net_buffer_1680() {
    memset(adx_encoder_context_pool, 0, sizeof(adx_encoder_context_pool));
}

void TLobby::clear_buffer_1680() {
    memset(adx_encoder_context_pool, 0, sizeof(adx_encoder_context_pool));
}

#pragma push
#pragma opt_propagation off

inline s32 put8_803C6860(SjRingBuffer *s, const void *v) {
    SjChunk b;
    s->interface->get_chunk(s, 0, 1, &b);
    if (b.size < 1) {
        s->interface->unget_chunk(s, 0, &b);
        return 0;
    }
    memcpy(b.data, v, 1);
    s->interface->put_chunk(s, 1, &b);
    return 1;
}

inline s32 put16_803C6860(SjRingBuffer *s, const void *v) {
    SjChunk b;
    s->interface->get_chunk(s, 0, 2, &b);
    if (b.size < 2) {
        s->interface->unget_chunk(s, 0, &b);
        return 0;
    }
    s16 *d = (s16 *)b.data;
    *d = *(const s16 *)v;
    s->interface->put_chunk(s, 1, &b);
    return 1;
}

inline s32 put32_803C6860(SjRingBuffer *s, const void *v) {
    SjChunk b;
    s->interface->get_chunk(s, 0, 4, &b);
    if (b.size < 4) {
        s->interface->unget_chunk(s, 0, &b);
        return 0;
    }
    s32 *d = (s32 *)b.data;
    *d = *(const s32 *)v;
    s->interface->put_chunk(s, 1, &b);
    return 1;
}

inline s32 putn_803C6860(SjRingBuffer *s, void *src, s32 n) {
    SjChunk b;
    s->interface->get_chunk(s, 0, n, &b);
    if (b.size < n) {
        s->interface->unget_chunk(s, 0, &b);
        return 0;
    }
    memcpy(b.data, src, (u16)n);
    s->interface->put_chunk(s, 1, &b);
    return n;
}

s32 write_adx_header(AdxEncoder *encoder, SjRingBuffer *s) {
    u8 c;
    u16 h;
    u16 h2;
    s32 w;
    s32 len;
    s32 total;
    s32 i;
    s32 lim;

    len = strlen(adx_encoder_copyright_tag);
    h = 0x8000;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h2 = encoder->data_offset;
    if (put16_803C6860(s, &h2) != 1) {
        goto fail;
    }
    c = encoder->encoding_type;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = encoder->block_size;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = encoder->sample_bits;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = encoder->channels;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    w = encoder->sample_rate;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    w = encoder->header_samples;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    h = encoder->highpass_freq;
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    c = 4;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    c = 0;
    if (put8_803C6860(s, &c) != 1) {
        goto fail;
    }
    w = 0;
    if (put32_803C6860(s, &w) != 1) {
        goto fail;
    }
    h = encoder->start_hist1[0];
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = encoder->start_hist2[0];
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = encoder->start_hist1[1];
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    h = encoder->start_hist2[1];
    if (put16_803C6860(s, &h) != 1) {
        goto fail;
    }
    total = 0x1C;
    if (encoder->loop_count > 0) {
        h = encoder->loop_type;
        if (put16_803C6860(s, &h) != 1) {
            goto fail;
        }
        h = encoder->loop_count;
        if (put16_803C6860(s, &h) != 1) {
            goto fail;
        }
        total += 4;
        for (i = 0; i < encoder->loop_count; i++) {
            h = i;
            if (put16_803C6860(s, &h) != 1) {
                goto fail;
            }
            h = 1;
            if (put16_803C6860(s, &h) != 1) {
                goto fail;
            }
            w = encoder->loop_start_sample;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = encoder->loop_start_byte;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = encoder->loop_end_sample;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            w = encoder->loop_end_byte;
            if (put32_803C6860(s, &w) != 1) {
                goto fail;
            }
            total += 0x14;
        }
    }
    c = 0;
    lim = encoder->data_offset - len;
    for (; total < lim; total++) {
        if (put8_803C6860(s, &c) != 1) {
            goto fail;
        }
    }
    if (putn_803C6860(s, adx_encoder_copyright_tag, len) != len) {
        goto fail;
    }
    total += len;
    return total + 4;
fail:
    return 0;
}

#pragma pop

#pragma push
#pragma opt_propagation off
inline void put16_803C7748(SjRingBuffer *s, const void *src) {
    SjChunk b;
    s->interface->get_chunk(s, 0, 2, &b);
    if (b.size < 2) {
        s->interface->unget_chunk(s, 0, &b);
    } else {
        s16 *d = (s16 *)b.data;
        *d = *(const s16 *)src;
        s->interface->put_chunk(s, 1, &b);
    }
}

inline void put_803C7748(SjRingBuffer *s, void *src, s32 n) {
    SjChunk b;
    s->interface->get_chunk(s, 0, n, &b);
    if (b.size < n) {
        s->interface->unget_chunk(s, 0, &b);
    } else {
        memcpy(b.data, src, n);
        s->interface->put_chunk(s, 1, &b);
    }
}

s32 adx_write_zero_padded_block(AdxEncoder *enc) {
    s32 len;
    s32 n;
    s32 i;
    u16 w;
    u8 zero;
    SjRingBuffer *s = enc->output;
    s32 off = enc->bytes_written;

    if (enc->loop_count <= 0) {
        n = enc->block_size;
    } else {
        n = (((off + enc->block_size + 0x7FF) / 2048) << 11) - off;
    }
    len = n - 4;
    if (s->interface->get_available(s, 0) < n) {
        return 0;
    }
    w = 0x8001;
    put16_803C7748(s, &w);
    w = len;
    put16_803C7748(s, &w);
    zero = 0;
    for (i = 0; i < len; i++) {
        put_803C7748(s, &zero, 1);
    }
    return n;
}
#pragma pop

/* Pulls n samples per channel from the input streams into pcm (inferred). */
inline s32 read_input_samples_7978(AdxEncoder *enc, s16 **pcm, s32 n) {
    SjRingBuffer **in;
    SjChunk b;
    s32 got;
    s32 i;

    in = enc->input;
    got = 0;
    for (i = 0; i < enc->channels; i++) {
        got = in[i]->interface->get_available(in[i], 1) / sizeof(s16);
        if (got < n) {
            return 0;
        }
    }
    for (i = 0; i < enc->channels; i++) {
        for (got = 0; got < n;) {
            in[i]->interface->get_chunk(in[i], 1, n * sizeof(s16), &b);
            memcpy(pcm[i] + got, b.data, b.size);
            got += b.size / sizeof(s16);
            in[i]->interface->put_chunk(in[i], 0, &b);
        }
    }
    return got;
}

/* Stores a channel's predictor history into the encoder (inferred). */
inline void set_history_7978(AdxEncoder *enc, s32 ch, s16 hist1, s16 hist2) {
    enc->hist1[ch] = hist1;
    enc->hist2[ch] = hist2;
}

/* Scales and quantizes one block of every channel (inferred). */
inline void encode_channels_7978(AdxEncoder *enc) {
    s32 ch;
    AdxEncChannel *c;
    AdxEncHistory *h;

    for (ch = 0; ch < enc->channels; ch++) {
        adx_encoder_process_step(enc, ch);
        c = enc->channel[ch];
        h = c->history;
        enc->block_scale[ch] = c->scale;
        enc->block_inv_scale[ch] = c->inv_scale;
        set_history_7978(enc, ch, h->hist1, h->hist2);
        adx_encoder_finish_block(enc, ch);
    }
}

inline s32 encode_block_7978(AdxEncoder *enc) {
    s16 *pcm[2];
    s32 i;
    s32 n;

    pcm[0] = enc->pcm[0];
    pcm[1] = enc->pcm[1];
    n = (enc->block_samples < enc->total_samples - enc->samples_encoded) ? enc->block_samples
                                                                          : enc->total_samples - enc->samples_encoded;
    if (read_input_samples_7978(enc, pcm, n) == 0) {
        return 0;
    }
    if (n < enc->block_samples) {
        for (i = 0; i < enc->channels; i++) {
            if (pcm[i] != NULL) {
                memset(pcm[i] + n, 0, (enc->block_samples - n) * sizeof(s16));
            }
        }
    }
    enc->samples_encoded += enc->block_samples;
    encode_channels_7978(enc);
    return enc->block_samples;
}

// Encodes every complete block of the input (inferred: CRI adxsje_encode_data).
s32 adx_encode_available_blocks(AdxEncoder *enc) {
    s32 total;
    SjRingBuffer *out;

    total = 0;
    out = enc->output;
    do {
        if (out->interface->get_available(out, 0) / 18 / enc->channels <= 0) {
            break;
        }
        if (encode_block_7978(enc) == 0) {
            break;
        }
        total += adx_write_encoded_blocks(enc);
    } while (enc->samples_encoded < enc->total_samples);
    return total;
}

inline void put_803C7C10(SjRingBuffer *s, void *src, s32 n) {
    SjChunk b;
    s->interface->get_chunk(s, 0, n, &b);
    if (b.size < n) {
        s->interface->unget_chunk(s, 0, &b);
    } else {
        memcpy(b.data, src, n);
        s->interface->put_chunk(s, 1, &b);
    }
}
s32 adx_write_encoded_blocks(AdxEncoder *enc) {
    s32 i;
    s32 total;
    u8 c;
    SjRingBuffer *s = enc->output;
    i = 0;
    total = 0;
    for (; i < enc->channels; i++) {
        s16 v = enc->block_scale[i] - 1;
        c = v >> 8;
        put_803C7C10(s, &c, 1);
        c = v;
        put_803C7C10(s, &c, 1);
        put_803C7C10(s, enc->block_data[i], 16);
        total += 0x12;
    }
    return total;
}

// Quantizes one block of channel ch to ADX nibbles (inferred: the ADX encoder's block step).
void adx_encoder_finish_block(AdxEncoder *enc, s32 ch) {
    s32 i;
    s32 k;
    s32 per_byte;
    AdxEncChannel *c;
    s32 v;
    s32 q;
    s32 r;
    s16 *in;
    s16 *clamped;
    s16 *decoded;
    u8 *out;
    s32 b;

    in = enc->input_samples[ch];
    out = enc->block_data[ch];
    k = 0;
    per_byte = 8 / enc->sample_bits;
    c = enc->channel[ch];
    clamped = enc->clamped_samples[ch];
    b = -1;
    decoded = enc->decoded_samples[ch];
    for (i = 0; i < enc->block_samples; i++) {
        in[i] = (c == NULL) ? 0 : c->samples[i];
        v = (s32)(c->inv_scale * in[i]);
        r = ADXENC_MIN(0x7FFF, ADXENC_MAX(-0x8000, v));
        clamped[i] = r;
        if (clamped[i] < 0) {
            q = (r - 0x924) / 0x1249;
        } else {
            q = (r + 0x924) / 0x1249;
        }
        q = ADXENC_MIN(ADXENC_MAX(-8, q), 7);
        v = (s32)(c->inv_scale * (q * c->scale));
        r = ADXENC_MIN(0x7FFF, ADXENC_MAX(-0x8000, v));
        decoded[i] = r;
        if (i % per_byte == 0) {
            k = 1;
            b++;
            out[b] = 0;
        }
        out[b] |= (s8)(((u8)((u32)q << (8 - enc->sample_bits)) >> (8 - enc->sample_bits)) << (enc->sample_bits * (per_byte - k)));
        k++;
    }
}


/* Predicts sample i from the channel history and records the residual (inferred). */
inline void predict_sample_8020(AdxEncChannel *c, s32 i, s16 smp) {
    s32 j;
    if (i == 0) {
        for (j = 0; j < c->block_samples; j++) {
            c->samples[j] = 0;
        }
        c->peak = 0;
    }
    if (c != NULL) {
        s32 d = smp - ((c->coef.coef1 * c->hist1) >> 12) - ((c->coef.coef2 * c->hist2) >> 12);
        s16 r = ADXENC_MIN(32767, ADXENC_MAX(-32768, d));
        c->samples[i] = r;
        if (__abs(r) > c->peak) {
            c->peak = __abs(r);
        }
        c->hist2 = c->hist1;
        c->hist1 = smp;
    }
}

inline s16 residual_8020(AdxEncChannel *c, s32 i) {
    if (c == NULL) {
        return 0;
    }
    return c->samples[i];
}

inline void set_history_8020(AdxEncHistory *h, s16 hist1, s16 hist2) {
    h->hist1 = hist1;
    h->hist2 = hist2;
}

/* Runs the decoder's predictor on a quantized value to track what the decoder will see (inferred). */
inline void decode_sample_8020(AdxEncChannel *c, s16 v) {
    AdxEncHistory *dec = c->history;
    if (dec != NULL) {
        s32 d = v + ((dec->coef.coef1 * dec->hist1 + dec->coef.coef2 * dec->hist2) >> 12);
        s16 h = ADXENC_MIN(ADXENC_MAX(d, -32768), 32767);
        dec->hist2 = dec->hist1;
        dec->hist1 = h;
    }
}

/* Computes the block scale of channel ch, then quantizes it against the decoder's history (inferred). */
s32 adx_encoder_process_step(AdxEncoder *enc, s32 ch) {
    s16 *smp = enc->pcm[ch];
    s32 i;
    AdxEncChannel *c = enc->channel[ch];
    AdxEncHistory *dec = c->history;
    s32 scale;

    set_history_8020(c, enc->hist1[ch], enc->hist2[ch]);
    for (i = 0; i < enc->block_samples; i++) {
        predict_sample_8020(c, i, smp[i]);
    }
    scale = (c->peak - 1) / 7 + 1;
    c->scale = ADXENC_MAX(ADXENC_MIN(scale, adx_encoder_max_scale), 1);
    if (c->peak == 0) {
        c->inv_scale = 32767.0;
    } else {
        c->inv_scale = 32767.0 / c->peak;
    }
    set_history_8020(c->history, enc->hist1[ch], enc->hist2[ch]);
    for (i = 0; i < enc->block_samples; i++) {
        s16 s = *smp;
        s32 f;
        s16 v;
        s32 q;
        s32 k;
        s16 d;
        set_history_8020(c, dec->hist1, dec->hist2);
        predict_sample_8020(c, i, s);
        d = residual_8020(c, i);
        f = d * c->inv_scale;
        v = ADXENC_MIN(32767, ADXENC_MAX(-32768, f));
        if (v < 0) {
            q = (v - 2340) / 4681;
        } else {
            q = (v + 2340) / 4681;
        }
        k = ADXENC_MIN(ADXENC_MAX(-8, q), 7);
        c->quantized[i] = k;
        f = k * c->scale;
        d = ADXENC_MIN(32767, ADXENC_MAX(-32768, f));
        decode_sample_8020(c, d);
        smp++;
    }
    return 0;
}
}

