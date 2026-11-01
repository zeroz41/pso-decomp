#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObjCityMainWarp_80186E24.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubTradeMain.h"
#include "pso/ui/TAdChrSelASlotGC.h"

extern "C" {

s32 get_message_10__20TWindowSubStatusDispFl(s32);
u32 find_local_player_in_range__16TObjCityMainWarpFf(f32);
void request_active_window_close(void);
s32 align_menu_entry_positions(u32);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32, s32);
s32 get_window_layout_position(s32);
extern s32 local_client_id;

void update_challenge_warp_window(void *arg0) {

    switch (*(s16 *)((s8 *)arg0 + 0xE0)) {
    case 0:
        *(s16 *)((s8 *)arg0 + 0xE0) = 1;
        *(s32 *)((s8 *)arg0 + 0xD0) = 0;
        return;
    case 1:
        if (find_local_player_in_range__16TObjCityMainWarpFf(*(f32 *)((s8 *)arg0 + 0xAC)) != 0U) {
            if ((u32) *(u32 *)((s8 *)arg0 + 0xB0) == 0U) {
                *(u32 *)((s8 *)arg0 + 0xB0) = check_room_seq_4__16TAdChrSelASlotGCFl(get_window_layout_position(0x35), 7);
                if ((u32) *(u32 *)((s8 *)arg0 + 0xB0) != 0U) {
                    ((TWindowSubTradeMain *)(*(u32 *)((s8 *)arg0 + 0xB0)))->add_text_entry(get_message_10__20TWindowSubStatusDispFl(0x40), 0, 0, -1);
                    ((TAdChrSelASlotGC *)(*(u32 *)((s8 *)arg0 + 0xB0)))->set_flag_40();
                    ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0xB0)))->calc_window_size();
                    align_menu_entry_positions(*(u32 *)((s8 *)arg0 + 0xB0));
                }
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                ((TWindowCtrl *)local_client_id)->suppress_slot();
            }
        } else {
            if ((u32) *(u32 *)((s8 *)arg0 + 0xB0) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)arg0 + 0xB0)))->close();
                *(u32 *)((s8 *)arg0 + 0xB0) = 0U;
            }
            end_player_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x15C) == 0) {
            *(s16 *)((s8 *)arg0 + 0xDC) = 0;
        }
        return;
    case -1:
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB0) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)arg0 + 0xB0)))->close();
            *(u32 *)((s8 *)arg0 + 0xB0) = 0U;
        }
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        ((TWindowCtrl *)local_client_id)->unsuppress_slot();
        break;
    }
}

}
