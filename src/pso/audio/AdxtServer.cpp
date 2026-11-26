#include <string.h>
#include "pso/audio/AdxError.h"
#include <dolphin/os/OSThread.h>
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AudioStreamInput.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/audio/AdxHeader.h"

#include "types.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/audio/GcrnaBridgePanId.h"
#include "pso/audio/GcrnaBridgeSampleBits.h"
#include "pso/audio/GcrnaBridgeStatus.h"
#include "pso/audio/GcrnaBridge.h"
#include "pso/audio/CriSvm.h"
#include "pso/audio/AdxManager.h"

void adxt_trap_entry_update(void *context);

extern "C" {
void adxt_loop_callback(void *context);
void adxt_exec_handle(AdxtPlayer *);
}
extern "C" {

void adxt_trap_end_update(void *context);

void adxt_stat_decinfo(AdxtPlayer *self);
s32 adxt_end_available;
s32 adxt_prep_available;
s32 adxt_prep_channel_count;

// Waits until every output SJ holds data, then starts the RNA.
inline void adxt_stat_prep(AdxtPlayer *self) {
    s32 n;
    s32 i;
    if (audio_stream_get_state(self->input_state) == 3) {
        n = self->input_state->get_channels();
        adxt_prep_channel_count = n;
        for (i = 0; i < n; i++) {
            adxt_prep_available = self->output_rings[i]->interface->get_available(self->output_rings[i], 1);
            if (adxt_prep_available >= 0x40) {
                break;
            }
        }
        if (i == n) {
            gcrna_bridge_set_trans_sw(self->rna_handle, 0);
            self->stat = 4;
        }
    }
}
// Starts playback once enough is decoded; pads the end with silence.
inline void adxt_stat_playing(AdxtPlayer *self) {
    GcrnaStream *rna = self->rna_handle;
    AudioStreamInputState *sjd = self->input_state;
    s32 i;
    s32 avail;
    s32 nbyte;
    s32 size;
    s32 nch;
    SjRingBuffer *sj;
    SjChunk ck;
    avail = query_available_size(rna);
    size = gcrna_bridge_get_packet_size(rna);
    if (avail >= self->reserved_48 * 2 || size <= sjd->get_block_samples() ||
        audio_stream_get_state(self->input_state) == 3) {
        if (self->auto_start_flag == 0) {
            if (self->pause_flag == 0) {
                gcrna_bridge_set_play_sw(rna, 1);
                self->base_time = 0;
                self->base_vblank = adxt_vblank_count;
            }
            self->stat = 3;
        }
        self->started_playback = 1;
    }
    if (audio_stream_get_state(self->input_state) == 3) {
        nch = adxt_get_num_channels(self);
        nbyte = self->reserved_48 * nch * 2;
        for (i = 0; i < nch; i++) {
            sj = self->output_rings[i];
            sj->interface->get_chunk(sj, 0, nbyte, &ck);
            memset(ck.data, 0, ck.size);
            sj->interface->put_chunk(sj, 1, &ck);
        }
    }
}
// Stops the RNA once its queue is empty.
inline void adxt_stat_playend(AdxtPlayer *self) {
    adxt_end_available = query_available_size(self->rna_handle);
    if (query_available_size(self->rna_handle) <= 0) {
        gcrna_bridge_set_play_sw(self->rna_handle, 0);
        self->stat = 5;
    }
}
// One server step of a handle, by its state.
#pragma push
#pragma opt_common_subs off
void adxt_exec_handle(AdxtPlayer *self) {
    s8 stat = self->stat;
    if (stat == 3) {
        adxt_stat_prep(self);
    } else if (stat == 1) {
        adxt_stat_decinfo(self);
    } else if (stat == 2) {
        adxt_stat_playing(self);
    } else if (stat == 4) {
        adxt_stat_playend(self);
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



void adxt_stat_decinfo(AdxtPlayer *self) {
    AudioStreamInputState *input_state = self->input_state;
    s32 k;
    s32 n1;
    char buf[32];

    if (audio_stream_get_state(input_state) == 2) {
        s32 v = input_state->get_channels();
        if (v > self->max_channels) {
            adxerr_format_id_pair(v, self->max_channels, buf, 0x10);
            adxerr_report_pair("E9081001 adxt_stat_decinfo: can't play this number of channels", buf);
            stop_audio_stream(self);
            return;
        }
        n1 = input_state->get_rate();
        k = get_stream_loop_type(input_state);
        if (k > 0) {
            self->reserved_48 = (n1 / self->server_freq) * 3;
        } else {
            self->reserved_48 = ((n1 / self->server_freq) * 3) / 2;
        }
        {
            s32 a = input_state->get_block_samples() * 2;
            self->reserved_48 = a * ((self->reserved_48 + a) / a);
        }
        input_state->set_max_samples(self->reserved_48);
        if (k > 0) {
            if ((s32) self->source_type == 2) {
                self->reserved_50 = 0;
            } else {
                s32 x = get_stream_loop_end_byte(input_state);
                s32 pages;
                self->reserved_50 = 0x800 - x % 0x800;
                pages = (x + 0x7FF) / 0x800;
                self->reserved_50 = self->reserved_50 % 0x800;
                self->total_pages = pages;
                set_adx_stream_end_sector(self->stream_file, pages);
                set_adx_stream_completion(self->stream_file, adxt_loop_callback, self);
            }
            s32 e = input_state->get_loop_end_sample();
            self->loop_end_sample = e;
            input_state->set_notify_sample_count(e);
            input_state->set_notify_bytes(0);
            input_state->set_notify_count(0);
            audio_stream_set_notify_callback(input_state, adxt_trap_entry_update, self);
        } else {
            if (self->stream_file != NULL) {
                set_adx_stream_end_sector(self->stream_file, 0x7FFFFFFF);
            }
            input_state->set_notify_sample_count(input_state->get_total_samples());
            input_state->set_notify_bytes(0);
            input_state->set_notify_count(0);
            audio_stream_set_notify_callback(input_state, adxt_trap_end_update, self);
        }
        k = input_state->get_rate();
        n1 = input_state->get_channels();
        s32 pid = input_state->get_total_samples();
        s32 p2 = input_state->get_bits_per_sample();
        gcrna_bridge_set_sample_bits(self->rna_handle, p2);
        gcrna_bridge_set_frequency(self->rna_handle, k);
        gcrna_bridge_set_stream_count(self->rna_handle, n1);
        gcrna_bridge_set_pan_id(self->rna_handle, pid);
        gcrna_bridge_set_volume(self->rna_handle, self->output_vol);
        if (self->input_state->get_channels() == 1) {
            if (self->out_pan[0] == -0x80) {
                gcrna_bridge_set_channel_pan(self->rna_handle, 0, 0);
            } else {
                gcrna_bridge_set_channel_pan(self->rna_handle, 0, self->out_pan[0]);
            }
        } else {
            if (self->out_pan[0] == -0x80) {
                gcrna_bridge_set_channel_pan(self->rna_handle, 0, -0xF);
            } else {
                gcrna_bridge_set_channel_pan(self->rna_handle, 0, self->out_pan[0]);
            }
            if (self->out_pan[1] == -0x80) {
                gcrna_bridge_set_channel_pan(self->rna_handle, 1, 0xF);
            } else {
                gcrna_bridge_set_channel_pan(self->rna_handle, 1, self->out_pan[1]);
            }
        }
        if (self->amp != NULL) {
            self->amp->set_packet_flags(k);
        }
        if (audio_stream_get_format(input_state) == 2) {
            u8 *header = input_state->get_header();
            run_step_4430(self->rna_handle, header);
        }
        gcrna_bridge_set_trans_sw(self->rna_handle, 1);
        self->stat = 2;
    }
}


void adxt_trap_end_update(void *context) {
  AdxtPlayer *o = static_cast<AdxtPlayer *>(context);
  AudioStreamInputState *input_state = o->input_state;
  SjRingBuffer *ring = o->input_sj;
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
  if (o->sync_mode_flag != 0)
  {
    tlen = 0;
    ring->interface->get_chunk(ring, 1, 0x7FFFFFFF, &a);
    ring->interface->get_chunk(ring, 1, 0x7FFFFFFF, &b);
    if (adx_parse_packet_header_len(a.data, a.size, &hlen) != 0)
    {
      o->sync_mode_flag = 0;
      ring->interface->unget_chunk(ring, 1, &b);
      ring->interface->unget_chunk(ring, 1, &a);
      return;
    }
    n = hlen;
    r1 = adx_find_end_marker((s16 *)(a.data + n), (s32)(a.size - n), &hlen);
    if (r1 == 0)
    {
      r2 = -1;
    }
    else
    {
      r2 = adx_find_end_marker((s16 *)b.data, (s32)b.size, &tlen);
    }
    n += hlen;
    m = tlen & 0xFFFFFFFFFFFFFFFFu;
    if ((r1 != 0) && (r2 != 0))
    {
      ring->interface->unget_chunk(ring, 1, &b);
      ring->interface->unget_chunk(ring, 1, &a);
      o->sync_mode_flag = 0;
      return;
    }
    if (r1 == 0)
    {
      ring->interface->unget_chunk(ring, 1, &b);
      sj_split_chunk(&a, n, &a, &c);
      ring->interface->put_chunk(ring, 0, &a);
      ring->interface->unget_chunk(ring, 1, &c);
    }
    else
    {
      ring->interface->put_chunk(ring, 0, &a);
      sj_split_chunk(&b, m, &b, &d);
      ring->interface->put_chunk(ring, 0, &b);
      ring->interface->unget_chunk(ring, 1, &d);
    }
    o->played_samples += audio_stream_get_output_samples(input_state);
    input_state->stop();
    audio_stream_start(input_state);
    process_audio_stream_input(input_state);
    if (audio_stream_get_state(input_state) != 2)
    {
      o->sync_mode_flag = 0;
      return;
    }
    input_state->set_max_samples(o->reserved_48);
    input_state->set_notify_sample_count(input_state->get_total_samples());
    input_state->set_notify_bytes(0);
    input_state->set_notify_count(0);
  }
}

void adxt_loop_callback(void *context) {
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

}

void adxt_trap_entry_update(void *context) {
    AdxtPlayer *player = static_cast<AdxtPlayer *>(context);
    SjChunk b;
    SjRingBuffer *s;
    s32 total;
    AudioStreamInputState *input;
    s32 off;
    s32 c;
    input = player->input_state;
    s = player->input_sj;
    c = input->get_loop_start_sample();
    off = input->get_loop_start_byte();
    total = input->get_loop_end_sample();
    if (player->stream_file == NULL && player->loop_flag == 0) {
        player->input_state->set_notify_sample_count(-1);
        return;
    }
    s->interface->get_chunk(s, 1, player->reserved_50, &b);
    if (b.size < player->reserved_50) {
        adxerr_report("E8101201 adxt_trap_entry: not enough data");
    }
    s->interface->put_chunk(s, 0, &b);
    input->set_notify_count(0);
    input->set_notify_sample_count(player->loop_end_sample = total - c);
    input->set_notify_bytes(off);
    input->set_decoded_samples(c);
    if ((s32)player->source_type == 2) {
        s->interface->reset(s);
        s->interface->get_chunk(s, 1, off, &b);
        s->interface->put_chunk(s, 0, &b);
    }
    player->reserved_4C += 1;
}
