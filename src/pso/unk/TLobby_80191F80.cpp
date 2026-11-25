#include "types.h"
#include "pso/network/TLobby.h"


s32 TLobby::is_idle() {
    return (u8)((u8) (lobby_state == 0));
}
