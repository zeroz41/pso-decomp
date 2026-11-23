#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"

extern "C" {


s32 TWindowCtrl::get_display_flag() {
    if (is_split_screen() != 0) {
        return 0;
    }
    if (instance == NULL) {
        return 0;
    }
    return ((u16) instance->flags >> 1U) & 1;
}

}
