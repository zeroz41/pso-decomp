#include "types.h"
#include "pso/unk/pso_carve_8020bf88.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8020B03C.h"

int TLobby__sub_8020BF88(void) {
    s32 count = 0;
    count += TLobby__sub_8020B308();
    count += TLobby::sum_floor_enemy_counts();
    return count * 2 + 0x10;
}
