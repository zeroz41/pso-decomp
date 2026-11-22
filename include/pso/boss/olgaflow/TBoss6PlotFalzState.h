#ifndef PSO_BOSS_OLGAFLOW_TBOSS6PLOTFALZSTATE_H
#define PSO_BOSS_OLGAFLOW_TBOSS6PLOTFALZSTATE_H

#include "types.h"

#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include <stddef.h>

typedef void (TBoss6PlotFalz::*TBoss6PlotFalzAction)();
struct TBoss6PlotFalzScriptState {
    const char *name;
    TBoss6PlotFalzAction enter;
    TBoss6PlotFalzAction leave;
    TBoss6PlotFalzAction tick;
    TBoss6PlotFalzAction update;
};
LAYOUT_ASSERT(TBoss6PlotFalzAction_size, sizeof(TBoss6PlotFalzAction) == 12);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_size, sizeof(TBoss6PlotFalzScriptState) == 0x34);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_name_offset, offsetof(TBoss6PlotFalzScriptState, name) == 0);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_enter_offset, offsetof(TBoss6PlotFalzScriptState, enter) == 4);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_leave_offset, offsetof(TBoss6PlotFalzScriptState, leave) == 0x10);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_tick_offset, offsetof(TBoss6PlotFalzScriptState, tick) == 0x1C);
LAYOUT_ASSERT(TBoss6PlotFalzScriptState_update_offset, offsetof(TBoss6PlotFalzScriptState, update) == 0x28);

extern TBoss6PlotFalzScriptState boss6_plot_falz_script_states[9];

#endif
