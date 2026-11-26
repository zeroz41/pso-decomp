#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/network/TLobby.h"



s32 TWindowDD::check_all_ready(s32 floor) {
    s16 flags;
    s32 object_type;
    s32 i;
    u8 *active_floor_enemy_rows;

    active_floor_enemy_rows = reinterpret_cast<u8 *>(get_active_floor_enemy_rows(floor));
    object_type = TLobby::get_object_type(floor);
    if (active_floor_enemy_rows != NULL) {
        for (i = 0; i < object_type; i++) {
            flags = *(s16 *)((s8 *)active_floor_enemy_rows + 2);
            if (!(flags & 8) && (flags & 2)) {
                return 0;
            }
            active_floor_enemy_rows += 0x48;
        }
    }
    return 1;
}

