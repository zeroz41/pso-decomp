#include "types.h"
#include "pso/unk/text_802233F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
void fn_802233F8(void) {
    u16 self_slot;
    s32 i;
    u8 *p;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        self_slot = TCameraCtrl::get_nth_view_player_id(0);
        for (i = 0; i < 4; i++) {
            if (self_slot != i) {
                p = (u8 *)get_player_by_client_id(i);
                if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((saddr)p);
                    TWindowCtrl::enable_client_main_menu(((TObjBase *)(p))->get_entity_id());
                }
            }
        }
    }
}
void fn_80223480(void) {
    u16 self_slot;
    s32 i;
    u8 *p;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        self_slot = TCameraCtrl::get_nth_view_player_id(0);
        for (i = 0; i < 4; i++) {
            if (self_slot != i) {
                p = (u8 *)get_player_by_client_id(i);
                if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() == 0) {
                    TObjPlayer::play_effect_default((saddr)p, (int)(-1));
                    TWindowCtrl::disable_client_main_menu(((TObjBase *)(p))->get_entity_id());
                }
            }
        }
    }
}

}
