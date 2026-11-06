#include "types.h"
#include "pso/unk/TLobby_8013292C.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/unk/TLobby.h"
#include "pso/player/PlayerClassFlags.h"

extern "C" {

s32 TQuestVmDownLoadServer__sub_8006EF6C(s32);

s32 TLobby::get_class_type_name(s32 class_flags) {
    if (class_flags & CLASS_FLAG_HUNTER) {
        return TQuestVmDownLoadServer__sub_8006EF6C(3);
    }
    if (class_flags & CLASS_FLAG_RANGER) {
        return TQuestVmDownLoadServer__sub_8006EF6C(4);
    }
    if (class_flags & CLASS_FLAG_FORCE) {
        return TQuestVmDownLoadServer__sub_8006EF6C(5);
    }
    return 0;
}

void select_main_menu_item_10(s32 arg0) {
    get_localized_text_entry(0xA, arg0);
}

}
