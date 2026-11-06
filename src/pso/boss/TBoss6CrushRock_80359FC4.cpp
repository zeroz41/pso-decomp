#include "types.h"
#include "pso/boss/TBoss6CrushRock.h"
#include "pso/boss/TBoss6PlotFalz.h"

s32 TBoss6CrushRock::is_falz_alive() {
    return TBoss6PlotFalz::get_hp() ? 1 : 0;
}
