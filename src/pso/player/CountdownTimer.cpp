#include "types.h"
#include "pso/player/CountdownTimer.h"

s32 decrement_timer(s32 *timer) {
    *timer -= 1;
    if ((s32) *timer < 0) {
        *timer = 0;
        return 0;
    }
    return 1;
}
