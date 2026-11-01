#include "types.h"
#include "pso/unk/text_8027FCE4.h"
#include "pso/unk/text_8027FD88.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TUnk_804D1AD0.h"

struct RecoveredGlobal_8027FCE4_lbl_804D1AD0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
s32 TWindowSubStatusDisp__ct(int, int);
}
extern RecoveredGlobal_8027FCE4_lbl_804D1AD0 status_category_window_vtable;
extern const f32 lbl_805DD6DC;
typedef char RecoveredGlobal_8027FCE4_lbl_804D1AD0_size[sizeof(RecoveredGlobal_8027FCE4_lbl_804D1AD0) == 0x18 ? 1 : -1];
u8 *construct_status_category_window(u8 *arg0, s32 arg1, s32 arg2) {
    s32 storage;
    s32 var_r0;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &status_category_window_vtable.value;
    *(s32 *)((s8 *)arg0 + 0x20) = arg1;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    *(s32 *)((s8 *)arg0 + 0x24) = ((TUnk_804D1AD0 *)arg0)->create_status_category_menu();
    storage = __nw__7TObjectFUl(0x74);
    var_r0 = storage;
    if (var_r0 != 0) {
        var_r0 = TWindowSubStatusDisp__ct(storage, (int) (*(s32 *)((s8 *)arg0 + 0x1C)));
    }
    ((TUnk_804D1AD0 *)arg0)->m_28 = var_r0;
    if (TCameraCtrl::get_camera_id() > 2) {
        ((TWindowAddition *)(*(s32 *)((s8 *)arg0 + 0x24)))->set_position_xy(lbl_805DD6DC, lbl_805DD6DC);
        fn_8027FD88((void *)(((TUnk_804D1AD0 *)arg0)->m_28), lbl_805DD6DC, lbl_805DD6DC);
    }
    return arg0;
}
