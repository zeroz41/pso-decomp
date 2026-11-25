#ifndef PSO_AUDIO_ADX_CACHE_CONTROL_H
#define PSO_AUDIO_ADX_CACHE_CONTROL_H

#include "types.h"

extern "C" {
void adx_invalidate_cache(void *start, u32 length);
}

#endif
