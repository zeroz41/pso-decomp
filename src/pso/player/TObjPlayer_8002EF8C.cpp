// TObjPlayer::calc_random_scaled starts the TU after the Player breakup TU: it follows that TU's __sinit in .text,
// and its int-to-float double (0x80435620) is the only .rodata it owns.
#include "types.h"
#include <stdlib.h>
#include "pso/player/TObjPlayer.h"

extern "C" {
extern const f32 lbl_805D8244;
extern const f32 lbl_805D8248;
}

s32 TObjPlayer::calc_random_scaled() {
    return (s32) (lbl_805D8248 * (lbl_805D8244 * (f32) rand()));
}
