#include "pso/audio/AdxStreamFile.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AixPlayer.h"
#include "pso/audio/AdxTalk.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxStreamLock.h"
#include "pso/system/CvFs.h"

extern "C" {
void update_file_stream_range(void *context);
AixPlayer aix_player_pool[4];
void aix_exec_server(void) {
    s32 i;
    aix_demuxer_exec_server();
    for (i = 0; i < 4; i++) {
        if ((s32)aix_player_pool[i].used == 1) {
            aix_exec_handle(&aix_player_pool[i]);
        }
    }
}

void aix_exec_handle(AixPlayer *player) {
    AixDemuxer *demuxer;
    AdxtPlayer **tracks;
    s32 i;
    s32 count;
    s32 offset;
    s32 size;
    tracks = player->tracks;
    demuxer = player->demuxer;
    if (player->state == 1) {
        if (get_demuxer_state(demuxer) == 2) {
            get_entry_pair(demuxer, player->segment = player->start_segment, &offset, &size);
            seek_adx_stream_sector(player->stream, (long long)(offset / 2048));
            set_adx_stream_end_sector(player->stream, (offset + size) / 2048);
            set_adx_stream_completion(player->stream, update_file_stream_range, player);
            set_client_slot(demuxer, 0);
            if (player->loop == 1 || player->continue_segments == 1) {
                set_flag_4(demuxer, 1);
            }
            count = get_demuxer_layer_count(demuxer);
            for (i = 0; i < count; i++) {
                set_sync_mode_flag(player->tracks[i], 1);
                adxt_start_sj(tracks[i], player->track_inputs[i]);
            }
            player->state = 2;
        }
    } else if (player->state == 2) {
        if (get_demuxer_state(demuxer) == 3) {
            for (i = 0; i < player->track_count; i++) {
                s32 r = adxt_get_stat(player->tracks[i]);
                if (r != 5 && r != 0) {
                    break;
                }
            }
            if (i == player->track_count) {
                player->state = 3;
            }
        }
    }
    for (i = 0; i < player->track_count; i++) {
        if (get_error_code(player->tracks[i]) == -1) {
            player->state = 4;
            break;
        }
    }
}

}

extern "C" void update_file_stream_range(void *context) {
    AixPlayer *player = static_cast<AixPlayer *>(context);
    s32 offset;
    s32 size;

    player->segment++;
    if (player->loop == 1 && player->segment >= player->loop_end) {
        player->segment = player->loop_start;
    }
    if (player->continue_segments == 1 && player->segment < get_demuxer_segment_count(player->demuxer)) {
        aix_interrupt_lock_enter();
        get_entry_pair(player->demuxer, player->segment, &offset, &size);
        seek_adx_stream_sector(player->stream, offset / 2048);
        set_adx_stream_end_sector(player->stream, (offset + size) / 2048);
        init_adx_stream_position(player->stream);
        adx_interrupt_lock_leave();
    }
}

CvFsErrorCallback cvfs_completion_callback;
s32 cvfs_completion_context;

void cvFsEntryErrFunc(CvFsErrorCallback callback, s32 context) {
    if (callback == NULL) {
        cvfs_completion_callback = NULL;
        cvfs_completion_context = 0;
        return;
    }
    cvfs_completion_callback = callback;
    cvfs_completion_context = context;
}
