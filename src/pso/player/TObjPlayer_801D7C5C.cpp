#include "types.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TMainCursor_8013DEF8.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_result_entry__18TChallenge4PResultFPv(s32, s32);
s32 can_use_palette_action_for_entry__10TObjPlayerFUl(s32, s32);

void TObjPlayer::update_party_cursors(saddr arg0, s32 arg1) {
    s32 var_r31;
    s32 i;
    saddr temp_r29;

    i = 0;
    var_r31 = 0;
    do {
        s32 call_r3 = (saddr)TObjPlayer__sub_801D84B0((s32 *)arg0);
        temp_r29 = call_r3 + var_r31;
        if (get_result_entry__18TChallenge4PResultFPv(arg1, i) == 0) {
            TObjPlayer__sub_8013DEF8((u8 *)temp_r29);
        } else if (can_use_palette_action_for_entry__10TObjPlayerFUl(temp_r29, arg1) != 0) {
            TMainCursor__sub_8013DFC4((u8 *)temp_r29);
        } else {
            TObjPlayer__sub_8013DEF8((u8 *)temp_r29);
        }
        i += 1;
        var_r31 += 4;
    } while (i < 4);
}

}
