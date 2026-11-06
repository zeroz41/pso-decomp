#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubItem.h"

int TWindowSubStatusDisp::is_flag_4_set() { return *(u16 *)&this->m_name & 0x4; }
int TWindowMenuIconLine::get_flag() { return (this->state_flags >> 6) & 0x1; }
