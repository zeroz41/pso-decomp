#include "types.h"
#include "pso/unk/text_800D8830.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/map/CurrentArea.h"

extern "C" {
s32 play_sound_effect(int, void *, int, int);

void fn_800D8830(void *owner, void *pos) {
    switch (get_current_area()) {
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_persistent_sound(0x3A842, (s32)owner, (u32)pos, 0, 0);
        break;
    case 34:
        play_persistent_sound(0x4003B22D, (s32)owner, (u32)pos, 0, 0);
        break;
    case 28:
    case 29:
        play_persistent_sound(0x4003A835, (s32)owner, (u32)pos, 0, 0);
        break;
    }
}

void fn_800D88E4(void *pos) {
    switch (get_current_area()) {
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x3A840, pos, 0, 0);
        break;
    case 34:
        play_sound_effect(0x4003B22B, pos, 0, 0);
        break;
    case 28:
    case 29:
        play_sound_effect(0x4003A833, pos, 0, 0);
        break;
    }
}
}
