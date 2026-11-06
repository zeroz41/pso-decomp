#include "types.h"
#include "pso/ui/window/TWindowDD_803471C0.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {
s32 update_state__9TWindowDDFv(s32, s32, s32);

extern s32 window_dd_buffer_a;

void TWindowDD::open(s32 arg0, s32 arg1) {
    update_state__9TWindowDDFv(arg0, window_dd_buffer_a, arg1);
    TWindowCtrl::open(arg1, window_dd_buffer_a, 0x4F);
}

u8 TWindowDD::is_id_in_special_range(s16 id) {
    s32 r = 0;
    if (id >= 0x45d && id <= 0x46f && id != 0x46d && id != 0x46e) {
        r = 1;
    }
    return r;
}

s32 TWindowDD__sub_80347238(s16 arg0) {
    u8 var_r3;
    var_r3 = 0;
    if ((arg0 >= 0x300) && (arg0 <= 0x395)) {
        var_r3 = 1;
    }
    return var_r3;
}

}
