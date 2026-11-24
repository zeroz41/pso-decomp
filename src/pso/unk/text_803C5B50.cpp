#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSThread.h>
#include "pso/audio/AdxError.h"
#include "pso/audio/AdxLock.h"
#include "pso/unk/text_803C5B50.h"
#include "pso/unk/TLobby.h"
#undef PSO_SDK_COMPACT_MATH
#include <string.h>
#include "pso/audio/AdxEncoder.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/LscStream.h"

#include "types.h"

#pragma readonly_strings on

extern "C" {
extern u8 adx_stream_ring_buffer_storage[];
extern u8 adx_stream_ring_buffer[];

void TLobby__sub_803C5B50(AdxtPlayer *player, s32 arg1, s32 arg2, s32 arg3) {
    SjRingBuffer *arr[2];
    SjChunk b1;
    SjChunk b2;
    SjRingBuffer *src;
    SjRingBuffer *dst;
    AdxEncoder *enc;
    adx_encoder_pool_init();
    src = sj_ring_buffer_create(adx_stream_ring_buffer, 0x400, 0);
    arr[0] = sj_ring_buffer_create(adx_stream_ring_buffer_storage, 0x400, 0);
    arr[1] = sj_ring_buffer_create(adx_stream_ring_buffer_storage + 0x20, 0x400, 0);
    dst = player->input_sj;
    enc = TLobby__sub_803C61C4(2, arr, src);
    TLobby__sub_803C60F0(enc, arg1, arg2, arg3);
    TLobby__sub_803C6118(enc);
    TLobby__sub_803C5E78();
    src->interface->get_chunk(src, 1, 0x400, &b1);
    if (b1.size == 0) {
        for (;;) {
        }
    }
    dst->interface->get_chunk(dst, 0, b1.size, &b2);
    if (b2.size < b1.size) {
        for (;;) {
        }
    }
    memcpy(b2.data, b1.data, b1.size);
    src->interface->put_chunk(src, 0, &b1);
    dst->interface->put_chunk(dst, 1, &b2);
    TLobby__sub_803C610C(enc);
    TLobby__sub_803C6138(enc);
    src->interface->destroy(src);
    arr[1]->interface->destroy(arr[1]);
    arr[0]->interface->destroy(arr[0]);
    adx_encoder_pool_finish();
}

s32 TLobby__sub_803C5D00(AdxtPlayer *player) {
    return lsc_get_queued_stream_count(player->lsc_stream);
}

s32 lbl_805D7548;

void TLobby__sub_803C5D24(AdxtPlayer *player) {
    LscStream *lsc;
    lsc = player->lsc_stream;
    TLobby__sub_803C9DB4(player);
    adx_lock();
    start_stream_playback(player, player->input_ring);
    player->input_sj->interface->reset(player->input_sj);
    player->source_type = 4;
    lsc_set_min_buffer_bytes(lsc, player->min_sectors << 0xB);
    lsc_start(lsc);
    player->sync_mode_flag = 1;
    adx_unlock();
}
}
static const char lbl_8047C5D8[] = "E0071301 ADXT_EntryAfs: can't entry ";
extern char music_stream_afs_filename_buffer[];
void ADXT_EntryAfs(AdxtPlayer *player, s32 partition_id, s32 file_id) {
    char buf[16];
    s32 a;
    s32 b;
    s32 c;
    LscStream *h;
    h = player->lsc_stream;
    if (TLobby::get_afs_file_info(partition_id, file_id, music_stream_afs_filename_buffer, &a, &b, &c) == 0) {
        lsc_enqueue_range(h, music_stream_afs_filename_buffer, a, b, c);
        return;
    }
    adxerr_format_id_pair(partition_id, file_id, buf, 0x10);
    adxerr_report_pair(lbl_8047C5D8, buf);
}


void TLobby__sub_803C5E58(void) {
    lbl_805D7548 -= 1;
}

void TLobby__sub_803C5E68(void) {
    lbl_805D7548 += 1;
}


u8 adx_stream_ring_buffer_storage[0x40];
u8 adx_stream_ring_buffer[0x400];
char music_stream_afs_filename_buffer[0x120];
