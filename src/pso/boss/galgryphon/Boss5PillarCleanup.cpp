#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/Boss5PillarCleanup.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/boss/galgryphon/Boss5CommonResource.h"
#include "pso/network/TLobby.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5PillarCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/door/TODoorFourLightSpace.h"


void cleanup_pillar_demo() {
    if (boss5_ctrl_instance != NULL) {
        boss5_ctrl_instance->queue_destruction();
        boss5_ctrl_instance = NULL;
    }
    pillar_demo_stub_a();
    TObjBoss5PillarCtrl::update_pillar();
    cleanup_pillar_demo_stub_a();
    clear_pillar_target_refs();
    free_boss5_common_assets();
}
void cleanup_boss5_pillars() { load_boss5_common_assets(); TObjBoss5PillarDemo::update_active_pillar(); cleanup_pillar_demo_stub_b(); TObjBoss5PillarCtrl::forward_pillar_2B710(); pillar_demo_stub_b(); boss5_ctrl_instance = NULL; }
