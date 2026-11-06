#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void set_state__10TNpcPlayerFPvs(void *, s16);
void set_type__10TNpcPlayerFPvs(void *, s16);
s32 TObjPlayer__sub_801D9E18(s32, s32);
void TObjPlayer::set_slot_type_state(s32 arg0, s32 arg1, s16 arg2, s16 arg3) {
    u8 *temp_r3;
    temp_r3 = (u8 *)(TObjPlayer__sub_801D9E18(arg0, arg1));
    set_type__10TNpcPlayerFPvs(temp_r3, arg2);
    set_state__10TNpcPlayerFPvs(temp_r3, arg3);
}

}
