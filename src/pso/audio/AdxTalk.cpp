#include <string.h>
#include "pso/audio/AdxError.h"
#include "pso/audio/AdxLock.h"
#include <dolphin/os/OSThread.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/audio/AdxHeader.h"
#include "pso/audio/AdxStream.h"
#include "pso/audio/AdxTalk.h"
#include "pso/audio/AdxDecode4.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AudioStreamInput.h"
#include "pso/unk/TLobby_803BFE50.h"
#include "pso/unk/TLobby_803CBF50.h"
#include "pso/audio/GcrnaBridgeReady.h"
#include "pso/audio/GcrnaBridgeTeardown.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/audio/GcrnaStream.h"
#include "pso/unk/text_803D31A4.h"

struct Pair_803C8678 { u32 a, b; };

extern "C" {

void adxt_set_output_mono(s32 mode) {
    adx_set_stereo_downmix(mode);
}

s32 TLobby__sub_803C9104(AdxtPlayer *player, s32 channels, s32 samples) {
    s32 blk;
    s32 total;
    SjRingBuffer *sj;
    s32 n1;
    s32 n2;
    SjChunk a;
    SjChunk b;
    void *p = player->input_sj;
    sj = (SjRingBuffer *)p;
    if (p == NULL) {
        return 0;
    }
    blk = channels * 0x12;
    total = (samples / 32) * blk;
    sj->interface->get_chunk(sj, 0, total, &a);
    n1 = blk * (a.size / blk);
    memset(a.data, 0, n1);
    TLobby__sub_803D3130(&a, n1, &a, &b);
    sj->interface->put_chunk(sj, 1, &a);
    sj->interface->unget_chunk(sj, 0, &b);
    total = total - n1;
    sj->interface->get_chunk(sj, 0, total, &a);
    n2 = blk * (a.size / blk);
    memset(a.data, 0, n2);
    TLobby__sub_803D3130(&a, n2, &a, &b);
    sj->interface->put_chunk(sj, 1, &a);
    sj->interface->unget_chunk(sj, 0, &b);
    return ((n1 + n2) / blk) * 32;
}

s32 adx_check_packet_header(u16 *p, s32 size, s32 *out) {
    if (size < 2) {
        return 0;
    }
    if (*p != 0x8001) {
        return 0;
    }
    *out = size;
    return 1;
}
s32 adx_get_data_start_offset(u16 *hdr, s32 size, s32 *arg2) {
    s32 a7;
    s32 a8;
    s32 a9;
    s16 len;
    u8 b3;
    s8 b4;
    s8 b5;
    u8 b6;
    if (size < 2) {
        return 0;
    }
    if (*hdr != 0x8000) {
        return 0;
    }
    if (adx_parse_header_info((u8 *)hdr, size, &len, &b3, &b4, &b5, &b6, &a7, &a8, &a9) < 0) {
        return 0;
    }
    *arg2 = len;
    return 1;
}
}

typedef void (*RecoveredCallback_2be3cacebb2e)(void);


extern s32 lbl_805D7540;

extern "C" {
void TLobby__sub_803CA8B4(AdxtPlayer *);
extern AdxtPlayer adx_stream_player_pool[16];

s32 lbl_805D7560;
s32 lbl_805D7564;
s32 lbl_805D7568;
f32 lbl_805D756C;
s32 lbl_805D7570;
RecoveredCallback_2be3cacebb2e lbl_805D7574;

void set_sync_mode_flag(AdxtPlayer *player, s8 flag) {
    player->sync_mode_flag = flag;
}

void TLobby__sub_803C9350(AdxtPlayer *player, s32 offset) {
    player->time_offset = offset;
}

inline void inl_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        adx_lock();
        lbl_805D7564 = 1;
        sub_803C0018();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].used == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        adx_unlock();
    }
}
s32 TLobby__sub_803C9358(AdxtPlayer *player) {
    s32 ret;
    s32 save;
    s32 pos;
    s32 rate;
    if (player->pause_flag == 0) {
        return 0;
    }
    ret = TLobby__sub_803CBF10(player->rna_handle);
    inl_803C9608();
    save = lbl_805D7560;
    lbl_805D7560 = 0;
    TLobby__sub_803C97F4(player, &pos, &rate);
    lbl_805D7560 = save;
    player->base_time = (s32)((f32)lbl_805D7570 * ((f32)pos / (f32)rate));
    player->base_vblank = lbl_805D7540;
    return ret;
}

