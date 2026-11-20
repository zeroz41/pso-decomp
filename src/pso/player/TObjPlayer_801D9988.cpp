#include "types.h"
#include "pso/player/TObjPlayer.h"

s32 TObjPlayer::is_invalid_slot(u8 arg0) {
    return (u8)((u8) (arg0 == 0xFF));
}
