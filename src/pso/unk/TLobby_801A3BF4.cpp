#include "types.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/unk/TLobby.h"

void TLobby::reset_quest_counter() { lobby_quest_progress_flag = 0; }

void TLobby::set_cleanup_flag() { quest_warp_enabled = 1; }
