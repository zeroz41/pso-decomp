// TObjPlayer::calc_random_scaled starts the TU after the Player breakup TU: it follows that TU's __sinit in .text,
// and its int-to-float double (0x80435620) is the only .rodata it owns.
#include "types.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include <stdlib.h>
#include "pso/player/TObjPlayer.h"


s32 TObjPlayer::calc_random_scaled() {
    return (s32) (random_angle_range * (random_unit_scale * (f32) rand()));
}
