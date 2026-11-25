#include "types.h"
#include "pso/audio/AixPlayer.h"

s32 get_demuxer_layer_count(AixDemuxer *demuxer) {
    return demuxer->header.layer_count;
}
