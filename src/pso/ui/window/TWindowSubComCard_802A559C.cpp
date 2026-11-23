#include "types.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/chat/TWindowSubShortMail.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/object/warp/TObjCityMainWarp.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"

extern "C" {

// The yes/no choice menu sits 111 left of and 10 above the message window's bottom-right corner.
void TWindowMessageYesNo::get_choice_menu_position(NJS_POINT2 *position) {
    if (message_menu != NULL) {
        position->x = (message_menu->target_position[0] + message_menu->target_size[0]) - 111.0f;
        position->y = (message_menu->target_position[1] + message_menu->target_size[1]) - 10.0f;
    }
}

void TWindowSubComCard::free_windows() {
    if ((u32) this->m_28 != 0U) {
        reinterpret_cast<TWindowBase *>(this->m_28)->reparent_to_main_ctrl();
    }
    if ((u32) this->m_2c != 0U) {
        reinterpret_cast<TWindowBase *>(this->m_2c)->reparent_to_main_ctrl();
    }
}

void TWindowMessageYesNo::move_to(const NJS_POINT2 *position) {
    NJS_POINT2 choice_position;
    TWindowBase *window = message_menu;
    if (window != NULL && (window->target_position[0] != position->x || window->target_position[1] != position->y)) {
        window->slide_to((f32 *)position);
    }
    if (choice_menu != NULL) {
        get_choice_menu_position(&choice_position);
        window = choice_menu;
        if (window->target_position[0] != choice_position.x || window->target_position[1] != choice_position.y) {
            window->slide_to((f32 *)&choice_position);
        }
    }
}

void TWindowSubComCard::update_card_slot() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowMenu *)m)->set_flag_40(); }
void TWindowSubComCard::notify_trade_main() { void* m = *(void* *)&this->m_2c; if (m) ((TWindowSubTradeMain *)m)->clear_trade_flag(); }

}
