#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz_802AABEC.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/player/TObjPlayer_80011014.h"


s32 TBoss6PlotFalz::is_flag_set() {
    return (u8)((u8) (TBoss6PlotFalz__instance != 0));
}

s32 TBoss6PlotFalz::get_next_point(s16 *set_index_out, s16 *entity_id_out) {
    if (count_free_child_ids() < 1) {
        return 0;
    }
    *set_index_out = this->set_index + next_child_index;
    *entity_id_out = this->entity_id + next_child_index;
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
    s32 result;

    result = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        result = 1;
    }
    return (u8) result;
}
int TBoss6PlotFalz::is_ready() { return 0; }

