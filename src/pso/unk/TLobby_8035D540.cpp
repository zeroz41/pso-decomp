#include "pso/ui/window/MessageWindowSettingsAbi.h"
#include "types.h"
#include "pso/ui/window/TWindowMessageScroll.h"
#include "pso/unk/TLobby_80269C6C.h"
#include "pso/unk/TLobby_8026B06C.h"


void TWindowMessageScroll::set_scroll_speed(f32 speed) {
    scroll_speed = speed;
}

TWindowMessageScroll *open_message_scroll_window(const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 *completion) {
    TWindowMessageScroll *window;

    TLobby__sub_80269CA4(0x23);
    TLobby__sub_80269DA4(extent, 1);
    window = new TWindowMessageScroll(reinterpret_cast<saddr>(position), completion);
    TLobby__sub_80269C90();
    return window;
}
