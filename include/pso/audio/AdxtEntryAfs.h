#ifndef PSO_AUDIO_ADXTENTRYAFS_H
#define PSO_AUDIO_ADXTENTRYAFS_H

#include "types.h"
#include "pso/audio/AdxStreamRuntime.h"

// --- C functions defined in AdxtEntryAfs.cpp ---
extern "C" {
s32 get_stream_queued_count(AdxtPlayer *player);
void TLobby__sub_803C5D24(AdxtPlayer *player);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
}
// --- end of C functions

#endif
