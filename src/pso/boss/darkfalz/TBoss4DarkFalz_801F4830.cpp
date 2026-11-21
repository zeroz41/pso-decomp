#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

extern "C" {

s32 send_6x75_quest_flag_cur_difficulty__6TLobbyFss(int, s32);
s32 set_story_flag(u16);

void set_story_flag_or_send_quest_flag(u16 flag) {
    if (get_main_phase() == 0xF) {
        send_6x75_quest_flag_cur_difficulty__6TLobbyFss(flag, 0);
        return;
    }
    set_story_flag(flag);
}

}
