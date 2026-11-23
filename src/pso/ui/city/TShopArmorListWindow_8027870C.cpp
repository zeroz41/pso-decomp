#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
void TWindowMenuIconLine::refresh_armor_equip_list(u16 kind, u16 sub) { save_cursor_selection(); reset_list(); add_armor_equip_candidates(kind, sub); clamp_selection_to_valid_entry(); }
