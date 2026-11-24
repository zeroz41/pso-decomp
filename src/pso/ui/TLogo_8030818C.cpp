#include "types.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"
#include "pso/ui/TLogo.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/system/ControllerInput.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSRtc.h>
#include <dolphin/vi.h>
#undef PSO_SDK_COMPACT_MATH

extern "C" {

s32 disable_progressive_mode__13TAdVIConfigGCFPv();


s32 TLogo::check_progressive_ready() {
    if (VIGetDTVStatus() == 0U) {
        disable_progressive_mode__13TAdVIConfigGCFPv();
        return 0;
    }
    if ((OSGetProgressiveMode() != 1U) && (test_previous_buttons_packed(&controller_physical_port_bank.controllers[0], 2) == 0)) {
        disable_progressive_mode__13TAdVIConfigGCFPv();
        return 0;
    }
    return 1;
}

void TAdYesNoBaseGC::vfunc_8() {  }
void TAdYesNoBaseGC::vfunc_9() {  }

}
