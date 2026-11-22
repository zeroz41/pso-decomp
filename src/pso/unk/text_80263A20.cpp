#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/unk/text_80263A20.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/player/TObjPlayer_80011014.h"


extern "C" {
s32 is_player_input_active(s32 param_1);
}
void toggle_help_window_on_button(uaddr arg0, s32 client_index) {
    if ((is_split_screen() != 0) && (arg0 != 0U) && (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state + (is_player_input_active(client_index) * 0x50) + 0x20), 0x400) != 0)) {
        if (((TWindowBase *)arg0)->sub_80246948() != 0) {
            window_request_show((void *)arg0);
            return;
        }
        reinterpret_cast<TWindowBase *>(arg0)->request_close();
    }
}
