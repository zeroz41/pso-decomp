#include "types.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/TWindowSubTechnique.h"

s32 TWindowSubTechnique::category_changed() {
    if (category_menu == NULL) {
        return 0;
    }
    if (current_category == category_menu->get_selected_value()) {
        return 0;
    }
    current_category = category_menu->get_selected_value();
    return 1;
}
