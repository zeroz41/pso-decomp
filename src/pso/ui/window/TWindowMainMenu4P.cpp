#include "types.h"
#include "pso/ui/window/TWindowMainMenu4P.h"

#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

extern "C" {

void TWindowMainMenu4P::on_submenu_closed() { if (close_active_submenu() != 0) { this->show_child_window(); } }

void TWindowMainMenu4P::close_main_menu() {
    if (this->m_4c & 1) {
        TWindowMainMenu::close_and_clear_flags();
    }
}

void TWindowMainMenu4P::open_main_menu() {
    u8 *arg0 = (u8 *)this;
    u8 *player;
    if (!(this->m_4c & 1)) {
        player = (u8 *)(get_player_by_client_id(client_index));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                ((TWindowMainMenu *)arg0)->open((saddr)main_menu_4p_android_entries);
            } else {
                ((TWindowMainMenu *)arg0)->open((saddr)main_menu_4p_entries);
            }
            this->on_menu_opened();
        }
    }
}

void TWindowMainMenu4P::render() {  }
void TWindowMainMenu4P::run_task() { handle_menu_selection(); sub_80263FE0(); }

}
TWindowMainMenu4P::~TWindowMainMenu4P() {

}


const char *TWindowMainMenu4P__name = "TWindowMainMenu4P";

TWindowMainMenu4P::TWindowMainMenu4P(TObject *parent, s32 client) : TWindowMainMenu(parent, client) {
    m_name = TWindowMainMenu4P__name;
}

