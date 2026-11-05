#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TOKeyJungleMain.h"

extern "C" {

s32 send_6x75_quest_flag__6TLobbyFsss(int, s32, s32);
s32 set_story_flag_in_bank(s32, u16);

void TOKeyJungleMain::dispatch_by_phase(s32 arg0, u16 flag) {
    if (get_main_phase() == 0xF) {
        send_6x75_quest_flag__6TLobbyFsss(flag, 0, arg0);
        return;
    }
    set_story_flag_in_bank(arg0, flag);
}

}
