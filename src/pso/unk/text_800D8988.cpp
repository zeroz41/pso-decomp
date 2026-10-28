#include "types.h"
#include "pso/system/vector.h"
#include "pso/map/FloorArea.h"

extern "C" {
s32 play_sound_effect(s32 id, Vec *src, s32 a2, s32 flags);

void TObjEneGibbles__sub_800D8988(Vec *pos) {
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x3A841, pos, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4003B22C, pos, 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4003A834, pos, 0, 0);
        break;
    }
}
}
