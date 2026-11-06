#include "types.h"
#include "pso/ui/window/TWindowMainMenu4P.h"

#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_802889A8_lbl_804D04F8 { s32 value; u8 remaining[0x34]; };
typedef char RecoveredGlobal_802889A8_lbl_804D04F8_size[sizeof(RecoveredGlobal_802889A8_lbl_804D04F8) == 0x38 ? 1 : -1];

struct RecoveredGlobal_802889A8_lbl_804D0530 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_802889A8_lbl_804D0530_size[sizeof(RecoveredGlobal_802889A8_lbl_804D0530) == 0x30 ? 1 : -1];

extern "C" {
void *get_player_by_client_id(s32 i);
extern RecoveredGlobal_802889A8_lbl_804D04F8 lbl_804D04F8;
extern RecoveredGlobal_802889A8_lbl_804D0530 lbl_804D0530;
void *TWindowMainMenu4P__ct(void *arg0);
void TWindowMainMenu__ct(void *);
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
        player = (u8 *)(get_player_by_client_id(this->m_54));
        if (player != NULL) {
            if (((TObjPlayer *)player)->is_android() != 0) {
                ((TWindowMainMenu *)arg0)->open((s32) &lbl_804D0530.value);
            } else {
                ((TWindowMainMenu *)arg0)->open((s32) &lbl_804D04F8.value);
            }
            this->vfunc_7();
        }
    }
}

void TWindowMainMenu4P::render() {  }
void TWindowMainMenu4P::run_task() { handle_menu_selection(); sub_80263FE0(); }

extern s32 __vt__17TWindowMainMenu4P[];

}
TWindowMainMenu4P::~TWindowMainMenu4P() {

}


extern void *TWindowMainMenu4P__name;

void *TWindowMainMenu4P__ct(void *window_main_menu4_p) {
    TWindowMainMenu__ct(window_main_menu4_p);
    *(s32 **)((s8 *)window_main_menu4_p + 0x18) = __vt__17TWindowMainMenu4P;
    *(void * *)&((TWindowMainMenu4P *)window_main_menu4_p)->m_name = TWindowMainMenu4P__name;
    return window_main_menu4_p;
}

