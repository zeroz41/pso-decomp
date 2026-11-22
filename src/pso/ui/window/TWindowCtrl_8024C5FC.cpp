#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"


saddr TWindowCtrl::get_window(s32 client_id) {
    if (instance == NULL) {
        return 0;
    }
    if (client_id < 0) {
        return 0;
    }
    if (client_id >= 0xC) {
        return 0;
    }
    return ((saddr *)((s8 *)instance + 0x48))[client_id];
}
