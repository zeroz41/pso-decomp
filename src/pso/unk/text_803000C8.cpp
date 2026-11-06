#include "types.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/network/TPlyJoinLobbyEntry.h"
#include "pso/unk/text_803000C8.h"
extern "C" {
s32 is_split_screen(void);
extern s32 TAdMultiSelGameModeGC__data_805D69F0;
void fn_803000C8(void) {
    if (is_split_screen() != 0) {
        switch (TAdMultiSelGameModeGC__data_805D69F0) {
        case 1:
            set_player_count__6TLobbyFi(1);
            break;
        case 2:
            enable_split_screen_challenge_mode();
            break;
        case 0:
            break;
        }
    }
}

}
