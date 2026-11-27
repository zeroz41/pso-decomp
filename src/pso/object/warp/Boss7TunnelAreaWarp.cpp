#include "types.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/object/warp/Boss7TunnelAreaWarp.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/system/task/TMainTask.h"

void TObjAreaWarpBoss7Tunnel::render() {
    if (visible != 0) {
        TObjAreaWarpForest::render();
    }
}

void TObjAreaWarpBoss7Tunnel::run_task() {
    if (TObjBoss7Tunnel::has_stopped() != 0) {
        visible = 1;
    }
    TObjAreaWarpForest::run_task();
}

TObjAreaWarpBoss7Tunnel::~TObjAreaWarpBoss7Tunnel() {}

TObjAreaWarpBoss7Tunnel::TObjAreaWarpBoss7Tunnel(TObject *parent, ObjectSetData *set_data) : TObjAreaWarpForest(parent, set_data) {
    visible = 0;
}

void *TObjAreaWarpBoss7Tunnel::create(ObjectSetData *set_data) {
    return new TObjAreaWarpBoss7Tunnel(tl_05, set_data);
}
