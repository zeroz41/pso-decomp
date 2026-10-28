#include "types.h"
#include "pso/misc/TLobby_80207644.h"
#include "pso/unk/text_80203418.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

struct Stack_80203470 {
    s32 sp8;
    u8 trailing_storage[0x8];
};

extern s32 current_floor_index;
extern s32 current_floor_area_type;
extern s32 boss_area_id_table[];

s32 is_boss_area(void) {
    s32 state = get_current_area();
    s32 i = 0;
    while (boss_area_id_table[i] != -1) {
        if (state == boss_area_id_table[i++]) return 1;
    }
    return 0;
}

void set_current_floor_area(s32 arg0) {
    Stack_80203470 stack;
    current_floor_index = arg0;
    if (get_floor_map_selection((arg0), (u8 *)&stack.sp8) == 1) {
        current_floor_area_type = stack.sp8;
    }
}
