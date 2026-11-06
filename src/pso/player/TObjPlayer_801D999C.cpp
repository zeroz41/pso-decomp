#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u8 TObjPlayer__sub_801D9514(s32, s32);
s32 is_invalid_slot__10TObjPlayerFUc(u8);
bool TObjPlayer::is_slot_within_limit(s32 arg0, s32 arg1, u8 arg2) {
    if (is_invalid_slot__10TObjPlayerFUc(arg2) != 0) {
        return 1;
    }
    return arg2 <= TObjPlayer__sub_801D9514(arg0, arg1);
}

}
