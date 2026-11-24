#include "types.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AudioStreamInput.h"
#include <stddef.h>
#include "pso/unk/TLobby_803BFE50.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803C1780.h"
#include "pso/unk/text_803D2F1C.h"
#include <string.h>


// The RIFF chunk ids TLobby__sub_803C1780 scans a WAVE header for.
const char *wav_fmt_chunk_id = "fmt ";
const char *wav_data_chunk_id = "data";

struct Obj_803C07E8 { u8 a; s8 b; };

typedef struct Vt_803C0628 {
    u8 pad0[0x18];
    void (*fn18)(struct Obj_803C0628 *, s32, s32, void *);
} Vt_803C0628;

typedef struct Obj_803C0628 {
    Vt_803C0628 *vt;
} Obj_803C0628;

typedef struct Rec_803C0628 {
    s32 a;
    s32 b;
} Rec_803C0628;

typedef struct S_803C0628 {
    s32 f0;
    TLobby *decoder;
    s32 f8;
    Obj_803C0628 *objs[4];
    Rec_803C0628 recs[3];
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
} S_803C0628;

struct Snd_803C0F98 {
    u8 pad0[4];
    s32 state;
    saddr lobby;
    u8 pad0C[2];
    s8 channels;
    u8 pad0F[0x50 - 0x0F];
    u8 *src;
    s32 max;
    u8 pad58[0x64 - 0x58];
    s16 *dst;
    s32 size;
    s32 rofs;
    s32 pos;
    s32 avail;
    s32 unk78;
    u8 pad7C[0x88 - 0x7C];
    void (*get)(s32, s32 *, s32 *, s32 *);
    s32 getCtx;
    void (*put)(s32, s32, s32);
    s32 putCtx;
    u8 pad98[0xA0 - 0x98];
    s32 count;
    s32 bytes;
};

struct Snd_803C0BE8 {
    u8 pad0[4];
    s32 state;
    saddr lobby;
    u8 pad0C[2];
    s8 channels;
    u8 pad0F[0x50 - 0x0F];
    u8 *src;
    s32 max;
    u8 pad58[0x64 - 0x58];
    s16 *dst;
    s32 size;
    s32 rofs;
    s32 pos;
    s32 avail;
    s32 unk78;
    u8 pad7C[0x88 - 0x7C];
    void (*get)(s32, s32 *, s32 *, s32 *);
    s32 getCtx;
    void (*put)(s32, s32, s32);
    s32 putCtx;
    u8 pad98[0xA0 - 0x98];
    s32 count;
    s32 bytes;
};

struct Rec_803C0018 { u8 state; u8 pad[0x9B]; };

// Decoder handle fields read directly (TLobby::get_field_a8 returns the same field).
struct AudioStreamSource;

// Same slot layout as SjRingBufferInterface (CRI SJ stream interface).
struct AudioStreamSourceVtable {
    void *pad[6];
    void (*get_chunk)(AudioStreamSource *, s32, s32, SjChunk *);
    void (*unget_chunk)(AudioStreamSource *, s32, SjChunk *);
    void (*put_chunk)(AudioStreamSource *, s32, SjChunk *);
    s32 (*get_available)(AudioStreamSource *, s32);
};

struct AudioStreamSource { AudioStreamSourceVtable *vt; };

extern "C" {
void TLobby__sub_803BFE58(u8 *arg0);
void TLobby__sub_803BFEE8(u8 *arg0);
s32 TLobby__sub_803C3ABC(u8 *adxb_decoder);
s32 TLobby__sub_803C3AC4(u8 *adxb_decoder);
void TLobby__sub_803C3A04(u8 *arg0);
void TLobby__sub_803C3984(u8 *arg0);
s32 TLobby__sub_803C3B44(u8 *adxb_decoder);
void audio_stream_get_format(u8 *arg0);
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, s32 arg2);
s32 audio_stream_get_output_samples(u8 *lobby);
void TLobby__sub_803C39CC(u8 *arg0);
void audio_stream_start(u8 *lobby);
}

RecoveredGlobal_lbl_80570AC0 lbl_80570AC0;

