#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {

s32 refresh_with_default_list__20TWindowSubStatusDispFll(s32, s32 *);
s32 get_option_entry__17TWindowOptionCtrlFi(s32);

extern s32 lbl_8044F49C[];

s32 TWindowOptionCtrl::create_option_menu() {
    s32 temp_r31;

    temp_r31 = refresh_with_default_list__20TWindowSubStatusDispFll(get_option_entry__17TWindowOptionCtrlFi(0xD0), lbl_8044F49C);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x10), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x11), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, get_localized_text_entry(0xF, 0x12), 2);
    ((TWindowSubStatusDisp *)temp_r31)->set_selected_index((s16) TWindowOptionCtrl::get_option_field_C());
    return temp_r31;
}

}
