#include "types.h"
#include "pso/ui/window/TWindowSubEquip_80263AB0.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowSubEquip.h"

extern "C" {
s32 create_submenu__15TWindowMainMenuFUl(s32, s16);
s32 destroy_submenu__15TWindowMainMenuFv();
s32 fn_802449E0(u32);
s32 is_split_screen();

void call_if_split_screen(u32 object) {
    if ((is_split_screen() != 0) && (object != 0U)) {
        fn_802449E0(object);
    }
}
void TWindowSubEquip__sub_80263AF4(void) {  }


f32 TWindowSubEquip__sub_80263AF8(u8 *arg0, u32 arg1) {
    return *(f32 *)((s8 *)arg0 + 0x58) - (f32) arg1;
}

void TWindowMainMenu::set_scale_f() { *(float*)((char*)this + 0x58) = 50300.0f; }

void TWindowSubEquip::open_submenu(s32 arg0, s32 arg1) {
    destroy_submenu__15TWindowMainMenuFv();
    create_submenu__15TWindowMainMenuFUl(arg0, (s16) arg1);
}

}
