#ifndef PSO_AUDIO_ADXSTREAM_H
#define PSO_AUDIO_ADXSTREAM_H

#include "types.h"
#include "pso/audio/AdxStreamFile.h"

// --- C functions defined in AdxStream.cpp ---
extern "C" {
void set_adx_stream_size_sectors(AdxStreamFile *file, s32 sectors);
s32 set_adx_max_read_sectors(AdxStreamFile *file, s32 sectors);
s32 get_adx_threshold_and_chunk(AdxStreamFile *file, s32 *threshold, s32 *chunk_size);
s32 get_adx_stream_position(const AdxStreamFile *file, s32 *position);
void stop_adx_stream(AdxStreamFile *file);
s32 get_adx_stream_status(const AdxStreamFile *file);
void adxstm_close(AdxStreamFile *file);
}
// --- end of C functions

extern AdxStreamFile adx_stream_read_requests[40];

#endif
