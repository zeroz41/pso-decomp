#include "types.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/Language.h"

extern "C" {
s32 refresh_with_default_list__20TWindowSubStatusDispFll(int, void *);
int get_option_entry__17TWindowOptionCtrlFi(int);
extern s32 lbl_8044F48C[];
s32 TWindowOptionCtrl::create_select_menu_window() {
    s32 temp_r31;
    temp_r31 = refresh_with_default_list__20TWindowSubStatusDispFll(get_option_entry__17TWindowOptionCtrlFi(0xCF), lbl_8044F48C);
    TWindowOptionCtrl::add_menu_item(temp_r31, (int) (get_localized_text_entry(0xF, 8)), 0);
    TWindowOptionCtrl::add_menu_item(temp_r31, (int) (get_localized_text_entry(0xF, 9)), 1);
    TWindowOptionCtrl::add_menu_item(temp_r31, (int) (get_localized_text_entry(0xF, 0xA)), 2);
    TWindowOptionCtrl::add_menu_item(temp_r31, (int) (get_localized_text_entry(0xF, 0xB)), 3);
    TWindowOptionCtrl::add_menu_item(temp_r31, (int) (get_localized_text_entry(0xF, 0xC)), 4);
    ((TWindowSubStatusDisp *)temp_r31)->set_selected_index((s16)((void *) ((s16) current_language)));
    return temp_r31;
}

}
