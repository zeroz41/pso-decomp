#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/object/warp/TObjCityMainWarp_80186E24.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/unk/text_8024ACEC.h"
#include "pso/unk/text_8024AD30.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/object/warp/TObjCityMainWarp.h"

extern "C" {

void request_active_window_close(void);
s32 get_window_layout_position(s32);
extern s32 local_client_id;

void update_challenge_warp_window(TObjCityMainWarpChallenge *warp) {

    switch (warp->state_step) {
    case 0:
        warp->state_step = 1;
        *(s32 *)((s8 *)warp + 0xD0) = 0;
        return;
    case 1:
        if (find_local_city_warp_player(warp, warp->warp_range) != NULL) {
            if ((u32) warp->menu_window == 0U) {
                warp->menu_window = create_window_menu_default(get_window_layout_position(0x35), 7);
                if ((u32) warp->menu_window != 0U) {
                    ((TWindowMenu *)(warp->menu_window))->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x40), 0, 0, -1);
                    ((TWindowMenu *)(warp->menu_window))->set_flag_40();
                    ((TWindowMenu *)(warp->menu_window))->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(warp->menu_window));
                }
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        } else {
            if ((u32) warp->menu_window != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
                warp->menu_window = 0U;
            }
            end_player_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
        if ((s32) warp->player_on_dest_floor == 0) {
            warp->next_state = 0;
        }
        return;
    case -1:
        if ((u32) warp->menu_window != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
            warp->menu_window = 0U;
        }
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
        break;
    }
}

}
