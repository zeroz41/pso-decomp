#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubEquip_80279044.h"

extern "C" {

s32 TWindowSubItem__sub_8027AA78(s32 arg0);
}

void TWindowMenuIconLine::refresh_battle_stat_list() {
    u32 stat;

    stat = 0U;
    do {
        add_battle_stat_entry(stat, TWindowSubItem__sub_8027AA78(stat), 1);
        stat += 1;
    } while (stat < 5U);
    if (entry_count <= 0) {
        advance_status_disp_entry(-1);
    }
    TWindowSubEquip__sub_80279044(this);
    calc_content_extent();
}
