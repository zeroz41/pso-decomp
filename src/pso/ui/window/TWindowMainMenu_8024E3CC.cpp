#include "types.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowDeposit.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

void TWindowMainMenu__sub_8024E3CC(void) {  }
void TWindowMainMenu__sub_8024E3D0(void) {  }
int TWindowMainMenu__sub_8024E3D4(void* p) { return (*(u32*)((char*)p + 0x4c) >> 3) & 0x1; }
int TWindowMainMenu__sub_8024E3E0(void* p) { return *(u32*)((char*)p + 0x4c) & 0x1; }

void TWindowMainMenu::open_main_menu() {  }
void TWindowMainMenu::close_main_menu() {  }

int TWindowMainMenu__sub_8024E3F4(void* p) { return (*(u16*)((char*)p + 0x1c) >> 6) & 0x1; }
void TWindowDeposit::set_meseta(s32 meseta) {
    *(s32 *)((s8 *)get_array_entry(1) + 0x20) = meseta;
}
