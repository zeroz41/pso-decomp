#include "types.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"

extern "C" {

s32 TLobby__sub_80269DA4(s32 a0 = 0, s32 a1 = 0);

void TLobby::set_timer(f32 v) { *(f32*)((char*)this + 0x94) = v; }

saddr TLobby::open_message_scroll_window(saddr arg0, saddr arg1, saddr arg2) {
    saddr window_message_scroll;

    TLobby__sub_80269CA4(0x23);
    TLobby__sub_80269DA4(arg1, 1);
    window_message_scroll = (saddr)new TWindowMessageScroll(arg0, (s32 *)arg2);
    TLobby__sub_80269C90();
    return window_message_scroll;
}

}
