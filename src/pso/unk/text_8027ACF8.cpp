#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubItemList.h"
#include "pso/misc/TWindowSubStatusDisp.h"

void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
extern s32 actor_frame_tick;

void TWindowSubItemList::sub_8027ACF8(u8 *window_key_board_soft) {
    u8 *arg0 = (u8 *)this;
    s16 temp_r5;
    u16 *temp_r3;
    temp_r5 = *(s16 *)((s8 *)arg0 + 0x88);
    if ((temp_r5 >= 0) && !(actor_frame_tick & 0x10)) {
        temp_r3 = (u16 *)(((TWindowBase *)arg0)->get_array_entry((s32) temp_r5));
        if (*temp_r3 & 1) {
            draw_selection_bar(window_key_board_soft, (u8 *)temp_r3, 1);
        }
    }
}
