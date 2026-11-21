#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"

void TWindowChat::close_and_clear_flag() {
    close_all_children();
    flags &= ~2;
    open_next_input_window();
}

void TWindowChat::set_keyboard_flag62_bit4() {
    TWindowKeyBoardBase *keyboard = static_cast<TWindowKeyBoardBase *>(composer);
    if (keyboard != NULL) {
        keyboard->set_flag62_bit4();
    }
}
