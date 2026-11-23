#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

int build_usable_item_list(void*);

void TWindowMenuIconLine::refresh_usable_item_list() { save_cursor_selection(); reset_list(); build_usable_item_list(this); clamp_selection_to_valid_entry(); }

}
