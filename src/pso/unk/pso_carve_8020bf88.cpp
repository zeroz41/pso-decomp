#include "types.h"
#include "pso/unk/pso_carve_8020bf88.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobby_8020B03C.h"

int get_floor_set_flags_size(void) {
    s32 count = 0;
    count += get_total_object_set_count();
    count += TLobby::sum_floor_enemy_counts();
    return count * 2 + 0x10;
}
