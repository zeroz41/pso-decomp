#ifndef PSO_PLAYER_COUNTDOWNTIMER_H
#define PSO_PLAYER_COUNTDOWNTIMER_H

#include "types.h"

// Counts *timer down by one; returns 0 once it has run out (clamped at 0), else 1.
s32 decrement_timer(s32 *timer);

#endif