extern "C" {
void TLobby__sub_803C406C(void);
void TLobby__sub_803C133C(Snd_803C0BE8 *arg0);
void decode_adxb_pcm_stream(u8 *lobby);
s32 audio_stream_get_state(Obj_803C07E8 *self);

void audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
void sub_803C0BE8(Snd_803C0BE8 *arg0);
void sub_803C0018(void);
void decode_audio_stream_step(AudioStreamInputState *st);
s32 TLobby__sub_803C3B68(saddr decoder, u16 *hdr, saddr size);
void process_audio_stream_input(AudioStreamInputState *st);

void TLobby__sub_803C3B5C(TLobby *decoder, void (*callback)(void *, s32 *, s32 *, s32 *), void *context);
AudioStreamInputState *alloc_audio_stream_state(AudioStreamSource *source, s32 channels, SjRingBuffer **rings);
s32 TLobby::get_offset_58() {
    s32 arg0 = (saddr)this;
    return arg0 + 0x58;
}
void TLobby__sub_803BFE58(u8 *arg0) {
    ((TLobby *)(*(saddr *)((s8 *)arg0 + 4)))->get_field_34();
}
s32 AudioStreamInputState::get_loop_end_sample() {
    return decoder->get_field30();
}
s32 AudioStreamInputState::get_loop_start_byte() {
    AdxbDecoder *adx = reinterpret_cast<AdxbDecoder *>(decoder);
    return adx->get_loop_start_byte();
}
s32 AudioStreamInputState::get_loop_start_sample() {
    return decoder->get_field_28();
}
void TLobby__sub_803BFEE8(u8 *arg0) {
    ((TLobby *)(*(saddr *)((s8 *)arg0 + 4)))->get_slot();
}
s32 TLobby::send_packet_by_id() {
    u8 *arg0 = (u8 *)this;
    return TLobby__sub_803C3ABC((u8 *)(*(saddr *)((s8 *)arg0 + 4)));
}
s32 TLobby::notify_field_4_alt() {
    u8 *arg0 = (u8 *)this;
    return TLobby__sub_803C3AC4((u8 *)(*(saddr *)((s8 *)arg0 + 4)));
}
s32 TLobby::send_packet_by_id_2() {
    u8 *arg0 = (u8 *)this;
    return ((TLobby *)(*(saddr *)((s8 *)arg0 + 4)))->get_packet_flag_for_state();
}
s32 TLobby::send_with_offset4() {
    AudioStreamInputState *stream = (AudioStreamInputState *)this;
    return TLobby__sub_803C3B38((const AdxbDecoder *)stream->decoder);
}
s32 TLobby::notify_field_4() {
    u8 *arg0 = (u8 *)this;
    return TLobby__sub_803C3B44((u8 *)(*(saddr *)((s8 *)arg0 + 4)));
}
void audio_stream_get_format(u8 *arg0) {
    AudioStreamInputState *stream = (AudioStreamInputState *)arg0;
    stream->decoder->get_field_a8();
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
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x48) = arg1;
    *(s32 *)((s8 *)arg0 + 0x4C) = arg2;
}
void AudioStreamInputState::set_decoded_samples(s32 samples) {
    decoded_samples = samples;
}
s32 audio_stream_get_output_samples(u8 *lobby) {
    return *(s32 *)((s8 *)lobby + 0x2C);
}

