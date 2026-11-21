#include "types.h"
#include "pso/object/ambient/TObjRainCtrl.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TObject.h"

extern "C" TObject *tl_particle;

void TObjRainCtrl::create() {
    if (TRaderMapCore::is_not_split_screen() == 0) {
        new TObjRainCtrl(tl_particle);
    }
}
