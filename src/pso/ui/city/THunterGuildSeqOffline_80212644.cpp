#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

void THunterGuildSeqOffline::set_state_3() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline__active_instance->unk_38 = 3;
        THunterGuildSeqOffline__active_instance->set_state(5);
    }
}
