#include "types.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 show_chat_balloon__11TWindowCtrlFllPvPv(u32, s32, s32, s32, s32);
s32 post_chat_log_message();

extern s32 local_client_id;
extern u32 TWindowCtrl__active_window;

s32 TWindowCtrl::open(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r3;

    if ((u32) TWindowCtrl__active_window == 0U) {
        return 0;
    }
    if (arg2 & 0x40) {
        post_chat_log_message();
    }
    temp_r3 = show_chat_balloon__11TWindowCtrlFllPvPv(TWindowCtrl__active_window, arg0, arg2, arg1, local_client_id);
    if (temp_r3 == 0) {
        return 0;
    }
    set_text__15TWindowFukidasiFPvii((u8 *)temp_r3, arg1, arg2);
    return temp_r3;
}

}
