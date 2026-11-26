#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/boss/galgryphon/Boss5CommonResource.h"
#include "pso/network/TLobby.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/task/TObject.h"
#include "pso/object/door/TODoorFourLightSpace.h"

extern "C" {
int forward_pillar_2B710__19TObjBoss5PillarCtrlFv(void);
s32 update_pillar__19TObjBoss5PillarCtrlFv();

void TLobby::cleanup_pillar_demo() {
    if (boss5_ctrl_instance != NULL) {
        boss5_ctrl_instance->queue_destruction();
        boss5_ctrl_instance = NULL;
    }
    TObjBoss5PillarDemo__sub_8028ACE0();
    update_pillar__19TObjBoss5PillarCtrlFv();
    fn_802898E8();
    clear_pillar_target_refs();
    free_boss5_common_assets();
}
void TLobby::cleanup_boss5_pillars() { load_boss5_common_assets(); TObjBoss5PillarDemo::update_active_pillar(); fn_802898EC(); forward_pillar_2B710__19TObjBoss5PillarCtrlFv(); TObjBoss5PillarDemo__sub_8028ACE4(); boss5_ctrl_instance = NULL; }

}
