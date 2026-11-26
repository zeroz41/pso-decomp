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

    set_message_window_flags(0x23);
    set_message_window_size(extent, 1);
    window = new TWindowMessageScroll(position, completion);
    set_message_window_default_flags();
    return window;
}
