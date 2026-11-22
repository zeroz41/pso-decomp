#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz_802AABEC.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/player/TObjPlayer_80011014.h"


extern saddr TBoss6PlotFalz__instance;

s32 TBoss6PlotFalz::is_flag_set() {
    return (u8)((u8) (TBoss6PlotFalz__instance != 0));
}

s32 TBoss6PlotFalz::get_next_point(s16 *arg1, s16 *arg2) {
    if (count_free_child_ids() < 1) {
        return 0;
    }
    *arg1 = this->set_index + next_child_index;
    *arg2 = this->entity_id + next_child_index;
    next_child_index = next_child_index + 1;
    return 1;
}

s32 TBoss6PlotFalz::count_free_child_ids() {
    s32 n;
    n = next_child_index;
    if ((n < 1) || (n > 0x1FD)) {
        return 0;
    }
    return 0x1FD - n;
}

void TBoss6PlotFalz::reset_child_ids() { next_child_index = 1; }
s32 TBoss6PlotFalz::is_ending_or_split_screen() {
    s32 var_r31;

    var_r31 = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}
int TBoss6PlotFalz::is_ready() { return 0; }

