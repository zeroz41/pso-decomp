#ifndef PSO_AUDIO_GCRNAMUSYXSTREAM_H
#define PSO_AUDIO_GCRNAMUSYXSTREAM_H

#include "types.h"

struct SND_ADPCMSTREAM_INFO;

extern "C" {
void sndStreamMixParameterEx(u32 stream_id, u8 volume, u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b);
u32 sndStreamActivate(u32 stream_id);
void sndStreamDeactivate(u32 stream_id);
void sndStreamFree(u32 stream_id);
void sndStreamFrq(u32 stream_id, u32 frequency);
u32 sndStreamAllocEx(u8 priority, void *buffer, u32 samples, u32 frequency, u8 volume,
                     u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b, u8 studio, u32 flags,
                     u32 (*callback)(void *, u32, void *, u32, u32), u32 user,
                     SND_ADPCMSTREAM_INFO *adpcm_info);
}

#endif
