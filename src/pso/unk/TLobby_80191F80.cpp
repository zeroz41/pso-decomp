#include "types.h"
#include "pso/unk/TLobby.h"


s32 TLobby::is_idle() {
    return (u8)((u8) (data_805D5594 == 0));
}
