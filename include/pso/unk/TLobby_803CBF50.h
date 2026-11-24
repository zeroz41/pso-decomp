#ifndef PSO_UNK_TLOBBY_803CBF50_H
#define PSO_UNK_TLOBBY_803CBF50_H

#include "types.h"

struct GcrnaStream;

extern "C" {
void TLobby__sub_803CBF50(GcrnaStream *stream, s32 ch, s32 pan);
void trigger_sub_task(GcrnaStream *stream, s32 volume);
void TLobby__sub_803CBF90(GcrnaStream *stream, s32 rate);
void TLobby__sub_803CBFB0(GcrnaStream *stream, s32 stream_count);
s32 TLobby__sub_803CBFF0(GcrnaStream *stream);
s32 query_available_size(GcrnaStream *stream);
void TLobby__sub_803CC030(GcrnaStream *stream, s32 enabled);
}

#endif
