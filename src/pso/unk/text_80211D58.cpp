#include "types.h"
#include "pso/misc/TPlayerBattleCtrl4P.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/unk/text_80211D58.h"
#include "pso/THunterGuildWarning.h"
#include "pso/misc/TRaderMapCore.h"
extern "C" {
s32 get_nth_view_player_id__11TCameraCtrlFl(s32);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 get_map_id__13TRaderMapCoreFv();
u32 get_player_by_client_id(s32);
s32 is_active__19THunterGuildWarningFv();
s32 THunterGuildSeqOffline__sub_80211FEC(s32);
s32 THunterGuildSeqOffline__sub_80212000(s32);
s32 THunterGuildSeqOffline__sub_80212060(s32);
extern u8 controller_input_state[][0x50];
extern s32 lbl_805D55C0;
s32 TLobby__sub_80211D58(s32 arg0) {
    s32 kind;
    s32 player;
    if (get_main_phase() == 14) {
        if (TRaderMapCore::is_not_split_screen() == 1) {
            if (get_game_play_mode() == 0) {
                return 1;
            }
            player = get_nth_view_player_id__11TCameraCtrlFl(0);
            if ((u16)player != arg0) {
                return 1;
            }
            if (is_active__19THunterGuildWarningFv() != 0) {
                return 1;
            }
            kind = TPlayerBattleCtrl4P::fn_80211B10(player);
            if (kind != 0) {
                if (get_player_by_client_id((u16)player) != 0) {
                    if (TWindowShortListCtrl__check_controller_button(&controller_input_state[get_map_id__13TRaderMapCoreFv()][0x20], 4) != 0 &&
                        is_active__19THunterGuildWarningFv() == 0) {
                        switch (kind) {
                        case 1:
                        case 2:
                            THunterGuildWarning::create_instance(0);
                            break;
                        case 3:
                            THunterGuildWarning::create_instance(1);
                            break;
                        }
                    }
                }
                return 1;
            }
        }
        return THunterGuildSeqOffline__sub_80212060(arg0);
    }
    if (get_main_phase() == 15) {
        if (lbl_805D55C0 != 0) {
            return 1;
        }
        if (THunterGuildSeqOffline__sub_80212000(arg0) != 0) {
            return 1;
        }
        return THunterGuildSeqOffline__sub_80211FEC(arg0) != 0 ? 1 : 0;
    }
    return 0;
}

}
