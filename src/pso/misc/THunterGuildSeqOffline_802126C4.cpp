#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TShopWindowBase.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/quest/TQuestListVM.h"

extern "C" THunterGuildSeqOffline *THunterGuildSeqOffline__active_instance;

void THunterGuildSeqOffline::notify_close() {
    if (THunterGuildSeqOffline__active_instance != NULL) {
        THunterGuildSeqOffline__active_instance->display_guild_message(0x19, 1);
        THunterGuildSeqOffline__active_instance->set_field_20(4);
    }
}

void THunterGuildSeqOffline::create_quest_list_vm() {
    TQuestListVM *vm = new TQuestListVM(tl_05, THunterGuildSeqOffline__active_instance,
                                        (TObjBase *)THunterGuildSeqOffline__active_instance->m_24);
    if (vm != NULL) {
        vm->on_close = notify_close;
        vm->on_error = init_quest_list;
        vm->on_finish = set_state_3;
    }
}
