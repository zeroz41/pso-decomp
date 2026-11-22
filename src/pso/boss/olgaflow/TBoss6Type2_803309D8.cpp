#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"

TBoss6Mag *TBoss6Type2::create_mag(TBoss6MagSpawnParams *params) {
    return new TBoss6Mag(new TObjControl(tl_04), params);
}
