#include "types.h"
#include "pso/unk/TLobby.h"

    extern int lobby_quest_progress_flag;
void TLobby::reset_quest_counter() { lobby_quest_progress_flag = 0; }

    extern int quest_warp_enabled;
void TLobby::set_cleanup_flag() { quest_warp_enabled = 1; }
