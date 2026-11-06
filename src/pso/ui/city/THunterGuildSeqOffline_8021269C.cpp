#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

extern s32 THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::init_quest_list() {
    ((TShopWindowBase *)THunterGuildSeqOffline__active_instance)->set_field_20(9);
}
