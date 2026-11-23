#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

extern "C" {

int populate_judgment_item_list(void*);

void TWindowMenuIconLine::refresh_judgment_item_list() { save_cursor_selection(); reset_list(); populate_judgment_item_list(this); clamp_selection_to_valid_entry(); }

}
