#include "types.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {

s32 post_chat_log_message();

extern s32 local_client_id;

saddr TWindowCtrl::open(s32 id, saddr text, s32 flags) {
    saddr temp_r3;

    if (instance == NULL) {
        return 0;
    }
    if (flags & 0x40) {
        post_chat_log_message();
    }
    temp_r3 = (saddr)instance->show_chat_balloon(id, flags, (void *)text, (void *)(saddr)local_client_id);
    if (temp_r3 == 0) {
        return 0;
    }
    set_text__15TWindowFukidasiFPvii((u8 *)temp_r3, text, flags);
    return temp_r3;
}

}
