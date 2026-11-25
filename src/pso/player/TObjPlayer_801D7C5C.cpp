#include "types.h"
#include "pso/player/TObjPlayer_801D84A8.h"
#include "pso/ui/hud/TMainCursor_8013DEF8.h"
#include "pso/ui/hud/TMainCursor_8013DF5C.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 get_result_entry__18TChallenge4PResultFPv(s32, s32);
s32 can_use_palette_action_for_entry__10TObjPlayerFP10TObjPlayer(s32, s32);

void TObjPlayer::update_party_cursors(saddr cursors, s32 result) {
    s32 offset;
    s32 i;
    saddr entry;

    i = 0;
    offset = 0;
    do {
        s32 base = (saddr)TObjPlayer__sub_801D84B0((s32 *)cursors);
        entry = base + offset;
        if (get_result_entry__18TChallenge4PResultFPv(result, i) == 0) {
            set_action_channel_inactive((u8 *)entry);
        } else if (can_use_palette_action_for_entry__10TObjPlayerFP10TObjPlayer(entry, result) != 0) {
            set_action_channel_active((u8 *)entry);
        } else {
            set_action_channel_inactive((u8 *)entry);
        }
        i += 1;
        offset += 4;
    } while (i < 4);
}

}
