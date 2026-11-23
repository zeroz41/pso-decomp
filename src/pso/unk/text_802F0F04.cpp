#include "types.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"
#include "pso/unk/text_802F0F04.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804E48D8::render() {
    if (visible != 0) {
        TObjAreaWarpForest::render();
    }
}

void TUnk_804E48D8::run_task() {
    if (TObjBoss7Tunnel::has_stopped() != 0) {
        visible = 1;
    }
    TObjAreaWarpForest::run_task();
}

TUnk_804E48D8::~TUnk_804E48D8() {}

TUnk_804E48D8::TUnk_804E48D8(TObject *parent, void *set_data) : TObjAreaWarpForest(parent, set_data) {
    visible = 0;
}

void *TUnk_804E48D8::create(void *set_data) {
    return new TUnk_804E48D8(tl_05, set_data);
}
