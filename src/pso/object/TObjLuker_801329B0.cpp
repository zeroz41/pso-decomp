#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/object/TObjLuker_801329B0.h"
#include "pso/object/TObjLuker.h"

extern u8 *text_language_group_table;
extern s32 game_difficulty_selection;

// Section ID names, indexed by a character's section id (TObjCMName, TAdPlyStatusGC).
const char *luker_stat_entry_ptr_table[] = {
    "VIRIDIA", "GREENILL", "SKYLY", "BLUEFULL", "PURPLENUM", "PINKAL",
    "REDRIA", "ORAN", "YELLOWBOZE", "WHITILL", "???????", 0,
};

// Text ids (text group 9) of the floor destination names, by floor area.
const s32 floor_destination_text_id_table[36] = {
    0x23, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
    0x0B, 0x0C, 0x0D, 0x24, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21,
};

void get_floor_destination_name(u32 arg0) {
    u32 var_r3;
    var_r3 = arg0;
    if ((var_r3 == 0xB) && ((s32) game_difficulty_selection >= 3)) {
        var_r3 = 0xE;
    }
    get_localized_text_entry(9, floor_destination_text_id_table[var_r3]);
}

int TObjLuker::get_stat_table_entry(int a0) {  return (int)luker_stat_entry_ptr_table[a0]; }
s32 enemy_name_for_rt_index(s32 arg0) {
    s32 var_r3;
    var_r3 = arg0;
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    if (var_r3 >= 0x58) {
        var_r3 = 0;
    }
    if ((s32) game_difficulty_selection >= 3) {
        return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 0xC)) + (var_r3 * 4));
    }
    return *(s32 *)((s8 *)(*(s32 *)((s8 *)text_language_group_table + 8)) + (var_r3 * 4));
}
