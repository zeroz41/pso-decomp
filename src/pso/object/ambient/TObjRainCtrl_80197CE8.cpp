#include "types.h"
#include "pso/object/ambient/TObjRainCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TObject.h"

extern "C" {


extern void *tl_particle;

void TObjRainCtrl::create() {
    void *rain_ctrl;

    if (TRaderMapCore::is_not_split_screen() == 0) {
        rain_ctrl = TObject::operator new(0x20);
        if (rain_ctrl != 0) {
            TObjRainCtrl__ct(rain_ctrl, tl_particle);
        }
    }
}

}
