#ifndef PSO_AUDIO_ADXRNASTREAMID_H
#define PSO_AUDIO_ADXRNASTREAMID_H

#include "types.h"

struct GcrnaStream;

extern "C" {
s32 adx_bridge_get_stream_id(GcrnaStream *stream, s32 channel);
}

#endif