struct Obj_803C0628;

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
    TLobby *h;
    AudioStreamSource *s;
    s32 n;
    s = st->source;
    h = st->decoder;
    s->vt->get_chunk(s, 1, 0x1000, &b);
    if (b.size < 0x10) {
        s->vt->unget_chunk(s, 1, &b);
        return;
    }
    n = TLobby__sub_803C3B68((saddr)h, (u16 *)b.data, b.size);
    if (n == 0 || n > b.size) {
        s->vt->unget_chunk(s, 1, &b);
        return;
    }
    st->header_size = n;
    if (h->get_field_a8() == 4) {
        st->stop_when_drained = 1;
    }
    if (h->get_field_a8() == 2) {
        memcpy(st->header, b.data, b.size < 0x40 ? b.size : 0x40);
    }
    if (h->get_field_a8() == 10) {
        s->vt->unget_chunk(s, 1, &b);
    } else {
        TLobby__sub_803D3130(&b, n, &b, &b2);
        s->vt->put_chunk(s, 0, &b);
        s->vt->unget_chunk(s, 1, &b2);
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
    TLobby *h = st->decoder;
    AudioStreamSource *s = st->source;
    s32 need;
    if (st->stop_when_drained == 1 && s->vt->get_available(s, 1) == 0) {
        st->state = 3;
        return;
    }
    s->vt->get_chunk(s, 1, 0x7FFFFFFF, &st->src_chunk);
    // An ADX footer ends the stream before the next block is submitted.
    if (h->get_field_a8() == 0 && st->src_chunk.size >= 2 && (u16)*(s16 *)st->src_chunk.data == 0x8001) {
        st->state = 3;
        s->vt->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    if (st->decoded_samples >= TLobby__sub_803C3ABC((u8 *)st->decoder)) {
        st->state = 3;
        s->vt->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    need = TLobby__sub_803C3AC4((u8 *)st->decoder);
    if (st->rings[0]->interface->get_available(st->rings[0], 0) / 2 < need) {
        s->vt->unget_chunk(s, 1, &st->src_chunk);
        return;
    }
    if (h->get_field_a8() == 10) {
        s->vt->unget_chunk(s, 1, &st->src_chunk);
    }
    h->init_scroll((saddr)st->src_chunk.data, st->src_chunk.size);
    TLobby__sub_803C3A04((u8 *)h);
}

inline void drain_audio_stream_decoder(AudioStreamInputState *st) {
    s32 n;
    TLobby *h = st->decoder;
    AudioStreamSource *s = st->source;
    SjChunk head;
    SjChunk tail;
    s32 bytes;
    s32 avail;
    s32 i;
    n = TLobby__sub_803C3ABC((u8 *)h);
    bytes = h->get_field_0xa4();
    avail = h->get_field_a0();
    n -= st->decoded_samples;
    n = avail < n ? avail : n;
    TLobby__sub_803D3130(&st->src_chunk, bytes, &head, &tail);
    s->vt->put_chunk(s, 0, &head);
    s->vt->unget_chunk(s, 1, &tail);
    for (i = 0; i < TLobby__sub_803C3B38((const AdxbDecoder *)st->decoder); i++) {
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
    TLobby__sub_803C3984((u8 *)h);
}

inline void skip_audio_stream_decoder(AudioStreamInputState *st) {
    TLobby *h = st->decoder;
    s32 n = TLobby__sub_803C3ABC((u8 *)h);
    s32 bytes = h->get_field_0xa4();
    s32 avail = h->get_field_a0();
    n -= st->decoded_samples;
    n = avail < n ? avail : n;
    st->output_samples += n;
    st->consumed_bytes += bytes;
    st->decoded_samples += n;
}

void decode_audio_stream_step(AudioStreamInputState *st) {
    TLobby *h = st->decoder;
    if (h->get_entry_id() == 0) {
        feed_audio_stream_decoder(st);
    }
    AdxbDecoder *decoder = reinterpret_cast<AdxbDecoder *>(h);
    TLobby__sub_803C34F4(decoder);
    if (h->get_entry_id() == 3) {
        drain_audio_stream_decoder(st);
    }
    // Format 10 also updates the counters outside the output-ring path.
    if (decoder->m_A8 == 10) {
        skip_audio_stream_decoder(st);
    }
}

void audio_stream_get_write_window(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3) {
    S_803C0628 *arg0 = (S_803C0628 *)arg0_;
    saddr h;
    s32 i;
    s32 t;
    s32 v;
    h = (saddr)arg0->objs[0];
    for (i = 0; i < TLobby__sub_803C3B38((const AdxbDecoder *)arg0->decoder); i++) {
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
    arg0->decoder->get_field_0x3c();
}

void TLobby::reset_flag() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C39CC((u8 *)(*(saddr *)((s8 *)arg0 + 4)));
    *(s8 *)((s8 *)arg0 + 1) = 0;
}
void audio_stream_start(u8 *lobby) {
    *(s32 *)((s8 *)lobby + 0x98) = 0;
    *(s32 *)((s8 *)lobby + 0x2C) = 0;
    *(s32 *)((s8 *)lobby + 0x30) = 0;
    *(s32 *)((s8 *)lobby + 0x34) = 0;
    *(s32 *)((s8 *)lobby + 0x38) = 0x7FFFFFFF;
    *(s32 *)((s8 *)lobby + 0x3C) = -1;
    *(s32 *)((s8 *)lobby + 0x40) = 0;
    *(s32 *)((s8 *)lobby + 0x44) = 0;
    *(s8 *)((s8 *)lobby + 3) = 0;
    *(s8 *)((s8 *)lobby + 1) = 1;
}
void TLobby::set_network_result(s32 result) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x38) = result;
    TLobby__sub_803C1A00((u8 *)(*(saddr *)((s8 *)arg0 + 4)), result);
}
void TLobby::set_param_and_notify(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 8) = arg1;
    ((TLobby *)(*(saddr *)((s8 *)arg0 + 4)))->invoke_notify_callback();
}

