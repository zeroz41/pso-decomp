#include "types.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_803C0B08_lbl_80570AC0 {
    s32 value;
    u8 remaining[0x9BC];
};

struct RecoveredGlobal_803C0AD8_lbl_80570AC0 {
    s32 value;
    u8 remaining[0x9BC];
};

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
    s32 f4;
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
    s32 lobby;
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
    s32 lobby;
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
struct AudioStreamDecoder { u8 pad_0[0xA8]; s16 format; };

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

// Names inferred from the decode step (TLobby__sub_803C0238) and the setup in TLobby__sub_803C0848.
struct AudioStreamInputState {
    s8 in_use;
    s8 state;
    u8 channels;
    char stop_when_drained;
    TLobby *decoder;
    AudioStreamSource *source;
    SjRingBuffer *rings[2];
    SjChunk src_chunk;
    SjChunk out_chunks[2];
    s32 output_samples;
    s32 consumed_bytes;
    s32 decoded_samples;
    s32 max_samples;
    s32 notify_samples;
    s32 notify_count;
    s32 notify_bytes;
    void (*notify_callback)(void *);
    void *notify_context;
    void (*output_callback)(void *, s32, u8 *, s32);
    void *output_context;
    u8 header[0x40];
    s32 header_size;
};

extern "C" {
void TLobby__sub_803BFE58(u8 *arg0);
void TLobby__sub_803BFEE8(u8 *arg0);
s32 TLobby__sub_803C3ABC(u8 *arg0);
s32 TLobby__sub_803C3AC4(u8 *arg0);
void TLobby__sub_803C3A04(u8 *arg0);
void TLobby__sub_803C3984(u8 *arg0);
void TLobby__sub_803C34F4(TLobby *decoder);
s32 TLobby__sub_803C3B38(int);
s32 TLobby__sub_803C3B44(u8 *arg0);
s32 get_field_a8__6TLobbyFv(int);
void TLobby__sub_803BFFC0(u8 *arg0);
void TLobby__sub_803BFFFC(u8 *arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_803C0010(u8 *arg0);
void TLobby__sub_803C39CC(u8 *arg0);
void TLobby__sub_803C0758(u8 *arg0);
s32 TLobby__sub_803C1A00(int);
s32 memset(void *, int, int);
RecoveredGlobal_803C0B08_lbl_80570AC0 lbl_80570AC0;
void TLobby__sub_803C406C(void);
void TLobby__sub_803C133C(Snd_803C0BE8 *arg0);
void TLobby__sub_803C0B3C(u8 *arg0);
s32 TLobby__sub_803C07E8(Obj_803C07E8 *self);
s32 memcmp(void *, void *, int);
extern s32 lbl_805E0CB0;
extern s32 lbl_805E0CB8;

void TLobby__sub_803C0628(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3);
void EXIGetID(Snd_803C0BE8 *arg0);
void GXFlush(void);
void TLobby__sub_803C0238(AudioStreamInputState *st);
s32 TLobby__sub_803C3B68(TLobby *decoder, u16 *hdr, s32 size);
void TLobby__sub_803D3130(SjChunk *chunk, s32 size, SjChunk *head, SjChunk *tail);
void *memcpy(void *, const void *, u32);
void process_audio_stream_input(AudioStreamInputState *arg0);
TLobby *alloc_record__6TLobbyFiiii(s32 channels, u8 *buffer, s32 size, s32 total);
void TLobby__sub_803C3B5C(TLobby *decoder, void (*callback)(void *, s32 *, s32 *, s32 *), void *context);
AudioStreamInputState *TLobby__sub_803C0848(AudioStreamSource *source, s32 channels, SjRingBuffer **rings);
s32 TLobby::get_offset_58() {
    s32 arg0 = (s32)this;
    return arg0 + 0x58;
}
void TLobby__sub_803BFE58(u8 *arg0) {
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_field_34();
}
void TLobby::dispatch_field4_event() {
    u8 *arg0 = (u8 *)this;
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_field30();
}
void TLobby::send_with_offset4_alt() {
    u8 *arg0 = (u8 *)this;
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_field_2c();
}
void TLobby::notify_client() {
    u8 *arg0 = (u8 *)this;
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_field_28();
}
void TLobby__sub_803BFEE8(u8 *arg0) {
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_slot();
}
void TLobby::send_packet_by_id() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C3ABC((u8 *)(*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby::notify_field_4_alt() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C3AC4((u8 *)(*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby::send_packet_by_id_2() {
    u8 *arg0 = (u8 *)this;
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->get_packet_flag_for_state();
}
void TLobby::send_with_offset4() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C3B38((int) (*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby::notify_field_4() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C3B44((u8 *)(*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby__sub_803BFFC0(u8 *arg0) {
    get_field_a8__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby::set_field_44(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x44) = arg1;
}
void TLobby::set_field_40(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x40) = arg1;
}
void TLobby::set_field_3c(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C) = arg1;
}
void TLobby__sub_803BFFFC(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x48) = arg1;
    *(s32 *)((s8 *)arg0 + 0x4C) = arg2;
}
void TLobby::set_count(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x34) = arg1;
}
s32 TLobby__sub_803C0010(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x2C);
}

struct Obj_803C0628;

void GXFlush(void) {
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
    n = TLobby__sub_803C3B68(h, (u16 *)b.data, b.size);
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
        TLobby__sub_803C0238(st);
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
    h->init_scroll((s32)st->src_chunk.data, st->src_chunk.size);
    TLobby__sub_803C3A04((u8 *)h);
}

inline void drain_audio_stream_decoder(AudioStreamInputState *st) {
    TLobby *h = st->decoder;
    AudioStreamSource *s = st->source;
    SjChunk head;
    SjChunk tail;
    s32 total = TLobby__sub_803C3ABC((u8 *)h);
    s32 bytes = h->get_field_0xa4();
    s32 avail = h->get_field_a0();
    s32 n = total - st->decoded_samples;
    s32 i;
    if (avail < n) {
        n = avail;
    }
    TLobby__sub_803D3130(&st->src_chunk, bytes, &head, &tail);
    s->vt->put_chunk(s, 0, &head);
    s->vt->unget_chunk(s, 1, &tail);
    for (i = 0; i < TLobby__sub_803C3B38((int)st->decoder); i++) {
        TLobby__sub_803D3130(&st->out_chunks[i], n * 2, &head, &tail);
        if (st->output_callback != NULL) {
            st->output_callback(st->output_context, i, head.data, head.size);
        }
        st->rings[i]->interface->put_chunk(st->rings[i], 1, (SjChunk *)&head);
        st->rings[i]->interface->unget_chunk(st->rings[i], 0, (SjChunk *)&tail);
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
    s32 total = TLobby__sub_803C3ABC((u8 *)h);
    s32 bytes = h->get_field_0xa4();
    s32 avail = h->get_field_a0();
    s32 n = total - st->decoded_samples;
    if (avail < n) {
        n = avail;
    }
    st->output_samples += n;
    st->consumed_bytes += bytes;
    st->decoded_samples += n;
}

void TLobby__sub_803C0238(AudioStreamInputState *st) {
    TLobby *h = st->decoder;
    if (h->get_entry_id() == 0) {
        feed_audio_stream_decoder(st);
    }
    TLobby__sub_803C34F4(h);
    if (h->get_entry_id() == 3) {
        drain_audio_stream_decoder(st);
    }
    if (((AudioStreamDecoder *)h)->format == 10) {
        skip_audio_stream_decoder(st);
    }
}

void TLobby__sub_803C0628(void *arg0_, s32 *arg1, s32 *arg2, s32 *arg3) {
    S_803C0628 *arg0 = (S_803C0628 *)arg0_;
    s32 h;
    s32 i;
    s32 t;
    s32 v;
    h = (s32)arg0->objs[0];
    for (i = 0; i < ((s32)TLobby__sub_803C3B38(arg0->f4)); i++) {
        arg0->objs[i]->vt->fn18(arg0->objs[i], 0, 0x4000, &arg0->recs[i]);
    }
    *arg1 = (arg0->recs[0].a - (s32)sj_ring_buffer_get_buffer((SjRingBuffer*)h)) / 2;
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
    ((TLobby *)(arg0->f4))->get_field_0x3c();
}

void TLobby::reset_flag() {
    u8 *arg0 = (u8 *)this;
    TLobby__sub_803C39CC((u8 *)(*(s32 *)((s8 *)arg0 + 4)));
    *(s8 *)((s8 *)arg0 + 1) = 0;
}
void TLobby__sub_803C0758(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x98) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x38) = 0x7FFFFFFF;
    *(s32 *)((s8 *)arg0 + 0x3C) = -1;
    *(s32 *)((s8 *)arg0 + 0x40) = 0;
    *(s32 *)((s8 *)arg0 + 0x44) = 0;
    *(s8 *)((s8 *)arg0 + 3) = 0;
    *(s8 *)((s8 *)arg0 + 1) = 1;
}
void TLobby::set_network_result(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x38) = arg1;
    TLobby__sub_803C1A00((int) (*(s32 *)((s8 *)arg0 + 4)));
}
void TLobby::set_param_and_notify(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 8) = arg1;
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->invoke_notify_callback();
}

s32 TLobby__sub_803C07E8(Obj_803C07E8 *self) {
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
AudioStreamInputState *TLobby__sub_803C0848(AudioStreamSource *source, s32 channels, SjRingBuffer **rings) {
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
    st->decoder = alloc_record__6TLobbyFiiii(channels, buffer, size, size + sj_ring_buffer_get_extra_buffer_size(ring) / 2);
    if (st->decoder == NULL) {
        return NULL;
    }
    TLobby__sub_803C3B5C(st->decoder, TLobby__sub_803C0628, st);
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
    memset((void *) (&(*(RecoveredGlobal_803C0AD8_lbl_80570AC0 *)&lbl_80570AC0).value), 0, 0x9C0);
}
void TLobby::reset_sound_buffers() {
    TLobby__sub_803C406C();
    memset(&lbl_80570AC0.value, 0, 0x9C0);
}
void TLobby__sub_803C0B3C(u8 *lobby) {
    s16 temp_r0;
    temp_r0 = *(s16 *)((s8 *)lobby + 0xAA);
    if (temp_r0 == 2) {
        EXIGetID((Snd_803C0BE8 *)(lobby));
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
    if (memcmp(arg0, &lbl_805E0CB0, 4) == 0 && memcmp((u8 *)&this->m_prev, &lbl_805E0CB8, 4) == 0) {
        return 1;
    }
    return 0;
}

void EXIGetID(Snd_803C0BE8 *arg0) {
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

typedef char RecoveredGlobal_803C0B08_lbl_80570AC0_size[sizeof(RecoveredGlobal_803C0B08_lbl_80570AC0) == 0x9C0 ? 1 : -1];
typedef char RecoveredGlobal_803C0AD8_lbl_80570AC0_size[sizeof(RecoveredGlobal_803C0AD8_lbl_80570AC0) == 0x9C0 ? 1 : -1];

}
