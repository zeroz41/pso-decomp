#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::init_all_slots() {
    s32 var_r31;

    var_r31 = 0;
    do {
        ((TWindowCtrl *)var_r31)->suppress_slot();
        var_r31 += 1;
    } while (var_r31 < 0xC);
}

void TWindowCtrl::init_all_slots2() {
    s32 var_r31;

    var_r31 = 0;
    do {
        ((TWindowCtrl *)var_r31)->unsuppress_slot();
        var_r31 += 1;
    } while (var_r31 < 0xC);
}
