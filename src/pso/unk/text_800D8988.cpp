#include "types.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/system/vector.h"
#include "pso/map/CurrentArea.h"

extern "C" {
s32 play_sound_effect(s32 id, Vec *src, s32 a2, s32 flags);

void TObjEneGibbles__sub_800D8988(Vec *pos) {
    switch (get_current_area()) {
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x3A841, pos, 0, 0);
        break;
    case 34:
        play_sound_effect(0x4003B22C, pos, 0, 0);
        break;
    case 28:
    case 29:
        play_sound_effect(0x4003A834, pos, 0, 0);
        break;
    }
}
}
