#include "types.h"
#include "pso/unk/text_802233F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/TObjBase.h"
#include "pso/unk/text_8024AB98.h"

extern "C" {
u8 *get_player_by_client_id(s32);
void fn_802233F8(void) {
    u16 self_slot;
    s32 i;
    u8 *p;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        self_slot = TCameraCtrl::get_nth_view_player_id(0);
        for (i = 0; i < 4; i++) {
            if (self_slot != i) {
                p = get_player_by_client_id(i);
                if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((saddr)p);
                    TLobby__sub_8024AC20(((TObjBase *)(p))->get_entity_id());
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
                p = get_player_by_client_id(i);
                if (p != NULL && ((TObjPlayer *)p)->check_player_flag1() == 0) {
                    TObjPlayer::play_effect_default((saddr)p, (int)(-1));
                    TObjPlayer__sub_8024ABDC(((TObjBase *)(p))->get_entity_id());
                }
            }
        }
    }
}

}
