#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 create_lobby_object_05(s32);
s32 create_tl05_object__6TLobbyFPv(s32);
s32 create__22THunterGuildSeqOfflineFPv(s32);

extern s32 local_client_id;
extern s32 TLobby__designated_client_id;

s32 TLobby::handle_main_phase(s32 arg0) {
    if (get_main_phase() == 0xE) {
        return create__22THunterGuildSeqOfflineFPv(arg0);
    }
    if (get_main_phase() == 0xF) {
        if ((s32) local_client_id == (s32) TLobby__designated_client_id) {
            return create_tl05_object__6TLobbyFPv(arg0);
        }
        return create_lobby_object_05(arg0);
    }
    return 0;
}

}
