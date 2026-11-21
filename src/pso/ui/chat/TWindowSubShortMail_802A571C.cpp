#include "pso/ui/window/TWindowMessageYesNo.h"
#include "pso/ui/window/TWindowMenu.h"

void TWindowMessageYesNo::set_choice_menu_flag70_bit10() {
    TWindowMenu *menu = choice_menu;
    if (menu != NULL) {
        menu->set_flag70_bit10();
    }
}
