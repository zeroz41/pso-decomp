#include "types.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

extern s32 THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::init_quest_list() {
    ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(9);
}
