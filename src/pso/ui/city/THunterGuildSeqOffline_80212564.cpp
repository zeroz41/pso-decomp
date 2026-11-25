#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"

void THunterGuildSeqOffline::set_state_4(TShopWindowBase *) {
    if (THunterGuildSeqOffline::active_instance != NULL) {
        THunterGuildSeqOffline::active_instance->display_guild_message(6, 1);
        THunterGuildSeqOffline::active_instance->exit_action = 4;
        THunterGuildSeqOffline::active_instance->set_state(5);
    }
}

void THunterGuildSeqOffline::handle_click() {
    if (is_message_ready() != 0 && (is_decide_pressed() != 0 || is_cancel_pressed() != 0)) {
        display_guild_message(0x19, 1);
        set_state(4);
    }
}

