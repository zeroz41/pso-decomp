#include "pso/map/FloorPopulation.h"
#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/TLobby.h"

extern "C" {


s32 TWindowDD::check_all_ready(s32 floor) {
    s16 temp_r3_2;
    s32 object_type;
    s32 i;
    u8 *var_r31;

    var_r31 = reinterpret_cast<u8 *>(get_active_floor_enemy_rows(floor));
    object_type = TLobby::get_object_type(floor);
    if (var_r31 != NULL) {
        for (i = 0; i < object_type; i++) {
            temp_r3_2 = *(s16 *)((s8 *)var_r31 + 2);
            if (!(temp_r3_2 & 8) && (temp_r3_2 & 2)) {
                return 0;
            }
            var_r31 += 0x48;
        }
    }
    return 1;
}

}
