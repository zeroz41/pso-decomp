#include "types.h"
#include "pso/audio/AdxRnaStreamId.h"

extern "C" {

s32 gcrna_get_stream_id();

s32 adx_bridge_get_stream_id(int) {
    return gcrna_get_stream_id();
}

}
