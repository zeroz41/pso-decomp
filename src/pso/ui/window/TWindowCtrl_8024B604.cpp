#include "types.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {


extern saddr tl_07;

void TWindowCtrl::create_level_up_window(saddr arg0, saddr arg1) {
    void *obj = TObject::operator new(0x40);
    if (obj != NULL) {
        __ct__17TWindowSetLevelUpFv(obj, (void *)tl_07, (void *)arg0, (void *)arg1);
    }
}

}
