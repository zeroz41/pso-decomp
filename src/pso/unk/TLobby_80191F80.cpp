#include "types.h"
#include "pso/unk/TLobby.h"

extern s32 TLobby__data_805D5594;

s32 TLobby::is_idle() {
    return (u8)((u8) (TLobby__data_805D5594 == 0));
}
