#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/network/TLobby.h"

void TAdSelectCurGC::set_selection_index(s32 index) { selected_index = index; }
void reset_multi_sel_rule(void) { clear_challenge_and_split_screen_flags(); TLobby::set_player_count(0); }
