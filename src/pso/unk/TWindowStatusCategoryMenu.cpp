#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include <stddef.h>
#include "pso/unk/TWindowStatusCategoryMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCardList.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/WindowLayout.h"

TWindowStatusCategoryMenu::TWindowStatusCategoryMenu(TWindowMainMenu *parent, s32 client) : TObject(parent) {
    main_menu = parent;
    client_id = client;
    category_menu = create_status_category_menu();
    status_disp = new TWindowSubStatusDisp(client_id);
    if (TCameraCtrl::get_camera_id() > 2) {
        category_menu->set_position_xy(0.84f, 0.84f);
        status_disp->set_scale(0.84f, 0.84f);
    }
}

TWindowStatusCategoryMenu::~TWindowStatusCategoryMenu() {
    if (status_disp != NULL) {
        status_disp->close();
        status_disp = NULL;
    }
    if (category_menu != NULL) {
        category_menu->close();
        category_menu = NULL;
    }
}

// Cancel hands control back to the main menu; the page window follows the selected category.
void TWindowStatusCategoryMenu::run_task() {
    is_player_input_active(client_id);
    if (category_menu->is_cancelled() != 0) {
        main_menu->on_submenu_closed();
    }
    status_disp->set_requested_page(category_menu->get_selected_value());
}

void TWindowStatusCategoryMenu::render() {
}

// The category menu: "status" pages 0x10A-0x10C, titled by message 0x1D on the full-screen layouts.
TWindowMenu *TWindowStatusCategoryMenu::create_status_category_menu() {
    TWindowMenu *menu;
    if (TCameraCtrl::get_camera_id() > 2) {
        menu = create_window_menu(get_window_layout_position(0x18), 3, client_id);
    } else {
        menu = create_titled_window_menu(get_window_layout_position(0x18), 3, (saddr)TWindowSubStatusDisp::get_message_10(0x1D), client_id);
    }
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x10A)), 0x36, 0);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x10B)), 0x36, 1);
    menu->add_text_entry((saddr)(TWindowSubStatusDisp::get_message_10(0x10C)), 0x36, 2);
    (menu)->set_flag70_bit10();
    (menu)->update_layout_height(202.0f);
    align_menu_entry_positions(reinterpret_cast<TWindowMenu *>(menu));
    return menu;
}