s32 audio_stream_get_state(Obj_803C07E8 *self) {
    return self->b;
}

void TLobby::reset_entry() {
    u8 *arg0 = (u8 *)this;
    u8 *lobby;
    if (arg0 != NULL) {
        lobby = (u8 *)(*(u8 **)((s8 *)arg0 + 4));
        if (lobby != NULL) {
            ((TLobby *)lobby)->clear_record();
        }
        TLobby::init_once();
        memset(arg0, 0, 0x9C);
        TLobby::release_ref();
    }
}
AudioStreamInputState *alloc_audio_stream_state(AudioStreamSource *source, s32 channels, SjRingBuffer **rings) {
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
    st->decoder = (TLobby *)TLobby::alloc_record(channels, (saddr)buffer, size, size + sj_ring_buffer_get_extra_buffer_size(ring) / 2);
    if (st->decoder == NULL) {
        return NULL;
    }
    TLobby__sub_803C3B5C(st->decoder, audio_stream_get_write_window, st);
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

void TLobby::clear_session_buffer() {
    memset((void *) (&lbl_80570AC0.value), 0, 0x9C0);
}
void TLobby::reset_sound_buffers() {
    TLobby__sub_803C406C();
    memset(&lbl_80570AC0.value, 0, 0x9C0);
}
void decode_adxb_pcm_stream(u8 *lobby) {
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)lobby + 0xAA);
    if (temp_r0 == 2) {
        sub_803C0BE8((Snd_803C0BE8 *)(lobby));
        return;
    }
    if (temp_r0 == 1) {
        ((TLobby *)lobby)->convert_pcm_u8_to_s16();
        return;
    }
    if (temp_r0 == 0) {
        TLobby__sub_803C133C((Snd_803C0BE8 *)(lobby));
    }
}
s32 TLobby::is_riff_wave() {
    u8 *arg0 = (u8 *)this;
    if (memcmp(arg0, "RIFF", 4) == 0 && memcmp((u8 *)&this->m_prev, "WAVE", 4) == 0) {
        return 1;
    }
    return 0;
}

void sub_803C0BE8(Snd_803C0BE8 *arg0) {
    u8 *src = arg0->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (arg0->state == 1 && ((TLobby *)(arg0->lobby))->get_client_count() == 0) {
        arg0->get(arg0->getCtx, &arg0->pos, &arg0->avail, &arg0->unk78);
        n = arg0->size - arg0->pos;
        if (n > arg0->avail) {
            n = arg0->avail;
        }
        if (n > arg0->max) {
            n = arg0->max;
        }
        l = arg0->dst + arg0->pos;
        if (arg0->channels == 2) {
            r = arg0->dst + (arg0->rofs + arg0->pos);
            for (i = 0; i < n; i++) {
                l[i] = src[i * 4] | (src[i * 4 + 2] << 8);
                r[i] = src[i * 4 + 1] | (src[i * 4 + 3] << 8);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = src[i * 2] | (src[i * 2 + 1] << 8);
            }
        }
        arg0->count = n;
        arg0->bytes = arg0->channels * (n * 2);
        arg0->state = 2;
    }
    if (arg0->state == 2) {
        arg0->put(arg0->putCtx, arg0->bytes, arg0->count);
        arg0->state = 3;
    }
}

