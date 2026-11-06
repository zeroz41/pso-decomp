#include "types.h"
#include "pso/ui/window/TWindowDD_803424EC.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 apply_entry_layout__9TWindowDDFPv(s32);
s32 update_selection_state__9TWindowDDFv();
s32 TWindowDD__sub_803482B0(s32);
s32 TWindowDD__sub_803484C4(s32);

void handle_input__9TWindowDDFi(s32 arg0) {
    update_selection_state__9TWindowDDFv();
    if (((TWindowDD *)arg0)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_803484C4(arg0);
        return;
    }
    if (TWindowDD__sub_803482B0(arg0) != 0) {
        TWindowDD::play_se();
        apply_entry_layout__9TWindowDDFPv(arg0);
    }
}

}
