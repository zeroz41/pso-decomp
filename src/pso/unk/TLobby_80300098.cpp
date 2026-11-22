#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby.h"

void TAdSelectCurGC::set_selection_index(s32 index) { selected_index = index; }
void TLobby__sub_803000A0(void) { TLobby__sub_802930A8(); TLobby::set_player_count(0); }
