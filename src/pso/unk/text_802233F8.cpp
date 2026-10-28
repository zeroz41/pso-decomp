#include "types.h"
#include "pso/unk/text_802233F8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TRaderMapCore.h"

extern "C" {
s32 get_entity_id(void *);
u8 *get_player_by_client_id(s32);
s32 TLobby__sub_8024AC20(u16);
s32 play_effect_default__10TObjPlayerFii(void *, s32);
s32 TObjPlayer__sub_8024ABDC(u16);
void fn_802233F8(void) {
    u16 self_slot;
    s32 i;
    u8 *p;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        self_slot = TCameraCtrl::get_nth_view_player_id(0);
        for (i = 0; i < 4; i++) {
            if (self_slot != i) {
                p = get_player_by_client_id(i);
                if (p != NULL && ((TLobby *)p)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((s32)p);
                    TLobby__sub_8024AC20(get_entity_id(p));
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
                if (p != NULL && ((TLobby *)p)->check_player_flag1() == 0) {
                    play_effect_default__10TObjPlayerFii(p, -1);
                    TObjPlayer__sub_8024ABDC(get_entity_id(p));
                }
            }
        }
    }
}

}
