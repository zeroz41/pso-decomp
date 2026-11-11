#include "types.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/object/TObjRoomId.h"
#include "pso/npc/TObjNpcEnemy.h"

extern s32 lbl_805D53B0;
extern void *current_room_id;
bool fn_800FD8A0(s32 arg0) {
    return lbl_805D53B0 == arg0;
}
s32 is_current_room(void *object) {
    return current_room_id == object ? TRUE : FALSE;
}

extern "C" {

s32 debug_printf_at(s32, s32, ...);


void TObjRoomId::draw_debug_line(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 == (u32) current_room_id) {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at((arg1 << 0x10) | arg2, arg3);
        TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    }
}

}
