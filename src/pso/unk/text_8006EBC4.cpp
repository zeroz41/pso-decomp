#include "types.h"
#include "pso/unk/text_8006EBC4.h"
#include "pso/ui/window/TWindowCtrl.h"

extern "C" {
s32 __ct__16TObjBagWarnWin4PFv(int, void *);
s32 __nw__7TObjectFUl(int);
s32 fn_8006EBC4(s32 bag_warn_win4_p) {
    s32 temp_r3;
    s32 var_r0;
    if (TWindowCtrl::is_map_visible() == 0) {
        temp_r3 = __nw__7TObjectFUl(0xA4);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = __ct__16TObjBagWarnWin4PFv((int)temp_r3, (void *)bag_warn_win4_p);
        }
        return var_r0;
    }
    return 0;
}

}
