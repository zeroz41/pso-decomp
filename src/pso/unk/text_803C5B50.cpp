#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSThread.h>
#include "pso/unk/text_803C5B50.h"
#include "pso/unk/TLobby.h"
#undef PSO_SDK_COMPACT_MATH
#include <string.h>
#include "pso/audio/AdxEncoder.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/LscStream.h"

#include "types.h"

#pragma readonly_strings on

extern "C" {
extern u8 adx_stream_ring_buffer_storage[];
extern u8 adx_stream_ring_buffer[];

void TLobby__sub_803C5B50(AdxStreamPlayer *player, s32 arg1, s32 arg2, s32 arg3) {
    SjRingBuffer *arr[2];
    SjChunk b1;
    SjChunk b2;
    SjRingBuffer *src;
    SjRingBuffer *dst;
    AdxEncoder *enc;
    TLobby::clear_buffer_1680();
    src = sj_ring_buffer_create(adx_stream_ring_buffer, 0x400, 0);
    arr[0] = sj_ring_buffer_create(adx_stream_ring_buffer_storage, 0x400, 0);
    arr[1] = sj_ring_buffer_create(adx_stream_ring_buffer_storage + 0x20, 0x400, 0);
    dst = player->input;
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
    TLobby::clear_net_buffer_1680();
}

void TLobby__sub_803C5D00(AdxStreamPlayer *player) {
    lsc_get_queued_stream_count(player->lsc);
}

s32 lbl_805D7548;

void TLobby__sub_803C5D24(AdxStreamPlayer *player) {
    LscStream *lsc;
    lsc = player->lsc;
    TLobby__sub_803C9DB4((u8 *)player);
    TLobby::init_once();
    ((TLobby *)player)->start_stream_playback(player->file_buffer);
    player->input->interface->reset(player->input);
    player->play_mode = 4;
    lsc_set_min_buffer_bytes(lsc, player->min_sectors << 0xB);
    lsc_start(lsc);
    player->lsc_started = 1;
    TLobby::release_ref();
}
}
static const char lbl_8047C5D8[] = "E0071301 ADXT_EntryAfs: can't entry ";
extern char music_stream_afs_filename_buffer[];
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2);
void append_music_stream_segment(u8 *arg0, s32 arg1, s32 arg2) {
    char buf[16];
    s32 a;
    s32 b;
    s32 c;
    LscStream *h;
    h = ((AdxStreamPlayer *)arg0)->lsc;
    if (TLobby::get_afs_file_info(arg1, arg2, music_stream_afs_filename_buffer, &a, &b, &c) == 0) {
        lsc_enqueue_range(h, music_stream_afs_filename_buffer, a, b, c);
        return;
    }
    TLobby::format_number_pair(arg1, arg2, buf, 0x10);
    TLobby::report_adx_error(lbl_8047C5D8, buf);
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
