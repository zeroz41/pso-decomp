#ifndef PSO_AUDIO_ADXTENTRYAFS_H
#define PSO_AUDIO_ADXTENTRYAFS_H

#include "types.h"

struct AdxtPlayer;

extern "C" {
s32 get_stream_queued_count(AdxtPlayer *player);
void adxt_start_seamless(AdxtPlayer *player);
void adxt_entry_count_decrement(void);
void adxt_entry_count_increment(void);
}

void ADXT_EntryAfs(AdxtPlayer *player, s32 partition_id, s32 file_id);

#endif
