#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

s32 set_menu_flags__13TItemMenuCtrlFv(u32, s32);

extern uaddr TItemMenuCtrl__instance;

void TItemMenuCtrl::open_menu(u32 arg0) {
    if (((u32) TItemMenuCtrl__instance == 0U)) {
        new TItemMenuCtrl(tl_05);
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
