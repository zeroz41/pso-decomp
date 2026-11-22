#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"

void toggle_help_window_on_button(uaddr arg0, s32 client_index) {
    if ((is_split_screen() != 0) && (arg0 != 0U) && (test_pressed_buttons_packed(&controller_input_state.controllers[is_player_input_active(client_index)], 0x400) != 0)) {
        if (((TWindowBase *)arg0)->sub_80246948() != 0) {
            window_request_show((void *)arg0);
            return;
        }
        reinterpret_cast<TWindowBase *>(arg0)->request_close();
    }
}
