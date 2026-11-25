#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

void THunterGuildSeqOffline::set_state_3() {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->unk_38 = 3;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}
