#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80066F10.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/system/task/TObject.h"

extern "C" {
void fn_802898EC(void);
int forward_pillar_2B710__19TObjBoss5PillarCtrlFv(void);
extern u32 boss5_ctrl_instance;
void fn_802898E8(void);
s32 update_pillar__19TObjBoss5PillarCtrlFv();

void TLobby::cleanup_pillar_demo() {
    if ((u32) boss5_ctrl_instance != 0U) {
        ((TObject *)boss5_ctrl_instance)->queue_destruction();
        boss5_ctrl_instance = 0U;
    }
    TObjBoss5PillarDemo__sub_8028ACE0();
    update_pillar__19TObjBoss5PillarCtrlFv();
    fn_802898E8();
    TObjBoss5PillarDemo__sub_8028AB38();
    TLobby__sub_80066EC0();
}
void TLobby::cleanup_boss5_pillars() { load_boss5_common_assets(); TObjBoss5PillarDemo::update_active_pillar(); fn_802898EC(); forward_pillar_2B710__19TObjBoss5PillarCtrlFv(); TObjBoss5PillarDemo__sub_8028ACE4(); (*(int *)&boss5_ctrl_instance) = 0; }

}
