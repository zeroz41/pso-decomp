#include "types.h"
#include "pso/ui/window/TWindowSetLevelUp.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/task/TMainTask.h"

void TWindowCtrl::create_level_up_window(saddr stats, saddr client) {
    new TWindowSetLevelUp(tl_07, stats, client);
}
