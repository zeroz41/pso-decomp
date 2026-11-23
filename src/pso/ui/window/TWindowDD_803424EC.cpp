#include "types.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 TWindowDD__sub_803482B0(s32);
s32 TWindowDD__sub_803484C4(s32);

void handle_input__9TWindowDDFi(saddr window_dd) {
    ((TWindowDD *)window_dd)->update_selection_state();
    if (((TWindowDD *)window_dd)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803484C4(window_dd);
        return;
    }
    if (TWindowDD__sub_803482B0(window_dd) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout((void *)window_dd);
    }
}

}
