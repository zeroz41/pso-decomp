#include "types.h"
#include "pso/unk/TLobby.h"

extern void *TLobby__protocol_instance;

void TLobby::clear_counters() {
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBC04) = 0;
    *(s32 *)((s8 *)TLobby__protocol_instance + 0xBC18) = 0;
}
