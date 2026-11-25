#include "types.h"
#include "pso/audio/AixPlayer.h"

extern "C" {
s32 get_demuxer_state(AixDemuxer *demuxer) {
    return demuxer->state;
}

}
