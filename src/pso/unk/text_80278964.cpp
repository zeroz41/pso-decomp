#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquip_80279044.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/unk/text_80278964.h"

extern "C" {

s32 TWindowSubItem__sub_8027AA78(s32 arg0);
}

void refresh_battle_stat_list(void *window_base) {
    u32 var_r31;

    var_r31 = 0U;
    do {
        add_battle_stat_entry(window_base, var_r31, TWindowSubItem__sub_8027AA78(var_r31), 1);
        var_r31 += 1;
    } while (var_r31 < 5U);
    if (*(s16 *)((s8 *)window_base + 0x72) <= 0) {
        advance_status_disp_entry((TWindowBase *)window_base, -1);
    }
    TWindowSubEquip__sub_80279044(window_base);
    ((TWindowMenuIconLine *)window_base)->calc_content_extent();
}
