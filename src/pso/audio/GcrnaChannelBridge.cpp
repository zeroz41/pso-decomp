#include "types.h"
#include "pso/audio/GcrnaChannelBridge.h"

void TLobby__sub_803D4704(GcrnaStream *stream, s32 stream_count) {
    if (stream != NULL) {
        stream->stream_count = stream_count;
    }
}
