#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int rebuild_entry__6TLobbyFv(void);
int init_sub_state__6TLobbyFv(void);

void TLobby::init_sub_objects() { init_sub_state__6TLobbyFv(); rebuild_entry__6TLobbyFv(); }

}
