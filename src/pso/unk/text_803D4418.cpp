#include "types.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {
u32 gcrna_get_stream_id(GcrnaStream *stream, s32 channel) {
    return stream->stream_ids[channel];
}

}
