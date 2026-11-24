#include "types.h"
#include "pso/unk/TLobby.h"

void clear_lobby_name() {
    s32 i;
    for (i = 0; i < 0x14; i++) {
        lobby_name[i] = 0;
    }
}
