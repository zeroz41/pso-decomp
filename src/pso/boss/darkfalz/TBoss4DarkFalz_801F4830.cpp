#include "types.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/network/TLobby.h"

extern "C" {

s32 set_story_flag(u16);

void set_story_flag_or_send_quest_flag(u16 flag) {
    if (get_main_phase() == 0xF) {
        TLobby::send_6x75_quest_flag_cur_difficulty(flag, 0);
        return;
    }
    set_story_flag(flag);
}

}
