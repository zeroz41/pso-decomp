#ifndef PSO_AUDIO_ADXCALLBACKS_H
#define PSO_AUDIO_ADXCALLBACKS_H

#include "types.h"

typedef void (*AdxTransitionCallback)(s32 context);
typedef s32 (*AdxWorkerCallback)(s32 context);
typedef void (*AdxMessageCallback)(s32 context, const char *message);

#endif
