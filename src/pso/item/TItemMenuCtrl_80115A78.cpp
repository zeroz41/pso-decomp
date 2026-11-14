#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

s32 TItemMenuCtrl__ct(u32, s32);
u32 __nw__7TObjectFUl(s32);
s32 set_menu_flags__13TItemMenuCtrlFv(u32, s32);

extern u32 TItemMenuCtrl__instance;
extern s32 tl_05;

void TItemMenuCtrl::open_menu(u32 arg0) {
    u32 obj;
    if (((u32) TItemMenuCtrl__instance == 0U) && ((obj = __nw__7TObjectFUl(0x20)) != 0U)) {
        TItemMenuCtrl__ct(obj, tl_05);
    }
    if (arg0 < 7U) {
        if (arg0 == 0) {
            ((TObject *)TItemMenuCtrl__instance)->queue_destruction();
            return;
        }
        set_menu_flags__13TItemMenuCtrlFv(TItemMenuCtrl__instance, 1 << arg0);
    }
}

}
