#include <string.h>
#include <dolphin/os/OSThread.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AudioStreamInput.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/unk/text_803D31A4.h"

struct Pair_803C8678 { u32 a, b; };

struct Strm_803CB20C;
struct Buf_803CB20C { void *data; s32 size; };

struct VT_803CB20C {
    void *pad[5];
    void (*m14)(Strm_803CB20C *);
    void (*lock)(Strm_803CB20C *, s32, s32, Buf_803CB20C *);
    void *pad1C;
    void (*commit)(Strm_803CB20C *, s32, Buf_803CB20C *);
};

struct Strm_803CB20C { VT_803CB20C *vt; };

struct Obj_803CB20C {
    u8 pad0[2]; u8 f2; u8 pad3; AudioStreamInputState *input_state; u32 f8; u8 padC[8]; Strm_803CB20C *f14;
    u8 pad18[0x4C - 0x18]; s32 f4C; s32 f50; u8 pad54[0x6C - 0x54]; s8 f6C;
    u8 pad6D[0x90 - 0x6D]; s32 f90;
};

extern "C" {
void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0);

extern s32 lbl_805D7540;
s32 TLobby__sub_803CC030(int, int);
s32 dispatch_packet__6TLobbyFv(int, int);
void TLobby__sub_803CB194(void *context);
void audio_stream_start(u8 *lobby);
s32 TLobby__sub_803CBF50(saddr, s32, s32);
void TLobby__sub_803CA8B4(AdxtPlayer *);

s32 trigger_sub_task__6TLobbyFv(saddr, s32);

s32 audio_stream_get_output_samples(u8 *lobby);

}
extern "C" {

s32 TLobby__sub_803BFE58(int);
s32 TLobby__sub_803BFEE8(int);
s32 audio_stream_get_format(int);
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, void *context);
s32 audio_stream_get_state(int);
s32 run_step_4430__6TLobbyFv(int, int);
s32 TLobby__sub_803CBF0C(int, int);
s32 TLobby__sub_803CBF30(int, int);
s32 TLobby__sub_803CBF90(int, int);
s32 TLobby__sub_803CBFB0(int, int);
struct Conn_803CAEB4;
void TLobby__sub_803CAEB4(Conn_803CAEB4 *arg0);

void adxt_stat_decinfo(AdxtPlayer *self);
s32 TLobby__sub_803CBFF0(int);
s32 lbl_805D7578;
s32 lbl_805D757C;
s32 lbl_805D7580;

