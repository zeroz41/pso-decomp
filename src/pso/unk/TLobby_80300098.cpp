#include "types.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/unk/TLobby_80300098.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/TLobby.h"

void TLobby::set_ad_field(s32 v) { *(s32*)((char*)this + 0xa4) = v; }
void TLobby__sub_803000A0(void) { TLobby__sub_802930A8(); set_player_count__6TLobbyFi(0); }
