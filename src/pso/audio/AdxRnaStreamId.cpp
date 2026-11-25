#include "types.h"
#include "pso/audio/AdxRnaStreamId.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {

s32 adx_bridge_get_stream_id(GcrnaStream *stream, s32 channel) {
    return gcrna_get_stream_id(stream, channel);
}

}
