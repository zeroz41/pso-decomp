#include "types.h"
#include "pso/audio/AixPlayer.h"

extern "C" {
void set_flag_4(AixDemuxer *demuxer, s8 continuous) {
    demuxer->continuous = continuous;
}

void set_client_slot(AixDemuxer *demuxer, s8 paused) {
    demuxer->paused = paused;
}
}
