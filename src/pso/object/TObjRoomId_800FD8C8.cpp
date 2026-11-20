#include "types.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/unk/text_800FD930.h"
#include "pso/object/TObjRoomId.h"
#include "pso/npc/TObjNpcEnemy.h"

// One TU 0x800FD8B4-0x800FD944 with .sbss 0x805D53B8-0x805D53C0 (8-aligned start after the previous TU's pad).
u8 item_light_interaction_blocked_flag;
void *current_room_id;

extern "C" {
s32 debug_printf_at(s32, s32, ...);
}

s32 is_current_room(void *object) {
    return current_room_id == object ? TRUE : FALSE;
}

void TObjRoomId::draw_debug_line(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 == (uaddr)current_room_id) {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at((arg1 << 0x10) | arg2, arg3);
        TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    }
}

bool is_item_light_interaction_blocked(void) {
    return (s8) item_light_interaction_blocked_flag != 0;
}
