#include <dolphin/os/OSThread.h>
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

static inline AdxtPlayer *adxt_player_from_lobby(void *self) {
    return (AdxtPlayer *)self;
}

void TLobby::adxt_start_mem_idx(u8 *table_data, s32 entry_index) {
    AdxtPlayer *player = adxt_player_from_lobby(this);
    s32 ring_handle;
    stop_audio_stream((u8 *)player);
    if (entry_index >= ((AdxtMemTableEntry *)table_data)[0].length || entry_index < 0) {
        return;
    }
    TLobby::init_once();
    ring_handle = (saddr)sj_memory_buffer_create(table_data + *(s32 *)(table_data + (entry_index + 1) * 8), 0x40000000);
    if (ring_handle == 0) {
        TLobby::release_ref();
        TLobby::notify_error("E8101207: can't create sj (ADXT_StartMemIdx)");
        return;
    }
    start_stream_playback(ring_handle);
    player->source_type = 2;
    player->sync_mode_flag = 0;
    TLobby::release_ref();
}

void start_audio_stream_file(AdxtPlayer *player, const char *name) {
    stop_audio_stream((u8 *)player);
    TLobby::init_once();
    if ((player->stream_file = ADXSTM_OpenFnameEx(name, (saddr)player->input_ring)) == 0) {
        TLobby::release_ref();
        TLobby::report_adx_error("E8101205 ADXT_StartFname: can't open ", name);
        player->error_code = -1;
        player->stat = 6;
    } else {
        configure_audio_stream_output(player);
        player->sync_mode_flag = 0;
        TLobby::release_ref();
    }
}

