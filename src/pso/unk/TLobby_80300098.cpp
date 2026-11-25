#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/network/TLobby.h"

void TAdSelectCurGC::set_selection_index(s32 index) { selected_index = index; }
void TLobby__sub_803000A0(void) { clear_challenge_and_split_screen_flags(); TLobby::set_player_count(0); }
