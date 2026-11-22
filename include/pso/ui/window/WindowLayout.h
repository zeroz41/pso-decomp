#ifndef PSO_UI_WINDOW_WINDOWLAYOUT_H
#define PSO_UI_WINDOW_WINDOWLAYOUT_H

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/system/NinjaTypes.h"

// Window placement helpers shared by the menu windows. get_window_layout_position is defined in
// TWindowOptionCtrl_8026CBA4.cpp, align_menu_entry_positions in TWindowSubComCard_80265410.cpp.
extern "C" {
const NJS_POINT2 *get_window_layout_position(s32 idx);
}

#endif
