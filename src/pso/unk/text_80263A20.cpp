#include "types.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/unk/text_80263A20.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowSubTradeMain.h"

struct RecoveredGlobal_80263A20_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 is_split_screen();
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 sub_80246948__11TWindowBaseFv(void *);
s32 is_player_input_active(void *);
}
extern RecoveredGlobal_80263A20_lbl_8050E208 controller_input_state;
typedef char RecoveredGlobal_80263A20_lbl_8050E208_size[sizeof(RecoveredGlobal_80263A20_lbl_8050E208) == 0x1B0 ? 1 : -1];
void toggle_help_window_on_button(u32 arg0, s32 arg1) {
    if ((is_split_screen() != 0) && (arg0 != 0U) && (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state.value + (is_player_input_active((void *)arg1) * 0x50) + 0x20), 0x400) != 0)) {
        if (sub_80246948__11TWindowBaseFv((void *)arg0) != 0) {
            window_request_show((void *)arg0);
            return;
        }
        ((TWindowLockOn *)arg0)->request_close();
    }
}
