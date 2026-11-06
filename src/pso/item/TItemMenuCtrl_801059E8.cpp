#include "types.h"
#include "pso/item/TItemMenuCtrl.h"

extern "C" {

s32 test_flags_any(s32, s32);

extern u32 TItemMenuCtrl__instance;

s32 TItemMenuCtrl::query_flag(s32 arg0) {
    if ((u32) TItemMenuCtrl__instance != 0U) {
        return test_flags_any(TItemMenuCtrl__instance + 0x1C, 1 << arg0);
    }
    return 0;
}

}
