#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"


extern uaddr *TWindowCtrl__active_window;

void TWindowCtrl::dispatch_to_child(s32 arg0, s32 kind) {
    uaddr *p = TWindowCtrl__active_window;
    if (p != 0 && p[arg0 + 18] != 0U) {
        ((TWindowCtrlMain *)p[arg0 + 18])->spawn_palette_slot_light(kind);
    }
}

