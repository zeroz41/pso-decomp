#include "types.h"
#include "pso/unk/text_8020C354.h"
#include "pso/unk/TLobby.h"
struct Row_8020C354 { s16 type, flags; u8 u4[8]; s16 room; u8 ue[0x3a]; };

extern "C" {
Row_8020C354 *resolve_matching_object__6TLobbyFv(s32 floor);
s32 is_room_free_of_active_enemies(s32 floor, s16 room) {
    Row_8020C354 *rows = resolve_matching_object__6TLobbyFv(floor);
    s32 count = TLobby::get_object_type(floor);
    if (rows != NULL) {
        for (; count > 0; count--, rows++) {
            if (rows[0].room == room && !(rows[0].flags & 8) && (rows[0].flags & 2)) {
                return 0;
            }
        }
    }
    return 1;
}

}