void TLobby__sub_803C94B8(AdxMessageCallback callback, s32 context) {
    adxerr_set_callback(callback, context);
}

void TLobby__sub_803C94D8(void) {

}

void TLobby__sub_803C94DC(AdxtPlayer *player, s32 paused) {
    s32 pos;
    s32 rate;
    s32 st;
    s32 save;
    st = player->stat;
    if (paused != player->pause_flag) {
        adx_lock();
        player->pause_flag = paused;
        if (st == 3 || st == 4) {
            if (paused == 1) {
                TLobby__sub_803CC030(player->rna_handle, 0);
            } else {
                TLobby__sub_803CC030(player->rna_handle, 1);
                player->base_vblank = lbl_805D7540;
            }
            save = lbl_805D7560;
            lbl_805D7560 = 0;
            TLobby__sub_803C97F4(player, &pos, &rate);
            lbl_805D7560 = save;
            player->base_time = (s32)((f32)lbl_805D7570 * ((f32)pos / (f32)rate));
        }
        adx_unlock();
    }
}

s32 get_error_code(AdxtPlayer *player) {
    return player->error_code;
}

void TLobby__sub_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        adx_lock();
        lbl_805D7564 = 1;
        sub_803C0018();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].used == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        adx_unlock();
    }
}

void set_auto_repeat(AdxtPlayer *player, s8 flag) {
    player->auto_repeat = flag;
}

void TLobby__sub_803C96A8(AdxtPlayer *player, s32 freq) {
    player->server_freq = freq;
}

s16 TLobby__sub_803C96B0(AdxtPlayer *player) {
    return player->output_vol;
}

}

void set_field_40_and_notify(AdxtPlayer *player, s32 volume) {
    player->output_vol = volume;
    trigger_sub_task(player->rna_handle, volume);
}

