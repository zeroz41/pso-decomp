#include "types.h"
#include "pso/unk/text_80071A9C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
extern "C" {
s32 get_layout_id__20TWindowSubStatusDispFv(s32);
s32 *TWindowSubStatusDisp__sub_8006F0D8(s32, s32);
s32 fn_80071A9C(s32 arg0, s32 arg1, s32 slot) {
    s32 n;
    s32 i;
    s32 *p;
    slot = TWindowSubStatusDisp::resolve_player_slot(slot);
    p = TWindowSubStatusDisp__sub_8006F0D8(arg1, slot);
    n = get_layout_id__20TWindowSubStatusDispFv(slot);
    for (i = 0; i < n; i++, p++) {
        s32 r = TLobby::get_valid_slot(*p);
        if (*p == 0 || r == 0) {
            break;
        }
    }
    return i;
}

}
