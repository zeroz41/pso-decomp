#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/HelpWindowToggle.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubTradeMain.h"
#include "pso/system/ControllerInput.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowCtrl.h"

void toggle_help_window_on_button(TWindowBase *window, s32 client_index) {
    if ((is_split_screen() != 0) && (window != NULL) && (test_pressed_buttons_packed(&controller_input_state.controllers[is_player_input_active(client_index)], 0x400) != 0)) {
        if (window->is_closed() != 0) {
            window->request_show();
            return;
        }
        window->request_close();
    }
}
