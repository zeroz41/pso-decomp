#include "types.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

s32 TWindowSubItem::get_cursor_pos() { return *(s32*)((char*)this + 0x18); }
