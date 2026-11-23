#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 TObjPlayer__sub_801D9514(s32, s32);
bool TObjPlayer::is_slot_within_limit(s32 cls, s32 tech, u8 level) {
    if (TObjPlayer::is_invalid_slot(level) != 0) {
        return 1;
    }
    return level <= TObjPlayer__sub_801D9514(cls, tech);
}

}
