#include "types.h"
#include "pso/unk/TLobby_8013292C.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/TLobby.h"
#include "pso/player/PlayerClassFlags.h"

extern "C" {

saddr get_message_text(s32);

saddr TLobby::get_class_type_name(s32 class_flags) {
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

void select_main_menu_item_10(s32 id) {
    get_localized_text_entry(0xA, id);
}

}
