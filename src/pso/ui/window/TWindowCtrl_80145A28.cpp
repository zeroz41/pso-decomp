#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


s32 TWindowCtrl::get_field24() {
    if (instance == NULL) {
        return -0x1600;
    }
    return instance->m_24;
}
