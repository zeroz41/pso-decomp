#ifndef PSO_AUDIO_ADXSTREAM_H
#define PSO_AUDIO_ADXSTREAM_H

#include "types.h"
#include "pso/audio/AdxStreamFile.h"

// --- C functions defined in AdxStream.cpp ---
extern "C" {
void TLobby__sub_803C8514(AdxStreamFile *file, s32 sectors);
s32 TLobby__sub_803C8578(AdxStreamFile *file, s32 sectors);
s32 TLobby__sub_803C8594(AdxStreamFile *file, s32 *threshold, s32 *chunk_size);
s32 TLobby__sub_803C85AC(const AdxStreamFile *file, s32 *position);
void TLobby__sub_803C89C4(AdxStreamFile *file);
s32 TLobby__sub_803C8B2C(const AdxStreamFile *file);
void TLobby__sub_803C8B38(AdxStreamFile *file);
}
// --- end of C functions

extern AdxStreamFile adx_stream_read_requests[40];

#endif
