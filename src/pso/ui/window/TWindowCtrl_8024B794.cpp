#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"



void TWindowCtrl::dispatch_to_child(s32 client, s32 kind) {
    uaddr *p = (uaddr *)TWindowCtrl__active_window;
    if (p != 0 && p[client + 18] != 0U) {
        ((TWindowCtrlMain *)p[client + 18])->spawn_palette_slot_light(kind);
    }
}

