#include "types.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 apply_entry_layout__9TWindowDDFPv(s32);
s32 update_selection_state__9TWindowDDFv();
s32 TWindowDD__sub_803482B0(s32);
s32 TWindowDD__sub_803484C4(s32);

void handle_input__9TWindowDDFi(saddr window_dd) {
    update_selection_state__9TWindowDDFv();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803484C4(window_dd);
        return;
    }
    if (TWindowDD__sub_803482B0(window_dd) != 0) {
        TWindowDD::play_se();
        apply_entry_layout__9TWindowDDFPv(window_dd);
    }
}

}
