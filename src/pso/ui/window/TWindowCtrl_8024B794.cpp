#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"

extern "C" {

extern u32* TWindowCtrl__active_window;

void TWindowCtrl::dispatch_to_child(void *arg1) {
    s32 arg0 = (s32)this;
    u32* p = TWindowCtrl__active_window;
    if (p != 0 && p[arg0 + 18] != 0U) {
        ((TWindowCtrlMain *)p[arg0 + 18])->spawn_palette_slot_light((s32)arg1);
    }
}

}
