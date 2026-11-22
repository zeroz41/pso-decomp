#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_8026AC50.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"


void TWindowCtrl::shutdown() {
    if (TWindowCtrl__active_window != NULL) {
        TWindowCtrl__active_window->queue_destruction();
        TWindowCtrl__active_window = NULL;
    }
    fn_8026AC50();
    TWindowMainMenu__sub_8024E3CC();
}
