#include "types.h"
#include "pso/unk/text_802032AC.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"
struct SurfaceAreaTable { s32 enabled[36]; };

extern SurfaceAreaTable player_auxiliary_surface_flag_table;
s32 player_auxiliary_surfaces_enabled() {
    SurfaceAreaTable table = player_auxiliary_surface_flag_table;
    return table.enabled[get_current_area()];
}
