#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/unk/text_80278BD8.h"

extern "C" {


void TWindowMenuIconLine::refresh_armor_equip_list(u16 kind, u16 sub) { save_cursor_selection(); reset_list(); add_armor_equip_candidates((u8 *)this, kind, sub); clamp_selection_to_valid_entry(); }

}
