#include "types.h"
#include "pso/ui/charcreate/TChCrEffCtrlPl.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/system/ControllerInputState.h"

#include "pso/unk/text_80299420.h"

PadSlot *get_creation_pad(void) {
    return controller_physical_port_bank.sources[TChCrEffCtrlPl::get_clamped_player_index()];
}

s32 TChCrEffCtrlPl::get_clamped_player_index() {
    s32 index;

    index = TAdMultiPlyChrSelectGC::is_selection_confirmed();
    if ((index < 0) || (index > 3)) {
        index = 0;
    }
    return index;
}
int TChCrEffCtrlPl__sub_80298F6C() { return TAdMultiPlyChrSelectGC__sub_80299454(); }
