#include "types.h"
#include "pso/unk/TLobby_8020B334.h"
#include "pso/unk/TLobby.h"

extern "C" {

int get_matching_object__6TLobbyFv(void*);
int get_object_count__6TLobbyFv(void*);

int TLobby::resolve_matching_object() { return get_matching_object__6TLobbyFv(this); }
int get_object_count__6TLobbyFPv(void* p) { return get_object_count__6TLobbyFv(p); }

}