// Inferred: CRI adxt_stat_prep (wait until every output SJ holds data, then start the RNA).
inline void prep_803CA8B4(AdxtPlayer *self) {
    s32 n;
    s32 i;
    if (audio_stream_get_state(reinterpret_cast<saddr>(self->input_state)) == 3) {
        n = reinterpret_cast<TLobby *>(self->input_state)->send_with_offset4();
        lbl_805D7580 = n;
        for (i = 0; i < n; i++) {
            lbl_805D757C = self->output_rings[i]->interface->get_available(self->output_rings[i], 1);
            if (lbl_805D757C >= 0x40) {
                break;
            }
        }
        if (i == n) {
            TLobby::dispatch_packet((GcrnaStream *)(self->rna_handle), 0);
            self->stat = 4;
        }
    }
}
// Inferred: CRI adxt_stat_playing (start playback once enough is decoded; pad the end with silence).
inline void dec_803CA8B4(AdxtPlayer *self) {
    saddr rna = self->rna_handle;
    AudioStreamInputState *sjd = self->input_state;
    s32 i;
    s32 avail;
    s32 nbyte;
    s32 size;
    s32 nch;
    SjRingBuffer *sj;
    SjChunk ck;
    avail = TLobby::query_available_size((TLobby *)rna);
    size = TLobby__sub_803CBFF0(rna);
    if (avail >= self->reserved_48 * 2 || size <= reinterpret_cast<TLobby *>(sjd)->notify_field_4_alt() ||
        audio_stream_get_state(reinterpret_cast<saddr>(self->input_state)) == 3) {
        if (self->auto_start_flag == 0) {
            if (self->pause_flag == 0) {
                TLobby__sub_803CC030(rna, 1);
                self->base_time = 0;
                self->base_vblank = lbl_805D7540;
            }
            self->stat = 3;
        }
        self->started_playback = 1;
    }
    if (audio_stream_get_state(reinterpret_cast<saddr>(self->input_state)) == 3) {
        nch = TLobby__sub_803C9740((u8 *)self);
        nbyte = self->reserved_48 * nch * 2;
        for (i = 0; i < nch; i++) {
            sj = self->output_rings[i];
            sj->interface->get_chunk(sj, 0, nbyte, &ck);
            memset(ck.data, 0, ck.size);
            sj->interface->put_chunk(sj, 1, &ck);
        }
    }
}
// Inferred: CRI adxt_stat_playend (stop the RNA once its queue is empty).
inline void end_803CA8B4(AdxtPlayer *self) {
    lbl_805D7578 = TLobby::query_available_size((TLobby *)self->rna_handle);
    if (TLobby::query_available_size((TLobby *)self->rna_handle) <= 0) {
        TLobby__sub_803CC030(self->rna_handle, 0);
        self->stat = 5;
    }
}
// Inferred: CRI ADXT_ExecHndl (per-handle state step of the ADXT server).
#pragma push
#pragma opt_common_subs off
void TLobby__sub_803CA8B4(AdxtPlayer *self) {
    s8 stat = self->stat;
    if (stat == 3) {
        prep_803CA8B4(self);
    } else if (stat == 1) {
        adxt_stat_decinfo(self);
    } else if (stat == 2) {
        dec_803CA8B4(self);
    } else if (stat == 4) {
        end_803CA8B4(self);
    }
    if (self->stream_file != NULL && get_adx_stream_status(self->stream_file) == 4) {
        self->error_code = -1;
        self->stat = 6;
    }
    if (self->lsc_stream != NULL && lsc_get_state(self->lsc_stream) == 3) {
        self->error_code = -1;
        self->stat = 6;
    }
}
#pragma pop

#define SBF50 TLobby__sub_803CBF50

