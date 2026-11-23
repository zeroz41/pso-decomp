#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"


void THunterGuildSeqOffline::notify_close() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->display_guild_message(0x19, 1);
        THunterGuildSeqOffline__active_instance->set_state(4);
    }
}

void THunterGuildSeqOffline::create_quest_list_vm(TShopWindowBase *) {
    TQuestListVM *vm = new TQuestListVM(tl_05, THunterGuildSeqOffline__active_instance,
                                        THunterGuildSeqOffline__active_instance->player);
    if (vm != NULL) {
        vm->on_close = notify_close;
        vm->on_error = init_quest_list;
        vm->on_finish = set_state_3;
    }
}
