#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/TLogo.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

extern "C" {

u32 OSGetProgressiveMode();
s32 disable_progressive_mode__13TAdVIConfigGCFPv();
u32 VIGetDTVStatus();
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);

extern s8 controller_physical_port_bank[];

s32 TLogo::check_progressive_ready() {
    if (VIGetDTVStatus() == 0U) {
        disable_progressive_mode__13TAdVIConfigGCFPv();
        return 0;
    }
    if ((OSGetProgressiveMode() != 1U) && (is_on_current_screen__11TCameraCtrlFv(controller_physical_port_bank + 0x20, 2) == 0)) {
        disable_progressive_mode__13TAdVIConfigGCFPv();
        return 0;
    }
    return 1;
}

void TAdYesNoBaseGC::vfunc_8() {  }
void TAdYesNoBaseGC::vfunc_9() {  }

}
