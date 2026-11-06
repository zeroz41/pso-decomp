#include "types.h"
#include "pso/unk/TLobby_80209BD8.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 TLobby__sub_802099FC(s16 *, s32);

extern s32 lobby_random_slot_id_table[];

s32 pick_random_slot__6TLobbyFPv(s16 *arg0) {
    s32 key;
    s32 sp8;

    TLobby::pick_weighted_entry(&key, &sp8);
    if ((key != -1) && (sp8 != -1)) {
        *arg0 = (s16) lobby_random_slot_id_table[sp8];
        TLobby__sub_802099FC(arg0, key);
        ((TLobby *)arg0)->pick_random_entry();
        return 0;
    }
    return 1;
}

}
