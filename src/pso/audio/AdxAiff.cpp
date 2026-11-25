#include "types.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AdxExpand.h"
#include "pso/audio/AudioStreamInput.h"
#include <stddef.h>
#include "pso/audio/SjRingBuffer.h"
#include "pso/network/TLobby.h"
#include "pso/unk/text_803C1780.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include <string.h>
#include "pso/audio/AdxAiff.h"
#include "pso/audio/AiffHeader.h"

// The RIFF chunk ids TLobby__sub_803C1780 scans a WAVE header for.
const char *wav_fmt_chunk_id = "fmt ";
const char *wav_data_chunk_id = "data";

typedef struct Vt_803C0628 {
    u8 pad0[0x18];
    void (*fn18)(struct AudioStreamGetOutputSamplesObject *, s32, s32, void *);
} Vt_803C0628;

typedef struct AudioStreamGetOutputSamplesObject {
    Vt_803C0628 *vt;
} AudioStreamGetOutputSamplesObject;

typedef struct Rec_803C0628 {
    s32 a;
    s32 b;
} Rec_803C0628;

typedef struct AudioStreamGetWriteWindowState {
    s32 f0;
    AdxbDecoder *decoder;
    s32 f8;
    AudioStreamGetOutputSamplesObject *objs[4];
    Rec_803C0628 recs[3];
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
} AudioStreamGetWriteWindowState;



struct Rec_803C0018 { u8 state; u8 pad[0x9B]; };


RecoveredGlobal_lbl_80570AC0 lbl_80570AC0;

extern "C" {
void adxb_exec_wav_pcm16(AdxbDecoder *adxb);
void adxb_exec_wav_split16(AdxbDecoder *adxb);
void adxb_exec_wav_pcm8(AdxbDecoder *adxb);

void decode_audio_stream_step(AudioStreamInputState *st);
u8 *AudioStreamInputState::get_offset_58() {
    return header;
}
s32 get_stream_loop_end_byte(AudioStreamInputState *st) {
    return st->decoder->get_loop_end_byte();
}
s32 AudioStreamInputState::get_loop_end_sample() {
    return decoder->get_loop_end_sample();
}
s32 AudioStreamInputState::get_loop_start_byte() {
    return decoder->get_loop_start_byte();
}
s32 AudioStreamInputState::get_loop_start_sample() {
    return decoder->get_loop_start_sample();
}
s32 get_stream_loop_type(AudioStreamInputState *st) {
    return st->decoder->get_loop_type();
}
s32 AudioStreamInputState::send_packet_by_id() {
    return decoder->get_total_samples();
}
s32 AudioStreamInputState::notify_field_4_alt() {
    return decoder->get_block_samples();
}
s32 AudioStreamInputState::send_packet_by_id_2() {
    return decoder->get_packet_flag_for_state();
}
s32 AudioStreamInputState::send_with_offset4() {
    return decoder->get_channels();
}
s32 AudioStreamInputState::notify_field_4() {
    return decoder->get_rate();
}
s32 audio_stream_get_format(AudioStreamInputState *st) {
    return st->decoder->get_format();
}
void AudioStreamInputState::set_notify_bytes(s32 bytes) {
    notify_bytes = bytes;
}
void AudioStreamInputState::set_notify_count(s32 samples) {
    notify_count = samples;
}
void AudioStreamInputState::set_notify_sample_count(s32 samples) {
    notify_samples = samples;
}
void audio_stream_set_notify_callback(AudioStreamInputState *st, void (*callback)(void *), void *context) {
    st->notify_callback = callback;
    st->notify_context = context;
}
void AudioStreamInputState::set_decoded_samples(s32 samples) {
    decoded_samples = samples;
}
s32 audio_stream_get_output_samples(AudioStreamInputState *st) {
    return st->output_samples;
}

struct AudioStreamGetOutputSamplesObject;

void sub_803C0018(void) {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        if ((s32)((Rec_803C0018 *)&lbl_80570AC0)[i].state == 1) {
            process_audio_stream_input((AudioStreamInputState *)(&((Rec_803C0018 *)&lbl_80570AC0)[i]));
        }
    }
}

