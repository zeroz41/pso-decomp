#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

void TItemMenuCtrl::open_menu(u32 arg0) {
    if (TItemMenuCtrl__instance == NULL) {
        new TItemMenuCtrl(tl_05);
    }
    if (arg0 < 7U) {
        if (arg0 == 0) {
            TItemMenuCtrl__instance->queue_destruction();
            return;
        }
        TItemMenuCtrl__instance->set_menu_flags(1U << arg0);
    }
}

}
