#ifndef PSO_AUDIO_ADXSTREAMRUNTIME_H
#define PSO_AUDIO_ADXSTREAMRUNTIME_H

#include "pso/audio/AdxStream.h"
#include "types.h"
#include "pso/audio/AdxCallbacks.h"
#include "pso/audio/AdxExpand.h"
#include "pso/audio/AdxManager.h"
#include "pso/audio/AdxTalk.h"
#include "pso/audio/AdxtEntryAfs.h"

struct AudioStreamInputState;
struct LscStream;
struct SjRingBuffer;

struct AdxtPlayer;
struct AdxDecoderChannel;

// Defined in AdxStream.cpp.
extern "C" {
AdxStreamFile *ADXSTM_OpenFnameEx(const char *name, SjRingBuffer *sj);
AdxStreamFile *adxstm_open_fname_attr(const char *name, s32 mode, SjRingBuffer *sj);
AdxStreamFile *ADXSTM_OpenFnameRange(const char *name, s32 mode, s32 off, s32 nsect, SjRingBuffer *sj);
AdxStreamFile *ADXSTM_OpenFnameRangeExRt(const char *name, s32 mode, s32 off, s32 nsect, SjRingBuffer *sj);
}
void update_active_stream_reads(void);

#endif