inline void parse_audio_stream_input_header(AudioStreamInputState *st) {
    SjChunk b;
    SjChunk b2;
    AdxbDecoder *h;
    SjRingBuffer *s;
    s32 n;
    s = st->source;
    h = st->decoder;
    s->interface->get_chunk(s, 1, 0x1000, &b);
    if (b.size < 0x10) {
        s->interface->unget_chunk(s, 1, &b);
        return;
    }
    n = adxb_decode_header(h, b.data, b.size);
    if (n == 0 || n > b.size) {
        s->interface->unget_chunk(s, 1, &b);
        return;
    }
    st->header_size = n;
    if (h->get_format() == 4) {
        st->stop_when_drained = 1;
    }
    if (h->get_format() == 2) {
        memcpy(st->header, b.data, b.size < 0x40 ? b.size : 0x40);
    }
    if (h->get_format() == 10) {
        s->interface->unget_chunk(s, 1, &b);
    } else {
        TLobby__sub_803D3130(&b, n, &b, &b2);
        s->interface->put_chunk(s, 0, &b);
        s->interface->unget_chunk(s, 1, &b2);
    }
    st->state = 2;
}
void process_audio_stream_input(AudioStreamInputState *st) {
    if (st->state == 2) {
        decode_audio_stream_step(st);
    } else if (st->state == 1) {
        parse_audio_stream_input_header(st);
    }
}

