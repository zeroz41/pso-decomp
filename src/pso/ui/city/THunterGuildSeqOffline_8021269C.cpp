#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"


void THunterGuildSeqOffline::init_quest_list() {
    THunterGuildSeqOffline__active_instance->set_state(9);
}
