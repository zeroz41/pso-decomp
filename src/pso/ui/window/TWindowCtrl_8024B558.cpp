#include "types.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 post_chat_log_message();

extern s32 local_client_id;
extern uaddr TWindowCtrl__active_window;

saddr TWindowCtrl::open(s32 arg0, saddr arg1, s32 arg2) {
    saddr temp_r3;

    if ((u32) TWindowCtrl__active_window == 0U) {
        return 0;
    }
    if (arg2 & 0x40) {
        post_chat_log_message();
    }
    temp_r3 = (saddr)((TWindowCtrl *)TWindowCtrl__active_window)->show_chat_balloon(arg0, arg2, (void *)arg1, (void *)(saddr)local_client_id);
    if (temp_r3 == 0) {
        return 0;
    }
    set_text__15TWindowFukidasiFPvii((u8 *)temp_r3, arg1, arg2);
    return temp_r3;
}

}