inline void feed_audio_stream_decoder(AudioStreamInputState *st) {
    AdxbDecoder *h = st->decoder;
    SjRingBuffer *s = st->source;
    s32 need;
    if (st->stop_when_drained == 1 && s->interface->get_available(s, 1) == 0) {
        st->state = 3;
        return;
    }
    s->interface->get_chunk(s, 1, 0x7FFFFFFF, &st->src_chunk);
    // An ADX footer ends the stream before the next block is submitted.
    if (h->get_format() == 0 && st->src_chunk.size >= 2 && (u16)*(s16 *)st->src_chunk.data == 0x8001) {
        st->state = 3;
        s->interface->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    if (st->decoded_samples >= st->decoder->get_total_samples()) {
        st->state = 3;
        s->interface->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    need = st->decoder->get_block_samples();
    if (st->rings[0]->interface->get_available(st->rings[0], 0) / 2 < need) {
        s->interface->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    if (h->get_format() == 10) {
        s->interface->unget_chunk(s, 1, &st->src_chunk);
    }
    h->set_source(st->src_chunk.data, st->src_chunk.size);
    h->start();
}

inline void drain_audio_stream_decoder(AudioStreamInputState *st) {
    s32 n;
    AdxbDecoder *h = st->decoder;
    SjRingBuffer *s = st->source;
    SjChunk head;
    SjChunk tail;
    s32 bytes;
    s32 avail;
    s32 i;
    n = h->get_total_samples();
    bytes = h->get_decoded_bytes();
    avail = h->get_decoded_samples();
    n -= st->decoded_samples;
    n = avail < n ? avail : n;
    TLobby__sub_803D3130(&st->src_chunk, bytes, &head, &tail);
    s->interface->put_chunk(s, 0, &head);
    s->interface->unget_chunk(s, 1, &tail);
    for (i = 0; i < st->decoder->get_channels(); i++) {
        TLobby__sub_803D3130(&st->out_chunks[i], n * 2, &head, &tail);
        if (st->output_callback != NULL) {
            st->output_callback(st->output_context, i, head.data, head.size);
        }
        st->rings[i]->interface->put_chunk(st->rings[i], 1, &head);
        st->rings[i]->interface->unget_chunk(st->rings[i], 0, &tail);
    }
    st->output_samples += n;
    st->consumed_bytes += bytes;
    st->decoded_samples += n;
    st->notify_count += n;
    st->notify_bytes += bytes;
    if (st->notify_samples >= 0 && st->notify_count >= st->notify_samples) {
        if (st->notify_callback != NULL) {
            st->notify_callback(st->notify_context);
        }
    }
    h->reset();
}

inline void skip_audio_stream_decoder(AudioStreamInputState *st) {
    AdxbDecoder *h = st->decoder;
    s32 n = h->get_total_samples();
    s32 bytes = h->get_decoded_bytes();
    s32 avail = h->get_decoded_samples();
    n -= st->decoded_samples;
    n = avail < n ? avail : n;
    st->output_samples += n;
    st->consumed_bytes += bytes;
    st->decoded_samples += n;
}

void decode_audio_stream_step(AudioStreamInputState *st) {
    AdxbDecoder *h = st->decoder;
    if (h->get_state() == 0) {
        feed_audio_stream_decoder(st);
    }
    adxb_exec_handle(h);
    if (h->get_state() == 3) {
        drain_audio_stream_decoder(st);
    }
    // Format 10 also updates the counters outside the output-ring path.
    if (h->format == 10) {
        skip_audio_stream_decoder(st);
    }
}

s16 *audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3) {
    AudioStreamGetWriteWindowState *arg0 = (AudioStreamGetWriteWindowState *)arg0_;
    saddr h;
    s32 i;
    s32 t;
    s32 v;
    h = (saddr)arg0->objs[0];
    for (i = 0; i < arg0->decoder->get_channels(); i++) {
        arg0->objs[i]->vt->fn18(arg0->objs[i], 0, 0x4000, &arg0->recs[i]);
    }
    *arg1 = (arg0->recs[0].a - (saddr)sj_ring_buffer_get_buffer((SjRingBuffer*)h)) / 2;
    v = arg0->f38;
    t = arg0->recs[0].b / 2;
    if (t < v) {
        v = t;
    }
    *arg2 = v;
    if (arg0->f3C >= 0) {
        *arg3 = arg0->f3C - arg0->f40;
    } else {
        *arg3 = 0x1FFFFFFF;
    }
    return arg0->decoder->get_output_buffer();
}

void AudioStreamInputState::reset_flag() {
    decoder->stop();
    state = 0;
}
void audio_stream_start(AudioStreamInputState *st) {
    st->header_size = 0;
    st->output_samples = 0;
    st->consumed_bytes = 0;
    st->decoded_samples = 0;
    st->max_samples = 0x7FFFFFFF;
    st->notify_samples = -1;
    st->notify_count = 0;
    st->notify_bytes = 0;
    st->stop_when_drained = 0;
    st->state = 1;
}
void AudioStreamInputState::set_network_result(s32 result) {
    max_samples = result;
    decoder->set_max_samples(result);
}
void AudioStreamInputState::set_param_and_notify(SjRingBuffer *sj) {
    source = sj;
    decoder->invoke_notify_callback();
}

s32 audio_stream_get_state(AudioStreamInputState *st) {
    return st->state;
}

void AudioStreamInputState::reset_entry() {
    if (this != NULL) {
        if (decoder != NULL) {
            decoder->clear_record();
        }
        adx_lock();
        memset(this, 0, sizeof(AudioStreamInputState));
        adx_unlock();
    }
}
AudioStreamInputState *alloc_audio_stream_state(SjRingBuffer *source, s32 channels, SjRingBuffer **rings) {
    AudioStreamInputState *st;
    s32 i;
    u8 *buffer;
    SjRingBuffer *ring = rings[0];
    s32 size;
    for (i = 0; i < 0x10; i++) {
        if (((AudioStreamInputState *)&lbl_80570AC0)[i].in_use == 0) {
            break;
        }
    }
    if (i == 0x10) {
        return NULL;
    }
    st = &((AudioStreamInputState *)&lbl_80570AC0)[i];
    buffer = sj_ring_buffer_get_buffer(ring);
    size = sj_ring_buffer_get_buffer_size(ring) / 2;
    st->decoder = AdxbDecoder::alloc_record(channels, (saddr)buffer, size, size + sj_ring_buffer_get_extra_buffer_size(ring) / 2);
    if (st->decoder == NULL) {
        return NULL;
    }
    adxb_set_read_callback(st->decoder, audio_stream_get_write_window, st);
    st->source = source;
    st->channels = channels;
    for (i = 0; i < channels; i++) {
        st->rings[i] = rings[i];
    }
    st->state = 0;
    st->header_size = 0;
    st->output_samples = 0;
    st->consumed_bytes = 0;
    st->decoded_samples = 0;
    st->max_samples = 0x7FFFFFFF;
    st->notify_samples = -1;
    st->notify_count = 0;
    st->notify_bytes = 0;
    st->stop_when_drained = 0;
    st->notify_callback = 0;
    st->notify_context = 0;
    st->output_callback = 0;
    st->output_context = 0;
    st->in_use = 1;
    return st;
}

void adxb_finish(void) {
    memset((void *) (&lbl_80570AC0.value), 0, 0x9C0);
}
void adxb_init(void) {
    AdxbDecoder::clear_pool();
    memset(&lbl_80570AC0.value, 0, 0x9C0);
}
void adxb_exec_one_wav(AdxbDecoder *adxb) {
    s16 encoding;
    encoding = adxb->encoding;
    if (encoding == 2) {
        adxb_exec_wav_split16(adxb);
        return;
    }
    if (encoding == 1) {
        adxb_exec_wav_pcm8(adxb);
        return;
    }
    if (encoding == 0) {
        adxb_exec_wav_pcm16(adxb);
    }
}
s32 adxb_is_wav_header(const u8 *hdr) {
    if (memcmp(hdr, "RIFF", 4) == 0 && memcmp(hdr + 8, "WAVE", 4) == 0) {
        return 1;
    }
    return 0;
}

// The 4-bit WAVE encoding, decoded as 16-bit samples whose low and high bytes are stored apart.
void adxb_exec_wav_split16(AdxbDecoder *adxb) {
    u8 *src = adxb->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (adxb->state == 1 && adxb->channel->get_state() == 0) {
        adxb->read(adxb->readArg, &adxb->pos, &adxb->avail, &adxb->x78);
        n = adxb->bufLen - adxb->pos;
        if (n > adxb->avail) {
            n = adxb->avail;
        }
        if (n > adxb->maxLen) {
            n = adxb->maxLen;
        }
        l = adxb->buf + adxb->pos;
        if (adxb->channels == 2) {
            r = adxb->buf + (adxb->rOff + adxb->pos);
            for (i = 0; i < n; i++) {
                l[i] = src[i * 4] | (src[i * 4 + 2] << 8);
                r[i] = src[i * 4 + 1] | (src[i * 4 + 3] << 8);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = src[i * 2] | (src[i * 2 + 1] << 8);
            }
        }
        adxb->n = n;
        adxb->bytes = adxb->channels * (n * 2);
        adxb->state = 2;
    }
    if (adxb->state == 2) {
        adxb->done(adxb->doneArg, adxb->bytes, adxb->n);
        adxb->state = 3;
    }
}

void adxb_exec_wav_pcm8(AdxbDecoder *adxb) {
    u8 *src = adxb->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (adxb->state == 1 && adxb->channel->get_state() == 0) {
        adxb->read(adxb->readArg, &adxb->pos, &adxb->avail, &adxb->x78);
        n = adxb->bufLen - adxb->pos;
        if (n > adxb->avail) {
            n = adxb->avail;
        }
        if (n > adxb->maxLen) {
            n = adxb->maxLen;
        }
        l = adxb->buf + adxb->pos;
        if (adxb->channels == 2) {
            r = adxb->buf + (adxb->rOff + adxb->pos);
            for (i = 0; i < n; i++) {
                l[i] = (u8)(src[i * 2] - 0x80) << 8;
                r[i] = (u8)(src[i * 2 + 1] - 0x80) << 8;
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (u8)(src[i] - 0x80) << 8;
            }
        }
        adxb->n = n;
        adxb->bytes = n * adxb->channels;
        adxb->state = 2;
    }
    if (adxb->state == 2) {
        adxb->done(adxb->doneArg, adxb->bytes, adxb->n);
        adxb->state = 3;
    }
}

void adxb_exec_wav_pcm16(AdxbDecoder *adxb) {
    u16 *src = (u16 *)adxb->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (adxb->state == 1 && adxb->channel->get_state() == 0) {
        adxb->read(adxb->readArg, &adxb->pos, &adxb->avail, &adxb->x78);
        n = adxb->bufLen - adxb->pos;
        if (n > adxb->avail) {
            n = adxb->avail;
        }
        if (n > adxb->maxLen) {
            n = adxb->maxLen;
        }
        l = adxb->buf + adxb->pos;
        if (adxb->channels == 2) {
            r = adxb->buf + (adxb->rOff + adxb->pos);
            for (i = 0; i < n; i++) {
                l[i] = (((src[i * 2]) & 0xFF) << 8) | (((src[i * 2]) >> 8) & 0xFF);
                r[i] = (((src[i * 2 + 1]) & 0xFF) << 8) | (((src[i * 2 + 1]) >> 8) & 0xFF);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (((src[i]) & 0xFF) << 8) | (((src[i]) >> 8) & 0xFF);
            }
        }
        adxb->n = n;
        adxb->bytes = adxb->channels * (n * 2);
        adxb->state = 2;
    }
    if (adxb->state == 2) {
        adxb->done(adxb->doneArg, adxb->bytes, adxb->n);
        adxb->state = 3;
    }
}

s32 adxb_decode_header_wav(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    s16 n;
    adxb->m_02 = 1;
    if (TLobby__sub_803C1780(hdr, size, &n, &adxb->encoding_type, &adxb->bits, &adxb->block_bytes,
                             &adxb->channels, &adxb->rate, &adxb->samples, &adxb->block_samples, &adxb->encoding) < 0) {
        return 0;
    }
    adxb->cutoff = 0;
    adxb->m_4A = 0;
    adxb->m_48 = 0;
    adxb->loop_count = 0;
    adxb->loop_type = 0;
    adxb->loop_end_byte = 0;
    adxb->loop_end_sample = 0;
    adxb->loop_start_byte = 0;
    adxb->loop_start_sample = 0;
    adxb->loop_enabled = 0;
    adxb->stream_channels = adxb->channels;
    adxb->stream_block_bytes = adxb->block_bytes;
    adxb->stream_block_samples = adxb->block_samples;
    adxb->buf = adxb->output_buffer;
    adxb->bufLen = adxb->wrap_len;
    adxb->rOff = adxb->wrap_offset;
    adxb->m_7C = adxb->m_48;
    adxb->m_7E = adxb->m_4A;
    adxb->m_80 = adxb->m_4C;
    adxb->write_pos = 0;
    adxb->total_written = 0;
    adxb->format = 1;
    memset(adxb->m_4C, 0, 4);
    return n;
}

}

typedef void (*RecoveredCallback_1268626c296b)(void *);

s32 (*lbl_805D7510)();
RecoveredCallback_1268626c296b lbl_805D7514;
extern s32 (*lbl_805D7510)();


// "fmt " chunk of a WAVE file.
struct WavFmtChunk {
    char id[4];
    u32 size;
    u16 format;
    u16 channels;
    u32 sample_rate;
    u32 byte_rate;
    u16 block_align;
    u16 bits;
};

struct WavDataChunk {
    char id[4];
    u32 size;
};

LAYOUT_ASSERT(WavFmtChunkSize, sizeof(WavFmtChunk) == 0x18);
LAYOUT_ASSERT(WavFmtChannelOffset, offsetof(WavFmtChunk, channels) == 0xA);
LAYOUT_ASSERT(WavFmtBlockAlignOffset, offsetof(WavFmtChunk, block_align) == 0x14);
LAYOUT_ASSERT(WavDataChunkSize, sizeof(WavDataChunk) == 8);

#define WAVE_SWAP16(value) ((((value) >> 8) & 0xFF) | (((value) << 8) & 0xFF00))
#define WAVE_SWAP32(value) ((((value) >> 24) & 0xFF) | (((value) >> 8) & 0xFF00) | \
                            (((value) << 8) & 0xFF0000) | (((value) << 24) & 0xFF000000))
