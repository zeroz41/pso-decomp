#include "types.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/unk/text_802AA8FC.h"
#include "pso/boss/TBoss6PlotFalz.h"

extern "C" {

s32 is_split_screen();

extern s32 TBoss6PlotFalz__instance;

u8 TBoss6PlotFalz::is_flag_set() {
    return (u8) (TBoss6PlotFalz__instance != 0);
}

s32 TBoss6PlotFalz::get_next_point(s16 *arg1, s16 *arg2) {
    if (((s32 (*)(void))TBoss6PlotFalz__sub_802AAC74)() < 1) {
        return 0;
    }
    *arg1 = *(s16 *)&this->set_index + *(s32 *)((s8 *)this + 0x3C8);
    *arg2 = this->entity_id + *(s32 *)((s8 *)this + 0x3C8);
    *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) + 1);
    return 1;
}

s32 TBoss6PlotFalz__sub_802AAC74(u8 *arg0) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x3C8);
    if ((temp_r0 < 1) || (temp_r0 > 0x1FD)) {
        return 0;
    }
    return 0x1FD - temp_r0;
}

void TBoss6PlotFalz::sub_802AAC98() { *(s32*)((char*)this + 0x3c8) = 1; }
u8 TBoss6PlotFalz::is_ending_or_split_screen() {
    s32 var_r31;

    var_r31 = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}
int TBoss6PlotFalz::is_ready() { return 0; }

}
