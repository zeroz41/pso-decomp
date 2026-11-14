#include "types.h"
#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/system/ControllerInputState.h"

extern "C" {

int TAdMultiPlyChrSelectGC__sub_80299454(void*);

s32 get_creation_pad(void) {
    return ((s32 *)controller_physical_port_bank.unknown_00)[TChCrEffCtrlPl::get_clamped_player_index()];
}

s32 TChCrEffCtrlPl::get_clamped_player_index() {
    s32 var_r3;

    var_r3 = TAdMultiPlyChrSelectGC::is_selection_confirmed();
    if ((var_r3 < 0) || (var_r3 > 3)) {
        var_r3 = 0;
    }
    return var_r3;
}
int TChCrEffCtrlPl__sub_80298F6C(void* p) { return TAdMultiPlyChrSelectGC__sub_80299454(p); }

}
