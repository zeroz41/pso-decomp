#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 rand();


s32 TObjPlayer::is_rand_below_threshold() {
    return (u32)__cntlzw(((3.0517578e-05f * (f32) rand()) < 0.3f)) >> 5;
}

}
