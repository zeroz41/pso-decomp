#include "types.h"
#include "pso/object/collision/TOSymbolchatColli.h"
#include "pso/ui/window/TWindowCtrl.h"

void TOSymbolchatColli::open_balloon_chat(s32 state, u16 player) {
    if (state < 3) {
        u8 *chat = balloon_chats[state];
        if (chat != 0) {
            TWindowCtrl::open_balloon(get_entity_id(), chat, 10, player);
        }
    }
}
