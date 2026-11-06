#include "types.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TForceOperate.h"
#include "pso/ui/hud/TMainCursor.h"

void TWindowActionPalette::set_slot(u8 v) { this->m_1 = v; }
void TWindowActionPalette::set_mode(u8 v) { *(u8*)((char*)this + 0x0) = v; }