void adxt_stat_decinfo(AdxtPlayer *self) {
    AudioStreamInputState *input_state = self->input_state;
    s32 k;
    s32 n1;
    char buf[32];

    if (audio_stream_get_state(reinterpret_cast<saddr>(input_state)) == 2) {
        s32 v = reinterpret_cast<TLobby *>(input_state)->send_with_offset4();
        if (v > self->max_channels) {
            TLobby::format_number_pair(v, self->max_channels, buf, 0x10);
            TLobby::report_adx_error("E9081001 adxt_stat_decinfo: can't play this number of channels", buf);
            stop_audio_stream(self);
            return;
        }
        n1 = reinterpret_cast<TLobby *>(input_state)->notify_field_4();
        k = TLobby__sub_803BFEE8(reinterpret_cast<saddr>(input_state));
        if (k > 0) {
            self->reserved_48 = (n1 / self->server_freq) * 3;
        } else {
            self->reserved_48 = ((n1 / self->server_freq) * 3) / 2;
        }
        {
            s32 a = reinterpret_cast<TLobby *>(input_state)->notify_field_4_alt() * 2;
            self->reserved_48 = a * ((self->reserved_48 + a) / a);
        }
        reinterpret_cast<TLobby *>(input_state)->set_network_result(self->reserved_48);
        if (k > 0) {
            if ((s32) self->source_type == 2) {
                self->reserved_50 = 0;
            } else {
                s32 x = TLobby__sub_803BFE58(reinterpret_cast<saddr>(input_state));
                s32 pages;
                self->reserved_50 = 0x800 - x % 0x800;
                pages = (x + 0x7FF) / 0x800;
                self->reserved_50 = self->reserved_50 % 0x800;
                self->total_pages = pages;
                set_adx_stream_end_sector(self->stream_file, pages);
                set_adx_stream_completion(self->stream_file, TLobby__sub_803CB194, self);
            }
            s32 e = input_state->get_loop_end_sample();
            self->loop_end_sample = e;
            input_state->set_notify_sample_count(e);
            input_state->set_notify_bytes(0);
            input_state->set_notify_count(0);
            audio_stream_set_notify_callback(reinterpret_cast<u8 *>(input_state), (saddr)adxt_trap_entry_update__6TLobbyFPv, self);
        } else {
            if (self->stream_file != NULL) {
                set_adx_stream_end_sector(self->stream_file, 0x7FFFFFFF);
            }
            input_state->set_notify_sample_count(reinterpret_cast<TLobby *>(input_state)->send_packet_by_id());
            input_state->set_notify_bytes(0);
            input_state->set_notify_count(0);
            audio_stream_set_notify_callback(reinterpret_cast<u8 *>(input_state), (saddr)TLobby__sub_803CAEB4, self);
        }
        k = reinterpret_cast<TLobby *>(input_state)->notify_field_4();
        n1 = reinterpret_cast<TLobby *>(input_state)->send_with_offset4();
        s32 pid = reinterpret_cast<TLobby *>(input_state)->send_packet_by_id();
        s32 p2 = reinterpret_cast<TLobby *>(input_state)->send_packet_by_id_2();
        TLobby__sub_803CBF30(self->rna_handle, p2);
        TLobby__sub_803CBF90(self->rna_handle, k);
        TLobby__sub_803CBFB0(self->rna_handle, n1);
        TLobby__sub_803CBF0C(self->rna_handle, pid);
        trigger_sub_task__6TLobbyFv(self->rna_handle, self->output_vol);
        if (reinterpret_cast<TLobby *>(self->input_state)->send_with_offset4() == 1) {
            if (self->out_pan[0] == -0x80) {
                SBF50(self->rna_handle, 0, 0);
            } else {
                SBF50(self->rna_handle, 0, self->out_pan[0]);
            }
        } else {
            if (self->out_pan[0] == -0x80) {
                SBF50(self->rna_handle, 0, -0xF);
            } else {
                SBF50(self->rna_handle, 0, self->out_pan[0]);
            }
            if (self->out_pan[1] == -0x80) {
                SBF50(self->rna_handle, 1, 0xF);
            } else {
                SBF50(self->rna_handle, 1, self->out_pan[1]);
            }
        }
        if (self->amp != NULL) {
            ((TLobby *)(self->amp))->set_packet_flags(k);
        }
        if (audio_stream_get_format(reinterpret_cast<saddr>(input_state)) == 2) {
            s32 o = reinterpret_cast<TLobby *>(input_state)->get_offset_58();
            run_step_4430__6TLobbyFv(self->rna_handle, o);
        }
        TLobby::dispatch_packet((GcrnaStream *)(self->rna_handle), 1);
        self->stat = 2;
    }
}
#undef SBF50

typedef struct Conn_803CAEB4 Conn_803CAEB4;
typedef struct RingVt_803CAEB4 RingVt_803CAEB4;
typedef struct Ring_803CAEB4 Ring_803CAEB4;
struct Ring_803CAEB4;
struct RingVt_803CAEB4
{
  u8 pad0[0x18];
  void (*m4)(Ring_803CAEB4 *, s32, s32, SjChunk *);
  void (*m5)(Ring_803CAEB4 *, s32, SjChunk *);
  void (*m6)(Ring_803CAEB4 *, s32, SjChunk *);
};
struct Ring_803CAEB4
{
  RingVt_803CAEB4 *vt;
};
struct Conn_803CAEB4
{
  u8 pad0[4];
  s32 lobby;
  u8 pad8[0x14 - 0x8];
  Ring_803CAEB4 *ring;
  u8 pad18[0x48 - 0x18];
  s32 f48;
  u8 pad4C[0x98 - 0x4C];
  s8 active;
  u8 pad99[0xA4 - 0x99];
  s32 fA4;
};
s32 process_audio_stream_input(int);

