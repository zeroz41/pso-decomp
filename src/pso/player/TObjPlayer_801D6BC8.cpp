#include "types.h"
#include "pso/player/TObjPlayer.h"

s32 TObjPlayer::decrement_timer(s32 *timer) {
    *timer -= 1;
    if ((s32) *timer < 0) {
        *timer = 0;
        return 0;
    }
    return 1;
}
