#include "types.h"
#include "pso/misc/TWindowMainMenu_8024E3CC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowDeposit.h"
#include "pso/misc/TWindowSubStatusDisp.h"

void TWindowMainMenu__sub_8024E3CC(void) {  }
void TWindowMainMenu__sub_8024E3D0(void) {  }
int TWindowMainMenu__sub_8024E3D4(void* p) { return (*(u32*)((char*)p + 0x4c) >> 3) & 0x1; }
int TWindowMainMenu__sub_8024E3E0(void* p) { return *(u32*)((char*)p + 0x4c) & 0x1; }

void TWindowMainMenu::vfunc_6() {  }
void TWindowMainMenu::vfunc_8() {  }

int TWindowMainMenu__sub_8024E3F4(void* p) { return (*(u16*)((char*)p + 0x1c) >> 6) & 0x1; }
void TWindowMainMenu::set_entry_field_20(s32 arg0, s32 arg1) {
    *(s32 *)((s8 *)(((TWindowBase *)arg0)->get_array_entry(1)) + 0x20) = arg1;
}
