#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_field24() {
    if (TWindowCtrl__active_window == NULL) {
        return -0x1600;
    }
    return TWindowCtrl__active_window->m_24;
}
