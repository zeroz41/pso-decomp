#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"

void TWindowCtrl::init_all_slots() {
    saddr var_r31;

    var_r31 = 0;
    do {
        TWindowCtrl::suppress_slot(var_r31);
        var_r31 += 1;
    } while (var_r31 < 0xC);
}

void TWindowCtrl::init_all_slots2() {
    saddr var_r31;

    var_r31 = 0;
    do {
        TWindowCtrl::unsuppress_slot(var_r31);
        var_r31 += 1;
    } while (var_r31 < 0xC);
}
