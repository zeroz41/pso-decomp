#include "types.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/object/warp/Boss7TunnelAreaWarp.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/system/task/TMainTask.h"

void Boss7TunnelAreaWarp::render() {
    if (visible != 0) {
        TObjAreaWarpForest::render();
    }
}

void Boss7TunnelAreaWarp::run_task() {
    if (TObjBoss7Tunnel::has_stopped() != 0) {
        visible = 1;
    }
    TObjAreaWarpForest::run_task();
}

Boss7TunnelAreaWarp::~Boss7TunnelAreaWarp() {}

Boss7TunnelAreaWarp::Boss7TunnelAreaWarp(TObject *parent, ObjectSetData *set_data) : TObjAreaWarpForest(parent, set_data) {
    visible = 0;
}

void *Boss7TunnelAreaWarp::create(ObjectSetData *set_data) {
    return new Boss7TunnelAreaWarp(tl_05, set_data);
}
