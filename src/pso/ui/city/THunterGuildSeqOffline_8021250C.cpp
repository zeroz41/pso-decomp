#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

void THunterGuildSeqOffline::set_state_close(TShopWindowBase *) {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->display_guild_message(0xC, 1);
        THunterGuildSeqOffline__active_instance->unk_38 = 0;
        THunterGuildSeqOffline__active_instance->set_state(5);
    }
}
