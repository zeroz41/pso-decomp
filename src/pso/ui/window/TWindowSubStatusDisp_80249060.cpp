#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubItem.h"

int TWindowLayoutEntry::is_flag_4_set() const { return flags & 0x4; }
int TWindowMenuIconLine::get_flag() { return (this->state_flags >> 6) & 0x1; }
