#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
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

    switch (*(s16 *)((s8 *)warp + 0xE0)) {
    case 0:
        *(s16 *)((s8 *)warp + 0xE0) = 1;
        *(s32 *)((s8 *)warp + 0xD0) = 0;
        return;
    case 1:
        if (find_local_city_warp_player(warp, warp->warp_range) != NULL) {
            if ((u32) *(u32 *)((s8 *)warp + 0xB0) == 0U) {
                *(u32 *)((s8 *)warp + 0xB0) = create_window_menu_default(get_window_layout_position(0x35), 7);
                if ((u32) *(u32 *)((s8 *)warp + 0xB0) != 0U) {
                    ((TWindowSubTradeMain *)(*(uaddr *)((s8 *)warp + 0xB0)))->add_text_entry((saddr)TWindowSubStatusDisp::get_message_10(0x40), 0, 0, -1);
                    ((TAdChrSelASlotGC *)(*(uaddr *)((s8 *)warp + 0xB0)))->set_flag_40();
                    ((TWindowMenu *)(*(uaddr *)((s8 *)warp + 0xB0)))->calc_window_size();
                    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(*(uaddr *)((s8 *)warp + 0xB0)));
                }
                begin_player_keyboard_hold(local_client_id);
                request_active_window_close();
                TWindowCtrl::suppress_slot(local_client_id);
            }
        } else {
            if ((u32) *(u32 *)((s8 *)warp + 0xB0) != 0U) {
                ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
                *(u32 *)((s8 *)warp + 0xB0) = 0U;
            }
            end_player_keyboard_hold(local_client_id);
            TWindowCtrl::clear_flag();
            TWindowCtrl::unsuppress_slot(local_client_id);
        }
        if ((s32) *(s32 *)((s8 *)warp + 0x15C) == 0) {
            *(s16 *)((s8 *)warp + 0xDC) = 0;
        }
        return;
    case -1:
        if ((u32) *(u32 *)((s8 *)warp + 0xB0) != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)warp + 0xB0)))->close();
            *(u32 *)((s8 *)warp + 0xB0) = 0U;
        }
        end_player_keyboard_hold(local_client_id);
        TWindowCtrl::clear_flag();
        TWindowCtrl::unsuppress_slot(local_client_id);
        break;
    }
}

}
