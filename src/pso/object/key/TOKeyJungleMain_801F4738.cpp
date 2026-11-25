#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/network/TLobby.h"

extern "C" {

s32 set_story_flag_in_bank(s32, u16);

void TOKeyJungleMain::dispatch_by_phase(s32 phase, u16 flag) {
    if (get_main_phase() == 0xF) {
        TLobby::send_6x75_quest_flag(flag, 0, phase);
        return;
    }
    set_story_flag_in_bank(phase, flag);
}

}
