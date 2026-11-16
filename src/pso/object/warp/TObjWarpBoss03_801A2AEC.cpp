#include "types.h"
#include "pso/object/warp/TObjWarpBoss03.h"
#include "pso/system/task/TMainTask.h"


void *TObjWarpBoss03::create(void *arg0) {
    return new TObjWarpBoss03(tl_05, arg0);
}

