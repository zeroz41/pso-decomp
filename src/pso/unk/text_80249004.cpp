#include "types.h"
#include "pso/unk/text_80249004.h"
#include "pso/unk/text_80268384.h"
#include "pso/ui/window/TUnk_804CE7E8.h"

struct StatusDispWindowDispatchTable { s32 value; u8 remaining[0x1C]; };
extern StatusDispWindowDispatchTable status_disp_window_dispatch_table;
u8 *fn_80249004(u8 *arg0, s32 arg1, s16 arg2) {
    fn_802683F4(arg0, arg1, 5, arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &status_disp_window_dispatch_table.value;
    ((TUnk_804CE7E8 *)arg0)->sub_80248B7C(arg2);
    return arg0;
}
