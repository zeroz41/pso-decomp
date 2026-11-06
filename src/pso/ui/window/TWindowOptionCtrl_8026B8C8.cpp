#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {

s32 refresh_with_default_list__20TWindowSubStatusDispFll(s32, s32 *);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);

extern s32 lbl_8044F494[];

s32 TWindowOptionCtrl::create_sound_mode_menu() {
    s32 temp_r31;

    s32 temp_r3_after_cba4 = get_option_entry__17TWindowOptionCtrlFi(0xCF);
    temp_r31 = refresh_with_default_list__20TWindowSubStatusDispFll(temp_r3_after_cba4, lbl_8044F494);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xE), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xD), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0xF), 2);
    switch (*(s16 *)((s8 *)this + 0x20)) {
    case 0:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(0);
        break;
    case 1:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(1);
        break;
    case 2:
        ((TWindowSubStatusDisp *)temp_r31)->set_selected_index(2);
        break;
    }
    return temp_r31;
}

}
