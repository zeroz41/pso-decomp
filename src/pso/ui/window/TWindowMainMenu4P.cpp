#include "types.h"
#include "pso/ui/window/TWindowMainMenu4P.h"

#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

extern "C" {
void *get_player_by_client_id(s32 i);
s32 close_and_clear_flags__15TWindowMainMenuFv();

void TWindowMainMenu4P::vfunc_9() { if (close_active_submenu() != 0) { this->show_child_window(); } }

void TWindowMainMenu4P::vfunc_8() {
    if (this->m_4c & 1) {
        close_and_clear_flags__15TWindowMainMenuFv();
    }
}

void TWindowMainMenu4P::vfunc_6() {
    u8 *arg0 = (u8 *)this;
    u8 *player;
    if (!(this->m_4c & 1)) {
        player = (u8 *)(get_player_by_client_id(client_index));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                ((TWindowMainMenu *)arg0)->open((s32)main_menu_4p_android_entries);
            } else {
                ((TWindowMainMenu *)arg0)->open((s32)main_menu_4p_entries);
            }
            this->vfunc_7();
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