void TLobby::convert_pcm_u8_to_s16() {
    Snd_803C0F98 *arg0 = (Snd_803C0F98 *)this;
    u8 *src = arg0->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (arg0->state == 1 && ((TLobby *)(arg0->lobby))->get_client_count() == 0) {
        arg0->get(arg0->getCtx, &arg0->pos, &arg0->avail, &arg0->unk78);
        n = arg0->size - arg0->pos;
        if (n > arg0->avail) {
            n = arg0->avail;
        }
        if (n > arg0->max) {
            n = arg0->max;
        }
        l = arg0->dst + arg0->pos;
        if (arg0->channels == 2) {
            r = arg0->dst + (arg0->rofs + arg0->pos);
            for (i = 0; i < n; i++) {
                l[i] = (u8)(src[i * 2] - 0x80) << 8;
                r[i] = (u8)(src[i * 2 + 1] - 0x80) << 8;
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (u8)(src[i] - 0x80) << 8;
            }
        }
        arg0->count = n;
        arg0->bytes = n * arg0->channels;
        arg0->state = 2;
    }
    if (arg0->state == 2) {
        arg0->put(arg0->putCtx, arg0->bytes, arg0->count);
        arg0->state = 3;
    }
}

void TLobby__sub_803C133C(Snd_803C0BE8 *arg0) {
    u16 *src = (u16 *)arg0->src;
    s16 *l;
    s16 *r;
    s32 i;
    s32 n;
    if (arg0->state == 1 && ((TLobby *)(arg0->lobby))->get_client_count() == 0) {
        arg0->get(arg0->getCtx, &arg0->pos, &arg0->avail, &arg0->unk78);
        n = arg0->size - arg0->pos;
        if (n > arg0->avail) {
            n = arg0->avail;
        }
        if (n > arg0->max) {
            n = arg0->max;
        }
        l = arg0->dst + arg0->pos;
        if (arg0->channels == 2) {
            r = arg0->dst + (arg0->rofs + arg0->pos);
            for (i = 0; i < n; i++) {
                l[i] = (((src[i * 2]) & 0xFF) << 8) | (((src[i * 2]) >> 8) & 0xFF);
                r[i] = (((src[i * 2 + 1]) & 0xFF) << 8) | (((src[i * 2 + 1]) >> 8) & 0xFF);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (((src[i]) & 0xFF) << 8) | (((src[i]) >> 8) & 0xFF);
            }
        }
        arg0->count = n;
        arg0->bytes = arg0->channels * (n * 2);
        arg0->state = 2;
    }
    if (arg0->state == 2) {
        arg0->put(arg0->putCtx, arg0->bytes, arg0->count);
        arg0->state = 3;
    }
}

s32 sub_803C1668(AdxbDecoder *h, u8 *buf, s32 len) {
    s16 n;
    h->m_02 = 1;
    if (TLobby__sub_803C1780(buf, len, &n, &h->m_0C, &h->bits, &h->block_bytes,
                             &h->channels, &h->rate, &h->samples, &h->block_samples, &h->m_AA) < 0) {
        return 0;
    }
    h->m_1C = 0;
    h->m_4A = 0;
    h->m_48 = 0;
    h->m_26 = 0;
    h->m_24 = 0;
    h->m_34 = 0;
    h->m_30 = 0;
    h->loop_start_byte = 0;
    h->m_28 = 0;
    h->m_20 = 0;
    h->stream_channels = h->channels;
    h->stream_block_bytes = h->block_bytes;
    h->stream_block_samples = h->block_samples;
    h->buf = h->m_3C;
    h->bufLen = h->wrap_len;
    h->rOff = h->wrap_offset;
    h->m_7C = h->m_48;
    h->m_7E = h->m_4A;
    h->m_80 = h->m_4C;
    h->m_9C = 0;
    h->m_98 = 0;
    h->m_A8 = 1;
    memset(h->m_4C, 0, 4);
    return n;
}

}

typedef void (*RecoveredCallback_1268626c296b)(void *);
struct Obj_803C1A24 { u8 pad[0xAC]; void *fac; };

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

void TLobby__sub_803C19D8(void) {
    lbl_805D7510();
}
void TLobby__sub_803C1A00(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0xB0) = arg1;
    *(u32 *)((s8 *)arg0 + 0xB4) = (u32) (arg1 / 96);
}
void TLobby::invoke_notify_callback() {
    Obj_803C1A24 *arg0 = (Obj_803C1A24 *)this;
    if (arg0->fac != 0) {
        lbl_805D7514(arg0->fac);
    }
}
