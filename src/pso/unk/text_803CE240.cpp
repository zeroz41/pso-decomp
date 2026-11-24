#include "pso/audio/AdxStreamFile.h"
#include "types.h"
#include "pso/unk/text_803CD99C.h"
#include "pso/unk/text_803CE240.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AixPlayer.h"

extern "C" {
void TLobby__sub_803C9E38(TLobby *, VObj_803C9E38 *);
s32 TLobby__sub_803C9CB0(TLobby *);
void update_file_stream_range(void *context);
s32 get_field_60__6TLobbyFv(TLobby *);
AixPlayer aix_player_pool[4];
void TLobby__sub_803CE240(void) {
    s32 i;
    TLobby__sub_803CD99C();
    for (i = 0; i < 4; i++) {
        if ((s32)aix_player_pool[i].used == 1) {
            TLobby__sub_803CE2A0(&aix_player_pool[i]);
        }
    }
}

void TLobby__sub_803CE2A0(AixPlayer *player) {
    AixDemuxer *demuxer;
    TLobby **tracks;
    s32 i;
    s32 count;
    s32 offset;
    s32 size;
    tracks = player->tracks;
    demuxer = player->demuxer;
    if (player->state == 1) {
        if (TLobby__sub_803CE1F4(demuxer) == 2) {
            get_entry_pair(demuxer, player->segment = player->start_segment, &offset, &size);
            seek_adx_stream_sector(player->stream, (long long)(offset / 2048));
            set_adx_stream_end_sector(player->stream, (offset + size) / 2048);
            set_adx_stream_completion(player->stream, update_file_stream_range, player);
            set_client_slot(demuxer, 0);
            if ((s32)player->loop == 1 || (s32)player->continue_segments == 1) {
                set_flag_4(demuxer, 1);
            }
            count = TLobby__sub_803CE1D8(demuxer);
            for (i = 0; i < count; i++) {
                player->tracks[i]->set_field98(1);
                TLobby__sub_803C9E38(tracks[i], player->track_inputs[i]);
            }
            player->state = 2;
        }
    } else if (player->state == 2) {
        if (TLobby__sub_803CE1F4(demuxer) == 3) {
            for (i = 0; i < player->track_count; i++) {
                s32 r = TLobby__sub_803C9CB0(player->tracks[i]);
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
        if (get_field_60__6TLobbyFv(player->tracks[i]) == -1) {
            player->state = 4;
            break;
        }
    }
}

}
