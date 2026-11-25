#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListVM.h"


void THunterGuildSeqOffline::set_state_close2(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(0xC, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 0;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

    extern int evt2_random_enemies_mode;
void THunterGuildSeqOffline::set_enemy_mode_5(TObject *) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 5; TKeyBoardControl__sub_8000F950(); }

void THunterGuildSeqOffline::set_enemy_mode_1(TObject *) { TLobby::set_enemy_mode_flag(); evt2_random_enemies_mode = 1; TKeyBoardControl__sub_8000F950(); }
