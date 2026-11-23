#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

void TWindowMenuIconLine::refresh_mag_item_list(u16 kind) { save_cursor_selection(); reset_list(); build_mag_item_candidates(kind); clamp_selection_to_valid_entry(); }
