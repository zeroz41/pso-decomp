#include "types.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

int check_flag__10TObjPlayerFl(void*, int);

extern void *TWindowCtrl__active_window;

s32 TWindowCtrl::get_flag_bit3() {
    if ((void *) TWindowCtrl__active_window == NULL) {
        return 0;
    }
    return ((u16) *(u16 *)((s8 *)TWindowCtrl__active_window + 0x1C) >> 3U) & 1;
}

int TWindowCtrl::is_player_flag_4000_set() { return check_flag__10TObjPlayerFl(this, 16384); }
s32 TWindowCtrl::is_map_visible() {
    if (TRaderMapCore::is_not_split_screen() != 1) {
        return 1;
    }
    if (get_game_play_mode() != 1) {
        return 1;
    }
    return TLobby__sub_8030A770() != 0 ? 1 : 0;
}

}