#pragma push
#pragma opt_propagation off
s32 TLobby__sub_803C1780(u8 *buffer, s32 size, s16 *data_offset,
                        s8 *flags, s8 *bits_per_sample, s8 *block_align,
                        s8 *channels, s32 *sample_rate, s32 *sample_count,
                        s32 *codec, s16 *encoding) {
    s32 offset;
    WavFmtChunk *format;
    WavDataChunk *data;
    s32 data_size;
    s16 payload_offset;
    for (offset = 0; offset < size; ++offset) {
        if (memcmp((void *)(buffer + offset), wav_fmt_chunk_id, 4) == 0) {
            break;
        }
    }
    if (offset == size) {
        return -1;
    }
    if (offset % 4 != 0) {
        return -1;
    }
    format = reinterpret_cast<WavFmtChunk *>(offset + reinterpret_cast<uaddr>(buffer));
    if (static_cast<s16>(WAVE_SWAP16(format->format)) > 1) {
        return -1;
    }
    for (offset = 0; offset < size; ++offset) {
        if (memcmp((void *)(buffer + offset), wav_data_chunk_id, 4) == 0) {
            break;
        }
    }
    if (offset == size) {
        return -1;
    }
    data = reinterpret_cast<WavDataChunk *>(offset + reinterpret_cast<uaddr>(buffer));
    data_size = WAVE_SWAP32(static_cast<u32>(data->size));
    payload_offset = offset + 8;
    *data_offset = payload_offset;
    *flags = -1;
    *sample_rate = WAVE_SWAP32(format->sample_rate);
    *channels = WAVE_SWAP16(format->channels);
    *bits_per_sample = WAVE_SWAP16(format->bits);
    *block_align = WAVE_SWAP16(format->block_align);
    *sample_count = data_size / *block_align;
    *codec = 1;
    if (*bits_per_sample == 16) {
        *encoding = 0;
    } else if (*bits_per_sample == 8) {
        *encoding = 1;
    } else if (*bits_per_sample == 4) {
        *block_align = *channels * 2;
        *codec = 4;
        *sample_count = (data_size / 2) / *channels;
        *bits_per_sample = 16;
        *encoding = 2;
    }
    if (*bits_per_sample == 0) {
        return -1;
    }
    if (*block_align == 0) {
        return -1;
    }
    if (*channels <= 0 || *channels > 2) {
        return -1;
    }
    return *sample_rate == 0 ? -1 : 0;
}
#pragma pop
#undef WAVE_SWAP16
#undef WAVE_SWAP32

