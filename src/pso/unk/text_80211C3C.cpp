#include "types.h"
#include "pso/unk/text_80211C3C.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/quest/TQuestListOnline.h"

extern "C" {
extern s32 TLobby__designated_client_id;
extern s32 local_client_id;
s32 THunterGuildSeqOffline__sub_80213458(void);
}

s32 TLobby__sub_80211C3C(void) {
    if (get_main_phase() != 0xF) {
        return 3;
    }
    if (TLobby__designated_client_id == local_client_id) {
        switch (TQuestListOnline::get_list_state()) {
        case 0:
            return 3;
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            return 0;
        }
    }
    switch (THunterGuildSeqOffline__sub_80213458()) {
    case -1:
        return 3;
    default:
        return 0;
    }
}
