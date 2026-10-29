#include "types.h"
#include "pso/unk/text_800FD8A0.h"

extern s32 lbl_805D53B0;
extern void *current_room_id;
bool fn_800FD8A0(s32 arg0) {
    return lbl_805D53B0 == arg0;
}
s32 is_current_room(void *object) {
    return current_room_id == object ? TRUE : FALSE;
}