extern "C" {

s16 TLobby__sub_803C96E0(AdxtPlayer *player, s32 ch) {
    return player->out_pan[ch];
}

void ADXT_SetOutPan(AdxtPlayer *player, s32 ch, s32 pan) {
    player->out_pan[ch] = pan;
    if (ch < player->max_channels) {
        TLobby__sub_803CBF50(player->rna_handle, ch, pan);
        return;
    }
    adxerr_report("E8101208 ADXT_SetOutPan: parameter error");
}

s32 TLobby__sub_803C9740(AdxtPlayer *player) {
    if (player->stat >= 2) {
        return player->input_state->send_with_offset4();
    }
    return 0;
}

s32 apply_if_v2(AdxtPlayer *player) {
    if (player->stat >= 2) {
        return player->input_state->notify_field_4();
    }
    return 0;
}

s32 TLobby__sub_803C97B8(AdxtPlayer *player) {
    if (player->stat >= 2) {
        return player->input_state->send_packet_by_id();
    }
    return 0;
}


extern "C" {
u32 lbl_805D4678 = 1;
}

inline void get_play_position_803C97F4(AdxtPlayer *p, s32 *pos, s32 *rate) {
    s32 st = p->stat;
    if (st == 3 || st == 4) {
        s32 total;
        *rate = p->input_state->notify_field_4();
        total = audio_stream_get_output_samples(p->input_state);
        *pos = p->played_samples + (total - (query_available_size(p->rna_handle) + (p->output_rings[0] != NULL ? p->output_rings[0]->interface->get_available(p->output_rings[0], 1) / 2 : 0)));
    } else if (st == 5) {
        *pos = p->input_state->send_packet_by_id();
        *rate = p->input_state->notify_field_4();
        *pos *= 16 / p->input_state->send_packet_by_id_2();
        *pos += p->played_samples;
    } else {
        *pos = 0;
        *rate = 1;
    }
    *pos += p->time_offset;
}

void TLobby__sub_803C97F4(AdxtPlayer *p, s32 *pos, s32 *rate) {
    s32 cur_pos;
    s32 cur_rate;
    s32 st;

    if (lbl_805D7560 == 0) {
        get_play_position_803C97F4(p, pos, rate);
        return;
    }
    lbl_805D756C = 0.0f;
    st = p->stat;
    if (st == 3 || st == 4) {
        if (p->pause_flag == 0) {
            *pos = p->base_time + (lbl_805D7540 - p->base_vblank) * 100;
        } else {
            *pos = p->base_time;
        }
        get_play_position_803C97F4(p, &cur_pos, &cur_rate);
        lbl_805D756C = 1000.0f * ((f32)cur_pos / (f32)cur_rate - (f32)*pos / (f32)lbl_805D7570);
        if (lbl_805D756C > 60.0f || lbl_805D756C < -60.0f) {
            if (lbl_805D4678 == 1) {
                s32 save = lbl_805D7560;
                lbl_805D7560 = 0;
                TLobby__sub_803C97F4(p, &cur_pos, &cur_rate);
                lbl_805D7560 = save;
                lbl_805D7568++;
            }
            p->base_time = (u32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
            p->base_vblank = lbl_805D7540;
        }
    } else if (st == 5) {
        cur_pos = p->input_state->send_packet_by_id();
        cur_rate = p->input_state->notify_field_4();
        cur_pos *= 16 / p->input_state->send_packet_by_id_2();
        *pos = (s32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
        *pos += p->base_time + 1;
    } else {
        *pos = 0;
    }
    *pos += p->time_offset;
    *rate = lbl_805D7570;
}

void adx_talk_set_rate_mode(s32 rate_mode) {
    if (rate_mode == 1) {
        lbl_805D7570 = 0x176A;
    } else if (rate_mode == 2) {
        lbl_805D7570 = 0x1388;
    }
    lbl_805D7560 = rate_mode;
}

s32 TLobby__sub_803C9CB0(AdxtPlayer *player) {
    return player->stat;
}
}
#pragma push
#pragma fp_contract on
void stop_audio_stream(AdxtPlayer *player) {
    if (player->stream_file != NULL) {
        stop_adx_stream(player->stream_file);
        adxstm_close(player->stream_file);
        if (player->input_sj != NULL) {
            player->input_sj->interface->reset(player->input_sj);
        }
        player->stream_file = NULL;
    }
    adx_lock();
    if ((s32)player->source_type == 4) {
        lsc_stop(player->lsc_stream);
        if (player->input_sj != NULL) {
            player->input_sj->interface->reset(player->input_sj);
        }
    }
    adx_lock();
    TLobby::dispatch_packet(player->rna_handle, 0);
    TLobby__sub_803CC030(player->rna_handle, 0);
    player->input_state->reset_flag();
    if ((s32)player->source_type == 2) {
        if (player->input_sj != NULL) {
            player->input_sj->interface->destroy(player->input_sj);
        }
    }
    player->input_sj = NULL;
    player->stat = 0;
    adx_unlock();
    adx_unlock();
}
#pragma pop


void TLobby__sub_803C9DB4(AdxtPlayer *player) {
    adx_lock();
    TLobby::dispatch_packet(player->rna_handle, 0);
    TLobby__sub_803CC030(player->rna_handle, 0);
    player->input_state->reset_flag();
    if ((s32)player->source_type == 2) {
        if (player->input_sj != NULL) {
            player->input_sj->interface->destroy(player->input_sj);
        }
    }
    player->input_sj = NULL;
    player->stat = 0;
    adx_unlock();
}

extern "C" {
void TLobby__sub_803C9E38(AdxtPlayer *player, SjRingBuffer *sj) {
    s32 i;
    if (player->stream_file != NULL) {
        stop_adx_stream(player->stream_file);
        adxstm_close(player->stream_file);
        if (player->input_sj != NULL) {
            player->input_sj->interface->reset(player->input_sj);
        }
        player->stream_file = NULL;
    }
    adx_lock();
    if ((s32)player->source_type == 4) {
        lsc_stop(player->lsc_stream);
        if (player->input_sj != NULL) {
            player->input_sj->interface->reset(player->input_sj);
        }
    }
    adx_lock();
    TLobby::dispatch_packet(player->rna_handle, 0);
    TLobby__sub_803CC030(player->rna_handle, 0);
    player->input_state->reset_flag();
    if ((s32)player->source_type == 2) {
        if (player->input_sj != NULL) {
            player->input_sj->interface->destroy(player->input_sj);
        }
    }
    player->input_sj = NULL;
    player->stat = 0;
    adx_unlock();
    adx_unlock();
    adx_lock();
    for (i = 0; i < player->max_channels; i++) {
        player->output_rings[i]->interface->reset(player->output_rings[i]);
    }
    player->input_state->set_param_and_notify(sj);
    player->input_sj = sj;
    audio_stream_start(player->input_state);
    player->stat = 1;
    player->source_type = 3;
    player->reserved_4C = 0;
    player->sync_mode_flag = 1;
    player->base_time = 0;
    player->base_vblank = lbl_805D7540;
    adx_unlock();
}

void configure_audio_stream_output(AdxtPlayer *player) {
    s32 i;
    SjRingBuffer *sj;
    AdxtPlayer *pp;
    adxstm_set_read_range(player->stream_file, player->min_sectors << 11, player->total_sectors << 11);
    set_adx_stream_end_sector(player->stream_file, 0x19);
    init_stream_position__6TLobbyFv(player->stream_file);
    sj = player->input_ring;
    pp = player;
    for (i = 0; i < player->max_channels; i++) {
        pp->output_rings[0]->interface->reset(pp->output_rings[0]);
        pp = (AdxtPlayer *)((u8 *)pp + 4);
    }
    player->input_state->set_param_and_notify(sj);
    player->input_sj = sj;
    audio_stream_start(player->input_state);
    player->stat = 1;
    player->reserved_4C = 0;
    player->started_playback = 0;
    player->total_pages = 0x7FFFFFFF;
    player->loop_end_sample = -1;
    player->base_time = 0;
    player->played_samples = 0;
    player->base_vblank = lbl_805D7540;
    player->source_type = 0;
}

void start_stream_playback(AdxtPlayer *player, SjRingBuffer *sj) {
    s32 i;
    for (i = 0; i < player->max_channels; i++) {
        player->output_rings[i]->interface->reset(player->output_rings[i]);
    }
    player->input_state->set_param_and_notify(sj);
    player->input_sj = sj;
    audio_stream_start(player->input_state);
    player->stat = 1;
    player->reserved_4C = 0;
    player->started_playback = 0;
    player->total_pages = 0x7FFFFFFF;
    player->loop_end_sample = -1;
    player->base_time = 0;
    player->played_samples = 0;
    player->base_vblank = lbl_805D7540;
}

void adx_destroy_stream_player(AdxtPlayer *player) {
    s32 i;
    if (player == NULL) {
        return;
    }
    if (lbl_805D7574 != NULL) {
        lbl_805D7574();
    }
    if ((s32)player->used == 1) {
        if (player->stream_file != NULL) {
            stop_adx_stream(player->stream_file);
            adxstm_close(player->stream_file);
            if (player->input_sj != NULL) {
                player->input_sj->interface->reset(player->input_sj);
            }
            player->stream_file = NULL;
        }
        adx_lock();
        if ((s32)player->source_type == 4) {
            lsc_stop(player->lsc_stream);
            if (player->input_sj != NULL) {
                player->input_sj->interface->reset(player->input_sj);
            }
        }
        adx_lock();
        TLobby::dispatch_packet(player->rna_handle, 0);
        TLobby__sub_803CC030(player->rna_handle, 0);
        player->input_state->reset_flag();
        if ((s32)player->source_type == 2) {
            if (player->input_sj != NULL) {
                player->input_sj->interface->destroy(player->input_sj);
            }
        }
        player->input_sj = NULL;
        player->stat = 0;
        adx_unlock();
        adx_unlock();
    }
    if (player->rna_handle != NULL) {
        unregister_si_polling(player->rna_handle);
    }
    if (player->input_state != NULL) {
        player->input_state->reset_entry();
    }
    if (player->stream_file != NULL) {
        adxstm_close(player->stream_file);
    }
    if (player->lsc_stream != NULL) {
        lsc_destroy(player->lsc_stream);
    }
    adx_lock();
    if (player->input_ring != NULL) {
        player->input_ring->interface->destroy(player->input_ring);
    }
    for (i = 0; i < player->max_channels; i++) {
        if (player->output_rings[i] != NULL) {
            player->output_rings[i]->interface->destroy(player->output_rings[i]);
        }
        if (player->extra_objs[i] != NULL) {
            player->extra_objs[i]->interface->destroy(player->extra_objs[i]);
        }
        if (player->extra_objs2[i] != NULL) {
            player->extra_objs2[i]->interface->destroy(player->extra_objs2[i]);
        }
    }
    if (player->amp != NULL) {
        player->amp->clear_entry();
    }
    memset(player, 0, sizeof(AdxtPlayer));
    player->used = 0;
    adx_unlock();
}

AdxtPlayer *adx_create_stream_player(s32 n, void *work, s32 size) {
    AdxtPlayer *c;
    s32 aligned = ((saddr)work + 0x3F) & ~0x3F;
    s32 rem = size - (aligned - (saddr)work);
    s32 i;
    s32 t;
    for (i = 0; i < 16; i++) {
        if (adx_stream_player_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = &adx_stream_player_pool[i];
    memset(c, 0, sizeof(AdxtPlayer));
    c->max_channels = n;
    t = (n * 0x2060) << 1;
    c->input_buf_addr = aligned + t;
    c->input_buf_size = (rem - t - 0x24) / 2048 * 2048;
    c->input_extra_size = 0x24;
    c->output_buf_addr = aligned;
    c->output_buf_size = 0x2000;
    c->output_stride = 0x2060;
    c->input_sj = NULL;
    c->input_ring = sj_ring_buffer_create((void *)c->input_buf_addr, c->input_buf_size, c->input_extra_size);
    if (c->input_ring == NULL) {
        adx_destroy_stream_player(c);
        return NULL;
    }
    for (i = 0; i < n; i++) {
        c->output_rings[i] = sj_ring_buffer_create((void *)(c->output_buf_addr + c->output_stride * i * 2), c->output_buf_size * 2, (c->output_stride - c->output_buf_size) * 2);
        if (c->output_rings[i] == NULL) {
            adx_destroy_stream_player(c);
            return NULL;
        }
    }
    if ((c->input_state = alloc_audio_stream_state(c->input_ring, n, c->output_rings)) == NULL) {
        adx_destroy_stream_player(c);
        return NULL;
    }
    if ((c->rna_handle = TLobby::run_step_5210(c->output_rings, n)) == NULL) {
        adx_destroy_stream_player(c);
        return NULL;
    }
    if ((c->lsc_stream = LSC_Create(c->input_ring)) == NULL) {
        adx_destroy_stream_player(c);
        return NULL;
    }
    c->server_freq = 0x3C;
    c->total_sectors = c->input_buf_size / 2048;
    c->min_sectors = 0.85 * c->total_sectors;
    c->output_vol = 0;
    for (i = 0; i < n; i++) {
        c->out_pan[i] = -0x80;
    }
    c->loop_flag = 1;
    c->reserved_54 = 0;
    c->reserved_58 = 0;
    c->reserved_5C = 0;
    c->error_code = 0;
    c->reserved_64 = 0;
    c->reserved_68 = 0;
    c->reserved_6A = 0;
    c->auto_repeat = 1;
    c->pause_flag = 0;
    c->time_offset = 0;
    c->sync_mode_flag = 1;
    c->used = 1;
    return c;
}
}


