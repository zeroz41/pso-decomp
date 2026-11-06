#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int clear_record_flags_b__6TLobbyFv(void*);

int TLobby::init_sub_state() { return clear_record_flags_b__6TLobbyFv(this); }

}
