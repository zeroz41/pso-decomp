#ifndef PSO_NETWORK_NETWORK_TIMER_H
#define PSO_NETWORK_NETWORK_TIMER_H

#include "types.h"

// Timer records store a callback invoked without arguments by the timer loop.
typedef void (*NetTimerCallback)(void);

#ifdef __cplusplus
extern "C" {
#endif
s16 NetRegisterTimer(s32 period, s16 locked, NetTimerCallback fn);
s32 NetUnregisterTimer(NetTimerCallback fn);
#ifdef __cplusplus
}
#endif

#endif
