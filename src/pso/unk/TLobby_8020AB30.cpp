#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int clear_record_flags_a__6TLobbyFv(void*);

int TLobby::rebuild_entry() { return clear_record_flags_a__6TLobbyFv(this); }

}
