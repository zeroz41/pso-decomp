#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int TLobby__sub_8020B47C(void*);

int TLobby::sync_game_state() { return TLobby__sub_8020B47C(this); }

}
