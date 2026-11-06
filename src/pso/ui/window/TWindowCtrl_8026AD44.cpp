#include "types.h"
#include "pso/ui/window/TWindowCtrl_8026AD44.h"
#include "pso/ui/window/TWindowCtrl.h"

extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_field44() {
    if ((void *) TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return *(s32 *)((s8 *)TWindowCtrl__active_window + 0x44);
}

void TWindowCtrl__sub_8026AD60(void) {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(s32 *)((s8 *)TWindowCtrl__active_window + 0x44) = 0;
    }
}

void TWindowCtrl__sub_8026AD78(s32 arg0) {
    if ((void *) TWindowCtrl__active_window != NULL) {
        *(s32 *)((s8 *)TWindowCtrl__active_window + 0x44) = arg0;
    }
}
