#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"

void toggle_help_window_on_button(uaddr object, s32 client_index) {
    if ((is_split_screen() != 0) && (object != 0U) && (test_pressed_buttons_packed(&controller_input_state.controllers[is_player_input_active(client_index)], 0x400) != 0)) {
        if (((TWindowBase *)object)->is_closed() != 0) {
            window_request_show((void *)object);
            return;
        }
        reinterpret_cast<TWindowBase *>(object)->request_close();
    }
}
