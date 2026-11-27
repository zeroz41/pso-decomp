#include "types.h"
#include "pso/player/ClassTypeName.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerClassFlags.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"

const char *get_class_type_name(s32 class_flags) {
    if (class_flags & CLASS_FLAG_HUNTER) {
        return get_message_text(3);
    }
    if (class_flags & CLASS_FLAG_RANGER) {
        return get_message_text(4);
    }
    if (class_flags & CLASS_FLAG_FORCE) {
        return get_message_text(5);
    }
    return 0;
}

const char *select_main_menu_item_10(s32 id) {
    return get_localized_text_entry(0xA, id);
}
