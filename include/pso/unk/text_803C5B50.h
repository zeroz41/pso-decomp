#ifndef PSO_UNK_TEXT_803C5B50_H
#define PSO_UNK_TEXT_803C5B50_H

#include "types.h"

struct AdxtPlayer;

// --- C functions defined in text_803C5B50.cpp ---
extern "C" {
s32 get_stream_queued_count(AdxtPlayer *player);
void TLobby__sub_803C5D24(AdxtPlayer *player);
void TLobby__sub_803C5E58(void);
void TLobby__sub_803C5E68(void);
}
// --- end of C functions

void ADXT_EntryAfs(AdxtPlayer *player, s32 partition_id, s32 file_id);

#endif
