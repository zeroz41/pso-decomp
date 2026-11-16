#include "types.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {


extern s32 tl_07;

void TWindowCtrl::create_level_up_window(s32 arg0, s32 arg1) {
    void *obj = TObject::operator new(0x40);
    if (obj != NULL) {
        __ct__17TWindowSetLevelUpFv(obj, (void *)tl_07, (void *)arg0, (void *)arg1);
    }
}

}
