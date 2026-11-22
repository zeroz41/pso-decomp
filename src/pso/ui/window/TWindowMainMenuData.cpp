#include "types.h"
#include "pso/ui/window/TWindowMainMenu.h"

// Data-only unit (.data): TWindowMainMenu1P/4P and TWindowUserSort open these tables.
// Main-menu tables (rows: item id, submenu table; 0x1F ends a table). Names inferred from their users:
// TWindowMainMenu1P::open_main_menu and TWindowMainMenu4P::open_main_menu open the *_android tables when
// TObjPlayer::is_android() holds; those lack item 3.
TWindowMainMenuEntry main_menu_1p_item2_submenu[] = {
    {0x09}, {0x0B}, {0x17}, {0x1A}, {0x0C}, {0x0F}, {0x1F},
};

TWindowMainMenuEntry main_menu_1p_item5_submenu[] = {
    {0x11}, {0x12}, {0x0E}, {0x13}, {0x16}, {0x15}, {0x1F},
};

TWindowMainMenuEntry main_menu_1p_entries[] = {
    {0x02, 0, main_menu_1p_item2_submenu}, {0x00}, {0x03}, {0x05, 0, main_menu_1p_item5_submenu},
    {0x19}, {0x06}, {0x07}, {0x1F},
};

TWindowMainMenuEntry main_menu_1p_android_entries[] = {
    {0x02, 0, main_menu_1p_item2_submenu}, {0x00}, {0x05, 0, main_menu_1p_item5_submenu},
    {0x19}, {0x06}, {0x07}, {0x1F},
};

TWindowMainMenuEntry main_menu_4p_item2_submenu[] = {
    {0x09}, {0x0B}, {0x17}, {0x1F},
};

TWindowMainMenuEntry main_menu_4p_entries[] = {
    {0x02, 0, main_menu_4p_item2_submenu}, {0x00}, {0x03}, {0x19}, {0x06}, {0x07}, {0x1F},
};

TWindowMainMenuEntry main_menu_4p_android_entries[] = {
    {0x02, 0, main_menu_4p_item2_submenu}, {0x00}, {0x19}, {0x06}, {0x07}, {0x1F},
};

