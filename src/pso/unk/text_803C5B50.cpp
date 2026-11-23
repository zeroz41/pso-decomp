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

// Stream object view: its SjRingBuffer lives at 0x14 and is the copy target
// when a decoded ADX chunk is drained from the source ring.
struct AdxRingBufferHost { u8 pad_0[0x14]; SjRingBuffer *ringBuffer; };

extern "C" {
extern u8 adx_stream_ring_buffer_storage[];
extern u8 adx_stream_ring_buffer[];

void TLobby__sub_803C5B50(AdxRingBufferHost *arg0, s32 arg1, s32 arg2, s32 arg3) {
    SjRingBuffer *arr[2];
    SjChunk b1;
    SjChunk b2;
    SjRingBuffer *src;
    SjRingBuffer *dst;
    u8 *ctx;
    TLobby::clear_buffer_1680();
    src = sj_ring_buffer_create(adx_stream_ring_buffer, 0x400, 0);
    arr[0] = sj_ring_buffer_create(adx_stream_ring_buffer_storage, 0x400, 0);
    arr[1] = sj_ring_buffer_create(adx_stream_ring_buffer_storage + 0x20, 0x400, 0);
    dst = arg0->ringBuffer;
    ctx = TLobby__sub_803C61C4(2, arr, src);
    TLobby__sub_803C60F0(ctx, arg1, arg2, arg3);
    TLobby__sub_803C6118(ctx);
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
    TLobby__sub_803C610C(ctx);
    TLobby__sub_803C6138((S_803C6138 *)ctx);
    src->interface->destroy(src);
    arr[1]->interface->destroy(arr[1]);
    arr[0]->interface->destroy(arr[0]);
    TLobby::clear_net_buffer_1680();
}

void TLobby__sub_803C5D00(u8 *arg0) {
    lsc_get_queued_stream_count(((Ent_803C9608 *)arg0)->f94);
}

s32 lbl_805D7548;

void TLobby__sub_803C5D24(u8 *lobby) {
    struct LobbyStreamFields { u8 pad_0[2]; s8 field_2; u8 pad_3[13]; s32 field_10; void ** field_14; u8 pad_18[38]; s16 field_3E; u8 pad_40[84]; u8 * field_94; s8 field_98; };
    void **temp_r3;
    u8 *temp_r31;
    u8 *temp_r4;
    temp_r31 = (u8 *)(((LobbyStreamFields*)lobby)->field_94);
    TLobby__sub_803C9DB4(lobby);
    TLobby::init_once();
    ((TLobby *)lobby)->start_stream_playback(((LobbyStreamFields*)lobby)->field_10);
    temp_r3 = (void **)(((LobbyStreamFields*)lobby)->field_14);
    temp_r4 = (u8 *)(*temp_r3);
    (*(s32 (**)(void **, void *))((s8 *)temp_r4 + 0x14))(temp_r3, temp_r4);
    ((LobbyStreamFields*)lobby)->field_2 = 4;
    lsc_set_min_buffer_bytes((LscStream*)temp_r31, ((LobbyStreamFields*)lobby)->field_3E << 0xB);
    lsc_start((LscStream*)temp_r31);
    ((LobbyStreamFields*)lobby)->field_98 = 1;
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
    h = ((Ent_803C9608 *)arg0)->f94;
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
