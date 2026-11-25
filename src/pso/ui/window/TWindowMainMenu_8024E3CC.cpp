#include "types.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowCtrlPlayer.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDeposit.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void TWindowMainMenu__sub_8024E3CC(void) {  }
void TWindowMainMenu__sub_8024E3D0(void) {  }
s32 TWindowMainMenu::is_log_active() { return (state_flags >> 3) & 0x1; }
s32 TWindowMainMenu::is_open() { return state_flags & 0x1; }

void TWindowMainMenu::open_main_menu() {  }
void TWindowMainMenu::close_main_menu() {  }

s32 TWindowCtrlPlayer::is_main_menu_locked() { return (flags >> 6) & 0x1; }
void TWindowDeposit::set_meseta(s32 meseta) {
    *(s32 *)((s8 *)get_array_entry(1) + 0x20) = meseta;
}
