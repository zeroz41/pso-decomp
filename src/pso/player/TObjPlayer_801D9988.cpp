#include "types.h"
#include "pso/player/TObjPlayer.h"

s32 TObjPlayer::is_invalid_slot(u8 level) {
    return (u8)((u8) (level == 0xFF));
}