void adxb_exec_one_ahx(AdxbDecoder *adxb) {
    lbl_805D7510();
}
void AdxbDecoder::set_max_samples(s32 limit) {
    max_samples = limit;
    max_sample_units = (u32)(limit / 96);
}
void AdxbDecoder::invoke_notify_callback() {
    if (ahx_handle != NULL) {
        lbl_805D7514(ahx_handle);
    }
}

// CRI adx_baif.c: the AIFF decoder (ADXB_ExecOneAiff and its 8/16-bit steps, header check and parse).

extern "C" {
void adxb_decode_aiff_pcm8(AdxbDecoder *o);
void adxb_decode_aiff_pcm16(AdxbDecoder *o);
}

extern "C" {

void adxb_exec_one_aiff(AdxbDecoder *adxb) {
    if (adxb->encoding == 1) {
        adxb_decode_aiff_pcm8(adxb);
        return;
    }
    adxb_decode_aiff_pcm16(adxb);
}

void adxb_decode_aiff_pcm8(AdxbDecoder *o) {
    u8 *src = o->src;
    if (o->state == 1 && o->channel->get_state() == 0) {
        s16 *l;
        s16 *r;
        s32 i;
        s32 n;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        l = o->buf + o->pos;
        if (o->channels == 2) {
            r = o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                l[i] = (src[i * 2] << 8) & 0xFF00;
                r[i] = (src[i * 2 + 1] << 8) & 0xFF00;
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (src[i] << 8) & 0xFF00;
            }
        }
        o->n = n;
        o->bytes = n * o->channels;
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

void adxb_decode_aiff_pcm16(AdxbDecoder *o) {
    u16 *src = (u16 *)o->src;
    u16 *l;
    s32 v;
    u16 *r;
    s32 i;
    s32 n;
    if (o->state == 1 && o->channel->get_state() == 0) {
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        l = (u16 *)o->buf + o->pos;
        if (o->channels == 2) {
            r = (u16 *)o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                v = src[i * 2];
                l[i] = (src[i * 2] >> 8) | (v << 8);
                r[i] = (src[i * 2 + 1] >> 8) | (src[i * 2 + 1] << 8);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (src[i] >> 8) | (src[i] << 8);
            }
        }
        o->n = n;
        o->bytes = o->channels * (n * 2);
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

s32 adxb_decode_header_aiff(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    s32 frames;
    s32 bits;
    s32 channels;
    s32 rate;
    s16 len;
    s32 st;
    u8 *e;
    adxb->m_02 = 1;
    if (size < 0x1000) {
        len = 0;
        st = -1;
    } else if ((e = adx_aiff_parse_header(hdr, &rate, &channels, &bits, &frames)) == NULL) {
        st = -1;
    } else if ((len = e - hdr) <= 0) {
        st = -1;
    } else {
        adxb->rate = rate;
        adxb->channels = channels;
        adxb->bits = bits;
        adxb->samples = frames;
        adxb->encoding_type = -1;
        adxb->block_bytes = (adxb->channels * adxb->bits) / 8;
        adxb->block_samples = 1;
        st = 0;
    }
    if (st < 0) {
        return 0;
    }
    adxb->cutoff = 0;
    adxb->m_4A = 0;
    adxb->m_48 = 0;
    adxb->loop_count = 0;
    adxb->loop_type = 0;
    adxb->loop_end_byte = 0;
    adxb->loop_end_sample = 0;
    adxb->loop_start_byte = 0;
    adxb->loop_start_sample = 0;
    adxb->loop_enabled = 0;
    adxb->stream_channels = adxb->channels;
    adxb->stream_block_bytes = adxb->block_bytes;
    adxb->stream_block_samples = adxb->block_samples;
    adxb->buf = adxb->output_buffer;
    adxb->bufLen = adxb->wrap_len;
    adxb->rOff = adxb->wrap_offset;
    adxb->m_7C = adxb->m_48;
    adxb->m_7E = adxb->m_4A;
    adxb->m_80 = adxb->m_4C;
    adxb->write_pos = 0;
    adxb->total_written = 0;
    adxb->format = 3;
    if (adxb->bits == 8) {
        adxb->encoding = 1;
    } else {
        adxb->encoding = 0;
    }
    memset(adxb->m_4C, 0, 4);
    return len;
}

s32 adxb_is_aiff_header(const u8 *hdr) {
    const AiffFormHeader *h = (const AiffFormHeader *)hdr;
    if (memcmp(h->id, "FORM", 4) == 0 && memcmp(h->type, "AIFF", 4) == 0) {
        return 1;
    }
    return 0;
}

// Little-endian reads of big-endian header fields, swapped in place afterwards.
#define READ_LE32(b) ((b)[0] | ((b)[1] << 8) | ((b)[2] << 16) | ((b)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))
#define READ_LE16(b) ((u16)(b)[0] | ((u16)(b)[1] << 8))
#define SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

// Walks the chunks of an AIFF ("FORM"/"AIFF") header, whose fields are big-endian: COMM gives
// the format, SSND the start of the sample data, which is returned (NULL if not an AIFF).
u8 *adx_aiff_parse_header(u8 *hdr, s32 *rate, s32 *channels, s32 *bits, s32 *frames) {
    u8 *p;
    u8 *end;
    u8 *data;
    s32 id;
    s32 size;
    s32 type;
    s32 have_comm;
    s32 have_ssnd;
    u16 exponent;
    u16 mantissa;
    u32 offset;

    p = hdr + 12;
    have_comm = 0;
    have_ssnd = 0;
    data = NULL;
    id = READ_LE32(hdr);
    size = READ_LE32(hdr + 4);
    size = SWAP32(size);
    type = READ_LE32(hdr + 8);
    if (id != 0x4D524F46) {
        return NULL;
    }
    if (type != 0x46464941) {
        return NULL;
    }
    end = p + size - 4;
    while (p < end) {
        id = READ_LE32(p);
        size = READ_LE32(p + 4);
        size = SWAP32(size);
        p += 8;
        switch (id) {
        case 0x4D4D4F43:
            if (have_comm != 0) {
                break;
            }
            if (size < 18) {
                return NULL;
            }
            have_comm = 1;
            *channels = READ_LE16(p);
            *channels = SWAP16(*channels);
            *frames = READ_LE32(p + 2);
            *frames = SWAP32(*frames);
            *bits = READ_LE16(p + 6);
            *bits = SWAP16(*bits);
            exponent = READ_LE16(p + 8);
            exponent = SWAP16(exponent);
            mantissa = READ_LE16(p + 10);
            mantissa = SWAP16(mantissa);
            p += 18;
            *rate = mantissa >> (0x400E - exponent);
            if (have_ssnd != 0) {
                return data;
            }
            break;
        case 0x444E5353:
            if (have_ssnd != 0) {
                break;
            }
            have_ssnd = 1;
            offset = READ_LE32(p);
            offset = SWAP32(offset);
            p += 4;
            data = p + offset;
            if (have_comm != 0) {
                return data;
            }
            break;
        default:
            p += (size + 1) & ~1;
            break;
        }
    }
    return data;
}

}