void TLobby__sub_803CAEB4(Conn_803CAEB4 *o) {
  saddr lobby = o->lobby;
  AudioStreamInputState *input_state = reinterpret_cast<AudioStreamInputState *>(lobby);
  Ring_803CAEB4 *ring = o->ring;
  SjChunk a;
  SjChunk c;
  SjChunk b;
  SjChunk d;
  s16 hlen;
  s16 tlen;
  s32 r1;
  s32 r2;
  s32 n;
  s32 m;
  if (o->active != 0)
  {
    tlen = 0;
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &a);
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &b);
    if (((TLobby *)(a.data))->parse_packet_header_len(a.size, &hlen) != 0)
    {
      o->active = 0;
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      return;
    }
    n = hlen;
    r1 = TLobby::find_terminator_index((s16 *)(a.data + n), (s32)(a.size - n), &hlen);
    if (r1 == 0)
    {
      r2 = -1;
    }
    else
    {
      r2 = TLobby::find_terminator_index((s16 *)b.data, (s32)b.size, &tlen);
    }
    n += hlen;
    m = tlen & 0xFFFFFFFFFFFFFFFFu;
    if ((r1 != 0) && (r2 != 0))
    {
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      o->active = 0;
      return;
    }
    if (r1 == 0)
    {
      ring->vt->m5(ring, 1, &b);
      TLobby__sub_803D3130(&a, n, &a, &c);
      ring->vt->m6(ring, 0, &a);
      ring->vt->m5(ring, 1, &c);
    }
    else
    {
      ring->vt->m6(ring, 0, &a);
      TLobby__sub_803D3130(&b, m, &b, &d);
      ring->vt->m6(ring, 0, &b);
      ring->vt->m5(ring, 1, &d);
    }
    o->fA4 += audio_stream_get_output_samples((u8 *)lobby);
    ((TLobby *)lobby)->reset_flag();
    audio_stream_start((u8 *)lobby);
    process_audio_stream_input(lobby);
    if (audio_stream_get_state(lobby) != 2)
    {
      o->active = 0;
      return;
    }
    ((TLobby *)lobby)->set_network_result(o->f48);
    input_state->set_notify_sample_count(((TLobby *)lobby)->send_packet_by_id());
    input_state->set_notify_bytes(0);
    input_state->set_notify_count(0);
  }
}

void TLobby__sub_803CB194(void *context) {
    AdxtPlayer *player = static_cast<AdxtPlayer *>(context);
    AdxStreamFile *file = player->stream_file;
    s32 loop_start_byte = player->input_state->get_loop_start_byte();
    if (player->loop_flag == 0) {
        player->input_state->set_notify_sample_count(-1);
        set_adx_stream_end_sector(player->stream_file, 0x7FFFFFFF);
        return;
    }
    seek_adx_stream_sector(file, loop_start_byte / 2048);
}

void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0) {
    Buf_803CB20C b;
    Strm_803CB20C *s;
    s32 total;
    AudioStreamInputState *input;
    s32 off;
    s32 c;
    input = arg0->input_state;
    s = arg0->f14;
    c = input->get_loop_start_sample();
    off = input->get_loop_start_byte();
    total = input->get_loop_end_sample();
    if (arg0->f8 == 0U && arg0->f6C == 0) {
        arg0->input_state->set_notify_sample_count(-1);
        return;
    }
    s->vt->lock(s, 1, arg0->f50, &b);
    if (b.size < arg0->f50) {
        TLobby::notify_error("E8101201 adxt_trap_entry: not enough data");
    }
    s->vt->commit(s, 0, &b);
    input->set_notify_count(0);
    input->set_notify_sample_count(arg0->f90 = total - c);
    input->set_notify_bytes(off);
    input->set_decoded_samples(c);
    if ((s32)arg0->f2 == 2) {
        s->vt->m14(s);
        s->vt->lock(s, 1, off, &b);
        s->vt->commit(s, 0, &b);
    }
    arg0->f4C += 1;
}

}
