#include "types.h"
#include "pso/render/DebugFont.h"
#include "pso/object/TObjRoomId.h"
#include "pso/npc/TObjNpcEnemy.h"

// One TU with its own .sbss block (8-aligned start after the previous TU's pad).
u8 item_light_interaction_blocked_flag;
void *current_room_id;

s32 is_current_room(void *object) {
    return current_room_id == object ? TRUE : FALSE;
}

void TObjRoomId::draw_debug_line(s32 row, s32 column, const char *format) {
    if (this == current_room_id) {
        set_debug_text_color(0xFF00FF);
        debug_printf_at((row << 0x10) | column, format);
        set_debug_text_color(0xF0F0F0FF);
    }
}

bool is_item_light_interaction_blocked(void) {
    return (s8) item_light_interaction_blocked_flag != 0;
}
