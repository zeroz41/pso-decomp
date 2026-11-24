#include <dolphin/os/OSThread.h>
#include "pso/audio/AdxError.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

void ADXT_StartMemIdx(AdxtPlayer *player, u8 *table_data, s32 entry_index) {
    SjRingBuffer *ring_handle;
    stop_audio_stream(player);
    if (entry_index >= ((AdxtMemTableEntry *)table_data)[0].length || entry_index < 0) {
        return;
    }
    adx_lock();
    ring_handle = (SjRingBuffer *)sj_memory_buffer_create(table_data + *(s32 *)(table_data + (entry_index + 1) * 8), 0x40000000);
    if (ring_handle == 0) {
        adx_unlock();
        adxerr_report("E8101207: can't create sj (ADXT_StartMemIdx)");
        return;
    }
    start_stream_playback(player, ring_handle);
    player->source_type = 2;
    player->sync_mode_flag = 0;
    adx_unlock();
}

void ADXT_StartFname(AdxtPlayer *player, const char *name) {
    stop_audio_stream(player);
    adx_lock();
    if ((player->stream_file = ADXSTM_OpenFnameEx(name, (saddr)player->input_ring)) == 0) {
        adx_unlock();
        adxerr_report_pair("E8101205 ADXT_StartFname: can't open ", name);
        player->error_code = -1;
        player->stat = 6;
    } else {
        configure_audio_stream_output(player);
        player->sync_mode_flag = 0;
        adx_unlock();
    }
}

