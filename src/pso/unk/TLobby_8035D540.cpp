#include "types.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 TLobby__sub_80269DA4(s32 a0 = 0, s32 a1 = 0);
s32 __nw__7TObjectFUl(s32 a0 = 0);

void TLobby::set_timer(f32 v) { *(f32*)((char*)this + 0x94) = v; }

s32 TLobby::open_message_scroll_window(s32 arg0, s32 arg1, s32 arg2) {
    s32 window_message_scroll;

    TLobby__sub_80269CA4(0x23);
    TLobby__sub_80269DA4(arg1, 1);
    window_message_scroll = __nw__7TObjectFUl(0x9C);
    if (window_message_scroll != 0) {
        window_message_scroll = (s32)TWindowMessageScroll__ct((u8 *)window_message_scroll, arg0, (s32 *)arg2);
    }
    TLobby__sub_80269C90();
    return window_message_scroll;
}

}
